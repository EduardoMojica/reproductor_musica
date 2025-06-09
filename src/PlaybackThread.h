#pragma once
#include <thread>
#include <atomic>
#include "AudioDecoder.h"

class PlaybackThread {
private:
    std::thread hilo;
    std::atomic<bool> activo;
    AudioDecoder* decoder;
public:
    PlaybackThread(AudioDecoder* dec);
    void iniciar();
    void detener();
    ~PlaybackThread();
};
