#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100   // Frecuencia de muestreo (Hz)
#define TONE_FREQUENCY 440 // Frecuencia del tono (Hz, A4)
#define DURATION 2         // Duración del tono (segundos)

int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    snd_pcm_uframes_t frames;
    short *buffer;
    int err;

    // Abrir el dispositivo de salida de sonido
    err = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (err < 0) {
        fprintf(stderr, "Error al abrir el dispositivo de audio: %s\n", snd_strerror(err));
        return 1;
    }

    // Configurar los parámetros de hardware
    snd_pcm_hw_params_alloca(&params);
    err = snd_pcm_hw_params_any(handle, params);
    if (err < 0) {
        fprintf(stderr, "Error al obtener los parámetros de hardware: %s\n", snd_strerror(err));
        return 1;
    }

    err = snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    err = snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    err = snd_pcm_hw_params_set_channels(handle, params, 1);  // Mono
    err = snd_pcm_hw_params_set_rate(handle, params, SAMPLE_RATE, 0);

    err = snd_pcm_hw_params(handle, params);
    if (err < 0) {
        fprintf(stderr, "Error al configurar los parámetros de hardware: %s\n", snd_strerror(err));
        return 1;
    }

    // Calcular el número de frames que vamos a reproducir
    frames = SAMPLE_RATE * DURATION;
    buffer = (short *)malloc(frames * sizeof(short));

    if (buffer == NULL) {
        fprintf(stderr, "Error al alocar memoria para el buffer\n");
        return 1;
    }

    // Generar una onda sinusoidal
    for (int i = 0; i < frames; i++) {
        buffer[i] = (short)(32767.0 * sin(2.0 * M_PI * TONE_FREQUENCY * i / SAMPLE_RATE));
    }

    // Reproducir el sonido
    err = snd_pcm_writei(handle, buffer, frames);
    if (err < 0) {
        fprintf(stderr, "Error al reproducir el sonido: %s\n", snd_strerror(err));
        return 1;
    }

    // Liberar recursos
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);

    return 0;
}
