#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    // Inicialización si aplica
    playback = nullptr; // o la lógica que uses
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
    // Lógica para reproducir
}

void MusicPlayer::pausar()
{
    // Lógica para pausar
}

void MusicPlayer::detener()
{
    // Lógica para detener
}

void MusicPlayer::siguiente()
{
    // Lógica para siguiente canción
}

void MusicPlayer::anterior()
{
    // Lógica para anterior canción
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
