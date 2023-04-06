#include <FastTouch.h>

// MIDI note here, change if you like

int note1 = 60;
int note2 = 62;
int note3 = 64;
int note4 = 65;
int note5 = 67;
int note6 = 69;
int note7 = 71;
int note8 = 72;

//-------------------

int val1;
int val2;
int val3;
int val4;
int val5;
int val6;
int val7;
int val8;

int initval1;
int initval2;
int initval3;
int initval4;
int initval5;
int initval6;
int initval7;
int initval8;

int avg1;
int avg2;
int avg3;
int avg4;
int avg5;
int avg6;
int avg7;
int avg8;

int samplesize = 5; // how much samples to take avarage, change if needed
int thresh = 5; // threshold to trigger MIDI notes, change if needed

boolean key1;
boolean key2;
boolean key3;
boolean key4;
boolean key5;
boolean key6;
boolean key7;
boolean key8;

boolean lastkey1;
boolean lastkey2;
boolean lastkey3;
boolean lastkey4;
boolean lastkey5;
boolean lastkey6;
boolean lastkey7;
boolean lastkey8;

//the MIDI channel number to send messages
const int channel = 1;

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(9600);
  allNotesZero();
  delay(100);
  initval1 = fastTouchRead(5);
  initval2 = fastTouchRead(7);
  initval3 = fastTouchRead(9);
  initval4 = fastTouchRead(11);
  initval5 = fastTouchRead(14);
  initval6 = fastTouchRead(16);
  initval7 = fastTouchRead(18);
  initval8 = fastTouchRead(20);
  delay(100);
  pinMode(13, OUTPUT);
}

void loop() {
  // read touch sensor pins, pins are for TeensyLC touch pins
  val1 = fastTouchRead(5);
  val2 = fastTouchRead(7);
  val3 = fastTouchRead(9);
  val4 = fastTouchRead(11);
  val5 = fastTouchRead(14);
  val6 = fastTouchRead(16);
  val7 = fastTouchRead(18);
  val8 = fastTouchRead(20);


  // take avarage to create smoother sensor value
  // if you want to change the sample size of the avaraging, change samplesize at the begining of this code
  avg1 = (avg1 * (samplesize - 1) + val1) / samplesize;
  avg2 = (avg2 * (samplesize - 1) + val2) / samplesize;
  avg3 = (avg3 * (samplesize - 1) + val3) / samplesize;
  avg4 = (avg4 * (samplesize - 1) + val4) / samplesize;
  avg5 = (avg5 * (samplesize - 1) + val5) / samplesize;
  avg6 = (avg6 * (samplesize - 1) + val6) / samplesize;
  avg7 = (avg7 * (samplesize - 1) + val7) / samplesize;
  avg8 = (avg8 * (samplesize - 1) + val8) / samplesize;

  // store the previous value to compare
  storeLastKeyState();

  if (avg1 > initval1+thresh) {key1 = true;} 
  else {key1 = false;}
  if (avg2 > initval2+thresh) {key2 = true;} 
  else {key2 = false;}
  if (avg3 > initval3+thresh) {key3 = true;} 
  else {key3 = false;}
  if (avg4 > initval4+thresh) {key4 = true;} 
  else {key4 = false;}
  if (avg5 > initval5+thresh) {key5 = true;} 
  else {key5 = false;}
  if (avg6 > initval6+thresh) {key6 = true;} 
  else {key6 = false;}
  if (avg7 > initval7+thresh) {key7 = true;} 
  else {key7 = false;}
  if (avg8 > initval8+thresh) {key8 = true;} 
  else {key8 = false;}


  if (key1 != lastkey1) {
    if (key1 == true) {
      usbMIDI.sendNoteOn(note1, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key1 == false) {
      usbMIDI.sendNoteOn(note1, 0, channel);
      digitalWrite(13,LOW);
    }
  }

  if (key2 != lastkey2) {
    if (key2 == true) {
      usbMIDI.sendNoteOn(note2, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key2 == false) {
      usbMIDI.sendNoteOn(note2, 0, channel);
      digitalWrite(13,LOW);
    }
  }

  if (key3 != lastkey3) {
    if (key3 == true) {
      usbMIDI.sendNoteOn(note3, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key3 == false) {
      usbMIDI.sendNoteOn(note3, 0, channel);
      digitalWrite(13,LOW);
    }
  }
  if (key4 != lastkey4) {
    if (key4 == true) {
      usbMIDI.sendNoteOn(note4, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key4 == false) {
      usbMIDI.sendNoteOn(note4, 0, channel);
      digitalWrite(13,LOW);
    }
  }
  if (key5 != lastkey5) {
    if (key5 == true) {
      usbMIDI.sendNoteOn(note5, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key5 == false) {
      usbMIDI.sendNoteOn(note5, 0, channel);
      digitalWrite(13,LOW);
    }
  }
  if (key6 != lastkey6) {
    if (key6 == true) {
      usbMIDI.sendNoteOn(note6, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key6 == false) {
      usbMIDI.sendNoteOn(note6, 0, channel);
      digitalWrite(13,LOW);
    }
  }
  if (key7 != lastkey7) {
    if (key7 == true) {
      usbMIDI.sendNoteOn(note7, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key7 == false) {
      usbMIDI.sendNoteOn(note7, 0, channel);
      digitalWrite(13,LOW);
    }
  }
  if (key8 != lastkey8) {
    if (key8 == true) {
      usbMIDI.sendNoteOn(note8, 99, channel);
      digitalWrite(13,HIGH);
    }
    if (key8 == false) {
      usbMIDI.sendNoteOn(note8, 0, channel);
      digitalWrite(13,LOW);
    }
  }



   // print sensor values
  printSensorVal();
  delay(10);

}

void storeLastKeyState() {
  // store the previous value to compare
  lastkey1 = key1;
  lastkey2 = key2;
  lastkey3 = key3;
  lastkey4 = key4;
  lastkey5 = key5;
  lastkey6 = key6;
  lastkey7 = key7;
  lastkey8 = key8;
  
}

void printSensorVal(){
  SerialUSB.print(avg1);
  SerialUSB.print(" ");
  SerialUSB.print(avg2);
  SerialUSB.print(" ");
  SerialUSB.print(avg3);
  SerialUSB.print(" ");
  SerialUSB.print(avg4);
  SerialUSB.print(" ");
  SerialUSB.print(avg5);
  SerialUSB.print(" ");
  SerialUSB.print(avg6);
  SerialUSB.print(" ");
  SerialUSB.print(avg7);
  SerialUSB.print(" ");
  SerialUSB.print(avg8);
  SerialUSB.println();
  
}

void allNotesZero(){
  usbMIDI.sendNoteOn(note1, 0, channel);
  usbMIDI.sendNoteOn(note2, 0, channel);
  usbMIDI.sendNoteOn(note3, 0, channel);
  usbMIDI.sendNoteOn(note4, 0, channel);
  usbMIDI.sendNoteOn(note5, 0, channel);
  usbMIDI.sendNoteOn(note6, 0, channel);
  usbMIDI.sendNoteOn(note7, 0, channel);
  usbMIDI.sendNoteOn(note8, 0, channel);

}
