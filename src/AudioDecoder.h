#pragma once
#include <string>

class AudioDecoder
{
public:
    virtual void cargar(const std::string &archivo) = 0;
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual void actualizar() {}
    virtual void reanudar() {}
    virtual void setVolumen(float) {}
    virtual bool estaReproduciendo() const { return false; }

    virtual ~AudioDecoder() = default;
};
