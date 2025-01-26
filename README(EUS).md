# Eguraldi Estazioa ESP8266 oinarrituta

**ESP8266** mikrokontroladorean oinarritutako eguraldi estazioa garatu dugu, ingurumenaren monitorizaziorako soluzio eraginkor eta kostu eraginkorra eskaintzen duena. Eguraldi estazio hau **Tenperatura (ºC)**, **Hezetasuna (%)** eta **Roska-puntua (ºC)** neurtzeko diseinatuta dago, eta datuak **Thingsboard DEMO** plataforman erakusten dira, ikuspegi eta analisi errazetarako.

<p align="center">
  <img src="/Irudiak/Thingsboard.png" width="800" height="400">
</p>

Ikusi egungo datuak **Thingsboard LIVE Dashboards**-ean, ondorengo [lotura](https://demo.thingsboard.io/dashboard/71711470-d8d3-11ef-9dbc-834dadad7dd9?publicId=3cd10c30-53e6-11ed-a339-0708081d40ce) klik eginez.

Sistemak ere **alarma bat martxan jartzeko** aukera du, hezetasun-mailak zein maila zehatz bat gainditzen duenean, ingurumen aldaketa kritikoetan alerta emateko. Ezaugarri hau bereziki erabilgarria da nekazaritza bezalako egoeretan, non hezetasun optimoa mantentzea funtsezkoa den, edo barruko inguruneetan, non airearen kalitatea kontrolatzea garrantzitsua den.

# Edukiak

Proiektu honek ez bakarrik IoT (Internet of Things) printzipioen aplikazio praktiko gisa balio du, baita ikasle eta zaletuentzako plataforma hezigarria ere:

- **Sentsoreen integrazioa:** Ikasi **ESP8266**-rekin tenperatura eta hezetasun sentsoreak nola konektatu.
- **Datuen komunikazioa:** Ulertu **MQTT** protokoloa, sentsoreen datuak hodeira bidaltzeko.
- **Plataformaren interakzioa:** Ikusi nola **Thingsboard**-ek datuak benetan bistaratzen dituen eta aurreratutako analisiak eskaintzen dituen.
- **Alarma sistemak:** Implementatu muga batzuetan oinarritutako alertak, ingurumen aldaketa berriak modu azkarragoan kudeatzeko.

## WEB Baliabideak

Eguraldi estazioa **Thingsboard DEMO** plataformaren bidez bistaratuko dugu, hodeiko datuen bistaratze, analisi eta gailuen kudeaketarako IoT soluzio indartsu bat. Ingurumen datuak, hala nola tenperatura, hezetasuna eta roska-puntua, interfazea intuitibo baten bidez kontrolatzeko aukera ematen digu. Thingsboard-ek aurreratutako ezaugarriak ere eskaintzen ditu, hala nola alerta sistemak eta egokitutako dashboard-ak ikuspuntu hobeak lortzeko.

<div align="center">
  <div style="display: flex; justify-content: center; align-items: center; gap: 200px;">
    <img src="/Irudiak/DEMO.png" width="600" height="300" style="margin-right: 50px;">
    <img src="/Irudiak/White.png" width="100" height="300" style="margin-right: 50px;">
    <img src="/Irudiak/App.jpg" width="150" height="300" style="margin-left: 50px;">
  </div>
</div>

Gainera, Thingsboard-ek Android aplikazio bat eskaintzen du, dashboard-ak mugikorrean bistaratzen dituztenak, erabiltzaileek euren datuak edonon eta noiznahi monitoriza ditzaten. Aplikazioa Google Play Store-n deskargatzeko aukera dago: [APP](https://play.google.com/store/apps/details?id=org.thingsboard.demo.app).

## Hardware Baliabideak
Eguraldi estazio hau eraikitzeko, honako hardware osagaiak beharrezkoak dira:

|Osagaia| Kantitatea | Lotura | Modelo|
|---|---|---|---|
| NodeMCU V2| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/placas-de-desarrollo/37815-placa-de-desarrollo-nodemcu-v2-lua-esp8266.html)|Amica|
| DHT11| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/sensores/38012-sensor-de-temperatura-y-humedad-digital-dht11-para-arduino.html)|Tº & Hº|
| Jumper Dupont| 1 |[E-IKA](https://www.e-ika.com/cables-dupont-100cm-h-h-40-uds)|Female-Female|

<div align="center">
  <div style="display: flex; justify-content: center; align-items: center; gap: 100px;">
    <img src="/Irudiak/kaxa.jpeg" width="460" height="260" style="margin-right: 10px;">
    <img src="/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="/Irudiak/DHT11.png" width="200" height="260" style="margin-right: 10px;">
    <img src="/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="/Irudiak/Dupont.png" width="200" height="260" style="margin-left: 10px;">
  </div>
</div>

> **Oharrak:** 3D inprimagailu bat gomendatzen da kasuaren etxebizitza sortzeko.
Hardware konfigurazio hau proiektuaren oinarrizko eta fidagarria da.
> Hardware etxebizitza proiektu honetarako aurkitu dezakezu hurrengo loturan:
[Hardware Etxebizitza Proiekturako Lotura](https://www.thingiverse.com/thing:2510742)

## NodeMCU V2 Pinout
Kontuan izan NodeMCU-ren GPIO zenbakiak zehaztu behar direla Arduino kodean.

<p align="center">
  <img src="/Irudiak/NodeMCU_Pinout.png" width="800" height="600">
</p>

## Eskema Elektrikoa
Behean, elektrikoen zirkuituaren eskema aurkituko duzu. Ziurtatu guztiak ondo konektatzen dituzula eta zirkuituari konektatutako pinak definitzen dituzula programan. Eskema elektrikoa **Fritzing**-en erabiliz sortu da.

<p align="center">
  <img src="/Irudiak/Scheme.png" width="600" height="450">
</p>

> **Oharrak:** Konektatzen dituzun guztiak ondo konektatzen direla eta tentsioaren polaritateak errespetatzen direla ziurtatu.

## Arduino IDE
ESP8266 mikrokontroladorea programatzeko, Arduino IDE eta hainbat liburutegi beharrezkoak dira. Funtsean, **ESP8266-DHT.ino** fitxategia **NodeMCU**-ra igo behar da **Arduino IDE**-ren bidez. Jarraitu pauso hauek:

1. [Arduino IDE Deskargatu](https://www.arduino.cc/en/software)

<p align="center">
  <img src="/Irudiak/IDE.jpg" width="600" height="450">
</p>

3. [NodeMCU Arduino IDE-n Instalatu](https://projecthub.arduino.cc/PatelDarshil/getting-started-with-nodemcu-esp8266-on-arduino-ide-b193c3)
<p align="center">
  <img src="/Irudiak/Board.png" width="600" height="300">
</p>

5. Hona hemen beharrezko liburutegiak Arduino IDE-n instalatzeko. Hori egiteko, ireki Library Manager-a **Sketch** > **Include Library** > **Manage Libraries** bidez.
   - ESP8266WiFi.h
   - PubSubClient.h
   - DHT.h

  Era berean, 2025etik aurrera, ondorengo liburutegi konpilatuak nahikoa direla frogatu da:

  - SimpleWifiClient Toemblom-en eskutik
  - IoTtweet Isaranu-ren eskutik
  - DHT Sensor Library Adafruit-ekoa
  - PubSubClient Nick O'Leary-ren eskutik

## Arduino Kodea
Kode hau NodeMCU-ra igo dezakezu. Denak ondo joan bada, kodearen parametroak konfiguratzeko atala aurkituko duzu aurrerago.
 [Eguraldi Estazioko Arduino Kodea](/StationArduinoCode.ino)

```cpp
/*ESP8266 Eguraldi Estazioa Thingsboard Integratuekin. Proiektu honek **ESP8266** mikrokontroladorea erabiltzen du ingurumeneko datuak (tenperatura, hezetasuna, eta roska-puntua) monitorizatzeko
eta **Thingsboard** IoT plataformara MQTT bidez bidaltzeko.
Kode hau Creative Commons lizentziapean dago.
Axpi-ren eskutik.
*/

#include <ESP8266WiFi.h> // WiFi liburutegia ESP8266-rentzat
#include <PubSubClient.h>
#include <DHT.h>

// WiFi eta MQTT konfigurazioa
const char* ssid = "zureWiFiSSID";    // Zure WIFI izena jarri
const char* password = "zureWiFiPasahitza";   // Zure WIFI pasahitza jarri 
const char* mqtt_server = "demo.thingsboard.io";  // Mantendu berdin

// MQTT autentifikazioa
const char* mqtt_user = "zureDispositiboToken";   // ThingsboardDemo.io-n gailu berri bat sortu eta haren sarbide-tokens hartu.
const char* mqtt_password = "";     // Mantendu berdin

// DHT konfigurazioa
#define DHTPIN 2 // DHT11 datu pin-a (GPI14 = D5 NodeMCU-n)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQTT bezeroa
WiFiClient espClient;
PubSubClient client(espClient);

// MQTT gaia konfigurazioa
const char* topic = "v1/devices/me/telemetry";   // Mantendu berdin

// Funtzioak
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

  Serial.println("");
  Serial.println("WiFi-ra konektatuta!");
  Serial.print("IP helbidea: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT zerbitzariari konektatzen...");
    if (client.connect("NodeMCUClient", mqtt_user, mqtt_password)) { // Autentifikatutako konexioa
      Serial.println("Konektatuta!");
    } else {
      Serial.print("Ezin konektatu, errore kodea = ");
      Serial.print(client.state());
      Serial.println(". 5 segundoan berriro saiatuko...");
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

  // Tenperatura eta hezetasuna irakurri, roska-puntua kalkulatu
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // DHT irakurketa baliodunak diren egiaztatu
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT sentsorearen datuak irakurtzeko huts egin da!");
    return;
  }

  // Roska-puntua kalkulatu (Magnus-Tetens ekuazioa)
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

  // Datuak MQTT bidez argitaratu
  if (client.publish(topic, payload.c_str())) {
    Serial.print("Datuak argitaratuta: ");
    Serial.println(payload);
  } else {
    Serial.println("Argitalpena huts egin da!");
  }

  delay(5000); // Argitalpenaren tartea, 5 segundo
}

## Konfigurazioa
Arduino kodean gure Wifi-a eta Thingsboard-eko Device-a konfiguratu beharko ditugu.

 > WIFI-a: ESP8266-DHT.ino artxiboan termostatoa zein wifi-tara konektatuko den konfiguratu. Wifi honek **192.168.1.X** tartean banatu beharko ditu helbideak.
~~~
const char* ssid     = "yourWiFiSSID";            
const char* password = "yourWiFiPassword"; 
~~~
 
  > THINGSBOARD-eko KONFIGURAZIOA: MQTT broket, topic eta decive token-a.
~~~
const char* mqtt_server = "demo.thingsboard.io";
const char* mqtt_user = "yourDeviceToken";
const char* mqtt_password = "";

const char* topic = "v1/devices/me/telemetry";
~~~

> DATUEN MAIZTASUNA KONFIGURATU: Datuak zenbatero igoko diren erabaki.

~~~
delay(5000); // 5 segundoko tartea argitalpenen artean
~~~

## Estekak
 
Diy IOT Tknika [https://youtu.be/uq5OR8RlGLc](https://www.youtube.com/watch?v=z61bxGR6Poo&list=PLOYSs5_FlYNtzRIuRgQhgzTNdCzludb6r&index=24)
NODE RED eta THINGSBOARD Oteitza Lizeoa [https://youtu.be/uq5OR8RlGLc](https://www.youtube.com/playlist?list=PLLzgegoyyqcNHDIyPvh3pWa9Zu6rSWcN-)

