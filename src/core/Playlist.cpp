#include "Playlist.h"

// Constructor: empieza la playlist vacía y el índice en 0
Playlist::Playlist() : actual(0) {}

// Agrega una canción al final
void Playlist::agregarCancion(const Cancion &c)
{
    canciones.push_back(c);
}

// Elimina la canción en la posición indicada
void Playlist::eliminarCancion(int index)
{
    if (index >= 0 && index < canciones.size())
    {
        canciones.erase(canciones.begin() + index);
        // Si se elimina la última, ajusta el índice actual
        if (actual >= canciones.size())
            actual = canciones.size() - 1;
    }
}

// Avanza a la siguiente canción, vuelve al principio si está al final
Cancion *Playlist::siguiente()
{
    if (canciones.empty())
        return nullptr;
    actual = (actual + 1) % canciones.size();
    return &canciones[actual];
}

// Retrocede a la anterior, vuelve al final si está al principio
Cancion *Playlist::anterior()
{
    if (canciones.empty())
        return nullptr;
    actual = (actual - 1 + canciones.size()) % canciones.size();
    return &canciones[actual];
}

// Devuelve la canción actual
Cancion *Playlist::actualCancion()
{
    if (canciones.empty())
        return nullptr;
    return &canciones[actual];
}

// Devuelve una referencia a todo el vector de canciones
const std::vector<Cancion> &Playlist::obtenerCanciones() const
{
    return canciones;
}
