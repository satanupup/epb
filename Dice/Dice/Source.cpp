
#include "stdafx.h"
#include <Strsafe.h>

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client
{
public:
	chat_client(boost::asio::io_service& io_service,
		tcp::resolver::iterator endpoint_iterator)
		: io_service_(io_service),
		socket_(io_service)
	{
		boost::asio::async_connect(socket_, endpoint_iterator,
			boost::bind(&chat_client::handle_connect, this,
			boost::asio::placeholders::error));

	}

	void write(const chat_message& msg)
	{
		io_service_.post(boost::bind(&chat_client::do_write, this, msg));
	}

	void close()
	{
		io_service_.post(boost::bind(&chat_client::do_close, this));
	}

private:

	void handle_connect(const boost::system::error_code& error)
	{
		if (!error)
		{
			char ch1[256];

			MessageBoxA(NULL,_itoa(read_msg_.body_length(),ch1,256),"oo",MB_OK ); 
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), chat_message::header_length),
				boost::bind(&chat_client::handle_read_header, this,
				boost::asio::placeholders::error));
		}
	}

	void handle_read_header(const boost::system::error_code& error)
	{
		if (!error && read_msg_.decode_header())
		{
			char ch1[256];

			MessageBoxA(NULL,_itoa(read_msg_.body_length(),ch1,256),"oo",MB_OK ); 
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
				boost::bind(&chat_client::handle_read_body, this,
				boost::asio::placeholders::error));
		}
		else
		{
			do_close();
		}
	}

	void handle_read_body(const boost::system::error_code& error)
	{
		if (!error)
		{
			Sleep(10);
			char ch1[256];

			MessageBoxA(NULL,_itoa(read_msg_.body_length(),ch1,256),"oo2",MB_OK ); 

			std::cout.write(read_msg_.body(), read_msg_.body_length());
			std::cout << "\n";
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), chat_message::header_length),
				boost::bind(&chat_client::handle_read_header, this,
				boost::asio::placeholders::error));
		}
		else
		{
			do_close();
		}
	}

	void do_write(chat_message msg)
	{
		bool write_in_progress = !write_msgs_.empty();
		write_msgs_.push_back(msg);
		if (!write_in_progress)
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
				write_msgs_.front().length()),
				boost::bind(&chat_client::handle_write, this,
				boost::asio::placeholders::error));
		}
	}

	void handle_write(const boost::system::error_code& error)
	{
		if (!error)
		{
			write_msgs_.pop_front();
			if (!write_msgs_.empty())
			{
				boost::asio::async_write(socket_,
					boost::asio::buffer(write_msgs_.front().data(),
					write_msgs_.front().length()),
					boost::bind(&chat_client::handle_write, this,
					boost::asio::placeholders::error));
			}
		}
		else
		{
			do_close();
		}
	}

	void do_close()
	{
		socket_.close();
	}

private:
	boost::asio::io_service& io_service_;
	tcp::socket socket_;
	chat_message read_msg_;
	chat_message_queue write_msgs_;
};


typedef struct dicedate
{
	char Role_Name[256];
	char Dice_reasons[256];
	char Quantity[256];
	char Dice_face[256];
	char Adjusted_value[256];
}dicedate;

// This is a typedef for a random number generator.
// Try boost::mt19937 or boost::ecuyer1988 instead of boost::minstd_rand
typedef boost::minstd_rand base_generator_type;
// This is a reproducible simulation experiment.  See main().
void experiment(base_generator_type & generator);
const int ID_MYBUTTON = 60001;
const int ID_UPDATE = 60002;
const int IDS_LISTBOX = 60007;
int NumberID = 0;


HWND Role_Name = NULL;
HWND Dice_reasons = NULL;
HWND Quantity = NULL;
HWND Dice_face = NULL;
HWND Adjusted_value = NULL;
HWND Tlist= NULL;
static HWND hList		= NULL;

