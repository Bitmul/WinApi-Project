#include <windows.h>
#include "GraphicEngine.h"
#include <time.h>
#include <mmsystem.h>
#include <conio.h>
#include "putbar.h"
#include "Player.h"
#include "Timer.h"
#include "InterSect.h"
#include "PhazePat.h"
#include "Phazeone.h"
#include "Phazetwo.h"
#include "Phazethree.h"
#pragma comment(lib, "winmm.lib")

#define TITLE 0
#define PHAZE1 1
#define PHAZE2 2
#define PHAZE3 3
#define GAMEOVER 4
#define CLEAR 5

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void ___aMainLoop(HWND hWnd);
int g_Gamelayer = 0;
int g_playerx = 50;
int g_playery = 200;
int g_bulletx = -100;
int g_bullety = -100;
int DELT = 0;
int wait = 100;
float acc = 1.00;
int acchit = 0;
int Totalfire = 0;
float g_Bbulletx[11] = { 900,900,900,900,900,900,900,900,900,900 };
float g_Bbullety[11] = { 900,900,900,900,900,900,900,900,900,900 };
float g_Bbulletx2[11] = { 900,900,900,900,900,900,900,900,900,900 };
float g_Bbullety2[11] = { 900,900,900,900,900,900,900,900,900,900 };
int g_Bbulletx3[11] = { 900,900,900,900,900,900,900,900,900,900 };
int g_Bbullety3[11] = { 900,900,900,900,900,900,900,900,900,900 };
int BF3rate = 0;
int BF3fire = 0;
int g_monsterx[6] = { 800,800,800,800,800 };
int g_monstery[6] = { 300,300,300,300,300 };
int g_bossx = 800;
int g_bossy = 190;
int g_bulletFire = 0;
int firstspawn = 0;
int g_mons = 0;
int isimmo = 0;
int g_immotime = 1000;
int kills = 0;
int i = 0;
int g_nphaze = 1; //1이면 1페이즈 2면 2페이즈.....
int randpat = 0;
int bossHmove = 0;
int g_playerHP = 15;
int g_playerMHP = 15;
int g_phaze1HP = 300;
int g_phaze2HP = 1000;
int g_phaze3HP = 2000;
int ATT = 1;
int g_bossimmo = 0;
int g_bossimmotime = 0;
int g_phaze1Die = 0;
int g_phaze2Die = 0;
int g_phaze3Die = 0;
int pause = 0;
int BBpat = 0;
int BBFire = 0;
int TMusic = 0;
int P1Music = 0;
int P2Music = 0;
int P3Music = 0;
int BFrate = 0;
int HealItem = 0;
int PhazeC = 0;
int Laserx = 0;
int Lasery = 0;
int LaserT = 0;
int AlaserT = 0;
int LaserFire = 0;
int LaserRate = 0;
int VLaserx = 0;
int VLasery = 0;
int Clear = 0;
int Score = 0;
int phaze1on = 0;
int phaze2on = 0;
int phaze3on = 0;
HINSTANCE g_hInst;
HWND hWndMain;
LPSTR lpszClass="[Flying Plane Alpha]";
RECT rt, mrt, rcTEMP,Brt,KBBrt[15],KBBBrt[8],Krt,KBrt[15],LBrt[5],VLBrt;

SURFACEINFO g_sfBack;			// 후  면 표면
SURFACEINFO g_sfTitle;			// 타이틀 표면
SURFACEINFO g_sfGameover;	    // 게임 오버 표면
SURFACEINFO g_sfBG;				// 페이즈 1배경 표면
SURFACEINFO g_sfBG2;				// 페이즈 2배경 표면 
SURFACEINFO g_sfBG3;				// 페이즈 3배경 표면 
SURFACEINFO g_sfPhaze;				// 페이즈  변경 표면
SURFACEINFO g_sfMon;			// 플레이어 표면
SURFACEINFO g_sfMonHit;			// 플레이어 피격 표면
SURFACEINFO g_sfHos;			// 몬스터 표면
SURFACEINFO g_sfBul;			// 총알 표면
SURFACEINFO g_sfBoss;           // 보스 1페이즈 표면
SURFACEINFO g_sfBoss2;           // 보스 2페이즈 표면
SURFACEINFO g_sfBoss3;           // 보스 3페이즈 표면
SURFACEINFO g_sfBossB;           // 보스 총알 표면
SURFACEINFO g_sfBossHit;           // 보스 1페이즈 피격
SURFACEINFO g_sfBoss2Hit;           // 보스 2페이즈 피격
SURFACEINFO g_sfBoss3Hit;           // 보스 3페이즈 피격
SURFACEINFO g_sfLaserR;           // 레이저 발사 준비 표면
SURFACEINFO g_sfLaserF;           // 레이저 발사 표면
SURFACEINFO g_sfVLaserR;           // 세로 레이저 발사 준비 표면
SURFACEINFO g_sfVLaserF;           // 세로 레이저 발사 표면
SURFACEINFO g_sfBHPT;           // 보스 체력 틀 표면
SURFACEINFO g_sfBHP;           // 보스 체력바 표면
SURFACEINFO g_sfPHPT;           // 플레이어 체력 틀 표면
SURFACEINFO g_sfPHP;           // 플레이어 체력바 표면
SURFACEINFO g_sfCLEAR;           //게임 클리어 표면
SURFACEINFO g_sfACC;           // 정확도 바 표면
SURFACEINFO g_sfACCT;           //정확도 틀 표면

