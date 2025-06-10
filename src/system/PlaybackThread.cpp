#include "PlaybackThread.h"
#include <chrono>
#include <iostream>

// Constructor: inicializa el puntero al decoder y el flag de control
PlaybackThread::PlaybackThread(AudioDecoder *dec)
    : decoder(dec), activo(false) {}

// Inicia el hilo y llama periódicamente a reproducir()
void PlaybackThread::iniciar()
{
    activo = true;
    // Lambda que se ejecuta en el hilo
    hilo = std::thread([this]()
                       {
        while (activo) {
            decoder->reproducir(); // Llama a reproducir (debe ser no bloqueante)
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } });
}

// Detiene el hilo de reproducción
void PlaybackThread::detener()
{
    activo = false;
    if (hilo.joinable())
        hilo.join(); // Espera a que el hilo termine
}

// Destructor: se asegura de detener el hilo si el objeto se destruye
PlaybackThread::~PlaybackThread()
{
    detener();
}
