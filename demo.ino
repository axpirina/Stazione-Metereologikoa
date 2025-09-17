/*
ESP8266 Weather Station + Location (ThingsBoard Integration)

- DHT11 sentsorea: tenperatura, hezetasuna, dew point
- HTTP bidez: latitude eta longitude lortzen dira (ip-api.com)
- ThingsBoard-era bidalketa:
   * DHT datuak -> 5 segundoro
   * Lat/Lon    -> 30 minuturo

By Axpi (adapted)
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// WiFi eta MQTT konfigurazioa
const char* ssid = "yourWiFiSSID";       // Zure WiFi izena
const char* password = "yourWiFiPassword"; // Zure WiFi pasahitza
const char* mqtt_server = "demo.thingsboard.io";

// ThingsBoard tokena
const char* mqtt_user = "yourDeviceToken";  
const char* mqtt_password = "";

// MQTT bezeroa
WiFiClient espClient;
PubSubClient client(espClient);

// DHT konfigurazioa
#define DHTPIN 2   // DHT11 datu pin (GPIO2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQTT topic
const char* topic = "v1/devices/me/telemetry";

// Denborak
unsigned long lastDhtSend = 0;
unsigned long lastLocSend = 0;
const unsigned long dhtInterval = 5000;       // 5 seg
const unsigned long locInterval = 1800000;    // 30 min

// Latitude eta longitude
float latitude = 0.0;
float longitude = 0.0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("WiFi-ra konektatzen: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nKonektatuta WiFi-ra!");
  Serial.print("IP helbidea: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT-ra konektatzen...");
    if (client.connect("NodeMCUClient", mqtt_user, mqtt_password)) {
      Serial.println("Konektatuta!");
    } else {
      Serial.print("Huts! errore kodea = ");
      Serial.print(client.state());
      Serial.println(". 5 segundotan berriro...");
      delay(5000);
    }
  }
}

// ip-api.com-etik kokapena lortu
void updateLocation() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://ip-api.com/json/");
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      StaticJsonDocument<512> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        latitude = doc["lat"];
        longitude = doc["lon"];
        Serial.printf("Kokapena eguneratuta -> Lat: %f, Lon: %f\n", latitude, longitude);
      } else {
        Serial.println("JSON errorea!");
      }
    } else {
      Serial.printf("HTTP errorea: %d\n", httpCode);
    }
    http.end();
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  dht.begin();
  updateLocation(); // lehenengo aldian kokapena jaso
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();

  // DHT datuak 5 segundoro bidali
  if (now - lastDhtSend > dhtInterval) {
    lastDhtSend = now;

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Ezin izan da DHT sentsorea irakurri!");
      return;
    }

    // Dew point kalkulatu
    float a = 17.27;
    float b = 237.7;
    float alpha = ((a * temperature) / (b + temperature)) + log(humidity / 100.0);
    float dewPoint = (b * alpha) / (a - alpha);

    // JSON mezua
    String payload = "{\"temperature\":";
    payload += String(temperature);
    payload += ",\"humidity\":";
    payload += String(humidity);
    payload += ",\"dewPoint\":";
    payload += String(dewPoint);
    payload += "}";

    if (client.publish(topic, payload.c_str())) {
      Serial.print("DHT datuak bidalita: ");
      Serial.println(payload);
    } else {
      Serial.println("DHT publish huts egin du!");
    }
  }

  // Latitude/Longitude 30 minuturo bidali
  if (now - lastLocSend > locInterval) {
    lastLocSend = now;
    updateLocation();

    String payload = "{\"latitude\":";
    payload += String(latitude, 6);
    payload += ",\"longitude\":";
    payload += String(longitude, 6);
    payload += "}";

    if (client.publish(topic, payload.c_str())) {
      Serial.print("Kokapena bidalita: ");
      Serial.println(payload);
    } else {
      Serial.println("Kokapena publish huts egin du!");
    }
  }
}
