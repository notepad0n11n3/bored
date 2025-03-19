#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>

#define PCM_DEVICE "default"

int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    unsigned int rate = 44100;  // Frecuencia de muestreo
    int channels = 1;           // Canal monoaural
    int err;
    
    // Abre el dispositivo de audio
    if ((err = snd_pcm_open(&handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "Error al abrir el dispositivo PCM: %s\n", snd_strerror(err));
        return 1;
    }

    // Asigna los parámetros de hardware
    snd_pcm_hw_params_alloca(&params);
    if ((err = snd_pcm_hw_params_any(handle, params)) < 0) {
        fprintf(stderr, "Error al inicializar los parámetros de hardware: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "Error al establecer el acceso a los datos: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE)) < 0) {
        fprintf(stderr, "Error al establecer el formato de datos: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0)) < 0) {
        fprintf(stderr, "Error al establecer la frecuencia de muestreo: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_channels(handle, params, channels)) < 0) {
        fprintf(stderr, "Error al establecer los canales: %s\n", snd_strerror(err));
        return 1;
    }

    // Aplicar los parámetros configurados
    if ((err = snd_pcm_hw_params(handle, params)) < 0) {
        fprintf(stderr, "Error al aplicar los parámetros de hardware: %s\n", snd_strerror(err));
        return 1;
    }

    // Crear una onda de 1 kHz
    int tone_duration = 5; // Duración en segundos
    short buffer[rate * channels];
    for (int i = 0; i < rate * channels; i++) {
        buffer[i] = (short)(32767.0 * sin(2.0 * M_PI * 1000.0 * i / rate));  // 1 kHz
    }

    // Reproducir el sonido
    for (int i = 0; i < tone_duration; i++) {
        if ((err = snd_pcm_writei(handle, buffer, rate)) < 0) {
            fprintf(stderr, "Error al escribir datos al dispositivo: %s\n", snd_strerror(err));
            return 1;
        }
    }

    // Cerrar el dispositivo
    snd_pcm_close(handle);
    return 0;
}
