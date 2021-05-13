// Global variables

//////////////// LED ///////////////////////
boolean startupError;

//////////////// MOTORS ////////////////////////////
uint32_t prevSpeedStart;
int16_t prevSpeed;
int32_t currentPos = 0;

///////////////// MPU-6050 //////////////////////////
MPU6050 mpu;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 gy;         // [x, y, z]            gyro sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// MPU waarden, ook gebruikt voor Calibratie
int16_t accX, accY, accZ, gyroX, gyroY, gyroZ;
int accX_offset, accY_offset, accZ_offset, gyroX_offset, gyroY_offset, gyroZ_offset;
int mean_accX, mean_accY, mean_accZ, mean_gyroX, mean_gyroY, mean_gyroZ = 0;
int accX_offsetinit, accY_offsetinit, accZ_offsetinit, gyroX_offsetinit, gyroY_offsetinit, gyroZ_offsetinit;
int state_calibration = 0;
unsigned int calibratedOffsetAdress = 0;
unsigned int loopcount=0;


// hieronder mag misschien weg...
// MPU6050 specific
#define GYRO_SCALE_FACTOR             131     // LSB / (degs per seconds)
#define ACC_SCALE_FACTOR              8192    // LSB / g

//static float GYRO_RAW_TO_DEGS = 1.0 / (1000000.0 / PERIOD) / GYRO_SCALE_FACTOR;

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

uint8_t retval;   //Return value mpu6050


//////// Controller //////////

// populated in the SerialControl part
uint8_t joystickX;
uint8_t joystickY;
uint32_t loop_timer;
uint32_t print_timer;
float roll, pitch, rollAcc, pitchAcc;  // mag weg, wordt vervangen door onderstaand
volatile float currentAngle;
float prevAngle;
float AngleX, AngleY, AngleZ;
volatile int16_t rotation = 0;         // om te kunnen draaien
float speeed;


//////// PID //////////
Preferences pref_eeprom;

volatile float Kp;  // Volatile is necessary so that variables can be shared between cores
volatile float Ki;
volatile float Kd;
volatile float selfBalanceAngleSetpoint;
volatile float pidOutput, pidError, pidLastError, integralErr, positionErr, serialControlErr, prevSerialControlErr, errorDerivative;

float MAX_CONTROL_OR_POSITION_ERR = MAX_PID_OUTPUT / Kp;
float MAX_CONTROL_ERR_INCREMENT = MAX_CONTROL_OR_POSITION_ERR / 400;
#define MIN_CONTROL_ERR 1

uint8_t PrintPIDLoops = PrintPIDMillis * 1000 / PERIOD ;   //hoeveel loops overslaan om serial print te doen van PID parameteters?
uint8_t PrintPIDloopCounter = 0;

//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
DNSServer dnsServer;
TaskHandle_t Task1;    //Taskhandle om wifi op 2e cpu te draaien
const char* PARAM_INPUT_1 = "output";   // voor de asyncwebserver
const char* PARAM_INPUT_2 = "state";

const char* oms_Kp = "Kp proportioneel";
const char* hdl_Kpup = "butkpup";
const char* hdl_Kpdo = "butkpdo";
const char* hdl_Kpch = "butkpch";

const char* oms_Ki = "Ki Integraal";
const char* hdl_Kiup = "butkiup";
const char* hdl_Kido = "butkido";
const char* hdl_Kich = "butkich";

const char* oms_Kd = "Kd Derivation";
const char* hdl_Kdup = "butkdup";
const char* hdl_Kddo = "butkddo";
const char* hdl_Kdch = "butkdch";

const char* oms_An = "Balanceer Hoek";
const char* hdl_Anup = "butanup";
const char* hdl_Ando = "butando";
const char* hdl_Anch = "butanch";

const char* oms_ShowAngle = "Gemeten Hoek= ";
const char* hdl_ShowAngle = "butShowAngle";

const char* oms_SaveConfig = "Save PID";
const char* hdl_SaveConfig = "butSaveConfig";

const char* oms_Restart = "Restart";
const char* hdl_Restart = "butRestart";

volatile float Kp_change = 1.0;      // Elke druk in wifi app, verhoogt/verlaagt met waarde
volatile float Ki_change = 1.0;
volatile float Kd_change = 1.0; 
volatile float An_change = 1.0; 
