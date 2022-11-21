#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiManager.h>
#include <WakeOnLan.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);
WiFiManager wm;
bool res;

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

  res = wm.autoConnect("WOL_Gateway");
  if (!res)
  {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else
  {
    // if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
    WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());
  }
}

void loop()
{
  if (res)
  {
    wakeMyPC();
  }
}
