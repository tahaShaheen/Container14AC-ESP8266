/*
  Code used:
   Rui Santos
   https://randomnerdtutorials.com/esp8266-web-server-with-arduino-ide/

   examples from library by markszabo
   https://github.com/markszabo/IRremoteESP8266.git

    ESP8266 server example with GPIO 2 light turn on and off
    and

    Basic Example from NTP library
    https://github.com/arduino-libraries/NTPClient
*/
// Load Wi-Fi library
#include <ESP8266WiFi.h>
//NTP library
#include <NTPClient.h>
//Don't know which library this is
#include <WiFiUdp.h>


// Replace with your network credentials
const char* ssid     = "SSID";
const char* password = "PASSWORD";

int IRledPin =  D0;    // IR LED connected to digital pin D0

//actual time
String timeInput;;

/*
  //testing time
  String chuttiTime1 = "14:05:00";
  String chuttiTime2 = "14:06:00";
*/

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;
char val = 'F'; //Initialization to 'F' is important

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.google.com", 3600, 60000);

void setup() {
  Serial.begin(115200);
  delay(10);
  // prepare GPIO
  pinMode(IRledPin, OUTPUT);  //did not initialize because not necessary

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  //  IPAddress ip(10, 200, 31, 221/*XX*/);
  //  IPAddress gateway(10, 200, 31, 192);
  //  IPAddress subnet(255, 255, 255, 0);
  //  WiFi.config(ip, gateway, subnet);

  /*I'm not entirely certain how the above four lines do it
    but they freeze the ip to 125.200.31.221 (no it doesn't: the only thing I have control over is the last byte marked XX)(and that shit just leads to no connection to the NTP server)
    This is one of the last few CLass A IP addresses (the SARSABZ router kept assigning to us 10.sth.sth.sth)
    Abdul Samad said that the router assigns these serially
    This means that the router won't get to this number very quickly
    And we can always request it and get it*/

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  timeClient.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  timeClient.update();
  String currentTime = timeClient.getFormattedTime();
  delayMicroseconds(5000);

  if (currentTime == timeInput) {
    val = 'T';

    Serial.println("Sending IR signal");
    SendCode(val);

    Serial.println("TIME TO COOL SHIT DOWN!!");
  }

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /TURBO") >= 0) {
              Serial.println("16C TURBO");
              val = 'T';
            }
            else if (header.indexOf("GET /OFF") >= 0) {
              Serial.println("AC OFF");
              val = 'F';
            }
            else if (header.indexOf("GET /22") >= 0) {
              Serial.println("22C NORMAL");
              val = 'N';
            }

            /*else {
              Serial.println("invalid request");
              client.stop();
              return;
              }*/

            // Set IR signal according to the request
            Serial.println("Sending IR signal");
            SendCode(val);

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #f44336; border: none; color: white; padding: 16px 40px; font-size: 16px; border-radius: 8px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: white; border: 1px solid #f44336; color: #f44336; padding: 16px 40px; font-size: 16px; border-radius: 8px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>Container number 14 AC control</h1>");

            // Display current state for TURBO and turn off if button clicked again
            client.println("<p>TURBO @ 16C</p>");
            // If the output5State is off, it displays the ON button
            if (val == 'T') {
              client.println("<p><a href=\"/OFF\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/TURBO\"><button class=\"button button2\">OFF</button></a></p>");
            }


            // Display current state for 22 and turn off if button clicked again
            client.println("<p>22C NORMAL</p>");
            // If the output4State is off, it displays the ON button
            if (val == 'N') {
              client.println("<p><a href=\"/OFF\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22\"><button class=\"button button2\">OFF</button></a></p>");
            }


            client.println("<form action=\"/action_page.php\">First name:<input type=\"text\" name=\"fname\"><br>Last name: <input type=\"text\" name=\"lname\"><br><input type=\"submit\" value=\"Submit\"></form>");

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
