//4ch redio controll using esp8266 and Blynk.
//by Abid Hossain.

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App and from your email.

char auth[] = "...............";

//WiFi credentials.

char ssid[] = "........"; 

char pass[] = "...........";

//creating servo object
Servo throttle;
Servo yaw;
Servo rudder;
Servo elevator;

BLYNK_WRITE(V1) {

throttle.write(param.asInt());

}


BLYNK_WRITE(V2) {

yaw.write(param.asInt());

}

BLYNK_WRITE(V3) {

rudder.write(param.asInt());

}

BLYNK_WRITE(V4) {

elevator.write(param.asInt());

}
void setup() {

Serial.begin(9600);
Blynk.begin(auth, ssid, pass);

throttle.attach(15); // 15 means D8 pin of ESP8266
yaw.attach(13); // 13 means D7 pin of ESP8266
rudder.attach(12); // 12 means D6 pin of ESP8266
elevator.attach(4); // 4 means D2 pin of ESP8266
}

void loop()

{

Blynk.run();

}
