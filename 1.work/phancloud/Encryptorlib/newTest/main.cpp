
#include <bearlib.h>
#include <windows.h>
#include <iostream>
#include "ScrectKey\SCardAPI.h"
#include "phc_tst.h"
#include <boost\thread.hpp>


const int ID_MYBUTTON = 60001;
const int ID_MYBUTTON2 = 60002;
const int ID_MYBUTTON3 = 60003;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

int WINAPI WinMain(HINSTANCE hinstance, 
                             HINSTANCE hPrevInstance, 
                             LPSTR lpCmdLine, 
                             int nCmdShow) 
{     
    WNDCLASSEX wcx;         					//　視窗類
    HWND hwnd;             	 				//  視窗處理
    MSG msg;               					//　訊息    
   
    // 填充視窗類的資料結構
    wcx.cbSize = sizeof(wcx);				// 結構體的大小
    wcx.style = CS_HREDRAW | CS_VREDRAW;    // 樣式：大小改變時重繪介面 
    wcx.lpfnWndProc = WndProc; 			// 視窗訊息處理函數 
    wcx.cbClsExtra = 0;           			// 不使用類記憶體
    wcx.cbWndExtra = 0;          			// 不使用視窗記憶體 
    wcx.hInstance = hinstance;				// 所屬的應用程式實例處理 
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);  					// 圖示：使用預設值	
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW);						// 遊標：使用預設值
    wcx.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH);      					// 背景：白色
    wcx.lpszMenuName =  NULL;  				// 選單：不使用
    wcx.lpszClassName = "MainWClass";			// 視窗類名 
	wcx.hIconSm = (HICON)LoadImage(hinstance,	// 小圖示
         MAKEINTRESOURCE(5),
         IMAGE_ICON, 
         GetSystemMetrics(SM_CXSMICON), 
         GetSystemMetrics(SM_CYSMICON), 
         LR_DEFAULTCOLOR); 
 
    // 註冊視窗類
    if(!RegisterClassEx(&wcx))
    {
          return 1;
    }
 
      // 建立視窗 
      hwnd = CreateWindow( 
          "MainWClass",       	// 視窗名
          "Test",            	// 視窗標題 
         WS_OVERLAPPEDWINDOW,	// 視窗樣式  
         100,      	// 水準位元置X：使用預設值 
         100,      	// 垂直位元置Y：使用預設值
         640,       	// 寬度：使用預設值
         480,       	// 高度：使用預設值
         (HWND) NULL,         	// 父視窗：無 
         (HMENU) NULL,        	// 選單：使用視窗類的選單 
         hinstance,           	// 應用程式實例處理 
         (LPVOID) NULL);      	// 視窗建立時資料：無 
 
        if (!hwnd) 
        {
               return 1; 
         }
         // 顯示視窗 
         ShowWindow(hwnd, nCmdShow); 
         UpdateWindow(hwnd); 

              // 訊息迴圈
		while (GetMessage(&msg, NULL, 0, 0))
		{ 			 
			TranslateMessage(&msg);
			DispatchMessage(&msg);		 
		} 


    return msg.wParam; 
 
} 

HWND gtest	= NULL;
HWND gtest2	= NULL;
static unsigned long UsageCount = 0;

#define One ((int)(UsageCount > 30000)) 


LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;	
	
    switch (Message) 
    { 						
		case WM_CREATE: 		
		{			
			gtest = CreateWindow(TEXT("EDIT"), TEXT("gg"), WS_CHILD | WS_VISIBLE ,
				80, 200, 300, 20, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);

			gtest2 = CreateWindow(TEXT("EDIT"), TEXT("gg"), WS_CHILD | WS_VISIBLE ,
				80, 250, 300, 20, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);

				CreateWindow(TEXT("BUTTON"), TEXT("save"), WS_CHILD | WS_VISIBLE ,
				80, 135, 80, 20, hwnd, HMENU(ID_MYBUTTON), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);
				CreateWindow(TEXT("BUTTON"), TEXT("load"), WS_CHILD | WS_VISIBLE ,
				80, 165, 80, 20, hwnd, HMENU(ID_MYBUTTON2), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);
				CreateWindow(TEXT("BUTTON"), TEXT("count"), WS_CHILD | WS_VISIBLE ,
				80, 185, 80, 20, hwnd, HMENU(ID_MYBUTTON3), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);
		}
		break;	
		case WM_COMMAND:
			// 剖析功能表選取項目:		
		switch (LOWORD(wParam))
		{
		case ID_MYBUTTON:
			{												
				int var[25] ;
				UsageCount = 60000;
				var[0] = UsageCount;
				loadtable();
				SCard_SetIntArr(21,var);
				SCard_Save(21,1);
			}
			break;
		case ID_MYBUTTON2:
			{
				int var[25] ; 						
				loadtable();			
				SCard_Load(21,1);			
				SCard_GetIntArr(21,var);		
				char cc[25];
				sprintf(cc,"%d",Show_pool_int(21)[0]);
				SetWindowText(gtest2,cc);	
			}
			break;
		case ID_MYBUTTON3:
			{			

				int var[25]; 						
				loadtable();		
				//get
				SCard_Load(21,1);			
				SCard_GetIntArr(21,var);					
				unsigned long y = Show_pool_int(21)[0];
				unsigned long z = y+1;
				y *= y;
				y -= 1;
				UsageCount = y / z;
				//set
				var[0] = UsageCount;				
				SCard_SetIntArr(21,var);
				SCard_Save(21,1);				
				char cc[255];
				sprintf(cc,"%lu",Show_pool_int(21)[0]);
				SetWindowText(gtest2,cc);

					
				char ccd[255];
				sprintf(ccd,"%d",One);
				SetWindowText(gtest,ccd);

				
			}
			break;
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
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
			// TODO: 在此加入任何繪圖程式碼...			
			EndPaint(hwnd, &ps);
		break;
		case WM_DESTROY: 				
			PostQuitMessage(0);
            return 0; 
        default: 
             return DefWindowProc(hwnd, Message, wParam, lParam); 
    } 
	return 0;
}

