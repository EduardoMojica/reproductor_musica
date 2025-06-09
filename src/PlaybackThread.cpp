#include "PlaybackThread.h"
#include <chrono>
#include <iostream>

PlaybackThread::PlaybackThread(AudioDecoder* dec) : decoder(dec), activo(false) {}

void PlaybackThread::iniciar() {
    activo = true;
    hilo = std::thread([this]() {
        while (activo) {
            decoder->reproducir();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
}

void PlaybackThread::detener() {
    activo = false;
    if (hilo.joinable()) hilo.join();
}

PlaybackThread::~PlaybackThread() {
    detener();
}
