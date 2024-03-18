#include <Servo.h> 

 int AIA = 3; //Define pin number for motor
 int AIB = 5; //Define pin number for motor
 int BIA = 6; //Define pin number for motor
 int BIB = 9; //Define pin number for motor

 int R = A5; //Line Sensor Right
 int M = A4; //Line Sensor Middle
 int L = A3; //Line Sensor Left

 int overtakeVar=0;

 int FD = A0; //Distance sensor front
 int MD = A1; //Distance sensor middle
 int BD = A2; //Distance sensor back

const int GROUND_COLOR = 100; // threshold for line sensor

int frontD = 0;

//int Vehicle_Direction = 1;

int z=0; //value for loop increment for steering
int VAL = 0; //received value from bluetooth converted to int
//int i;
int ignore = 0;
int angle=0;
int FromSerial; //received value from bluetooth
int servo_initial_position = 80; //initial position for servo from steering
Servo servo_direction; //define servomotor
int follow = 0;

void setup() {
  
Serial.begin(9600); //initialize comunication with arduino board
servo_direction.attach(10); //define pin number for servomotor / need to be a pwm pin
servo_direction.write(servo_initial_position); //set direction in initial position

 pinMode(FD, INPUT); //Configure the specified pin to behave as an input
 pinMode(MD, INPUT); //Configure the specified pin to behave as an input
 pinMode(BD, INPUT); //Configure the specified pin to behave as an input

 pinMode(R, INPUT); //Configure the specified pin to behave as an input
 pinMode(M, INPUT); //Configure the specified pin to behave as an input
 pinMode(L, INPUT); //Configure the specified pin to behave as an input

 pinMode(AIA, OUTPUT); //Configure the specified pin to behave as an output
 pinMode(AIB, OUTPUT); //Configure the specified pin to behave as an output
 pinMode(BIA, OUTPUT); //Configure the specified pin to behave as an output
 pinMode(BIB, OUTPUT); //Configure the specified pin to behave as an output
 
delay(2000); // delay time for a secure initialisation
}


