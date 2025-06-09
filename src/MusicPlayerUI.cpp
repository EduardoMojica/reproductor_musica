#include "MusicPlayerUI.h"
#include "raylib.h"
#include <string>
<<<<<<< HEAD
#include <vector>
#include <cmath>
#include <cstdlib>

// Dibuja botones redondeados con hover
void drawButton(Rectangle rect, const char *text, Color base, Color hover, bool isHovered)
{
    DrawRectangleRounded(rect, 0.5f, 10, isHovered ? hover : base);
    int textWidth = MeasureText(text, 18);
    DrawText(text, rect.x + (rect.width - textWidth) / 2, rect.y + 10, 18, DARKBLUE);
}

// Dibuja visualizador tipo barra animada
void drawVisualizer(Rectangle rect, int bars, float animTime)
{
    int barWidth = (rect.width - (bars + 1) * 4) / bars;
    for (int i = 0; i < bars; i++)
    {
        float phase = animTime * 1.5f + i * 0.7f;
        float height = (std::sin(phase) + 1.2f) / 2.2f * (rect.height - 20);
        Rectangle bar = {
            rect.x + 4 + i * (barWidth + 4),
            rect.y + rect.height - height - 10,
            (float)barWidth,
            height};
        DrawRectangleRounded(bar, 0.3f, 6, ColorAlpha(BLUE, 0.75f));
        DrawRectangleRoundedLines(bar, 0.3f, 6, 2, SKYBLUE);
    }
}

void MusicPlayerUI::iniciar(MusicPlayer &player)
{
    const int ancho = 800, alto = 600;
    InitWindow(ancho, alto, "MeloPlayer XP Edition");
    SetTargetFPS(60);

    Color fondoXP = {49, 106, 197, 255};
    Color baseBtn = {180, 215, 250, 255};
    Color hoverBtn = {200, 235, 255, 255};

    // Layout
    int visW = 420, visH = 120;
    Rectangle vis = {ancho / 2.0f - visW / 2.0f, 170, (float)visW, (float)visH};
    int infoY = vis.y - 70;
    int progBarY = vis.y + vis.height + 30;
    Rectangle progBar = {80, (float)progBarY, ancho - 160, 14};

    // Botones centrados
    float btnW = 52, btnH = 52, gap = 20;
    float totalBtnW = 5 * btnW + 4 * gap;
    float startX = (ancho - totalBtnW) / 2;
    int btnY = progBar.y + 50;
    std::vector<Rectangle> btns = {
        {startX + 0 * (btnW + gap), (float)btnY, btnW, btnH}, // Prev
        {startX + 1 * (btnW + gap), (float)btnY, btnW, btnH}, // Play
        {startX + 2 * (btnW + gap), (float)btnY, btnW, btnH}, // Pause
        {startX + 3 * (btnW + gap), (float)btnY, btnW, btnH}, // Stop
        {startX + 4 * (btnW + gap), (float)btnY, btnW, btnH}  // Next
    };
    std::vector<const char *> icons = {"<<", ">", "||", "[]", ">>"};

    // Barra de volumen debajo de los botones
    float volBarW = 300, volBarH = 14;
    float volBarX = (ancho - volBarW) / 2;
    float volBarY = btnY + btnH + 32;
    Rectangle volBar = {volBarX, volBarY, volBarW, volBarH};

    float volume = 0.7f;
    float progress = 0.0f;
    float duration = 1.0f; // Cambia esto por la duración real si tienes acceso

    float animTime = 0;

    while (!WindowShouldClose())
    {
        animTime += GetFrameTime();

        BeginDrawing();
        ClearBackground(fondoXP);

        // Visualizador
        DrawRectangleRounded(vis, 0.20f, 18, ColorAlpha(LIGHTGRAY, 0.25f));
        drawVisualizer(vis, 32, animTime);

        // Info canción (centrada arriba)
        Cancion *actual = player.obtenerCancionActual();
        if (actual)
        {
            std::string tituloStr = "Título: " + actual->titulo;
            std::string artistaStr = "Artista: " + actual->artista;
            int tWidth = MeasureText(tituloStr.c_str(), 30);
            int aWidth = MeasureText(artistaStr.c_str(), 24);
            DrawText(tituloStr.c_str(), ancho / 2 - tWidth / 2, infoY, 30, WHITE);
            DrawText(artistaStr.c_str(), ancho / 2 - aWidth / 2, infoY + 38, 24, SKYBLUE);
        }
        else
        {
            std::string txt = "No hay canciones cargadas.";
            int width = MeasureText(txt.c_str(), 26);
            DrawText(txt.c_str(), ancho / 2 - width / 2, infoY, 26, YELLOW);
        }

        // ----- BARRA DE PROGRESO INTERACTIVA -----
        DrawRectangleRounded(progBar, 0.5f, 8, DARKBLUE);
        DrawRectangleRounded((Rectangle){progBar.x, progBar.y, progress * progBar.width, progBar.height}, 0.5f, 8, SKYBLUE);

        // Tiempos (simulados: pon aquí los reales si los tienes)
        DrawText("00:00", progBar.x, progBar.y + 18, 16, WHITE);
        DrawText("03:45", progBar.x + progBar.width - 55, progBar.y + 18, 16, WHITE);

        // ----- BOTONES -----
        Vector2 mouse = GetMousePosition();
        for (int i = 0; i < btns.size(); ++i)
        {
            bool hovered = CheckCollisionPointRec(mouse, btns[i]);
            drawButton(btns[i], icons[i], baseBtn, hoverBtn, hovered);
        }

        // ----- BARRA DE VOLUMEN -----
        DrawText("Volumen", volBar.x - 100, volBar.y - 2, 20, WHITE);
        DrawRectangleRounded(volBar, 0.5f, 8, SKYBLUE);
        DrawRectangleRounded((Rectangle){volBar.x, volBar.y, volume * volBar.width, volBar.height}, 0.5f, 8, YELLOW);
        DrawCircle(volBar.x + volume * volBar.width, volBar.y + volBar.height / 2, 10, YELLOW);

        // Interacciones
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // BARRA DE PROGRESO: click para adelantar canción
            if (CheckCollisionPointRec(mouse, progBar))
            {
                progress = (mouse.x - progBar.x) / progBar.width;
                if (progress < 0)
                    progress = 0;
                if (progress > 1)
                    progress = 1;
                // Si tienes un método para esto en tu MusicPlayer, llama aquí:
                player.setProgreso(progress);
            }
            // Botones
            if (CheckCollisionPointRec(mouse, btns[0]))
                player.anterior();
            if (CheckCollisionPointRec(mouse, btns[1]))
                player.reproducir();
            if (CheckCollisionPointRec(mouse, btns[2]))
                player.pausar();
            if (CheckCollisionPointRec(mouse, btns[3]))
                player.detener();
            if (CheckCollisionPointRec(mouse, btns[4]))
                player.siguiente();
            // BARRA DE VOLUMEN
            if (CheckCollisionPointRec(mouse, volBar))
            {
                volume = (mouse.x - volBar.x) / volBar.width;
                if (volume < 0)
                    volume = 0;
                if (volume > 1)
                    volume = 1;
                player.setVolumen(volume);
            }
=======

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
>>>>>>> 5ac8b0b436599045590fd8992c130d6267be10e9
        }

        EndDrawing();
    }

    CloseWindow();
}
