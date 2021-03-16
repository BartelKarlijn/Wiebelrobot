// Configuration file

///////////////// I2C  //////////////////////////////

// Used default I2C pins
// SDA gpio21
// SCL gpio22


///////////////// MPU-6050 //////////////////////////

// Used I2Cscanner to find adress.  It's 0x68
static int MPU_ADDR = 0x68;  


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
float BASE_Kp = 100.0;
float BASE_Ki = 5.0;
float BASE_Kd = 130.0;
#define Kp_change 10      // Elke druk in wifi app, verhoogt/verlaagt met waarde
#define Ki_change 0.5 
#define Kd_change 10 

#define PERIOD  9000    // loop period in micros default 4000
#define PRINT_PERIOD  100000    // print period in micros


