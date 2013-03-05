
#include "stdafx.h"


// This is a typedef for a random number generator.
// Try boost::mt19937 or boost::ecuyer1988 instead of boost::minstd_rand
typedef boost::minstd_rand base_generator_type;
// This is a reproducible simulation experiment.  See main().
void experiment(base_generator_type & generator);
/*
首先就是擲骰無上限...或者至少255顆
數量
骰面
調整值
選用則是第二組以上的數量與骰面
不過神啟只用到D6所以是選擇性加入功能啦_A_
然後就是公開性
骰網的用意是為了能公開擲骰
X 的「X」 擲了「5 d 6 + 13」 ，擲出「1、2、5、5、3」，總合為「29」。
Quantity
Dice face
Adjusted value
*/
const int ID_MYBUTTON = 60001;

HWND Role_Name = NULL;
HWND Dice_reasons = NULL;
HWND Quantity = NULL;
HWND Dice_face = NULL;
HWND Adjusted_value = NULL;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

/* ************************************
* 功能顯示一個視窗
**************************************/
int WINAPI WinMain(HINSTANCE hinstance, 
				   HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, 
				   int nCmdShow) 
{     
	WNDCLASSEX wcx;         //　視窗類
	HWND hwnd;              //  視窗處理
	MSG msg;               //　訊息    

	// 填充視窗類的資料結構
	wcx.cbSize = sizeof(wcx);// 結構體的大小
	wcx.style = CS_HREDRAW | CS_VREDRAW;    // 樣式：大小改變時重繪介面 
	wcx.lpfnWndProc = WndProc; // 視窗訊息處理函數 
	wcx.cbClsExtra = 0;           // 不使用類記憶體
	wcx.cbWndExtra = 0;          // 不使用視窗記憶體 
	wcx.hInstance = hinstance;// 所屬的應用程式實例處理 
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // 圖示：使用預設值
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);// 遊標：使用預設值
	wcx.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH);      // 背景：白色
	wcx.lpszMenuName =  NULL;  // 選單：不使用
	wcx.lpszClassName = TEXT("MainWClass");// 視窗類名 
	wcx.hIconSm = (HICON)LoadImage(hinstance,// 小圖示
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
		TEXT("MainWClass"),       // 視窗名
		TEXT("Dice"),            // 視窗標題 
		WS_OVERLAPPEDWINDOW,// 視窗樣式  
		100,      // 水準位元置X：使用預設值 
		100,      // 垂直位元置Y：使用預設值
		640,       // 寬度：使用預設值
		480,       // 高度：使用預設值
		(HWND) NULL,         // 父視窗：無 
		(HMENU) NULL,        // 選單：使用視窗類的選單 
		hinstance,           // 應用程式實例處理 
		(LPVOID) NULL);      // 視窗建立時資料：無 

	if (!hwnd) 
	{
		return 1; 
	}
	// 顯示視窗 

	RECT   rect;   
	int   ScreenWidth= GetSystemMetrics(SM_CXSCREEN);   
	int   ScreenHeight=  GetSystemMetrics(SM_CYSCREEN); 
	GetWindowRect(hwnd,&rect);
	int width = rect.right-rect.left;
	int height = rect.bottom-rect.top;
	MoveWindow(hwnd,ScreenWidth/2-width/2,ScreenHeight/2-height/2,width,height,TRUE);


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
			SendMessage (hwnd, WM_DESTROY, 0, 0) ;			
			CloseHandle(hmutex); 
        return FALSE; 
		} 
    } 
    else 
    { 
        MessageBox(NULL,TEXT("無法建立Mutex!請重新執行"),TEXT("SMSServer"),MB_OK |MB_ICONINFORMATION); 
        //關閉互斥對象，退出程序 
		SendMessage (hwnd, WM_DESTROY, 0, 0) ;		
		if(hmutex != NULL)
			CloseHandle(hmutex); 
        return FALSE; 
    }

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
/* ************************************
* WndProc
* 功能視窗訊息處理函數，
對所有的訊息都使用NULL處理函數
**************************************/

LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (Message) 
	{ 
	case WM_CREATE: 
		{
			/*
			Role Name:
			Dice reasons:
			數量 骰面 調整值
			Role_Name 
			Dice_reasons
			Quantity
			Dice face
			Adjusted value
			選用則是第二組以上的數量與骰面
			不過神啟只用到D6所以是選擇性加入功能啦_A_*/
			//Ctrl+K->Ctrl+D
			
			bearlib::wreadcfg(0);

			sendCGlobal::ClientVerification();
			WCHAR strText[512];
		{
			//
		
		std::string Temporary_str;
		Temporary_str = "Connection";
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

		sendCGlobal::CVerificationNumberR(sendCGlobal::CReceive_instructions().c_str());	
			  
			 MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, strText, 510 );
			 MessageBox(NULL,strText,L"error",MB_OK |MB_ICONINFORMATION); 
			//
		}
			CreateWindowA("STATIC", "Role Name", WS_CHILD | WS_VISIBLE ,
				20, 24, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "Dice reasons", WS_CHILD | WS_VISIBLE ,
				140, 24, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "Quantity", WS_CHILD | WS_VISIBLE ,
				260, 24, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "Dice face", WS_CHILD | WS_VISIBLE ,
				380, 24, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "Adjusted value", WS_CHILD | WS_VISIBLE ,
				500, 24, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 
			Role_Name = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				20, 55, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Dice_reasons = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				140, 55, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Quantity = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				260, 55, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Dice_face = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				380, 55, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Adjusted_value = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				500, 55, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindow(TEXT("BUTTON"), TEXT("按鈕1"), WS_CHILD | WS_VISIBLE ,
				500, 100, 100, 28, hwnd, HMENU(ID_MYBUTTON), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);

			//	SetWindowTextA(Quantity,"cc");

		}
		break;
	case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
		case ID_MYBUTTON:
			{		

				char   szText[256]; 
				SendMessageA(Quantity,WM_GETTEXT,10,(LPARAM)szText); 

				char   szText2[256]; 
				SendMessageA(Dice_face,WM_GETTEXT,10,(LPARAM)szText2); 

				int a,b,c;
				a = atoi(szText);
				b = atoi(szText2);
				c = a + b;
				char ch1[256];
				sprintf_s(ch1,"%d",c);

				MessageBoxA(NULL, ch1 ,"Error" , MB_OK);


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



// This is a reproducible simulation experiment.  See main().
void experiment(base_generator_type & generator)
{
  // Define a uniform random number distribution of integer values between
  // 1 and 6 inclusive.
  typedef boost::uniform_int<> distribution_type;
  typedef boost::variate_generator<base_generator_type&, distribution_type> gen_type;
  gen_type die_gen(generator, distribution_type(1, 60));

  // If you want to use an STL iterator interface, use iterator_adaptors.hpp.
  boost::generator_iterator<gen_type> die(&die_gen);
  for(int i = 0; i < 10; i++)
    std::cout << *die++ << " ";
  std::cout << '\n';
}