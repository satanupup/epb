#include <windows.h>

class GroupEventer{
public:
	
static void shellgrouoppget();	//從伺服端取回群組列表
static void shelluserpget(std::string wstr);	//從伺服端取回使用者列表，參數一填入群組
static void GrouopAdd(std::string wstr);//新增群組
static void GrouopDel(std::string wstr);//刪除群組
static void UserAdd(std::string wstr);//新增使用者
static void UserDel(std::string wstr);//刪除使用者
static void GroupUserUpdate();//傳給伺服端update，已註解
static void UserMod(std::string wstr);	//更改使用者群組
static std::string GroupName;

static int GroupEventer::split(const std::string& str, std::vector<std::string>& ret_ );	//以"/n"為區隔分割為元件，填入容器
static int bhja1(const std::string& str, std::vector<std::string>& ret_ );	//以","為區隔分割為元件，填入容器

static HWND hGroupList		;
static HWND hGroupText		;
static HWND hUserList		;
static HWND hUserText		;
static HWND hGroupEditText	;
static HWND hUserEditText	;
static HWND hUserModText	;
static HWND hGroupModText	;

  static int GroupEventNumber;
  static int GroupNumberID;
};

LRESULT CALLBACK DialogProcGROUPUSER_TITLE(HWND, UINT, WPARAM, LPARAM); //loadimginformation
	//初始化介面，設置WM_COMMAND的地方
void RegisterDialogGROUPUSER_TITLE(HWND);
//置中及只能開一個視窗的count設置
