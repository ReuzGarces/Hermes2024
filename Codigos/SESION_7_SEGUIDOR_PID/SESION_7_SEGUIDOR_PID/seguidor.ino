void seguidor(){
  error=posicion-sp;
  integral=integral+error;
  derivada=error - ultimoError;
  giro=kp*error+kd*derivada;
  velIzq=tp+giro;
  velDer=tp-giro;
  motor(velIzq,velDer);
  ultimoError=error ;
}
