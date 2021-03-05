void  setup_dcmotors() {
  pinMode(motorLpin1, OUTPUT);
  pinMode(motorLpin2, OUTPUT);
  pinMode(motorRpin1, OUTPUT);
  pinMode(motorRpin2, OUTPUT);

  ledcAttachPin(motorLpin1, MOT_L_CHANNEL); 
  ledcAttachPin(motorLpin2, MOT_L_CHANNEL);
  ledcAttachPin(motorRpin1, MOT_R_CHANNEL);
  ledcAttachPin(motorRpin2, MOT_R_CHANNEL);

  ledcSetup(motorLpin1, freq, resolution);  // these will be updated later by the ledcWriteNote()
  ledcSetup(motorLpin2, freq, resolution);  // these will be updated later by the ledcWriteNote()

  disableL(true);
  disableR(true);
}
