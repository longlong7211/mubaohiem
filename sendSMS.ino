void Send_SMS() {
  sim.write("AT+CMGF=1");
  sim.write(se, sizeof(se));
  delay(1000);
  sim.write("AT+CMGS=\"0947397499\"");
  sim.write(se, sizeof(se));
  delay(1000);
  sim.write("3 o banh mi thap cam nha co");
  sim.write(s, sizeof(s));
}
