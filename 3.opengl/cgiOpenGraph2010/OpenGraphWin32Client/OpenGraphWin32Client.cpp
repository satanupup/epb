////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

// OpenGraphWin32Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <Winuser.h>
#include <time.h>
#include "OpenGraphWin32Client.h"


// jxu--
#include "OpenGraph.h"
using namespace NSOpenGraphLib;
#include "Helper.h"

COpenGraph m_openGraph;
int m_nCx;
int m_nCy;
HCURSOR m_hCursor;


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_OPENGRAPHWIN32CLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPENGRAPHWIN32CLIENT));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPENGRAPHWIN32CLIENT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
    m_hCursor = wcex.hCursor;
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_OPENGRAPHWIN32CLIENT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));


	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   // jxu--
   m_openGraph.Initialize(hWnd);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
        case ID_VIEW_SELECT_ALL:
            OnViewSelectall();
            break;
        case ID_VIEW_UNSELECT_ALL:
            OnViewUnselectall();
            break;
        case ID_VIEW_REVERSE_SELECT:
            OnViewReverseselect();
            break;
        case ID_DRAW_NODES:
            OnDrawDrawnodes();
            break;
        case ID_DRAW_LINES:
            OnDrawDrawlines();
            break;
		case ID_DRAW_TRIANGLES:
			OnDrawDrawtriangles();
            break;
        case ID_DRAW_QUADS:
            OnDrawDrawquads();
            break;
        case   ID_DRAW_CLEAR:
            OnDrawClear();
			break;
        case ID_MODE_DEFAULT:
            OnModeDefault();
            break;
        case ID_MODE_TRACK:
            OnModeTrack();
            break;
        case ID_MODE_ROTATE:
            OnModeRotate();
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		m_openGraph.Render();
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

    // jxu
    case WM_ERASEBKGND:
        break;

    case WM_SIZE:
        {
            m_nCx    = LOWORD(lParam );
            m_nCy = HIWORD(lParam );
            m_openGraph.SetWindowSize(m_nCx, m_nCy);
        }
        break;

    case WM_LBUTTONDOWN:
        {
            RECT rect;
            UINT nFlags = GET_KEYSTATE_WPARAM(wParam);
            POINT pt;
            pt.x = LOWORD(lParam);
            pt.y = HIWORD(lParam); 
            m_openGraph.OnLButtonDown(rect, nFlags, pt);
        }
        break;

    case WM_MOUSEMOVE:
        {
            m_openGraph.OnSetCursor();  // jxu-  Win32 app is different from MFC
            UINT nFlags = GET_KEYSTATE_WPARAM(wParam);
            POINT pt;
            pt.x = LOWORD(lParam);
            pt.y = HIWORD(lParam); 
            m_openGraph.OnMouseMove(nFlags, pt);
        }
        break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

