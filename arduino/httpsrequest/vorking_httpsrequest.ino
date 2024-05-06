#include <WiFi.h>
#include <HTTPClient.h>
const char * ssid="progettotemperatura"; //puntatore zona di memoria
// #define ssid "RETE_A24"
const char * wifipw="progettotemperatura";

void setup(){
  Serial.begin(115200);
  startWifi();
  Serial.println("");
  Serial.println("WiFi connected.");
  segnale_rssi ();
  delay (5000);
  //WiFi.disconnect();
  //Serial.println("disconnesso");
}

void loop() {
  String oj = httpGETRequest("http://10.0.3.58:5000/add?aula=MM1&valore=32");
  delay(5000);
    
}

void  startWifi(){
  WiFi.begin(ssid, wifipw);
  Serial.println("Connecting Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}
void  segnale_rssi(){
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Wifi RSSI=");
  Serial.println(WiFi.RSSI());
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // If you need Node-RED/server authentication, insert user and password below
  //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
