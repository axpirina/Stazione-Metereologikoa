# Weather Station Based on ESP8266  
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Oteitza.png" width="280" height="80">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="100" height="100">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Vincenza.png" width="300" height="100">
</p>
We have developed a weather station based on the **ESP8266** microcontroller, providing an efficient and cost-effective solution for environmental monitoring. This weather station is designed to measure **Temperature (ºC)**, **Humidity (%)** and **Dew Point (ºC)** with the data being displayed on the **Thingsboard DEMO** platform for easy visualization and analysis.  

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Thingsboard.png" width="800" height="400">
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

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/DEMO.png" width="600" height="300">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="150" height="300">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/App.jpg" width="150" height="300">
</p>



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
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/kaxa.jpeg" width="460" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/DHT11.png" width="200" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/White.png" width="10" height="260" style="margin-right: 10px;">
    <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Dupont.png" width="200" height="260" style="margin-left: 10px;">
  </div>
</div>

> **Note:** A 3D printer is recommended to create the enclosure.
This hardware setup provides an efficient and reliable foundation for the project.
> You can find a possible hardware enclosure for this project at the following link:
[Link to the Hardware Enclosure Project](https://www.thingiverse.com/thing:2510742) - 
[Another link to the Hardware Enclosure Project](https://www.thingiverse.com/thing:4864299)

## NodeMCU V2 Pinout
Keep in mind that the GPIO numbers of the NodeMCU must be specified in the Arduino code.
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/NodeMCU_Pinout.png" width="800" height="600">
</p>

## Electrical Scheme 
Below, you will find the electrical circuit schematic. Make sure to connect everything correctly and define the pins you connected in the schematic within the program. The electrical schematic has been created using [Fritzing](https://www.fritzing.com).

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Scheme.png" width="600" height="450">
</p>

> **Note:** Please ensure that all connections are made correctly and that the voltage polarities are respected.

## Network Scheme 
Below, you will find the network circuit schematic. Make sure to connect to your wifi correctly. The network schematic has been created using [Draw.io](https://www.draw.io).

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Network.png" width="600" height="600">
</p>

> **Note:** Please ensure that you configure your place Wifi accordinly to your place.

## Arduino IDE
To program the ESP8266 microcontroller, you will need the Arduino IDE and several libraries. Essentially, the **ESP8266-DHT.ino** file must be uploaded to the **NodeMCU** using **Arduino IDE**. Follow the steps:

1. [Arduino IDE Download](https://www.arduino.cc/en/software)

<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/IDE.jpg" width="600" height="450">
</p>
   
3. [Installing NodeMCU on Arduino IDE](https://projecthub.arduino.cc/PatelDarshil/getting-started-with-nodemcu-esp8266-on-arduino-ide-b193c3)
<p align="center">
  <img src="https://axpirina.github.io/Stazione-Metereologikoa/Irudiak/Board.png" width="600" height="300">
</p>

   
5. Install the following libraries in the Arduino IDE. To do this, open the Library Manager by navigating to **Sketch** > **Include Library** > **Manage Libraries**.
   - ESP8266WiFi.h
   - PubSubClient.h
   - DHT.h

    Additionally, as of 2025, the following compiled libraries have been found sufficient:

     - SimpleWifiClient by Toemblom
     - IoTtweet by Isaranu
     - DHT Sensor Library by Adafruit
     - PubSubClient by Nick O`Leary


## Arduino Code
Upload the Arduino code provide below to the NodeMCU. If everything has gone well, you will find the section for parameterizing the code further ahead.
 [Arduino Code for the Weather Station](/StationArduinoCode.ino)

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
const char* ssid = "yourWiFiSSID";    // Give your WIFI name -- OLP
const char* password = "yourWiFiPassword";   // Give your WIFI password -- oteitzaLP
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

## Configuration
Configure the following parameters in the Arduino code according to your project's infrastructure.

 > WIFI Setup: Connects the ESP8266 to a WiFi network using your SSID and password. 
```cpp
const char* ssid     = "yourWiFiSSID";   // Give your WIFI name           
const char* password = "yourWiFiPassword"; // Give your WIFI password  
```
  > MQTT Connection: The device connects to the Thingsboard server using MQTT with authentication (device token as mqtt_user).
```cpp
const char* mqtt_server = "demo.thingsboard.io";   // Leave as it is
const char* mqtt_user = "yourDeviceToken";     // Create a new Device in https://demo.thingsboard.io and get its access token.
const char* mqtt_password = "";     // Leave as it is
```
  > DHT11 and NODEMCU Connection:  Look at the electrical scheme. The DHT11 is connected to D5 (GPIO14)
```cpp
#define DHTPIN 14 // DHT11 data pin (GPI14 = D5 on NodeMCU)
```
 > MQTT Topic: Thingsboard API request the topic to be the following).
```cpp
const char* topic = "v1/devices/me/telemetry";   // Leave as it is
```

> CONFIGURE DATA FREQUENCY: Decide how often data will be sent.
```cpp
delay(5000); // Interval of 5 seconds between publications
```

## Links                            
 
Diy IOT Tknika [Diy IOT Tknika](https://www.youtube.com/watch?v=z61bxGR6Poo&list=PLOYSs5_FlYNtzRIuRgQhgzTNdCzludb6r&index=24)  
NODE RED and THINGSBOARD Oteitza Lizeoa [NODE RED and THINGSBOARD Oteitza Lizeoa](https://www.youtube.com/playlist?list=PLLzgegoyyqcNHDIyPvh3pWa9Zu6rSWcN-)

## License

This project is licensed under a Creative Commons Attribution 4.0 International License.
You are free to:

    Share — copy and redistribute the material in any medium or format.
    Adapt — remix, transform, and build upon the material for any purpose, even commercially.

As long as you provide proper attribution to the original author.
<p align="center"> <a href="https://creativecommons.org/licenses/by/4.0/"> <img src="https://i.creativecommons.org/l/by/4.0/88x31.png" alt="Creative Commons License"> </a> </p>
