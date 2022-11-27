#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiManager.h>
#include <WakeOnLan.h>
#include <iostream>
#include <algorithm>
#include "EepromManager.hpp"
#include "index.html.h"

WiFiUDP UDP;
WakeOnLan WOL(UDP);
WiFiManager wm;
bool wifiConnected;
ESP8266WebServer server(80);
EepromManager eepromManager = EepromManager();

void handleRoot()
{
  server.send(200, "text/html", indexHtml);
}

void getData()
{
  server.send(200, "text", eepromManager.readWord());
}

void removePC()
{
  if (server.arg("item"))
  {
    String item = server.arg("item");
    Serial.println("item to remove:");
    Serial.println(item);

    String storedData = eepromManager.readWord();
    Serial.println("EEPROM stored data:");
    Serial.println(storedData);

    String newData = storedData;
    newData.replace(item, "");
    newData.replace(";;", ";");
    if (newData[0] == ';')
    {
      newData[0] = ' ';
    }
    if (newData[newData.length() - 1] == ';')
    {
      newData[newData.length() - 1] = ' ';
    }
    newData.trim();
    Serial.println("EEPROM new data:");
    Serial.println(newData);
    eepromManager.writeWord(newData);
  }
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void AddPC()
{
  if (server.arg("name") && server.arg("mac") && server.arg("port"))
  {
    String name = server.arg("name");
    name.replace(",", "");
    name.replace(";", "");

    String mac = server.arg("mac");
    mac.replace(",", "");
    mac.replace(";", "");

    String port = server.arg("port");
    port.replace(",", "");
    port.replace(";", "");

    String data = name + "," + mac + "," + port;
    Serial.println("Received data:");
    Serial.println(data);

    String storedData = eepromManager.readWord();
    Serial.println("EEPROM stored data:");
    Serial.println(storedData);

    String NewData = storedData + ";" + data;
    if (NewData[0] == ';')
    {
      NewData[0] = ' ';
    }
    NewData.trim();
    Serial.println("New stored data:");
    Serial.println(NewData);

    eepromManager.writeWord(NewData);
  }
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void wakeMyPC()
{
  const char *MACAddress = "B0:6E:BF:CF:E0:0C";
  WOL.sendMagicPacket(MACAddress);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting the server");

  WiFi.mode(WIFI_STA);
  WiFi.hostname("WOL_Gateway");

  wifiConnected = wm.autoConnect("WOL_Gateway");
  if (!wifiConnected)
  {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else
  {
    // if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
    Serial.println(WiFi.localIP());
    WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());
    server.on("/", handleRoot);
    server.on("/getData", getData);
    server.on("/AddNew", AddPC);
    server.on("/remove", removePC);
    server.begin();
  }
}

void loop()
{
  if (wifiConnected)
  {
    // wakeMyPC();
    server.handleClient();
  }
}
