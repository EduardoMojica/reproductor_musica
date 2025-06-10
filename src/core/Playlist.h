#pragma once
#include <vector>
#include "../core/Cancion.h"

// Playlist: gestiona una lista de canciones y permite navegar entre ellas.
class Playlist
{
private:
    std::vector<Cancion> canciones; // Lista de canciones
    int actual;                     // Índice de la canción actual

public:
    Playlist();

    // Agrega una canción al final de la playlist
    void agregarCancion(const Cancion &c);

    // Elimina una canción por índice (posición)
    void eliminarCancion(int index);

    // Avanza a la siguiente canción (con wrap-around)
    Cancion *siguiente();

    // Retrocede a la canción anterior (con wrap-around)
    Cancion *anterior();

    // Obtiene la canción actual
    Cancion *actualCancion();

    // Permite acceder a la lista completa de canciones (por si la UI quiere mostrar el listado)
    const std::vector<Cancion> &obtenerCanciones() const;
};