bool check(std::string str);
int split(const std::string& str, std::vector<std::string>& ret_ );
void shellgrouoppget(HWND hwnd);
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
		800,       // 寬度：使用預設值
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
void hello_world() 
{
	MessageBoxA(NULL,"Hello world, I'm a thread!","oo",MB_OK ); 
	std::string name;
	try
	{
		boost::asio::io_service io_service;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("127.0.0.1","8080");
		tcp::resolver::iterator iterator = resolver.resolve(query);

		chat_client c(io_service, iterator);
		boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
		char line[chat_message::max_body_length + 1];
		sprintf_s(line,"apple\napple");
		//		char str[256];
		//while (std::cin.getline(line, chat_message::max_body_length + 1))
		//	{
		//std::cin.getline(line, chat_message::max_body_length + 1);

		Sleep(300);
		//std::getline (std::cin,name);
		//	std::cout << name ;
		//	MessageBoxA(NULL,name.c_str(),"oo",MB_OK ); 

		using namespace std; // For strlen and memcpy.
		chat_message msg;
		msg.body_length(strlen(line));
		memcpy(msg.body(), line, msg.body_length());
		msg.encode_header();
		c.write(msg);
		//	}

		c.close();
		t.join();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)name.c_str());


}
LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	std::vector<std::string> vtsub;	
	switch (Message) 
	{ 
	case WM_CREATE: 
		{

			CreateWindowA("STATIC", "角色名稱", WS_CHILD | WS_VISIBLE ,
				20, 15, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "擲骰原因", WS_CHILD | WS_VISIBLE ,
				20, 85, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "骰子數量", WS_CHILD | WS_VISIBLE ,
				140, 15, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "骰子面數", WS_CHILD | WS_VISIBLE ,
				260, 15, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindowA("STATIC", "調整值", WS_CHILD | WS_VISIBLE ,
				380, 15, 100, 28, hwnd, NULL, 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 
			Role_Name = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				20, 50, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Dice_reasons = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				140, 85, 200, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Quantity = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				140, 50, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Dice_face = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				260, 50, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			Adjusted_value = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
				380, 50, 100, 28, hwnd, NULL,
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL); 

			CreateWindow(TEXT("BUTTON"), TEXT("擲骰"), WS_CHILD | WS_VISIBLE ,
				500, 50, 100, 28, hwnd, HMENU(ID_MYBUTTON), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);

			CreateWindow(TEXT("BUTTON"), TEXT("刷新"), WS_CHILD | WS_VISIBLE ,
				500, 85, 100, 28, hwnd, HMENU(ID_UPDATE), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);

			hList = CreateWindow(L"LISTBOX",NULL,
				WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
				LBS_STANDARD & (!LBS_SORT) | LBS_NOTIFY |WS_HSCROLL | WS_VSCROLL ,
				20, 120, 700, 300, hwnd, HMENU(IDS_LISTBOX), 
				((LPCREATESTRUCT)lParam)->hInstance,
				NULL);
			/*
			Tlist = CreateWindowA("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,
			500, 140, 100, 28, hwnd, NULL,
			((LPCREATESTRUCT)lParam)->hInstance,
			NULL); */


			bearlib::wreadcfg(0);

		}
		break;
	case WM_COMMAND:
		// 剖析功能表選取項目:
		switch (LOWORD(wParam))
		{
			NumberID  = SendMessage (hList, LB_GETCURSEL, 0, 0) ;
		case ID_MYBUTTON:
			{	
				// 開始一條使用 "hello_world" function 的新執行緒
				//	boost::thread my_thread(&hello_world);
				// 等待執行緒完成工作
				//	my_thread.join();
				/*
				std::string name;
				try
				{
				boost::asio::io_service io_service;
				tcp::resolver resolver(io_service);
				tcp::resolver::query query("127.0.0.1","8080");
				tcp::resolver::iterator iterator = resolver.resolve(query);

				chat_client c(io_service, iterator);
				boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
				char line[chat_message::max_body_length + 1];
				sprintf(line,"apple\napple");

				//while (std::cin.getline(line, chat_message::max_body_length + 1))
				//	{

				std::getline (std::cin,name);
				std::cout << name ;
				MessageBoxA(NULL,name.c_str(),"oo",MB_OK ); 

				using namespace std; // For strlen and memcpy.
				chat_message msg;
				msg.body_length(strlen(line));
				memcpy(msg.body(), line, msg.body_length());
				msg.encode_header();
				c.write(msg);
				//	}

				c.close();
				t.join();
				}
				catch (std::exception& e)
				{
				std::cerr << "Exception: " << e.what() << "\n";
				}
				SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)name.c_str());

				*/

				sendCGlobal::ClientVerification();
				WCHAR strText[2048];

				char   GetszText[30000]; 

				char   GetszText2[30000]; 

				char   GetszText3[30000]; 

				char   GetszText4[30000]; 

				char   GetszText5[30000]; 
				
        memset(strText,0,2048);
        memset(GetszText,0,30000);
		memset(GetszText2,0,30000);
		memset(GetszText3,0,30000);
		memset(GetszText4,0,30000);
		memset(GetszText5,0,30000);
		
				SendMessageA(Role_Name,WM_GETTEXT,30,(LPARAM)GetszText); 
				SendMessageA(Dice_reasons,WM_GETTEXT,200,(LPARAM)GetszText2); 
				SendMessageA(Quantity,WM_GETTEXT,10,(LPARAM)GetszText3); 
				SendMessageA(Dice_face,WM_GETTEXT,10,(LPARAM)GetszText4); 
				SendMessageA(Adjusted_value,WM_GETTEXT,10,(LPARAM)GetszText5); 


				if(strcmp(GetszText,"") == 0)
				{
					break;
				}
				if(strcmp(GetszText2,"") == 0)
				{
					break;
				}
				
				if((strcmp(GetszText3,"") == 0) || !check(GetszText3) || atoi(GetszText3) >= 30)
				{
					break;
				}
				if((strcmp(GetszText4,"") == 0) || !check(GetszText4) || atoi(GetszText3) >= 30)
				{
					break;
				}
				
				if((strcmp(GetszText5,"") == 0) || !check(GetszText5) || atoi(GetszText5) >= 899999999)
				{
					break;
				}

				std::string Temporary_str;
				Temporary_str = "Connection";
				Temporary_str += " ";
				Temporary_str += GetszText;
				Temporary_str += ",";
				Temporary_str += GetszText2;
				Temporary_str += ",";
				Temporary_str += GetszText3;
				Temporary_str += ",";
				Temporary_str += GetszText4;
				Temporary_str += ",";
				Temporary_str += GetszText5;

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
					MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 2048 );
					OutputDebugString(strText);     
				}

				sendCGlobal::CVerificationNumberR(sendCGlobal::CReceive_instructions().c_str());	

				MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, strText, 2048 );
				MessageBox(NULL,strText,L"骰子",MB_OK |MB_ICONINFORMATION); 

				SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)sendCGlobal::CReceive_instructions().c_str());

				
							
				vtsub.push_back(sendCGlobal::CReceive_instructions().c_str());
				SendMessage (hList, LB_RESETCONTENT, 0, 0) ;
				std::vector<std::string>::reverse_iterator rIt = vtsub.rbegin();
				for (size_t i = 0; i < vtsub.size(); ++ i)
				{ 
					SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)rIt[i].c_str());
				}
			}
			break;
		case ID_UPDATE:
			{	
				sendCGlobal::ClientVerification();
				SendMessage (hList, LB_RESETCONTENT, 0, 0) ;
				//				sendCGlobal::ClientVerification();
				WCHAR strText[2048];
				std::string Temporary_str;
				Temporary_str = "DiceUpdate";

				
        memset(strText,0,2048);
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
					MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 2048 );
					OutputDebugString(strText);     
				}

				sendCGlobal::CVerificationNumberR(sendCGlobal::CReceive_instructions().c_str());	

				MultiByteToWideChar( CP_ACP, 0, sendCGlobal::CReceive_instructions().c_str(), -1, strText, 2048 );
				//MessageBox(NULL,strText,L"error",MB_OK |MB_ICONINFORMATION); 
				/////////split

				std::vector<std::string> vt;
				split(sendCGlobal::CReceive_instructions().c_str(), vt);
				/*for (size_t i = 0; i < vt.size(); ++ i)
				{ 
					SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)vt[i].c_str());
				}*/

				std::vector<std::string>::reverse_iterator rIt = vt.rbegin();
				for (size_t i = 0; i < vt.size(); ++ i)
				{ 
					SendMessageA(hList,LB_ADDSTRING,0,(LPARAM)rIt[i].c_str());
				}
				//////////////////////////////////////////


			}
			break;
		case IDS_LISTBOX:
			{	//LBN_DBLCLK
				if(HIWORD(wParam)==LBN_SELCHANGE)
				{					
					if (LB_ERR == (NumberID = SendMessage (hList, LB_GETCURSEL, 0, 0L)))
						break ;
					shellgrouoppget(hwnd);
				}					

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


void shellgrouoppget(HWND hwnd)
{	
	//strsafe.h的前面定義#define STRSAFE_NO_DEPRECATE  因為設定視警告為錯誤的關係
	//#define STRSAFE_NO_DEPRECATE
	static PTSTR 		pText ;
	HGLOBAL      		hGlobal ;
	PTSTR        		pGlobal ;	
	char cc[5000];
	TCHAR bb[5000];
        memset(cc,0,5000);		
        memset(bb,0,5000);
	SendMessageA (hList, LB_GETTEXT, NumberID, (LPARAM)cc);
	SetWindowTextA(Tlist,cc);

	

	MultiByteToWideChar( CP_ACP, 0, cc, -1, bb, 5000 );

	pText = (PTSTR)malloc ((lstrlen (bb) + 1) * sizeof (TCHAR)) ;
	lstrcpy ((LPWSTR)pText, (LPCWSTR)bb) ;
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


int split(const std::string& str, std::vector<std::string>& ret_ )
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


bool check(std::string str)
{
	int rrnum=str.length();
	for(int i=0;i<rrnum;i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
			return false;
	}
	return true;

}