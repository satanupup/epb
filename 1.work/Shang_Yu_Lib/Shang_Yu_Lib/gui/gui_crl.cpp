#include "../applay_entry.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <io.h>


VOID gdi_out_area(HDC hdc)
{
	HPEN hpen,hpenOLd;
	HBRUSH hbrush,hbrushOld;
	POINT lppt;
	BYTE bRed =0;
	BYTE bGreen =0;
	BYTE bBlue = 0;
	COLORREF cPen = RGB(255,255 ,255);
	COLORREF cBrush = RGB(223,GetGValue(cPen),255);
	
	hpen = CreatePen(PS_SOLID,10,cPen);
	hbrush = CreateSolidBrush(cBrush);
	hpenOLd=(HPEN)SelectObject(hdc,hpen);
	hbrushOld=(HBRUSH)SelectObject(hdc,hbrush);
	MoveToEx(hdc,1,1,&lppt);
	LineTo(hdc,8,500);
	SelectObject(hdc,hbrushOld);
    Rectangle(hdc,20,20,500,500);
	
	DeleteObject(hpen);
	DeleteObject(hbrush);
 }
VOID GDI_TEXT(LPSTR s, HDC hdc,int x,int y)
{
//	HFONT hfntDefault, hfntDefault2;
	DWORD sLen = lstrlen(s);
	SetBkColor(hdc,RGB(255,255,255));
	SetTextColor(hdc,RGB(195,170,23));
	SetBkMode(hdc,TRANSPARENT);
//	hfntDefault2 = (HFONT)SelectObject(hdc,hfntDefault);
	
	TextOut(hdc,x,y,s, sLen);
}

VOID GetWinFormSize(HWND hWnd)
{
	 RECT rect;
     GetWindowRect(hWnd, &rect);
	 printf("%d,%d,%d,%d\n" ,rect.left,rect.right,rect.top,rect.bottom );
}
VOID gdi_tst ()
{
//	HWND s;
	HDC hdc ;

	//EnumDC(
	//GetWindows
	//hdc = GetDC (NULL);
	hdc = GetDC (GetConsoleWindow());
	GDI_TEXT("PHANCLOUD", hdc,0,28);
	//GetClientRect(
/*	s=WindowFromDC(hdc);
	hdc = GetDC (s);*/


	//hdc= GetWindowDC(GetTopWindow(NULL));

	//hdc=CreateDC("DISPLAY",NULL,NULL,NULL);
	gdi_out_area(hdc);
	ReleaseDC(NULL,hdc);
}


VOID Get_Bmpinfo()
{
    WORD bfType;//1
    DWORD bfSize;//2
    WORD bfReserved1;//3
    WORD bfReserved2;//4
    DWORD bfOffBits;//5
    DWORD biSize;//6
    LONG biWidth;//7
    LONG biHeight;//8
    WORD biPlanes;//9
    WORD biBitCount;//10
    DWORD biCompression;//11
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
	FILE *fp;
	RGBQUAD rgbb;
	fp = fopen ("startpic.bmp","r");
	if(fp != NULL)
	{
		fread((void*)(&bfType),sizeof(WORD),1,fp);//1
		fread((void*)(&bfSize),sizeof(DWORD),1,fp);//2
		fread((void*)(&bfReserved1),sizeof(WORD),1,fp);//3
		fread((void*)(&bfReserved2),sizeof(WORD),1,fp);//4
		fread((void*)(&bfOffBits),sizeof(DWORD),1,fp);//5
		fread((void*)(&biSize),sizeof(DWORD),1,fp);//6
		fread((void*)(&biWidth),sizeof(LONG),1,fp);//7
		fread((void*)(&biHeight),sizeof(LONG),1,fp);//8
		fread((void*)(&biPlanes),sizeof(WORD),1,fp);//9
		fread((void*)(&biBitCount),sizeof(WORD),1,fp);//10
		fread((void*)(&biCompression),sizeof(DWORD),1,fp);
		fread((void*)(&biSizeImage),sizeof(DWORD),1,fp);
		fread((void*)(&biXPelsPerMeter),sizeof(LONG),1,fp);
		fread((void*)(&biYPelsPerMeter),sizeof(LONG),1,fp);
		fread((void*)(&biClrUsed),sizeof(DWORD),1,fp);
		fread((void*)(&biClrImportant),sizeof(DWORD),1,fp);
	//	fread((void*)(&rgbb),sizeof(RGBQUAD),1,fp);

//BITMAP k;
//k.
        std::cout << "FILE_HEADER\n"
         << "bfType=\t\t"       << bfType       << '\n'
         << "bfSize=\t\t"       << bfSize       << '\n'
        << "bfReserved1=\t"    << bfReserved1  << '\n'
         << "bfReserved2=\t"    << bfReserved2  << '\n'
        << "bfOffBits=\t"      << bfOffBits    << "\n\n"
         << "INFO_HEADER\n"
         << "biSize=\t\t"       << biSize       << '\n'
         << "biWidth=\t"        << biWidth      << '\n'
         << "biHeight=\t"       << biHeight     << '\n'
        << "biPlanes=\t"       << biPlanes     << '\n'
         << "biBitCount=\t"     << biBitCount   << '\n'
         << "biCompression=\t"  << biCompression    << '\n'
         << "biSizeImage=\t"    << biSizeImage      << '\n'
         << "biXPelsPerMeter="  << biXPelsPerMeter  << '\n'
         << "biYPelsPerMeter="  << biYPelsPerMeter  << '\n'
         << "biClrUsed=\t"      << biClrUsed        << '\n'
        << "biClrImportant=\t" << biClrImportant   << "\n\n"<<std::endl;

			}


}

