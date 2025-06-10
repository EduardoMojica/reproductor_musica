#include "MusicPlayerUI.h"
#include "raylib.h"
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

// Dibuja botón redondeado con hover
void drawButton(Rectangle rect, const char *text, Color base, Color hover, bool isHovered)
{
    DrawRectangleRounded(rect, 0.5f, 10, isHovered ? hover : base);
    int textWidth = MeasureText(text, 18);
    DrawText(text, rect.x + (rect.width - textWidth) / 2, rect.y + 10, 18, DARKBLUE);
}

// Visualizador animado tipo XP
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
        DrawRectangleRounded(bar, 0.3f, 6, ColorAlpha(BLUE, 0.7f));
        DrawRectangleRoundedLines(bar, 0.3f, 6, 2, SKYBLUE);
    }
}

void MusicPlayerUI::iniciar(MusicPlayer &player)
{
    const int ancho = 900, alto = 700;
    InitWindow(ancho, alto, "MeloPlayer XP Edition");
    SetTargetFPS(60);

    Color fondoXP = {49, 106, 197, 255};
    Color baseBtn = {180, 215, 250, 255};
    Color hoverBtn = {200, 235, 255, 255};

    // Layout visualizador
    int visW = 420, visH = 120;
    Rectangle vis = {ancho / 2.0f - visW / 2.0f, 120, (float)visW, (float)visH};
    int infoY = vis.y - 70;
    int progBarY = vis.y + vis.height + 35;
    Rectangle progBar = {80, (float)progBarY, ancho - 160, 16};

    // Botones de control
    float btnW = 60, btnH = 60, gap = 24;
    float totalBtnW = 5 * btnW + 4 * gap;
    float startX = (ancho - totalBtnW) / 2;
    int btnY = progBar.y + 55;
    std::vector<Rectangle> btns = {
        {startX + 0 * (btnW + gap), (float)btnY, btnW, btnH}, // Prev
        {startX + 1 * (btnW + gap), (float)btnY, btnW, btnH}, // Play
        {startX + 2 * (btnW + gap), (float)btnY, btnW, btnH}, // Pause
        {startX + 3 * (btnW + gap), (float)btnY, btnW, btnH}, // Stop
        {startX + 4 * (btnW + gap), (float)btnY, btnW, btnH}  // Next
    };
    std::vector<const char *> icons = {"<<", ">", "||", "[]", ">>"};

    // Barra de volumen centrada debajo de botones
    float volBarW = 300, volBarH = 16;
    float volBarX = (ancho - volBarW) / 2;
    float volBarY = btnY + btnH + 30;
    Rectangle volBar = {volBarX, volBarY, volBarW, volBarH};

    float volume = 0.7f; // Valor inicial
    float animTime = 0;

    // Variables para barra de progreso
    float progress = 0.0f;
    float duracion = 1.0f; // segundos

    while (!WindowShouldClose())
    {
        animTime += GetFrameTime();

        // ---- Actualiza progreso real si hay canción ----
        Cancion *actual = player.obtenerCancionActual();
        if (actual && player.getDuracion() > 0)
        {
            duracion = player.getDuracion();
            progress = player.getProgreso();
        }
        else
        {
            progress = 0;
            duracion = 1.0f;
        }

        BeginDrawing();
        ClearBackground(fondoXP);

        // Visualizador animado
        DrawRectangleRounded(vis, 0.20f, 18, ColorAlpha(LIGHTGRAY, 0.25f));
        drawVisualizer(vis, 32, animTime);

        // Info canción
        if (actual)
        {
            std::string tituloStr = "Título: " + actual->titulo;
            std::string artistaStr = "Artista: " + actual->artista;
            int tWidth = MeasureText(tituloStr.c_str(), 32);
            int aWidth = MeasureText(artistaStr.c_str(), 22);
            DrawText(tituloStr.c_str(), ancho / 2 - tWidth / 2, infoY, 32, WHITE);
            DrawText(artistaStr.c_str(), ancho / 2 - aWidth / 2, infoY + 38, 22, SKYBLUE);
        }
        else
        {
            std::string txt = "No hay canciones cargadas.";
            int width = MeasureText(txt.c_str(), 24);
            DrawText(txt.c_str(), ancho / 2 - width / 2, infoY + 12, 24, YELLOW);
        }

        // Barra de progreso real
        DrawRectangleRounded(progBar, 0.5f, 8, DARKBLUE);
        DrawRectangleRounded((Rectangle){progBar.x, progBar.y, progress * progBar.width, progBar.height}, 0.5f, 8, SKYBLUE);

        // Muestra el tiempo transcurrido y el total
        char tInit[8], tEnd[8];
        int pos = progress * duracion;
        int min1 = pos / 60, sec1 = pos % 60;
        int min2 = duracion / 60, sec2 = ((int)duracion) % 60;
        sprintf(tInit, "%02d:%02d", min1, sec1);
        sprintf(tEnd, "%02d:%02d", min2, sec2);
        DrawText(tInit, progBar.x, progBar.y + 20, 16, WHITE);
        DrawText(tEnd, progBar.x + progBar.width - 55, progBar.y + 20, 16, WHITE);

        // Botones de control
        Vector2 mouse = GetMousePosition();
        for (int i = 0; i < btns.size(); ++i)
        {
            bool hovered = CheckCollisionPointRec(mouse, btns[i]);
            drawButton(btns[i], icons[i], baseBtn, hoverBtn, hovered);
        }

        // Barra de volumen centrada debajo de los botones
        DrawText("Volumen", volBar.x - 110, volBar.y - 3, 22, WHITE);
        DrawRectangleRounded(volBar, 0.5f, 8, SKYBLUE);
        DrawRectangleRounded((Rectangle){volBar.x, volBar.y, volume * volBar.width, volBar.height}, 0.5f, 8, YELLOW);
        DrawCircle(volBar.x + volume * volBar.width, volBar.y + volBar.height / 2, 11, YELLOW);

        // ----- Listado de canciones (simple, abajo) -----
        int listY = volBar.y + 60;
        int index = 0;
        auto &lista = player.getPlaylist();
        for (const auto &c : lista.obtenerCanciones())
        {
            int isActual = (actual && actual->archivo == c.archivo);
            DrawText((std::to_string(index + 1) + ". " + c.titulo + " - " + c.artista).c_str(),
                     80, listY + 28 * index, 20, isActual ? YELLOW : WHITE);
            index++;
        }

        // ------ Interacciones ------
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Barra de progreso interactiva
            if (CheckCollisionPointRec(mouse, progBar))
            {
                float p = (mouse.x - progBar.x) / progBar.width;
                if (p < 0)
                    p = 0;
                if (p > 1)
                    p = 1;
                player.setProgreso(p);
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
            // Barra de volumen
            if (CheckCollisionPointRec(mouse, volBar))
            {
                float v = (mouse.x - volBar.x) / volBar.width;
                if (v < 0)
                    v = 0;
                if (v > 1)
                    v = 1;
                volume = v;
                player.setVolumen(volume);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
