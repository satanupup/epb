#include "stdafx.h"
 HWND GroupEventer::hGroupList		= NULL;
 HWND GroupEventer::hGroupText		= NULL;
 HWND GroupEventer::hUserList		= NULL;
 HWND GroupEventer::hUserText		= NULL;
 HWND GroupEventer::hGroupEditText	= NULL;
 HWND GroupEventer::hUserEditText	= NULL;
 HWND GroupEventer::hUserModText	= NULL;
 HWND GroupEventer::hGroupModText	= NULL;
 
std::string GroupEventer::GroupName	= "";

int GroupEventer::GroupEventNumber = 0;
int GroupEventer::GroupNumberID = 0;
LRESULT CALLBACK DialogProcGROUPUSER_TITLE( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{	
	static bool GROUPUSERbChangeText = true;
	PAINTSTRUCT ps;
	HDC hdc; 
	HMENU hMenu;
	
	int UserNumberID;
	switch(msg) 
	{
		case WM_CREATE:	 
		{					
			hMenu = CreateMenu();		
			AppendMenu(hMenu, MF_STRING, (UINT)ID_MYBUTTON, L"Always displayed on top");
			SetMenu(hwnd, hMenu);	
			SetWindowPos(hwnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
			
			{
				{//group
					int x = 15;
 
				CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						5, 0, 370*One, 425*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
				CreateWindow(L"STATIC", 
						L"Group", WS_CHILD | WS_VISIBLE,
						x, 11, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);			
 
				GroupEventer::hGroupList = CreateWindow(L"LISTBOX",NULL,
						WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
 LBS_STANDARD & (!LBS_SORT) | LBS_NOTIFY |WS_HSCROLL | WS_VSCROLL ,
						x, 30, 160*One, 365*One, hwnd, HMENU(IDS_LISTBOX_GROUP), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
				GroupEventer::hGroupText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						x, 395, 160*One, 20*One, hwnd, HMENU(ID_LB_GETTEXT), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				}
				{//user
					int x = 200;
				CreateWindow(L"STATIC", 
						L"User", WS_CHILD | WS_VISIBLE,
						x, 11, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				GroupEventer::hUserList = CreateWindow(L"LISTBOX", 
						L"User", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
 LBS_STANDARD & (!LBS_SORT) | LBS_NOTIFY |WS_HSCROLL | WS_VSCROLL,
						x, 30, 160*One, 365*One, hwnd, HMENU(IDS_LISTBOX_USER), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				GroupEventer::hUserText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						x, 395, 160*One, 20*One, hwnd, HMENU(ID_LB_USER_GETTEXT), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
				}
				{//group
 
					CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						380, 0, 250*One, 140*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					CreateWindow(L"STATIC", 
						L"Group", WS_CHILD | WS_VISIBLE,
						390, 20, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					GroupEventer::hGroupEditText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 20, 180*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					CreateWindow(L"BUTTON", 
						L"GroupAdd", WS_CHILD | WS_VISIBLE ,
						440, 50, 80*One, 20*One, hwnd, HMENU(IDS_LISTBOX_GROUP_ADD), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"BUTTON", 
						L"GroupDel", WS_CHILD | WS_VISIBLE ,
						540, 50, 80*One, 20*One, hwnd, HMENU(IDS_LISTBOX_GROUP_DEL), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				}
				{//user
					CreateWindow(L"STATIC", 
						L"User", WS_CHILD | WS_VISIBLE ,
						390, 80, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					GroupEventer::hUserEditText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 80, 180*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					CreateWindow(L"BUTTON", 
						L"UserAdd", WS_CHILD | WS_VISIBLE ,
						440, 110, 80*One, 20*One, hwnd, HMENU(IDS_LISTBOX_USER_ADD), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"BUTTON", 
						L"UserDel", WS_CHILD | WS_VISIBLE ,
						540, 110, 80*One, 20*One, hwnd, HMENU(IDS_LISTBOX_USER_DEL), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				}
 
				{
					CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						380, 140, 250*One, 140*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					CreateWindow(L"STATIC", 
						L"User", WS_CHILD | WS_VISIBLE ,
						390, 160, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"STATIC", 
						L"Group", WS_CHILD | WS_VISIBLE ,
						390, 190, 60*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					GroupEventer::hUserModText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER |ES_READONLY,
						440, 160, 180*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					GroupEventer::hGroupModText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER |ES_READONLY,
						440, 190, 180*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					
					//Enable
					CreateWindow(L"BUTTON", 
						L"UserMod", WS_CHILD | WS_VISIBLE ,
						520, 220, 100*One, 20*One, hwnd, HMENU(IDS_USER_MOD),  
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				}
				{
					/*
					CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						380, 140, 250, 140, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
					CreateWindow(L"STATIC", 
						L"Header", WS_CHILD | WS_VISIBLE ,
						390, 160, 60, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"STATIC", 
						L"From", WS_CHILD | WS_VISIBLE ,
						390, 190, 60, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"STATIC", 
						L"To", WS_CHILD | WS_VISIBLE ,
						390, 220, 60, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 160, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 190, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 220, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"BUTTON", 
						L"UserBetchAdd", WS_CHILD | WS_VISIBLE ,
						520, 250, 100, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);*/
 
				}
				{
					/*
					CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						380, 280, 250, 145, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"STATIC", 
						L"New", WS_CHILD | WS_VISIBLE ,
						390, 300, 60, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"STATIC", 
						L"Check", WS_CHILD | WS_VISIBLE ,
						390, 330, 60, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 300, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						440, 330, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"BUTTON", 
						L"PasswordChange", WS_CHILD | WS_VISIBLE ,
						490, 360, 130, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 */
 
				}
 
				{
					
 
					GroupEventer::shellgrouoppget();				
					//shelluserpget();
 
					//SetFocus (hGroupList) ;	
				}
 
			}
		}
		break;
		case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
			GroupEventer::GroupNumberID  = SendMessage (GroupEventer::hGroupList, LB_GETCURSEL, 0, 0) ;

		case ID_MYBUTTON:
			{		
				if (GROUPUSERbChangeText)
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
 GROUPUSERbChangeText = !GROUPUSERbChangeText;
			}
			break;
			/*
			hFontList = CreateWindow(L"LISTBOX",NULL,
						WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
 LBS_STANDARD & (!LBS_SORT) | LBS_NOTIFY |WS_HSCROLL | WS_VSCROLL ,
						x, 30, 160, 365, hwnd, HMENU(IDS_LISTBOX_GROUP), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
			hGroupText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						x, 395, 160, 20, hwnd, HMENU(ID_LB_GETTEXT), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
			//if(HIWORD(wParam)==LBN_DBLCLK)
 
 
 
			hUserText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						x, 395, 160, 20, hwnd, HMENU(ID_LB_USER_GETTEXT), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
			*/
			
		case IDS_LISTBOX_GROUP://bear1
			{	//LBN_DBLCLK
				if(HIWORD(wParam)==LBN_SELCHANGE)
				{					
					if (LB_ERR == (GroupEventer::GroupNumberID = SendMessage (GroupEventer::hGroupList, LB_GETCURSEL, 0, 0L)))
					break ;
 
					GroupEventer::shellgrouoppget();
					
				}
					
 
			}
			break;	
		case IDS_LISTBOX_GROUP_ADD:
			{			
				TCHAR  lpString[128] = L"\0"; 
				GetWindowText(GroupEventer::hGroupEditText,lpString,128); 	

				char g_w[1024];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 1024, NULL, NULL ); 
				GroupEventer::GrouopAdd(g_w);		
			}
			break;
		case IDS_LISTBOX_GROUP_DEL:
			{			
				TCHAR  lpString[128] = L"\0";  
				GetWindowText(GroupEventer::hGroupEditText,lpString,128); 	
				
				char g_w[1024];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 1024, NULL, NULL ); 

				GroupEventer::GrouopDel(g_w);		
			}
			break;	
					
		case IDS_LISTBOX_USER_ADD:
			{			
				TCHAR lpString[128] = L"\0"; 
				GetWindowText(GroupEventer::hUserEditText,lpString,128); 
				char bh[128] = "\0";
				for(int i=0;i<128;i++)
					bh[i] = (char)lpString[i];
				//MessageBox(NULL,lpString,TEXT("test"),MB_OK);
				
				if(GroupEventer::GroupName.c_str() == "")
				{
				}
				else
				{
					
					if(strcmp(bh,"") == 0)
					{
					}
					else
					{
						
				char g_w[1024];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 1024, NULL, NULL ); 

						GroupEventer::UserAdd(g_w);
					}
				
				}
				
			}
			break;			
		case IDS_LISTBOX_USER_DEL:
			{			
				TCHAR lpString[128] = L"\0"; 
				GetWindowText(GroupEventer::hUserEditText,lpString,128); 
				char bh[128] = "\0";
				for(int i=0;i<128;i++)
					bh[i] = (char)lpString[i];
				//MessageBox(NULL,lpString,TEXT("test"),MB_OK);
				
				if(GroupEventer::GroupName.c_str() == "")
				{
				}
				else
				{
					
					if(strcmp(bh,"") == 0)
					{
					}
					else
					{
						
				char g_w[1024];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 1024, NULL, NULL ); 

						GroupEventer::UserDel(g_w);
					}
				
				}
				
			}
			break;
		case IDS_LISTBOX_USER://bear2
			{	//LBN_DBLCLK
				if(HIWORD(wParam)==LBN_SELCHANGE)
				{					
					if (LB_ERR == (UserNumberID = SendMessage (GroupEventer::hUserList,LB_GETCURSEL, 0, 0L)))
					break ;
 
					TCHAR lpString[128] = L"\0"; 	
					SendMessage (GroupEventer::hUserList, LB_GETTEXT, UserNumberID, (LPARAM) lpString) ;					 
					SetWindowText(GroupEventer::hUserText,lpString);			
					SetWindowText(GroupEventer::hUserModText,lpString);			
					
				}
					
 
			}
			break;	
		
		case IDS_USER_MOD:
			{	
				
				TCHAR lpString[128] = L"\0"; 
				GetWindowText(GroupEventer::hUserModText,lpString,128); 
				char bh[128] = "\0";
				for(int i=0;i<128;i++)
					bh[i] = (char)lpString[i];
				//MessageBox(NULL,lpString,TEXT("test"),MB_OK);
				
				if(GroupEventer::GroupName.c_str() == "")
				{
				}
				else
				{
					
					if(strcmp(bh,"") == 0)
					{
					}
					else
					{
						
				char g_w[1024];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 1024, NULL, NULL ); 

						GroupEventer::UserMod(g_w);
					}
				
				}
				
			
			}
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		break;		
		case WM_LBUTTONDOWN://RBUTTONDOWN: 
		{			
			//OutputDebugString(TEXT("WM_DESTROY"));
		}
		return 0; /*
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
		break;*/
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			// TODO: 在此加入任何繪圖程式碼...
			//TextOut(hdc,20,20,L"GROUPUSER",9);
			EndPaint(hwnd, &ps);
		break;
		case WM_CLOSE:			
			GroupEventer::GroupEventNumber = GroupEventer::GroupEventNumber - 1;
			DestroyWindow(hwnd);
			break; 
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
 }
 return 0;
 
 
}
 
void RegisterDialogGROUPUSER_TITLE(HWND hwnd) 
{
 WNDCLASSEX wc = {0};
 wc.cbSize = sizeof(WNDCLASSEX);
 wc.lpfnWndProc = (WNDPROC) DialogProcGROUPUSER_TITLE;
 wc.hInstance = MainApp::hinst;
 wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
 wc.lpszClassName = TEXT("DialogProcGROUPUSER_TITLE");
 RegisterClassEx(&wc);
 
	RECT rect; 
	int ScreenWidth= GetSystemMetrics(SM_CXSCREEN); 
	int ScreenHeight= GetSystemMetrics(SM_CYSCREEN); 
	GetWindowRect(hwnd,&rect);
	int width = rect.right-rect.left;
	int height = rect.bottom-rect.top;
 
 //WS_EX_DLGMODALFRAME 去掉視窗小圖示 | WS_EX_TOPMOST 總是在前
 CreateWindowEx(WS_EX_APPWINDOW |WS_EX_DLGMODALFRAME | WS_EX_TOPMOST, TEXT("DialogProcGROUPUSER_TITLE"), TEXT("GROUPUSER"), 
 WS_VISIBLE | WS_SYSMENU | WS_CAPTION , ScreenWidth/2-width/2, (ScreenHeight/2-height/2)+50, 640, 480, 
 NULL, NULL, MainApp::hinst, NULL);
 
 GroupEventer::GroupEventNumber = GroupEventer::GroupEventNumber + 1; 
}
void GroupEventer::shellgrouoppget()
{
	const int NumberMax = 1024;
	WCHAR wstrText[NumberMax];
	WCHAR wstrGidText[NumberMax];
	SendMessage (hGroupList, LB_RESETCONTENT, 0, 0) ;
 		
	std::string Temporary_str;
	Temporary_str 	 = "GroupList";
	sendCGlobal::CTransfer_instruction(Temporary_str);

	
	
 	
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();	
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	std::vector<std::string> vt;
	
	GroupEventer::split(sendCGlobal::CReceive_instructions().c_str(), vt);
		for (size_t i = 0; i < vt.size(); ++ i)
		{ 		
			std::string gg = ",";
			int abc = vt[i].find_last_of(gg);
			 
			MultiByteToWideChar( CP_ACP, 0, vt[i].substr(0,abc).c_str(), -1, wstrText, NumberMax );	 
			MultiByteToWideChar( CP_ACP, 0, vt[i].substr(abc + 1).c_str(), -1, wstrGidText, NumberMax );			 
			SendMessage(hGroupList,LB_ADDSTRING,0,(LPARAM)wstrText);		 
		}	

		
		{
			
			TCHAR lpString[128] = L"\0"; 
			//GetWindowText(hUserText,lpString,128); 					
			SendMessage (hGroupList, LB_GETTEXT, GroupEventer::GroupNumberID, (LPARAM) lpString) ;	
								
			SetWindowText(hGroupText,lpString);	
			SetWindowText(hGroupModText,lpString);	
			//bear11
			
			char g_w[128];
			WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 128, NULL, NULL ); 
			

			GroupEventer::GroupName = g_w;
 
			//
//			const int NumberMax = 1024;
		//	TCHAR wstrText[128] = L"\0";
			//SendMessage (hGroupList, LB_RESETCONTENT, 0, 0) ;
 		
		//	std::string Temporary_str;
			Temporary_str 	 = "GroupList";
			sendCGlobal::CTransfer_instruction(Temporary_str);

 
			
					
			try
			{
				boost::asio::io_service io_service;
				tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
				boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
				io_service.run();	
			}
			catch (std::exception& e)
			{
				WCHAR strText[512];
				MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
				OutputDebugString(strText);     
			}
					

			WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 128, NULL, NULL ); 


					std::string ad;
					std::vector<std::string> vt2;
					
					
					
					GroupEventer::split(sendCGlobal::CReceive_instructions().c_str(), vt2);
						for (size_t i = 0; i < vt2.size(); ++ i)
						{ 		
							std::string gg = ",";
							int abc = vt2[i].find_last_of(gg); 
							MultiByteToWideChar( CP_ACP, 0, vt2[i].substr(0,abc).c_str(), -1, wstrText, 1024 );
							
							if(bearlib::UNICODEtoANSI(lpString) == bearlib::UNICODEtoANSI(wstrText))
							{
								ad = vt2[i].substr(abc + 1).c_str();// L"1000";
							}
						}						
						shelluserpget(ad);

		}
		
			SendMessage (hGroupList, LB_SETCURSEL, GroupEventer::GroupNumberID, 0) ;
		
 ProgramEventer::ProgramGetGroupList();
 
}
	
void GroupEventer::shelluserpget(std::string wstr)
{
	WCHAR wstrText[1024];
	SendMessage (hUserList, LB_RESETCONTENT, 0, 0) ;
	//bear0511
 
 //"cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4=="+ wstr  +=" {print $1\",\"$4}'";
	
			
	std::string Temporary_str;
	Temporary_str 	 = "UserList";	
	Temporary_str 	 += wstr;
	sendCGlobal::CTransfer_instruction(Temporary_str);
	 
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	std::vector<std::string> vt;
	
		

	GroupEventer::split(sendCGlobal::CReceive_instructions().c_str(), vt);
	
	for (size_t i = 0; i < vt.size(); ++ i)
	{
		std::string gg = ",";
		int abc = vt[i].find_last_of(gg);

		MultiByteToWideChar( CP_ACP, 0,vt[i].substr(0,abc).c_str(), -1, wstrText, 1024 );	

		SendMessage(hUserList,LB_ADDSTRING,0,(LPARAM)wstrText); 		 
	}	 
}


void GroupEventer::GrouopAdd(std::string wstr)
{  		
	std::string Temporary_str;
	Temporary_str 	 = "groupadd";	

	std::vector<std::string> vt;
    GroupEventer::bhja1("!,@,#,$,%,^,&,*,(,),-,+,=,\",\',{,},[,],\\,|,`,~,\r,\n,\t, ", vt);
    for (size_t i = 0; i < vt.size(); ++ i)
    {
		char bbd;		
		bbd = boost::lexical_cast<char>( vt[i].c_str() );
		wstr.erase(remove(wstr.begin(), wstr.end(), bbd), wstr.end());			
    }
	
	Temporary_str 	 += wstr;	
	sendCGlobal::CTransfer_instruction(Temporary_str);
	 	 

					
	
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	GroupUserUpdate();
	shellgrouoppget();	
	
}

void GroupEventer::GrouopDel(std::string wstr)
{  		
	std::string Temporary_str;
	Temporary_str 	 = "groupdel";
	
	std::vector<std::string> vt;
    GroupEventer::bhja1("!,@,#,$,%,^,&,*,(,),-,+,=,\",\',{,},[,],\\,|,`,~,\r,\n,\t, ", vt);
    for (size_t i = 0; i < vt.size(); ++ i)
    {
		char bbd;		
		bbd = boost::lexical_cast<char>( vt[i].c_str() );
		wstr.erase(remove(wstr.begin(), wstr.end(), bbd), wstr.end());			
    }

	Temporary_str 	 += wstr;
	sendCGlobal::CTransfer_instruction(Temporary_str);

 	  
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	
	GroupUserUpdate();	
	shellgrouoppget();
	//找不到gid所以才出現亂碼
	
}

void GroupEventer::UserAdd(std::string wstr)
{  						
	std::string Temporary_str;
	Temporary_str = "UserAdd ";	
	Temporary_str += GroupEventer::GroupName;
	Temporary_str += " ";
		
	std::vector<std::string> vt;
    GroupEventer::bhja1("!,@,#,$,%,^,&,*,(,),-,+,=,\",\',{,},[,],\\,|,`,~,\r,\n,\t, ", vt);
    for (size_t i = 0; i < vt.size(); ++ i)
    {
		char bbd;		
		bbd = boost::lexical_cast<char>( vt[i].c_str() );
		wstr.erase(remove(wstr.begin(), wstr.end(), bbd), wstr.end());			
    }	
	
	Temporary_str += wstr;
	sendCGlobal::CTransfer_instruction(Temporary_str);
		
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	
	GroupUserUpdate();
	shellgrouoppget();	
	
}

void GroupEventer::UserDel(std::string wstr)
{  			
	
	std::vector<std::string> vt;
    GroupEventer::bhja1("!,@,#,$,%,^,&,*,(,),-,+,=,\",\',{,},[,],\\,|,`,~,\r,\n,\t, ", vt);
    for (size_t i = 0; i < vt.size(); ++ i)
    {
		char bbd;		
		bbd = boost::lexical_cast<char>( vt[i].c_str() );
		wstr.erase(remove(wstr.begin(), wstr.end(), bbd), wstr.end());			
    }	
	std::string Temporary_str;
	Temporary_str = "UserDel ";	
	Temporary_str += GroupEventer::GroupName;
	Temporary_str += " ";
	Temporary_str += wstr;
	sendCGlobal::CTransfer_instruction(Temporary_str);
	 
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

	
	GroupUserUpdate();
	shellgrouoppget();	
	
}
void GroupEventer::GroupUserUpdate()
{
	/*
	sendCGlobal::Transfer_instruction = "update"; 
	
	
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}
 */
}

void GroupEventer::UserMod(std::string wstr)
{  				
	std::string Temporary_str;
	Temporary_str = "UserMod ";	
	Temporary_str += GroupEventer::GroupName;
	Temporary_str += " ";
	Temporary_str += wstr;
	sendCGlobal::CTransfer_instruction(Temporary_str);
	
	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> client_ptr(new sendclient(io_service,endpoint));
		io_service.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}
 
	
	GroupUserUpdate();
	shellgrouoppget();	
	
}

int GroupEventer::split(const std::string& str, std::vector<std::string>& ret_ )
{
	std::string sep = "\n";

	 if (str.empty())
	 {
		return 0;
	 }
 
	 string tmp;
	 string::size_type pos_begin = str.find_first_not_of(sep);
	 string::size_type comma_pos = 0;
 
	 while (pos_begin != string::npos)
	 {
		 comma_pos = str.find(sep, pos_begin);
		 if (comma_pos != string::npos)
		 {
			 tmp = str.substr(pos_begin, comma_pos - pos_begin);
			 pos_begin = comma_pos + sep.length();
		 }
		 else
		 {
			 tmp = str.substr(pos_begin);
			 pos_begin = comma_pos;
		 }
 
		 if (!tmp.empty())
		 {
			 ret_.push_back(tmp);
			 tmp.clear();
		 }
	 }
	 return 0;
}

int GroupEventer::bhja1(const std::string& str, std::vector<std::string>& ret_ )
{
	std::string sep = ",";
	 if (str.empty())
	 {
		return 0;
	 }
 
	 string tmp;
	 string::size_type pos_begin = str.find_first_not_of(sep);
	 string::size_type comma_pos = 0;
 
	 while (pos_begin != string::npos)
	 {
		 comma_pos = str.find(sep, pos_begin);
		 if (comma_pos != string::npos)
		 {
			 tmp = str.substr(pos_begin, comma_pos - pos_begin);
			 pos_begin = comma_pos + sep.length();
		 }
		 else
		 {
			 tmp = str.substr(pos_begin);
			 pos_begin = comma_pos;
		 }
 
		 if (!tmp.empty())
		 {
			 ret_.push_back(tmp);
			 tmp.clear();
		 }
	 }
	 return 0;
}