/*
Author: jehongjeon27
version: 1.0
*/

#ifndef PT2258_h
#define PT2258_h

#include "Arduino.h"
#include <Wire.h>

class PT2258
{
  public:
    PT2258(uint8_t address);
    void init();
    
    void setAddress(uint8_t address);
    void setVolume_All(uint8_t volume);
    void setVolume_1ch(uint8_t volume);
    void setVolume_2ch(uint8_t volume);
    void setVolume_3ch(uint8_t volume);
    void setVolume_4ch(uint8_t volume);
    void setVolume_5ch(uint8_t volume);
    void setVolume_6ch(uint8_t volume);
    void setMuteState(bool mute);

    uint8_t getAddress();
    uint8_t getVolume_1ch();
    uint8_t getVolume_2ch();
    uint8_t getVolume_3ch();
    uint8_t getVolume_4ch();
    uint8_t getVolume_5ch();
    uint8_t getVolume_6ch();
    bool getMuteState();
    
  private:
    uint8_t _address;
    uint8_t _volume_1;
    uint8_t _volume_2;
    uint8_t _volume_3;
    uint8_t _volume_4;
    uint8_t _volume_5;
    uint8_t _volume_6;
    bool _muteState;
};

#endif
