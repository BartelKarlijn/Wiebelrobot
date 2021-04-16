// Global variables

//////////////// LED ///////////////////////
boolean startupError;

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
float roll, pitch, rollAcc, pitchAcc;  // mag weg, wordt vervangen door onderstaand
float currentAngle, prevAngle;
float AngleX, AngleY, AngleZ;
volatile int16_t rotation = 0;         // om te kunnen draaien
float speeed;


//////// PID //////////

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
const char* oms_Kp = "Kp proportioneel";
const char* hdl_Kpup = "butkpup";
const char* hdl_Kpdo = "butkpdo";
const char* hdl_Kpch = "butkpch";

const char* oms_Ki = "Ki Integraal";
const char* hdl_Kiup = "butkiup";
const char* hdl_Kido = "butkido";

const char* oms_Kd = "Kd Derivation";
const char* hdl_Kdup = "butkdup";
const char* hdl_Kddo = "butkddo";

const char* oms_Angle = "Balanceer Hoek";
const char* hdl_Angleup = "butAngleup";
const char* hdl_Angledo = "butAngledo";

const char* oms_SaveConfig = "Save PID";
const char* hdl_SaveConfig = "butSaveConfig";

const char* oms_Restart = "Restart";
const char* hdl_Restart = "butRestart";

const char* oms_ShowAngle = "Gemeten Hoek= ";
const char* hdl_ShowAngel = "butShowAngle";

volatile float Kp_change = 1.0;      // Elke druk in wifi app, verhoogt/verlaagt met waarde
volatile float Ki_change = 1.0;
volatile float Kd_change = 1.0; 
