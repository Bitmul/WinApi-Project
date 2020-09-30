#include "Phazeone.h"

void pattern1(SURFACEINFO g_sfBack,SURFACEINFO g_sfBossB,int *g_phaze1HP,float*g_Bbulletx,float*g_Bbullety)
{
	RECT rcTEMP,KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 4 + i;
			}
			else
			{
				g_Bbulletx[i] -= 11;
				g_Bbullety[i] += 0.1 + (i*0.2);
			}
			g_Bbullety[i] += 0.1 + (i*0.2);
		}
		else
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 4 + (i - 5);
			}
			else {
				g_Bbulletx[i] -= 11;
				g_Bbullety[i] -= 0.1 + ((i - 5)*0.2);
			}
			g_Bbullety[i] -= 0.1 + ((i - 5)*0.2);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void pattern2(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,int *g_phaze1HP, float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 5 + i;
			}
			else
			{
				g_Bbulletx[i] -= 5;
			}

			g_Bbullety[i] += 0.25 - (i + 1);
		}
		else
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 5 + (i - 5);
			}
			else { g_Bbulletx[i] -= 5; }
			g_Bbullety[i] -= 0.25 - ((i - 4));
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void pattern3(SURFACEINFO g_sfBack, SURFACEINFO g_sfBossB,int *g_phaze1HP, float*g_Bbulletx, float*g_Bbullety)
{
	RECT rcTEMP, KBrt[15];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 5 + i;
			}
			else {
				g_Bbulletx[i] -= 9;
				g_Bbullety[i] += 1 + (i*0.2);
			}
			g_Bbullety[i] += 0.6 + (i*0.2);
		}
		else if (i >= 3 && i<7)
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 5 + (i - 3);
			}
			else { g_Bbulletx[i] -= 9; }
		}
		else if (i >= 7)
		{
			if (*g_phaze1HP < 150)
			{
				g_Bbulletx[i] -= 5 + (i - 7);
			}
			else {
				g_Bbulletx[i] -= 9;
				g_Bbullety[i] -= 1 + ((i - 7)*0.2);
			}
			g_Bbullety[i] -= 0.6 + ((i - 7)*0.2);
		}
		__gePutSprite(g_sfBack.dcSurface,
			g_Bbulletx[i], g_Bbullety[i], &g_sfBossB);
	}
}

void Bulletcheck(float*g_Bbulletx, float*g_Bbullety, int*BBFire, int*isimmo, int*g_playerHP, int*g_immotime,int*g_playerx,int*g_playery)
{
	int i = 0;
	RECT rcTEMP, KBrt[15],rt;
	for (i = 0; i < 10; i++)
	{
		if (g_Bbulletx[i] < 0 && g_Bbulletx[i] > -600)
		{
			g_Bbulletx[i] = -610;
			g_Bbullety[i] = -610;
			*BBFire -= 1;
		}
		SetRect(&KBrt[i], g_Bbulletx[i], g_Bbullety[i], g_Bbulletx[i] + 12, g_Bbullety[i] + 12);
		SetRect(&rt, *g_playerx + 4, *g_playery + 4, *g_playerx + 20, *g_playery + 16);//플레이어 피격
		if (IntersectRect(&rcTEMP, &rt, &KBrt[i])) //충돌판정
		{
			if (*isimmo == 0) //무적시간
			{
				*g_playerHP -= 2; //체력을 2깎음
				*g_immotime = 80;
				*isimmo = 1; //피격무적발동
			}
		}
	}
}