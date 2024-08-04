void seguidor(){
  error=posicion-sp;
  giro=kp*error;
  velIzq=tp+giro;
  velDer=tp-giro;
  motor(velIzq,velDer);
 
}
