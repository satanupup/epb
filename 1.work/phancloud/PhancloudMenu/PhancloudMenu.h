// win
#include <winsock2.h>
#include <istream>
#include <iostream>
#include <ostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <shellapi.h>
#include <stack> 
#include <tchar.h>
#include <wchar.h>
#include <strsafe.h>
#include <atlbase.h> 
#include <winnetwk.h>
#include <time.h> 
#pragma   comment(lib,"mpr")
#pragma comment(lib, "ws2_32.lib")

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>
#include <conio.h>

//boost
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>

//epb to be...
#include <epb_BoostClass.h>
#include <epb_icmp_header.hpp>
#include <epb_ipv4_header.hpp>
#include <epb_SendMessageGetString.h>
#include <epb_bearlib.h>
#include <epb_Container.h>
#include "IdNumber.h"
#include "applay_entry.h"
#include "Common.h"
#include "ApplicationScope.h"
#include "CallbackHandler.h"

#pragma once



class MainApp{
	
public:
    MainApp();
    ~MainApp();

    static HRESULT Initialize();
    static void RunMessageLoop();
	
	static void hello_world(std::string str);
	static void hello_world2(std::string str);
	static int buttonNumber;
	static bool userlogin;        
	static std::string DiskUser;
	static std::string DiskGroup;

private:
	static void GetAppDlgItemText(HWND a,int b,int c);
	static void SetAppMenu(HWND h);
	
    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam
        );

    static HWND m_hwnd;
	static HINSTANCE hInstance;	
	static HWND title1;
	static HWND title2;
	static HWND title3;
	static HWND title4;
	static HWND title5;
	static HWND title6;
	static HWND title7;
	static HWND title8;
	static HWND title9;
	static HWND title10;
	static HWND title11;
	static HWND title12;
	
	static NETRESOURCE nr;
	static NETRESOURCE ntr;
	static HACCEL hAccel ;//•[≥t¡‰
	static HWND hwndEdit1;
	static HWND hwndEdit2;	
	static HWND button1;
	
	static HWND button2;
	
	static HWND button3;
	static ACCEL Accel[3] ;
	static HMENU hmenu;//µÊ≥Ê•y¨`
	   
	static std::string ProgramGroupName;
};


/////////////////////////////////////////////////////////////////////////////////////////////


class CWhatheverYouWantToHold
{
public:
	CWhatheverYouWantToHold()
	{
		wcscpy_s(m_szName, TEXT("This could be any user-supplied data."));
		hwnd = NULL;
	}
private:
	TCHAR  m_szName[MAX_PATH];
	HANDLE hwnd;
};

class CMyCallbackHandler: public CCallbackHandler
{	
	epb::Container::a_multimap ccprogaom;
	epb::Container::a_multimap::dictionary acontainer; 	
	std::string bpathnumber;
	std::string bpathDirectory;

	virtual void OnProcessEvent(
		PQUEUED_ITEM pQueuedItem, 
		PVOID        pvParam
		);	
	
};

void Perform(
	CCallbackHandler*        pHandler,
	CWhatheverYouWantToHold* pParamObject
	)
{
	CApplicationScope& g_AppScope = CApplicationScope::GetInstance(
		pHandler     // User-supplied object for handling notifications
		);
	__try
	{
		//
		// Initiate monitoring
		//
		g_AppScope.StartMonitoring(
			pParamObject // Pointer to a parameter value passed to the object 
			); 		
		
		while(!_kbhit())
		{
			Sleep(100);
		}
		DWORD bres=0;				
		bres = _getch();
	}
	__finally
	{
		//
		// Terminate the process of observing processes
		//
		g_AppScope.StopMonitoring();
	}
}