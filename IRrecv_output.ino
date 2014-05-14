/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * Johan test 2
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int outPin1 = 4;
int outPin2 = 5;
long compareValue = 0;
long lastValue = 0;
long conRepeatValue = 4294967295;
long conOnOff = 16753245;
int conZero = 1;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Serial.println(results.value);
    Serial.println("----------");

    Serial.println("#");
    Serial.println(results.value + conZero);

    if (results.value == conRepeatValue)
    {
      compareValue = lastValue;
    }
    else
    {
      compareValue = results.value;
      lastValue = results.value;
    }

    if (compareValue == conOnOff)
    {
      digitalWrite(outPin1, HIGH);
      digitalWrite(outPin2, LOW);
    }
    else
    {
      digitalWrite(outPin2, HIGH);
      digitalWrite(outPin1, LOW);
    }

    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
}

/*
FFA25D

16753245

*/
