#include "Controller.h"
#include "FileLoader.h"

void Controller::iniciarConInterfaz() {
    FileLoader loader;
    Playlist lista;
    auto canciones = loader.scanDirectory("assets");

    for (const auto& c : canciones) {
        lista.agregarCancion(c);
    }

    player.cargarLista(lista);
    ui.iniciar(player);
}
