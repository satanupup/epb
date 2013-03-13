#include "stdafx.h"
int ConfiguationEventer::ConfiguationEventNumber = 0;

LRESULT CALLBACK DialogProcCONFIGUATION_TITLE( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	static bool CONFIGUATIONbChangeText = true;
	PAINTSTRUCT ps;
	HDC hdc; 
	HMENU hMenu, hSubMenu;
	
	switch(msg)  
	{
		case WM_CREATE:	 
		{				
			
			hMenu = CreateMenu();
			hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_SEPARATOR, 0, NULL);			
			AppendMenu(hMenu, MF_STRING, (UINT)ID_MYBUTTON, L"Always displayed on top");
			SetMenu(hwnd, hMenu);	
			DestroyMenu(hSubMenu);

			SetWindowPos(hwnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

			CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						5, 0, 370*One, 325*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
			CreateWindow(L"STATIC", 
						L"server IP", WS_CHILD | WS_VISIBLE,
						10, 11, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);	
			
			hConfiguationIPText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						80, 11, 160*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);

			SetWindowText(hConfiguationIPText,bearlib::wreadcfg().c_str());		

		}
		break;
		case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
		case ID_MYBUTTON:
			{		
				if (CONFIGUATIONbChangeText)
               { 
					hMenu = GetMenu(hwnd); 					
					ModifyMenu(hMenu, ID_MYBUTTON, MF_STRING, ID_MYBUTTON, L"The general level"); 
					SetMenu(hwnd, hMenu);	
					SetWindowPos(hwnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);														
               }
               else
               {									
					hMenu = GetMenu(hwnd); 					
					ModifyMenu(hMenu, ID_MYBUTTON, MF_STRING, ID_MYBUTTON, L"Always displayed on top"); 
					SetMenu(hwnd, hMenu);					
					SetWindowPos(hwnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
               }
               CONFIGUATIONbChangeText = !CONFIGUATIONbChangeText;
			}
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		break;	
		case WM_KEYUP:
		{						
			switch(wParam)
			{
				case VK_ESCAPE:
				{     					
					SendMessage(hwnd, WM_CLOSE, NULL, NULL);
				}          
				break;			
			}        
		}
		break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			// TODO: 在此加入任何繪圖程式碼...
			//TextOut(hdc,20,20,L"CONFIGUATION",12);
			EndPaint(hwnd, &ps);
		break;
		case WM_CLOSE:
			ConfiguationEventer::ConfiguationEventNumber = ConfiguationEventer::ConfiguationEventNumber -1;
			DestroyWindow(hwnd);
			break;       
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
  

}


void RegisterDialogCONFIGUATION_TITLE(HWND hwnd) 
{
  WNDCLASSEX wc = {0};
  wc.cbSize           = sizeof(WNDCLASSEX);
  wc.lpfnWndProc      = (WNDPROC) DialogProcCONFIGUATION_TITLE;
  wc.hInstance        = MainApp::hinst;
  wc.hbrBackground    = GetSysColorBrush(COLOR_3DFACE);
  wc.lpszClassName    = TEXT("DialogProcCONFIGUATION_TITLE");
  RegisterClassEx(&wc);

  
  RECT rect; 
	int ScreenWidth= GetSystemMetrics(SM_CXSCREEN); 
	int ScreenHeight= GetSystemMetrics(SM_CYSCREEN); 
	GetWindowRect(hwnd,&rect);
	int width = rect.right-rect.left;
	int height = rect.bottom-rect.top;
	   
 //WS_EX_DLGMODALFRAME 去掉視窗小圖示 | WS_EX_TOPMOST 總是在前
 CreateWindowEx(WS_EX_APPWINDOW |WS_EX_DLGMODALFRAME | WS_EX_TOPMOST, TEXT("DialogProcCONFIGUATION_TITLE"), TEXT("CONFIGUATION"), 
 WS_VISIBLE | WS_SYSMENU | WS_CAPTION , ScreenWidth/2-width/2, (ScreenHeight/2-height/2)+50, 400, 400, 
 NULL, NULL, MainApp::hinst, NULL);


//   CreateWindowEx(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,  TEXT("DialogProcCONFIGUATION_TITLE"), TEXT("CONFIGUATION"), 
//        WS_VISIBLE | WS_SYSMENU | WS_CAPTION , 100, 100, 400, 400, 
//        NULL, NULL, MainApp::hinst,  NULL);
   
   ConfiguationEventer::ConfiguationEventNumber = ConfiguationEventer::ConfiguationEventNumber +1;
}