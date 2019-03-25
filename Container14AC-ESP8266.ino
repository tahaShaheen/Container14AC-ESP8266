#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseHttpClient.h>
/*
    had to add this (<FirebaseHttpClient.h>) and replace the
    kFirebaseFingerprint[] data to "B8 4F 40 70 0C 63 90 E0 07 E8 7D BD B4 11 D0 4A EA 9C 90 F6"
    in the FireBaseHttpClient.h library.
    apparently the figerprint for firebasio had been updated by Google
    I found the updated fingerprint using https://www.grc.com/fingerprints.htm
    and feeding in it my https://example.firebaseio.com/
*/


#define FIREBASE_HOST "HOST"
#define FIREBASE_AUTH "AUTH"

#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

int IRledPin =  D3;    // IR LED connected to digital pin D3

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
}

void loop() {

  //first find out whether the user wants a setting update or not AND
  //if they do want a setting update, we find out which setting they want

  if ((Firebase.getBool("updateSetting") == true) && (Firebase.getBool("confirmationStatus") == false)) {
    SendCode(Firebase.getInt("whichSetting"));

    Firebase.setBool("updateSetting", false);
    Firebase.setBool("confirmationStatus", true);
  }
}
