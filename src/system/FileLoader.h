#pragma once

#include <vector>
#include <string>
#include "../core/Cancion.h"

// Clase encargada de escanear directorios para encontrar archivos de música (*.mp3)
// y devolver una lista de objetos Cancion.
class FileLoader
{
public:
    // Escanea el directorio especificado y regresa un vector con las canciones encontradas.
    // El nombre del archivo debe tener formato "artista - titulo.mp3" (si no, usa "Artista desconocido").
    std::vector<Cancion> scanDirectory(const std::string &path);
};
