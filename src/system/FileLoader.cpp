#include "FileLoader.h"
#include <filesystem>
#include <iostream>

// Escanea el directorio 'path' y retorna un vector de Cancion con los archivos mp3 encontrados.
// El nombre debe tener formato "artista - titulo.mp3". Si no, pone artista "desconocido".
std::vector<Cancion> FileLoader::scanDirectory(const std::string &path)
{
    std::vector<Cancion> canciones;

    // Recorre todos los archivos del directorio usando la biblioteca estándar.
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        std::string nombre = entry.path().filename().string();
        std::string ruta = entry.path().string();

        // Solo procesa archivos .mp3
        if (entry.path().extension() == ".mp3")
        {
            std::string titulo, artista;
            size_t guion = nombre.find(" - ");
            if (guion != std::string::npos)
            {
                // Formato: Artista - Título.mp3
                artista = nombre.substr(0, guion);
                // Busca ".mp3" desde el final para soportar títulos con '-'
                size_t extPos = nombre.rfind(".mp3");
                titulo = nombre.substr(guion + 3, extPos - guion - 3);
            }
            else
            {
                // Si no tiene " - ", pon artista por defecto
                artista = "Artista desconocido";
                size_t extPos = nombre.rfind(".mp3");
                titulo = nombre.substr(0, extPos);
            }
            // Por ahora la duración (0) es solo un placeholder
            canciones.emplace_back(titulo, artista, 0, ruta);
        }
    }

    return canciones;
}
