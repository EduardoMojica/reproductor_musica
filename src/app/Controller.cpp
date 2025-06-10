#include "Controller.h"
#include "../system/FileLoader.h"

// Método principal: carga canciones y arranca la interfaz gráfica
void Controller::iniciarConInterfaz()
{
    FileLoader loader;
    Playlist lista;

    // Escanea el folder de assets y carga todas las canciones MP3
    auto canciones = loader.scanDirectory("assets");

    // Agrega cada canción encontrada a la playlist
    for (const auto &c : canciones)
    {
        lista.agregarCancion(c);
    }

    // Carga la playlist al reproductor y lanza la interfaz de usuario
    player.cargarLista(lista);
    ui.iniciar(player);
}
