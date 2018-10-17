#include <call.h>
#include <gps.h>
#include <GSM.h>
#include <HWSerial.h>
#include <inetGSM.h>
#include <LOG.h>
#include <SIM900.h>
#include <sms.h>
#include <Streaming.h>
#include <WideTextFinder.h>

#include "SIM900.h"
#include <SoftwareSerial.h>
//#include "inetGSM.h"
//#include "sms.h"
//#include "call.h"
#include "gps.h"

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
14CORE TEST CODE FOR 
E18-D80NK Infrared Distance Ranging Sensor 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
void setup()  {
 
 Serial.begin(9600); //Start serial communication boud rate at 9600
 pinMode(5,INPUT); //Pin 5 as signal input
 
}
int counter = 0;
boolean resetAndReadyToCount = true;
void loop()  {
   //delay(100);
   //Serial.println(resetAndReadyToCount);
   if(digitalRead(5)==LOW && resetAndReadyToCount)  { 
    // If no signal print collision detected
     //Serial.println("Collision Detected.");
     counter++;
     resetAndReadyToCount = false;
     Serial.println(counter);
   }
   if (digitalRead(5)==HIGH && !resetAndReadyToCount) {
    resetAndReadyToCount = true;
     // If signal detected print collision detected
     //Serial.println("No Collision Detected.");
   }
}


/*
//To change pins for Software Serial, use the two lines in GSM.cpp.

//GSM Shield for Arduino
//www.open-electronics.org
//this code is based on the example of Arduino Labs.

//Simple sketch to start a connection as client.

//InetGSM inet;
//CallGSM call;
//SMSGSM sms;
GPSGSM gps;

char lon[15];
char lat[15];
char alt[15];
char time[20];
char vel[15];
char msg1[5];
char msg2[5];

char stat;
char inSerial[20];
int i=0;
boolean started=false;

void setup()
{
    pinMode(7, OUTPUT);
  
     //Serial connection.
     Serial.begin(9600);
     Serial.println("GSM Shield testing.");
     //Start configuration of shield with baudrate.
     //For http uses is raccomanded to use 4800 or slower.
     if (gsm.begin(2400)) {
          Serial.println("\nstatus=READY");
          gsm.forceON();    //To ensure that SIM908 is not only in charge mode
          started=true;
     } else Serial.println("\nstatus=IDLE");

     if(started) {
          //GPS attach
          if (gps.attachGPS())
               Serial.println("status=GPSREADY");
          else Serial.println("status=ERROR");

          delay(20000); //Time for fixing
          stat=gps.getStat();
          if(stat==1)
               Serial.println("NOT FIXED");
          else if(stat==0)
               Serial.println("GPS OFF");
          else if(stat==2)
               Serial.println("2D FIXED");
          else if(stat==3)
               Serial.println("3D FIXED");
          delay(5000);
     }
};

void loop()
{
     //Read for new byte on serial hardware,
     //and write them on NewSoftSerial.
     serialhwread();
     //Read for new byte on NewSoftSerial.
     serialswread();

    //Get data from GPS
    gps.getPar(lon,lat,alt,time,vel);
    Serial.print("Longtitude: ");
    Serial.println(lon);
    Serial.print("Latitude: ");
    Serial.println(lat);
    Serial.print("Altitude: ");
    Serial.println(alt);
    Serial.print("Time: ");
    Serial.println(time);
    Serial.print("Velosity: ");
    Serial.println(vel);
    Serial.println("");
    if (atof(vel) > 0.3) {
      digitalWrite(7, LOW);
    } else {
      digitalWrite(7, HIGH);
    }
};

void serialhwread()
{
     i=0;
     if (Serial.available() > 0) {
          while (Serial.available() > 0) {
               inSerial[i]=(Serial.read());
               delay(10);
               i++;
          }

          inSerial[i]='\0';
          if(!strcmp(inSerial,"/END")) {
               Serial.println("_");
               inSerial[0]=0x1a;
               inSerial[1]='\0';
               gsm.SimpleWriteln(inSerial);
          }
          //Send a saved AT command using serial port.
          if(!strcmp(inSerial,"TEST")) {
               stat=gps.getStat();
               if(stat==1)
                    Serial.println("NOT FIXED");
               else if(stat==0)
                    Serial.println("GPS OFF");
               else if(stat==2)
                    Serial.println("2D FIXED");
               else if(stat==3)
                    Serial.println("3D FIXED");
          }
          //Read last message saved.
          if(!strcmp(inSerial,"MSG")) {
               Serial.println(msg1);
          } else {
               Serial.println(inSerial);
               gsm.SimpleWriteln(inSerial);
          }
          inSerial[0]='\0';
     }
}

void serialswread()
{
     gsm.SimpleRead();
}
*/
