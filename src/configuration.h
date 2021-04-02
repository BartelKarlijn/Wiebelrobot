// Configuration file

///////////////// I2C  //////////////////////////////

// Used default I2C pins
// SDA gpio21
// SCL gpio22


///////////////// MPU-6050 //////////////////////////

// Used I2Cscanner to find adress.  It's 0x68
static int MPU_ADDR = 0x68;  
#define gyroCalibrationLoops 200    //Hoeveel loops om te calibreren?

//////////////// MOTORS ////////////////////////////

//Pins
#define motorLpin1 26
#define motorLpin2 27
#define motorRpin1 25
#define motorRpin2 33

//ledc library
#define motorLcha1 0   // for the ledc library
#define motorLcha2 1   // for the ledc library
#define motorRcha1 2   // for the ledc library
#define motorRcha2 3   // for the ledc library
#define freq 20000          //pwm frequency 20000
#define resolution 10     // 8bit

// speed
#define MAX_SPEED 1024   // 10bit dus tot 1024
#define MIN_SPEED 660    // 10bit  Hieronder gebeurt er niets

// PID ?
float BASE_Kp = 1.0;
float BASE_Ki = 0.0;
float BASE_Kd = 0.0;
#define Kp_change 1      // Elke druk in wifi app, verhoogt/verlaagt met waarde
#define Ki_change 0.1
#define Kd_change 1 
#define MAX_PID_OUTPUT 1000  // bepaalt hoe groot PID params kunnen zijn

#define PERIOD  4000    // loop period in micros default 4000 microsec,  MPU6050 geeft graden/sec weer.  Hier dus schatting van looptime wordt oa bij gyro calibratie gebruikt als delay
#define PRINT_PERIOD  100000    // print period in microsec
#define SerialSpeed   230400 //was 115200

///////////////// wifi  //////////////////////////////
#define autoConnectAP "WiebelRobot"    //ssid access point voor als je niet aan wifi geraakt
#define autoConnectName "WiebelRobot"      //naam op het wifi netwerk, als het werkt
#define autoConnectIP IPAddress(192,168,1,1)     // ip adress
#define autoConnectGW IPAddress(192,168,1,1)     // gateway
#define autoConnectSN IPAddress(255,255,255,0)   // subnet

#define autoConnectReset false                   // om alle gegevens van autoconnect te herzeten