HBITMAP LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{

	// ss;
FILE *filePtr; //our file pointer
BITMAPFILEHEADER bitmapFileHeader; //our bitmap file header
unsigned char *bitmapImage;  //store image data
int imageIdx=0;  //image index counter
unsigned char tempRGB;  //our swap variable

//open filename in read binary mode
filePtr = fopen(filename,"rb");
if (filePtr == NULL)
return NULL;

//read the bitmap file header
fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER),1,filePtr);

//verify that this is a bmp file by check bitmap id
if (bitmapFileHeader.bfType !=0x4D42)
{
fclose(filePtr);
return NULL;
}

//read the bitmap info header
fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER),1,filePtr);

//move file point to the begging of bitmap data
fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

//allocate enough memory for the bitmap image data
bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

//verify memory allocation
if (!bitmapImage)
{
free(bitmapImage);
fclose(filePtr);
return NULL;
}

//read in the bitmap image data
fread(bitmapImage,bitmapInfoHeader->biSizeImage,1,filePtr);

//make sure bitmap image data was read
if (bitmapImage == NULL)
{
fclose(filePtr);
return NULL;
}

//swap the r and b values to get RGB (bitmap is BGR)
for (imageIdx = 0;imageIdx < bitmapInfoHeader->biSizeImage;imageIdx+=3)
{
tempRGB = bitmapImage[imageIdx];
bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
bitmapImage[imageIdx + 2] = tempRGB;
}

//close file and return bitmap iamge data
fclose(filePtr);

//return bitmapImage;
return (HBITMAP)bitmapImage;
}

