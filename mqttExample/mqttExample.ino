/*
*
* This Arduino UNO R4 code is made available for public use without any restriction
*
*/

#include <WiFiS3.h>
#include <MQTTClient.h>

#define POTEN A0
#define LED 9

const char WIFI_SSID[] = "UwU";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "absc1234";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "192.168.0.11";  // CHANGE TO MQTT BROKER'S IP ADDRESS
const int MQTT_PORT = 1883; // Port Number
const char MQTT_CLIENT_ID[] = "PhycomServer";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";              // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";              // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC1[] = "67070114/temp";       // CHANGE IT AS YOU DESIRE
const char PUBLISH_TOPIC2[] = "67070114/light";       // CHANGE IT AS YOU DESIRE
const char PUBLISH_TOPIC3[] = "67070114/food";       // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "67070114/venus";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 100;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

#include "sensor.h"

Temperature	tempSen(A0);
Potentiometer poten(A1, 255);
Ultrasonic	ulSen(2, 3);
RGBLed	led(8, 9, 10);

void setup() {
	Serial.begin(9600);

	int status = WL_IDLE_STATUS;
	while (status != WL_CONNECTED) {
		Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
		Serial.println(WIFI_SSID);
		// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
		status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

		// wait 10 seconds for connection:
		delay(10000);
	}
	// print your board's IP address:
	Serial.print("IP Address: ");
	Serial.println(WiFi.localIP());

	connectToMQTT();
}

void loop() {
	mqtt.loop();

	if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
	  sendToMQTT();
	  lastPublishTime = millis();
	}
}

void connectToMQTT() {
	// Connect to the MQTT broker
	mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

	// Create a handler for incoming messages
	mqtt.onMessage(messageReceived);

	Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

	while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
		Serial.print(".");
		delay(100);
	}
	Serial.println();

	if (!mqtt.connected()) {
		Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
		return;
	}

	// Subscribe to a topic, the incoming messages are processed by messageHandler() function
	if (mqtt.subscribe(SUBSCRIBE_TOPIC))
		Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
	else
		Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

	Serial.println(SUBSCRIBE_TOPIC);
	Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

// TODO: Edit code here
void sendToMQTT() {
	char messageBuffer[10];
	int	temp = tempSen.getTemperature();
	int	resis = poten.getRawValue();
	int	dis = ulSen.getDistance();

	//int val = analogRead(A0);
	String val_str = String(temp);
	val_str.toCharArray(messageBuffer, 10);
	mqtt.publish(PUBLISH_TOPIC1, messageBuffer);
	val_str = String(resis);
	val_str.toCharArray(messageBuffer, 10);
	mqtt.publish(PUBLISH_TOPIC2, messageBuffer);
	if (dis > 20)
		mqtt.publish(PUBLISH_TOPIC3, "off");
	
	Serial.print("TEMP: ");
	Serial.print(temp);
	Serial.print(" Resistance: ");
	Serial.print(resis);
	Serial.print(" Distance: ");
	Serial.println(dis);

	// Serial.println("Arduino UNO R4 - sent to MQTT:");
	// Serial.print("- topic: ");
	// Serial.println(PUBLISH_TOPIC);
	// Serial.print("- payload:");
	// Serial.println(messageBuffer);

	// Serial.print(ADC_Data);
}

// TODO: Edit code here
void messageReceived(String &topic, String &payload) {
	Serial.println("Arduino UNO R4 - received from MQTT:");
	Serial.println("- topic: " + topic);
	Serial.println("- payload:");
	Serial.println(payload);

	int val = std::atoi(payload.c_str());
	if (val >= 36 && val <= 50)
		led.setValue(0, 1, 1);
	else if (val >= 26)
		led.setValue(1, 1, 0);
	else if (val >= 10)
		led.setValue(1, 0, 1);
}