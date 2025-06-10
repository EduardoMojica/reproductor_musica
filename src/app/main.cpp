#include "Controller.h"
#include "raylib.h"

// Punto de entrada de la aplicación.
// Inicializa el sistema de audio, crea el controlador principal y ejecuta el flujo principal.
int main()
{
    // Inicializa el dispositivo de audio antes de cualquier reproducción
    InitAudioDevice();

    // Crea el controlador principal (arma toda la lógica y la interfaz)
    Controller controlador;
    controlador.iniciarConInterfaz();

    // Libera los recursos de audio antes de salir
    CloseAudioDevice();

    return 0;
}
