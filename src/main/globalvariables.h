// Global variables

//////////////// MOTORS ////////////////////////////
uint32_t prevSpeedStart;
int16_t prevSpeed;
int32_t currentPos = 0;


///////////////// MPU-6050 //////////////////////////
// MPU6050 specific
#define MPU6050_FS_SEL0 3
#define MPU6050_FS_SEL1 4
#define MPU6050_AFS_SEL0 3
#define MPU6050_AFS_SEL1 4

// Combined definitions for the FS_SEL values.eg.  ±250 degrees/second
#define MPU6050_FS_SEL_250  (0)
#define MPU6050_FS_SEL_500  (bit(MPU6050_FS_SEL0))
#define MPU6050_FS_SEL_1000 (bit(MPU6050_FS_SEL1))
#define MPU6050_FS_SEL_2000 (bit(MPU6050_FS_SEL1) | bit(MPU6050_FS_SEL0))

// Combined definitions for the AFS_SEL values
#define MPU6050_AFS_SEL_2G  (0)
#define MPU6050_AFS_SEL_4G  (bit(MPU6050_AFS_SEL0))
#define MPU6050_AFS_SEL_8G  (bit(MPU6050_AFS_SEL1))
#define MPU6050_AFS_SEL_16G (bit(MPU6050_AFS_SEL1)|bit(MPU6050_AFS_SEL0))

// See page 12 & 13 of MPU-6050 datasheet for sensitivities config and corresponding output
#define GYRO_FULL_SCALE_RANGE         MPU6050_FS_SEL_250
#define GYRO_SCALE_FACTOR             131     // LSB / (degs per seconds)
#define ACC_FULL_SCALE_RANGE          MPU6050_AFS_SEL_4G
#define ACC_SCALE_FACTOR              8192    // LSB / g

static float GYRO_RAW_TO_DEGS = 1.0 / (1000000.0 / PERIOD) / GYRO_SCALE_FACTOR;

int16_t accX, accY, accZ;
int16_t gyroX, gyroY, gyroZ;
int16_t gyroX_calibration, gyroY_calibration, gyroZ_calibration;

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
float roll, pitch, rollAcc, pitchAcc;
float speeed;


//////// PID //////////

#define MAX_PID_OUTPUT 1

volatile float Kp;  // Volatile is necessary so that variables can be shared between cores
volatile float Ki;
volatile float Kd;
float angleSetpoint = 0, selfBalanceAngleSetpoint = 0;
float pidOutput, pidError, pidLastError, integralErr, positionErr, serialControlErr, prevSerialControlErr, errorDerivative;

float MAX_CONTROL_OR_POSITION_ERR = MAX_PID_OUTPUT / Kp;
float MAX_CONTROL_ERR_INCREMENT = MAX_CONTROL_OR_POSITION_ERR / 400;
#define MIN_CONTROL_ERR 1

uint8_t PrintPIDLoops = PrintPIDMillis * 1000 / PERIOD ;   //hoeveel loops overslaan om serial print te doen van PID parameteters?
uint8_t PrintPIDloopCounter = 0;

//////////////// MOTORS ////////////////////////////
uint32_t prevSpeedStart;
int16_t prevSpeed;
int32_t currentPos = 0;
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define motorInterfaceType 1  
// Create a new instance of the AccelStepper class:
AccelStepper stepperL = AccelStepper(motorInterfaceType, motorLpinSTEP , motorLpinDIR);
AccelStepper stepperR = AccelStepper(motorInterfaceType, motorRpinSTEP , motorRpinDIR);


//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken

TaskHandle_t Task1;    //Taskhandle om wifi op 2e cpu te draaien
const char* PARAM_output = "output";   // voor de asyncwebserver
const char* PARAM_joyX   = "joyX";     // voor de asyncwebserver
const char* PARAM_joyY   = "joyY";     // voor de asyncwebserver
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver

// handles voor wifi paginas
#define hdlController "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlConfig     "/configuratie"            // handle voor wiebelrobot in te stellen
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlJoystick   "/joy"                     // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiPWD    "/wificfg"                 // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
//#define hdlWifiScan   "/wifiscan"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiSave   "/wifisave"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWebSerial  "/webserial"               // Dit is niet te wijzigen, is om Serial Monitor via web te hebben

// knoppen
const char* oms_Kp = "Kp proportioneel";
const char* hdl_Kpup = "butkpup";
const char* hdl_Kpdo = "butkpdo";

const char* oms_Ki = "Ki Integraal";
const char* hdl_Kiup = "butkiup";
const char* hdl_Kido = "butkido";

const char* oms_Kd = "Kd Derivation";
const int   id_Kdup = 131;
const int   id_Kddo = 132; 
const int   id_Kdra = 133;  

const char* oms_An = "Balanceer Hoek";
const int   id_Anup = 141;
const int   id_Ando = 142; 
const int   id_Anra = 143;  

const char* oms_ShowAngle = "Gemeten Hoek= ";
const int   id_ShowAngle = 21;

const char* oms_SaveConfig = "Save PID";
const int   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const int   id_Restart = 23;

volatile float Kp_change = 1.0;      // Elke druk in wifi app, verhoogt/verlaagt met waarde
volatile float Ki_change = 1.0;
volatile float Kd_change = 1.0; 
volatile float An_change = 1.0; 

//////// Controller //////////
// populated in the SerialControl part
volatile int joystickX;
volatile int joystickY;
uint32_t loop_timer;
uint32_t print_timer;
float roll, pitch, rollAcc, pitchAcc;  // mag weg, wordt vervangen door onderstaand
volatile float currentAngle;
float prevAngle;
float AngleX, AngleY, AngleZ;
volatile int16_t rotation = 0;         // om te kunnen draaien
float speeed;


const char* oms_Save = "Save PID";
const char* hdl_Save = "butSave";
