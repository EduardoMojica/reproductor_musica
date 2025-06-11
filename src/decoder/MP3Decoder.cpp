#include "MP3Decoder.h"
#include <iostream>
#include <chrono>

// Constructor que inicializa el objeto MP3Decoder
MP3Decoder::MP3Decoder() {}

// Carga un archivo MP3 y libera el anterior si es necesario
void MP3Decoder::cargar(const std::string &archivo)
{
    stopThread();
    if (loaded)
    {
        UnloadMusicStream(music);
    }
    this->archivo = archivo;
    music = LoadMusicStream(archivo.c_str());
    loaded = true;
}

// Reproduce el stream y lanza un hilo para actualizarlo
void MP3Decoder::reproducir()
{
    if (loaded)
    {
        PlayMusicStream(music);
        stopThread(); // Por si hay un hilo anterior
        running = true;
        updaterThread = std::thread([this]()
                                    {
            while (running && IsMusicStreamPlaying(music)) {
                UpdateMusicStream(music);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
            running = false; });
        std::cout << "Reproduciendo MP3: " << archivo << std::endl;
    }
}

// Llama a UpdateMusicStream (si decides NO usar hilos)
void MP3Decoder::actualizar()
{
    if (loaded)
        UpdateMusicStream(music);
}

// Reanuda la reproducción del stream
void MP3Decoder::reanudar()
{
    if (loaded)
        ResumeMusicStream(music);
    std::cout << "Reanudado MP3\n";
}

// Detiene el stream y el hilo de actualización
void MP3Decoder::detener()
{
    if (loaded)
    {
        StopMusicStream(music);
        stopThread();
        std::cout << "Detenido MP3\n";
    }
}

// Cambia el volumen del stream
void MP3Decoder::setVolumen(float volumen)
{
    if (loaded)
        SetMusicVolume(music, volumen);
}

// ¿Se está reproduciendo actualmente?
bool MP3Decoder::estaReproduciendo() const
{
    return loaded && IsMusicStreamPlaying(music);
}

// Cambia el progreso de la canción 
void MP3Decoder::setProgreso(float progress)
{
    if (loaded && music.stream.sampleRate > 0)
    {
        float totalSec = GetMusicTimeLength(music);
        SeekMusicStream(music, totalSec * progress);
    }
}

// Detiene el hilo updaterThread de forma segura
void MP3Decoder::stopThread()
{
    running = false;
    if (updaterThread.joinable())
        updaterThread.join();
}

// Destructor: detiene todo y libera memoria
MP3Decoder::~MP3Decoder()
{
    detener();
    if (loaded)
        UnloadMusicStream(music);
}

float MP3Decoder::getProgreso() const
{
    if (loaded && GetMusicTimeLength(music) > 0.0f)
        return GetMusicTimePlayed(music) / GetMusicTimeLength(music);
    return 0.0f;
}

float MP3Decoder::getDuracion() const
{
    return loaded ? GetMusicTimeLength(music) : 0.0f;
}