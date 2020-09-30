#include "InterSect.h"
void _InterSect(int * g_monsterx, int*g_monstery, int*g_mons, SURFACEINFO g_sfBack, SURFACEINFO g_sfHos, int *g_playerx, int*g_playery, int *isimmo, int*g_playerHP, int*g_immotime)
{
	RECT rt, mrt, rcTEMP;
	if (*g_monsterx < -20 && *g_monstery > -30) //�� ������ ���� ����� ���������� �������� ����� ��ü�� -1
	{
		*g_monstery = -50;
		*g_mons -= 1;

	}
	else //�� ������ ������ ���� ����� ��� �̵��Ѵ�
	{
		*g_monsterx -= 4;
		__gePutSprite(g_sfBack.dcSurface,
			*g_monsterx, *g_monstery, &g_sfHos);
		SetRect(&rt, *g_playerx, *g_playery + 4, *g_playerx + 20, *g_playery + 14);//�÷��̾� �ǰ�
		SetRect(&mrt, *g_monsterx - 15, *g_monstery - 15, *g_monsterx + 26, *g_monstery + 15); //�̵��� ����� �ǰ������� ����
		if (IntersectRect(&rcTEMP, &rt, &mrt)) //�浹����
		{
			if (*isimmo == 0) //�����ð�
			{
				*g_playerHP -= 1; //ü���� 1����
				*g_immotime = 80;
				*isimmo = 1; //�ǰݹ����ߵ�
			}
		}
	}
}

void mobhit(int * g_monsterx, int *g_monstery, int*g_bullety, int*g_bulletx, int *kills, int*g_mons, int*g_playerHP, int*g_playerMHP,int*acchit, int*Totalhit, float*acc,int*Score, int*bossalive, int*phazeon
,int*g_bulletFire)
{
	RECT Brt, mrt, rcTEMP;
	SetRect(&mrt, *g_monsterx - 15, *g_monstery, *g_monsterx + 15, *g_monstery + 30); //�� �浹����

	if (*g_bullety > -119)
	{
		SetRect(&Brt, *g_bulletx - 30, *g_bullety - 3, *g_bulletx + 24, *g_bullety + 3);
	}
	if (IntersectRect(&rcTEMP, &mrt, &Brt) && *g_monsterx < 730) //�浹����
	{
		*g_bullety = -120;
		*g_bulletFire = 0;
		*g_monstery = -50; //���� �Ҹ�
		*kills += 1;
		*g_mons -= 1;
		if (*bossalive == 0 && *phazeon == 1)
		{
			*acchit += 1;
		}
		*Score += 20;
		Getacc(acc, acchit, Totalhit);
		int HealItem = 0;
		HealItem = rand() % 100 + 1;
		if (HealItem <= 5)
		{
			if (*g_playerHP < *g_playerMHP)
			{
				*g_playerHP += 1;
			}
		}

	}
}

void Fire(int *g_bulletFire, int*g_bulletx, int*g_bullety, SURFACEINFO g_sfBack, SURFACEINFO g_sfBul,int* acchit,int*Totalhit, float*acc,int*bossalive,int*phazeon)
{
	if (*g_bulletFire == 1)
	{
		*g_bulletx += 30;
		__gePutSprite(g_sfBack.dcSurface,
			*g_bulletx, *g_bullety, &g_sfBul);
		if (*g_bulletx > 600 && *g_bulletx < 800)
		{
			*g_bulletx = 900;
			*g_bulletFire = 0;
			Getacc(acc, acchit, Totalhit);
		}

	}
}

void Bosshit(int*bossHmove,RECT &Brt,RECT &Krt,RECT &rt,int*g_phazeHP,int*ATT,int*g_bossimmo,int*g_bossimmotime,int*g_bullety,
int*isimmo,int*g_playerHP,int*g_immotime,int*acchit,int*Totalhit,float*acc)
{
	RECT rcTEMP;
	if (*bossHmove >= 1)
	{
		if (IntersectRect(&rcTEMP, &Brt, &Krt)) //�浹����
		{
			*g_phazeHP -= *ATT;
			*g_bossimmo = 1;
			*g_bossimmotime = 5;
			*g_bullety = -220;
			*acchit += 1;
			Getacc(acc, acchit, Totalhit);
		}
		if (IntersectRect(&rcTEMP, &rt, &Krt)) //�浹����
		{
			if (*isimmo == 0) //�����ð�
			{
				*g_playerHP -= 2; //ü���� 2����
				*g_immotime = 80;
				*isimmo = 1; //�ǰݹ����ߵ�
			}
		}
	}
}

void Getacc(float*acc, int*acchit, int*Totalhit)
{
	if (*Totalhit == 0)
	{
		*acc = 1.0;
	}
	else {
		*acc = ((float)*acchit / (float)*Totalhit);
		if (*acc >= 1)
		{
			*acc = 1.00;
		}
	}
}