#include <QTRSensors.h>
#include "IO_PINES.h"

// QTRA no modificar
#define NUM_SENSORS 6            // NUMERO DE SENSORES USADOS
#define NUM_SAMPLES_PER_SENSOR 4 // MUESTRAS POR SENSOR (DEJAR EN 4)
#define EMITTER_PIN 11           // PIN QUE CONTROLA EL EMISOR

QTRSensorsAnalog qtra((unsigned char[]) {
  5, 4, 3, 2, 1, 0
},
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
int tp=40;
int boton = 0,posicion,error;
int sp=0;
float giro,velIzq,velDer;
float kp=0.39;

void setup() {
  Serial.begin(9600);
  motorInicio();
  botonInicio();

}

void loop() {
  posicion = qtra.readLine(sensorValues, true, false);
  posicion = map(posicion, 0, 5000, -255, 255);
  seguidor();
}
