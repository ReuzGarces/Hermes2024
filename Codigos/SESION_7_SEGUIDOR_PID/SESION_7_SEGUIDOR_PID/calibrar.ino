void calibrar()
{
  motor(30, -50);
  for (uint16_t i = 0; i < 70; i++)
  {
    qtra.calibrate();
    delay(20);
  }
}
