#pragma once
#include <vector>
#include "Cancion.h"

class Playlist {
private:
    std::vector<Cancion> canciones;
    int actual;
public:
    Playlist();
    void agregarCancion(const Cancion& c);
    void eliminarCancion(int index);
    Cancion* siguiente();
    Cancion* anterior();
    Cancion* actualCancion();
    std::vector<Cancion>& obtenerCanciones();
};
