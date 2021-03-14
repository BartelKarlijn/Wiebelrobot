// Arduino library includes
#include <Arduino.h>
#include <Wire.h>
//#include <WiFi.h>
//#include <WebServer.h>
//#include <I2Cdev.h>
#include <MPU6050.h>

// //Configuratie
#include <configuration.h>
#include <main/globalvariables.h>

// // define

// // eigen subprogrammas
#include <main\i2cscanner.h>   
#include <main\dcmotors.h>
#include <setup\setup_dcmotors.h>
#include <main\gyro.h>
#include <setup\setup_mpu.h>
#include <setup\setup_task.h>
//#include <main\testmotor.h>      // om motors te testen (aan/uit)
//#include <main\testmotorPWM.h>   // eerste versie om motors via PWM aan te sturen
//#include <main\testmotorPWM2.h>    // tweede versie met functies
//#include <main\testgyro.h>         // MPU6050 uittesten en printen

// #include <wifi/wifidefinitions.h>
// #include <wifi/htmlbutton.h>
// #include <wifi/sendhtml.h>
// #include <wifi/handle.h>
// #include <wifi/setupwifi.h>

