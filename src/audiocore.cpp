// ----------------------------------------------------------------
// audio core implementation
//
// This code is built leveraging the platform independent nature of
// the DaisySP library.
//
// This example is an evolution of the delayline example from the
// DaisyExample github depot
// ----------------------------------------------------------------

#include "audiocore.h"

#include "daisysp.h"

// Set max delay time to -1.75 of samplerate.
#define MAX_DELAY static_cast<size_t>(48000 * 0.75f)

using namespace daisysp;

// Helper Modules
static AdEnv env;
static Oscillator osc;
static Metro tick;

// Declare a DelayLine of MAX_DELAY number of floats.
static DelayLine<float, MAX_DELAY> del;

void AudioCoreInit(float sample_rate) {
  env.Init(sample_rate);
  osc.Init(sample_rate);
  del.Init();

  // Set up Metro to pulse every second
  tick.Init(1.0f, sample_rate);

  // set adenv parameters
  env.SetTime(ADENV_SEG_ATTACK, 0.001);
  env.SetTime(ADENV_SEG_DECAY, 0.50);
  env.SetMin(0.0);
  env.SetMax(0.25);
  env.SetCurve(0);  // linear

  // Set parameters for oscillator
  osc.SetWaveform(osc.WAVE_TRI);
  osc.SetFreq(220);
  osc.SetAmp(0.25);

  // Set Delay time to 0.75 seconds
  del.SetDelay(sample_rate * 0.75f);
}

void AudioCoreKernel(const float *in, float *out, size_t size) {
  for (size_t i = 0; i < size; i += 2) {
    // When the Metro ticks:
    // trigger the envelope to start, and change freq of oscillator.
    if (tick.Process()) {
      float freq = rand() % 200;
      osc.SetFreq(freq + 100.0f);
      env.Trigger();
    }

    // Use envelope to control the amplitude of the oscillator.
    auto env_out = env.Process();
    osc.SetAmp(env_out);
    auto osc_out = osc.Process();

    // Read from delay line
    auto del_out = del.Read();
    // Calculate output and feedback
    auto sig_out = del_out + osc_out;
    auto feedback = (del_out * 0.75f) + osc_out;

    // Write to the delay
    del.Write(feedback);

    // Output (interleaved stereo)
    out[i] = sig_out;
    out[i + 1] = sig_out;
  }
}
