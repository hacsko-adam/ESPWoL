#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <WakeOnLan.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);

char ssid[] = "***";
char password[] = "***";
char hostname[] = "WOL_Gateway";

void wakeMyPC()
{
  const char *MACAddress = "B0:6E:BF:CF:E0:0C";

  WOL.sendMagicPacket(MACAddress); // Send Wake On Lan packet with the above MAC address. Default to port 9.
}

bool ConnectToNetwork(char *ssid, char *pass)
{
  int timeout = 0;
  bool succes = false;
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED && timeout < 10)
  {
    delay(1000);
    timeout++;
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    succes = true;
  }
  else
  {
    Serial.println("Connecting to SSID Failed ");
  }
  return succes;
}

void setup()
{
  delay(1000);
  Serial.begin(9600);
  WiFi.hostname(hostname);
  delay(1000);
  Serial.println("Starting the WOL Gateway ");
  while (!ConnectToNetwork(ssid, password))
  {
    delay(2000);
  }
  WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());
}

void loop()
{
  wakeMyPC();

  Serial.println("Sent");
  delay(5000);
}
