// Arduino sketch that returns calibration offsets for MPU6050 //   Version 1.1  (31th January 2014)
// Done by Luis Ródenas <luisrodenaslorda@gmail.com>
// Based on the I2Cdev library and previous work by Jeff Rowberg <jeff@rowberg.net>
// Updates (of the library) should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib

// These offsets were meant to calibrate MPU6050's internal DMP, but can be also useful for reading sensors.
// The effect of temperature has not been taken into account so I can't promise that it will work if you
// calibrate indoors and then use it outdoors. Best is to calibrate and use at the same room temperature.

///////////////////////////////////   FUNCTIONS   ////////////////////////////////////
void meansensors()
{
    long i = 0, buff_ax = 0, buff_ay = 0, buff_az = 0, buff_gx = 0, buff_gy = 0, buff_gz = 0;

    while (i < (buffersize + discardfirstmeas + 1))
    {
        // read raw accel/gyro measurements from device
        mpu.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);

        if (i > discardfirstmeas && i <= (buffersize + discardfirstmeas))
        { //First 100 measures are discarded
            buff_ax = buff_ax + accX;
            buff_ay = buff_ay + accY;
            buff_az = buff_az + accZ;
            buff_gx = buff_gx + gyroX;
            buff_gy = buff_gy + gyroY;
            buff_gz = buff_gz + gyroZ;
        }
        if (i == (buffersize + 100))
        {
            mean_accX = buff_ax / buffersize;
            mean_accY = buff_ay / buffersize;
            mean_accZ = buff_az / buffersize;
            mean_gyroX = buff_gx / buffersize;
            mean_gyroY = buff_gy / buffersize;
            mean_gyroZ = buff_gz / buffersize;
        }
        i++;
        delay(2); //Needed so we don't get repeated measures
    }

    Serial.print("Results of measurements a/g:\t");
    Serial.print(mean_accX);
    Serial.print("\t");
    Serial.print(mean_accY);
    Serial.print("\t");
    Serial.print(mean_accZ);
    Serial.print("\t");
    Serial.print(mean_gyroX);
    Serial.print("\t");
    Serial.print(mean_gyroY);
    Serial.print("\t");
    Serial.println(mean_gyroZ);
}

bool calibration()
{
    accX_offset = -mean_accX / accel_offset_divisor;
    accY_offset = -mean_accY / accel_offset_divisor;
    //az_offset=- mean_accZ/accel_offset_divisor;
    accZ_offset = (16384 - mean_accZ) / 8;

    gyroX_offset = -mean_gyroX / gyro_offset_divisor;
    gyroY_offset = -mean_gyroY / gyro_offset_divisor;
    gyroZ_offset = -mean_gyroZ / gyro_offset_divisor;
    while (1)
    {
        int ready = 0;
        mpu.setXAccelOffset(accX_offset + accX_offsetinit);
        mpu.setYAccelOffset(accY_offset + accY_offsetinit);
        mpu.setZAccelOffset(accZ_offset + accZ_offsetinit);

        mpu.setXGyroOffset(gyroX_offset + gyroX_offsetinit);
        mpu.setYGyroOffset(gyroY_offset + gyroY_offsetinit);
        mpu.setZGyroOffset(gyroZ_offset + gyroZ_offsetinit);

        meansensors();
        Serial.println("...");

        if (abs(mean_accX) <= acel_deadzone)
            ready++;
        else
            accX_offset = accX_offset - mean_accX / acel_deadzone;

        if (abs(mean_accY) <= acel_deadzone)
            ready++;
        else
            accY_offset = accY_offset - mean_accY / acel_deadzone;

        //if (abs( mean_accZ)<=acel_deadzone) ready++;
        //else az_offset=az_offset- mean_accZ/acel_deadzone;

        if (abs(16384 - mean_accZ) <= acel_deadzone)
            ready++;
        else
            accZ_offset = accZ_offset + (16384 - mean_accZ) / acel_deadzone;

        if (abs(mean_gyroX) <= gyro_deadzone)
            ready++;
        else
            gyroX_offset = gyroX_offset - mean_gyroX / (gyro_deadzone + 1);

        if (abs(mean_gyroY) <= gyro_deadzone)
            ready++;
        else
            gyroY_offset = gyroY_offset - mean_gyroY / (gyro_deadzone + 1);

        if (abs(mean_gyroZ) <= gyro_deadzone)
            ready++;
        else
            gyroZ_offset = gyroZ_offset - mean_gyroZ / (gyro_deadzone + 1);

        if (ready == 6)
        {
            return true;
            break;
        }

        Serial.print("Resulting offset calibration value a/g:\t");
        Serial.print(accX_offset + accX_offsetinit);
        Serial.print("\t");
        Serial.print(accY_offset + accY_offsetinit);
        Serial.print("\t");
        Serial.print(accZ_offset + accZ_offsetinit);
        Serial.print("\t");
        Serial.print(gyroX_offset + gyroX_offsetinit);
        Serial.print("\t");
        Serial.print(gyroY_offset + gyroY_offsetinit);
        Serial.print("\t");
        Serial.println(gyroZ_offset + gyroZ_offsetinit);
        loopcount = loopcount + 1;
        Serial.print("Loop Cnt: ");
        Serial.println(loopcount);
        if (loopcount == maxloopCount)
        {
            return false;
            break; // exit the calibration routine if no stable results can be obtained after maxloopCount calibration loops
        }
    }
}

