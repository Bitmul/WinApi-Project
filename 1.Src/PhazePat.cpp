#include "PhazePat.h"

void ___aInit(HDC hdc, SURFACEINFO &g_sfBack,SURFACEINFO &g_sfTitle,SURFACEINFO &g_sfGameover,SURFACEINFO &g_sfBG,SURFACEINFO &g_sfBG2,SURFACEINFO &g_sfBG3,
	SURFACEINFO &g_sfPhaze,SURFACEINFO &g_sfMon,SURFACEINFO &g_sfMonHit,SURFACEINFO &g_sfHos,SURFACEINFO &g_sfBul,SURFACEINFO &g_sfBoss,SURFACEINFO &g_sfBoss2,
	SURFACEINFO &g_sfBoss3,SURFACEINFO &g_sfBossB,SURFACEINFO &g_sfBossHit,SURFACEINFO &g_sfBoss2Hit,SURFACEINFO &g_sfBoss3Hit,SURFACEINFO &g_sfLaserR,SURFACEINFO &g_sfLaserF,
	SURFACEINFO &g_sfVLaserR,SURFACEINFO &g_sfVLaserF,SURFACEINFO &g_sfBHPT,SURFACEINFO &g_sfBHP,SURFACEINFO &g_sfPHPT,SURFACEINFO &g_sfPHP, SURFACEINFO &g_sfCLEAR,
    SURFACEINFO &g_sfACC,SURFACEINFO &g_sfACCT)
{
	srand((unsigned)time(NULL));
	////
	__geCreateBackBuffer(hdc, 640, 480, 32, &g_sfBack);

	////
	__geSetImgSurface(&g_sfTitle);
	g_sfTitle.hBmp = __geBmpFile2BmpHandle("Sprites\\타이틀.bmp");
	__geLoadSurface(hdc, &g_sfTitle);

	__geSetImgSurface(&g_sfBG);
	g_sfBG.hBmp = __geBmpFile2BmpHandle("Sprites\\배경1.bmp");
	__geLoadSurface(hdc, &g_sfBG);

	__geSetImgSurface(&g_sfBG2);
	g_sfBG2.hBmp = __geBmpFile2BmpHandle("Sprites\\배경2.bmp");
	__geLoadSurface(hdc, &g_sfBG2);

	__geSetImgSurface(&g_sfBG3);
	g_sfBG3.hBmp = __geBmpFile2BmpHandle("Sprites\\배경3.bmp");
	__geLoadSurface(hdc, &g_sfBG3);

	__geSetImgSurface(&g_sfPhaze);
	g_sfPhaze.hBmp = __geBmpFile2BmpHandle("Sprites\\페이즈 전환.bmp");
	__geLoadSurface(hdc, &g_sfPhaze);

	__geSetSprSurface(&g_sfMon, RGB(0, 255, 0));
	g_sfMon.hBmp = __geBmpFile2BmpHandle("Sprites\\플레이어.bmp");
	__geLoadSurface(hdc, &g_sfMon);

	__geSetSprSurface(&g_sfMonHit, RGB(255, 0, 255));
	g_sfMonHit.hBmp = __geBmpFile2BmpHandle("Sprites\\플레이어 피격.bmp");
	__geLoadSurface(hdc, &g_sfMonHit);

	__geSetSprSurface(&g_sfBul, RGB(0, 255, 0));
	g_sfBul.hBmp = __geBmpFile2BmpHandle("Sprites\\총알.bmp");
	__geLoadSurface(hdc, &g_sfBul);

	__geSetSprSurface(&g_sfHos, RGB(0, 255, 0));
	g_sfHos.hBmp = __geBmpFile2BmpHandle("Sprites\\히오스.bmp");
	__geLoadSurface(hdc, &g_sfHos);

	__geSetSprSurface(&g_sfBoss, RGB(0, 255, 0));
	g_sfBoss.hBmp = __geBmpFile2BmpHandle("Sprites\\보스.bmp");
	__geLoadSurface(hdc, &g_sfBoss);

	__geSetSprSurface(&g_sfBoss2, RGB(0, 255, 0));
	g_sfBoss2.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 2페이즈.bmp");
	__geLoadSurface(hdc, &g_sfBoss2);

	__geSetSprSurface(&g_sfBoss3, RGB(0, 255, 0));
	g_sfBoss3.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 3페이즈.bmp");
	__geLoadSurface(hdc, &g_sfBoss3);

	__geSetSprSurface(&g_sfBossB, RGB(0, 255, 0));
	g_sfBossB.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 탄환.bmp");
	__geLoadSurface(hdc, &g_sfBossB);

	__geSetSprSurface(&g_sfBossHit, RGB(255, 0, 255));
	g_sfBossHit.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 피격.bmp");
	__geLoadSurface(hdc, &g_sfBossHit);

	__geSetSprSurface(&g_sfBoss2Hit, RGB(255, 0, 255));
	g_sfBoss2Hit.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 2페이즈 피격.bmp");
	__geLoadSurface(hdc, &g_sfBoss2Hit);

	__geSetSprSurface(&g_sfBoss3Hit, RGB(255, 0, 255));
	g_sfBoss3Hit.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 3페이즈 피격.bmp");
	__geLoadSurface(hdc, &g_sfBoss3Hit);

	__geSetSprSurface(&g_sfGameover, RGB(0, 255, 0));
	g_sfGameover.hBmp = __geBmpFile2BmpHandle("Sprites\\게임 오버.bmp");
	__geLoadSurface(hdc, &g_sfGameover);

	__geSetSprSurface(&g_sfLaserR, RGB(0, 255, 0));
	g_sfLaserR.hBmp = __geBmpFile2BmpHandle("Sprites\\게이저 준비.bmp");
	__geLoadSurface(hdc, &g_sfLaserR);

	__geSetSprSurface(&g_sfLaserF, RGB(0, 255, 0));
	g_sfLaserF.hBmp = __geBmpFile2BmpHandle("Sprites\\게이저 발사.bmp");
	__geLoadSurface(hdc, &g_sfLaserF);

	__geSetSprSurface(&g_sfVLaserR, RGB(0, 255, 0));
	g_sfVLaserR.hBmp = __geBmpFile2BmpHandle("Sprites\\세로 게이저 준비.bmp");
	__geLoadSurface(hdc, &g_sfVLaserR);

	__geSetSprSurface(&g_sfVLaserF, RGB(0, 255, 0));
	g_sfVLaserF.hBmp = __geBmpFile2BmpHandle("Sprites\\세로 게이저 발사.bmp");
	__geLoadSurface(hdc, &g_sfVLaserF);

	__geSetSprSurface(&g_sfBHPT, RGB(0, 255, 0));
	g_sfBHPT.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 체력바.bmp");
	__geLoadSurface(hdc, &g_sfBHPT);

	__geSetSprSurface(&g_sfBHP, RGB(0, 255, 0));
	g_sfBHP.hBmp = __geBmpFile2BmpHandle("Sprites\\보스 체력.bmp");
	__geLoadSurface(hdc, &g_sfBHP);

	__geSetSprSurface(&g_sfPHPT, RGB(0, 255, 0));
	g_sfPHPT.hBmp = __geBmpFile2BmpHandle("Sprites\\플레이어 체력바.bmp");
	__geLoadSurface(hdc, &g_sfPHPT);

	__geSetSprSurface(&g_sfPHP, RGB(0, 255, 0));
	g_sfPHP.hBmp = __geBmpFile2BmpHandle("Sprites\\플레이어 체력.bmp");
	__geLoadSurface(hdc, &g_sfPHP);

	__geSetSprSurface(&g_sfACCT, RGB(0, 255, 0));
	g_sfACCT.hBmp = __geBmpFile2BmpHandle("Sprites\\정확도.bmp");
	__geLoadSurface(hdc, &g_sfACCT);

	__geSetSprSurface(&g_sfACC, RGB(0, 255, 0));
	g_sfACC.hBmp = __geBmpFile2BmpHandle("Sprites\\정확도 게이지.bmp");
	__geLoadSurface(hdc, &g_sfACC);

	__geSetSprSurface(&g_sfCLEAR, RGB(0, 255, 0));
	g_sfCLEAR.hBmp = __geBmpFile2BmpHandle("Sprites\\클리어.bmp");
	__geLoadSurface(hdc, &g_sfCLEAR);

}
void ___aDestroyAll(SURFACEINFO &g_sfBack, SURFACEINFO &g_sfTitle, SURFACEINFO &g_sfGameover, SURFACEINFO &g_sfBG, SURFACEINFO &g_sfBG2, SURFACEINFO &g_sfBG3,
	SURFACEINFO &g_sfPhaze, SURFACEINFO &g_sfMon, SURFACEINFO &g_sfMonHit, SURFACEINFO &g_sfHos, SURFACEINFO &g_sfBul, SURFACEINFO &g_sfBoss, SURFACEINFO &g_sfBoss2,
	SURFACEINFO &g_sfBoss3, SURFACEINFO &g_sfBossB, SURFACEINFO &g_sfBossHit, SURFACEINFO &g_sfBoss2Hit, SURFACEINFO &g_sfBoss3Hit, SURFACEINFO &g_sfLaserR, SURFACEINFO &g_sfLaserF,
	SURFACEINFO &g_sfVLaserR, SURFACEINFO &g_sfVLaserF, SURFACEINFO &g_sfBHPT, SURFACEINFO &g_sfBHP, SURFACEINFO &g_sfPHPT, SURFACEINFO &g_sfPHP, SURFACEINFO &g_sfCLEAR,
	SURFACEINFO &g_sfACC, SURFACEINFO &g_sfACCT)
{
	__geReleaseSurface(&g_sfHos);
	__geReleaseSurface(&g_sfMon);
	__geReleaseSurface(&g_sfBG);
	__geReleaseSurface(&g_sfBG2);
	__geReleaseSurface(&g_sfBG3);
	__geReleaseSurface(&g_sfBack);
	__geReleaseSurface(&g_sfBul);
	__geReleaseSurface(&g_sfBoss);
	__geReleaseSurface(&g_sfBossB);
	__geReleaseSurface(&g_sfBoss2);
	__geReleaseSurface(&g_sfBoss3);
	__geReleaseSurface(&g_sfBossHit);
	__geReleaseSurface(&g_sfBoss2Hit);
	__geReleaseSurface(&g_sfBoss3Hit);
	__geReleaseSurface(&g_sfTitle);
	__geReleaseSurface(&g_sfGameover);
	__geReleaseSurface(&g_sfPhaze);
	__geReleaseSurface(&g_sfLaserR);
	__geReleaseSurface(&g_sfLaserF);
	__geReleaseSurface(&g_sfVLaserR);
	__geReleaseSurface(&g_sfVLaserF);
	__geReleaseSurface(&g_sfBHPT);
	__geReleaseSurface(&g_sfBHP);
	__geReleaseSurface(&g_sfPHPT);
	__geReleaseSurface(&g_sfPHP);
	__geReleaseSurface(&g_sfACCT);
	__geReleaseSurface(&g_sfACC);
	__geReleaseSurface(&g_sfCLEAR);
}
void Spawn(int g_monsterx[], int g_monstery[], int * pause, int*firstspawn, int*g_mons)
{
	int i = 0;
	int randpat = 0;
	if (*pause == 0)
	{
		randpat = rand() % 4 + 1;
		switch (randpat)
		{
		case 1:
			for (i = 0; i < 5; i++)//총 5마리
			{
				g_monsterx[i] = 800 + i * 60;
				g_monstery[i] = 380 - i * 80;
				*g_mons += 1; //방 안의 개체수 +1
			}
			*firstspawn = 1; //g_mons가 0이 될때까지 1인 상태로 있는다
			break;
		case 2:
			for (i = 0; i < 5; i++)//총 5마리
			{
				g_monsterx[i] = 1100 - i * 60;
				g_monstery[i] = 380 - i * 80;
				*g_mons += 1; //방 안의 개체수 +1
			}
			*firstspawn = 1; //g_mons가 0이 될때까지 1인 상태로 있는다
			break;
		case 3:
			for (i = 0; i < 5; i++)//총 5마리
			{
				if (i < 3)
				{
					g_monsterx[i] = 800 + i * 60;
				}
				else { g_monsterx[i] = 980 - (i - 1) * 60; }
				g_monstery[i] = 380 - i * 80;
				*g_mons += 1; //방 안의 개체수 +1
			}
			*firstspawn = 1; //g_mons가 0이 될때까지 1인 상태로 있는다
			break;
		case 4:
			for (i = 0; i < 5; i++)//총 5마리
			{
				switch (i)
				{
				case 0:
					g_monsterx[i] = 800;
					g_monstery[i] = 220;
					break;
				case 1:
					g_monsterx[i] = 860;
					g_monstery[i] = 300;
					break;
				case 2:
					g_monsterx[i] = 860;
					g_monstery[i] = 140;
					break;
				case 3:
					g_monsterx[i] = 920;
					g_monstery[i] = 380;
					break;
				case 4:
					g_monsterx[i] = 920;
					g_monstery[i] = 60;
					break;
				}
				*g_mons += 1; //방 안의 개체수 +1
			}
			*firstspawn = 1; //g_mons가 0이 될때까지 1인 상태로 있는다
			break;
		}
	}
}
void BHsprite(int g_Gamelayer, int*g_bossimmo, int*g_bossx, int*g_bossy, SURFACEINFO g_sfBack, SURFACEINFO g_sfBoss, SURFACEINFO g_sfBossHit, SURFACEINFO g_sfBoss2, SURFACEINFO g_sfBoss2Hit, SURFACEINFO g_sfBoss3, SURFACEINFO g_sfBoss3Hit)
{
	switch (g_Gamelayer)
	{
	case 1:
		if (*g_bossimmo == 0)
		{
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBoss);
		}
		else {
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBossHit);
		}
		break;
	case 2:
		if (*g_bossimmo == 0)
		{
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBoss2);
		}
		else {
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBoss2Hit);
		}
		break;
	case 3:
		if (*g_bossimmo == 0)
		{
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBoss3);
		}
		else {
			__gePutSprite(g_sfBack.dcSurface,
				*g_bossx, *g_bossy, &g_sfBoss3Hit);
		}
		break;
	}
}

