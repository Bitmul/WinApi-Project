#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

void threepattern1(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety);
void threepattern2(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety);
void threepattern3(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety);
void threepattern4(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, int*g_Bbulletx3, int*g_Bbullety3, int*g_bossx, int*g_bossy);