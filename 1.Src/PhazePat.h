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
void ___aInit(HDC hdc, SURFACEINFO &g_sfBack,			// ��  �� ǥ��
	SURFACEINFO &g_sfTitle,			// Ÿ��Ʋ ǥ��
	SURFACEINFO &g_sfGameover,	    // ���� ���� ǥ��
	SURFACEINFO &g_sfBG,			// ������ 1��� ǥ��
	SURFACEINFO &g_sfBG2,				// ������ 2��� ǥ�� 
	SURFACEINFO &g_sfBG3,			// ������ 3��� ǥ�� 
	SURFACEINFO &g_sfPhaze,				// ������  ���� ǥ��
	SURFACEINFO &g_sfMon,			// �÷��̾� ǥ��
	SURFACEINFO &g_sfMonHit,		// �÷��̾� �ǰ� ǥ��
	SURFACEINFO &g_sfHos,			// ���� ǥ��
	SURFACEINFO &g_sfBul,			// �Ѿ� ǥ��
	SURFACEINFO &g_sfBoss,          // ���� 1������ ǥ��
	SURFACEINFO &g_sfBoss2,           // ���� 2������ ǥ��
	SURFACEINFO &g_sfBoss3,           // ���� 3������ ǥ��
	SURFACEINFO &g_sfBossB,           // ���� �Ѿ� ǥ��
	SURFACEINFO &g_sfBossHit,           // ���� 1������ �ǰ�
	SURFACEINFO &g_sfBoss2Hit,          // ���� 2������ �ǰ�
	SURFACEINFO &g_sfBoss3Hit,           // ���� 3������ �ǰ�
	SURFACEINFO &g_sfLaserR,           // ������ �߻� �غ� ǥ��
	SURFACEINFO &g_sfLaserF,           // ������ �߻� ǥ��
	SURFACEINFO &g_sfVLaserR,           // ���� ������ �߻� �غ� ǥ��
	SURFACEINFO &g_sfVLaserF,           // ���� ������ �߻� ǥ��
	SURFACEINFO &g_sfBHPT,           // ���� ü�� Ʋ ǥ��
	SURFACEINFO &g_sfBHP,           // ���� ü�¹� ǥ��
	SURFACEINFO &g_sfPHPT,           // �÷��̾� ü�� Ʋ ǥ��
	SURFACEINFO &g_sfPHP,          // �÷��̾� ü�¹� ǥ��
	SURFACEINFO &g_sfCLEAR,        //Ŭ���� ǥ��
	SURFACEINFO &g_sfACC,           // ��Ȯ�� �� ǥ��
	SURFACEINFO &g_sfACCT           //��Ȯ�� Ʋ ǥ��
);
void ___aDestroyAll(SURFACEINFO &g_sfBack, SURFACEINFO &g_sfTitle, SURFACEINFO &g_sfGameover, SURFACEINFO &g_sfBG, SURFACEINFO &g_sfBG2, SURFACEINFO &g_sfBG3,
	SURFACEINFO &g_sfPhaze, SURFACEINFO &g_sfMon, SURFACEINFO &g_sfMonHit, SURFACEINFO &g_sfHos, SURFACEINFO &g_sfBul, SURFACEINFO &g_sfBoss, SURFACEINFO &g_sfBoss2,
	SURFACEINFO &g_sfBoss3, SURFACEINFO &g_sfBossB, SURFACEINFO &g_sfBossHit, SURFACEINFO &g_sfBoss2Hit, SURFACEINFO &g_sfBoss3Hit, SURFACEINFO &g_sfLaserR, SURFACEINFO &g_sfLaserF,
	SURFACEINFO &g_sfVLaserR, SURFACEINFO &g_sfVLaserF, SURFACEINFO &g_sfBHPT, SURFACEINFO &g_sfBHP, SURFACEINFO &g_sfPHPT, SURFACEINFO &g_sfPHP, SURFACEINFO &g_sfCLEAR,
	SURFACEINFO &g_sfACC, SURFACEINFO &g_sfACCT);