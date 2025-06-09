#pragma once
#include <string>

<<<<<<< HEAD
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

=======
class AudioDecoder {
public:
    virtual void cargar(const std::string& archivo) = 0;
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    virtual ~AudioDecoder() = default;
};
