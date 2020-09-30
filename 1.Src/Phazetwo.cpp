#include "Phazeone.h"

void twopattern1(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			g_Bbulletx[i] -= 4 + i;
			g_Bbullety[i] += 0.1 + (i*0.2);
		}
		else
		{
			g_Bbulletx[i] -= 4 + (i - 5);
			g_Bbullety[i] -= 0.1 + ((i - 5)*0.2);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void twopattern2(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			g_Bbulletx[i] -= 4 + i;
			g_Bbullety[i] += 0.25 - (i + 1);
		}
		else
		{
			g_Bbulletx[i] -= 4 + (i - 5);
			g_Bbullety[i] -= 0.25 - ((i - 4));
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void twopattern3(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			g_Bbulletx[i] -= 3 + i;
			g_Bbullety[i] += 1 + (i*0.3);
		}
		else if (i >= 3 && i < 7)
		{
			g_Bbulletx[i] -= 3 + (i - 3);
		}
		else if (i >= 7)
		{
			g_Bbulletx[i] -= 3 + (i - 7);
			g_Bbullety[i] -= 1 + ((i - 7)*0.3);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}