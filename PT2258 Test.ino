#include "PT2258.h"

/* Check your PT2258 I2C Address with I2C Scanner Example code
PT2258 Address Code depends on the state of CODE1 and CODE2

CODE1 = LOW  | CODE2 = LOW    =>    0x40
CODE1 = LOW  | CODE2 = HIGH   =>    0x42
CODE1 = HIGH | CODE2 = LOW    =>    0x44
CODE1 = HIGH | CODE2 = HIGH   =>    0x46
*/

// Support multiple PT2258 with different I2C Addresses
PT2258 PT2258_L(0x44);
PT2258 PT2258_R(0x46);

void setup() {
  Serial.begin(9600);
  // Initialize PT2258 Class before use
  PT2258_L.init();
  PT2258_R.init();
  delay(1000);
}

void loop() {
  //This is an Example how to use PT2258 Library
  // range from 0 to 79 (-0dB ~ -79dB)
  // Channel 1 to channel 6, support volume set for all channel at once
  
  
  // Set volume of Left 1ch to -0dB
  PT2258_L.setVolume_1ch(0);
  // Set volume of Right 2ch to -0dB
  PT2258_R.setVolume_2ch(0);
  // Set volume of Left 5ch to -79dB
  PT2258_L.setVolume_5ch(79);
  // Set volume of Right 6ch to -79dB
  PT2258_R.setVolume_6ch(79);
  
  // Set all channel volume to -50dB
  PT2258_L.setVolume_All(50)
  // Get volume of Left 3ch
  int vol = PT2258_L.getVolume_3ch();
  
  // Set mute of Left all channel
  PT2258_L.setMuteState(True);
  

  while(True) {}
}
