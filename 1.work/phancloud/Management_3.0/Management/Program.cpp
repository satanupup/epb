#include "stdafx.h"


int ProgramEventer::ProgramEventNumber = 0;
int ProgramEventer::ProgramNumberID = 0;
int ProgramEventer::ProgramProgramNumberID = 0;

std::string ProgramEventer::GetAPPNameAPPON = "";
std::string ProgramEventer::ProgramGroupName = "";
std::string ProgramEventer::GetAPPName = "";
std::string ProgramEventer::GetAPPPathName = "";

HWND ProgramEventer::hProgramView					= NULL;
HWND ProgramEventer::hProgramGroupList				= NULL;
HWND ProgramEventer::hProgramGroupText				= NULL;
HWND ProgramEventer::hProgramGroupProgramList		= NULL;
HWND ProgramEventer::hProgramGroupProgramText		= NULL;
HWND ProgramEventer::hProgramGroupProgramUseText	= NULL;
HWND ProgramEventer::hProgramGroupProgramMaxText	= NULL;

HWND ProgramEventer::hProgramGroupProgramPathText	= NULL;
HWND ProgramEventer::hProgramSoftwareEditText		= NULL;
HWND ProgramEventer::hProgramSoftwarehProgBar		= NULL;
HWND ProgramEventer::hProgramSoftwarePathText		= NULL;
HWND ProgramEventer::hProgramSoftwareAppMaxText		= NULL;

int ProgramEventer::rg = 0;

NETRESOURCE ntr;  
int g_iHierarchy = 0;

