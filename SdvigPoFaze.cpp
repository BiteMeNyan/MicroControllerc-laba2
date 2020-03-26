#include <Arduino.h>
#include "TimerThree.h"
#include "Math.h"
#define pi = M_PI;
#define PIN_POT A0;

const int pin [3]={8,9,10};
int uref=5;
int t;
int k;

void fun(){
	t=millis()/double(1000);
	k=analogRead(A0)/4;
	analogWrite(pin[2], uref/(2*(sin(k*t+4*M_PI/3)+1)));
	analogWrite(pin[1], uref/(2*(sin(k*t+2*M_PI/3)+1)));
	analogWrite(pin[0], uref/(2*(sin(k*t)+1)));
	digitalWrite(pin[2],LOW);
}

void setup() {
	for(int i=0;i<3;i++){
	pinMode(pin[i], OUTPUT);
}}



void loop() {
	Timer3.initialize(10000);
	Timer3.attachInterrupt(fun);
for (int i=0;i<3;i++){
	digitalWrite(pin[i],LOW);
}
