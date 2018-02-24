#include <Servo.h>
//Servo Variables
Servo thr;
Servo pitch;
Servo roll;
Servo yaw;

//output pins//

/*Match pins on the Arduino to corresponding signal on Flight controller*/
int t = 11; 
int p = 10; 
int r = 9; 
int y = 6; 


int _HIGHP = 1800; //High-point//
int _MINP = 989;  //Min-point//
int _MIDP = 1500; //Mid-point//

int _INC = 20; //increment//

void setup() {
  //set up Servos//
  thr.attach(t);
  pitch.attach(p);
  roll.attach(r);
  yaw.attach(y);

  //set up default midpoints//
  //thr.writeMicroseconds();
  pitch.writeMicroseconds(_MIDP);
  roll.writeMicroseconds(_MIDP);
  yaw.writeMicroseconds(_MIDP);
}

void loop() {

// Servo value tests
 thr_test();
 pitch_test(); 
 roll_test();
 yaw_test();
}

//Throtle value test-----------------------------------------
 void thr_test()
 {
   //initialize and set value to current throttle servo value
   int c_thr = thr.readMicroseconds(); 

   //increment value for the throttle servo
   while(c_thr <= _HIGHP)
   {
      thr.writeMicroseconds(c_thr + _INC);    //write previous value +_INC to thr servo
      delay(100);                             //creates small delay .1 sec
      c_thr = thr.readMicroseconds();         //set the c_thr to new throtle value
   }

   //decrement value for throttle servo
  while(c_thr >= _MINP)
   {
      thr.writeMicroseconds(c_thr - _INC);    //write previous value -_INC to thr servo
      delay(100);
      c_thr = thr.readMicroseconds();
   }
   
 }

/*Code for the rest of the tests follow the same structure */

 //Pitch Value test------------------------------------------
 void pitch_test()
 {
   int c_pitch = pitch.readMicroseconds();
   while(c_pitch <= _HIGHP)
   {
      pitch.writeMicroseconds(c_pitch + _INC);
      delay(100);
      c_pitch = pitch.readMicroseconds();
   }
  while(c_pitch >= _MINP)
   {
      pitch.writeMicroseconds(c_pitch - _INC);
      delay(100);
      c_pitch = pitch.readMicroseconds();
   }
   
 }

//Roll Value Test-------------------------------------------
 void roll_test()
 {
   int c_roll= roll.readMicroseconds();
   while(c_roll <= _HIGHP)
   {
      roll.writeMicroseconds(c_roll + _INC);
      delay(100);
      c_roll = roll.readMicroseconds();
   }
  while(c_roll >= _MINP)
   {
      roll.writeMicroseconds(c_roll - _INC);
      delay(100);
      c_roll = roll.readMicroseconds();
   }
   
 }

 //Yaw Value Test -------------------------------------------
 void yaw_test()
 {
   int c_yaw = yaw.readMicroseconds();
   while(c_yaw <= _HIGHP)
   {
      yaw.writeMicroseconds(c_yaw + _INC);
      delay(100);
      c_yaw = yaw.readMicroseconds();
   }
  while(c_yaw >= _MINP)
   {
      yaw.writeMicroseconds(c_yaw - _INC);
      delay(100);
      c_yaw = yaw.readMicroseconds();
   }
   
 }
