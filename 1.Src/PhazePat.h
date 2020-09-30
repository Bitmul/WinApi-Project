#include <windows.h>
#include <stdio.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

void Spawn(int g_monsterx[], int g_monstery[], int * pause, int*firstspawn, int*g_mons);
void BHsprite(int g_Gamelayer, int*g_bossimmo, int*g_bossx, int*g_bossy, SURFACEINFO g_sfBack, SURFACEINFO g_sfBoss, SURFACEINFO g_sfBossHit, SURFACEINFO g_sfBoss2, SURFACEINFO g_sfBoss2Hit, SURFACEINFO g_sfBoss3, SURFACEINFO g_sfBoss3Hit);
void __Displaytext(SURFACEINFO g_sfBack, int*kills, int*ATT, int *g_playerHP, int*g_playerMHP, int*g_Gamelayer, int*g_phaze1HP, int*g_phaze2HP, int*g_phaze3HP, int*bossHmove, int*g_phaze1Die, 
	int*g_phaze2Die, int*g_phaze3Die,float*acc, int*Score);
void ___aInit(HDC hdc, SURFACEINFO &g_sfBack,			// 후  면 표면
	SURFACEINFO &g_sfTitle,			// 타이틀 표면
	SURFACEINFO &g_sfGameover,	    // 게임 오버 표면
	SURFACEINFO &g_sfBG,			// 페이즈 1배경 표면
	SURFACEINFO &g_sfBG2,				// 페이즈 2배경 표면 
	SURFACEINFO &g_sfBG3,			// 페이즈 3배경 표면 
	SURFACEINFO &g_sfPhaze,				// 페이즈  변경 표면
	SURFACEINFO &g_sfMon,			// 플레이어 표면
	SURFACEINFO &g_sfMonHit,		// 플레이어 피격 표면
	SURFACEINFO &g_sfHos,			// 몬스터 표면
	SURFACEINFO &g_sfBul,			// 총알 표면
	SURFACEINFO &g_sfBoss,          // 보스 1페이즈 표면
	SURFACEINFO &g_sfBoss2,           // 보스 2페이즈 표면
	SURFACEINFO &g_sfBoss3,           // 보스 3페이즈 표면
	SURFACEINFO &g_sfBossB,           // 보스 총알 표면
	SURFACEINFO &g_sfBossHit,           // 보스 1페이즈 피격
	SURFACEINFO &g_sfBoss2Hit,          // 보스 2페이즈 피격
	SURFACEINFO &g_sfBoss3Hit,           // 보스 3페이즈 피격
	SURFACEINFO &g_sfLaserR,           // 레이저 발사 준비 표면
	SURFACEINFO &g_sfLaserF,           // 레이저 발사 표면
	SURFACEINFO &g_sfVLaserR,           // 세로 레이저 발사 준비 표면
	SURFACEINFO &g_sfVLaserF,           // 세로 레이저 발사 표면
	SURFACEINFO &g_sfBHPT,           // 보스 체력 틀 표면
	SURFACEINFO &g_sfBHP,           // 보스 체력바 표면
	SURFACEINFO &g_sfPHPT,           // 플레이어 체력 틀 표면
	SURFACEINFO &g_sfPHP,          // 플레이어 체력바 표면
	SURFACEINFO &g_sfCLEAR,        //클리어 표면
	SURFACEINFO &g_sfACC,           // 정확도 바 표면
	SURFACEINFO &g_sfACCT           //정확도 틀 표면
);
void ___aDestroyAll(SURFACEINFO &g_sfBack, SURFACEINFO &g_sfTitle, SURFACEINFO &g_sfGameover, SURFACEINFO &g_sfBG, SURFACEINFO &g_sfBG2, SURFACEINFO &g_sfBG3,
	SURFACEINFO &g_sfPhaze, SURFACEINFO &g_sfMon, SURFACEINFO &g_sfMonHit, SURFACEINFO &g_sfHos, SURFACEINFO &g_sfBul, SURFACEINFO &g_sfBoss, SURFACEINFO &g_sfBoss2,
	SURFACEINFO &g_sfBoss3, SURFACEINFO &g_sfBossB, SURFACEINFO &g_sfBossHit, SURFACEINFO &g_sfBoss2Hit, SURFACEINFO &g_sfBoss3Hit, SURFACEINFO &g_sfLaserR, SURFACEINFO &g_sfLaserF,
	SURFACEINFO &g_sfVLaserR, SURFACEINFO &g_sfVLaserF, SURFACEINFO &g_sfBHPT, SURFACEINFO &g_sfBHP, SURFACEINFO &g_sfPHPT, SURFACEINFO &g_sfPHP, SURFACEINFO &g_sfCLEAR,
	SURFACEINFO &g_sfACC, SURFACEINFO &g_sfACCT);