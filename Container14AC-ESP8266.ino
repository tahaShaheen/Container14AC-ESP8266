//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseHttpClient.h>
/*had to add this and change the
   kFirebaseFingerprint[] to "B8 4F 40 70 0C 63 90 E0 07 E8 7D BD B4 11 D0 4A EA 9C 90 F6"
   apparantly the figerprint for firebasio had been updated by Google
   I found the updated fingerprint using https://www.grc.com/fingerprints.htm
   and feeding in it my https://example.firebaseio.com/
*/


// Set these to run example.
#define FIREBASE_HOST "HOST"
#define FIREBASE_AUTH "AUTH"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

void setup() {
  Serial.begin(9600);

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

int n = 0;

void loop() {
  // set value
  Firebase.setFloat("number", 42.0);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);

  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);

  // get value
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);

  Firebase.setString("message", "hi universe");
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);

  // get String value
  Serial.print("message: ");
  Serial.println(Firebase.getString("message"));
  delay(1000);

  // remove value
  Firebase.remove("message");
  delay(1000);

  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /truth failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);

  
  Firebase.setBool("truth", true);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /truth failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);
// set bool value
  Serial.print("truth: ");
  Serial.println(Firebase.getBool("truth"));
  delay(1000);

  // remove value
  Firebase.remove("truth");
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
    Serial.print("pushing /logs failed:");
    Serial.println(Firebase.error());
    return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);
}
