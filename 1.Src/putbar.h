#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

BOOL Putbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfBHPT, SURFACEINFO g_sfBack, int g_Gamelayer, int BHP);
BOOL Playerbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfPHPT, SURFACEINFO g_sfBack, int g_playerHP, int g_playerMHP);
BOOL ACCbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfACC, SURFACEINFO g_sfBack, float acc);