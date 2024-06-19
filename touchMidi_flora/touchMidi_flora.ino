#include <CapacitiveSensor.h>

// MIDI note here, change if you like

int note1 = 60;
int note2 = 62;
int note3 = 64;
int note4 = 65;

int intensity = 100;
int led = 7;
int thresh = 500;
#define CHANNEL 1  // MIDI channel number
CapacitiveSensor   cs_0_1 = CapacitiveSensor(0, 1);
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor   cs_9_10 = CapacitiveSensor(9, 10);
CapacitiveSensor   cs_6_12 = CapacitiveSensor(6, 12);

boolean key1;
boolean key2;
boolean key3;
boolean key4;

boolean lastkey1;
boolean lastkey2;
boolean lastkey3;
boolean lastkey4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
 // Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  long total1 =  cs_0_1.capacitiveSensor(30);
  long total2 =  cs_2_3.capacitiveSensor(30);
  long total3 =  cs_9_10.capacitiveSensor(30);
  long total4 =  cs_6_12.capacitiveSensor(30);

//  Serial.print(total1);
//  Serial.print(" ; ");
//   Serial.print(total2);
//   Serial.print(" ; ");
//   Serial.print(total3);
//   Serial.print(" ; ");
//   Serial.println(total4);


  if (total1 > thresh) {
    key1 = true;
  }
  else {
    key1 = false;
  }
  if (total2 > thresh) {
    key2 = true;
  }
  else {
    key2 = false;
  }
  if (total3 > thresh) {
    key3 = true;
  }
  else {
    key3 = false;
  }
  if (total4 > thresh) {
    key4 = true;
  }
  else {
    key4 = false;
  }

  if (key1 != lastkey1) {
    if (key1 == true) {
      usbMIDI.sendNoteOn(note1, intensity, CHANNEL);
      digitalWrite(led, HIGH);
    }
    if (key1 == false) {
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      usbMIDI.sendNoteOff(note1, 0, CHANNEL);
    }
  }
    if (key2 != lastkey2) {
    if (key2 == true) {
     usbMIDI.sendNoteOn(note2, intensity, CHANNEL);
      digitalWrite(led, HIGH);
    }
    if (key2 == false) {
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      usbMIDI.sendNoteOff(note2, 0, CHANNEL);
    }
  }
    if (key3 != lastkey3) {
    if (key3 == true) {
      usbMIDI.sendNoteOn(note3, intensity, CHANNEL);
      digitalWrite(led, HIGH);
    }
    if (key3 == false) {
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
     usbMIDI.sendNoteOff(note3, 0, CHANNEL);
    }
  }
    if (key4 != lastkey4) {
    if (key4 == true) {
      usbMIDI.sendNoteOn(note4, intensity, CHANNEL);
      digitalWrite(led, HIGH);
    }
    if (key4 == false) {
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      usbMIDI.sendNoteOff(note4, 0, CHANNEL);
    }
  }

  lastkey1 = key1;
  lastkey2 = key2;
  lastkey3 = key3;
  lastkey4 = key4;
  delay(10);
}
