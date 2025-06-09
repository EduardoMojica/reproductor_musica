#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    playback = new PlaybackThread(&decoder);
}

MusicPlayer::~MusicPlayer()
{
    delete playback;
}

void MusicPlayer::cargarLista(const Playlist &p)
{
    lista = p;
}

void MusicPlayer::reproducir()
{
    Cancion *c = lista.actualCancion();
    if (c)
    {
        decoder.cargar(c->archivo);
        playback->iniciar();
    }
}

void MusicPlayer::pausar()
{
    decoder.pausar();
}

void MusicPlayer::detener()
{
    playback->detener();
    decoder.detener();
}

void MusicPlayer::siguiente()
{
    lista.siguiente();
    reproducir();
}

void MusicPlayer::anterior()
{
    lista.anterior();
    reproducir();
}

void MusicPlayer::setVolumen(float volumen)
{
    decoder.setVolumen(volumen);
}

void MusicPlayer::setProgreso(float progress)
{
    decoder.setProgreso(progress);
}

Cancion *MusicPlayer::obtenerCancionActual()
{
    return lista.actualCancion();
}
