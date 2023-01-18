// Sensor ultraSonico
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el echo del sensor

long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros

//Motores
int mA =11;
int mA1=10;
int mB=9;
int mB1=8;


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0

// Inicializamos el motor derecho
  pinMode(mA, OUTPUT);
  pinMode(mA1, OUTPUT);
//Inicializamos el motor izquierdo
  pinMode(mB, OUTPUT);
  pinMode(mB1, OUTPUT);
}
 
void loop() {

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
 d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  
  front();
  delay(3000);
  back();
  delay(3000);
  
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