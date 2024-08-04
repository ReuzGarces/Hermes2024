void calibrar()
{
  motor(30, -30);
  for (uint16_t i = 0; i < 70; i++)
  {
    qtra.calibrate();
    delay(20);
  }
}
