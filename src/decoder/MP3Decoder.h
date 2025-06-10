#pragma once

#include "../decoder/AudioDecoder.h"
#include "raylib.h"
#include <string>
#include <thread>
#include <atomic>

// Decodificador de archivos MP3 usando Raylib.
// Permite cargar, reproducir, detener y manipular el stream de audio en un hilo.
class MP3Decoder : public AudioDecoder
{
private:
    std::thread updaterThread;        // Hilo que actualiza el stream de música
    std::atomic<bool> running{false}; // Flag para controlar el hilo
    std::string archivo;              // Path del archivo actual
    Music music;                      // Objeto Raylib para el stream
    bool loaded = false;              // Indica si hay música cargada

    // Detiene y une el hilo updaterThread si está corriendo
    void stopThread();

public:
    MP3Decoder();

    // Carga un archivo MP3 al decodificador
    void cargar(const std::string &archivo) override;

    // Inicia la reproducción del stream (y el hilo de actualización)
    void reproducir() override;

    // Llama a UpdateMusicStream (solo si NO usas hilos)
    void actualizar() override;

    // Reanuda la reproducción si está pausada
    void reanudar() override;

    // Detiene el stream y el hilo
    void detener() override;

    // Ajusta el volumen (de 0.0f a 1.0f)
    void setVolumen(float volumen) override;

    // Retorna true si se está reproduciendo música
    bool estaReproduciendo() const override;

    // Salta a un punto del stream según el progreso (0.0 = inicio, 1.0 = fin)
    void setProgreso(float progress) override;

    ~MP3Decoder() override;

    float getProgreso() const;
    
    float getDuracion() const;
};
