void  setup_dcmotors() {
  pinMode(motorLpin1, OUTPUT);
  pinMode(motorLpin2, OUTPUT);
  pinMode(motorRpin1, OUTPUT);
  pinMode(motorRpin2, OUTPUT);

  ledcSetup(motorLcha1, freq, resolution);  
  ledcSetup(motorLcha2, freq, resolution);  
  ledcSetup(motorRcha1, freq, resolution);  
  ledcSetup(motorRcha2, freq, resolution);  

  ledcAttachPin(motorLpin1, motorLcha1); 
  ledcAttachPin(motorLpin2, motorLcha2);
  ledcAttachPin(motorRpin1, motorRcha1); 
  ledcAttachPin(motorRpin2, motorRcha2);

  forwardL(0);
  forwardR(0);
}
