void Print(String TXT){
#ifdef PrintWebserial
  WebSerial.print(TXT);
#endif
#ifdef PrintSerial
  Serial.print(TXT);
#endif
}

void Println(String TXT){
#ifdef PrintWebserial
  WebSerial.println(TXT);
#endif
#ifdef PrintSerial
  Serial.println(TXT);
#endif
}