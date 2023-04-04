#include <LGT8F328P.h>
#include <Audio.h> // Library untuk audio

#define SAMPLE_RATE 8000 // Sample rate in Hz
#define BUFFER_SIZE 128  // Size of input and output buffers

AudioInputAnalog adc(A0); // Audio input object for ADC
AudioOutputDAC dac; // Audio output object for DAC
AudioEffectReverb reverb(delayTime, decay); // Audio effect object for reverb
AudioConnection patchCord1(adc, 0, reverb, 0); // Connect ADC to reverb
AudioConnection patchCord2(reverb, 0, dac, 0); // Connect reverb to DAC

float delayTime = 0.5; // Delay time in seconds for reverb effect
float decay = 0.5; // Decay factor for reverb effect

void setup() {
  // Initialize audio
  AudioMemory(BUFFER_SIZE); // Allocate audio memory
  dac.begin(SAMPLE_RATE); // Initialize DAC with sample rate
}

void loop() {
  // Do nothing in loop as audio processing is done in the background
}
