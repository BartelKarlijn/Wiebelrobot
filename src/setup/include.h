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
// 2 regels hieronder mogen waarschijnlijk weg
//#include <WebServer.h>      // Local DNS Server used for redirecting all requests to the configuration portal (  https://github.com/zhouhan0126/DNSServer---esp32  )
//#include <DNSServer.h>      // Local WebServer used to serve the configuration portal (  https://github.com/zhouhan0126/DNSServer---esp32  )



// **** Eigen wiebelrobot libraries ****
// //Configuratie
#include <configuration.h>

// define & variables
#include <main/globalvariables.h>

// algemene zaken
#include <setup\save_eprom.h>
#include <main/resetPID.h>

// MPU
#ifdef flag_calibrateMPU
  #include <mpu\calibrateMPU.h>
#else
  #include <mpu\setupMPU.h>
  #include <mpu\loopMPU.h>
#endif

// motors
#include <main\dcmotors.h>
#include <setup\setup_dcmotors.h>

// Wifi
#include <wifi/credentials.h>        // added to gitignore
#include <wifi/html_buttonSimple.h>  // routine om simpele pushbutton te maken
#include <wifi/html_buttonUpDown.h>  // routine om PID parameters up/down aan te passen
#include <wifi/html_sendPage.h>      // send the (config) html string
#include <wifi/html_processor.h>     // vervangt placeholder in sendPage
#include <wifi/buttonChange.h>       // acties die gebeuren als je op knop drukt
#include <wifi/setup_AsyncWebserver.h> 


//#include <main\gyro.h>           //dit moet vervangen worden
//#include <setup\setup_mpu.h>      //oud, mag weg
//#include <main\testmotor.h>      // om motors te testen (aan/uit)
//#include <main\testmotorPWM.h>   // eerste versie om motors via PWM aan te sturen
#include <main\testmotorPWM2.h>    // tweede versie met functies
//#include <main\testgyro.h>         // MPU6050 uittesten en printen

#include <setup/setupSerial.h>
#include <setup\setupIntled.h>
//#include <ESPAsyncWebServer.h>
//#include <AsyncElegantOTA.h>
//#include <wifi/wifidefinitions.h>    // kan wat opgekuist worden?
#include <wifi/OTA.h>
//#include <wifi/handle.h>                // voorlopig even afgezet
#include <wifi/setupwifiManager.h>
#include <main\printPIDparams.h>
//#include <setup\setup_task.h>             // voorlopig even afgezet
#include <wifi\setupOTA.h>
