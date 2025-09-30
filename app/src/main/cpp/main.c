#include "raymob.h" // This header can replace 'raylib.h' and includes additional functions related to Android.
#include <stdbool.h>

volatile bool g_medi = false;
volatile bool g_notif = false;

JNIEXPORT void JNICALL
Java_com_pmus_tillua_NativeLoader_setmediJNI(JNIEnv *env, jobject thiz, jboolean granted) {
    g_medi = (granted == JNI_TRUE);
}

JNIEXPORT void JNICALL
Java_com_pmus_tillua_NativeLoader_setnotifJNI(JNIEnv *env, jobject thiz, jboolean granted) {
    g_notif = (granted == JNI_TRUE);
}

int main(void)
{
    InitWindow(0, 0, "pmus");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("PMUS INTIAL APP", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2, 70, RED);
        if(g_medi)
            DrawText("We got media permission", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 120, 45, GREEN);
        else
            DrawText("We don't have media permission", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 120, 45, RED);
        if(g_notif)
            DrawText("We got notification permission", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 170, 45, GREEN);
        else
            DrawText("We don't have notification permission", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 170, 45, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}