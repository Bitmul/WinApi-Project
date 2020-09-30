#include "Timer.h"

void timers(int *g_mons, int *firstspawn, int*g_immotime, int *isimmo, int*BFrate, int*g_bossimmotime, int *g_bossimmo, int * LaserRate, int * LaserT, int * AlaserT, int * BF3rate)
{
	if (*g_mons == 0) //방 안의 몬스터가 0마리면 다시 스폰시킨다
	{
		*firstspawn = 0;
	}
	if (*g_immotime > 1)//피격무적이 남아있다면 계속 실행
	{
		*g_immotime -= 1; //피격시간 -1,기본적으로 피격시간은 60
	}
	else {
		*isimmo = 0;//피격무적이 0일시 피격무적 해제
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