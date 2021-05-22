int button = 8; //button pin is put to the 8th PIN of the Arduino Board

const int in1=3; //first motor first pin
const int in2=5; //first motor second pin
const int in3=6; //second motor first pin
const int in4=9; //second motor second pin
const int ena=10; //first motor enable pin
const int enb=11; //second motor enable pin

int ctr=0;

void setup()
{
  Serial.begin(9600);
  pinMode(in1,OUTPUT);  
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ena,OUTPUT);
  analogWrite(ena,255);
  pinMode(enb,OUTPUT);
  analogWrite(enb,255);

  pinMode(button,INPUT);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  /*pinMode(button,INPUT);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);*/
}
void loop()
{
  int k=digitalRead(button); //reading the input of the button if pushed
  if(k==LOW) 
  {
    Serial.println('1'); //printing 1 on the serial pointer in a new line
    if(ctr%2==0)
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in3,HIGH);
      delay(5000);
    }
    else if(ctr%2!=0)
    {
      digitalWrite(in1,LOW);
      digitalWrite(in3,LOW);
      delay(5000);
    }
    ctr=ctr+1;
  }
  delay(5000);
}
