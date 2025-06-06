# ESP8266an oinarrituriko Estazio Metereologikoa
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Oteitza.png" width="280" height="80">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="100" height="100">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Vincenza.png" width="300" height="100">
</p>

**ESP8266** mikroprozesagailuan oinarritutako eguraldi-estazio bat garatu dugu, ingurumenaren jarraipena egiteko irtenbide eraginkor eta merke bat eskainiz. Estazio honek tenperatura (ºC), hezetasuna (%) eta ihar-puntua (ºC) neurtzen ditu, eta datuak Thingsboard DEMO plataforman bistaratzen dira, modu errazean ikusi eta aztertzeko aukera emanez.  


<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Thingsboard.png" width="800" height="400">
</p>

Momentuko datuak **Thingsboard LIVE Dashboard** ean ikusi ondorengo esteka klikatuaz [link](https://demo.thingsboard.io/dashboard/71711470-d8d3-11ef-9dbc-834dadad7dd9?publicId=3cd10c30-53e6-11ed-a339-0708081d40ce)

Sistemak **alarma** bat konfiguratua du hezetasun mailak balio jakin bat gainditzen duenean, hezetasun aldaketen denbora errealeko jarraipen bat egiteko gai den einean. Gaitasun hau zinez interesgarria da nekazaritza, edo industria bezalako sektoreetan non hezetasun balioak berebiziko garrantzia duten.  

# Edukiak 

Proiektu honek IoT (Internet of Things) inguruneak lantzeaz gain ikaskuntza plataforma bat eskaintzen du ikerkuntzan sakondu nahi duten ikasleentzat.   
- **Sentsoreen integrazioa:** Ikasi **ESP8266** gailuarekin tenperatura naiz hezetasuna bistaratzen.  
- **Datuen komunikazioa:** **MQTT** protokoloa ulertu eta erabili sentsoreen datuak lainora bidaltzeko.   
- **Plataformen integrazioa:** **Thingsboard** plataforma erabiliaz denbora errealeko datuak irudikatu.   
- **Alarma sistemak:** Ingurune aldaketen jakitun egingo gaituen alarma garatzen ikasi.   


## WEB Resources

Gure estazio metereologikoa [Thingsboard DEMO](https://demo.thingsboard.io/) web plataforma erabiliaz garatuko dugu. Thingsboard denbora errealeko datuen bistaratzea, analisia eta gailuen kudeaketa ahalbidetzen dituen IoT irtenbide indartsua da. Ingurumen-datuak, hala nola tenperatura, hezetasuna eta ihar-puntua, interfaze intuitibo baten bidez kontrolatzeko aukera ematen digu. Gainera, Thingsboard-ek funtzionalitate aurreratuak eskaintzen ditu, alarma-sistemak eta norabide pertsonalizagarriak barne, informazio sakonagoa lortzeko.

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/DEMO.png" width="600" height="300">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="150" height="300">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/App.jpg" width="150" height="300">
</p>



Gainera, Thingsboard-ek Android aplikazio natibo bat eskaintzen du, mugikorretako gailuetan panela ikusteko aukera ematen duena. Horri esker, erabiltzaileek beren datuak edonon eta edonoiz monitorizatu ditzakete. Aplikazioa Google Play Store-n eskuragarri dago deskargatzeko. [APP](https://play.google.com/store/apps/details?id=org.thingsboard.demo.app).

## Elementuak
Eguraldi-estazio hau eraikitzeko, ondorengo hardware osagaiak behar dira:

|Elementuak| kantitatea | Esteka | Modeloa|
|---|---|---|---|
| NodeMCU V2| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/placas-de-desarrollo/37815-placa-de-desarrollo-nodemcu-v2-lua-esp8266.html)|Amica|
| DHT11| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/sensores/38012-sensor-de-temperatura-y-humedad-digital-dht11-para-arduino.html)|Tº & Hº|
| Jumper Dupont| 1 |[E-IKA](https://www.e-ika.com/cables-dupont-100cm-h-h-40-uds)|Female-Female|

<div align="center">
  <div style="display: flex; justify-content: center; align-items: center; gap: 100px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/kaxa.jpeg" width="460" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/DHT11.png" width="200" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Dupont.png" width="200" height="260" style="margin-left: 10px;">
  </div>
</div>

> **Oharra:** Estalkia sortzeko, 3D inprimagailu bat erabiltzea gomendatzen da.
Hardware-konfigurazio honek proiektuarentzat oinarri eraginkor eta fidagarria eskaintzen du.
> Proiektu honetarako estalki posible bat ondorengo estekan aurki dezakezu:
[Link to the Hardware Enclosure Project](https://www.thingiverse.com/thing:2510742) - 
[Another link to the Hardware Enclosure Project](https://www.thingiverse.com/thing:4864299)

## NodeMCU V2 konexioak
Gogoratu NodeMCU-ren GPIO zenbakiak zehaztu behar direla Arduino kodean.
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/NodeMCU_Pinout.png" width="800" height="600">
</p>

## Eskema elektrikoa
Behean aurkituko duzu zirkuitu elektrikoaren eskema.
Ziurtatu dena zuzenean konektatzen duzula eta eskeman konektatutako pinak programan zehazten dituzula.
Zirkuitu elektrikoaren eskema hau [Fritzing](https://www.fritzing.com). erabiliz sortu da 

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Scheme.png" width="600" height="450">
</p>

> **Oharra:** Mesedez, ziurtatu konekzio guztiak ondo egin direla eta tentsioaren polaritateak errespetatu direla.

## Sare eskema
Behean aurkituko duzu sare-zirkuituaren eskema. Ziurtatu zure WiFi-ra zuzenean konektatzen zarala. Sare-zirkuituaren eskema hau  [Draw.io](https://www.draw.io). erabiliaz sortu da

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Network.png" width="600" height="600">
</p>

> **Oharra:** Mesedez, ziurtatu zure lekuaren arabera zure WiFi sarearen konfigurazioa egokia dela.

## Arduino IDEa
ESP8266 mikroprozesagailua programatzeko, Arduino IDE eta hainbat liburutegi beharko dituzu. Orokorrean, ESP8266-DHT.ino fitxategia NodeMCU-ra igo behar da Arduino IDE erabiliz. Jarraitu hurrengo pausoak:

1. [Arduino IDE jaitsi](https://www.arduino.cc/en/software)

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/IDE.jpg" width="600" height="450">
</p>
   
3. [NodeMCUa instalatu Arduino IDEan](https://projecthub.arduino.cc/PatelDarshil/getting-started-with-nodemcu-esp8266-on-arduino-ide-b193c3)
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Board.png" width="600" height="300">
</p>

   
5. Ondorengo liburutegiak Arduino IDEan instalatu. Horretarako, ireki Library Manager hau egiten: jo Sketch > Include Library > Manage Libraries.
   - ESP8266WiFi.h
   - PubSubClient.h
   - DHT.h

    Gainera, 2025etik aurrera, honako liburutegi konpilatu hauek izan dira nahikoak:

     - SimpleWifiClient by Toemblom
     - IoTtweet by Isaranu
     - DHT Sensor Library by Adafruit
     - PubSubClient by Nick O`Leary


## Arduino Kodea
Jarraian emandako Arduino kodea igo NodeMCU-ra. Denak ondo joan badira, aurrerago kodea gehiago parametrizatzeko atala aurkituko duzu.
 [Arduino kodea](/StationArduinoCode.ino)

```cpp
/*ESP8266 Weather Station with Thingsboard Integration. This project demonstrates how to use the **ESP8266** microcontroller to monitor environmental data (temperature, humidity, and dew point)
and send it to the **Thingsboard** IoT platform via MQTT.
This code is under a Creative Commons license.
By Axpi.
*/

#include <ESP8266WiFi.h> // WiFi library for ESP8266
#include <PubSubClient.h>
#include <DHT.h>

// WiFi and MQTT configuration
const char* ssid = "yourWiFiSSID";    // Give your WIFI name
const char* password = "yourWiFiPassword";   // Give your WIFI password 
const char* mqtt_server = "demo.thingsboard.io";  // Leave as it is

// MQTT authentication
const char* mqtt_user = "yourDeviceToken";   // Create a new Device in ThingboardDemo.io and get its access token.
const char* mqtt_password = "";     // Leave as it is

// DHT configuration
#define DHTPIN 2 // DHT11 data pin (GPI14 = D5 on NodeMCU)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// MQTT topic configuration
const char* topic = "v1/devices/me/telemetry";   // Leave as it is

// Functions
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT server...");
    if (client.connect("NodeMCUClient", mqtt_user, mqtt_password)) { // Authenticated connection
      Serial.println("Connected!");
    } else {
      Serial.print("Failed, error code = ");
      Serial.print(client.state());
      Serial.println(". Retrying in 5 seconds...");
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

  // Read temperature, humidity, and calculate dew point
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if the DHT readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read data from DHT sensor!");
    return;
  }

  // Calculate dew point (Magnus-Tetens equation)
  float a = 17.27;
  float b = 237.7;
  float alpha = ((a * temperature) / (b + temperature)) + log(humidity / 100.0);
  float dewPoint = (b * alpha) / (a - alpha);

  // Prepare data in JSON format
  String payload = "{\"temperature\":";
  payload += String(temperature);
  payload += ",\"humidity\":";
  payload += String(humidity);
  payload += ",\"dewPoint\":";
  payload += String(dewPoint);
  payload += "}";

  // Publish data via MQTT
  if (client.publish(topic, payload.c_str())) {
    Serial.print("Data published: ");
    Serial.println(payload);
  } else {
    Serial.println("Publish failed!");
  }

  delay(5000); // Publish interval of 5 seconds
}
```

## Konfigurazioa
Parametrizatu honako aldagai hauek Arduino kodean, zure proiektuaren azpiegituraren arabera.

 > WIFI konfigurazioa: ESP8266a zure WiFi sarearekin konektatzen du, zure SSID eta pasahitza erabiliz.
```cpp
const char* ssid     = "yourWiFiSSID";   // Give your WIFI name           
const char* password = "yourWiFiPassword"; // Give your WIFI password  
```
  > MQTT konfigurazioa: Gailuak Thingsboard zerbitzariarekin konektatzen da MQTT bidez, autentifikazioarekin (gailuaren tokena mqtt_user gisa erabiliz).
```cpp
const char* mqtt_server = "demo.thingsboard.io";   // Leave as it is
const char* mqtt_user = "yourDeviceToken";     // Create a new Device in https://demo.thingsboard.io and get its access token.
const char* mqtt_password = "";     // Leave as it is
```
  > DHT11 eta NODEMCU konexioa:  Begiratu zirkuitu elektrikoari. DHT11a konektatuta dago D5 (GPIO14) pinera.
```cpp
#define DHTPIN 14 // DHT11 data pin (GPI14 = D5 on NodeMCU)
```
 > MQTT Topika: Thingsboard APIk gai hau izatea eskatzen du (topic hau izan behar da):
```cpp
const char* topic = "v1/devices/me/telemetry";   // Leave as it is
```

> LAGINKETA MAIZTASUNA: Erabaki zein maiztasunekin bidaliko diren datuak.
```cpp
delay(5000); // Interval of 5 seconds between publications
```

## Estekak                            
 
Diy IOT Tknika [Diy IOT Tknika](https://www.youtube.com/watch?v=z61bxGR6Poo&list=PLOYSs5_FlYNtzRIuRgQhgzTNdCzludb6r&index=24)  
NODE RED and THINGSBOARD Oteitza Lizeoa [NODE RED and THINGSBOARD Oteitza Lizeoa](https://www.youtube.com/playlist?list=PLLzgegoyyqcNHDIyPvh3pWa9Zu6rSWcN-)

## License

This project is licensed under a Creative Commons Attribution 4.0 International License.
You are free to:

    Share — copy and redistribute the material in any medium or format.
    Adapt — remix, transform, and build upon the material for any purpose, even commercially.

As long as you provide proper attribution to the original author.
<p align="center"> <a href="https://creativecommons.org/licenses/by/4.0/"> <img src="https://i.creativecommons.org/l/by/4.0/88x31.png" alt="Creative Commons License"> </a> </p>

