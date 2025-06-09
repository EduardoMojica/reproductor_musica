#include "FileLoader.h"
#include <filesystem>

std::vector<Cancion> FileLoader::scanDirectory(const std::string& path) {
    std::vector<Cancion> canciones;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string nombre = entry.path().filename().string();
        std::string ruta = entry.path().string();

        if (entry.path().extension() == ".mp3") {
            std::string titulo, artista;
            size_t guion = nombre.find(" - ");
            if (guion != std::string::npos) {
                artista = nombre.substr(0, guion);
                titulo = nombre.substr(guion + 3, nombre.find(".mp3") - guion - 3);
            } else {
                artista = "Artista desconocido";
                titulo = nombre.substr(0, nombre.find(".mp3"));
            }
            canciones.emplace_back(titulo, artista, 0, ruta);
        }
    }

    return canciones;
}
