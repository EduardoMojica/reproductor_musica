#pragma once
#include "AudioDecoder.h"
#include <string>
#include <thread>
#include <atomic>

class MP3Decoder : public AudioDecoder
{
private:
    std::thread updaterThread;
    std::atomic<bool> running{false};
    std::string archivo;
    Music music;
    bool loaded = false;
    void stopThread();

public:
    MP3Decoder();
    void cargar(const std::string &archivo) override;
    void reproducir() override;
    void actualizar() override;
    void pausar() override;
    void reanudar() override;
    void detener() override;
    void setVolumen(float volumen) override;
    bool estaReproduciendo() const override;
    void setProgreso(float progress) override;
    ~MP3Decoder() override;
};
