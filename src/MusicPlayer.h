#pragma once
#include "Playlist.h"
#include "PlaybackThread.h"
#include "MP3Decoder.h"

<<<<<<< HEAD
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
=======
class MusicPlayer {
private:
    Playlist lista;
    MP3Decoder decoder;
    PlaybackThread* playback;
public:
    MusicPlayer();
    ~MusicPlayer();
    void cargarLista(const Playlist& p);
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    void reproducir();
    void pausar();
    void detener();
    void siguiente();
    void anterior();
<<<<<<< HEAD
    void setVolumen(float volumen);
    void setProgreso(float progress);
    Cancion *obtenerCancionActual();
=======
    Cancion* obtenerCancionActual();
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
};
