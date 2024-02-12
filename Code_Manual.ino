// คุม servo แบบปรับได้ๆ
#include <ESP32_Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;


int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int servo1;
int servo2;
int servo3;
int fo;
int back;
int left;
int right;
int turn_left;
int turn_right;
int y;
int x;
int z;

// DC Motor_Backward_Left
int Motor1_IN1 = 33;
int Motor1_IN2 = 32;
int Motor1_EN1 = 25;
// DC Motor_Forward_Left
int Motor2_IN3 = 18;
int Motor2_IN4 = 19;
int Motor2_EN2 = 5;
// DC Motor_Forward_Right
int Motor3_IN5 = 23;
int Motor3_IN6 = 22;
int Motor3_EN3 = 21;
// DC Motor_Backward_Right
int Motor4_IN7 = 2;
int Motor4_IN8 = 4;
int Motor4_EN4 = 15;

void setup() {
  Serial.begin(115200);

  myservo1.attach(13); 
  myservo2.attach(12);
  myservo3.attach(14);

  pinMode(Motor1_IN1, OUTPUT);
  pinMode(Motor1_IN2, OUTPUT);
  pinMode(Motor1_EN1, OUTPUT);
  pinMode(Motor2_IN3, OUTPUT);
  pinMode(Motor2_IN4, OUTPUT);
  pinMode(Motor2_EN2, OUTPUT);
  pinMode(Motor3_IN5, OUTPUT);
  pinMode(Motor3_IN6, OUTPUT);
  pinMode(Motor3_EN3, OUTPUT);
  pinMode(Motor4_IN7, OUTPUT);
  pinMode(Motor4_IN8, OUTPUT);
  pinMode(Motor4_EN4, OUTPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);

  digitalWrite(Motor1_IN1, LOW);
  digitalWrite(Motor1_IN2, LOW);
  digitalWrite(Motor2_IN3, LOW);
  digitalWrite(Motor2_IN4, LOW);
  digitalWrite(Motor3_IN5, LOW);
  digitalWrite(Motor3_IN6, LOW);
  digitalWrite(Motor4_IN7, LOW);
  digitalWrite(Motor4_IN8, LOW);
  
  myservo1.write(50);
  myservo2.write(0);
  myservo3.write(180);
}