void loop()
{

//Serial.print("Fata ");
//Serial.println(analogRead(FD));
//Serial.print(" Mijloc ");
//Serial.println(analogRead(MD));
//Serial.print(" Spate ");
//Serial.print(analogRead(BD));
//Serial.print(" Stanga ");
//Serial.println(analogRead(L));
//Serial.print(" Mijloc ");
//Serial.println(analogRead(M));
//Serial.print(" Dreapta ");
//Serial.println(analogRead(R));

/*if(Serial.available()) //Take the received value from serial in "VAL"
  {  
    FromSerial=Serial.read();
    if ( (FromSerial!=35) &&  (FromSerial!=98) &&  (FromSerial!=61))
    {
      VAL = FromSerial;
    Serial.println(FD);
    }
  }*/
/*
//emergency braking 
    if(analogRead(FD)>430)
    VAL=48;
  */
 /* //cruise control
  if(analogRead(FD)<430 && analogRead(FD)>325)
  VAL=49;
*/
  /*
  //obstacle avoidance
    if(analogRead(FD)>430)
      VAL=10; */ 
/*
//parcare laterala
  if(analogRead(MD)<500)
    VAL=11;
*/

//lane keep assist
if(analogRead(M)>400 || analogRead(R)>400 || analogRead(L)>400)
VAL=12;


switch(VAL) //Drive by phone
  {
    /*case 10: //obstacle avoidance
   {
     if(overtakeVar==0)
     {
      //servo_direction.write(64);
      //delay(1000);
      //Forward();
      //delay(350);
      //Stop();
      //delay(5);
     Backward();
     delay(1250);
     Stop();
     delay(5);
     

      for(angle=0;angle<110;angle++)
      {
        Left();
        delay(10);
      }
      Forward();
      delay(1750);
      Stop();
      delay(5);
      for(angle=0;angle<185;angle++)
      {
        Right();
        delay(10);
      }
       Forward();
      delay(1200);
      Stop();
      delay(5);
    Forward();
    delay(150);
    Stop();
    delay(5);

for(angle=0;angle<90;angle++)
      {
        Left();
        delay(10);
      }
      Stop();
      delay(5);

    for(angle=0;angle<110;angle++)
      {
        Right();
        delay(10);
      }
       Forward();
      delay(1000);  
      Stop();
      delay(5);

      Forward();
      delay(1500);  
      Stop();
      delay(5);
      
      for(angle=0;angle<180;angle++)
      {
        Left();
        delay(10);
      }
      Forward();
      delay(1750);
      Stop();
      delay(5);
  for(angle=0;angle<70;angle++)
      {
        Right();
        delay(10);
      }

     Forward();
      delay(1250);
      Stop();
      delay(5);
      delay(5000);
     }
     overtakeVar=1;
      break;

   }
  */
  /*
  case 11: // parcare laterala
{
  if(overtakeVar==0)
  {
    Stop();
    delay(500);

    for(angle=0;angle<70;angle++)
      {
        Left();
        delay(10);
      }
      Stop();
      delay(5);

    Forward();
    delay(3200);
    Stop();
    delay(5);
    for(angle=0;angle<200;angle++)
      {
        Right();
        delay(10);
      }
      Stop();
      delay(5);

      Backward();
      delay(770);
      Stop();
      delay(5);    
    for(angle=0;angle<45;angle++)
      {
        Left();
        delay(10);
      }
    Stop();
      delay(5);

     Backward();
      delay(800);
      Stop();
      delay(5);

    for(angle=0;angle<220;angle++)
      {
        Left();
        delay(10);
      }
      Stop();
      delay(5);

      Backward();
      delay(1150);
      Stop();
      delay(5);

    for(angle=0;angle<240;angle++)
      {
        Right();
        delay(10);
      }
    Stop();
      delay(5);

    Forward();
      delay(1100);
      Stop();
      delay(5);

for(angle=0;angle<90;angle++)
      {
        Left();
        delay(10);
      }
    Stop();
      delay(5);

    Backward();
      delay(500);
      Stop();
      delay(5);
  overtakeVar=1;
  }
  
  break;
}
*/
case 12: //lane keep assist fata
{
  Forward();
  if(analogRead(M)>400){
  servo_direction.write(80);
  servo_direction.write(80);
  Forward();delay(200);
  }
    if(analogRead(L)>400){
  servo_direction.write(64);
  servo_direction.write(64);
  Forward();delay(200);
  }

  if(analogRead(R)>400){
  servo_direction.write(104);
  servo_direction.write(104);
  Forward();delay(200);
  }
  if(analogRead(L)>700 && analogRead(M)>700 && analogRead(R)>700)
  Stop();

  break;
}


  case 49:// Front
    {    
      Forward();
      break;
    }
  case 50:// Backward
    {
      Backward();
      break;
    }
  case 51: // Left
    {
      Hard_Left();
      break;
    }
  case 52: // Right
    {
      Hard_Right();
      break;
    }
  case 55:
    {
      //Line_Follow();
      break;
    } 
  case 48:
    {
      Stop();
      break;
    }
  case 0:
    {
      Stop();
      break;
    }
  }
}
void Forward()
{
analogWrite(AIA, 255);
analogWrite(AIB, 0);
analogWrite(BIA, 255);
analogWrite(BIB, 0);
}

void Backward()
{
analogWrite(AIA, 0);
analogWrite(AIB, 255);
analogWrite(BIA, 0);
analogWrite(BIB, 255);
}

void Stop()
{
 analogWrite(AIA, 0);
 analogWrite(AIB, 0);
 analogWrite(BIA, 0);
 analogWrite(BIB, 0);
}

void Left()
{
//Serial.println(z);
z++;
if(z>7)
  {
    z=0;
    servo_direction.write(servo_initial_position --);
  if (servo_initial_position <= 64)
    {
    servo_initial_position = 64;
    }
  } 
}
void Hard_Left()
{
//Serial.println(z);
z++;
if(z>7)
  {
    z=0;
    servo_direction.write(servo_initial_position = servo_initial_position - 10);
  if (servo_initial_position <= 70)
    {
    servo_initial_position = 70;
    }
  }
   
}
void Right()
{
//Serial.println(z);
z++;
if(z>7)
  {
    z=0;
    servo_direction.write(servo_initial_position ++);
  if (servo_initial_position >= 104)
    {
    servo_initial_position = 104;
    }
  } 
}
void Hard_Right()
{
//Serial.println(z);
z++;
if(z>7)
  {
    z=0;
    servo_direction.write(servo_initial_position  = servo_initial_position + 10 );
  if (servo_initial_position >= 100)
    {
    servo_initial_position = 100;
    }
  } 
}
