#pragma once
#include <string>

class AudioDecoder
{
public:
    virtual void cargar(const std::string &archivo) = 0;
    virtual void reproducir() = 0;
    virtual void actualizar() = 0;
    virtual void pausar() = 0;
    virtual void reanudar() = 0;
    virtual void detener() = 0;
    virtual void setVolumen(float volumen) = 0;
    virtual bool estaReproduciendo() const = 0;
    virtual void setProgreso(float progress) = 0;
    virtual ~AudioDecoder() = default;
};
