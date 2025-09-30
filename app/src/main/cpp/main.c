#include "raymob.h" // This header can replace 'raylib.h' and includes additional functions related to Android.

int main(void)
{
    InitWindow(0, 0, "pmus");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("PMUS INTIAL APP", GetScreenWidth() / 2, GetScreenHeight() / 2, 70, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}