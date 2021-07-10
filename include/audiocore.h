// ----------------------------------------------------------------
// audio core interface
// ----------------------------------------------------------------

#ifndef AUDIOCORE__H
#define AUDIOCORE__H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * initialize any DaisySP component instantaiated within the audio core
 * @param[in] sample_rate sampling frequency in Hz
 */
void AudioCoreInit(float sample_rate);

/**
 * implements the audio functionality. This is registered as the audio callback
 * on a Daisy platform, or invoked in the process loop in a VCV Rack plugin
 * @param[in] in input audio samples - interleaved stereo
 * @param[out] out output audio samples - interleaved stereo
 * @param[in] size size of the in and out vectors
 */
void AudioCoreKernel(const float *in, float *out, size_t size);

#ifdef __cplusplus
}
#endif

#endif  // AUDIOCORE__H
