/**********************************************************************************
 *  TITLE: Alexa control 8 channel Relay Module using NodeMCU or ESP32
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/tIFEtHVLexw
 *  Related Blog : https://easyelectronicsproject.com/esp32-projects/
 *  by Subhajit (Tech StudyCell)
 *  Bearbeitet by Bonbonkocher
 *  
 *  Download the libraries:
 *  https://github.com/Aircoookie/Espalexa
 *  Version: 2.7.0
 *  
 *  Datei -> Voreinstellung
 *  Preferences --> Aditional boards Manager URLs :
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board:
 *  For ESP8266 NodeMCU: https://github.com/esp8266/Arduino
 *  Version: 2.7.4
 *  
 *  For ESP32                  : https://github.com/espressif/arduino-esp32
 *  Version: ?
 *
 *  Verbindungprobleme
 *  Blaue LED Blinkend 2,5sec  = Verbindungprobleme
 *  Blaue LED dauerhaft aus    = Verbunden mit dem Router
 *  Blaue LED Blinkend 0,25sec = Verbindungsaufbau
 *
 **********************************************************************************/


#include <ESP8266WiFi.h>

#define ESPALEXA_MAXDEVICES 8
#include <Espalexa.h>

#define Relay_Pin_D0 16 //D0
#define Relay_Pin_D1 05 //D1
#define Relay_Pin_D2 04 //D2
#define Relay_Pin_D3 00 //D3
#define WIFIV_Pin_D4 02 //D4 Blaue Onboard LED
#define Relay_Pin_D5 14 //D5
#define Relay_Pin_D6 12 //D6
#define Relay_Pin_D7 13 //D7
#define Relay_Pin_D8 15 //D8

//###########################################################
//Bearbeitung
//
//Findbare Namen für Alexa
#define NAME_00 "Gerät1"
#define NAME_01 "Gerät2"
#define NAME_02 "Gerät3"
#define NAME_03 "Gerät4"
#define NAME_05 "Gerät5"
#define NAME_06 "Gerät6"
#define NAME_07 "Gerät7"
#define NAME_08 "Gerät8"
//
//###########################################################

#define AN "An"
#define AUS "Aus"

boolean connectWifi();

void TEST0(uint8_t brightness);
void TEST1(uint8_t brightness);
void TEST2(uint8_t brightness);
void TEST3(uint8_t brightness);
void TEST5(uint8_t brightness);
void TEST6(uint8_t brightness);
void TEST7(uint8_t brightness);
void TEST8(uint8_t brightness);

#include "WifiConnect.h"

String Device_00_Name = NAME_00;
String Device_01_Name = NAME_01;
String Device_02_Name = NAME_02;
String Device_03_Name = NAME_03;
String Device_05_Name = NAME_05;
String Device_06_Name = NAME_06;
String Device_07_Name = NAME_07;
String Device_08_Name = NAME_08;

boolean wifiConnected = false;

Espalexa espalexa;

void setup()
{
  Serial.begin(115200);

  pinMode(Relay_Pin_D0, OUTPUT);
  pinMode(Relay_Pin_D1, OUTPUT);
  pinMode(Relay_Pin_D2, OUTPUT);
  pinMode(Relay_Pin_D3, OUTPUT);
  pinMode(WIFIV_Pin_D4, OUTPUT);
  pinMode(Relay_Pin_D5, OUTPUT);
  pinMode(Relay_Pin_D6, OUTPUT);
  pinMode(Relay_Pin_D7, OUTPUT);
  pinMode(Relay_Pin_D8, OUTPUT);

  wifiConnected = connectWifi();

  if (wifiConnected)
  {
    espalexa.addDevice(Device_00_Name, TEST0);
    espalexa.addDevice(Device_01_Name, TEST1);
    espalexa.addDevice(Device_02_Name, TEST2);
    espalexa.addDevice(Device_03_Name, TEST3);
    espalexa.addDevice(Device_05_Name, TEST5);
    espalexa.addDevice(Device_06_Name, TEST6);
    espalexa.addDevice(Device_07_Name, TEST7);
    espalexa.addDevice(Device_08_Name, TEST8);

    espalexa.begin();
  }
  else
  {
    while (1)
    {
      Serial.println("Kann nicht Verbinden mit WiFi. Bitte Code kontrollieren und Neustarten.");
      digitalWrite(WIFIV_Pin_D4, HIGH);
      delay(2500);
      digitalWrite(WIFIV_Pin_D4, LOW);
      delay(2500);
    }
  }
}

void loop()
{
  espalexa.loop();
  delay(1);
}

void TEST0(uint8_t brightness)
{
  if (brightness == 255)
  {
    digitalWrite(Relay_Pin_D0, LOW);
    Serial.print(NAME_00);
    Serial.print(":");
    Serial.print(AN);
  }
  else
  {
    digitalWrite(Relay_Pin_D0, HIGH);
    Serial.print(NAME_00);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST1(uint8_t brightness)
{
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D1, LOW);
    Serial.print(NAME_01);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D1, HIGH);
    Serial.print(NAME_01);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST2(uint8_t brightness)
{
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D2, LOW);
    Serial.print(NAME_02);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D2, HIGH);
    Serial.print(NAME_02);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST3(uint8_t brightness)
{
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D3, LOW);
    Serial.print(NAME_03);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D3, HIGH);
    Serial.print(NAME_03);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST5(uint8_t brightness)
{ 
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D5, LOW);
    Serial.print(NAME_05);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D5, HIGH);
    Serial.print(NAME_05);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST6(uint8_t brightness)
{ 
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D6, LOW);
    Serial.print(NAME_06);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D6, HIGH);
    Serial.print(NAME_06);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST7(uint8_t brightness)
{
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D7, LOW);
    Serial.print(NAME_07);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D7, HIGH);
    Serial.print(NAME_07);
    Serial.print(":");
    Serial.print(AUS);
  }
}

void TEST8(uint8_t brightness)
{
  if (brightness == 255)
    {
    digitalWrite(Relay_Pin_D8, LOW);
    Serial.print(NAME_08);
    Serial.print(":");
    Serial.print(AN);
    }
  else
  {
    digitalWrite(Relay_Pin_D8, HIGH);
    Serial.print(NAME_08);
    Serial.print(":");
    Serial.print(AUS);
  }
}

boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.println("");
  Serial.println("Verbinde mit WiFi");

  Serial.print("Verbinde...");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WIFIV_Pin_D4, HIGH);
    delay(250);
    digitalWrite(WIFIV_Pin_D4, LOW);
    delay(250);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Verbinde zur ");
    Serial.println(WIFI_SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(WIFIV_Pin_D4, LOW);
  }
  else {
    Serial.println("Verbindung fehlgeschlagen.");
    digitalWrite(WIFIV_Pin_D4, LOW);
  }
  return state;
}
