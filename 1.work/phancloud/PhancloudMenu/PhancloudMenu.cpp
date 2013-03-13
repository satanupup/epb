#include "PhancloudMenu.h"

#pragma once
//兩個相等會跑到else
#define DebugKOKdddddddd

/* 公用變數　*/

//static unsigned long UsageCount = 0;
//#define One ((int)(UsageCount > 30000))
#define One ((int)(1))



std::string MainApp::ProgramGroupName = "";
std::string MainApp::DiskUser = "";
std::string MainApp::DiskGroup = "";

NETRESOURCE MainApp::nr;
NETRESOURCE MainApp::ntr;
HACCEL MainApp::hAccel = NULL;;//加速鍵
HINSTANCE MainApp::hInstance= NULL;
HWND MainApp::m_hwnd= NULL;
HWND MainApp::hwndEdit1 = NULL;
HWND MainApp::hwndEdit2 = NULL;	
HWND MainApp::button1 = NULL;
HWND MainApp::button2 = NULL;
HWND MainApp::button3 = NULL;
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


ACCEL MainApp::Accel[3] ;
HMENU MainApp::hmenu;//菜單句柄

bool MainApp::userlogin = false;
int  MainApp::buttonNumber = 0;  

SystemProcessPath Pathprocess;	

//////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(
    HINSTANCE,			// hInstance
    HINSTANCE,			// hPrevInstance
    LPSTR,				// lpCmdLine
    int					// nCmdShow			
    )
{		
	
    // Ignore the return value because we want to continue running even in the
    // unlikely event that HeapSetInformation fails.
    HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	
    if (SUCCEEDED(CoInitialize(NULL)))
    {
        {		
			if (SUCCEEDED(MainApp::Initialize()))
			{
				MainApp::RunMessageLoop();
			}
		
        }
        CoUninitialize();
    }

    return 0;
}

