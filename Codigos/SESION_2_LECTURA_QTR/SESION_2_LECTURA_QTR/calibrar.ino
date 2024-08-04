void calibrar()
{
  //motor(60, -60);
  for (uint16_t i = 0; i < 130; i++)
  {
    qtra.calibrate();
    delay(20);
  }
}
