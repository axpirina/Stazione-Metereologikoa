# ESP8266an oinarrituriko Estazio Metereologikoa
ESP8266an oinarritutako estazio metereologikoa garatu dugu. Tenperatura (ºC) eta Hezetasuna (%) atzemango ditu eta Thingsboard DEMO plataforman bistarazi. Hezetasunari alarma bat jarriko digu neurri jakin batean.

## ERABILERA
 
 Thingsboard DEMO web-aren bitartez ikusiko dugu gure eztazio metereologikoa [Public Dashboard]([http://192.168.1.201](https://demo.thingsboard.io/dashboard/71711470-d8d3-11ef-9dbc-834dadad7dd9?publicId=3cd10c30-53e6-11ed-a339-0708081d40ce)). Thingsboard-en app-a ere instalatu dezakegu web-a mugikorrean ikusteko [Thingsboard APP]((https://play.google.com/store/apps/details?id=org.thingsboard.demo.app)). 
<p align="center">
  <img src="/Irudiak/Thingsboard.png" width="800" height="600">
</p>


## Hardwarea 
Eskema elektrikoa eta kaxa. 
<p align="center">
  <img src="/Irudiak/Termostatoa_bb.png" width="880" height="300">
  <img src="/Irudiak/kaxa.jpeg" width="460" height="260">
</p>

## Elementuen lista

|Elementuak| Kantitatea | Link | 
|---|---|---|
| NodeMCU V2| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/placas-de-desarrollo/37815-placa-de-desarrollo-nodemcu-v2-lua-esp8266.html)|
| DHT11| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/sensores/38012-sensor-de-temperatura-y-humedad-digital-dht11-para-arduino.html)|
| 1 Relay Shield| 1 |[E-IKA](https://www.e-ika.com/modulo-rele-1-canal-para-arduino)|
| Jumper| 1 |[E-IKA](https://www.e-ika.com/cables-dupont-100cm-h-h-40-uds)|

> Oharra: Relay shield-a erosterako garaian kontuan izan 3,3V tako irteerez gidatu daitekeen errelea izan behar duela, ez 5Vz soilik. HON WEI etxeko JQC3F errele shield-ek adibidez funtzio hau betetzen dute.

## NODEMCU V2 aren Pinout-a
Oso kontuan izan Arduino kodean Nodemcu-aren GPIO zenbakiak adierazi beharko dituzuela.
<p align="center">
  <img src="/Irudiak/NodeMCU_Pinout.png" width="800" height="600">
</p>


## Arduino IDE-a eta Kodea
ESP8266 mikrokontrolagailua programatu ahal izateko Arduino IDE-a eta zenbait liburutegi beharko ditugu. Oinarrian **Arduino IDE**-aren bitartez **ESP8266-DHT.ino** artxiboa **NodeMCU**-ra igo beharko dugu.

1. [Arduino IDE Download](https://www.arduino.cc/en/software)
2. [Installing NodeMCU on Arduino IDE](https://projecthub.arduino.cc/PatelDarshil/getting-started-with-nodemcu-esp8266-on-arduino-ide-b193c3)
3. Hurrengo liburutegiak instalatu Arduino IDE-an.
   - ESP8266WiFi.h
   - WiFiClient.h
   - ESP8266WebServer.h
   - FS.h 
   - ctype.h 
   - DHT.h

  Eta Horretarako hurrengo liburutegia konposatuak instalatzea nahikoa dela ikusi da 2025ean:
  
     - SimpleWifiClient by Toemblom
     - IoTtweet by Isaranu
     - DHT Sensor Libray by Adafruit
     - AVision_ESP8266 by AVision

4. [Termostatoaren Arduino Kodea](/ESP8266-DHT.ino)


## Konfigurazioa
Arduino kodean gure Wifi-a eta hozgailuaren Tºak konfiguratu beharko ditugu.

 > WIFI-a: ESP8266-DHT.ino artxiboan termostatoa zein wifi-tara konektatuko den konfiguratu. Wifi honek **192.168.1.X** tartean banatu beharko ditu helbideak.
~~~
const char* ssid     = "yourWiFiSSID";            
const char* password = "yourWiFiPassword"; 
~~~
 
  > Tº KONFIGURAZIOA: ESP8266-DHT.ino artxiboan hozgailuaren Tº max eta min konfiguratu (ºC).
~~~
int heatOn = 5;
int heatOff = 15;
~~~

> IP HELBIDEA KONFIGURATU: Zuen sareko egituraren arabera IP helbide bat eman NodeMcu-ari.

**Adibide honetako IP helbidea:** `192, 168, 0, 201`

~~~
WiFi.config(IPAddress(192, 168, 0, 201), IPAddress(192, 168, 0, 1), IPAddress(255, 255, 255, 0));
~~~

## Estekak
 
Adibide bideoa https://youtu.be/uq5OR8RlGLc

Instructables https://www.instructables.com/ESP8266-12E-DHT-Thermostat/

### Thanks to @dmainmon
