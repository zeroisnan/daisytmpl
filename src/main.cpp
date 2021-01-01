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

using namespace daisy;

static DaisySeed seed;

int main(void) {
  // initialize seed hardware and daisysp modules
  float sample_rate;
  seed.Configure();
  seed.Init();
  sample_rate = seed.AudioSampleRate();
  AudioCoreInit(sample_rate);

  // start callback
  seed.StartAudio(AudioCoreKernel);

  while (1) {
  }
}
