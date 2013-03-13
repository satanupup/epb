
//---------------------------------------------------------------------------
//
// ConsCtl.cpp
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//子系統：
//監視進程創建和終止
//
// MODULE:    
//				Control application for monitoring NT process and 
//              DLLs loading observation. 
//模塊：
//控制應用程序和監測NT進程
// DLL的加載觀察。
//
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------

#include "Common.h"
#include <conio.h>
#include <tchar.h>
#include "ApplicationScope.h"
#include "CallbackHandler.h"
#include <iostream>
//
// This constant is declared only for testing putposes and
// determines how many process will be created to stress test
// the system
//此常量宣布測試putposes只
//決定有多少進程將創建壓力測試
//系統
//

//---------------------------------------------------------------------------
// 
// class CWhatheverYouWantToHold
//
// Implements a dummy class that can be used inside provide callback 
// mechanism. For example this class can manage sophisticated methods and 
// handles to a GUI Win32 Window. 
//實現了一個虛擬的類，可用於內提供回調
//機制。例如，這個類可以管理複雜的方法，
//處理一個GUI Win32窗口。
//
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// 
// class CWhatheverYouWantToHold
//
// Implements a dummy class that can be used inside provide callback 
// mechanism. For example this class can manage sophisticated methods and 
// handles to a GUI Win32 Window. 
//實現了一個虛擬的類，可用於內提供回調
//機制。例如，這個類可以管理複雜的方法，
//處理一個GUI Win32窗口。
//
//---------------------------------------------------------------------------

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
	// 
	// You might want to use this attribute to store a 
	// handle to Win32 GUI Window
//你可能想使用此屬性來存儲
//處理的Win32 GUI窗口
	//
	HANDLE hwnd;
};


//---------------------------------------------------------------------------
// 
// class CMyCallbackHandler
//
// Implements an interface for receiving notifications
//實現一個接口，用於接收通知
//
//---------------------------------------------------------------------------
class CMyCallbackHandler: public CCallbackHandler
{
	//
	// Implements an event method
//實現一個事件方法
	//
	virtual void OnProcessEvent(
		PQUEUED_ITEM pQueuedItem, 
		PVOID        pvParam
		)
	{
		TCHAR szFileName[MAX_PATH];
		//
		// Deliberately I decided to put a delay in order to 
		// demonstrate the queuing / multithreaded functionality 
//故意，我決定把以延遲
//演示排隊/多線程功能
		//
		::Sleep(500);
		//
		// Get the dummy parameter we passsed when we 
		// initiated process of monitoring (i.e. StartMonitoring() )
//獲取參數，我們passsed當我們的假人
//啟動監測進程（即StartMonitoring（））
		//
		CWhatheverYouWantToHold* pParam = static_cast<CWhatheverYouWantToHold*>(pvParam);
		//
		// And it's about time to handle the notification itself
//它的時間來處理的通知本身
		//
		if (NULL != pQueuedItem)
		{
			TCHAR szBuffer[1024];
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
				//
				// At this point you can use OpenProcess() and
				// do something with the process itself
//此時，您可以使用OpenProcess（）和
//執行過程中的東西本身
				//
				wsprintf(
					szBuffer,
					TEXT("Process has been created: PID=%.8X %s\n"),
					pQueuedItem->hProcessId,
					szFileName
					);
				OutputDebugString(szBuffer);    
			}
			else
			{
				wsprintf(
					szBuffer,
					TEXT("Process has been terminated: PID=%.8X\n"),
					pQueuedItem->hProcessId);
				OutputDebugString(szBuffer); 
			}
			//
			// Output to the console screen
//輸出到控制台屏幕
			//
			_tprintf(szBuffer);
		} // if
	}
};

//---------------------------------------------------------------------------
// Perform
//
// Thin wrapper around __try..__finally
//左右__薄包裝嘗試.. __finally
//---------------------------------------------------------------------------


void Perform(
	CCallbackHandler*        pHandler,
	CWhatheverYouWantToHold* pParamObject
	)
{
	CApplicationScope& g_AppScope = CApplicationScope::GetInstance(
		pHandler     // User-supplied object for handling notifications
		);//用戶提供的對象處理的通知
	__try
	{
		//
		// Initiate monitoring
//啟動監測
		//
		g_AppScope.StartMonitoring(
			pParamObject // Pointer to a parameter value passed to the object 
			); //參數值的指針傳遞給對象
		
		
		while(!_kbhit())
		{
			Sleep(100);
		}
	//	_getch();
		Sleep(100);
	}
	__finally
	{
		//
		// Terminate the process of observing processes
//終止觀察進程的過程中
		//
		g_AppScope.StopMonitoring();
	}
}


//---------------------------------------------------------------------------
// 
// Entry point
//
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{	
	CMyCallbackHandler      myHandler;
	CWhatheverYouWantToHold myView; 
	Perform( &myHandler, &myView );

	return 0;
}
//--------------------- End of the file -------------------------------------
