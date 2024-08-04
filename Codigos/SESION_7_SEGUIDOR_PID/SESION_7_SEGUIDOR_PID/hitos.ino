void hitos() {
  int Hiz = analogRead(HIZ);
  int Hde = analogRead(HDE);
  // se modificaron los "<" de umbral por ">"

  if (Hiz > umbral) {
    Hiz = 1;
  } else {
    Hiz = 0;
  }

  if (Hde > umbral) {
    Hde = 1;
  } else {
    Hde = 0;
  }

  if (Hiz == 0 && Hde == 0) {
    geo = 0;
  }
  if (Hiz == 1 && Hde == 0) {
    geo = 1;
  }
  if (Hiz == 0 && Hde == 1) {
    geo = 2;
  }
  if (Hiz == 1 && Hde == 1) {
    geo = 3;
  }

  if (geo1 != geo) {
    if (geo == 0 && geo1 == 1 && geo2 == 0) {
      tone(BUZZER, 200, 200);

    }
    if (geo == 0 && geo1 == 2 && geo2 == 0) {

      fin++;
      while(fin==2){
        motor(0,0);
      }
    }
    if (geo == 0 && ((geo1 == 3) || (geo2 == 3) || (geo3 == 3))) {
      Serial.println("Intersection");
    }
    geo5 = geo4;
    geo4 = geo3;
    geo3 = geo2;
    geo2 = geo1;
    geo1 = geo;
  }
}
