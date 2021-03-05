// Configuration file

///////////////// MPU-6050 //////////////////////////

// Used I2Cscanner to find adress.  It's 0x68
static int MPU_ADDR = 0x68; //AD0 is HIGH


//////////////// MOTORS ////////////////////////////

//Pins
#define motorLpin1 26
#define motorLpin2 27
#define motorRpin1 25
#define motorRpin2 33

//ledc library
#define MOT_R_CHANNEL 1   // for the ledc library
#define MOT_L_CHANNEL 2   // for the ledc library
#define freq 20000        //pwm frequency
#define resolution 8      // 8bit

