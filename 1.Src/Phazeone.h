#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

void pattern1(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,int *g_phaze1HP, float*g_Bbulletx, float*g_Bbullety);
void pattern2(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,int *g_phaze1HP, float*g_Bbulletx, float*g_Bbullety);
void pattern3(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,int *g_phaze1HP, float*g_Bbulletx, float*g_Bbullety);
void Bulletcheck(float*g_Bbulletx, float*g_Bbullety, int*BBFire, int*isimmo, int*g_playerHP, int*g_immotime,int*g_playerx,int*g_playery);