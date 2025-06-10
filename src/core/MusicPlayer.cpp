#include "MusicPlayer.h"
#include <iostream>

// Constructor: inicializa el hilo de playback
MusicPlayer::MusicPlayer()
{
    playback = new PlaybackThread(&decoder);
}

// Destructor: libera el hilo
MusicPlayer::~MusicPlayer()
{
    delete playback;
}

// Carga la lista de canciones en el reproductor
void MusicPlayer::cargarLista(const Playlist &p)
{
    lista = p;
}

// Carga la canción actual del playlist y la reproduce
void MusicPlayer::cargarYReproducirCancion()
{
    Cancion *actual = lista.actualCancion();
    if (actual)
    {
        decoder.cargar(actual->archivo); // Carga el archivo mp3
        playback->detener();             // Por si ya hay una reproducción activa
        playback->iniciar();             // Inicia la reproducción en hilo
    }
    else
    {
        std::cout << "No hay canción para reproducir." << std::endl;
    }
}

// Inicia la reproducción de la canción actual
void MusicPlayer::reproducir()
{
    cargarYReproducirCancion();
}

// Pausa la canción actual
void MusicPlayer::pausar()
{
    decoder.pausar();
}

// Detiene la reproducción actual
void MusicPlayer::detener()
{
    playback->detener();
    decoder.detener();
}

// Pasa a la siguiente canción y la reproduce
void MusicPlayer::siguiente()
{
    lista.siguiente();
    cargarYReproducirCancion();
}

// Vuelve a la canción anterior y la reproduce
void MusicPlayer::anterior()
{
    lista.anterior();
    cargarYReproducirCancion();
}

// Cambia el volumen (de 0.0 a 1.0)
void MusicPlayer::setVolumen(float volumen)
{
    decoder.setVolumen(volumen);
}

// Cambia el progreso de la canción (0.0 = inicio, 1.0 = fin)
void MusicPlayer::setProgreso(float progress)
{
    decoder.setProgreso(progress);
}

// Devuelve un puntero a la canción actual (para mostrar info en UI)
Cancion *MusicPlayer::obtenerCancionActual()
{
    return lista.actualCancion();
}

float MusicPlayer::getDuracion() const
{
    return decoder.getDuracion();
}

float MusicPlayer::getProgreso() const
{
    return decoder.getProgreso();
}

const Playlist &MusicPlayer::getPlaylist() const
{
    return lista;
}