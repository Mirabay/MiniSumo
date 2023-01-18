// Inicializamos el motor derecho
int mA =11;
int mA1=10;
//Inicializamos el motor izquierdo
int mB=9;
int mB1=8;

void setup() {
  pinMode(mA, OUTPUT);
  pinMode(mA1, OUTPUT);
  pinMode(mB, OUTPUT);
  pinMode(mB1, OUTPUT);
}
 
void loop() {
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