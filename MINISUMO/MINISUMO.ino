// Sensor ultraSonico
// Sensor Frontal
#include <NewPing.h>
#define TriggerF  2   //Pin digital 2 para el Trigger del sensor
#define EchoF  3 //Pin digital 3 para el echo del sensor
// Sensor derecho
#define TriggerR  4
#define EchoR  5
// Sensor Izquierdo
#define TriggerD  6
#define EchoD  7

#define MAX_DIST 200

// Inicializamos la libreria de Newping, generando 3 sensores
NewPing sensor_1(TriggerF,EchoF,MAX_DIST);
NewPing sensor_2(TriggerD,EchoD,MAX_DIST);
NewPing sensor_3(TriggerR,EchoR,MAX_DIST);

//Motores
#define mA 11
#define mA1 10
#define mB 9
#define mB1 8


void setup() {
  Serial.begin(9600);
// Inicializamos el motor derecho
  pinMode(mA, OUTPUT);
  pinMode(mA1, OUTPUT);
//Inicializamos el motor izquierdo
  pinMode(mB, OUTPUT);
  pinMode(mB1, OUTPUT);
}
 
void loop() {
  // Esto se va a eliminar, namas es para que me aparezcan los valores de la distancia
  Serial.print("Sensor frontal(1):");
  Serial.print(sensor_1.ping_cm());
  Serial.println()
  Serial.print("Sensor Derecho(2):");
  Serial.print(sensor_2.ping_cm());
  Serial.println()
  Serial.print("Sensor Izquierdo(3):");
  Serial.print(sensor_3.ping_cm());
  Serial.println()
}
void front(){
  digitalWrite(mA, HIGH);
  digitalWrite(mA1, LOW);
  digitalWrite(mB1, HIGH);
  digitalWrite(mB, LOW);
}

void back(){
  digitalWrite(mA, LOW);
  digitalWrite(mA1, HIGH);
  digitalWrite(mB1, LOW);
  digitalWrite(mB, HIGH);
}