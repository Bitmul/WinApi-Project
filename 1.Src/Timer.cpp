#include "Timer.h"

void timers(int *g_mons, int *firstspawn, int*g_immotime, int *isimmo, int*BFrate, int*g_bossimmotime, int *g_bossimmo, int * LaserRate, int * LaserT, int * AlaserT, int * BF3rate)
{
	if (*g_mons == 0) //�� ���� ���Ͱ� 0������ �ٽ� ������Ų��
	{
		*firstspawn = 0;
	}
	if (*g_immotime > 1)//�ǰݹ����� �����ִٸ� ��� ����
	{
		*g_immotime -= 1; //�ǰݽð� -1,�⺻������ �ǰݽð��� 60
	}
	else {
		*isimmo = 0;//�ǰݹ����� 0�Ͻ� �ǰݹ��� ����
	}
	if (*BFrate >= 1)
	{
		*BFrate -=1;
	}
	if (*g_bossimmotime > 1)
	{
		*g_bossimmotime -= 1;
	}
	else {
		*g_bossimmo = 0;
	}
	if (*LaserRate >= 1)
	{
		*LaserRate -= 1;
	}
	if (*LaserT > 1)
	{
		*LaserT -= 1;
	}
	if (*AlaserT > 1)
	{
		*AlaserT -= 1;
	}
	if (*BF3rate >= 1)
	{
		*BF3rate -= 1;
	}
}