HRESULT MainApp::Initialize()
{    	       
	
	//加速鍵
	Accel[0].fVirt = 0 ;
    Accel[0].key = VK_TAB;
    Accel[0].cmd = IDC_TAB ;           
    hAccel = CreateAcceleratorTable (Accel, 1) ;

    Accel[1].fVirt = 0 ;
    Accel[1].key = 27 ;
    Accel[1].cmd = IDM_EXIT ;
    hAccel = CreateAcceleratorTable (Accel, 2) ;

	Accel[2].fVirt = 0 ;
    Accel[2].key = 13 ;
    Accel[2].cmd = IDC_ENTER ;
    hAccel = CreateAcceleratorTable (Accel, 3) ;

	WNDCLASSEX wcex = { sizeof(wcex) };
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = WndProc;
	wcex.cbClsExtra    = 0 ;
    wcex.cbWndExtra    = sizeof(LONG_PTR);
    wcex.hInstance     = hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);		
	wcex.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH); 
    wcex.lpszMenuName  = NULL ;
    wcex.lpszClassName = TEXT("MainApp");
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));
    RegisterClassEx(&wcex);

    // Create the application window.	
      m_hwnd = CreateWindowEx(WS_EX_APPWINDOW |WS_EX_DLGMODALFRAME ,TEXT("MainApp"),
		  TEXT("Please enter the account"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX  ,
      220, 220, 300, 200, 0, 0, hInstance, NULL);
    	
	  
	#ifndef DebugKOK	
	  
	//bearlib::terminateProcess(reinterpret_cast<unsigned int>(pQueuedItem->hProcessId));	
	//bool = false
	TCHAR strappname[] = TEXT("MainApp"); 
    HANDLE hmutex = NULL; 
    //創建互斥對象 
    hmutex = CreateMutex(NULL, false, strappname); 
	//load_reg_tree();
    if (hmutex != NULL) 
    { 
		if (load_reg_tree() == false) 
		{ 
			MessageBox(NULL,TEXT("load_reg_tree = false"),TEXT("SMSServer"),MB_OK |MB_ICONINFORMATION); 
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
		if(hmutex !=NULL)
			CloseHandle(hmutex); 
        return FALSE; 
    }
	
#else

#endif

    RECT   rect;   
    int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
    int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
    GetWindowRect(m_hwnd,&rect);
    int width = rect.right-rect.left;
    int height = rect.bottom-rect.top;
    MoveWindow(m_hwnd,ScreenWidth/2-width/2,ScreenHeight/2-height/2,width,height,TRUE);
	
	/*
	//不能多開程式
	TCHAR strappname[] = TEXT("MainApp"); 
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
		if(hmutex !=NULL)
			CloseHandle(hmutex); 
        return FALSE; 
    }
	
	
    if (One == 0) 
    { 
		MessageBox(NULL,TEXT("請插入卡片,或使用次數已達上限"),TEXT("Error"),MB_OK |MB_ICONINFORMATION); 
		//關閉互斥對象，退出程序 
		SendMessage (m_hwnd, WM_DESTROY, 0, 0) ;			
		CloseHandle(hmutex); 
    } 
    else 
    { 
    }
	*/


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
	static HBRUSH  		hBrushStatic ;
     	PAINTSTRUCT 		ps ;	
		
     	switch (message)
     	{
     	case WM_CREATE:
			{

				hwndEdit1 = CreateWindow(TEXT("Edit"), 
                TEXT(""), WS_CHILD | WS_VISIBLE |WS_BORDER,
                16, 16, 260*One, 28*One, hwnd, (HMENU)ID_ACCOUNTTEXT, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL); 					
            hwndEdit2 = CreateWindow(TEXT("Edit"), 
                TEXT(""), WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_PASSWORD,
                16, 56, 260*One, 28*One, hwnd, (HMENU)ID_PASSWDTEXT, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
            button1 = CreateWindow(TEXT("BUTTON"), 
                TEXT("Login"), WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                128, 96, 149*One, 40*One, hwnd, (HMENU)ID_MYBUTTON, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
			button2 = CreateWindow(TEXT("BUTTON"), 
                TEXT("Clear history"), WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                15, 96, 100*One, 40*One, hwnd, (HMENU)ID_CLEARBUFF, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
			
			button3 = CreateWindow(TEXT("BUTTON"), 
                TEXT("test"), WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                15, 140, 100*One, 20*One, hwnd, (HMENU)ID_SHANG_TEST, 
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
			
			
			//////////////////////////////////////////////////////
			
		title2 = CreateWindow(_T("STATIC"), 
						_T("PhcAdmin"), 
						WS_CHILD  ,
						13, 20, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title3 = CreateWindow(_T("STATIC"), 
						_T("Version"), 
						WS_CHILD  ,
						13, 55, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title4 = CreateWindow(_T("STATIC"), 
						_T("License"), 
						WS_CHILD  ,
						13, 90, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title5 = CreateWindow(_T("STATIC"), 
						_T("Server"), 
						WS_CHILD  ,
						13, 125, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title6 = CreateWindow(_T("STATIC"), 
						_T("Login"), 
						WS_CHILD  ,
						13, 160, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title7 = CreateWindow(_T("STATIC"), 
						_T("Usage"), 
						WS_CHILD  ,
						13, 195, 80*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 

		title8 = CreateWindow(_T("Edit"), 
						_T("2.7.42"),
						WS_CHILD  |WS_BORDER,
						100, 55, 200*One, 28*One, hwnd, NULL,//(HMENU)ID_ACCOUNTTEXT, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 
		title9 = CreateWindow(_T("Edit"), 
						_T("gg"),
						WS_CHILD  |WS_BORDER,
						100, 90, 200*One, 28*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 	
		title10 = CreateWindow(_T("Edit"), 
						_T("192.168.1.106"),
						WS_CHILD  |WS_BORDER,
						100, 125, 200*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title11 = CreateWindow(_T("Edit"), 
						_T("gg2"),
						WS_CHILD  |WS_BORDER,
						100, 160, 200*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
		title12 = CreateWindow(_T("Edit"), 
						_T("28920"),
						WS_CHILD  |WS_BORDER,
						100, 195, 200*One, 28*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL); 		
				
		bearlib::readcfg(0);			
		//sendCGlobal::ClientVerification();	//確認伺服器是否可以連		
		hBrushStatic = CreateSolidBrush (GetSysColor (COLOR_BTNHIGHLIGHT)) ;           
		SetFocus(hwndEdit1);		
		
			}
          	return 0 ;
		
     	case 	WM_CTLCOLORSTATIC :
			SetTextColor ((HDC) wParam, RGB (0, 0, 0)) ;
            SetBkColor ((HDC) wParam, GetSysColor (COLOR_BTNHIGHLIGHT));
        return (LRESULT) hBrushStatic ;
       	break ;
		case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
		case IDC_TAB://加速鍵
            {	
                if(GetFocus()==hwndEdit1)
                {
					SetFocus(hwndEdit2); 
                }
                else
                {
					SetFocus(hwndEdit1);
                }                
            }
            break;
        case IDM_EXIT://加速鍵
            {
				DWORD bres=0;
				bres = WNetCancelConnection2A(MainApp::DiskUser.c_str(),CONNECT_UPDATE_PROFILE,true);
				bres = WNetCancelConnection2A(MainApp::DiskGroup.c_str(),CONNECT_UPDATE_PROFILE,true);

				CloseSrv();

				DestroyAcceleratorTable (hAccel) ;//加速鍵	

				TCHAR strappname[] = TEXT("MainApp"); 
				HANDLE hmutex = NULL; 
				hmutex = CreateMutex(NULL, false, strappname); 				
		          		if(hmutex != NULL)
					CloseHandle(hmutex); 
				PostQuitMessage (0) ;    

                SendMessage (hwnd, WM_DESTROY, 0, 0) ;			
            }
            break;
		case IDC_ENTER://加速鍵
            {
            }
            break;			
        case ID_MYBUTTON:
            {			
				if(MainApp::userlogin == false)
				{
					if(MainApp::buttonNumber <= 2)
					{					
						SetFocus(button1);					
						GetAppDlgItemText(hwnd,ID_ACCOUNTTEXT,ID_PASSWDTEXT); //輸入帳密
						Sleep(100);	
					}
					else
					{
						EnableWindow (button1, FALSE) ;	
						
						EnableWindow (button2, FALSE) ;		
						EnableWindow (button3, FALSE) ;		
						
					}
				}
				else
				{
				}
				
            }
            break;
		case ID_CLEARBUFF://加速鍵
            {
				ClearBUFF();
            }
            break;	
		case ID_SHANG_TEST://加速鍵
            {
				machine_check();
            }
            break;			

			
		case ID_HOME:
            {
				ShellExecuteA(NULL, NULL, MainApp::DiskUser.c_str() , NULL, NULL, SW_SHOW);			
				//ShellExecute(NULL, NULL, TEXT("y:"), NULL, NULL, SW_SHOW);		
            }
            break;	
		case ID_GROUP_HOME:
            {									              
				ShellExecuteA(NULL, NULL, MainApp::DiskGroup.c_str(), NULL, NULL, SW_SHOW);
				//ShellExecute(NULL, NULL, TEXT("z:"), NULL, NULL, SW_SHOW);
            }
            break;		
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		break;	
     	case WM_PAINT:
			BeginPaint (hwnd, &ps) ;
          	EndPaint (hwnd, &ps) ;
          	return 0 ;
     	case WM_DESTROY:
			{			
				DWORD bres=0;
				bres = WNetCancelConnection2A(MainApp::DiskUser.c_str(),CONNECT_UPDATE_PROFILE,true);
				bres = WNetCancelConnection2A(MainApp::DiskGroup.c_str(),CONNECT_UPDATE_PROFILE,true);

				CloseSrv();

				DestroyAcceleratorTable (hAccel) ;//加速鍵	

				TCHAR strappname[] = TEXT("MainApp"); 
				HANDLE hmutex = NULL; 
				hmutex = CreateMutex(NULL, false, strappname); 				
				if(hmutex != NULL)
					CloseHandle(hmutex); 
				PostQuitMessage (0) ;    
				
			}
			return 0 ;
          			
     }
     	return DefWindowProc (hwnd, message, wParam, lParam) ;
}

void MainApp::hello_world(std::string str) 
{			
	int haw = epb::Container::a_multimap::AppCount.size();	
	for(int i=0 ; i < haw ; i++)
	{		
		Pathprocess.iflagAdd();
		Pathprocess.Pathstr(epb::Container::a_multimap::AppCount[i].second.c_str());	
	}		
	Sleep(1000);	
}
void MainApp::hello_world2(std::string str) 
{ 		
	CMyCallbackHandler      myHandler;
	CWhatheverYouWantToHold myView; 
	Perform( &myHandler, &myView );	
}
void MainApp::GetAppDlgItemText(HWND a,int b,int c)
{			
	//這一段程式只能執行一次不然會出錯
    int acolen = GetWindowTextLength(GetDlgItem(a, b)) * One;
    int passlen = GetWindowTextLength(GetDlgItem(a, c)) * One;	
	
    if(acolen > 0  && passlen > 0 && acolen < 19 && passlen < 19)
    {		       
		LPSTR acobuf = (LPSTR)GlobalAlloc(GPTR, acolen + 1);
        LPSTR passbuf = (LPSTR)GlobalAlloc(GPTR, passlen + 1);

        GetDlgItemTextA(a, b, acobuf, acolen + 1);
        GetDlgItemTextA(a, c, passbuf, passlen + 1);	 

		std::string Temporary_str;
		Temporary_str = "gg ";
		Temporary_str +=	acobuf;	
		//取得群組名稱
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
			OutputDebugStringA(e.what());    		  
			MessageBoxA(NULL, e.what() ,"GetAppDlgItemText" , MB_OK);
		}
		

		Sleep(200);	
        nr.dwType = RESOURCETYPE_DISK;		       
		//nr.lpLocalName = TEXT("y:");
		MainApp::DiskUser = bearlib::DiskAvailable(0).c_str();
		char bb[64];
		sprintf_s(bb,"%s",MainApp::DiskUser.c_str());		

		WCHAR r1[512];
		MultiByteToWideChar( CP_ACP, 0, bb, -1, r1, 510 );

		nr.lpLocalName = r1;	

        std::string ag1 = "\\\\";

        ag1 = ag1 + bearlib::readcfg().c_str();
        ag1 = ag1 + "\\" + acobuf;
		bearlib::Cacobuf(acobuf);
		
		WCHAR r2[512];
		MultiByteToWideChar( CP_ACP, 0, ag1.c_str(), -1, r2, 510 );

        nr.lpRemoteName = r2; //L"\\\\192.168.3.115\\gg2";
        nr.lpProvider = NULL;				
		
		DWORD bres=0;
		bres = WNetCancelConnection2A(MainApp::DiskUser.c_str(),CONNECT_UPDATE_PROFILE,true);
			
		WCHAR r6[512];
		MultiByteToWideChar( CP_ACP, 0, passbuf, -1, r6, 510 );
		WCHAR r7[512];
		MultiByteToWideChar( CP_ACP, 0, acobuf, -1, r7, 510 );

        DWORD res = WNetAddConnection2(&nr,r6,r7,CONNECT_UPDATE_PROFILE);			
		Sleep(200);	

		if(res == 0)
		{
			ShowWindow(hwndEdit1,SW_HIDE);
			ShowWindow(hwndEdit2,SW_HIDE);
			ShowWindow(button1,SW_HIDE);
			ShowWindow(button2,SW_HIDE);
			ShowWindow(button3,SW_HIDE);
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

			WCHAR e2[512];
			MultiByteToWideChar( CP_ACP, 0, bearlib::readcfg().c_str(), -1, e2, 510 );

			SetWindowText(title10,e2);		

			
			WCHAR e3[512];
			MultiByteToWideChar( CP_ACP, 0, acobuf, -1, e3, 510 );

			SetWindowText(title11,e3);	
    
			RECT   rect;   
			int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
			int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
			GetWindowRect(a,&rect);
			int width = rect.right-rect.left;
			int height = rect.bottom-rect.top;
			MoveWindow(a,ScreenWidth/2-width/2,ScreenHeight/2-height/2,320,300,TRUE);
	
			SetWindowText(a,_T("PhcMenu"));
			Sleep(200);						

			sendCGlobal::Modify_Receive_instructions_str();
			ntr.dwType = RESOURCETYPE_DISK;		
			//ntr.lpLocalName = TEXT("z:");

			MainApp::DiskGroup = bearlib::DiskAvailable(1).c_str();
			char dd[64];
			sprintf_s(dd,"%s",MainApp::DiskGroup.c_str());	

			WCHAR e1[512];
			MultiByteToWideChar( CP_ACP, 0, dd, -1, e1, 510 );

			ntr.lpLocalName = e1;

			std::string jj1 = "\\\\";
			jj1 += bearlib::readcfg().c_str();
			jj1 += "\\";
			jj1 += sendCGlobal::CReceive_instructions().c_str();
	
			bearlib::CGroup(sendCGlobal::CReceive_instructions().c_str());

			MainApp::ProgramGroupName = sendCGlobal::CReceive_instructions().c_str();
		
			WCHAR q1[512];
			MultiByteToWideChar( CP_ACP, 0, jj1.c_str(), -1, q1, 510 );

			ntr.lpRemoteName = q1; //L"\\\\192.168.3.115\\gg2";
			ntr.lpProvider = NULL;	
		
			WCHAR q2[512];
			MultiByteToWideChar( CP_ACP, 0, MainApp::DiskGroup.c_str(), -1, q2, 510 );

			DWORD bres=0;
			bres = WNetCancelConnection2(q2,CONNECT_UPDATE_PROFILE,true);
		
			WCHAR q3[1000];
			MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, q3, 998 );
						
			bres = WNetAddConnection2(&ntr,TEXT(""),q3,CONNECT_UPDATE_PROFILE);	
							 			
	
//		std::string Temporary_str;
		Temporary_str = "Connection";
		
		//sendCGlobal::CReceive_instructions("");
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
			OutputDebugStringA(e.what());    		  
			MessageBoxA(NULL, e.what() ,"GetAppDlgItemText" , MB_OK);
		}
	
		if(strcmp(sendCGlobal::CReceive_instructions().c_str() , "OK") == 0)
		{
			pinger::network_check = true;				
			
		}
		else
		{					
			//if(MessageBox(NULL, TEXT("Line cut off in sequence") ,TEXT("Error")  ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
			//{					
				pinger::network_check = false;		
							
				DWORD bres=0; 
				bres = WNetCancelConnection2A(MainApp::DiskUser.c_str(),CONNECT_UPDATE_PROFILE,true);		
				bres = WNetCancelConnection2A(MainApp::DiskGroup.c_str(),CONNECT_UPDATE_PROFILE,true);

				Sleep(1000);		
				CloseSrv();
				PostQuitMessage(0);
			//}
		}
		//ping	
		std::string bk1;
		bk1 = bearlib::readcfg().c_str();		
		
		boost::thread bbd(boost::bind(&hello_world2,bk1.c_str()));	//0924
	//	bbd.join();
		
			

			EnableWindow (button1, FALSE) ;
			EnableWindow (button2, FALSE) ;
			EnableWindow (button3, FALSE) ;

			pinger::network_check_2 = true;
			SetAppMenu(a);
			MainApp::buttonNumber = 100;
		}		
		else if(res == 64 || res == 86)
		{
			
			MainApp::buttonNumber = MainApp::buttonNumber + 1;
			MessageBox(NULL, TEXT("查無此帳號或密碼") ,TEXT("Error") , MB_OK);
			pinger::network_check_2 = false;
		}
		else
		{
			
		std::string wTmp = "";		
		wTmp = boost::lexical_cast<std::string>( res );		
		MessageBoxA(NULL, wTmp.c_str() ,"Error" , MB_OK);


			MainApp::buttonNumber = MainApp::buttonNumber + 1;
		//	MessageBox(NULL, TEXT("查無此帳號或密碼") ,TEXT("Error") , MB_OK);
			pinger::network_check_2 = false;			
		}
				
		if(MainApp::buttonNumber > 2)
		{
			EnableWindow (button1, FALSE) ;	
			EnableWindow (button2, FALSE) ;	
			EnableWindow (button3, FALSE) ;	
			if(MainApp::buttonNumber == 100)
			{
				//EnableWindow (button1, FALSE) ;					
			}
			else
			{
				MessageBox(NULL, TEXT("登入三次失敗 請重新登入") ,TEXT("Error") , MB_OK);
			}
		}
		else
		{					
		}		
    }
    else
    {
        MessageBox(NULL, TEXT("Error") ,TEXT("Error") , MB_OK);		
		DWORD bres=0; 
		bres = WNetCancelConnection2A(MainApp::DiskUser.c_str(),CONNECT_UPDATE_PROFILE,true);		
        bres = WNetCancelConnection2A(MainApp::DiskGroup.c_str(),CONNECT_UPDATE_PROFILE,true);
		CloseSrv();
		
        PostQuitMessage(0);
    }		
}

void MainApp::SetAppMenu(HWND h)//目前列表只需要讀出一行path還有時間
{	
	HMENU hMenu;
    hMenu = CreateMenu();
	if(pinger::network_check_2 == true)
		{
Sleep(1000);		
//	MessageBox(NULL, "The login is successful" ,"Phancloud" , MB_OK);	
			if(pinger::network_check == true)
			{
				MessageBox(NULL, _T("The login is successful") ,_T("Phancloud") , MB_OK);				
				hmenu=CreatePopupMenu();//生成菜單
				AppendMenu(hmenu,MF_STRING,IDR_PAUSE,_T("Leave"));//為菜單添加兩個選項
				AppendMenu(hmenu,MF_STRING,ID_HOME,_T("Personal Information area"));
				AppendMenu(hmenu,MF_STRING,ID_GROUP_HOME,_T("Group data area"));
				AppendMenu(hMenu, MF_STRING, ID_HOME, _T("Personal Information area"));
				AppendMenu(hMenu, MF_STRING, ID_GROUP_HOME, _T("Group data area"));
				SetMenu(h, hMenu);				 				
				
				std::string Temporary_str;
				Temporary_str = "GetSoftwareName ";
				Temporary_str += MainApp::ProgramGroupName;
				
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
					OutputDebugStringA(e.what());     				  
					MessageBoxA(NULL, e.what() ,"SetAppMenu" , MB_OK);
				}
	
				//分割伺服器傳來的字串	
				std::vector<std::string> vt;
				sendCGlobal::bb(sendCGlobal::CReceive_instructions().c_str(), vt);
				std::string t1 = "!@";
				std::string t2 = "#$";
				std::string t3 = "%^";
				int w1=0;
				int w2=0;
				int w3=0;			
				
				int vtint = 0;
				vtint = vt.size();
				for (int i = 0; i < vtint; ++ i)
				{ 	
					w1 = vt[i].find  (t1);			 
					w2 = vt[i].find  (t2);			 
					w3 = vt[i].find  (t3);		
			 
					int dd;
					dd = boost::lexical_cast<int>( vt[i].substr(w1+t1.size(),(w2-w1)-t2.size()).c_str() );																

					if(dd == 1)//有打勾的才會出現	
					{
						MessageBoxA(NULL, vt[i].substr(0,w1).c_str(),"install",MB_OK);																	
						epb::Container::a_multimap::AppCount.push_back(std::make_pair(vt[i].substr(0,w1).c_str(),vt[i].substr(w2+t2.size(),(w3-w2)-t3.size()).c_str()));
					}
				}
				
				int haw = epb::Container::a_multimap::AppCount.size();				
				std::string list[100];
				char data_[1024];
				for(int i=0 ; i < haw ; i++)
				{						
					sprintf_s(data_,"%s",epb::Container::a_multimap::AppCount[i].first.c_str());					
					list[i] = data_;
				}		
				
		boost::thread cc(boost::bind(&hello_world,"1"));	
		cc.join();
#ifndef DebugKOK		
				
	try
	{		  
		Sleep(2000);	

		

		Sleep(100);
		for(int i=0 ; i < haw ; i++)
		{							
			all_work(epb::Container::a_multimap::AppCount[i].first.c_str(),epb::Container::a_multimap::AppCount[i].second.c_str());		
			Sleep(2000);
		}	

		strt_set();

		Sleep(100);

		for(int i=0 ; i < haw ; i++)
		{							
			S_all_work2(epb::Container::a_multimap::AppCount[i].first.c_str());		
			Sleep(2000);
		}	

		ALL_run();
	
		//soft_list(list,haw);
		
		
		Sleep(2000);				
		MessageBoxA(NULL, "OK可以開始使用" ,"" , MB_OK);
	}
	catch (std::exception& e)
	{
		OutputDebugStringA(e.what());    
		MessageBoxA(NULL, e.what() ,"all_work" , MB_OK);
	}

#else
				MessageBox(NULL, _T("OK可以開始使用") ,_T("") , MB_OK);
				///////		
#endif
				}
		}
		else
		{
			MessageBox(NULL, _T("登入失敗，請重新登入") ,_T("Phancloud") , MB_OK);
		}		
}

void CMyCallbackHandler::OnProcessEvent(
		PQUEUED_ITEM pQueuedItem, 
		PVOID        pvParam
		)
	{
			TCHAR szFileName[MAX_PATH] = L"";
			
			::Sleep(500);
			CWhatheverYouWantToHold* pParam = static_cast<CWhatheverYouWantToHold*>(pvParam);
			
			if (NULL != pQueuedItem)
			{		
				TCHAR szBuffer[1024] = L"";
				::ZeroMemory(
					reinterpret_cast<PBYTE>(szBuffer),
					sizeof(szBuffer)
					);
				GetProcessName(
				reinterpret_cast<DWORD>(pQueuedItem->hProcessId), 
				szFileName, 
				MAX_PATH
				);

				if (pQueuedItem->bCreate)
				{  	
					wsprintfW(
					szBuffer, 
					TEXT("Process has been created: PID=%.8X %s\n"),
					pQueuedItem->hProcessId,
					szFileName
					);
					char pidstr[64];
					sprintf_s(pidstr,"%.8X",pQueuedItem->hProcessId);
										
					Sleep(500);

					int haw = epb::Container::a_multimap::AppCount.size();		
					int checksoftware = 0;

					char strTextrr[512];
					WideCharToMultiByte ( CP_ACP, 0, szFileName, -1, strTextrr, 510, NULL, NULL );	
					bpathnumber = strTextrr;

					bpathDirectory = "";                                                                                                 
					for (int i = 0; i < haw; ++ i)
					{	
						const char *str1 = bpathnumber.c_str();//"C:\\Program Files\\Microsoft Office\\Management_2.0.exe";
						const char *str2 = epb::Container::a_multimap::AppCount[i].second.c_str();						
						int r;
						r = bearlib::str_match(str1, str2);
						if(r == 0)     
							bpathDirectory = epb::Container::a_multimap::AppCount[i].second.c_str();								
					}			

					for (int i = 0; i < haw; ++ i)
					{				
						char br[64];
						sprintf_s(br,"%d",i+1);
						checksoftware = Pathprocess.func(br,strTextrr);

						//char bstr[2048];
						//sprintf_s(bstr,"%s\t%s\t%s\t%s\t%s\n",br,itoa(checksoftware,brstr,10),epb::Container::a_multimap::AppCount[i].first.c_str(),epb::Container::a_multimap::AppCount[i].second.c_str(),pidstr);						
						//OutputDebugStringA(bstr);

						if(checksoftware == 1)
						{
							if(acontainer.left.count(bpathDirectory) == 0)
							{
								std::string sse;
								sse = "a↓";
								sse += bpathDirectory.c_str();
								sse += ",";
								sse += pidstr;
								OutputDebugStringA(sse.c_str()); 	
							
								//連線到伺服端做確認					
								std::string Temporary_str;
								Temporary_str = "Approve";
								//Temporary_str += "ggc";
								Temporary_str += bearlib::CGroup().c_str();							
								Temporary_str += ",";
								//Temporary_str += "office";
								Temporary_str += epb::Container::a_multimap::AppCount[i].first.c_str();							
								Temporary_str += ",";
								//Temporary_str += "C:\\Program Files\\Microsoft Office";
								Temporary_str += bpathDirectory.c_str();
								Temporary_str += ",";
								Temporary_str += bearlib::getHostInfo().c_str();							
								Temporary_str += ",";
								Temporary_str += bearlib::Cacobuf().c_str();							
								Temporary_str += ",";

							
								char   tmpbuf1[128];   
								char   tmpbuf2[128];   
								  _tzset();   
								  _strtime(tmpbuf1);   
								  _strdate(tmpbuf2);   
								  //printf( "%s %s ",tmpbuf2,tmpbuf1);   
								  std::string btimec;
								  btimec = tmpbuf2 ;
								  btimec += " ";
								  btimec += tmpbuf1;
	  
								//Temporary_str += "201208170225";
								Temporary_str += btimec.c_str();
								sendCGlobal::CTransfer_instruction(Temporary_str);
			
								Sleep(100);
								try
								{
									boost::asio::io_service io_service;
									tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
									boost::shared_ptr<sendclient> sendclient_ptr(new sendclient(io_service,endpoint));
									io_service.run();		
								}
								catch (std::exception& e)
								{
									OutputDebugStringA(e.what());    		  
									MessageBoxA(NULL, e.what() ,"Connect to the server-side do confirm" , MB_OK);
								}

								if(strcmp(sendCGlobal::CReceive_instructions().c_str() , "OK") == 0)
								{	
									OutputDebugStringA(bpathDirectory.c_str());   									
									OutputDebugStringA("OK");    		
								}  	
								if(strcmp(sendCGlobal::CReceive_instructions().c_str() , "NO") == 0)
								{										
									OutputDebugStringA(bpathDirectory.c_str());  
									OutputDebugStringA("NO");    
									Sleep(100);
									bearlib::terminateProcess(reinterpret_cast<unsigned int>(pQueuedItem->hProcessId));	
								}  	
															
							}//同一套開啟次數為0
							
							
						}//if(checksoftware == 1)
						checksoftware = 0;

						
					}					
					
					acontainer.insert( epb::Container::a_multimap::adjustment(bpathDirectory,pidstr));	
					
				}
				else
				{
					
				wsprintfW(
					szBuffer,
					TEXT("Process has been terminated: PID=%.8X\n"),
					pQueuedItem->hProcessId);
				
				
					char pidstrb[64];
					sprintf_s(pidstrb,"%.8X",pQueuedItem->hProcessId);
				
					Sleep(100);
					
					epb::Container::a_multimap::dictionary::right_const_iterator it;	
					it = acontainer.right.find( pidstrb ); 
					std::string pbpathDirectory;
					if ( it != acontainer.right.end( ) )   
					{						
						pbpathDirectory = it->second.c_str();
					}
					//
					ccprogaom.removeApp(acontainer,pidstrb);
					
					int haw = epb::Container::a_multimap::AppCount.size();		
					int checksoftware = 0;
					
					for (int i = 0; i < haw; ++ i)
					{				

						char br[64];
						sprintf_s(br,"%d",i+1);			
						
						checksoftware = Pathprocess.func(br,bpathnumber.c_str());
						char bstr[2048];
						sprintf_s(bstr,"%s\t%d\t%s\t%s\t%s\n",br,checksoftware,epb::Container::a_multimap::AppCount[i].first.c_str(),epb::Container::a_multimap::AppCount[i].second.c_str(),pidstrb);
							
						if(checksoftware == 1)
						{							
							//連線到伺服端做確認
							if(acontainer.left.count(pbpathDirectory) == 0)
							{
								std::string rrc;
								rrc = "b↑";
								rrc += pbpathDirectory.c_str();
								rrc += ",";
								rrc += pidstrb;
								rrc += "";
								OutputDebugStringA(rrc.c_str()); 
					
							
								std::string Temporary_str;
								///							
								Temporary_str = "AppLogout";
								Temporary_str += bearlib::CGroup().c_str();							
								Temporary_str += ",";
								Temporary_str += "NULL";//epb::Container::a_multimap::AppCount[i].first.c_str();							
								Temporary_str += ",";
								Temporary_str += pbpathDirectory.c_str();
								Temporary_str += ",";
								Temporary_str += bearlib::getHostInfo().c_str();							
								Temporary_str += ",";
								Temporary_str += bearlib::Cacobuf().c_str();							
								Temporary_str += ",";
								//OutputDebugStringA("\n");  
								//OutputDebugStringA(Temporary_str.c_str());    	
							
								char   tmpbuf1[128];   
								char   tmpbuf2[128];   
								_tzset();   
								_strtime(tmpbuf1);   
								_strdate(tmpbuf2);   
								std::string btimec;
								btimec = tmpbuf2 ;
								btimec += " ";
								btimec += tmpbuf1;
	  
								Temporary_str += btimec.c_str();

								///
								sendCGlobal::CTransfer_instruction(Temporary_str);
			
								Sleep(100);
								try
								{
									boost::asio::io_service io_service;
									tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
									boost::shared_ptr<sendclient> sendclient_ptr(new sendclient(io_service,endpoint));
									io_service.run();		
								}
								catch (std::exception& e)
								{
									OutputDebugStringA(e.what());    		  
									MessageBoxA(NULL, e.what() ,"Connect to the server-side do confirm" , MB_OK);
								}

								if(strcmp(sendCGlobal::CReceive_instructions().c_str() , "OK") == 0)
								{	
									//OutputDebugStringA("hahahahahhaha\n");    		
								}  	
								//傳資訊到伺服端					
							}//同一套開啟次數為0	
							
						}//if(checksoftware == 1)
						checksoftware = 0;
					}					
					
				
				}
					
			_tprintf(szBuffer);		
			} 			
	}	