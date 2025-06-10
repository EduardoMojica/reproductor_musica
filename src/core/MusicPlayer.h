#pragma once
#include "../core/Playlist.h"
#include "../system/PlaybackThread.h"
#include "../decoder/MP3Decoder.h"

class MusicPlayer
{
private:
    Playlist lista;
    MP3Decoder decoder;
    PlaybackThread *playback;
    void cargarYReproducirCancion();

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
    float getProgreso() const;
    float getDuracion() const;
    const Playlist &getPlaylist() const;
};
