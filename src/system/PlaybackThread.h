#pragma once

#include <thread>
#include <atomic>
#include "../decoder/AudioDecoder.h"

// Clase encargada de gestionar la reproducción en un hilo separado
class PlaybackThread
{
private:
    std::thread hilo;         // Hilo que ejecuta la reproducción
    std::atomic<bool> activo; // Flag para indicar si el hilo debe seguir corriendo
    AudioDecoder *decoder;    // Puntero al decodificador de audio

public:
    // Constructor: recibe un puntero a un AudioDecoder
    PlaybackThread(AudioDecoder *dec);

    // Inicia el hilo de reproducción
    void iniciar();

    // Detiene el hilo de reproducción de forma segura
    void detener();

    // Destructor: asegura que el hilo se detenga antes de destruir el objeto
    ~PlaybackThread();
};