LRESULT CALLBACK DialogProcPROGRAM_TITLE( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	static bool PROGRAMbChangeText = true;
	PAINTSTRUCT ps;
	HDC hdc; 
	HMENU hMenu, hSubMenu;
	DWORD bres=0;
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
 
				ProgramEventer::hProgramGroupList = CreateWindow(L"LISTBOX",NULL,
						WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
 LBS_STANDARD & (!LBS_SORT) | LBS_NOTIFY |WS_HSCROLL | WS_VSCROLL ,
						x, 30, 160*One, 365*One, hwnd, HMENU(IDS_LISTBOX_PROGRAM_GROUP), 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
 
				ProgramEventer::hProgramGroupText = CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
						x, 395, 160*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				}
				{//user
					int x = 200;
				CreateWindow(L"STATIC", 
						L"Programs", WS_CHILD | WS_VISIBLE,
						x, 11, 80*One, 20*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				ProgramEventer::hProgramView = CreateWindow(WC_LISTVIEW, NULL, 
					WS_CHILD | WS_VISIBLE | 
					LVS_TYPEMASK | LVS_SINGLESEL | LVS_SHOWSELALWAYS | LVS_ALIGNLEFT | WS_BORDER | WS_TABSTOP ,
						x, 30, 160*One, 260*One, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				//816
				
				
				ProgramEventer::hProgramGroupProgramMaxText = CreateWindow(L"EDIT", 
							L"appMax Interim", WS_CHILD | WS_VISIBLE | WS_BORDER,
							x, 305, 160*One, 20*One, hwnd, NULL, 
							((LPCREATESTRUCT)lParam)->hInstance,
							NULL);

				ProgramEventer::hProgramGroupProgramUseText = CreateWindow(L"EDIT", 
							L"appuse Interim", WS_CHILD | WS_VISIBLE | WS_BORDER,
							x, 330, 160*One, 20*One, hwnd, NULL, 
							((LPCREATESTRUCT)lParam)->hInstance,
							NULL);


				ProgramEventer::hProgramGroupProgramText = CreateWindow(L"EDIT", 
							L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
							x, 355, 160*One, 20*One, hwnd, NULL, 
							((LPCREATESTRUCT)lParam)->hInstance,
							NULL);
				ProgramEventer::hProgramGroupProgramPathText = CreateWindow(L"EDIT", 
							L"", WS_CHILD | WS_VISIBLE | WS_HSCROLL  |
					WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL ,
							x, 380, 160*One, 40*One, hwnd, NULL, 
							((LPCREATESTRUCT)lParam)->hInstance,
							NULL);
				/*
				CreateWindow(L"EDIT", 
						L"", WS_CHILD | WS_VISIBLE| WS_BORDER |ES_READONLY,
						400, 30, 180, 20, hwnd, NULL, 
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
				*/
					//Enable
					CreateWindow(L"BUTTON", 
						L"Assign", WS_CHILD | WS_VISIBLE ,//Store check results
						400, 30, 200*One, 20*One, hwnd, HMENU(IDS_SAVE_PROGRAM),  
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(L"BUTTON", //Delete software
						L"AppDel", WS_CHILD | WS_VISIBLE ,
						400, 60, 200*One, 20*One, hwnd, HMENU(IDS_APPDEL_PROGRAM),  
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);

					CreateWindow(L"BUTTON", 
						L"",
						WS_CHILD | WS_VISIBLE |BS_GROUPBOX	,
						390, 80, 230*One, 200*One, hwnd, NULL,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(TEXT("STATIC"),
						TEXT("Software Name"), 
					WS_CHILD | WS_VISIBLE ,
					400, 90, 200*One, 28*One, hwnd, NULL, 
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 

					ProgramEventer::hProgramSoftwareEditText = CreateWindow(TEXT("Edit"), 
						TEXT(""),
					WS_CHILD | WS_VISIBLE |WS_BORDER,
					400, 120, 100*One, 28*One, hwnd, NULL,
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 
					
					CreateWindow(TEXT("BUTTON"),
						TEXT("AppNew"), WS_CHILD | WS_VISIBLE ,//Upload
						510, 180, 100*One, 20*One, hwnd, (HMENU)IDS_APPADD_PROGRAM,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(TEXT("STATIC"),
						TEXT("progress"), 
					WS_CHILD | WS_VISIBLE ,
					400, 200, 200*One, 28*One, hwnd, NULL, 
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 
					ProgramEventer::hProgramSoftwarehProgBar = CreateWindow(PROGRESS_CLASS,
						TEXT("Progress"), WS_CHILD | WS_VISIBLE ,
						400, 220, 200*One, 50*One, hwnd, (HMENU)IDC_PROGRESS1,
						((LPCREATESTRUCT)lParam)->hInstance,
						NULL);
					CreateWindow(TEXT("STATIC"),
						TEXT("Path"), 
					WS_CHILD | WS_VISIBLE ,
					510, 90, 80*One, 28*One, hwnd, NULL, 
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 

					ProgramEventer::hProgramSoftwarePathText = CreateWindow(TEXT("Edit"), 
						TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_HSCROLL  |
					WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL ,
					510, 120, 100*One, 50*One, hwnd, NULL,
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 

					////////
					//0816
					
					CreateWindow(TEXT("STATIC"),
						TEXT("AppMax"), 
					WS_CHILD | WS_VISIBLE ,
					400, 150, 80*One, 28*One, hwnd, NULL, 
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 
					
					ProgramEventer::hProgramSoftwareAppMaxText = CreateWindow(TEXT("Edit"), 
						TEXT(""),	WS_CHILD | WS_VISIBLE |WS_BORDER,
						400, 170, 80*One, 28*One, hwnd, NULL,
					((LPCREATESTRUCT)lParam)->hInstance,
					NULL); 
					

										//C:\Program Files\Microsoft Office
				}
				{
 
					ProgramEventer::ProgramGetGroupList();
					ProgramEventer::InitListViewColumns(ProgramEventer::hProgramView);
					
				}
		}
		break;
		case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
			ProgramEventer::ProgramNumberID  = SendMessage (ProgramEventer::hProgramGroupList, LB_GETCURSEL, 0, 0) ;
			ProgramEventer::ProgramProgramNumberID  = SendMessage (ProgramEventer::hProgramGroupProgramList, LB_GETCURSEL, 0, 0) ;
			 
			
		case ID_MYBUTTON:
			{		
				if (PROGRAMbChangeText)
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
               PROGRAMbChangeText = !PROGRAMbChangeText;
			}
			break;			
		case IDS_SAVE_PROGRAM:
			{				
				
				const int NumberMax = 1024;
				char strText[NumberMax]="\0";
				WCHAR wstrText[NumberMax]=TEXT("\0");
 				
			//	MessageBox(NULL,ProgramEventer::GetAPPNameAPPON.c_str() ,L"Error" , MB_OK); 

				//分割伺服器傳來的字串	
				std::vector<std::string> vt;
				ProgramEventer::bb(ProgramEventer::GetAPPNameAPPON.c_str(), vt);
				for (size_t i = 0; i < vt.size(); ++ i)
				{ 		
					std::string gg = ",";
					int abc = vt[i].find_last_of(gg);
			 								
					int dd;
					dd = boost::lexical_cast<int>( vt[i].substr(abc+1).c_str() );							
					
					std::string wTmp = "";				
					wTmp = boost::lexical_cast<std::string>( ListView_GetCheckState(ProgramEventer::hProgramView,i) );							
					ProgramEventer::SoftwareTick(ProgramEventer::ProgramGroupName,vt[i].substr(0,abc).c_str(),wTmp);
			
				}
			}		
			break;		
		case IDS_APPDEL_PROGRAM:
			{	
				if(ProgramEventer::GetAPPName == "")
				{					
				}
				else
				{
					//bear
					TCHAR g_w[512];
					MultiByteToWideChar( CP_ACP, 0, ProgramEventer::GetAPPName.c_str(), -1, g_w, 512 );	
					
					if(  MessageBox(NULL, g_w ,L"Whether to delete the software" , MB_OKCANCEL) == IDOK) 
					{												
						ProgramEventer::APPDel(ProgramEventer::GetAPPName);
					}
					else
					{											
					}
				}
			}		
			break;
		case IDS_LISTBOX_PROGRAM_GROUP:
			{	//LBN_DBLCLK
				if(HIWORD(wParam)==LBN_SELCHANGE)
				{					
					if (LB_ERR == (ProgramEventer::ProgramNumberID = SendMessage (ProgramEventer::hProgramGroupList, LB_GETCURSEL, 0, 0L)))
					break ;											
						
					TCHAR lpString[128]=TEXT("\0");
					SendMessage (ProgramEventer::hProgramGroupList, LB_GETTEXT, ProgramEventer::ProgramNumberID, (LPARAM) lpString) ;					 
					SetWindowText(ProgramEventer::hProgramGroupText,lpString);		

					char g_w[512];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 512, NULL, NULL ); 
				

					ProgramEventer::ProgramGroupName = g_w;
					
					//選擇的群組傳給伺服器
					//傳回軟體名稱及開關
					ProgramEventer::SoftwareView(ProgramEventer::ProgramGroupName);
				}
			}
			break;	
		case IDS_APPADD_PROGRAM:
			{	


				/*
			std::string strInstruction;
			strInstruction = "make -C /var/yp";		
	
			FILE *pp;
			if( (pp = popen(strInstruction.c_str(), "r")) == NULL )
			{
			std::cout<<"popen() error!"<<std::endl;
			exit(1);
			}
			pclose(pp);

			*/

				//hProgramSoftwareEditText
				TCHAR lpString[512] = TEXT("\0"); 
				GetWindowText(ProgramEventer::hProgramSoftwareEditText,lpString,512); 
				TCHAR lpString2[512] = TEXT("\0"); 
				GetWindowText(ProgramEventer::hProgramSoftwarePathText,lpString2,512); 					
				TCHAR lpString3[512] = TEXT("\0"); 
				GetWindowText(ProgramEventer::hProgramSoftwareAppMaxText,lpString3,512); 	
				

				std::string FolderNmae;

				
				char g_w_lp[512];
				char g_w_lp2[512];
				char g_w_lp3[512];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w_lp, 512, NULL, NULL ); 
				WideCharToMultiByte ( CP_ACP, 0, lpString2, -1, g_w_lp2, 512, NULL, NULL ); 
				WideCharToMultiByte ( CP_ACP, 0, lpString3, -1, g_w_lp3, 512, NULL, NULL ); 
				
				
				if((wcscmp(lpString,TEXT("")) == 0) || (wcscmp(lpString2,TEXT("")) == 0) || (wcscmp(lpString3,TEXT("")) == 0))
				{
					MessageBox(NULL, TEXT("Please name for your software or path") ,TEXT("Add") , MB_OK);
				}
				else
				{
					 /*
					FolderNmae = ProgramEventer::GetFolderName();
					boost::filesystem3::path p( FolderNmae );
					  if( exists( p ) && is_directory( p ) )
					  {					  		  						  													
						ntr.dwType = RESOURCETYPE_DISK;
						ntr.lpLocalName = TEXT("s:");
						std::wstring jj1 = TEXT("\\\\");
						jj1 += bearlib::wreadcfg().c_str();
						jj1 += TEXT("\\");
						jj1 += TEXT("App");
						//MessageBox(NULL,jj1.c_str(),TEXT("test"),MB_OK);
						
						ntr.lpRemoteName = (LPWSTR)jj1.c_str(); //L"\\\\192.168.3.115\\App";
						ntr.lpProvider = NULL;	
						WNetCancelConnection2(ntr.lpLocalName,CONNECT_UPDATE_PROFILE,true);
						
						DWORD resq = WNetAddConnection2(&ntr,TEXT(""),TEXT("App"),CONNECT_UPDATE_PROFILE);
				
						//copy folder				
						std::wstring CopyFolder;
						CopyFolder = TEXT("s:\\\\");
						CopyFolder += lpString;						
						boost::filesystem3::path p(  TEXT("s:\\\\") );
						  if( exists( p ) && is_directory( p ) )
						  {	
						 
							ProgramEventer::GetFiles( FolderNmae, CopyFolder.c_str() );
							SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_SETRANGE, 0, MAKELPARAM(0, ProgramEventer::rg)); 					
							SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_SETPOS, 0, 0);                // 設定進度條的初始位置											
							ProgramEventer::CopyFiles( FolderNmae, CopyFolder.c_str() );																	
							ProgramEventer::rg = 0;
							*/
						
		
							std::string Temporary_str;
							Temporary_str = "APPAdd ";
							Temporary_str +=	g_w_lp;	
							Temporary_str +=	",";
							Temporary_str +=	g_w_lp2;
							Temporary_str +=	",";
							Temporary_str +=	g_w_lp3;


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

							ProgramEventer::SoftwareView(ProgramEventer::ProgramGroupName);
														
							bres = WNetCancelConnection2(ntr.lpLocalName,CONNECT_UPDATE_PROFILE,true);
							bres = WNetCancelConnection2(ntr.lpRemoteName,CONNECT_UPDATE_PROFILE,true);	
							MessageBox(NULL, TEXT("Upload successful") ,TEXT("Upload") , MB_OK);
							/*
						  }
						  else
						  {
							  std::wstring fg;
							  fg = CopyFolder;
							  fg += TEXT("Mount failure");
							  MessageBox(NULL,fg.c_str(),TEXT("test"),MB_OK);

						  }*/
					/*  }
					  else
					  {
						  MessageBox(NULL, TEXT("Folder does not exist") ,TEXT("Error") , MB_OK);
					  }*/

				}
			}
			break;				
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		break;	
		case WM_NOTIFY:
		{		
			int nId = ::GetDlgCtrlID(ProgramEventer::hProgramView); 
			NMITEMACTIVATE *pListViewState=(NMITEMACTIVATE *)lParam;
			if(pListViewState->hdr.code==NM_CLICK)//NM_DBLCLK
			{
				ProgramEventer::ProgramProgramNumberID = pListViewState->iItem;
				TCHAR lpString[128] = TEXT("\0");
				ListView_GetItemText(ProgramEventer::hProgramView,pListViewState->iItem,0,lpString,128);	

				char g_w[128];
				WideCharToMultiByte ( CP_ACP, 0, lpString, -1, g_w, 128, NULL, NULL ); 
				
				ProgramEventer::GetAPPName = g_w;

				SetWindowText(ProgramEventer::hProgramGroupProgramText,lpString);	

				ProgramEventer::SoftwarePath(ProgramEventer::GetAPPName,ProgramEventer::ProgramGroupName);

				TCHAR g_h[512];
				MultiByteToWideChar( CP_ACP, 0, ProgramEventer::GetAPPPathName.c_str(), -1, g_h, 512 );	

				SetWindowText(ProgramEventer::hProgramGroupProgramPathText,g_h);	
				
				

					
				//////////////////
				
	
	std::string Temporary_str;
	Temporary_str  = "GetAppMax";
	Temporary_str  += ProgramEventer::GetAPPName.c_str();
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
	
	WCHAR strText[512];		
	MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, strText, 510 );
	SetWindowText(ProgramEventer::hProgramGroupProgramMaxText,strText);	
				///////////////
	//////////////////
	{	
	
	//std::string Temporary_str;
	Temporary_str  = "GetAppUse";
	Temporary_str  += ProgramEventer::GetAPPName.c_str();
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
		WCHAR cr3[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, cr3, 510 );
		OutputDebugString(cr3);     
	}
	
	WCHAR cr2[512];		
	MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, cr2, 510 );
	
	SetWindowText(ProgramEventer::hProgramGroupProgramUseText,cr2);	
	}
				//MessageBox(NULL,ProgramEventer::GetAPPName.c_str(),TEXT("test"),MB_OK);
			} 
		}
		break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
		break;
		case WM_CLOSE:
			ProgramEventer::ProgramEventNumber = ProgramEventer::ProgramEventNumber - 1;
			
			bres = WNetCancelConnection2(ntr.lpLocalName,CONNECT_UPDATE_PROFILE,true);
            bres = WNetCancelConnection2(ntr.lpRemoteName,CONNECT_UPDATE_PROFILE,true);	
			DestroyWindow(hwnd);
			break;       
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
  

}


void RegisterDialogPROGRAM_TITLE(HWND hwnd) 
{
  WNDCLASSEX wc = {0};
  wc.cbSize           = sizeof(WNDCLASSEX);
  wc.lpfnWndProc      = (WNDPROC) DialogProcPROGRAM_TITLE;
  wc.hInstance        = MainApp::hinst;
  wc.hbrBackground    = GetSysColorBrush(COLOR_3DFACE);
  wc.lpszClassName    = TEXT("DialogProcPROGRAM_TITLE");
  RegisterClassEx(&wc);

  RECT rect; 
	int ScreenWidth= GetSystemMetrics(SM_CXSCREEN); 
	int ScreenHeight= GetSystemMetrics(SM_CYSCREEN); 
	GetWindowRect(hwnd,&rect);
	int width = rect.right-rect.left;
	int height = rect.bottom-rect.top;
	   
 //WS_EX_DLGMODALFRAME 去掉視窗小圖示 | WS_EX_TOPMOST 總是在前
 CreateWindowEx(WS_EX_APPWINDOW |WS_EX_DLGMODALFRAME | WS_EX_TOPMOST, TEXT("DialogProcPROGRAM_TITLE"), TEXT("PROGRAM"), 
 WS_VISIBLE | WS_SYSMENU | WS_CAPTION , ScreenWidth/2-width/2, (ScreenHeight/2-height/2)+50, 640, 480, 
 NULL, NULL, MainApp::hinst, NULL);


 InitCommonControls();
 ProgramEventer::ProgramEventNumber = ProgramEventer::ProgramEventNumber + 1; 
}

void ProgramEventer::ProgramGetGroupList()
{
	const int NumberMax = 1024;
	char strText[NumberMax]="\0";
	WCHAR wstrText[NumberMax]=TEXT("\0");
	SendMessage (ProgramEventer::hProgramGroupList, LB_RESETCONTENT, 0, 0) ;
 		
		std::string Temporary_str;
		Temporary_str = "GroupList";
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
		WCHAR ccd3[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, ccd3, 510 );
		OutputDebugString(ccd3);     
	}
 
	 	
	
	//	TCHAR wstrText[1024] = L"\0";
	//	MultiByteToWideChar( CP_ACP, 0, getBuffer, -1, wstrText, 1024 );
	//	OutputDebugString(wstrText);

	vector<string> vt;


	ProgramEventer::bb(sendCGlobal::CReceive_instructions().c_str(), vt);
	for (size_t i = 0; i < vt.size(); ++ i)
	{ 		
		std::string gg = ",";
		int abc = vt[i].find_last_of(gg);
		 
		MultiByteToWideChar( CP_ACP, 0, vt[i].substr(0,abc).c_str(), -1, wstrText, NumberMax );	 	 
		SendMessage(ProgramEventer::hProgramGroupList,LB_ADDSTRING,0,(LPARAM)wstrText);		 
	}	
			 
}

BOOL ProgramEventer::InitListViewColumns(HWND hWndListView) 
{     	
	ShowWindow(ProgramEventer::hProgramView, SW_SHOW);
	ListView_SetExtendedListViewStyle(ProgramEventer::hProgramView, ListView_GetExtendedListViewStyle(ProgramEventer::hProgramView)
		| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

	
	LVCOLUMN lvc;

	// Insert column
	int iCol = 0;	
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_SUBITEM;
	lvc.iSubItem = iCol;	
	lvc.pszText = L"Software";
	lvc.fmt = LVCFMT_LEFT;   
	lvc.cchTextMax=9;
	lvc.cx = 160;   
	lvc.iSubItem = 0;

	if (ListView_InsertColumn(ProgramEventer::hProgramView, 0, &lvc)== -1)
	{
	OutputDebugString(L"ListView_InsertColumn failed.");
	}
		
    return TRUE;
} 
void ProgramEventer::SoftwareView(std::string a)
{	
	const int NumberMax = 1024;	
	char strText[NumberMax]="\0";
	WCHAR wstrText[NumberMax]=TEXT("\0");
	WCHAR wstrText2[NumberMax]=TEXT("\0");
	WCHAR wstrText3[NumberMax]=TEXT("\0");
			
	std::string Temporary_str;
	Temporary_str = "GetSoftwareName ";
	Temporary_str += a;
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
		WCHAR ccd2[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, ccd2, 510 );
		OutputDebugString(ccd2);     
	}

	LVITEM LvItem;
	SendMessage(ProgramEventer::hProgramView, LVM_DELETEALLITEMS, 0, LPARAM(&LvItem));
	//分割伺服器傳來的字串	
	std::vector<std::string> vt;


	ProgramEventer::bb(sendCGlobal::CReceive_instructions().c_str(), vt);
	//ProgramEventer::GetCountSoftware = vt.size();
	std::string gt="";
	std::string t1 = "!@";
	std::string t2 = "#$";
	std::string t3 = "%^";
	int w1=0;
	int w2=0;
	int w3=0;
	ProgramEventer::GetAPPNameAPPON = "";
		for (size_t i = 0; i < vt.size(); ++ i)
		{ 	
			w1 = vt[i].find  (t1);			 
			w2 = vt[i].find  (t2);			 
			w3 = vt[i].find  (t3);		
			 
			MultiByteToWideChar( CP_ACP, 0, vt[i].substr(0,w1).c_str(), -1, wstrText, NumberMax );//軟體名稱
			MultiByteToWideChar( CP_ACP, 0, vt[i].substr(w1+t1.size(),(w2-w1)-t2.size()).c_str(), -1, wstrText2, NumberMax );//打勾
			MultiByteToWideChar( CP_ACP, 0, vt[i].substr(w2+t2.size(),(w3-w2)-t3.size()).c_str(), -1, wstrText3, NumberMax );//軟體路徑
			
			//MessageBox(NULL, wstrText,TEXT("test"),MB_OK);
			
			ProgramEventer::GetAPPNameAPPON += vt[i].substr(0,w1).c_str();
			ProgramEventer::GetAPPNameAPPON += ",";
			ProgramEventer::GetAPPNameAPPON += vt[i].substr(w1+t1.size(),(w2-w1)-t2.size()).c_str();
			ProgramEventer::GetAPPNameAPPON += "\n";
			
			//if(i<vt.size()-1)
			

			ProgramEventer::GetAPPPathName = vt[i].substr(w2+t2.size(),(w3-w2)-t3.size()).c_str();

			int dd;
			dd = boost::lexical_cast<int>( wstrText2 );		
											
			ProgramEventer::SetView(vt[i].substr(0,w1).c_str(),LvItem,i);	
			ListView_SetCheckState(ProgramEventer::hProgramView, i, dd);	
			
		}
		
}


void ProgramEventer::SoftwarePath(std::string a,std::string b)
{	
	const int NumberMax = 1024;	
	char strText[NumberMax]="\0";
	WCHAR wstrText[NumberMax]=TEXT("\0");
	
	std::string Temporary_str;
	Temporary_str  = "GetSoftwarePathName ";
	Temporary_str  += a;//soft
	Temporary_str  += ",";
	Temporary_str  += b;//group
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
		WCHAR ccd[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, ccd, 510 );
		OutputDebugString(ccd);     
	}

	ProgramEventer::GetAPPPathName = sendCGlobal::CReceive_instructions().c_str();

		
}
void ProgramEventer::SetView(std::string a,LVITEM LvItem,int iCol)
{		
	// Insert item
	LvItem.mask = LVIF_TEXT | LVIF_STATE;
	LvItem.state = 0;   
	LvItem.stateMask = 0;  
	LvItem.iSubItem = 0;
	LvItem.cchTextMax = 64;
	
	TCHAR g_w[512];					
	MultiByteToWideChar( CP_ACP, 0, a.c_str(), -1, g_w, 512 );	

	LvItem.pszText = g_w;  
	LvItem.iItem = iCol;
	
		//SendMessage(hProgramViw, LVM_INSERTITEM, 0, LPARAM(&item));
	if (ListView_InsertItem(ProgramEventer::hProgramView, &LvItem) == -1)
	{
	OutputDebugString(L"ListView_InsertItem failed.");
	}
}

int crrtest(const string& str, vector<string>& ret_, string sep = ",")
{
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
void ProgramEventer::SoftwareTick(std::string a,std::string b,std::string c)
{
		
	std::string Temporary_str;
	Temporary_str 	 = "SoftwareTick ";
	Temporary_str 	 += a;
	Temporary_str 	 += " ";
	Temporary_str 	 += b;
	Temporary_str 	 += " ";
	Temporary_str 	 += c;
	sendCGlobal::CTransfer_instruction(Temporary_str);

 	
	
	vector<string> vt;
    crrtest("!,@,#,$,%,^,&,*,(,),-,+,=,\",\',{,},[,],\\,|,`,~,\r,\n,\t, ", vt);
    for (size_t i = 0; i < vt.size(); ++ i)
    {
		char bbd;		
		bbd = boost::lexical_cast<char>( vt[i].c_str() );
		a.erase(remove(a.begin(), a.end(), bbd), a.end());			
		b.erase(remove(b.begin(), b.end(), bbd), b.end());			
		c.erase(remove(c.begin(), c.end(), bbd), c.end());			
    }
	

					
	
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

}


void ProgramEventer::APPDel(std::string wstr)
{  		
		std::string Temporary_str;
		Temporary_str = "APPDel ";	
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
	
	SoftwareView(ProgramEventer::ProgramGroupName);
}

int ProgramEventer::bb(const std::string& str, std::vector<std::string>& ret_)
{
	 std::string sep;
	sep = "\n";
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

int ProgramEventer::hh(const std::string& str, std::vector<std::string>& ret_)
{
	 std::string sep;
	sep = ",";
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

void ProgramEventer::AppendSpace()
{	
	int iHie = g_iHierarchy;
	
	while( iHie>0 )
	{
//	cout<<" ";
	--iHie;	
	}
}
void ProgramEventer::CopyFiles( const boost::filesystem::path& from, const boost::filesystem::path& to )
{
	++g_iHierarchy;

	if( !boost::filesystem::exists(to) )
	{
		boost::filesystem::create_directories( to );
	}    

	boost::filesystem::directory_iterator end;

	for( boost::filesystem::directory_iterator it(from); it != end; ++it )
	{
		boost::filesystem::path newFrom = from;		
		newFrom /= it->path().filename();	
		boost::filesystem::path newTo = to;
		newTo /= it->path().filename();	

		if( boost::filesystem::is_directory( newFrom ) )
		{
			AppendSpace();
			SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_SETSTEP, 1, 0);              // 設定進度條的步進值
			SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_STEPIT, 0, 0);   
		

		//	cout<<"Copy Directory [" << newFrom.filename() <<"] to ["<< newTo.filename() <<"]" << endl;
			CopyFiles( newFrom, newTo );
		}
		else if( boost::filesystem::is_regular( newFrom ) )
		{
			AppendSpace();
			SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_SETSTEP, 1, 0);              // 設定進度條的步進值
			SendMessage(ProgramEventer::hProgramSoftwarehProgBar, PBM_STEPIT, 0, 0);   
		//	cout<<"Copy File ["<< newFrom.filename() <<"] to ["<< newTo.filename() << "]" << endl;
			boost::filesystem::copy_file( newFrom, newTo, boost::filesystem::copy_option::overwrite_if_exists );
		}
	}

	--g_iHierarchy;
}


void ProgramEventer::GetFiles( const boost::filesystem::path& from, const boost::filesystem::path& to )
{
	++g_iHierarchy;

	if( !boost::filesystem::exists(to) )
	{
		//boost::filesystem::create_directories( to );
	}    

	boost::filesystem::directory_iterator end;

	for( boost::filesystem::directory_iterator it(from); it != end; ++it )
	{
		boost::filesystem::path newFrom = from;		
		newFrom /= it->path().filename();	
		boost::filesystem::path newTo = to;
		newTo /= it->path().filename();	

		if( boost::filesystem::is_directory( newFrom ) )
		{
			ProgramEventer::AppendSpace();
			
			ProgramEventer::rg++;
		//	cout<<"Copy Directory [" << newFrom.filename() <<"] to ["<< newTo.filename() <<"]" << endl;
			GetFiles( newFrom, newTo );
		}
		else if( boost::filesystem::is_regular( newFrom ) )
		{
			ProgramEventer::AppendSpace();
			ProgramEventer::rg++;
		//	cout<<"Copy File ["<< newFrom.filename() <<"] to ["<< newTo.filename() << "]" << endl;
		//	boost::filesystem::copy_file( newFrom, newTo, boost::filesystem::copy_option::overwrite_if_exists );
		}
	}

	--g_iHierarchy;
}

std::string ProgramEventer::GetFolderName()
{
	std::string  bbb;
	BROWSEINFO BrowseInfo;
	memset(&BrowseInfo, 0, sizeof(BrowseInfo)); 
	TCHAR szBuffer[MAX_PATH]; 
	BrowseInfo.hwndOwner      = NULL;
	BrowseInfo.pszDisplayName = szBuffer;
	BrowseInfo.lpszTitle      = _T('\0');
	BrowseInfo.ulFlags        = BIF_RETURNONLYFSDIRS; 
	// Throw display dialog
	LPITEMIDLIST pList = SHBrowseForFolder(&BrowseInfo);
	assert (wcslen(szBuffer) < sizeof(szBuffer)); 
	if (pList != NULL)
	{
	 // Convert from MIDLISt to real string path
	 SHGetPathFromIDList(pList, szBuffer);				  
	// OutputDebugString(szBuffer);
	 char g_w[128];
	WideCharToMultiByte ( CP_ACP, 0, szBuffer, -1, g_w, 128, NULL, NULL ); 
				
	 bbb = g_w;
	 // Global pointer to the shell's IMalloc interface.  
	 LPMALLOC pMalloc;   
	 // Get the shell's allocator and free the PIDL returned by
	 // SHBrowseForFolder.
	 if (SUCCEEDED(SHGetMalloc(&pMalloc))) 
	  pMalloc->Free(pList);
	}
	return bbb;
}