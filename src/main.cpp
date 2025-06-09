#include "Controller.h"
#include "raylib.h"

int main()
{
    InitAudioDevice();

    Controller controlador;
    controlador.iniciarConInterfaz();

    CloseAudioDevice();
    return 0;
}