#include <Arduino.h>
#include "MIDIUSB.h"
#include <Encoder.h>
#include "Keyboard.h"

// PINOUT
// MUX
// Outputs
int muxChannel1 = 10;
int muxChannel2 = 9;
int muxChannel3 = 8;
int muxChannel4 = 7;

// Inputs
const int muxPotInputs[4] = {A1, A2, A3, A4};
int muxSwitchesInput1 = 12; // 16 channel analog
int muxSwitchesInput2 = 11; // 16 channel analog
int muxSwitchesInput3 = 6;  // 16 channel analog
int muxSwitchesInput4 = 5;  // 16 channel analog

// MULTIPLEXER BUTTONS - 16 CH EACH
const int NUMBER_MUX_BUTTONS = 16;
bool muxButtonsCurrentState[4][NUMBER_MUX_BUTTONS] = {0};
bool muxButtonsPreviousState[4][NUMBER_MUX_BUTTONS] = {0};

unsigned long lastDebounceTimeMUX[4][NUMBER_MUX_BUTTONS] = {0};
unsigned long debounceDelayMUX = 5;

// Configure multiplexer output pins
void setup() {
  pinMode(muxChannel1, OUTPUT);
  pinMode(muxChannel2, OUTPUT);
  pinMode(muxChannel3, OUTPUT);
  pinMode(muxChannel4, OUTPUT);
  digitalWrite(muxChannel1, LOW);
  digitalWrite(muxChannel2, LOW);
  digitalWrite(muxChannel3, LOW);
  digitalWrite(muxChannel4, LOW);

  pinMode(muxSwitchesInput1, INPUT);
  pinMode(muxSwitchesInput2, INPUT);
  pinMode(muxSwitchesInput3, INPUT);
  pinMode(muxSwitchesInput4, INPUT);
}

void loop() {
  updateMUXButtons(0, muxSwitchesInput1);
  updateMUXButtons(1, muxSwitchesInput2);
  updateMUXButtons(2, muxSwitchesInput3);
  updateMUXButtons(3, muxSwitchesInput4);
  updatePots();
}

void updateMUXButtons(int muxIndex, int inputPin) {
  for (int i = 0; i < NUMBER_MUX_BUTTONS; i++) {
    int A = bitRead(i, 0);
    int B = bitRead(i, 1);
    int C = bitRead(i, 2);
    int D = bitRead(i, 3);
    digitalWrite(muxChannel1, A);
    digitalWrite(muxChannel2, B);
    digitalWrite(muxChannel3, C);
    digitalWrite(muxChannel4, D);
    delay(1);
    muxButtonsCurrentState[muxIndex][i] = digitalRead(inputPin);

    if ((millis() - lastDebounceTimeMUX[muxIndex][i]) > debounceDelayMUX) {
      if (muxButtonsCurrentState[muxIndex][i] != muxButtonsPreviousState[muxIndex][i]) {
        lastDebounceTimeMUX[muxIndex][i] = millis();
        pressButton(muxIndex + 1, i, muxButtonsCurrentState[muxIndex][i] == LOW ? 0 : 1);
        muxButtonsPreviousState[muxIndex][i] = muxButtonsCurrentState[muxIndex][i];
      }
    }
  }
}

#define NUMBER_POTS 4
int previousPotValues[NUMBER_POTS] = {0};
int previousMidiValues[NUMBER_POTS] = {0};
unsigned long lastDebounceTime[NUMBER_POTS] = {0};
const int varThreshold = 5;

void updatePots() {
  for (int i = 0; i < NUMBER_POTS; i++) {
    int potValue = analogRead(muxPotInputs[i]);
    int midiValue = map(potValue, 0, 1023, 0, 127);

    if (abs(potValue - previousPotValues[i]) > varThreshold) {
      unsigned long currentTime = millis();
      if ((currentTime - lastDebounceTime[i]) > debounceDelayMUX) {
        lastDebounceTime[i] = currentTime;

        if (midiValue != previousMidiValues[i]) {
          Serial.print("Pot ");
          Serial.print(i);
          Serial.print(" Volume: ");
          Serial.println(midiValue);
          midiControlChange(selectedChannel, 7, midiValue);

          previousPotValues[i] = potValue;
          previousMidiValues[i] = midiValue;
        }
      }
    }
  }
}

void midiNoteOn(byte channel, unsigned short note) {
  midiEventPacket_t midiNoteOn = { 0x09, 0x90 | channel, note, 100 };
  MidiUSB.sendMIDI(midiNoteOn);
  MidiUSB.flush();
}

void midiNoteOff(byte channel, unsigned short note) {
  midiEventPacket_t midiNoteOff = { 0x08, 0x80 | channel, note, 0 };
  MidiUSB.sendMIDI(midiNoteOff);
  MidiUSB.flush();  // Ensure the message is sent immediately
}

void midiControlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();  // Ensure the message is sent immediately
}
