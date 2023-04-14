#include <FastTouch.h>

// MIDI note here, change if you like
int note1 = 60;

// variables
int val1;
boolean key1;
boolean lastKey1;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
val1 = fastTouchRead(5);

lastKey1 = key1;
  if (val1 > 10) {
    key1 = true;
  }
  else {
    key1 = false;
  }

    if (key1 != lastkey1) {
    if (key1 == true) {
      usbMIDI.sendNoteOn(note1, 99, channel);
    }
    if (key1 == false) {
      usbMIDI.sendNoteOn(note1, 0, channel);
    }
  }
}
