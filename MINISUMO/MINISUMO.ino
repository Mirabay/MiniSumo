// Sensor ultraSonico
// Sensor Frontal
const int TriggerF = 2;   //Pin digital 2 para el Trigger del sensor
const int EchoF = 3;   //Pin digital 3 para el echo del sensor
// Sensor derecho
const int TriggerR = 4;
const int EchoR = 5;
// Sensor Izquierdo
const int TriggerD = 6;
const int EchoD = 7;

long tF; //timepo que demora en llegar el eco
long dF; //distancia en centimetros

long tR; //timepo que demora en llegar el eco
long dR; //distancia en centimetros

long tD; //timepo que demora en llegar el eco
long dD; //distancia en centimetros

//Motores
const int mA =11;
const int mA1=10;
const int mB=9;
const int mB1=8;


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación

  pinMode(TriggerF, OUTPUT); //pin como salida
  pinMode(EchoF, INPUT);  //pin como entrada
  digitalWrite(TriggerF, LOW);//Inicializamos el pin con 0

  pinMode(TriggerD, OUTPUT); //pin como salida
  pinMode(EchoD, INPUT);  //pin como entrada
  digitalWrite(TriggerD, LOW);//Inicializamos el pin con 0

  pinMode(TriggerR, OUTPUT); //pin como salida
  pinMode(EchoR, INPUT);  //pin como entrada
  digitalWrite(TriggerR, LOW);//Inicializamos el pin con 0

// Inicializamos el motor derecho
  pinMode(mA, OUTPUT);
  pinMode(mA1, OUTPUT);
//Inicializamos el motor izquierdo
  pinMode(mB, OUTPUT);
  pinMode(mB1, OUTPUT);
}
 
void loop() {

  digitalWrite(TriggerF, HIGH);
  digitalWrite(TriggerD, HIGH);
  digitalWrite(TriggerR, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(TriggerF, LOW);
  digitalWrite(TriggerD, LOW);
  digitalWrite(TriggerR, LOW);


  tF = pulseIn(EchoF, HIGH); //obtenemos el ancho del pulso
  tD = pulseIn(EchoD, HIGH); //obtenemos el ancho del pulso
  tR = pulseIn(EchoR, HIGH); //obtenemos el ancho del pulso

  // dF = tF/59;             //escalamos el tiempo a una distancia en cm
  dD = tD/59;             //escalamos el tiempo a una distancia en cm
  dR = tR/59;             //escalamos el tiempo a una distancia en cm
  
  // Serial.print("Distancia de Frente: ");
  // Serial.print(dF);      //Enviamos serialmente el valor de la distancia
  // Serial.print("cm");
  // Serial.println();
  Serial.print("Distancia de Derecha: ");
  Serial.print(dD);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  Serial.print("Distancia de Izquierda: ");
  Serial.print(dR);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  
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