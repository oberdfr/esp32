#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 22
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

// vuribali
float hum;
float temp;

const char * ssid="progettotemperatura"; //puntatore zona di memoria
// #define ssid "RETE_A24"
const char * wifipw="progettotemperatura";


void setup(){
  Serial.begin(115200);
  dht.begin();
  Serial.println("");
  Serial.println("WiFi connected.");
  //segnale_rssi ();
  delay (5000);
  //WiFi.disconnect();
  //Serial.println("disconnesso");
  
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.println(hum);
  Serial.println(temp);  
  delay(1000);
    
}

void  startWifi(){
  WiFi.begin(ssid, wifipw);
  Serial.println("Connecting Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}
/*
 * void  segnale_rssi(){
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Wifi RSSI=");
  Serial.println(WiFi.RSSI());
}*/

/*void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print("");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
  }
} */
