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
int tp=50;
int boton = 0,posicion,error,integral,derivada,ultimoError;
int sp=0,fin=0,umbral=800,etapa=0;
float giro,velIzq,velDer;
float kp=0.4;
float ki=0;
float kd=5;
int geo5,geo4,geo3,geo2,geo1,geo;
void setup() {
  Serial.begin(9600);
  motorInicio();
  botonInicio();

}

void loop() {
  posicion = qtra.readLine(sensorValues, true, false);
  posicion = map(posicion, 0, 5000, -255, 255);
  hitos();
 seguidor();
}
