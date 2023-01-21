#define in1 A0 //L298n Motor Driver pins.
#define in2 A1
#define in3 A2
#define in4 A3


//IR PINS
int front_left = 3;
int front_right = 4;
int back = 5;

int wheel_speed = 128;


int d=1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(front_left, INPUT);
  pinMode(front_right, INPUT);
  pinMode(back, INPUT);
  Serial.begin(9600);
}

void loop() {
  forward();
  int IR[3];

  //CALL IR FUNCTION
  read_IR_data(IR);


  //PRINT IR DATA
  Serial.print(IR[0]);
  Serial.print(" ");
  Serial.print(IR[1]);
  Serial.print(" ");
  Serial.println(IR[2]);

  if(!IR[0]){
    backward();
    delay(1000);
    right();
  }
  if(!IR[1]){
    backward();
    delay(1000);
    left();
  }
  if(!IR[2]){
    forward();
  }

  
  // put your main code here, to run repeatedly:
//  delay(5*d);
//  forward();
//  delay(d);
//  left();
//  delay(d);
//  backward();
//  delay(d);
//  right();
//  delay(d);
//  stop();

}

void read_IR_data(int *ir){
  ir[0] = digitalRead(front_left);
  ir[1] = digitalRead(front_right);
  ir[2] = digitalRead(back);
  delay(1);
  return;
}

void stop(){
  analogWrite(in1,120);
  analogWrite(in2,120);
  analogWrite(in3,120);
  analogWrite(in4,120);
}

void forward(){
  analogWrite(in1,wheel_speed);
  analogWrite(in2,120);
  analogWrite(in3,120);
  analogWrite(in4,wheel_speed);
}

void backward(){
  analogWrite(in1,120);
  analogWrite(in2,wheel_speed);
  analogWrite(in3,wheel_speed);
  analogWrite(in4,120);
}

void left(){
  analogWrite(in1,120);
  analogWrite(in2,120);
  analogWrite(in3,120);
  analogWrite(in4,wheel_speed);
  delay(0.5*d);
  forward();
}

void right(){
  analogWrite(in1,wheel_speed);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0);
  delay(0.5*d);
  forward();
}
