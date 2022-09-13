#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "RTClib.h"

SoftwareSerial mySoftwareSerial(3, 2); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
RTC_DS3231 rtc;

void printDetail(uint8_t type, int value);

unsigned long last = 0;
int h, m;
boolean reproduciendo = false;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  //myDFPlayer.play(1);  //Play the first mp3
}

void loop() {
  if (millis() - last >= 1000) {
    last = millis();
    DateTime now = rtc.now();
    h = now.hour();
    m = now.minute();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print("    ");
    Serial.print(h);
    Serial.print(':');
    Serial.print(m);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    //--------------------------------------------------------
    if (h == 5 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 5 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //--------------------------------------------------------
    //--------------------------------------------------------
    if (h == 5 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 5 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //--------------------------------------------------------
    //--------------------------------------------------------
    if (h == 6 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 6 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //--------------------------------------------------------
    //--------------------------------------------------------
    if (h == 6 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 6 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //--------------------------------------------------------
    //--------------------------------------------------------
    if (h == 7 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 7 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //--------------------------------------------------------
    //--------------------------------------------------------
    if (h == 7 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 7 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 8 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 8 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 8 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 8 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 9 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 9 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 9 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 9 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 10 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 10 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 10 && m == 30 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 10 && m == 31 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 11 && m == 00 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 11 && m == 01 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
    //--------------------------------------------------------
    if (h == 13 && m == 05 && reproduciendo == false) {
      reproduciendo = true;
      myDFPlayer.play(1);
    }
    if (h == 13 && m == 06 && reproduciendo == true) {
      reproduciendo = false;
    }
    //---------------------------------------------------------
  }
}

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }

}
