#include "Player.h"

void __KeyProc(HWND hWnd,int*g_playerx,int*g_playery,int*g_bulletFire,int*g_bulletx,int*g_bullety,int *Totalfire, int*bossalive, int*phazeon,int*ATT)
{
	__move(g_playerx, g_playery,ATT);
	if (GetKeyState(0x5A) & 0x80)
	{
		if (*g_bulletFire == 0)
		{
			*g_bulletx = *g_playerx + 20;
			*g_bullety = *g_playery + 11;
			*g_bulletFire = 1;
			if (*bossalive == 0 && *phazeon == 1)
			{
				*Totalfire += 1;
			}
		}
	}
}

void __move(int* playerx, int* playery,int*ATT)
{
	if (GetKeyState(VK_LEFT) & 0x80)
	{
		if (*playerx > 8)
		{
			*playerx -= 3;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x80)
	{
		if (*playerx < 600)
		{
			*playerx += 5;
		}
	}
	if (GetKeyState(VK_UP) & 0x80)
	{
		if (*playery > 8)
		{
			*playery -= 4;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x80)
	{
		if (*playery < 440)
		{
			*playery += 4;
		}
	}
	if (GetKeyState(VK_ADD) & 0x80)
	{
			*ATT += 1;
	}
}

BOOL Hit(int *isimmo, int*g_playerx, int*g_playery, SURFACEINFO g_sfBack, SURFACEINFO g_sfMon, SURFACEINFO g_sfMonHit)
{
	if (*isimmo == 0)
	{
		return __gePutSprite(g_sfBack.dcSurface,
			*g_playerx, *g_playery, &g_sfMon);
	}
	else //피격시 색반전된 이미지가 대신함
	{
		return __gePutSprite(g_sfBack.dcSurface,
			*g_playerx, *g_playery, &g_sfMonHit);
	}
}

void Oatt(int*kills, int*ATT, int*g_playerMHP, int*g_playerHP)
{
	switch (*kills)
	{
	case 5:
		if (*ATT == 1)
		{
			*ATT += 1;
			*g_playerMHP += 5;
			*g_playerHP += 5;
		}
		break;
	case 15:
		if (*ATT == 2)
		{
			*ATT += 2;
			*g_playerMHP += 5;
			*g_playerHP += 5;
		}
		break;
	case 35:
		if (*ATT == 4)
		{
			*ATT += 2;
			*g_playerMHP += 5;
			*g_playerHP += 5;
		}
		break;
	}
}