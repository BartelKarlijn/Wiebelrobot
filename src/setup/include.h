// Arduino library includes
#include <Arduino.h>
TaskHandle_t Task1;    //Taskhandle om wifi op 2e cpu te draaien
#include <Wire.h>
#include <Preferences.h>
Preferences pref_eeprom;
#include <WebServer.h>      //Local DNS Server used for redirecting all requests to the configuration portal (  https://github.com/zhouhan0126/DNSServer---esp32  )
#include <DNSServer.h>      //Local WebServer used to serve the configuration portal (  https://github.com/zhouhan0126/DNSServer---esp32  )
#include <MPU6050.h>

// //Configuratie
#include <configuration.h>

// // define & variables
#include <wifi/credentials.h>      //added to gitignore
#include <main/globalvariables.h>

// // eigen subprogrammas
#include <main\i2cscanner.h>   
#include <main\dcmotors.h>
#include <setup\setup_dcmotors.h>
#include <main\gyro.h>
#include <setup\setup_mpu.h>
#include <setup\save_eprom.h>
//#include <main\testmotor.h>      // om motors te testen (aan/uit)
//#include <main\testmotorPWM.h>   // eerste versie om motors via PWM aan te sturen
//#include <main\testmotorPWM2.h>    // tweede versie met functies
//#include <main\testgyro.h>         // MPU6050 uittesten en printen

#include <ESPAsync_WiFiManager.h> 
#include <wifi/wifidefinitions.h>
#include <wifi/htmlbutton.h>
#include <wifi/html_configbutton.h>
#include <wifi/sendhtml.h>
#include <wifi/handle.h>
#include <wifi/setupwifi.h>          
#include <wifi/setupwifiManager.h>
#include <wifi/OTA.h>

#include <setup\setup_task.h>
