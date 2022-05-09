// Global variables

//////////////// LED ///////////////////////
boolean startupError;

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

TaskHandle_t Task1;    //Taskhandle om wifi op 2e cpu te draaien
const char* PARAM_output = "output";   // voor de asyncwebserver
const char* PARAM_joyX   = "joyX";     // voor de asyncwebserver
const char* PARAM_joyY   = "joyY";     // voor de asyncwebserver

// handles voor wifi paginas
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlController "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlConfig     "/configuratie"            // handle voor wiebelrobot in te stellen
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlJoystick   "/joy"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt

// knoppen
const char* oms_Kp = "Kp proportioneel";
const int   id_Kpup = 111;            // knop ID, moet uniek zijn, zie html_processor
const int   id_Kpdo = 112; 
const int   id_Kpra = 113;  

const char* oms_Ki = "Ki Integraal";
const int   id_Kiup = 121;
const int   id_Kido = 122; 
const int   id_Kira = 123;  

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