///////////////////////////////////   SETUP   ////////////////////////////////////
void calibrateMPUsetup()
{
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();

    // start message
    Serial.println("\nMPU6050 Calibration Sketch");
    delay(2000);
    Serial.println("\nYour MPU6050 should be placed in horizontal position, with package letters facing up. \nDon't touch it until you see a finish message.\n");
    delay(3000);
    // verify connection
    Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    delay(1000);

    // reset offsets
    accX_offsetinit = 0;
    accY_offsetinit = 0;
    accZ_offsetinit = 0;
    gyroX_offsetinit = 0;
    gyroY_offsetinit = 0;
    gyroZ_offsetinit = 0;

    mpu.setXAccelOffset(accX_offsetinit);
    mpu.setYAccelOffset(accY_offsetinit);
    mpu.setZAccelOffset(accZ_offsetinit);
    mpu.setXGyroOffset(gyroX_offsetinit);
    mpu.setYGyroOffset(gyroY_offsetinit);
    mpu.setZGyroOffset(gyroZ_offsetinit);

    // set the fll scale range of the gyro- and accelerometer respectively
    mpu.setFullScaleGyroRange(GYRO_FULL_SCALE_RANGE); //0: 250deg/s
    mpu.setFullScaleAccelRange(ACC_FULL_SCALE_RANGE); //0: 2g
}

///////////////////////////////////   LOOP   ////////////////////////////////////
void calibrateMPUloop() {

    bool CalibResult = false;

    if (state_calibration == 0)
    {
        Serial.println("\nReading sensors for first time...");
        meansensors();
        //if (abs( mean_accX)>=32000){ax_initoffset=- mean_accX;Serial.println("\nRemove X-axis deadlock...");}
        //if (abs( mean_accY)>=32000){ay_initoffset=- mean_accY;Serial.println("\nRemove Y-axis deadlock...");}
        //if ( mean_accZ<-32000){az_initoffset=- mean_accZ;Serial.println("\nRemove Z-axis deadlock...");}
        //if (abs(mean_gyroX)>=32000){gx_initoffset=-mean_gyroX;Serial.println("\nRemove Gyro X-axis deadlock...");}
        //if (abs(mean_gyroY)>=32000){gy_initoffset=-mean_gy;Serial.println("\nRemove Gyro Y-axis deadlock...");}
        //if (mean_gyroZ<-32000){gz_initoffset=-mean_gyroZ;Serial.println("\nRemove Gyro Z-axis deadlock...");}
        state_calibration++;
        delay(1000);
    }

    if (state_calibration == 1)
    {
        Serial.println("\nCalculating offsets...");
        CalibResult = calibration();
        if (CalibResult)
        {
            Serial.println("\nCalibration successful!");
        }
        else
        {
            Serial.println("\nCalibration failed!");
        }
        state_calibration++;
        delay(1000);
    }

    if (state_calibration == 2)
    {
        meansensors();

        Serial.println("\nFINISHED!");
        Serial.print("\nSensor readings with offsets:\t");
        Serial.print(mean_accX);
        Serial.print("\t");
        Serial.print(mean_accY);
        Serial.print("\t");
        Serial.print(mean_accZ);
        Serial.print("\t");
        Serial.print(mean_gyroX);
        Serial.print("\t");
        Serial.print(mean_gyroY);
        Serial.print("\t");
        Serial.println(mean_gyroZ);
        Serial.print("Your offsets:\t");
        Serial.print(accX_offset + accX_offsetinit);
        Serial.print("\t");
        Serial.print(accY_offset + accY_offsetinit);
        Serial.print("\t");
        Serial.print(accZ_offset + accZ_offsetinit);
        Serial.print("\t");
        Serial.print(gyroX_offset + gyroX_offsetinit);
        Serial.print("\t");
        Serial.print(gyroY_offset + gyroY_offsetinit);
        Serial.print("\t");
        Serial.print(gyroZ_offset + gyroZ_offsetinit);
        Serial.println("\nData is printed as: acelX acelY acelZ giroX giroY giroZ");
        Serial.println("Check that your sensor readings are close to 0 0 16384 0 0 0");
        Serial.println("If calibration was succesful write down your offsets so you can set them in your projects using something similar to mpu.setXAccelOffset(youroffset)");

        state_calibration++;

    }  
}