#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseHttpClient.h>
//NTP libraries
#include <NTPClient.h>
#include <WiFiUdp.h>
/*
   Libraries:
   
   https://github.com/FirebaseExtended/firebase-arduino
   commit cd5681f59cabdb31c2c50c55a5abc53af78a3280

   https://github.com/bblanchon/ArduinoJson.git
   commit ad4b13c8f044e67f1610fba96e8dc108ebc90cd5
     
*/

#define FIREBASE_HOST "HOST"
#define FIREBASE_AUTH "AUTH"

#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

int IRledPin =  D0;    // IR LED connected to digital pin D0
String chuttiTime1, currentTime;
bool updateSetting, updateSettingOld;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.google.com", 3600, 60000);

void setup() {
  Serial.begin(115200);

  pinMode(IRledPin, OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Firebase.setBool("proofOfConnection",!(Firebase.getBool("proofOfConnection")));
  
  updateSettingOld = Firebase.getBool("updateSetting");
  Firebase.setInt("whichSetting", 4);

}

void loop() {

  //timeCheck();

  //first find out whether the user wants a setting update or not AND
  //if they do want a setting update, we find out which setting they want

  updateSetting = Firebase.getBool("updateSetting");

  if (updateSettingOld ^ updateSetting) { //XOR here because != was resulting in false truths for some reason
    
    updateSettingOld = updateSetting;

    SendCode(Firebase.getInt("whichSetting"));
    Firebase.setBool("confirmationStatus", !(Firebase.getBool("confirmationStatus")));
    
    Firebase.setInt("whichSetting", 4); //This is for safetly. For some reason the (updateSettingOld ^ updateSetting) seems to yeild true at times it shouldn't.
  }

  
  
}