void __Displaytext(SURFACEINFO g_sfBack, int*kills, int*ATT, int *g_playerHP, int*g_playerMHP, int*g_Gamelayer, int*g_phaze1HP, int*g_phaze2HP, int*g_phaze3HP, int*bossHmove,
	int*g_phaze1Die, int*g_phaze2Die, int*g_phaze3Die,float*acc,int*Score)
{
	char  strBuff[100];
	TCHAR strBufff[255];
	wsprintf(strBuff, "Kills : %d", *kills);
	TextOut(g_sfBack.dcSurface, 10, 60,
		strBuff, (int)strlen(strBuff));
	wsprintf(strBuff, "ATT : 1 + %d", *ATT - 1);
	TextOut(g_sfBack.dcSurface, 70, 60,
		strBuff, (int)strlen(strBuff));
	wsprintf(strBuff, "HP : %d / %d", *g_playerHP, *g_playerMHP);
	TextOut(g_sfBack.dcSurface, 47, 9,
		strBuff, (int)strlen(strBuff));
	wsprintf(strBuff, "Score : %d", *Score);
	TextOut(g_sfBack.dcSurface, 10, 80,
		strBuff, (int)strlen(strBuff));
	sprintf(strBuff, "%.2f %%", *acc * 100);
	TextOut(g_sfBack.dcSurface, 35, 36,
		strBuff,strlen(strBuff));
	if (*bossHmove > 0)
	{
		switch (*g_Gamelayer)
		{
			
		case 1:
			if (*g_phaze1Die == 0)
			{
				wsprintf(strBuff, "Boss HP : %d / 300", *g_phaze1HP);
				TextOut(g_sfBack.dcSurface, 250, 435,
					strBuff, (int)strlen(strBuff));
			}
			break;
		case 2:
			if (*g_phaze2Die == 0)
			{
				wsprintf(strBuff, "Boss HP : %d / 1000", *g_phaze2HP);
				TextOut(g_sfBack.dcSurface, 250, 435,
					strBuff, (int)strlen(strBuff));
			}
			break;
		case 3:
			if (*g_phaze3Die == 0)
			{
				wsprintf(strBuff, "Boss HP : %d / 2000", *g_phaze3HP);
				TextOut(g_sfBack.dcSurface, 250, 435,
					strBuff, (int)strlen(strBuff));
			}
			break;
		}
	}
}