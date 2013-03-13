#include <windows.h>
#include <GdiPlus.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <wininet.h>
#include <string>
#include <vector>
#pragma comment(lib,"wininet")
#pragma comment(lib, "gdiplus.lib") 
using namespace Gdiplus;
using namespace std;

int Download(const string& url, ostream& output) ;
//std::wstring s2ws(const std::string& s);
void abc2(std::string b);
void abc(std::string b);
void ShowFont(HDC pDC,std::wstring a,int b,int c,int d);
void ShowImage(HDC pDC);

const int BUF_SIZE = 1024;
const int ID_MYBUTTON= 60001;
const int ID_PASSWDTEXT= 60009;
const RECT testWhiteTimerRect = {0,0,400,300};
HWND hEditText= NULL;
GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName [] = TEXT ("Bricks1") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;
///////////////////////
GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     
     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Demo"), 
                            WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT, CW_USEDEFAULT,
                            640, 480,
                            NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;

     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam)
{   
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
	{
	hEditText =  CreateWindow(TEXT("Edit"), 
                TEXT(""), WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT ,
                216, 56, 260, 28, hwnd, (HMENU)ID_PASSWDTEXT, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
          CreateWindow(TEXT("BUTTON"), 
                TEXT("Button"), WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                378, 96, 100, 40, hwnd, (HMENU)ID_MYBUTTON, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
  
	}
	return 0 ;
	case WM_COMMAND:
	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
// 剖析功能表選取項目:
	switch (wmId)
	{
		case ID_MYBUTTON:
		{

			char  lpString[128] = "\0"; 
			GetWindowTextA(hEditText,lpString,128); 
			abc(lpString);
			Sleep(100);
			abc2(lpString);
			Sleep(100);

			std::ifstream fin("test.txt");
			if(!fin)
			{   
			} 
			std::string s;
			std::string substr;
			char strText[512];
			while(std::getline(fin,s))
			{
				int nLenOfWcharStr=MultiByteToWideChar(CP_UTF8,0, s.c_str(),-1,NULL,0); 
				PWSTR pWideCharStr=(PWSTR)malloc(nLenOfWcharStr*sizeof(wchar_t));
				if(pWideCharStr!=NULL)
				MultiByteToWideChar(CP_UTF8,0, s.c_str(),-1,pWideCharStr,nLenOfWcharStr);
				WideCharToMultiByte ( CP_ACP, 0, pWideCharStr, -1, strText, 510, NULL, NULL );
				substr += strText;
			}
			fin.close();   

			Sleep(100);
			InvalidateRect(hwnd,&testWhiteTimerRect,true);     
			UpdateWindow (hwnd) ;
		}
		break;
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// TODO: 在此加入任何繪圖程式碼...
		ShowImage(hdc);
		
		ShowFont(hdc,L"開始更新程式",50,5,185);

		EndPaint(hwnd, &ps);
	break;
	case WM_DESTROY:

		GdiplusShutdown(gdiplusToken);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
}
return 0;
}


void ShowImage(HDC pDC)
{
	Graphics imgraphics( pDC );
	Image image(L"test.png");  
	imgraphics.DrawImage(&image,0,0);
}

void ShowFont(HDC pDC,std::wstring a,int b,int c,int d)
{
	Graphics mygraphics(pDC);            
	SolidBrush brush( Color(100,0,0,255) );   
	FontFamily fontFamily(L"Latha");       
	Font font( &fontFamily, (Gdiplus::REAL)b, FontStyleRegular,UnitWorld );     

	PointF pointF((Gdiplus::REAL)c,(Gdiplus::REAL)d);
	mygraphics.DrawString( a.c_str(), -1, &font, pointF, &brush );

}
void abc(std::string b)
{
	errno_t err;
	FILE *fd;
	   if( (err  = fopen_s( &fd, "test.png", "wb" )) !=0 )
		  printf( "The file 'crt_fopen_s.c' was not opened\n" );
	   else
		  printf( "The file 'crt_fopen_s.c' was opened\n" );


	///
	ofstream f(fd);

	std::string a;
	a += "http://avatar2.bahamut.com.tw/avataruserpic/";
	a += b.substr(0,1).c_str();
	a += "/";
	a += b.substr(1,1).c_str();
	a += "/";
	a += b.c_str();
	a += "/" ;
	a += b.c_str();
	a += ".png";

	std::string c = "http://avatar2.bahamut.com.tw/avataruserpic/b/a/babu61509/babu61509.png";

	int re = Download(a.c_str(), f);
	//////////
fclose (fd);
}


void abc2(std::string b)
{
	ofstream f("test.txt",std::ios::trunc);
	std::string a;
	a += "http://home.gamer.com.tw/homeindex.php?owner=";
	a += b.c_str();
	int re = Download(a.c_str(), f);
	f.close();
}

int Download(const string& url, ostream& output) {
   
   char buffer[BUF_SIZE];
   HINTERNET hUrl, hInet;
   DWORD rcv, total = 0;
  
   if (InternetAttemptConnect(0) != ERROR_SUCCESS) return 0;

   hInet = InternetOpen(L"download", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
   
   if (hInet == NULL) return 0;

   hUrl = InternetOpenUrlA(hInet, url.c_str(), NULL, 0, INTERNET_FLAG_NO_CACHE_WRITE, 0);
          
   if (hUrl == NULL) return 0;
  
   do {      
   InternetReadFile(hUrl, &buffer, BUF_SIZE, &rcv);
      output.write(buffer, rcv);
      total += rcv;
   } while (rcv > 0);
  
   InternetCloseHandle(hUrl);
   InternetCloseHandle(hInet);

   return total;
}