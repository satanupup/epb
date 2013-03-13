#include <winsock2.h>
#include <istream>
#include <iostream>
#include <ostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
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
#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#pragma   comment(lib,"mpr")

class bearlib
{
public:
	
static void wait (__in int seconds );
static std::string& trim(__in std::string &s) ;
static WCHAR *ANSItoUNICODE(__in const std::string &Source );
static std::string UNICODEtoANSI(__in const WCHAR *Source );
static bool readTheWholeFile(const char* fn, std::vector<char>& data);

static void readcfg(__in int Encounter);
static std::string readcfg(){return _cfgIP;}

static std::wstring s2ws(__in const std::string& s);

static void wreadcfg(__in int Encounter);
static std::wstring wreadcfg(){return _wcfgIP;}


static void Cacobuf(__in std::string nacobuf);
static std::string Cacobuf(){return _nacobuf;}

static void CGroup(__in std::string nGroup);
static std::string CGroup(){return _nGroup;}


static int str_match(const char *str1, const char *str2);


static std::string getHostInfo();

static void All_letters_to_uppercase(__in char *c,__out_opt char *h);
static void cfgistrue();
static std::string DiskAvailable(__in int Encounter);
	static void CopyFiles( const boost::filesystem::path& from, const boost::filesystem::path& to );
	static void AppendSpace();
	
	static int splitWriteN(const std::string& str, std::vector<std::string>& ret_ );
	static int splitppp(const std::string& str, std::vector<std::string>& ret_ );
	static int splitdr(const std::string& str, std::vector<std::string>& ret_ );
	
	static bool terminateProcess(unsigned int PID);
	
private:
	static std::string _cfgIP;
	static std::wstring _wcfgIP;
	
	static std::string _nGroup;
	static std::string _nacobuf;
	static int g_iHierarchy;
};


struct compare
{
	bool operator ()(std::string s1,std::string s2)
	{
	   return s1>s2;
	}
};
class SystemProcessPath
{
public:	
	SystemProcessPath()
	{
		iflag = 0;
		stpath = "";
	};
	typedef std:: multimap <std:: string, std:: string> mmss;
	void pathflag(int a);
	std:: string pathflag();
	int func(std:: string a,std:: string bb);
	void iflagAdd();
	//
//	bool CompareBySize( const boost::filesystem::path& rP1, const boost::filesystem::path& rP2 );
	void outputFileInfo( const boost::filesystem::path& rPath );
	void ScanDirectory( const boost::filesystem::path& rPath );
	void DisplayProcessNameAndID( DWORD processID );
	void Pathstr(std::string str);	
	//int Processstr(std::string str);	

private:
	typedef std::set<std::string,compare> _SET;
	_SET Epathstr;
	_SET Eprocestr;
	mmss mmmap;
	static int iflag;
	static std:: string stpath;
};