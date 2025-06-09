#pragma once
#include <string>

class Cancion {
public:
    std::string titulo;
    std::string artista;
    int duracionSegundos;
    std::string archivo;

    Cancion(std::string t, std::string a, int dur, std::string path)
        : titulo(t), artista(a), duracionSegundos(dur), archivo(path) {}
};
