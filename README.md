# ESP8266an oinarrituriko Estazio Metereologikoa
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Oteitza.png" width="280" height="80">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="100" height="100">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Vincenza.png" width="300" height="100">
</p>

**ESP8266** mikroprozesagailuan oinarritutako eguraldi-estazio bat garatu dugu, ingurumenaren jarraipena egiteko irtenbide eraginkor eta merke bat eskainiz. Estazio honek **tenperatura (ºC)**, **hezetasuna (%)** eta **ihar-puntua (ºC)** neurtzen ditu, eta datuak **Thingsboard DEMO** plataforman bistaratzen dira, modu errazean ikusi eta aztertzeko aukera emanez.  


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

Gure estazio metereologikoa [Thingsboard DEMO](https://demo.thingsboard.io/) web plataforma erabiliaz garatuko dugu. **Thingsboard** denbora errealeko datuen bistaratzea, analisia eta gailuen kudeaketa ahalbidetzen dituen IoT irtenbide indartsua da. Ingurumen-datuak, hala nola **tenperatura**, **hezetasuna** eta **ihar-puntua**, interfaze intuitibo baten bidez kontrolatzeko aukera ematen digu. Gainera, Thingsboard-ek funtzionalitate aurreratuak eskaintzen ditu, **alarma-sistemak** eta norabide pertsonalizagarriak barne, informazio sakonagoa lortzeko.


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
| DHT11| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/sensores/38012-sensor-de-temperatura-y-humedad-digital-dht11-para-arduino.html)|Tº eta Hº|
| Jumper Dupont| 1 |[E-IKA](https://www.e-ika.com/cables-dupont-100cm-h-h-40-uds)|Emea-Emea|

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
Behean aurkituko duzu sare-zirkuituaren eskema. Ziurtatu zure **WiFi**-ra zuzenean konektatzen zarala. Sare-zirkuituaren eskema hau  [Draw.io](https://www.draw.io). erabiliaz sortu da

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Network.png" width="600" height="600">
</p>

> **Oharra:** Mesedez, ziurtatu zure lekuaren arabera zure **WiFi** sarearen konfigurazioa egokia dela.

## Pausoz pauso Thingsboard plataforman DEVICE bat sortzen
Lehenengo lainora bidaliko ditugun datuak biltegiratuko dituen **Device** bat sortu behar dugu **Thingsboard**en. Jarraitu hurrengo pausoak:

1. [Thingsboard DEMO ireki](https://demo.thingsboard.io) eta **Device** berria sortu.

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Device.png" width="900" height="450">
</p>
   
2. **Device** horretan sartu eta **Access token**a kopiatu. Arduino programan txertatu beharko dugu ondoren.
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/AccessToken.png" width="800" height="300">
</p>


## Pausoz Pauso Programa NodeMCU-an txertatzen
**ESP8266** mikroprozesagailua programatzeko, **Arduino IDE** eta hainbat liburutegi beharko dituzu. Orokorrean, **ESP8266-DHT.ino** fitxategia **NodeMCU**-ra igo behar da Arduino IDE erabiliz. Jarraitu hurrengo pausoak:

1. [Arduino IDE jaitsi](https://www.arduino.cc/en/software)

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/IDE.jpg" width="600" height="450">
</p>
   
2. **NodeMCU**a **Arduino IDE**an instalatzeko **Files** > **Preferences** > **Aditional Board Manager URLs** atalean ondorengo esteka idatzi.
   - http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. **Plaka** zerrenda instalatzeko **Tools** > **Boards** > **Board Manager....** atalean **ESP8266** idatzi eta:
   - **ESP8266 by ESP8266 community** instalatu.

4. [CP2102 Driverrak instalatu](https://www.pololu.com/file/0J14/pololu-cp2102-windows-220616.zip). Jaitsitako artxiboa deskonprimatu eta: 
   - **pololu-cp2102-setup-x64.exe** exekutatu.
   
5. Ondorengo liburutegiak **Arduino IDE**an instalatu. Horretarako, ireki **Library Manager** hau egiten: jo **Sketch** > **Include Library** > **Manage Libraries** eta azpiko liburutegiak aurkitu.
   - ESP8266WiFi.h
   - PubSubClient.h
   - DHT.h

    Aurkitzen dituzuenean azalduko zaizkizuen zerrendatik ondorengo liburutegia sortak instalatu:

     - IoTtweet by Isaranu
     - PubSubClient by Nick O`Leary
     - DHT Sensor Library by Adafruit

6. Hurrengo atalean aurkituko duzuen **Arduino kodea** moldatu eta  **NodeMCU**ra bidaltzea soilik geratzen zaizue. 

## Arduino Kodea
Jarraian emandako **Arduino kodea** igo **NodeMCU**-ra. Denak ondo joan badira, aurrerago kodea gehiago parametrizatzeko atala aurkituko duzu.
 [Arduino kodea](/StationArduinoCode.ino)

```cpp
/*ESP8266 Eguraldi Estazioa Thingsboard integrazioarekin
Proiektu honek erakusten du nola erabili ESP8266 mikroprozesagailua ingurumen-datuak (tenperatura, hezetasuna eta ihar-puntua) monitorizatzeko eta Thingsboard IoT plataformara MQTT bidez bidaltzeko.
Kode hau Creative Commons lizentziapean dago.
Egilea: Axpi.
*/

#include <ESP8266WiFi.h> // ESP8266 platarako WiFi liburutegia
#include <PubSubClient.h>
#include <DHT.h>

// WiFi eta MQTT konfigurazioa
const char* ssid = "yourWiFiSSID";
const char* password = "yourWiFiPassword";
const char* mqtt_server = "demo.thingsboard.io";

// MQTT autentifikaziorako erabiltzaile-izena eta pasahitza
const char* mqtt_user = "yourDeviceToken";
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
```

## Konfigurazioa
Parametrizatu honako aldagai hauek Arduino kodean, zure proiektuaren azpiegituraren arabera.

 > **WIFI konfigurazioa**: ESP8266a zure **WiFi** sarearekin konektatzen du, zure **SSID** eta **pasahitza** erabiliz.
```cpp
const char* ssid     = "yourWiFiSSID";   // Ikastolako WIFIaren izena         
const char* password = "yourWiFiPassword"; // WIFIaren pasahitza 
```
  > **MQTT konfigurazioa**: Gailuak Thingsboard zerbitzariarekin konektatzen da MQTT bidez, autentifikazioarekin (gailuaren tokena mqtt_user gisa erabiliz).
```cpp
const char* mqtt_server = "demo.thingsboard.io";   // Thingsboard Demoren helbidea
const char* mqtt_user = "yourDeviceToken";     // Sortu gailu berri bat helbidean: https://demo.thingsboard.io eta lortu haren access token-a.
const char* mqtt_password = "";     // Hutsa utzi
```
  > **DHT11 eta NODEMCU konexioa**:  Begiratu zirkuitu elektrikoari. DHT11a konektatuta dago D5 (GPIO14) pinera.
```cpp
#define DHTPIN 14 // DHT11 data pin (GPI14 = D5 on NodeMCU)
```
 > M**QTT Topika**: Thingsboard APIk gai hau izatea eskatzen du (topic hau izan behar da):
```cpp
const char* topic = "v1/devices/me/telemetry";   // Horrela de Thingsboard-en APIa
```

> **LAGINKETA MAIZTASUNA**: Erabaki zein maiztasunekin bidaliko diren datuak.
```cpp
delay(5000); // 5sg tako tartea datuak bidaltzen
```

## Estekak                            
 
Diy IOT Tknika [Diy IOT Tknika](https://www.youtube.com/watch?v=z61bxGR6Poo&list=PLOYSs5_FlYNtzRIuRgQhgzTNdCzludb6r&index=24)  
NODE RED eta THINGSBOARD Oteitza Lizeoa [NODE RED and THINGSBOARD Oteitza Lizeoa](https://www.youtube.com/playlist?list=PLLzgegoyyqcNHDIyPvh3pWa9Zu6rSWcN-)

## License

Proiektu hau Creative Commons Attribution 4.0 International License lizentziapean dago.
Aske zara:

    Banatzeko —  kopiatu eta berriz banatu dezakezu edozein medio edo formatuan.
    Aldatzeko —  garatu, eraldatu eta oinarri hartuta proiektu berriak sortu ditzakezu edozein helburutarako, baita merkataritzarako ere.

Jatorrizko egileari egokia den aipamena ematen badiozu.
<p align="center"> <a href="https://creativecommons.org/licenses/by/4.0/"> <img src="https://i.creativecommons.org/l/by/4.0/88x31.png" alt="Creative Commons License"> </a> </p>

