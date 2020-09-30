#include "putbar.h"

BOOL Putbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfBHPT, SURFACEINFO g_sfBack, int g_Gamelayer, int BHP)
{
	float HPper = 0;
	__gePutSprite(g_sfBack.dcSurface,
		15, 430, &g_sfBHPT);
	switch (g_Gamelayer)
	{
	case 1:
		HPper = (BHP / 300.0); // 150 /300 = 0.5,즉 50 %.
		HPper = HPper * (float)psInfo->nWidth; //0.5 * 그림의 폭(280) = 즉 140
		HPper = psInfo->nWidth - HPper;
		break;
	case 2:
		HPper = (BHP / 1000.0);
		HPper = HPper * (float)psInfo->nWidth;
		HPper = psInfo->nWidth - HPper;
		break;
	case 3:
		HPper = (BHP / 2000.0);
		HPper = HPper * (float)psInfo->nWidth;
		HPper = psInfo->nWidth - HPper;
		break;
	}
	return TransparentBlt(dcDst,
		x, y, psInfo->nWidth - HPper, psInfo->nHeight, //체력바 크기 조절
		psInfo->dcSurface,
		0, 0, psInfo->nWidth - HPper, psInfo->nHeight, //안 건드려도 됨
		psInfo->crColorKey);
}

BOOL Playerbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfPHPT, SURFACEINFO g_sfBack, int g_playerHP, int g_playerMHP)
{
	float PHPper = 0;
	PHPper = (float)g_playerHP / (float)g_playerMHP;
	PHPper = PHPper * (float)psInfo->nWidth;
	PHPper = psInfo->nWidth - PHPper;
	__gePutSprite(g_sfBack.dcSurface,
		x, y, &g_sfPHPT);
	if (PHPper >= 150)
	{
		return TransparentBlt(dcDst,
			x, y, psInfo->nWidth, psInfo->nHeight, //체력바 크기 조절
			psInfo->dcSurface,
			0, 0, psInfo->nWidth, psInfo->nHeight, //안 건드려도 됨
			psInfo->crColorKey);
	}
	else
	{
		return TransparentBlt(dcDst,
			x, y, psInfo->nWidth - PHPper, psInfo->nHeight, //체력바 크기 조절
			psInfo->dcSurface,
			0, 0, psInfo->nWidth - PHPper, psInfo->nHeight, //안 건드려도 됨
			psInfo->crColorKey);
	}
}

BOOL ACCbar(HDC dcDst, int x, int y, SURFACEINFO* psInfo, SURFACEINFO g_sfACCT, SURFACEINFO g_sfBack, float acc)
{
	acc = acc * (float)psInfo->nWidth;
	acc = psInfo->nWidth - acc;
	__gePutSprite(g_sfBack.dcSurface,
		x-3, y-3, &g_sfACCT);
		return TransparentBlt(dcDst,
			x, y, psInfo->nWidth - acc, psInfo->nHeight, //체력바 크기 조절
			psInfo->dcSurface,
			0, 0, psInfo->nWidth - acc, psInfo->nHeight, //안 건드려도 됨
			psInfo->crColorKey);
}

