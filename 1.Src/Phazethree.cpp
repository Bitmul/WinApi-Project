#include "Phazethree.h"

void threepattern1(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			g_Bbulletx[i] -= 2.8 + i;
			g_Bbullety[i] += 0.4 + (i*0.3);
		}
		else
		{
			g_Bbulletx[i] -= 2.8 + (i - 5);
			g_Bbullety[i] -= 0.2 + ((i - 5)*0.3);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void threepattern2(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			g_Bbulletx[i] -= 3 + i;
			g_Bbullety[i] += 0.5 - (i + 1);
		}
		else
		{
			g_Bbulletx[i] -= 3 + (i - 5);
			g_Bbullety[i] -= 0.35 - ((i - 4));
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void threepattern3(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			g_Bbulletx[i] -= 3 + i;
			g_Bbullety[i] += 0.6 + (i*0.2);
		}
		else if (i >= 3 && i < 7)
		{
			g_Bbulletx[i] -= 3 + (i - 3);
		}
		else if (i >= 7)
		{
			g_Bbulletx[i] -= 3 + (i - 7);
			g_Bbullety[i] -= 0.6 + ((i - 7)*0.2);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void threepattern4(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB, int*g_Bbulletx3, int*g_Bbullety3,int*g_bossx,int*g_bossy)
{
	g_Bbulletx3[0] = *g_bossx;
	g_Bbullety3[0] = *g_bossy + 50;
	g_Bbulletx3[1] = *g_bossx + 14;
	g_Bbullety3[1] = *g_bossy + 77;
	g_Bbulletx3[2] = *g_bossx + 28;
	g_Bbullety3[2] = *g_bossy + 103;
	g_Bbulletx3[3] = *g_bossx + 42;
	g_Bbullety3[3] = *g_bossy + 129;
	g_Bbulletx3[4] = *g_bossx + 42;
	g_Bbullety3[4] = *g_bossy + 367;
	g_Bbulletx3[5] = *g_bossx + 28;
	g_Bbullety3[5] = *g_bossy + 393;
	g_Bbulletx3[6] = *g_bossx + 14;
	g_Bbullety3[6] = *g_bossy + 419;
	g_Bbulletx3[7] = *g_bossx;
	g_Bbullety3[7] = *g_bossy + 445;
}