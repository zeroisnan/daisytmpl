// ----------------------------------------------------------------
// this is the entry point for the program on the Daisy platform
// it is structured such that hardware initialization happens here
// whereas the whole audio processing is contained within audiocore
//
// this enables the reuse of audiocore as the processing kernel
// within rackbench, i.e. we can use VCV Rack to test the behaviour
// of the audio kernel within the comfort of a host platofrm
// ----------------------------------------------------------------

#include "audiocore.h"
#include "daisy_seed.h"

static daisy::DaisySeed hw;

int main(void) {
  // initialize seed hardware and daisysp modules
  float sample_rate;
  hw.Configure();
  hw.Init();
  sample_rate = hw.AudioSampleRate();
  AudioCoreInit(sample_rate);

  // start callback
  hw.StartAudio(AudioCoreKernel);

  while (1) {
  }
}
