#include "Playlist.h"

Playlist::Playlist() : actual(0) {}

void Playlist::agregarCancion(const Cancion& c) {
    canciones.push_back(c);
}

void Playlist::eliminarCancion(int index) {
    if (index >= 0 && index < canciones.size()) {
        canciones.erase(canciones.begin() + index);
        if (actual >= canciones.size()) actual = canciones.size() - 1;
    }
}

Cancion* Playlist::siguiente() {
    if (canciones.empty()) return nullptr;
    actual = (actual + 1) % canciones.size();
    return &canciones[actual];
}

Cancion* Playlist::anterior() {
    if (canciones.empty()) return nullptr;
    actual = (actual - 1 + canciones.size()) % canciones.size();
    return &canciones[actual];
}

Cancion* Playlist::actualCancion() {
    if (canciones.empty()) return nullptr;
    return &canciones[actual];
}

std::vector<Cancion>& Playlist::obtenerCanciones() {
    return canciones;
}
