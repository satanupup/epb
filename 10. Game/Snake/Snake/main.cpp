#include <windows.h>
#include <time.h>
#include "snaker.h"
#include "table.h"


#ifdef _DEBUG      // 檢查記憶體洩漏用(頂) 
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#define MYDEBUG_NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__) 
#define new MYDEBUG_NEW 
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the 
//allocations to be of _CLIENT_BLOCK type 
#else 
#define MYDEBUG_NEW 
#endif // _DEBUG 

//遊戲狀態定義
#define GAME_STATE_WAIT     0  //遊戲等待狀態
#define GAME_STATE_RUN      1  //遊戲運行狀態
#define GAME_STATE_END      2  //遊戲結束狀態

//介面相關物件尺寸定義
#define WALL_WIDTH             80  //外牆從左部到遊戲區的寬度
#define WALL_HEIGHT            80  //外牆從頂部到遊戲區的高度

#define BMP_SCORE_BOARD_WIDTH  256 //分數位元圖板的寬度
#define BMP_SCORE_BOARD_HEIGHT 55  //分數位元圖板的高度

#define BMP_WALL_WIDTH         16  //牆點陣圖的寬度
#define BMP_WALL_HEIGHT        16  //牆點陣圖的高度


void DrawGame(void);
void ShellDraw( HDC  hdc );
void GameAreaDraw(HDC hdc);

void OnTimer(UINT uTIMER_ID);
void StartGame( void );
void EndGame( void );

//創建一個桌子
CTable table;

int tableBlockWidth = 0;  //桌子的格子的寬度
int tableBlockHeight = 0; //桌子的格子的高度
int iScores = 0;          //遊戲的得分

UINT uGameState = GAME_STATE_WAIT; //當前遊戲狀態

HDC windowDC = NULL;      //windows螢幕設備
HDC bufferDC = NULL;      //緩衝設備環境
HDC picDC = NULL;         //snake圖像記憶體設備
HDC endDC = NULL;		 //遊戲終結圖像記憶體設備
HDC scoreDC = NULL;      //分數板記憶體設備

HWND hAppWnd = NULL;     //本application窗口控制碼


HBITMAP picBMP = NULL;      //snake圖像點陣圖控制碼
HBITMAP bufferBMP = NULL;   //緩衝點陣圖控制碼
HBITMAP endBMP = NULL;      //遊戲終結圖像記憶體控制碼
HBITMAP hbmpWall = NULL;    //牆點陣圖控制碼
HBITMAP hbmpScore = NULL;   //分數板點陣圖控制碼
HBRUSH hbrushWall = NULL;      //牆畫刷

//計時器標識
UINT uSnakeMoveTimer;  //蛇的移動
UINT uFoodAddTimer;    //水果的?生

//框架的位置資料定義
//GDI RECT 而不是 MFC CRect
RECT g_ClientRect;
RECT g_GameValueRect;
int g_iClientWidth;
int g_iClientHeight;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
/* ************************************
* 功能顯示一個視窗
**************************************/

