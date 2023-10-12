#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define SensorSalida 8

int Pin_boto=12;
int Pin_lectura;

float Segons=0;
int Minuts=0;
int Hores=0;

int Actual=0;
int Anterior=1;

int Rojo_Freq=0;
int Azul_Freq=0;
int Verde_Freq=0;
int pos = 0;  

int Canvi=0;
void setup() {
  pinMode (S0, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (S2, OUTPUT);
  pinMode (S3, OUTPUT);
  pinMode (SensorSalida, INPUT);
  pinMode (9, OUTPUT);
  pinMode(Pin_boto, INPUT);
  digitalWrite(S0, LOW);
  digitalWrite(S1,HIGH);
  Serial.begin (9600);}

  

void loop() {
  unsigned long Temps=millis();
  //mins ();
  //ROTACIÓ SERVO
  analogWrite (9,90);
  temps();}


  


void temps() {

  digitalWrite (S2, LOW);
  digitalWrite (S3, LOW);
  Rojo_Freq=pulseIn(SensorSalida,LOW);
    


  digitalWrite (S2, HIGH);
  digitalWrite (S3, HIGH);
  Verde_Freq=pulseIn(SensorSalida,LOW);


  digitalWrite (S2, LOW);
  digitalWrite (S3, HIGH);
  Azul_Freq=pulseIn(SensorSalida,LOW);

  //Serial.print(Rojo_Freq);
  //Serial.print(",");
  //Serial.print(Verde_Freq);
  //Serial.print(",");
  //Serial.println(Azul_Freq);

    
  if (0 <= Rojo_Freq && Rojo_Freq <= 20 && 0 < Verde_Freq && Verde_Freq < 20 && 0 < Azul_Freq && Azul_Freq < 20) {
    Actual=0;
    if (Actual==0 && Anterior==0){
      Canvi+=1;
      //A:
      //Segons+=x;
      //B:
      //Segons+=y;      
      Anterior=1;}
    }

  if (28<= Rojo_Freq && Rojo_Freq <= 80 && 28 < Verde_Freq && Verde_Freq < 90 && 28< Azul_Freq && Azul_Freq < 70) {
    Actual=1;
    if (Actual==1 && Anterior==1){
      Canvi+=1;
      //A:
      //Segons+=x;
      //B:
      //Segons+=y;
      Anterior=0;}
    }
  if (Segons >= 60) {
    Minuts+=1;
    Segons-=60;}

  if (Minuts == 60){
    Hores+=1;
    Minuts-=60;}
    
  int Boto_lectura= digitalRead(Pin_boto);
  if(Boto_lectura == 0){
    Serial.print ("Han passat: ");
    Serial.print (Hores);
    Serial.print (" hores ");

    Serial.print (Minuts);
    Serial.print (" minuts y ");
    Serial.print ("Han passat: ");

    Serial.print (Segons);
    Serial.print (" segons des de l'inici del gir. ");
    Serial.println (" ");
  }}
