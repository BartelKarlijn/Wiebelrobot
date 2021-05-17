// **** Community libraries ****
// Arduino library includes
#include <Arduino.h>
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven

// MPU6050
#include <Wire.h>           // voor I2C communicatie met MPU6050
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <ESPAsync_WiFiManager.h>   // Zorg dat systeem zelf paswoorden beheert
#include <AsyncElegantOTA.h>


// **** Eigen wiebelrobot libraries ****
// //Configuratie
#include <configuration.h>

// define & variables
#include <main/globalvariables.h>

// algemene zaken
#include <main/save_eprom.h>
#include <main/resetPID.h>
#include <setup/setupSerial.h>
#include <setup\setupIntled.h>
#include <main\printPIDparams.h>
#include <main\constr.h>

// MPU
#ifdef flag_calibrateMPU
  #include <mpu\calibrateMPU.h>
#else
  #include <mpu\setupMPU.h>
  #include <mpu\loopMPU.h>
#endif

// motors
#include <motors\dcmotors.h>
#include <motors\setup_dcmotors.h>

// Wifi
#include <wifi/credentials.h>        // added to gitignore
#include <wifi/html_buttonSimple.h>  // routine om simpele pushbutton te maken
#include <wifi/html_buttonUpDown.h>  // routine om PID parameters up/down aan te passen
#include <wifi/html_buttonLink.h>    // routine om knoppen met link te maken
#include <wifi/html_joystick.h>      // Poging om joystick te maken
#include <wifi/html_sendPage.h>      // send the (config) html string
#include <wifi/html_processor.h>     // vervangt placeholder in sendPage
#include <wifi/buttonChange.h>       // acties die gebeuren als je op knop drukt
#include <wifi/setup_AsyncWebserver.h> 
// Wifi manager en OTA
#include <wifi/setupwifiManager.h>
//#include <wifi/OTA.h>
//#include <wifi\setupOTA.h>

//#include <main\gyro.h>           //dit moet vervangen worden
