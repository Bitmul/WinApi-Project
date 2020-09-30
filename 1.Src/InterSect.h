#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

void _InterSect(int * g_monsterx, int*g_monstery, int*g_mons, SURFACEINFO g_sfBack, SURFACEINFO g_sfHos, int *g_playerx, int*g_playery, int *isimmo, int*g_playerHP, int*g_immotime);
void mobhit(int * g_monsterx, int *g_monstery, int*g_bullety, int*g_bulletx, int *kills, int*g_mons, int*g_playerHP, int*g_playerMHP,int*acchit,int*Totalhit, float*acc, int*Score, int*bossalive, int*phazeon,
	int*g_bulletFire);
void Fire(int *g_bulletFire, int*g_bulletx, int*g_bullety, SURFACEINFO g_sfBack, SURFACEINFO g_sfBul,int *acchit, int*Totalhit, float*acc,int*bossalive,int*phazeon);
void Bosshit(int*bossHmove, RECT &Brt, RECT &Krt, RECT &rt, int*g_nphze,int*ATT, int*g_bossimmo, int*g_bossimmotime, int*g_bullety,
	int*isimmo, int*g_playerHP, int*g_immotime,int*acchit, int*Totalhit, float*acc);
void Getacc(float*acc, int*acchit, int*Totalfire);