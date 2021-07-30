#define r1 8
const int echo = 12;
const int trig = 11;
const int ledpin1 = 5;
const int ledpin2 = 4;
const int ledpin3 = 3;
const int buzzer = 2;

//devinisi 

long duration;
int distance;
int savetyDistance;

void setup() {
  pinMode (echo,INPUT);
  pinMode (trig,OUTPUT);
  pinMode (ledpin1,OUTPUT);
  pinMode (ledpin2,OUTPUT);
  pinMode (ledpin3,OUTPUT);
  pinMode (r1,OUTPUT);
  pinMode (buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //buat penyasuaian sensor;
  digitalWrite (trig,LOW);
  delayMicroseconds (2);
  //buat atur nyala matinya sensor;
  digitalWrite (trig,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig,LOW);
  //NGATUR SI ECHO
  duration = pulseIn (echo,HIGH);
  //PEMBACAAN SENSOR;
  distance = duration *0.34/2;

  savetyDistance = distance;
  if (savetyDistance <=300){
    digitalWrite (r1,LOW);
    digitalWrite (ledpin1,HIGH);
  }else{
    digitalWrite (r1,HIGH);
    digitalWrite (ledpin1,LOW);
  }
  if (savetyDistance <=200){
    digitalWrite (ledpin1,HIGH);
    digitalWrite (ledpin2,HIGH);
  }else{
    digitalWrite (ledpin2,LOW);
  }
  if (savetyDistance <=100){
    digitalWrite (buzzer,HIGH);
    digitalWrite (ledpin1,HIGH);
    digitalWrite (ledpin2,HIGH);
    digitalWrite (ledpin3,HIGH);
  }else{
    digitalWrite (ledpin3,LOW);
    digitalWrite (buzzer,LOW);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
}
