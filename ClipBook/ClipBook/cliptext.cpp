/*-------------------------------------------------------------------------
CLIPTEXT.C --		The Clipboard and Text
(c) Charles Petzold, 1998
--------------------------------------------------------------------------*/
// stdafx.h : 可在此標頭檔中包含標準的系統 Include 檔，
// 或是經常使用卻很少變更的
// 專案專用 Include 檔案
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // 從 Windows 標頭排除不常使用的成員
// Windows 標頭檔:
#include <winsock2.h>
#include <windows.h>

// C RunTime 標頭檔
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <ctime>            // std::time

#include <atlbase.h>
#include <atlconv.h>

#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

//
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>


#include <Shlobj.h>
#include <assert.h>

#pragma   comment(lib,"mpr")

using namespace std;
// TODO: 在此參考您的程式所需要的其他標頭

#include "resource.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
#ifdef UNICODE
#define CF_TCHAR CF_UNICODETEXT
TCHAR szDefaultText[]		= TEXT ("Default Text - Unicode Version") ;
TCHAR szCaption[]			= TEXT ("Clipboard Text Transfers - Unicode Version") ;
#else
#define CF_TCHAR CF_TEXT
TCHAR szDefaultText[] = TEXT ("Default Text - ANSI Version") ;
TCHAR szCaption[]     		= TEXT ("Clipboard Text Transfers - ANSI Version") ;

#endif
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{
	static TCHAR 	szAppName[] = TEXT ("ClipText") ;
	HACCEL       			hAccel ;
	HWND         			hwnd ;
	MSG          			msg ;
	WNDCLASS     			wndclass ;

	wndclass.style         			= CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc   			= WndProc ;
	wndclass.cbClsExtra    			= 0 ;
	wndclass.cbWndExtra    			= 0 ;
	wndclass.hInstance     			= hInstance ;
	wndclass.hIcon         			= LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor       			= LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground 		= (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName  		= szAppName ;
	wndclass.lpszClassName 		= szAppName ;

	if (!RegisterClass (&wndclass))
	{
		MessageBox (	NULL, TEXT ("This program requires Windows NT!"),
			szAppName, MB_ICONERROR) ;
		return 0 ;
	}

	hwnd = CreateWindow (szAppName, szCaption,
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL) ;

	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;
	hAccel = LoadAccelerators (hInstance, szAppName) ;

	while (GetMessage (&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator (hwnd, hAccel, &msg))
		{
			TranslateMessage (&msg) ;
			DispatchMessage (&msg) ;
		}
	}
	return msg.wParam ;
}

LRESULT CALLBACK WndProc (	HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam)
{
	static PTSTR 		pText ;
	HGLOBAL      		hGlobal ;
	PTSTR        		pGlobal ;
	HDC          		hdc ;
	PAINTSTRUCT  		ps ;

	switch (message)
	{
	case 	WM_CREATE:
		{

			CreateWindow(TEXT("BUTTON"), TEXT("按鈕1"), WS_CHILD | WS_VISIBLE ,
				500, 100, 100, 28, hwnd, HMENU(ID_MYBUTTON), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);
		}
		return 0 ;

	case 	WM_COMMAND:
		switch (LOWORD (wParam))
		{
		case ID_MYBUTTON:
			{				
				TCHAR bb[]		= TEXT ("abc") ;				

				pText = (PTSTR)malloc ((lstrlen (bb) + 1) * sizeof (TCHAR)) ;
				lstrcpy (pText, bb) ;
				hGlobal = GlobalAlloc (GHND | GMEM_SHARE, 
					(lstrlen (pText) + 1) * sizeof (TCHAR)) ;
				pGlobal = (PTSTR)GlobalLock (hGlobal) ;
				lstrcpy (pGlobal, pText) ;
				GlobalUnlock (hGlobal) ;

				OpenClipboard (hwnd) ;
				EmptyClipboard () ;
				SetClipboardData (CF_UNICODETEXT, hGlobal) ;
				CloseClipboard () ;
			}
			break;
		}
		break ;

	case 	WM_PAINT:
		hdc = BeginPaint (hwnd, &ps) ;
		EndPaint (hwnd, &ps) ;
		return 0 ;
	case 	WM_DESTROY:
		PostQuitMessage (0) ;
		return 0 ;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}