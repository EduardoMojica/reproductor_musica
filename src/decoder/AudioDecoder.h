#pragma once
#include <string>


// Clase abstracta para decodificadores de audio.
// Cualquier clase hija debe implementar
// todos estos métodos virtuales para ser usada por el sistema.
// Así puedes crear decoders para MP3, WAV, OGG, etc. de manera flexible.
class AudioDecoder
{
public:
    // Carga un archivo de audio 
    virtual void cargar(const std::string &archivo) = 0;

    // Inicia o reanuda la reproducción del audio
    virtual void reproducir() = 0;

    // Actualiza el stream de audio 
    virtual void actualizar() = 0;

    // Reanuda la reproducción si estaba pausada
    virtual void reanudar() = 0;

    // Detiene la reproducción y libera recursos si aplica
    virtual void detener() = 0;

    // Cambia el volumen (valor de 0.0f a 1.0f)
    virtual void setVolumen(float volumen) = 0;

    // Retorna true si hay audio sonando
    virtual bool estaReproduciendo() const = 0;

    // Permite avanzar/retroceder a cierta parte del audio 
    virtual void setProgreso(float progress) = 0;

    // Destructor virtual para manejo correcto de memoria al heredar
    virtual ~AudioDecoder() = default;
};
