#pragma once
#include "AudioDecoder.h"
<<<<<<< HEAD
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
=======
#include <iostream>

class MP3Decoder : public AudioDecoder {
private:
    std::string archivo;
public:
    void cargar(const std::string& archivo) override {
        this->archivo = archivo;
    }
    void reproducir() override {
        std::cout << "Reproduciendo MP3: " << archivo << std::endl;
    }
    void pausar() override {
        std::cout << "Pausado MP3\n";
    }
    void detener() override {
        std::cout << "Detenido MP3\n";
    }
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
};
