#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

void __move(int* playerx, int* playery,int*ATT);
BOOL Hit(int *isimmo, int*g_playerx, int*g_playery, SURFACEINFO g_sfBack, SURFACEINFO g_sfMon, SURFACEINFO g_sfMonHit);
void __KeyProc(HWND hWnd, int*g_playerx, int*g_playery, int*g_bulletFire, int*g_bulletx, int*g_bullety,int*Totalfire, int*bossalive, int*phazeon,int*ATT);
void Oatt(int*kills, int*ATT, int*g_playerMHP, int*g_playerHP);