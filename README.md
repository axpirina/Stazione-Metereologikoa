# ESP8266an oinarrituriko Estazio Metereologikoa
ESP8266an oinarritutako estazio metereologikoa garatu dugu. Tenperatura (ºC) eta Hezetasuna (%) atzemango ditu eta Thingsboard DEMO plataforman bistarazi. Hezetasunari alarma bat jarriko digu neurri jakin batean.

## ERABILERA
 
 Thingsboard DEMO web-aren bitartez ikusiko dugu gure eztazio metereologikoa [Public Dashboard](https://demo.thingsboard.io/dashboard/71711470-d8d3-11ef-9dbc-834dadad7dd9?publicId=3cd10c30-53e6-11ed-a339-0708081d40ce). Thingsboard-en app-a ere instalatu dezakegu web-a mugikorrean ikusteko [Thingsboard APP](https://play.google.com/store/apps/details?id=org.thingsboard.demo.app). 
<p align="center">
  <img src="/Irudiak/Thingsboard.png" width="800" height="400">
</p>


## Hardwarea 
Eskema elektrikoa eta kaxa. 
<p align="center">
  <img src="/Irudiak/Scheme.png" width="400" height="300">
  <img src="/Irudiak/kaxa.jpeg" width="460" height="260">
</p>

## Elementuen lista

|Elementuak| Kantitatea | Link | 
|---|---|---|
| NodeMCU V2| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/placas-de-desarrollo/37815-placa-de-desarrollo-nodemcu-v2-lua-esp8266.html)|
| DHT11| 1 |[Electroson](https://www.electrosonsansebastian.com/eu/sensores/38012-sensor-de-temperatura-y-humedad-digital-dht11-para-arduino.html)|
| Jumper| 1 |[E-IKA](https://www.e-ika.com/cables-dupont-100cm-h-h-40-uds)|

> Oharra: 3D inprimagailu bat hobesten da kaxa egiteko.

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
   - PubSubClient.h
   - DHT.h

  Eta Horretarako hurrengo liburutegia konposatuak instalatzea nahikoa dela ikusi da 2025ean:
  
     - SimpleWifiClient by Toemblom
     - IoTtweet by Isaranu
     - DHT Sensor Libray by Adafruit
     - PubSubClient by Nick O`Leary

4. [Eztazioaren Arduino Kodea](/Station Arduino Code.ino)


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

