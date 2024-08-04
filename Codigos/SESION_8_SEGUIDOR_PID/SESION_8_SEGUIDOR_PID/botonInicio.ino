void botonInicio() {

  while (boton == 0)
  {
    boton = digitalRead(B);
    hitos();
  }
  etapa=1;
  tone(BUZZER, 600, 230);
  delay(162);
  noTone(BUZZER);
  boton = 0;
  calibrar();
  motor(0, 0);
  while (boton == 0)
  {
    boton = digitalRead(B);
  }

  delay(1000);
}