VOID DoPaint(HWND hWnd, DWORD dwMode)
{
	HBITMAP ghBitmap = (HBITMAP)LoadImage(NULL,"startpic.bmp",IMAGE_BITMAP,0,0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	PAINTSTRUCT ps;
	RECT rect;
	HDC hdcMem;
	BITMAP bm;
	HDC hDC = BeginPaint(hWnd, &ps);
	GetClientRect(hWnd, &rect);
	SetStretchBltMode(hDC, HALFTONE);
	hdcMem = CreateCompatibleDC(hDC);
	SelectObject(hdcMem, ghBitmap);
	if (ghBitmap)
	{
		if (GetObject(ghBitmap, sizeof(BITMAP), &bm))
		{
			if(dwMode == 1)
			{
				StretchBlt(hDC, 0, 0, rect.right, rect.bottom,
					hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
			}
			else
			{
				INT ixStart = (rect.right - rect.left - bm.bmWidth)/2;
				INT iyStart = (rect.bottom - rect.top - bm.bmHeight)/2;
				ixStart = ixStart < 0 ? 0 : ixStart;
				iyStart = iyStart < 0 ? 0 : iyStart;
				BitBlt(hDC, 0, 0, rect.right, rect.bottom,
					hdcMem,-ixStart,-iyStart, SRCCOPY);
			}
			DeleteDC(hdcMem);
		}
	}

	else
	{
		PatBlt(hDC, 0, 0, rect.right, rect.bottom, BLACKNESS);
	}
	//EndPaint(hWnd, &ps);
}



void screen_get(char* filename)
{

// This function only works for 24-bit (truecolor) display mode

// prepare DCs, bitmaps,..
HDC hScreenDC = GetWindowDC(0);
HDC hmemDC = CreateCompatibleDC(hScreenDC);
int ScreenWidth = GetDeviceCaps(hScreenDC, HORZRES);
int ScreenHeight = GetDeviceCaps(hScreenDC, VERTRES);
HBITMAP hmemBM = CreateCompatibleBitmap(hScreenDC, ScreenWidth,
ScreenHeight);
SelectObject(hmemDC, hmemBM);

// copy screen to memory DC
BitBlt(hmemDC, 0, 0, ScreenWidth, ScreenHeight, hScreenDC, 0, 0,
SRCCOPY);

// allocate and lock memory for the bitmap data
HGLOBAL hpxldata = GlobalAlloc(GMEM_FIXED, ScreenWidth * ScreenHeight
* 3);
void FAR* lpvpxldata = GlobalLock(hpxldata);

// fill .bmp - structures
BITMAPINFO bmInfo;
bmInfo.bmiHeader.biSize = 40;
bmInfo.bmiHeader.biWidth = ScreenWidth;
bmInfo.bmiHeader.biHeight = ScreenHeight;
bmInfo.bmiHeader.biPlanes = 1;
bmInfo.bmiHeader.biBitCount = 24;
bmInfo.bmiHeader.biCompression = 0;
bmInfo.bmiHeader.biSizeImage = 0;
bmInfo.bmiHeader.biXPelsPerMeter = 0;
bmInfo.bmiHeader.biYPelsPerMeter = 0;
bmInfo.bmiHeader.biClrUsed = 0;
bmInfo.bmiHeader.biClrImportant = 0;

BITMAPFILEHEADER bmFileHeader;
bmFileHeader.bfType = 19778;
bmFileHeader.bfSize = (ScreenWidth * ScreenHeight * 3) + 40 + 14;
bmFileHeader.bfReserved1 = 0;
bmFileHeader.bfReserved2 = 0;
bmFileHeader.bfOffBits = 54;

// copy bitmap data into global memory
GetDIBits(hmemDC, hmemBM, 0, ScreenHeight, lpvpxldata, &bmInfo,DIB_RGB_COLORS);


// SetDIBits(hmemDC, hmemBM, 0, ScreenHeight, lpvpxldata, &bmInfo,DIB_RGB_COLORS);
SetDIBitsToDevice(hmemDC, 0, 0, ScreenWidth, ScreenHeight, 0, 0, 0,ScreenHeight, lpvpxldata, &bmInfo, DIB_RGB_COLORS);
// StretchDIBits(hmemDC, 0, 0, ScreenWidth, ScreenHeight, 0, 0,ScreenWidth, ScreenHeight, lpvpxldata, &bmInfo, DIB_RGB_COLORS,SRCCOPY);

// open file and write data
int bmfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,S_IWRITE);
write(bmfile, &bmFileHeader, 14);
write(bmfile, &bmInfo, 40);
write(bmfile, lpvpxldata, ScreenWidth * ScreenHeight * 3);

// clean up
close(bmfile);
GlobalUnlock(hpxldata);
GlobalFree(hpxldata);
DeleteObject(hmemBM);
DeleteDC(hmemDC);
ReleaseDC(0, hScreenDC);
}



VOID bitmap_show(char *filename,HDC hdc)
{
	BITMAP Bitmap;
	//ptu2();
	HDC hdc2;
//	BITMAPINFOHEADER bitmapInfoHeader;
	//HDC hdc ,hdc2;
//	hdc = GetDC (GetConsoleWindow());
	
	//hdc = GetDC (GetTopWindow(NULL));
	//hdc = GetDC (NULL);

	hdc2 = CreateCompatibleDC(hdc);
	//ghBitmap = LoadBitmapFile("startpic.bmp", &bitmapInfoHeader);
	HBITMAP ghBitmap = (HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
	SelectObject(hdc2, ghBitmap);

	GetObject(ghBitmap,sizeof(BITMAP),(LPVOID)&Bitmap);
	
	BitBlt(hdc,0,0,Bitmap.bmWidth,Bitmap.bmHeight,hdc2,0,0,SRCCOPY);
	
	//DoPaint(GetTopWindow(NULL), 1);
	//ReleaseDC(NULL,hdc); 
	DeleteDC(hdc2);
}
VOID bitmap_show_TOP()
{
	HDC hdc;
	hdc = GetDC (NULL);
	char *a="startpic.bmp";
	bitmap_show(a,hdc);
}


VOID bitmap_test()
{
	HDC hdc ,hdc2;
	hdc = GetDC (GetConsoleWindow());
	char *a="startpic.bmp";
	bitmap_show(a,hdc);
}