int WINAPI WinMain (
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
	)
{	
	WNDCLASS wndClass;
	HWND hWnd;
	MSG msg;
	UINT width,height;
	

#ifdef _DEBUG   // 檢查記憶體洩漏用(進入點) 
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 	
	//_CrtSetBreakAlloc(71);
#endif 


	//定義窗口
	wndClass.style=CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc=WndProc;
	wndClass.cbClsExtra=0;
	wndClass.cbWndExtra=0;
	wndClass.hInstance=hPrevInstance;
	wndClass.hIcon=LoadIcon(NULL,MAKEINTRESOURCE(IDI_MAIN));
	wndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName=NULL;
	wndClass.lpszClassName=TEXT("Snake_CLASS");
	//註冊窗口
	RegisterClass(&wndClass);


	//取整個螢幕的尺寸	
	width=GetSystemMetrics(SM_CXSCREEN);
	height=	GetSystemMetrics(SM_CYSCREEN);
	//創建窗口
	hWnd=CreateWindowA(
		"Snake_CLASS",
		"skyblue snake",
		WS_POPUP,
		0,0,
		width,height,
		NULL,NULL,
		hPrevInstance,
		NULL);

	hAppWnd = hWnd;

	//顯示視窗
	ShowWindow(hWnd,nShowCmd);
	UpdateWindow(hWnd);

	//獲取表單大小
	GetClientRect(hAppWnd, &g_ClientRect);
	g_iClientWidth = g_ClientRect.right-g_ClientRect.left;
	g_iClientHeight = g_ClientRect.bottom-g_ClientRect.top;

	//將遊戲區域分成縱，橫均?20塊的小方塊
	//並計算每塊區域的大小
	tableBlockWidth = (g_iClientWidth-2*WALL_WIDTH)/20;
	tableBlockHeight = (g_iClientHeight-2*WALL_HEIGHT)/20;

	//獲取當前主視窗設備與windowDC關聯
	windowDC=GetDC(NULL);
	//創建與windowDC相容的記憶體設備環境
	bufferDC=CreateCompatibleDC(windowDC);
	picDC=CreateCompatibleDC(windowDC);
	endDC=CreateCompatibleDC(windowDC);	
	scoreDC=CreateCompatibleDC(windowDC);	

	//hBitmap = (HBITMAP)::LoadImage(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0,0,LR_CREATEDIBSECTION);
	//點陣圖的初始化或載入點陣圖	
	bufferBMP=CreateCompatibleBitmap(windowDC,g_iClientWidth,g_iClientHeight);
	picBMP=(HBITMAP)LoadImageA(NULL,"snake.bmp",IMAGE_BITMAP,160,80,LR_LOADFROMFILE);
	hbmpWall=(HBITMAP)LoadImageA(NULL,"brick.bmp",IMAGE_BITMAP,16,16,LR_LOADFROMFILE);
	endBMP = (HBITMAP)LoadImageA(NULL,"end.bmp",IMAGE_BITMAP,369,300,LR_LOADFROMFILE);
	hbmpScore=(HBITMAP)LoadImageA(NULL,"scoreboard.bmp",IMAGE_BITMAP,265,55,LR_LOADFROMFILE);
	//	picBMP=(HBITMAP)LoadImage(hCurrentInst,MAKEINTRESOURCE(IDB_BITMAP),IMAGE_BITMAP,160,80,LR_CREATEDIBSECTION);
	//	hbmpWall=(HBITMAP)LoadImage(hCurrentInst,MAKEINTRESOURCE(IDB_BITMAP_WALL),IMAGE_BITMAP,16,16,LR_CREATEDIBSECTION);
	//	endBMP = (HBITMAP)LoadImage(hCurrentInst,MAKEINTRESOURCE(IDB_BITGAMEEND),IMAGE_BITMAP,369,300,LR_CREATEDIBSECTION);	
	//	hbmpScore=(HBITMAP)LoadImage(hCurrentInst,MAKEINTRESOURCE(IDB_BITMAPSCORE),IMAGE_BITMAP,265,55,LR_CREATEDIBSECTION);

	//聲明點陣圖與設備環境的關聯
	SelectObject(bufferDC,bufferBMP);
	SelectObject(picDC,picBMP);
	SelectObject(endDC,endBMP);
	SelectObject(scoreDC,hbmpScore);

	//建立畫刷與其名相對應的圖像的關聯，
	//以備用刷子將牆刷出來，用PatBlt()實現
	hbrushWall = CreatePatternBrush(hbmpWall);

	StartGame();


	while(GetMessage(&msg,NULL,0,0))
	{		
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,
						 WPARAM wParam,LPARAM lParam)
{

	switch(message)
	{
	case WM_TIMER :
		OnTimer((UINT)wParam);		
		break;		

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_ESCAPE:
			exit(0);
			break;
		case VK_UP:
			table.ChangeSnakeDirect(S_UP);
			break;
		case VK_DOWN:
			table.ChangeSnakeDirect(S_DOWN);
			break;
		case VK_LEFT:
			table.ChangeSnakeDirect(S_LEFT);
			break;
		case VK_RIGHT:
			table.ChangeSnakeDirect(S_RIGHT);
			break;
		case VK_SPACE:
			if(	uGameState == GAME_STATE_END )
			{
				StartGame();
				break;
			}

		}
		return 0;
	case WM_SETCURSOR:
		SetCursor(NULL);
		return 0;
	case WM_DESTROY:
		ReleaseDC(hWnd,picDC);
		ReleaseDC(hWnd,bufferDC);
		ReleaseDC(hWnd,windowDC);
		PostQuitMessage(0);
		return 0;			
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

void DrawGame(void)
{
	//繪製外殼區域到緩衝
	ShellDraw(bufferDC);

	//繪製遊戲區域到緩衝
	GameAreaDraw(bufferDC);

	//將整個畫面從緩衝DC拷貝出螢幕
	BitBlt(windowDC,0,0,g_iClientWidth,g_iClientHeight,bufferDC,0,0,SRCCOPY);
}



void OnTimer(UINT uTIMER_ID)
{
	if ( uTIMER_ID == uSnakeMoveTimer )
	{
		//移動蛇
		table.SnakeMove();

		//檢測是否碰到身體(環繞)，結束遊戲
		if(table.GetSnake()->IsHeadTouchBody(table.GetSnake()->GetPos()[0].x,table.GetSnake()->GetPos()[0].y))
		{
			EndGame();
		}

		//根據蛇頭所在的區域作出相應的處理
		switch(table.GetData(table.GetSnake()->GetPos()[0].x,table.GetSnake()->GetPos()[0].y))
		{
		case TB_STATE_FOOD:
			table.ClearFood(table.GetSnake()->GetPos()[0].x,table.GetSnake()->GetPos()[0].y);
			table.AddBlock((rand())%tableBlockWidth,(rand())%tableBlockHeight);
			table.GetSnake()->AddBody();
			++iScores;
			break;
		case TB_STATE_BLOCK:
		case TB_STATE_SBLOCK:
			//檢測是否碰到障礙物，結束遊戲
			EndGame();
			break;
		}

		//顯示
		DrawGame();
	}
	else if ( uTIMER_ID == uFoodAddTimer )
	{//定時加食物
		table.AddFood((rand())%tableBlockWidth,(rand())%tableBlockHeight);
	}
}

void StartGame()
{
	iScores=0;

	//桌面的初始化
	table.InitialTable(tableBlockWidth,tableBlockHeight);
	table.GetSnake()->ChangeDirect(S_RIGHT);
	table.GetSnake()->SetHeadPos(tableBlockWidth/2,tableBlockHeight/2);

	//預先隨機?生幾個食物
	srand( (unsigned)time(NULL) );
	for(int iFoodNum=0;  iFoodNum<4; iFoodNum++)
	{
		table.AddFood((rand())%tableBlockWidth,(rand())%tableBlockHeight);
	}
	//不部下種子也可以直接用rand(),
	//但是每次遊戲開始都是?生完全一樣的?隨即序列

	//打開計時器
	uSnakeMoveTimer = SetTimer(hAppWnd,500,100,NULL);
	uFoodAddTimer = SetTimer(hAppWnd,600,7000,NULL);

	uGameState = GAME_STATE_RUN;
}

void EndGame( void )
{
	//關閉計時器
	KillTimer(hAppWnd,uSnakeMoveTimer);
	KillTimer(hAppWnd,uFoodAddTimer);
	uGameState = GAME_STATE_END;
}

void ShellDraw( HDC  hdc )
{	
	//	HDC hMemDc;
	//	BOOL ret = TRUE;
	//	HDC hMemoryDC;
	//	HBITMAP hbmp;
	//分數提示顯示文字
	char szText[30] = "Score: ";
	char szNum[20] = "";		

	int iNowScore = iScores*100;
	_itoa_s(iNowScore,szNum,10);
	strcat_s(szText,sizeof(szText), szNum);

	RECT rt, rect;
	GetClientRect(hAppWnd, &rt);
	//牆的繪製
	SelectObject(hdc,hbrushWall);
	PatBlt(hdc,rt.left,rt.top,rt.right,rt.bottom,PATCOPY);
	//內部遊戲區的白色底平面
	rect.left = rt.left+WALL_WIDTH;
	rect.top = rt.top + WALL_HEIGHT;
	rect.right = rt.right - WALL_WIDTH;
	rect.bottom = rt.bottom - WALL_HEIGHT;		
	FillRect(hdc, &rect, (HBRUSH) (COLOR_WINDOW+1));

	//分數提示板的繪製		
	/*	hMemoryDC =	CreateCompatibleDC(NULL);	
	hbmp = CreateCompatibleBitmap(hdc,265,55);		
	SelectObject(hMemoryDC,hbrushScore);	
	SelectObject(hMemoryDC,hbmp);	
	PatBlt(hMemoryDC,0,0,256,55,PATCOPY);	
	BitBlt(hdc,GetSystemMetrics(SM_CXSCREEN)/3,
	10,256,55,hMemoryDC,0,0,SRCCOPY);
	*/
	BitBlt(hdc,GetSystemMetrics(SM_CXSCREEN)/3,
		10,256,55,scoreDC,0,0,SRCCOPY);

	//分數的列印繪製
	SetBkMode(hdc, TRANSPARENT); 	
	TextOutA(hdc, GetSystemMetrics(SM_CXSCREEN)/3+50, 30,szText,strlen(szText) );
}

void GameAreaDraw(HDC hdc)
{
	int i,j;
	int x,y, x_pos,y_pos;
	BitmapState  state;
	//char strMark[20];

	//繪製水果與 毒果
	for(i=0;i<tableBlockHeight;i++)
		for(j=0;j<tableBlockWidth;j++)
		{	
			x_pos = j*20+WALL_WIDTH;
			y_pos = i*20+WALL_HEIGHT;

			switch(table.GetData(j,i))
			{
			case TB_STATE_FOOD:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,100,0,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,20,0,SRCAND);
				break;
			case TB_STATE_BLOCK:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,80,0,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,0,0,SRCAND);
				break;
			}
		}

		//根據當前的狀態繪製蛇頭		
		x=table.GetSnake()->GetPos()[0].x;
		y=table.GetSnake()->GetPos()[0].y;
		x_pos = x*20+WALL_WIDTH;
		y_pos = y*20+WALL_HEIGHT;		
		state=table.GetSnake()->GetStateArray()[0];

		switch(state)
		{
		case M_UP_UP:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,80,20,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,0,20,SRCAND);
			break;
		case M_DOWN_DOWN:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,140,20,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,60,20,SRCAND);
			break;
		case M_LEFT_LEFT:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,100,20,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,20,20,SRCAND);
			break;
		case M_RIGHT_RIGHT:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,120,20,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,40,20,SRCAND);
			break;
		}

		//根據各個蛇身節點的狀態繪製蛇身的形狀
		for(i=1;i<table.GetSnake()->GetLength()-1;i++)
		{
			x=table.GetSnake()->GetPos()[i].x;
			y=table.GetSnake()->GetPos()[i].y;
			x_pos = x*20+WALL_WIDTH;
			y_pos = y*20+WALL_HEIGHT;	
			state=table.GetSnake()->GetStateArray()[i];
			switch(state)
			{
			case M_UP_UP:
			case M_DOWN_DOWN:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,80,40,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,0,40,SRCAND);
				break;
			case M_LEFT_LEFT:
			case M_RIGHT_RIGHT:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,100,40,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,20,40,SRCAND);
				break;
			case M_RIGHT_DOWN:
			case M_UP_LEFT:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,100,60,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,20,60,SRCAND);
				break;
			case M_LEFT_DOWN:
			case M_UP_RIGHT:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,80,60,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,0,60,SRCAND);
				break;
			case M_RIGHT_UP:
			case M_DOWN_LEFT:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,140,40,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,60,40,SRCAND);
				break;
			case M_LEFT_UP:
			case M_DOWN_RIGHT:
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,120,40,SRCPAINT);
				BitBlt(hdc,x_pos,y_pos,20,20,picDC,40,40,SRCAND);
				break;

			}
		}

		//繪製蛇尾巴
		x=table.GetSnake()->GetPos()[table.GetSnake()->GetLength()-1].x;
		y=table.GetSnake()->GetPos()[table.GetSnake()->GetLength()-1].y;
		x_pos = x*20+WALL_WIDTH;
		y_pos = y*20+WALL_HEIGHT;	
		state=table.GetSnake()->GetStateArray()[table.GetSnake()->GetLength()-1];		
		switch(state)
		{
		case M_UP_UP:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,120,60,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,40,60,SRCAND);
			break;
		case M_DOWN_DOWN:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,120,0,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,40,0,SRCAND);
			break;
		case M_LEFT_LEFT:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,140,60,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,60,60,SRCAND);
			break;
		case M_RIGHT_RIGHT:
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,140,0,SRCPAINT);
			BitBlt(hdc,x_pos,y_pos,20,20,picDC,60,0,SRCAND);
			break;
		}

		if(uGameState == GAME_STATE_END)
		{//繪製遊戲結束圖像
			x_pos = g_iClientWidth/3;
			y_pos = g_iClientHeight/4;

			BitBlt(hdc, x_pos, y_pos, 369, 300, endDC, 0, 0, SRCCOPY);			
		}
} 
