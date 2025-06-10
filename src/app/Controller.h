#pragma once
#include "../core/MusicPlayer.h"
#include "../ui/MusicPlayerUI.h"

// Controlador principal de la aplicación
class Controller
{
private:
    MusicPlayer player; // Lógica y estado del reproductor
    MusicPlayerUI ui;   // Interfaz gráfica (UI)
public:
    // Inicia el flujo principal de la app
    void iniciarConInterfaz();
};
