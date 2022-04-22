void loopMPU()
{
  // if programming failed, don't try to do anything
  if (!dmpReady) {return;}
  // read a packet from FIFO
  // Clear the buffer so as we can get fresh values
  // The sensor is running a lot faster than our sample period
  mpu.resetFIFO();
  
  // get current FIFO count
  fifoCount = mpu.getFIFOCount();

  // wait for correct available data length, should be a VERY short wait
  while (fifoCount < packetSize) {
    fifoCount = mpu.getFIFOCount();
  }
  // read a packet from FIFO
  mpu.getFIFOBytes(fifoBuffer, packetSize);

//  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer))
//  { // Get the Latest packet
    // display Euler angles in degrees
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

//  }

}