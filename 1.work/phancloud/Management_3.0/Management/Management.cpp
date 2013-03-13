// Management 2.0.cpp : 定義應用程式的進入點。
//

#include "stdafx.h"
//加密
//#include "ScrectKey\SCardAPI.h"
//#include "phc_tst.h"

unsigned long MainApp::UsageCount = 0;

//#include "vld.h"
//#pragma   comment(lib,"vld.lib")
HINSTANCE MainApp::hinst; 
/* 公用變數　*/
HACCEL MainApp::hAccel ;//加速鍵
ACCEL MainApp::Accel[3] ;

HWND MainApp::title1 = NULL;
HWND MainApp::title2 = NULL;
HWND MainApp::title3 = NULL;
HWND MainApp::title4 = NULL;
HWND MainApp::title5 = NULL;
HWND MainApp::title6 = NULL;
HWND MainApp::title7 = NULL;
HWND MainApp::title8 = NULL;
HWND MainApp::title9 = NULL;
HWND MainApp::title10 = NULL;
HWND MainApp::title11 = NULL;
HWND MainApp::title12 = NULL;
HWND MainApp::title13 = NULL;
HWND MainApp::title14 = NULL;
HWND MainApp::title15 = NULL;

HWND MainApp::Account	= NULL;
HWND MainApp::Password	= NULL;
HWND MainApp::Login		= NULL;


int WINAPI WinMain(
    HINSTANCE /* hInstance */,
    HINSTANCE /* hPrevInstance */,
    LPSTR /* lpCmdLine */,
    int /* nCmdShow */
    )
{		
    // Ignore the return value because we want to continue running even in the
    // unlikely event that HeapSetInformation fails.
    HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	

    if (SUCCEEDED(CoInitialize(NULL)))
    {
        {			
		  	MainApp app;
			if (SUCCEEDED(app.Initialize()))
			{
				app.RunMessageLoop();
			}
		
        }
        CoUninitialize();
    }

    return 0;
}

MainApp::MainApp() :
    m_hwnd(NULL),
	hInstance(NULL)
{
}

//
// Release resources.
//
MainApp::~MainApp()
{
}
HRESULT MainApp::Initialize()
{    	       

	hinst = hInstance;      					// 應用程式實例處理，保存為公用變數
	//加速鍵
	Accel[0].fVirt = 0 ;
    Accel[0].key = VK_TAB;
    Accel[0].cmd = IDC_TAB ;           
    hAccel = CreateAcceleratorTable (Accel, 1) ;


	WNDCLASSEX wcex = { sizeof(wcex) };
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = WndProc;
	wcex.cbClsExtra    = 0 ;
    wcex.cbWndExtra    = sizeof(LONG_PTR);
    wcex.hInstance     = hInstance;
	//wcex.hIcon        = LoadIcon (NULL, IDI_APPLICATION) ; 
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);		
    wcex.hbrBackground = (HBRUSH) GetSysColorBrush(COLOR_3DFACE);//GetStockObject (WHITE_BRUSH) ; 
    wcex.lpszMenuName  = NULL ;
    wcex.lpszClassName = TEXT("Management");	
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));
	
    RegisterClassEx(&wcex);

	

    // Create the application window.
    	/*
	  m_hwnd = CreateWindow (TEXT ("Management"), TEXT ("PhcAdmin"), 
        WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, CW_USEDEFAULT, 
        640, 480, 
        NULL, NULL, hInstance, NULL) ; */
		  
	

      m_hwnd = CreateWindowEx(WS_EX_APPWINDOW |WS_EX_DLGMODALFRAME ,TEXT("Management"),
		  TEXT("PhcAdmin"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX  ,
      CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, 0, 0, hInstance, NULL);
	 
		
	RECT   rect;   
	int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
	int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
	GetWindowRect(m_hwnd,&rect);
	int width = rect.right-rect.left;
	int height = rect.bottom-rect.top;
	MoveWindow(m_hwnd,ScreenWidth/2-width/2,ScreenHeight/2-height/2,width,height,TRUE);


	//不能多開程式
	TCHAR strappname[] = TEXT("Management"); 
    HANDLE hmutex = NULL; 
    //創建互斥對象 
    hmutex = CreateMutex(NULL, false, strappname); 
    if (hmutex != NULL) 
    { 
		if (GetLastError() == ERROR_ALREADY_EXISTS) 
		{ 
			MessageBox(NULL,TEXT("另外一程式尚在執行！請關閉此程式"),TEXT("SMSServer"),MB_OK |MB_ICONINFORMATION); 
			//關閉互斥對象，退出程序 
			SendMessage (m_hwnd, WM_DESTROY, 0, 0) ;			
			CloseHandle(hmutex); 
        return FALSE; 
		} 
    } 
    else 
    { 
        MessageBox(NULL,TEXT("無法建立Mutex!請重新執行"),TEXT("SMSServer"),MB_OK |MB_ICONINFORMATION); 
        //關閉互斥對象，退出程序 
		SendMessage (m_hwnd, WM_DESTROY, 0, 0) ;		
		if(hmutex != NULL)
			CloseHandle(hmutex); 
        return FALSE; 
    }
 

	ShowWindow(m_hwnd, SW_SHOWNORMAL);
	UpdateWindow(m_hwnd);
	
    return 1;
}


