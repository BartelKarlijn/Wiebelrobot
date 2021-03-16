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

volatile float Kp = BASE_Kp;  // Volatile is necessary so that variables can be shared between cores
volatile float Ki = BASE_Ki;
volatile float Kd = BASE_Kd;    
float angleSetpoint = 0, selfBalanceAngleSetpoint = 0;
float pidOutput, pidError, pidLastError, integralErr, positionErr, serialControlErr, prevSerialControlErr, errorDerivative;

float MAX_CONTROL_OR_POSITION_ERR = MAX_PID_OUTPUT / Kp;
float MAX_CONTROL_ERR_INCREMENT = MAX_CONTROL_OR_POSITION_ERR / 400;
#define MIN_CONTROL_ERR 1


//////// Wifi //////////
const char* oms_Kp = "Kp proportioneel";
const char* hdl_Kpup = "butkpup";
const char* hdl_Kpdo = "butkpdo";

const char* oms_Ki = "Ki Integraal";
const char* hdl_Kiup = "butkiup";
const char* hdl_Kido = "butkido";

const char* oms_Kd = "Kd Derivation";
const char* hdl_Kdup = "butkdup";
const char* hdl_Kddo = "butkddo";
