#include <ESP8266WiFi.h> // ESP8266 platarako WiFi liburutegia
#include <PubSubClient.h>
#include <DHT.h>

// WiFi eta MQTT konfigurazioa
const char* ssid = "Liberia";
const char* password = "Roberspot";
const char* mqtt_server = "demo.thingsboard.io";

// MQTT autentifikaziorako erabiltzaile-izena eta pasahitza
const char* mqtt_user = "iq1YN6di6ahT8sYM7JZT";
const char* mqtt_password = "";

// DHT konfigurazioa
#define DHTPIN 4 // DHT11 datuen pina (GPIO4 = D2 NodeMCU-n)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQTT bezeroa
WiFiClient espClient;
PubSubClient client(espClient);

// MQTT gaiaren konfigurazioa
const char* topic = "v1/devices/me/telemetry";

// Funtzioak
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("WiFi-sarera konektatzen: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi-sarera konektatuta!");
  Serial.print("IP helbidea: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT zerbitzarira konektatzen...");
    if (client.connect("NodeMCUClient", mqtt_user, mqtt_password)) { // Autentifikazioa gehituta
      Serial.println("Konektatuta!");
    } else {
      Serial.print("Hutsegitea, kodea = ");
      Serial.print(client.state());
      Serial.println(" Saiatzen berriro 5 segundo barru...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);

  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

// Tenperatura, hezetasuna eta intza puntua irakurri eta bidali
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
// DHT irakurketa egiaztatu
if (isnan(temperature) || isnan(humidity)) {
  Serial.println("Errorea DHT datuak irakurtzean!");
  return;
}

// Intza puntua kalkulatu (Magnus-Tetens ekuazioa)
float a = 17.27;
float b = 237.7;
float alpha = ((a * temperature) / (b + temperature)) + log(humidity / 100.0);
float dewPoint = (b * alpha) / (a - alpha);

// JSON formatuan datuak prestatu
String payload = "{\"temperature\":";
payload += String(temperature);
payload += ",\"humidity\":";
payload += String(humidity);
payload += ",\"dewPoint\":";
payload += String(dewPoint);
payload += "}";

// MQTT argitalpena
if (client.publish(topic, payload.c_str())) {
  Serial.print("Datuak argitaratuta: ");
  Serial.println(payload);
} else {
  Serial.println("Argitalpena huts egin du!");
}

  delay(5000); // 5 segundoko tartea argitalpenen artean
}
