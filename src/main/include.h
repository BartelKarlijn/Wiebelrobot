// **** Community libraries ****
// Arduino library includes
#include <Arduino.h>
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven

// MPU6050
#include <Wire.h>           // voor I2C communicatie met MPU6050
//#include <I2Cdev.h>    //even oude mpu6050 uitgezet
//#include <MPU6050_6Axis_MotionApps20.h> //even oude mpu6050 uitgezet
 #include <MPU9250_WE.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
//#include <ESPAsync_WiFiManager.h>   // Zorg dat systeem zelf paswoorden beheert
#include <AsyncElegantOTA.h>
#include <WebSerial.h>

//Stepper motors
#include <AccelStepper.h>

// **** Eigen wiebelrobot libraries ****
// //Configuratie
#include <configuration.h>

// define & variables
#include <main/globalvariables.h>

// algemene zaken
#include <main/print.h>
#include <main/save_eprom.h>
#include <main/resetPID.h>
#include <main/setupSerial.h>
#include <main/setupIntled.h>
#include <main/printPIDparams.h>
#include <main/constr.h>

//Meerdere cpu's gebruiken
#include <main/setup_task1_stepper.h>

// MPU
#ifdef flag_I2Cscan
  #include <mpu/i2cscan.h>
#endif
#ifdef flag_calibrateMPU
  //#include <mpu\calibrateMPU.h>
#else
  #include <mpu\setupMPU.h>
  #include <mpu\loopMPU.h>
#endif
#include <mpu/mpu9250we_calibrate.h>
#include <mpu/mpu9250we_loop.h>

// motors
#include <motors\steppermotor.h>
#include <motors\setup_steppers.h>

// Wifi
//#include <wifi/credentials.h>        // added to gitignore
#include <wifi\html_buttonSimple.h>  // routine om simpele pushbutton te maken
#include <wifi\html_buttonUpDown.h>  // routine om PID parameters up/down aan te passen
#include <wifi\html_buttonLink.h>    // routine om knoppen met link te maken
#include <wifi\html_joystick.h>      // Poging om joystick te maken
#include <wifi\html_sendPage.h>      // send the (config) html string
#include <wifi\html_processor.h>     // vervangt placeholder in sendPage
#include <wifi\buttonChange.h>       // acties die gebeuren als je op knop drukt
#include <wifi\setup_AsyncWebserver.h> 
#include <wifi\setup_ConnectKnownWifi.h>
#include <wifi\setup_CreateAccessPoint.h>