#define SOUND_FILE_NAME "Plane.wav"
#define SOUND_FILE_NAME "Gravity Core.wav"
#define SOUND_FILE_NAME "Gravity Lord.wav"
#define SOUND_FILE_NAME "Gravity Lord Rise.wav"

int	   g_nFrame;				// 프레임 수 (화면 갱신)

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(NULL_BRUSH);
	WndClass.hCursor=LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass, WS_SYSMENU | WS_CAPTION, //WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,646,500,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	hWndMain=hWnd;

    while(1)
    {
    	if(PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ))
    	{
    	    if( !GetMessage( &msg, NULL, 0, 0 ) ) return (int) msg.wParam;
    	    TranslateMessage(&msg);
    	    DispatchMessage(&msg);
    	}
		else {
			___aMainLoop(hWnd);
		}
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	
	switch (iMessage)
	{
	case WM_CREATE:
		//// 표면 생성 및 기타
		hdc = GetDC(hWnd);
		___aInit(hdc, g_sfBack,g_sfTitle,g_sfGameover,g_sfBG,g_sfBG2,g_sfBG3,g_sfPhaze,g_sfMon,g_sfMonHit,g_sfHos,g_sfBul,g_sfBoss,g_sfBoss2,g_sfBoss3,
			g_sfBossB,g_sfBossHit,g_sfBoss2Hit,g_sfBoss3Hit,g_sfLaserR,g_sfLaserF,g_sfVLaserR,g_sfVLaserF,g_sfBHPT,g_sfBHP,g_sfPHPT,g_sfPHP,g_sfCLEAR,
			g_sfACC,g_sfACCT);
		ReleaseDC(hWnd, hdc);
		g_Gamelayer = 0;
		return 0;
	case WM_DESTROY:
		___aDestroyAll(g_sfBack, g_sfTitle, g_sfGameover, g_sfBG, g_sfBG2, g_sfBG3, g_sfPhaze, g_sfMon, g_sfMonHit, g_sfHos, g_sfBul, g_sfBoss, g_sfBoss2, g_sfBoss3,
			g_sfBossB, g_sfBossHit, g_sfBoss2Hit, g_sfBoss3Hit, g_sfLaserR, g_sfLaserF, g_sfVLaserR, g_sfVLaserF, g_sfBHPT, g_sfBHP, g_sfPHPT, g_sfPHP,g_sfCLEAR,
			g_sfACC, g_sfACCT);
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void ___aMainLoop(HWND hWnd)
{
	char  strBuff[100];
	HDC   hdc;
	static int nBgX;
	HFONT font, oldfont;


	switch (g_Gamelayer)
	{
	case TITLE:
		if (TMusic == 0){PlaySound(TEXT("Plane.wav"), NULL, SND_ASYNC | SND_LOOP); TMusic = 1;}
		__gePutImage(g_sfBack.dcSurface, 0, 0, &g_sfTitle);
		if (GetKeyState(VK_SPACE) & 0x80)
		{g_Gamelayer = PHAZE1; __geReleaseSurface(&g_sfTitle); PlaySound(0, NULL, 0);}
		break;
	case PHAZE1:
		__KeyProc(hWnd,&g_playerx,&g_playery,&g_bulletFire,&g_bulletx,&g_bullety,&Totalfire,&g_phaze1Die,&phaze1on,&ATT);
		SetRect(&rt, g_playerx + 4, g_playery + 4, g_playerx + 20, g_playery + 16);//플레이어 피격
		nBgX -= 4;
		i = 0;
		Oatt(&kills,&ATT,&g_playerMHP,&g_playerHP);
		if (g_playerHP < 1)
		{
			Sleep(300);
			PlaySound(0, NULL, 0);
			g_Gamelayer = GAMEOVER;
		}
			if (nBgX < -640) nBgX = 0;//배경 스크롤
			i = 0;
			// 배경	
			__gePutImage(g_sfBack.dcSurface, nBgX, 0, &g_sfBG);
			__gePutImage(g_sfBack.dcSurface, nBgX + 640, 0, &g_sfBG);
			SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
			SetBkMode(g_sfBack.dcSurface, TRANSPARENT);
			//// 플레이어 스프라이트
			Hit(&isimmo,&g_playerx,&g_playery,g_sfBack,g_sfMon,g_sfMonHit);
			for (i = 0; i < 1; i++)
			{Fire(&g_bulletFire,&g_bulletx,&g_bullety,g_sfBack,g_sfBul,&acchit,&Totalfire,&acc,&g_phaze1Die,&phaze1on);}
			//잡몹 이동 및 플레이어 피격체크
			for (i = 0; i < 5; i++)
			{_InterSect(&g_monsterx[i],&g_monstery[i],&g_mons,g_sfBack,g_sfHos,&g_playerx,&g_playery,&isimmo,&g_playerHP,&g_immotime);}
			//보스
			if (g_phaze1Die == 0)
			{
				if (firstspawn == 0) { Spawn(g_monsterx, g_monstery, &pause, &firstspawn, &g_mons); }
				switch (bossHmove)
				{
				case 0:
					if (g_bossx >= 500)
					{
						g_bossx -= 1;
						if (g_bossx == 499) { bossHmove = 1; phaze1on = 1; }
					}
					break;
				case 1:
					if (P1Music == 0){PlaySound(TEXT("Gravity Core.wav"), NULL, SND_ASYNC | SND_LOOP); P1Music = 1;}
					if (g_bossy >= 350){bossHmove = 2;}
					else {
						if (g_phaze1HP < 150){g_bossy += 4;}
						else { g_bossy += 3; }
					}
					break;
				case 2:
					if (g_bossy <= 30){bossHmove = 1;}
					else {
						if (g_phaze1HP < 150){g_bossy -= 4;}
						else { g_bossy -= 3; }
					}
					break;
				}
			}
			if (g_phaze1HP < 1){g_phaze1Die = 1;pause = 1;}
			if (g_phaze1Die == 0)
			{
				if (bossHmove >= 1){Putbar(g_sfBack.dcSurface, 15, 430, &g_sfBHP,g_sfBHPT,g_sfBack,1,g_phaze1HP);}
				if (BFrate == 0 && BBFire == 0 && bossHmove >=1)
				{
					BFrate = 200;
					if (g_phaze1HP < 150){BFrate = 100;}
					BBpat = rand()%3+1;
					for (i = 0;i < 10;i++)
					{
						g_Bbulletx[i] = g_bossx;
						g_Bbullety[i] = g_bossy+50;
					}
					BBFire = 10;
				}
				if (BBFire >= 1 && bossHmove >= 1)
				{
					if (BBpat == 1){pattern1(g_sfBack,g_sfBossB,&g_phaze1HP,g_Bbulletx,g_Bbullety);}
					else  if (BBpat == 2){pattern2(g_sfBack, g_sfBossB,&g_phaze1HP, g_Bbulletx, g_Bbullety);}
					else{pattern3(g_sfBack, g_sfBossB,&g_phaze1HP, g_Bbulletx, g_Bbullety);}
				}
				Bulletcheck(g_Bbulletx,g_Bbullety,&BBFire,&isimmo,&g_playerHP,&g_immotime,&g_playerx,&g_playery);
				SetRect(&Krt, g_bossx, g_bossy, g_bossx + 100, g_bossy + 100);//보스 피격
				SetRect(&Brt, g_bulletx - 30, g_bullety - 3, g_bulletx + 24, g_bullety + 3);
				Bosshit(&bossHmove, Brt, Krt, rt, &g_phaze1HP, &ATT, &g_bossimmo, &g_bossimmotime, &g_bullety, &isimmo, &g_playerHP, &g_immotime,&acchit, &Totalfire, &acc);
			}
			BHsprite(1, &g_bossimmo, &g_bossx, &g_bossy, g_sfBack, g_sfBoss, g_sfBossHit, g_sfBoss2, g_sfBoss2Hit, g_sfBoss3, g_sfBoss3Hit);
			Playerbar(g_sfBack.dcSurface, 10, 5, &g_sfPHP, g_sfPHPT, g_sfBack, g_playerHP, g_playerMHP);
			ACCbar(g_sfBack.dcSurface, 10, 35, &g_sfACC, g_sfACCT, g_sfBack, acc);
			for (i = 0; i < 5; i++)
			{
				mobhit(&g_monsterx[i],&g_monstery[i],&g_bullety,&g_bulletx,&kills,&g_mons,&g_playerHP,&g_playerMHP,&acchit, &Totalfire, &acc,&Score,&g_phaze1Die,&phaze1on,&g_bulletFire);
			}
			__Displaytext(g_sfBack, &kills, &ATT, &g_playerHP, &g_playerMHP, &g_Gamelayer, &g_phaze1HP, &g_phaze2HP, &g_phaze3HP, &bossHmove,&g_phaze1Die,&g_phaze2Die,&g_phaze3Die,&acc,&Score);
			timers(&g_mons, &firstspawn, &g_immotime, &isimmo, &BFrate, &g_bossimmotime, &g_bossimmo, &LaserRate, &LaserT, &AlaserT, &BF3rate);
		if (g_phaze1Die == 1)
		{
			if (DELT == 0)
			{
				for (i = 0; i < 10; i++){g_Bbulletx[i] = -610; g_Bbullety[i] = -610; BBFire = 0;}
				for (i = 0; i < 5; i++) { g_monstery[i] = 800; g_mons -= 1; firstspawn = 0; }
				if (g_mons < 0)
				{g_mons = 0;}
				DELT = 1;
				Score += 2000 * acc;
			}
			if (g_bossx < 800)
			{g_bossx ++; __gePutSprite(g_sfBack.dcSurface,g_bossx, g_bossy, &g_sfBossHit);}
			else
			{
				__gePutImage(g_sfBack.dcSurface, 0, 0, &g_sfPhaze);
				g_bossx = 800;
				g_bossy = 160;
				bossHmove = 0;
				g_nphaze = 2;
				g_bossimmotime = 0;
				g_bossimmo = 0;
				BFrate = 0;
				int healH = 0;
				g_playerMHP += 5;
				healH = g_playerMHP - g_playerHP;
				g_playerHP += healH;
				g_Gamelayer = PHAZE2;
			}
		}
		break;
		case PHAZE2:
			if (PhazeC == 0)
			{
				Sleep(200);
				PhazeC = 1;
				pause = 0;
				PlaySound(0, NULL, 0);
				LaserRate = 600;
				BFrate = 100;
			}
			__KeyProc(hWnd, &g_playerx, &g_playery, &g_bulletFire, &g_bulletx, &g_bullety, &Totalfire, &g_phaze2Die, &phaze2on,&ATT);
			SetRect(&rt, g_playerx + 4, g_playery + 4, g_playerx + 20, g_playery + 16);//플레이어 피격
				nBgX -= 6;
				i = 0;
				if (g_playerHP < 1){Sleep(300);g_Gamelayer = GAMEOVER;}
				if (nBgX < -640) nBgX = 0;//배경 스크롤
				i = 0;
				Oatt(&kills, &ATT, &g_playerMHP, &g_playerHP);
				// 배경	
				__gePutImage(g_sfBack.dcSurface, nBgX, 0, &g_sfBG2);
				__gePutImage(g_sfBack.dcSurface, nBgX + 640, 0, &g_sfBG2);
				//// 플레이어 스프라이트
				Hit(&isimmo, &g_playerx, &g_playery, g_sfBack, g_sfMon, g_sfMonHit);
				for (i = 0; i < 1; i++){Fire(&g_bulletFire, &g_bulletx, &g_bullety, g_sfBack, g_sfBul,&acchit, &Totalfire, &acc,&g_phaze2Die,&phaze2on);}
				//잡몹 이동 및 플레이어 피격체크
				for (i = 0; i < 5; i++){_InterSect(&g_monsterx[i], &g_monstery[i], &g_mons, g_sfBack, g_sfHos, &g_playerx, &g_playery, &isimmo, &g_playerHP, &g_immotime);}
				//보스
				if (g_phaze2Die == 0)
				{
					if (firstspawn == 0) { Spawn(g_monsterx, g_monstery, &pause, &firstspawn, &g_mons); }
					switch (bossHmove)
					{
					case 0:
						if (g_bossx >= 400)
						{
							g_bossx -= 1;
							if (g_bossx == 399){bossHmove = 1; phaze2on = 1;}
						}
						break;
					case 1:
						if (P2Music == 0)
						{PlaySound(0, NULL, 0); PlaySound(TEXT("Gravity Lord.wav"), NULL, SND_ASYNC | SND_LOOP); P2Music = 1;}
						if (g_bossy >= 300){bossHmove = 2;}
						else {
							if (g_phaze2HP < 500){g_bossy += 4;}
							else { g_bossy += 3; }
						}
						break;
					case 2:
						if (g_bossy <= 20){bossHmove = 1;}
						else {
							if (g_phaze2HP < 500){g_bossy -= 4;}
							else { g_bossy -= 3; }
						}
						break;
					}
				}
				if (g_phaze2HP < 1){g_phaze2Die = 1;}
				if (g_phaze2Die == 0)
				{
					if (LaserRate == 0 && LaserFire == 0 && bossHmove >= 1)
					{
						LaserFire = 1;
						if (g_phaze2HP < 500){LaserRate = 170; LaserT = 90;}
						else{LaserRate = 500; LaserT = 200;}
						Lasery = g_playery+4;
					}
					if (LaserFire == 1 && LaserT > 2){__gePutImage(g_sfBack.dcSurface, 0, Lasery, &g_sfLaserR); LaserT--;}
					if (LaserT == 1)
					{
						if (g_phaze2HP < 500){AlaserT = 100;}
						else { AlaserT = 200; }
						LaserT = 0;
					}
					if (LaserFire ==1 && AlaserT >= 2)
					{
						SetRect(&LBrt[0], Laserx, Lasery - 15, Laserx + 640, Lasery + 24);
						if (IntersectRect(&rcTEMP, &rt, &LBrt[0])) //충돌판정
						{if (isimmo == 0){g_playerHP -= 3;g_immotime = 40;isimmo = 1;}}
						__gePutImage(g_sfBack.dcSurface, 0, Lasery-20, &g_sfLaserF);
						AlaserT --;
					}
					if (AlaserT == 1){LaserFire = 0; AlaserT = 0;}
					if (BFrate == 0 && BBFire == 0 && bossHmove >= 1)
					{
						if (g_phaze2HP < 500){BFrate = 120;}
						else{BFrate = 250;}
						BBpat = rand() % 3 + 1;
						for (i = 0; i < 10; i++){g_Bbulletx[i] = g_bossx;g_Bbullety[i] = g_bossy + 80;}
						BBFire = 10;
					}
					if (BBFire >= 1 && bossHmove >= 1)
					{
						if (BBpat == 1){twopattern1(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety);}
						else  if (BBpat == 2){twopattern2(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety);}
						else{twopattern3(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety);}
					}
					Bulletcheck(g_Bbulletx, g_Bbullety, &BBFire, &isimmo, &g_playerHP, &g_immotime, &g_playerx, &g_playery);
					SetRect(&Krt, g_bossx, g_bossy+40, g_bossx + 180, g_bossy + 120);//보스 피격
					SetRect(&Brt, g_bulletx - 30, g_bullety - 3, g_bulletx + 24, g_bullety + 3);
					for (i = 0; i < 5; i++){mobhit(&g_monsterx[i], &g_monstery[i], &g_bullety, &g_bulletx, &kills, &g_mons, &g_playerHP, &g_playerMHP,&acchit, &Totalfire, &acc,&Score, &g_phaze2Die, &phaze2on, &g_bulletFire);}
					Bosshit(&bossHmove, Brt, Krt, rt, &g_phaze2HP, &ATT, &g_bossimmo, &g_bossimmotime, &g_bullety, &isimmo, &g_playerHP, &g_immotime,&acchit, &Totalfire, &acc);
					if (bossHmove >= 1){Putbar(g_sfBack.dcSurface, 15, 430, &g_sfBHP, g_sfBHPT, g_sfBack, 2, g_phaze2HP);}
				}
				BHsprite(2, &g_bossimmo, &g_bossx, &g_bossy, g_sfBack, g_sfBoss, g_sfBossHit, g_sfBoss2, g_sfBoss2Hit, g_sfBoss3, g_sfBoss3Hit);
				Playerbar(g_sfBack.dcSurface, 10, 5, &g_sfPHP, g_sfPHPT, g_sfBack, g_playerHP, g_playerMHP);
				ACCbar(g_sfBack.dcSurface, 10, 35, &g_sfACC, g_sfACCT, g_sfBack, acc);
				__Displaytext(g_sfBack, &kills, &ATT, &g_playerHP, &g_playerMHP, &g_Gamelayer, &g_phaze1HP, &g_phaze2HP, &g_phaze3HP, &bossHmove, &g_phaze1Die, &g_phaze2Die, &g_phaze3Die,&acc,&Score);
				timers(&g_mons, &firstspawn, &g_immotime, &isimmo, &BFrate, &g_bossimmotime, &g_bossimmo, &LaserRate, &LaserT, &AlaserT, &BF3rate);
				if (g_phaze2Die == 1)
				{
					if (DELT == 1)
					{
						for (i = 0; i < 10; i++){g_Bbulletx[i] = -610; g_Bbullety[i] = -610; BBFire = 0;}
						for (i = 0; i < 10; i++){g_Bbullety[i] = -610; BBFire = 0;}
						for (i = 0; i < 5; i++){g_monstery[i] = -50; g_mons -= 1;}
						DELT = 2;
						Score += 5000 * acc;
					}
					if (g_bossx < 800){g_bossx += 2; __gePutSprite(g_sfBack.dcSurface,g_bossx, g_bossy, &g_sfBoss2Hit);}
					else
					{
						__gePutImage(g_sfBack.dcSurface, 0, -13, &g_sfPhaze);
						g_bossx = 800;
						g_bossy = 0;
						bossHmove = 0;
						g_nphaze = 3;
						g_bossimmotime = 0;
						g_bossimmo = 0;
						BFrate = 0;
						int healH = 0;
						g_playerMHP += 15;
						healH = g_playerMHP - g_playerHP;
						g_playerHP += healH;
						Laserx = 0;
						Lasery = 0;
						LaserT = 0;
						AlaserT = 0;
						LaserFire = 0;
						LaserRate = 0;
						g_Gamelayer = PHAZE3;
					}
			}
			break;
			case PHAZE3 :
				if (PhazeC == 1){Sleep(200); PhazeC = 2; pause = 0; PlaySound(0, NULL, 0); LaserRate = 600; BFrate = 100;}
				__KeyProc(hWnd, &g_playerx, &g_playery, &g_bulletFire, &g_bulletx, &g_bullety, &Totalfire, &g_phaze3Die, &phaze3on,&ATT);
				SetRect(&rt, g_playerx + 6, g_playery, g_playerx + 20, g_playery + 13);//플레이어 피격
				nBgX -= 8;
				i = 0;
				if (g_playerHP < 1){Sleep(300); g_Gamelayer = GAMEOVER;}
				if (nBgX < -640) nBgX = 0;//배경 스크롤
				i = 0;
				//공격력 계산
				Oatt(&kills, &ATT, &g_playerMHP, &g_playerHP);
				// 배경	
				__gePutImage(g_sfBack.dcSurface, nBgX, 0, &g_sfBG3);
				__gePutImage(g_sfBack.dcSurface, nBgX + 640, 0, &g_sfBG3);
				//// 플레이어 스프라이트
				Hit(&isimmo, &g_playerx, &g_playery, g_sfBack, g_sfMon, g_sfMonHit);
				for (i = 0; i < 1; i++){Fire(&g_bulletFire, &g_bulletx, &g_bullety, g_sfBack, g_sfBul,&acchit,&Totalfire,&acc,&g_phaze3Die,&phaze3on);}
				//잡몹 이동 및 플레이어 피격체크
				for (i = 0; i < 5; i++){_InterSect(&g_monsterx[i], &g_monstery[i], &g_mons, g_sfBack, g_sfHos, &g_playerx, &g_playery, &isimmo, &g_playerHP, &g_immotime);}
				//보스
				if (g_phaze3Die == 0)
				{
					switch (bossHmove)
					{
					case 0:
						if (g_bossx >= 400)
						{
							BHsprite(3, &g_bossimmo, &g_bossx, &g_bossy, g_sfBack, g_sfBoss, g_sfBossHit, g_sfBoss2, g_sfBoss2Hit, g_sfBoss3, g_sfBoss3Hit);
							g_bossx -= 1;
							if (g_bossx == 399){bossHmove = 1; phaze3on = 1;}
						}
						break;
					case 1:
						if (P3Music == 0)
						{
							PlaySound(0, NULL, 0);
							PlaySound(TEXT("Gravity Lord Rise.wav"), NULL, SND_ASYNC | SND_LOOP);
							P3Music = 1;
						}
					}
					if (g_phaze3HP < 1){g_phaze3Die = 1;}
					if (g_phaze3Die == 0)
					{
						if (LaserRate == 0 && LaserFire == 0 && bossHmove >= 1)
						{
							LaserFire = 1;
							if (g_phaze3HP < 1000){LaserRate = 200;LaserT = 100;}
							else{LaserRate = 300;LaserT = 150;}
							Lasery = g_playery + 4;
							VLaserx = g_playerx + 20;
						}
						if (LaserFire == 1 && LaserT > 2)
						{
							__gePutImage(g_sfBack.dcSurface, 0, Lasery, &g_sfLaserR);
							__gePutImage(g_sfBack.dcSurface, VLaserx, 0, &g_sfVLaserR);
							LaserT--;
						}
						if (LaserT == 1)
						{
							if (g_phaze3HP < 1000){AlaserT = 100;}
							else{AlaserT = 150;}
							LaserT = 0;
						}
						if (LaserFire == 1 && AlaserT > 2)
						{
							SetRect(&LBrt[0], Laserx, Lasery - 15, Laserx + 640, Lasery + 24);
							SetRect(&VLBrt, VLaserx - 15, VLasery, VLaserx + 24, VLasery + 480);
							if (IntersectRect(&rcTEMP, &rt, &LBrt[0])) //충돌판정
							{
								if (isimmo == 0){g_playerHP -= 8; g_immotime = 80; isimmo = 1;}
							}
							if (IntersectRect(&rcTEMP, &rt, &VLBrt)) //충돌판정
							{
								if (isimmo == 0){g_playerHP -= 8; g_immotime = 80; isimmo = 1;}
							}
							__gePutImage(g_sfBack.dcSurface, 0, Lasery - 20, &g_sfLaserF);
							__gePutImage(g_sfBack.dcSurface, VLaserx - 20, 0, &g_sfVLaserF);
							AlaserT--;
						}
						if (AlaserT == 1){LaserFire = 0; AlaserT = 0;}
						if (bossHmove >= 1 && BF3fire == 0 && BF3rate == 0)
						{
							BF3fire = 8;
							threepattern4(g_sfBack, g_sfBossB, g_Bbulletx3, g_Bbullety3, &g_bossx, &g_bossy);
							if (g_phaze3HP < 1000){BF3rate = 100;}
							else{BF3rate = 200;}
						}
						if (BF3fire >= 1 && bossHmove >= 1)
						{
							for (i = 0; i < 8; i++)
							{
								__gePutSprite(g_sfBack.dcSurface,
									g_Bbulletx3[i], g_Bbullety3[i], &g_sfBossB);
								SetRect(&KBBBrt[i], g_Bbulletx3[i], g_Bbullety3[i], g_Bbulletx3[i] + 12, g_Bbullety3[i] + 12);
								if (IntersectRect(&rcTEMP, &rt, &KBBBrt[i]))
								{
									if (isimmo == 0){g_playerHP -= 2;}
								}
								if (g_Bbulletx3[i] < 0 && g_Bbulletx3[i] > -600){g_Bbulletx3[i] = -610; g_Bbullety3[i] = -610; BF3fire--;}
								if (g_phaze3HP < 1000){g_Bbulletx3[i] -= 7;}
								else{g_Bbulletx3[i] -= 5;}
							}
						}
						if (BFrate == 0 && BBFire == 0 && bossHmove >= 1)
						{
							if (g_phaze3HP < 1000){BFrate = 100;}
							else{BFrate = 200;}
							BBpat = rand() % 3 + 1;
							for (i = 0; i < 10; i++)
							{g_Bbulletx[i] = g_bossx + 13; g_Bbullety[i] = g_bossy + 219; g_Bbulletx2[i] = g_bossx + 13; g_Bbullety2[i] = g_bossy + 279;}
							BBFire = 20;
						}
						if (BBFire >= 1 && bossHmove >= 1)
						{
							if (BBpat == 1){threepattern1(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety); threepattern1(g_sfBack, g_sfBossB, g_Bbulletx2, g_Bbullety2);}
							else  if (BBpat == 2){threepattern2(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety); threepattern2(g_sfBack, g_sfBossB, g_Bbulletx2, g_Bbullety2);}
							else{threepattern3(g_sfBack, g_sfBossB, g_Bbulletx, g_Bbullety); threepattern3(g_sfBack, g_sfBossB, g_Bbulletx2, g_Bbullety2);}
						}
						Bulletcheck(g_Bbulletx, g_Bbullety, &BBFire, &isimmo, &g_playerHP, &g_immotime, &g_playerx, &g_playery);
						Bulletcheck(g_Bbulletx2, g_Bbullety2, &BBFire, &isimmo, &g_playerHP, &g_immotime, &g_playerx, &g_playery);
						SetRect(&Krt, g_bossx, g_bossy, g_bossx + 366, g_bossy + 496);//보스 피격
						SetRect(&Brt, g_bulletx - 30, g_bullety - 3, g_bulletx + 24, g_bullety + 3);
						Bosshit(&bossHmove, Brt, Krt, rt, &g_phaze3HP, &ATT, &g_bossimmo, &g_bossimmotime, &g_bullety, &isimmo, &g_playerHP, &g_immotime,&acchit, &Totalfire, &acc);
						if (bossHmove >= 1){BHsprite(3, &g_bossimmo, &g_bossx, &g_bossy, g_sfBack, g_sfBoss, g_sfBossHit, g_sfBoss2, g_sfBoss2Hit, g_sfBoss3, g_sfBoss3Hit);}
						if (bossHmove >= 1){Putbar(g_sfBack.dcSurface, 15, 430, &g_sfBHP, g_sfBHPT, g_sfBack, 3, g_phaze3HP);}
					}
					timers(&g_mons, &firstspawn, &g_immotime, &isimmo, &BFrate, &g_bossimmotime, &g_bossimmo, &LaserRate, &LaserT, &AlaserT, &BF3rate);}
					Playerbar(g_sfBack.dcSurface, 10, 5, &g_sfPHP, g_sfPHPT, g_sfBack, g_playerHP, g_playerMHP);
					ACCbar(g_sfBack.dcSurface, 10, 35, &g_sfACC, g_sfACCT, g_sfBack, acc);
					__Displaytext(g_sfBack, &kills, &ATT, &g_playerHP, &g_playerMHP, &g_Gamelayer, &g_phaze1HP, &g_phaze2HP, &g_phaze3HP, &bossHmove, &g_phaze1Die, &g_phaze2Die, &g_phaze3Die,&acc,&Score);
					if (g_phaze3Die == 1)
					{
						if (DELT == 2)
						{
							for (i = 0; i < 10; i++){g_Bbulletx[i] = -610; g_Bbullety[i] = -610; g_Bbulletx2[i] = -610; g_Bbullety2[i] = -610; g_Bbulletx3[i] = -610; g_Bbullety3[i] = -610; BBFire = 0;}
							for (i = 0; i < 10; i++){g_Bbullety[i] = -610; BBFire = 0;}
							for (i = 0; i < 5; i++){g_monstery[i] = -50; g_mons -= 1;}
							DELT = 3;
							Score += 10000 * acc;
						}
						bossHmove = 0;
						BFrate = 0;
						Laserx = 0;
						Lasery = 0;
						LaserT = 0;
						AlaserT = 0;
						LaserFire = 0;
						LaserRate = 0;
						__gePutImage(g_sfBack.dcSurface, 0, -13, &g_sfPhaze);
						g_Gamelayer = CLEAR;
				}
				break;
		case GAMEOVER :
			__gePutImage(g_sfBack.dcSurface, 0, -13, &g_sfGameover);
			break;
		case CLEAR:
			if (Clear == 0) {
				Sleep(200); PlaySound(TEXT("Plane.wav"), NULL, SND_ASYNC); Clear = 1;
			__gePutImage(g_sfBack.dcSurface, 0, 0, &g_sfCLEAR);
			font = CreateFont(50, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
				1, "Gobold");
			oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
			Score = Score + (Score * ((int)acc * 2));
			}
			if (wait >= 1)
			{
				wait -= 1;
			}
			else {
				SetTextColor(g_sfBack.dcSurface, RGB(255, 123, 0));
				font = CreateFont(50, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
					1, "Gobold");
				oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
				wsprintf(strBuff, "TOTAL SCORE : %d", Score);
				TextOut(g_sfBack.dcSurface, 160, 240,
					strBuff, (int)strlen(strBuff));
				SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 0));
				font = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1,
					1, "Gobold");
				oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
				sprintf(strBuff, "Total Accuracy : %.2f %%", acc * 100);
				TextOut(g_sfBack.dcSurface, 160, 300,
					strBuff, (int)strlen(strBuff));
				if (Score > 40000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : SS");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 30000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : S");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 25000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : A");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 20000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : B");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 15000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : C");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 10000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : D");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score > 5000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : E");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
				else if (Score < 5000)
				{
					SetTextColor(g_sfBack.dcSurface, RGB(255, 255, 255));
					font = CreateFont(75, 0, 0, 0, FW_BOLD, 0, 0, 0, 1, 3, 2, 1,
						1, "Gobold");
					oldfont = (HFONT)SelectObject(g_sfBack.dcSurface, font);
					wsprintf(strBuff, "RANK : F");
					TextOut(g_sfBack.dcSurface, 160, 340,
						strBuff, (int)strlen(strBuff));
				}
			}
			break;
	}
		////			
		hdc = GetDC(hWnd);
		//// 출력 완료 (후면표면DC --전송--> 전면표면DC/화면DC)
		__geCompleteBlt(hdc, &g_sfBack);
		ReleaseDC(hWnd, hdc);

		Sleep(1000 / 100);
	}
