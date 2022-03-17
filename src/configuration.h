// Configuration file

///////////////// I2C  //////////////////////////////

// Used default I2C pins
// SDA gpio21
// SCL gpio22
#define ledpin 2         // ESP32 Pin to which onboard LED is connected
#define ledstartblink 4  // Hoeveel keer knipperen bij start?

///////////////// MPU-6050 //////////////////////////

// Used I2Cscanner to find adress.  It's 0x68
// See page 12 & 13 of MPU-6050 datasheet for sensitivities config and corresponding output
// Dit definieert de gevoeligheid;  0: 250 degrees/second | 1: 500deg/s | 2: 1000deg/s | 3: 2000deg/s
#define GYRO_FULL_SCALE_RANGE         0 // 250 deg/sec, het meest gevoelige
// Dit definieert de gevoeligheid;  0: 2g | 1: 4g | 2: 8g | 3: 16g
#define ACC_FULL_SCALE_RANGE          0 //2g, het meest gevoelige

// we willen niet elke keer gyro calibreren, daarom hieronder preset waarden 
// om te calibreren, uncomment flag_calibrateMPU
// 2021 05 08 mpu ondersteboven gecalibreerd
/*
#define preset_XGyroOffset -2261
#define preset_YGyroOffset 1731
#define preset_ZGyroOffset 4743
#define preset_XAccelOffset 0
#define preset_YAccelOffset -43
#define preset_ZAccelOffset 26
*/
// 2021 05 08 mpu plat liggend gecalibreerd
#define preset_XGyroOffset -3489
#define preset_YGyroOffset 1821
#define preset_ZGyroOffset 1628
#define preset_XAccelOffset 0
#define preset_YAccelOffset -43
#define preset_ZAccelOffset 28

///////////////// MPU-6050 Calibration //////////////////////////
// Calibratie moet eigenlijk maar 1x gebeuren
//#define flag_calibrateMPU   //Uncomment om calibratie te doen
#ifdef flag_calibrateMPU
  //Change this 3 variables if you want to fine tune the skecth to your needs.
  int buffersize=1500;     //Amount of readings used to average, make it higher to get more precision but sketch will be slower  (default:1000)
  int discardfirstmeas=100;  // Amount of initial measurements to be discarded
  int acel_deadzone=6;     //Acelerometer error allowed, make it lower to get more precision, but sketch may not converge  (default:8)
  int gyro_deadzone=6;     //Giro error allowed, make it lower to get more precision, but sketch may not converge  (default:1)
  int accel_offset_divisor=8; //8;
  int gyro_offset_divisor=4; //4;
  int maxloopCount = 100;    //default 20
  // deadzone: amount of variation between 2 consecutive measurements
#endif


//////////////// MOTORS ////////////////////////////

//Pins
//#define motorLpin1 26
//#define motorLpin2 27
//#define motorRpin1 33
//#define motorRpin2 25
#define motorLpinDIR  26
#define motorLpinSTEP 27
#define motorRpinDIR  33
#define motorRpinSTEP 25

#define FlagNotMotor false  //true: motoren niet laten draaien

//ledc library
#define motorLcha1 0   // for the ledc library
#define motorLcha2 1   // for the ledc library
#define motorRcha1 2   // for the ledc library
#define motorRcha2 3   // for the ledc library
#define freq 20000          //pwm frequency 20000
#define resolution 10     // 8bit

// speed
#define MAX_SPEED 1024   // 10bit dus tot 1024
#define MIN_SPEED 700    // 10bit  Hieronder draait motortje niet
#define RUST_SPEED 5   // 10bit, het motorbereik wordt gezet op "MIN-RUST" tot "MAX"
#define MAX_SPEEDSTEPPER 300

// PID
float BASE_Kp = 0.0;
float BASE_Ki = 0.0;
float BASE_Kd = 0.0;
float BASE_Angle = 0.0;

#define MAX_PID_OUTPUT 1000     // bepaalt hoe groot PID params kunnen zijn
float MAXintegralErr = 100.0;   // zorgt dat de I niet belachelijk groot wordt
volatile float angleSetpoint = 0;  //rechtop staan.

#define PERIOD          4000    // loop period in micros default 4000 microsec,  MPU6050 geeft graden/sec weer.  Hier dus schatting van looptime wordt oa bij gyro calibratie gebruikt als delay
#define SerialSpeed   230400    // was 115200
#define PrintPIDMillis  1000    // Hoe dikwijls PIDparameters Serial printen?

///////////////// wifi  //////////////////////////////
#define autoConnectAP "WiebelRobot"    //ssid access point voor als je niet aan wifi geraakt
#define autoConnectName "WiebelRobot"      //naam op het wifi netwerk, als het werkt
#define autoConnectIP IPAddress(192,168,1,1)     // ip adress
#define autoConnectGW IPAddress(192,168,1,1)     // gateway
#define autoConnectSN IPAddress(255,255,255,0)   // subnet

#define autoConnectReset false                   // om alle gegevens van autoconnect te herzeten
