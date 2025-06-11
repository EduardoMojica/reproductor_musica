#pragma once
#include <string>


// Clase que representa una canción dentro de la playlist o reproductor.
// Contiene título, artista, duración y la ruta al archivo.

class Cancion
{
public:
    std::string titulo;   // Título de la canción
    std::string artista;  // Artista o banda
    int duracionSegundos; // Duración en segundos 
    std::string archivo;  // Ruta absoluta o relativa al archivo de audio

    // Constructor rápido
    Cancion(std::string t, std::string a, int dur, std::string path)
        : titulo(t), artista(a), duracionSegundos(dur), archivo(path) {}
};
