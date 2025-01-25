# Weather Station Based on ESP8266  

We have developed a weather station based on the **ESP8266** microcontroller, providing an efficient and cost-effective solution for environmental monitoring. This weather station is designed to measure **Temperature (ºC)**, **Humidity (%)** and **Dew Point (ºC)** with the data being displayed on the **Thingsboard DEMO** platform for easy visualization and analysis.  

<p align="center">
  <img src="/Irudiak/Thingsboard.png" width="800" height="400">
</p>

View the real-time data on **Thingsboard LIVE Dashboard** by clicking the following [link](https://demo.thingsboard.io/dashboard/71711470-d8d3-11ef-9dbc-834dadad7dd9?publicId=3cd10c30-53e6-11ed-a339-0708081d40ce)

The system also includes a feature to **trigger an alarm** when the humidity level surpasses a specific threshold, ensuring real-time awareness of critical environmental changes. This capability is especially useful in scenarios like agriculture, where maintaining optimal humidity is crucial, or in indoor environments where air quality monitoring is a priority.  

# Contents 

This project not only serves as a practical application of IoT (Internet of Things) principles but also offers an educational platform for students and enthusiasts to explore:  
- **Sensor integration:** Learn how to interface temperature and humidity sensors with the **ESP8266**.  
- **Data communication:** Understand the **MQTT** protocol used to send sensor data to the cloud.  
- **Platform interaction:** Explore how **Thingsboard** visualizes real-time data and allows for advanced analytics.  
- **Alarm systems:** Implement threshold-based alerts for improved responsiveness to environmental changes.  


## WEB Resources

We will visualize our weather station using the [Thingsboard DEMO](https://demo.thingsboard.io/) web platform, a powerful IoT solution designed for real-time data visualization, analytics, and device management. It allows us to monitor our environmental data, such as temperature, humidity, and dew point, through an intuitive interface. Thingsboard also supports advanced features such as alert systems and customizable dashboards for better insights.

<div align="center">
  <div style="display: flex; justify-content: center; align-items: center; gap: 200px;">
    <img src="/Irudiak/DEMO.png" width="600" height="300" style="margin-right: 50px;">
    <img src="/Irudiak/White.png" width="100" height="300" style="margin-right: 50px;">
    <img src="/Irudiak/App.jpg" width="150" height="300" style="margin-left: 50px;">
  </div>
</div>

Additionally, Thingsboard offers a native Android app for viewing dashboards on mobile devices, ensuring that users can monitor their data anywhere and anytime. The app is available for download from the Google Play Store [APP](https://play.google.com/store/apps/details?id=org.thingsboard.demo.app).



## Hardware Resouces
To build this weather station, the following hardware components are necessary:

|Component| Quantity | Link | Model|
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

> **Note:** A 3D printer is recommended to create the enclosure.
This hardware setup provides an efficient and reliable foundation for the project.
> You can find a possible hardware enclosure for this project at the following link:
[Link to the Hardware Enclosure Project](https://www.thingiverse.com/thing:2510742)


## NodeMCU V2 Pinout
Keep in mind that the GPIO numbers of the NodeMCU must be specified in the Arduino code.
<p align="center">
  <img src="/Irudiak/NodeMCU_Pinout.png" width="800" height="600">
</p>

## Hardware Resouces
Electrical scheme and enclosure. 
<p align="center">
  <img src="/Irudiak/Scheme.png" width="400" height="300">
  <img src="/Irudiak/kaxa.jpeg" width="460" height="260">
</p>

[Enclosure](https://www.thingiverse.com/thing:2510742)



## Arduino IDE and Code
To program the ESP8266 microcontroller, you will need the Arduino IDE and several libraries. Essentially, the **ESP8266-DHT.ino** file must be uploaded to the **NodeMCU** using **Arduino IDE**.

1. [Arduino IDE Download](https://www.arduino.cc/en/software)
2. [Installing NodeMCU on Arduino IDE](https://projecthub.arduino.cc/PatelDarshil/getting-started-with-nodemcu-esp8266-on-arduino-ide-b193c3)
3. Install the following libraries in Arduino IDE:
   - ESP8266WiFi.h
   - PubSubClient.h
   - DHT.h

  Additionally, as of 2025, the following compiled libraries have been found sufficient:

     - SimpleWifiClient by Toemblom
     - IoTtweet by Isaranu
     - DHT Sensor Library by Adafruit
     - PubSubClient by Nick O`Leary

4. [Arduino Code for the Station](/StationArduinoCode.ino)

## Configuration
In the Arduino code, configure your WiFi and the Thingsboard device.

 > WIFI: Configure the thermostat to connect to the desired WiFi in the **ESP8266-DHT.ino** file. The WiFi must distribute addresses in the **192.168.1.X** range.
~~~
const char* ssid     = "yourWiFiSSID";            
const char* password = "yourWiFiPassword"; 
~~~
 
  > THINGSBOARD CONFIGURATION: MQTT broker, topic, and device token.
~~~
const char* mqtt_server = "demo.thingsboard.io";
const char* mqtt_user = "yourDeviceToken";
const char* mqtt_password = "";

const char* topic = "v1/devices/me/telemetry";
~~~

> CONFIGURE DATA FREQUENCY: Decide how often data will be sent.

~~~
delay(5000); // Interval of 5 seconds between publications
~~~

## Links
 
Diy IOT Tknika [https://youtu.be/uq5OR8RlGLc](https://www.youtube.com/watch?v=z61bxGR6Poo&list=PLOYSs5_FlYNtzRIuRgQhgzTNdCzludb6r&index=24)  
NODE RED and THINGSBOARD Oteitza Lizeoa [https://youtu.be/uq5OR8RlGLc](https://www.youtube.com/playlist?list=PLLzgegoyyqcNHDIyPvh3pWa9Zu6rSWcN-)
