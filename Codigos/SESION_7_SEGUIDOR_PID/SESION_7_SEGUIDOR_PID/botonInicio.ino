void botonInicio() {
  
  while (boton == 0)
  {
    boton = digitalRead(B);
  }
  
  boton = 0;
  calibrar();
  motor(0, 0);
  while (boton == 0)
  {
    boton = digitalRead(B);
  }
 
  delay(2000);
}
