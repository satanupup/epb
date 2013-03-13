#include "pross_mem.h"
DWORD WINAPI ThreadProc_tst(LPVOID a)
{
	printf("%s\n", (char*)a);
	return 0;
}
DWORD WINAPI ThreadProc_bmap_tst(LPVOID a)
{
	HPEN hpen,hpenOLd;
	HBRUSH hbrush,hbrushOld,hbrush2;
	HDC hdc ;
	hdc = GetDC (GetConsoleWindow());
	COLORREF cPen = RGB(255,0 ,255);

	COLORREF cBrush = RGB(255,0,255);
	COLORREF cBrush2 = RGB(0,255,0);
	hpen = CreatePen(PS_SOLID,1,cPen);
	hbrush = CreateSolidBrush(cBrush);
	hbrush2 = CreateSolidBrush(cBrush2);
	hpenOLd=(HPEN)SelectObject(hdc,hpen);
	hbrushOld=(HBRUSH)SelectObject(hdc,hbrush);
	while(1)
	{

    Rectangle(hdc,330,0,350,48);
	(HBRUSH)SelectObject(hdc,hbrush2);
	Sleep(200);


	Rectangle(hdc,330,0,350,48);
	(HBRUSH)SelectObject(hdc,hbrush);
	Sleep(200);
	}
	SelectObject(hdc,hbrushOld);
	SelectObject(hdc,hpenOLd);
	DeleteObject(hpen);
	DeleteObject(hbrush);
	return 0;
}
DWORD WINAPI ThreadProc_bmap_tst2(LPVOID a)
{
	int  pg[10][10]={
		1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
		1 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1 ,1 ,1 ,0 ,0, 0 ,1 ,1 ,1 ,1,
		1 ,1 ,0 ,0 ,0, 0 ,0 ,1 ,1 ,1,
		1 ,0 ,1 ,0 ,0, 1 ,1 ,0 ,1 ,1,
		1 ,1 ,1 ,0 ,0, 1 ,1 ,1 ,0 ,1,
		1 ,1 ,0 ,1 ,1, 0 ,1 ,1 ,1 ,1,
		1 ,0 ,1 ,1 ,1, 1 ,0 ,1 ,1 ,1,
		1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1
	};
		int  pg2[10][10]={
		1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
		1 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1 ,1 ,1 ,0 ,0, 0 ,1 ,1 ,1 ,1,
		1 ,1 ,0 ,0 ,0, 0 ,0 ,1 ,1 ,1,
		1 ,0 ,1 ,0 ,0, 0 ,1 ,0 ,1 ,1,
		1 ,1 ,1 ,0 ,0, 0 ,1 ,1 ,1 ,1,
		1 ,1 ,1 ,0 ,1, 0 ,1 ,1 ,1 ,1,
		1 ,1 ,1 ,0 ,1, 0 ,1 ,1 ,1 ,1,
		1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,1
	};
	
	int v = 5;
	int xunitnum = 10;
	int yunitnum = 10;
	int xstart = 350;
	int ystart  = 20;
    HPEN hpen,hpenOLd;
	HBRUSH hbrush,hbrushOld,hbrush2;
	HDC hdc ;
	hdc = GetDC (GetConsoleWindow());
	COLORREF cPen = RGB(0,0 ,0);

	COLORREF cBrush = RGB(0,0,0);
	COLORREF cBrush2 = RGB(0,255,0);
	hpen = CreatePen(PS_SOLID,1,cPen);
	hbrush = CreateSolidBrush(cBrush);
	hbrush2 = CreateSolidBrush(cBrush2);
	hpenOLd=(HPEN)SelectObject(hdc,hpen);
	hbrushOld=(HBRUSH)SelectObject(hdc,hbrush);
	while(1)
	{
    for(int x =0 ; x< (xunitnum) ; x++)
	{
		for(int y = 0 ; y< (yunitnum) ; y++)
		{
		   if(pg [y][x] == 0)
		  {
			  (HBRUSH)SelectObject(hdc,hbrush2);
			  
		  }
		   else
		   {
			   (HBRUSH)SelectObject(hdc,hbrush);
		   }
		   Ellipse(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		 //  Rectangle(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		}
	}

	//(HBRUSH)SelectObject(hdc,hbrush2);
	Sleep(200);
	for(int x =0 ; x< (xunitnum) ; x++)
	{
		for(int y = 0 ; y< (yunitnum) ; y++)
		{
		   if(pg2 [y][x] == 0)
		  {
			  (HBRUSH)SelectObject(hdc,hbrush2);
			  
		  }
		   else
		   {
			   (HBRUSH)SelectObject(hdc,hbrush);
		   }
		   Ellipse(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		  // Rectangle(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		}
	}
	Sleep(100);
    for(int x =0 ; x< (xunitnum) ; x++)
	{
		for(int y = 0 ; y< (yunitnum) ; y++)
		{
			Ellipse(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		  // Rectangle(hdc,xstart + (x*v),ystart + (y*v),xstart + ((x+1)*v),(ystart + ((y+1)*v)));
		}
	}
	(HBRUSH)SelectObject(hdc,hbrush);
	Sleep(200);
	}
	SelectObject(hdc,hbrushOld);
	SelectObject(hdc,hpenOLd);
	DeleteObject(hpen);
	DeleteObject(hbrush);
 
	return 0;
}