void loop() {
  ch1 = pulseIn(39, HIGH); 
  ch2 = pulseIn(34, HIGH); 
  ch4 = pulseIn(35, HIGH); 
  ch3 = pulseIn(36, HIGH); 
  ch5 = pulseIn(26, HIGH); 
  ch6 = pulseIn(27, HIGH); 

  servo3 = map(ch3, 1010, 1988, 180, 0);
  servo2 = map(ch5, 1000, 2000, 0, 180);
  servo1 = map(ch6, 1000, 2000, 40, 180);

  fo = map(ch2, 1540, 1985, 85, 255);
  back = map(ch2, 1450, 1004, 85, 255);
  right = map(ch1, 1545, 2000, 85, 255);
  left = map(ch1, 1455, 999, 85, 255);
  turn_left = map(ch4, 1454, 999, 85, 255);
  turn_right = map(ch4, 1544, 1995, 85, 255);
  
  myservo1.write(servo1);
  myservo2.write(servo2);
  myservo3.write(servo3);
  
  if(ch2>=1540){
  analogWrite(Motor1_EN1, fo);
  analogWrite(Motor2_EN2, fo);
  analogWrite(Motor3_EN3, fo);
  analogWrite(Motor4_EN4, fo);
  digitalWrite(Motor1_IN1, HIGH);
  digitalWrite(Motor1_IN2, LOW);
  digitalWrite(Motor2_IN3, HIGH);
  digitalWrite(Motor2_IN4, LOW);
  digitalWrite(Motor3_IN5, HIGH);
  digitalWrite(Motor3_IN6, LOW);
  digitalWrite(Motor4_IN7, HIGH);
  digitalWrite(Motor4_IN8, LOW);
  }

  else if(ch2<=1450){
  analogWrite(Motor1_EN1, back);
  analogWrite(Motor2_EN2, back);
  analogWrite(Motor3_EN3, back);
  analogWrite(Motor4_EN4, back);
  digitalWrite(Motor1_IN1, LOW);
  digitalWrite(Motor1_IN2, HIGH);
  digitalWrite(Motor2_IN3, LOW);
  digitalWrite(Motor2_IN4, HIGH);
  digitalWrite(Motor3_IN5, LOW);
  digitalWrite(Motor3_IN6, HIGH);
  digitalWrite(Motor4_IN7, LOW);
  digitalWrite(Motor4_IN8, HIGH);
  }

  else if(ch1>=1545){
  analogWrite(Motor1_EN1, right);
  analogWrite(Motor2_EN2, right);
  analogWrite(Motor3_EN3, right);
  analogWrite(Motor4_EN4, right);
  digitalWrite(Motor1_IN1, LOW);
  digitalWrite(Motor1_IN2, HIGH);
  digitalWrite(Motor2_IN3, HIGH);
  digitalWrite(Motor2_IN4, LOW);
  digitalWrite(Motor3_IN5, LOW);
  digitalWrite(Motor3_IN6, HIGH);
  digitalWrite(Motor4_IN7, HIGH);
  digitalWrite(Motor4_IN8, LOW);
  }

  else if(ch1<=1455){
  analogWrite(Motor1_EN1, left);
  analogWrite(Motor2_EN2, left);
  analogWrite(Motor3_EN3, left);
  analogWrite(Motor4_EN4, left);
  digitalWrite(Motor1_IN1, HIGH);
  digitalWrite(Motor1_IN2, LOW);
  digitalWrite(Motor2_IN3, LOW);
  digitalWrite(Motor2_IN4, HIGH);
  digitalWrite(Motor3_IN5, HIGH);
  digitalWrite(Motor3_IN6, LOW);
  digitalWrite(Motor4_IN7, LOW);
  digitalWrite(Motor4_IN8, HIGH);
  }

  else if(ch4<=1454){
  analogWrite(Motor1_EN1, turn_left);
  analogWrite(Motor2_EN2, turn_left);
  analogWrite(Motor3_EN3, turn_left);
  analogWrite(Motor4_EN4, turn_left);
  digitalWrite(Motor1_IN1, LOW);
  digitalWrite(Motor1_IN2, HIGH);
  digitalWrite(Motor2_IN3, LOW);
  digitalWrite(Motor2_IN4, HIGH);
  digitalWrite(Motor3_IN5, HIGH);
  digitalWrite(Motor3_IN6, LOW);
  digitalWrite(Motor4_IN7, HIGH);
  digitalWrite(Motor4_IN8, LOW);
  }

  else if(ch4>=1544){
  analogWrite(Motor1_EN1, turn_right);
  analogWrite(Motor2_EN2, turn_right);
  analogWrite(Motor3_EN3, turn_right);
  analogWrite(Motor4_EN4, turn_right);
  digitalWrite(Motor1_IN1, HIGH);
  digitalWrite(Motor1_IN2, LOW);
  digitalWrite(Motor2_IN3, HIGH);
  digitalWrite(Motor2_IN4, LOW);
  digitalWrite(Motor3_IN5, LOW);
  digitalWrite(Motor3_IN6, HIGH);
  digitalWrite(Motor4_IN7, LOW);
  digitalWrite(Motor4_IN8, HIGH);
  }
  
  else{
  digitalWrite(Motor1_IN1, LOW);
  digitalWrite(Motor1_IN2, LOW);
  digitalWrite(Motor2_IN3, LOW);
  digitalWrite(Motor2_IN4, LOW);
  digitalWrite(Motor3_IN5, LOW);
  digitalWrite(Motor3_IN6, LOW);
  digitalWrite(Motor4_IN7, LOW);
  digitalWrite(Motor4_IN8, LOW);
  }
}
