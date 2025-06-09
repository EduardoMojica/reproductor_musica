#include "MusicPlayer.h"

<<<<<<< HEAD
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
=======
MusicPlayer::MusicPlayer() {
    playback = new PlaybackThread(&decoder);
}

MusicPlayer::~MusicPlayer() {
    delete playback;
}

void MusicPlayer::cargarLista(const Playlist& p) {
    lista = p;
}

void MusicPlayer::reproducir() {
    Cancion* c = lista.actualCancion();
    if (c) {
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
        decoder.cargar(c->archivo);
        playback->iniciar();
    }
}

<<<<<<< HEAD
void MusicPlayer::pausar()
{
    decoder.pausar();
}

void MusicPlayer::detener()
{
=======
void MusicPlayer::pausar() {
    decoder.pausar();
}

void MusicPlayer::detener() {
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    playback->detener();
    decoder.detener();
}

<<<<<<< HEAD
void MusicPlayer::siguiente()
{
=======
void MusicPlayer::siguiente() {
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    lista.siguiente();
    reproducir();
}

<<<<<<< HEAD
void MusicPlayer::anterior()
{
=======
void MusicPlayer::anterior() {
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    lista.anterior();
    reproducir();
}

<<<<<<< HEAD
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
=======
Cancion* MusicPlayer::obtenerCancionActual() {
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
    return lista.actualCancion();
}
