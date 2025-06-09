#pragma once
#include "AudioDecoder.h"
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
};
