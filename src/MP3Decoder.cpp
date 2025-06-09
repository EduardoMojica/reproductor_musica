#include "MP3Decoder.h"
#include "raylib.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

MP3Decoder::MP3Decoder()
{
    // Constructor vacío, puedes inicializar aquí si necesitas
}

void MP3Decoder::cargar(const std::string &archivo)
{
    stopThread();
    if (loaded) {
        UnloadMusicStream(music);
    }
    this->archivo = archivo;
    music = LoadMusicStream(archivo.c_str());
    loaded = true;
}

void MP3Decoder::reproducir()
{
    if (loaded)
    {
        PlayMusicStream(music);
        stopThread(); // Por si el usuario hace "play" varias veces
        running = true;
        updaterThread = std::thread([this]()
        {
            while (running && IsMusicStreamPlaying(music)) {
                UpdateMusicStream(music);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
            running = false;
        });
        std::cout << "Reproduciendo MP3: " << archivo << std::endl;
    }
}

void MP3Decoder::actualizar()
{
    // NO usar con thread, solo si no usas thread
    if (loaded)
        UpdateMusicStream(music);
}

void MP3Decoder::pausar()
{
    if (loaded)
        PauseMusicStream(music);
    std::cout << "Pausado MP3\n";
}

void MP3Decoder::reanudar()
{
    if (loaded)
        ResumeMusicStream(music);
    std::cout << "Reanudado MP3\n";
}

void MP3Decoder::detener()
{
    if (loaded)
    {
        StopMusicStream(music);
        stopThread();
        std::cout << "Detenido MP3\n";
    }
}

void MP3Decoder::setVolumen(float volumen)
{
    if (loaded)
        SetMusicVolume(music, volumen);
}

bool MP3Decoder::estaReproduciendo() const
{
    return loaded && IsMusicStreamPlaying(music);
}

void MP3Decoder::setProgreso(float progress)
{
    if (loaded && music.stream.sampleRate > 0) {
        float totalSec = GetMusicTimeLength(music);
        // SeekMusicStream está en Raylib 4.5+
        SeekMusicStream(music, totalSec * progress);
    }
}

// Métodos privados
void MP3Decoder::stopThread()
{
    running = false;
    if (updaterThread.joinable())
        updaterThread.join();
}

MP3Decoder::~MP3Decoder()
{
    detener();
    if (loaded)
        UnloadMusicStream(music);
}