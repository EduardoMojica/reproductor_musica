#pragma once
#include "Playlist.h"
#include "PlaybackThread.h"
#include "MP3Decoder.h"

class MusicPlayer
{
private:
    Playlist lista;
    MP3Decoder decoder;
    PlaybackThread *playback;

public:
    MusicPlayer();
    ~MusicPlayer();
    void cargarLista(const Playlist &p);
    void reproducir();
    void pausar();
    void detener();
    void siguiente();
    void anterior();
    void setVolumen(float volumen);
    void setProgreso(float progress);
    Cancion *obtenerCancionActual();
};
