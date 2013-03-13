#pragma once
#include <winsock2.h>
#include <windows.h>
#include <iostream>

#include <tchar.h>
#include <fstream>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>
#include <string>
#include <vector>


#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;

class MainApp{
	
public:
    MainApp();
    ~MainApp();

    HRESULT Initialize();
	//設置加速鍵，背景及icon，置中以及不能多開此軟體的地方

    void RunMessageLoop();//主迴圈
  

private:
	//初始化介面，設置WM_COMMAND的地方
    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam
        );
	
private:
    HWND m_hwnd;
	HINSTANCE hInstance;	
	static HACCEL hAccel ;//加速鍵
	static ACCEL Accel[3] ;
	
	
	
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
	static HWND title13;
	static HWND title14;
	static HWND title15;

	static HWND Account;
	static HWND Password;
	static HWND Login;

	static void GetCard();//卡片鎖，已註解
	static void GetAppDlgItemText(HWND a,int b,int c);
	//登入判斷是由設置掛載samba實現，已註解
public:
	static HINSTANCE hinst; 
	static unsigned long UsageCount;

};



//#define One ((int)(MainApp::UsageCount > 30000))
#define One ((int)(1))
