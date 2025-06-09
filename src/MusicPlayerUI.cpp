#include "MusicPlayerUI.h"
#include "raylib.h"
#include <string>

void MusicPlayerUI::iniciar(MusicPlayer& player) {
    const int ancho = 600;
    const int alto = 400;
    InitWindow(ancho, alto, "MeloPlayer - Raylib UI");
    SetTargetFPS(60);

    Rectangle btnPlay = { 50, 300, 80, 40 };
    Rectangle btnPause = { 140, 300, 80, 40 };
    Rectangle btnStop = { 230, 300, 80, 40 };
    Rectangle btnNext = { 320, 300, 80, 40 };
    Rectangle btnPrev = { 410, 300, 80, 40 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Cancion* actual = player.obtenerCancionActual();
        if (actual) {
            DrawText(("Título: " + actual->titulo).c_str(), 20, 40, 20, DARKGRAY);
            DrawText(("Artista: " + actual->artista).c_str(), 20, 70, 20, DARKGRAY);
        } else {
            DrawText("No hay canciones cargadas.", 20, 40, 20, RED);
        }

        DrawRectangleRec(btnPlay, LIGHTGRAY);
        DrawRectangleRec(btnPause, LIGHTGRAY);
        DrawRectangleRec(btnStop, LIGHTGRAY);
        DrawRectangleRec(btnNext, LIGHTGRAY);
        DrawRectangleRec(btnPrev, LIGHTGRAY);

        DrawText("Play", btnPlay.x + 20, btnPlay.y + 10, 20, BLACK);
        DrawText("Pause", btnPause.x + 15, btnPause.y + 10, 20, BLACK);
        DrawText("Stop", btnStop.x + 20, btnStop.y + 10, 20, BLACK);
        DrawText("Next", btnNext.x + 20, btnNext.y + 10, 20, BLACK);
        DrawText("Prev", btnPrev.x + 20, btnPrev.y + 10, 20, BLACK);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();

            if (CheckCollisionPointRec(mouse, btnPlay)) player.reproducir();
            if (CheckCollisionPointRec(mouse, btnPause)) player.pausar();
            if (CheckCollisionPointRec(mouse, btnStop)) player.detener();
            if (CheckCollisionPointRec(mouse, btnNext)) player.siguiente();
            if (CheckCollisionPointRec(mouse, btnPrev)) player.anterior();
        }

        EndDrawing();
    }

    CloseWindow();
}