void MainApp::RunMessageLoop()
{
    MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        if (!TranslateAccelerator (m_hwnd, hAccel, &msg))//加速鍵 要跟CreateWindow放在一起才有全域效果
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);	
        }
    } 
}


LRESULT CALLBACK MainApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     	HDC        hdc ; 
		PAINTSTRUCT  ps;	
		int wmId, wmEvent;
		
		//static HMENU hMenu; 					

     	switch (message)
     	{
     	case WM_CREATE:
			{		
			//	MainApp::GetCard();
				/*
			hMenu = CreateMenu();			
			AppendMenu(hMenu, MF_STRING, ID_GROUPUSER_TITLE, L"Group&User");		
			AppendMenu(hMenu, MF_STRING, ID_PROGRAM_TITLE, L"Program");
			AppendMenu(hMenu, MF_STRING, ID_CONFIGUATION_TITLE, L"Configuation");			
			SetMenu(hwnd, hMenu);*/

			int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
			int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
	
	{//title			
	           
		title1 = CreateWindow(L"BUTTON", 
						L"Administration",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						20, 240, 580, 190, hwnd, NULL,//(HMENU)ID_MYBUTTON, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);

		title2 = CreateWindow(L"STATIC", 
						L"PhcAdmin", 
						WS_CHILD | WS_VISIBLE ,
						13, 20, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title3 = CreateWindow(L"STATIC", 
						L"Version", 
						WS_CHILD | WS_VISIBLE ,
						13, 55, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title4 = CreateWindow(L"STATIC", 
						L"License", 
						WS_CHILD | WS_VISIBLE ,
						13, 90, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title5 = CreateWindow(L"STATIC", 
						L"Server", 
						WS_CHILD | WS_VISIBLE ,
						13, 125, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title6 = CreateWindow(L"STATIC", 
						L"Login", 
						WS_CHILD | WS_VISIBLE ,
						13, 160, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title7 = CreateWindow(L"STATIC", 
						L"Usage", 
						WS_CHILD | WS_VISIBLE ,
						13, 195, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 

		title8 = CreateWindow(L"Edit", 
						L"2.7.42",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						100, 55, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title9 = CreateWindow(L"Edit", 
						L"phancloud",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						100, 90, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 	
		title15 = CreateWindow(L"Edit", 
						L"127.0.0.1",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						100, 125, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title10 = CreateWindow(L"Edit", 
						L"Admin",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						100, 160, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title11 = CreateWindow(L"Edit", 
						L"28920",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						100, 195, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title12 = CreateWindow(L"Button", 
						L"Group/Users",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						40, 280, 160*One, 130*One, hwnd, (HMENU)ID_GROUPUSER_TITLE, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 	
		title13 = CreateWindow(L"Button", 
						L"App",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						230, 280, 160*One, 130*One, hwnd, (HMENU)ID_PROGRAM_TITLE, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title14 = CreateWindow(L"Button", 
						L"Config",
						WS_CHILD | WS_VISIBLE |WS_BORDER,
						420, 280, 160*One, 130*One, hwnd, (HMENU)ID_CONFIGUATION_TITLE, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		

		bearlib::wreadcfg(0);	//從文件讀取IP，放置到記憶體

	}  
					
	//登入0615
				/*
	ShowWindow(title1,SW_HIDE);
	ShowWindow(title2,SW_HIDE);
	ShowWindow(title3,SW_HIDE);
	ShowWindow(title4,SW_HIDE);
	ShowWindow(title5,SW_HIDE);
	ShowWindow(title6,SW_HIDE);
	ShowWindow(title7,SW_HIDE);
	ShowWindow(title8,SW_HIDE);
	ShowWindow(title9,SW_HIDE);
	ShowWindow(title10,SW_HIDE);
	ShowWindow(title11,SW_HIDE);
	ShowWindow(title12,SW_HIDE);
	ShowWindow(title13,SW_HIDE);
	ShowWindow(title14,SW_HIDE);
	ShowWindow(title15,SW_HIDE);
	
	SetWindowText(MainApp::title15,bearlib::wreadcfg().c_str());
	*/
	//0615
	/*
	Account =		CreateWindow(TEXT("Edit"), 
                TEXT(""), WS_CHILD | WS_VISIBLE |WS_BORDER,
                16, 16, 260*One, 28*One, hwnd, (HMENU)ID_ACCOUNTTEXT, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL); 					
    Password =        CreateWindow(TEXT("Edit"), 
                TEXT(""), WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_PASSWORD,
                16, 56, 260*One, 28*One, hwnd, (HMENU)ID_PASSWDTEXT, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
    Login	=        CreateWindow(TEXT("BUTTON"), 
                TEXT("Login"), WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                128, 96, 149*One, 40*One, hwnd, (HMENU)ID_MYBUTTON, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
	*/
			//bear
	////////////////////////////////////////////登入0615
	/*
			RECT   rect;   
			GetWindowRect(hwnd,&rect);
			int width = rect.right-rect.left;
			int height = rect.bottom-rect.top;
			MoveWindow(hwnd,ScreenWidth/2-width/2,ScreenHeight/2-height/2,300,200,TRUE);

			SetWindowText(hwnd,L"PhcAdmin");
			*/
			///////////////////////////////
			sendCGlobal::ClientVerification();//判斷是否可以連到伺服器
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
				SetFocus(Login);					
				GetAppDlgItemText(hwnd,ID_ACCOUNTTEXT,ID_PASSWDTEXT); //輸入帳密
				Sleep(100);	
				
				
            }
            break;
		case IDC_TAB:
			{							
				SendMessage(hwnd, WM_DESTROY, NULL, NULL);
			}
			break;
        case IDM_EXIT:
            {
               SendMessage(hwnd, WM_DESTROY, NULL, NULL);		
            }
            break;		
		case ID_GROUPUSER_TITLE://群組及使用者介面
			{				
				HANDLE DestHandle;
				DestHandle = FindWindow(NULL,L"GROUPUSER");
				//開啟groupuser的介面，同一時間只能開一個
				if (DestHandle != 0) 
				{				
					SetForegroundWindow((HWND)DestHandle);
					ShowWindow((HWND)DestHandle, SW_RESTORE);
				}

				if(GroupEventer::GroupEventNumber < 1)
					RegisterDialogGROUPUSER_TITLE(hwnd);					
				/*
				wTmp = boost::lexical_cast<string>( CGlobal::str );		
				OutputDebugString(wTmp.c_str());*/
			}
			break;
		case ID_PROGRAM_TITLE://軟體勾選
			{		
				HANDLE DestHandle;
				DestHandle = FindWindow(NULL,L"PROGRAM");
				//開啟program的介面，同一時間只能開一個
				if (DestHandle != 0) 
				{				
					SetForegroundWindow((HWND)DestHandle);
					ShowWindow((HWND)DestHandle, SW_RESTORE);
				}
				if(ProgramEventer::ProgramEventNumber < 1)
					RegisterDialogPROGRAM_TITLE(hwnd);				
			}
			break;
		case ID_CONFIGUATION_TITLE:
			{										
				HANDLE DestHandle;
				DestHandle = FindWindow(NULL,L"CONFIGUATION");
				if (DestHandle != 0) 
				{				
					SetForegroundWindow((HWND)DestHandle);
					ShowWindow((HWND)DestHandle, SW_RESTORE);
				}		

				if(ConfiguationEventer::ConfiguationEventNumber < 1)
					RegisterDialogCONFIGUATION_TITLE(hwnd);				
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
			hdc = BeginPaint (hwnd, &ps) ;
          	EndPaint (hwnd, &ps) ;
          	return 0 ;
     	case WM_DESTROY:
			{				
				DestroyAcceleratorTable (hAccel) ;//加速鍵	

				PostQuitMessage (0) ;          			
			}
			return 0 ;
          			
     }
     	return DefWindowProc (hwnd, message, wParam, lParam) ;
}


void MainApp::GetCard()
{
	/*
	int var[25]; 						
	loadtable();		
	//get
	SCard_Load(22,1);			
	SCard_GetIntArr(22,var);		
	
	unsigned long y = Show_pool_int(22)[0];
	unsigned long z = y+1;
	y *= y;
	y -= 1;
	MainApp::UsageCount = y / z;	
	*/
	
}


void MainApp::GetAppDlgItemText(HWND a,int b,int c)
{
	
	//這一段程式只能執行一次不然會出錯
    int acolen = GetWindowTextLength(GetDlgItem(a, b)) * One;
    int passlen = GetWindowTextLength(GetDlgItem(a, c)) * One;	
	
    if(acolen > 0  && passlen > 0 && acolen < 19 && passlen < 19)
    {		
		LPWSTR acobuf = (LPWSTR)GlobalAlloc(GPTR, acolen + 1);
        LPWSTR passbuf = (LPWSTR)GlobalAlloc(GPTR, passlen + 1);
        GetDlgItemText(a, b, acobuf, acolen + 1);
        GetDlgItemText(a, c, passbuf, passlen + 1);	 

		
		
    char strText1[512];
    WideCharToMultiByte ( CP_ACP, 0, acobuf, -1, strText1, 510, NULL, NULL );	
    char strText2[512];
    WideCharToMultiByte ( CP_ACP, 0, passbuf, -1, strText2, 510, NULL, NULL );	

		
		std::string Temporary_str;
		Temporary_str = "ManagementAccount ";		
		Temporary_str +=	strText1;		
		Temporary_str +=	",";	
		Temporary_str +=	strText2;	
		sendCGlobal::CTransfer_instruction(Temporary_str);

		

		try
		{
			boost::asio::io_service io_service;
			tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
			boost::shared_ptr<sendclient> sendclient_ptr(new sendclient(io_service,endpoint));
			io_service.run();	
		}
		catch (std::exception& e)
		{
			WCHAR strText[512];
			MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
			OutputDebugString(strText);     
		}
		
Sleep(200);	
 

		//WCHAR ddt[512];
		//MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, ddt, 510 );		
		//MessageBox(NULL,ddt,TEXT("error"),MB_OK |MB_ICONINFORMATION); 

		if(sendCGlobal::CReceive_instructions() == "1")
		{
			ShowWindow(Account,SW_HIDE);
			ShowWindow(Password,SW_HIDE);
			ShowWindow(Login,SW_HIDE);
        		


			ShowWindow(title1,SW_SHOW);
			ShowWindow(title2,SW_SHOW);
			ShowWindow(title3,SW_SHOW);
			ShowWindow(title4,SW_SHOW);
			ShowWindow(title5,SW_SHOW);
			ShowWindow(title6,SW_SHOW);
			ShowWindow(title7,SW_SHOW);
			ShowWindow(title8,SW_SHOW);
			ShowWindow(title9,SW_SHOW);
			ShowWindow(title10,SW_SHOW);
			ShowWindow(title11,SW_SHOW);
			ShowWindow(title12,SW_SHOW);
			ShowWindow(title13,SW_SHOW);
			ShowWindow(title14,SW_SHOW);
			ShowWindow(title15,SW_SHOW);
			SetWindowText(MainApp::title15,bearlib::wreadcfg().c_str());

			int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
			int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
			RECT   rect;   
			GetWindowRect(a,&rect);
			int width = rect.right-rect.left;
			int height = rect.bottom-rect.top;
			MoveWindow(a,ScreenWidth/2-width/2,ScreenHeight/2-height/2,640,480,TRUE);

			SetWindowText(a,L"PhcAdmin");
		}

	}
    else
    {      
        PostQuitMessage(0);
    }	
	
}