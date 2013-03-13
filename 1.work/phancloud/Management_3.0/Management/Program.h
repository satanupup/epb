#include <windows.h>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

class ProgramEventer{
private:
	
public:
	static int bb(const std::string& str, std::vector<std::string>& ret_);
		//以"/n"為區隔分割為元件，填入容器
	static int hh(const std::string& str, std::vector<std::string>& ret_);
		//以","為區隔分割為元件，填入容器
	static int ProgramEventNumber;
	static int ProgramNumberID;
	static int ProgramProgramNumberID;
	static std::string ProgramGroupName;
	static std::string GetAPPNameAPPON;
	//static int GetCountSoftware;
	static std::string GetAPPName;
	static std::string GetAPPPathName;
	static int rg;

	

static BOOL InitListViewColumns(HWND );
//ListView設置
static void SoftwareView(std::string);
//GetSoftwareName
static void SetView(std::string,LVITEM,int);
	//ListView
static void ProgramGetGroupList();
//GroupList
static void SoftwareTick(std::string,std::string,std::string);
	//軟體勾選
static void APPDel(std::string);
	//軟體刪除
static void SoftwarePath(std::string a,std::string b);
	//GetSoftwarePathName
static void AppendSpace();
//複製檔案的遞迴
static void CopyFiles( const bf::path& from, const boost::filesystem::path& to );
	//複製檔案
static void GetFiles( const boost::filesystem::path& from, const boost::filesystem::path& to );
	//取得檔案
static std::string GetFolderName();
	//取得資料夾名稱

static HWND hProgramView				;
static HWND hProgramGroupList			;
static HWND hProgramGroupText			;
static HWND hProgramGroupProgramList	;
static HWND hProgramGroupProgramUseText	;
static HWND hProgramGroupProgramMaxText	;

static HWND hProgramGroupProgramText	;
static HWND hProgramGroupProgramPathText;
static HWND hProgramSoftwareEditText	;
static HWND hProgramSoftwarehProgBar	;
static HWND hProgramSoftwarePathText	;
static HWND hProgramSoftwareAppMaxText	;



};

void RegisterDialogPROGRAM_TITLE(HWND);
	//初始化介面，設置WM_COMMAND的地方
LRESULT CALLBACK DialogProcPROGRAM_TITLE(HWND, UINT, WPARAM, LPARAM); //loadimginformation
	//置中及只能開一個視窗的count設置