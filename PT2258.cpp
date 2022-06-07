/*
Author: jehongjeon27
version: 1.0
*/

#include "PT2258.h"
#include "Arduino.h"

//instructions
#define EVC_VOL_1     0b11100000  //All-Channel, -1dB/step
#define EVC_VOL_10    0b11010000  //All-Channel, -10dB/step

#define EVC_1CH_1     0b10010000  //1Channel, -1dB/step
#define EVC_1CH_10    0b10000000  //1Channel, -10dB/step
#define EVC_2CH_1     0b01010000  //2Channel, -1dB/step
#define EVC_2CH_10    0b01000000  //2Channel, -10dB/step

#define EVC_3CH_1     0b00010000  //3Channel, -1dB/step
#define EVC_3CH_10    0b00000000  //3Channel, -10dB/step
#define EVC_4CH_1     0b00110000  //4Channel, -1dB/step
#define EVC_4CH_10    0b00100000  //4Channel, -10dB/step

#define EVC_5CH_1     0b01110000  //5Channel, -1dB/step
#define EVC_5CH_10    0b01100000  //5Channel, -10dB/step
#define EVC_6CH_1     0b10110000  //6Channel, -1dB/step
#define EVC_6CH_10    0b10100000  //6Channel, -10dB/step

#define EVC_MUTE      0b11111000  //All-Channel MUTE

//Constructor
PT2258::PT2258(uint8_t address) {
  _address = address;
  _volume_1 = 79;
  _volume_2 = 79;
  _volume_3 = 79;
  _volume_4 = 79;
  _volume_5 = 79;
  _volume_6 = 79;
  _muteState = false;
}

void PT2258::init() {
  delay(200);
  Wire.begin();
}

void PT2258::setAddress(uint8_t address) {
  _address = address;
}

void PT2258::setVolume_All(uint8_t volume) {
  if (volume > 80)
    volume = 79;
  
  _volume_1 = volume;
  _volume_2 = volume;
  _volume_3 = volume;
  _volume_4 = volume;
  _volume_5 = volume;
  _volume_6 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_VOL_10 | (volume / 10));
  Wire.write(EVC_VOL_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_1ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_1 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_1CH_10 | (volume / 10));
  Wire.write(EVC_1CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_2ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_2 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_2CH_10 | (volume / 10));
  Wire.write(EVC_2CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_3ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_3 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_3CH_10 | (volume / 10));
  Wire.write(EVC_3CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_4ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_4 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_4CH_10 | (volume / 10));
  Wire.write(EVC_4CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_5ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_5 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_5CH_10 | (volume / 10));
  Wire.write(EVC_5CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setVolume_6ch(uint8_t volume) {
  if (volume > 80)
    volume = 79;
    
  _volume_6 = volume;

  Wire.beginTransmission(_address);
  Wire.write(EVC_6CH_10 | (volume / 10));
  Wire.write(EVC_6CH_1 | (volume % 10));
  Wire.endTransmission();
}

void PT2258::setMuteState(bool mute) {
  _muteState = mute;

  Wire.beginTransmission(_address);
  Wire.write(EVC_MUTE | mute);
  Wire.endTransmission();
}

uint8_t PT2258::getAddress() {
  return _address;
}

uint8_t PT2258::getVolume_1ch() {
    return _volume_1;
}

uint8_t PT2258::getVolume_2ch() {
    return _volume_2;
}

uint8_t PT2258::getVolume_3ch() {
    return _volume_3;
}

uint8_t PT2258::getVolume_4ch() {
    return _volume_4;
}

uint8_t PT2258::getVolume_5ch() {
    return _volume_5;
}

uint8_t PT2258::getVolume_6ch() {
    return _volume_6;
}

bool PT2258::getMuteState() {
    return _muteState;
}
