#include <windows.h>

#include <dshow.h>
#pragma comment(lib, "strmiids.lib") 


const int ID_MYBUTTON= 60001;
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
void SoundPlay(long index);
int Load_WAV();

struct sound
{
	IGraphBuilder *pGraphBuilder;
	IMediaControl *pMediaControl;
	IMediaSeeking *pMediaSeeking;
	IMediaEventEx *pMediaEventEx;
	WCHAR wFileName[256];
	char totalTime[256];
	LONGLONG totalDuration;
	LONGLONG lDuration100NanoSecs;
	float step;
	long temporary;
	char szFileName[256];
};
sound *Sound;


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName [] = TEXT ("Bricks1") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;

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
	 	 
	 CoInitialize(NULL);
	if (Load_WAV()!=0)return 0;


     ShowWindow (hwnd, SW_SHOWNORMAL) ;
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
				SoundPlay(0);				
				Sleep(1000);				
				Sound[0].pMediaControl->Stop(); 
				
				SoundPlay(1);
			}
			break;
			default:
				return DefWindowProc(hwnd, message, wParam, lParam);
		}
			break;
	case WM_KEYUP:
		{

			switch(wParam)
			{
			case VK_ESCAPE:
				{            
					SendMessage(hwnd, WM_DESTROY, NULL, NULL);
				}          
				break;
			}        
		}
		break;	

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
}
return 0;
}

int Load_WAV()
{
	HRESULT hr;
	char * str[2] = {"122821.mp3","122857.mp3"};
		
	Sound=new sound[2];	 
	for(int i=0;i<2;i++){
		strcpy(Sound[i].szFileName,str[i]);
	}
	wchar_t wFileName[256];
	for(int i=0;i<2;i++)
	{
		mbstowcs(wFileName, Sound[i].szFileName, 256);
		Sound[i].pGraphBuilder=NULL;
		Sound[i].pMediaControl=NULL;
		Sound[i].pMediaSeeking=NULL;
		Sound[i].pMediaEventEx=NULL;
		
		hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder,
			(void**)&Sound[i].pGraphBuilder);
		if (SUCCEEDED(hr))
		{
			hr = Sound[i].pGraphBuilder->QueryInterface(IID_IMediaControl, (void **)&Sound[i].pMediaControl);
			hr = Sound[i].pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void**)&Sound[i].pMediaSeeking);
			hr = Sound[i].pGraphBuilder->QueryInterface(IID_IMediaEventEx, (void**)&Sound[i].pMediaEventEx);
			Sound[i].pGraphBuilder->RenderFile(wFileName,NULL); 
			Sound[i].pMediaSeeking->GetDuration(&Sound[i].lDuration100NanoSecs);
			Sound[i].totalDuration = Sound[i].lDuration100NanoSecs/10000000;
			Sound[i].temporary = (long)Sound[i].totalDuration;
			Sound[i].step = (float)100/Sound[i].temporary;
		}
		
	}

	return 0;
}

void SoundPlay(long index)
{
	LONGLONG start=0;
	if(Sound[index].pMediaSeeking)
	{
		Sound[index].pMediaSeeking->SetPositions(&start,
		AM_SEEKING_AbsolutePositioning,
		&Sound[index].lDuration100NanoSecs
		,AM_SEEKING_AbsolutePositioning); 
		Sound[index].pMediaControl->Run(); 
	}
	
}