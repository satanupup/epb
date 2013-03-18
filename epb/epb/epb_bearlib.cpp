#include "epb_bearlib.h"


std::string bearlib::_cfgIP = "";
std::string bearlib::_nacobuf = "";
std::string bearlib::_nGroup = "";
std::wstring bearlib::_wcfgIP = L"";
int bearlib::g_iHierarchy = 0;

void bearlib::wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int bearlib::str_match(const char *str1, const char *str2)
{
    int i;
    int j;
    int k;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for (i=0;i<=len1 - len2; i++)
    {
        j=0;k=i;

        while(j<len2 && *(str1+k)==*(str2+j))
        {
            //printf("ok\n");
            k++;
            j++;             
        }
        // printf("j=%d, len2=%d", j, len2);
        if (j == len2)
        {
            return i;   // 匹配成功的初始位置 
        }
    }
    return -1;
}
// 雙碼轉萬國碼
WCHAR *bearlib::ANSItoUNICODE( const std::string &Source )
{
    static WCHAR strText[512];
    MultiByteToWideChar( CP_ACP, 0, Source.c_str(), -1, strText, 510 );
    return strText;
}
 // 萬國碼轉雙碼
std::string bearlib::UNICODEtoANSI( const WCHAR *Source )
{
    char strText[512];
    WideCharToMultiByte ( CP_ACP, 0, Source, -1, strText, 510, NULL, NULL );	
    return std::string( strText );
}

std::string& bearlib::trim(std::string &s) 
{
  if (s.empty()) {
    return s;
  }
  s.erase(0,s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  return s;
}

bool bearlib::readTheWholeFile(const char* fn, std::vector<char>& data)
{
	std::ifstream file(fn, std::ios_base::in | std::ios_base::binary);
	if ( !file ) return false;
	std::istreambuf_iterator<char> dataBegin(file);		
	std::istreambuf_iterator<char> dataEnd;
	data.assign(dataBegin, dataEnd);
	file.close();
	return true;
}


std::string bearlib::getHostInfo()
{
 WSAData wsaData;
 std::string IP;   
    WSAStartup(MAKEWORD(2,0),&wsaData);           //初始化WINSOCK調用   
    char HostName[64];                                             //存放本主機名   
    gethostname(HostName,sizeof(HostName));   //得到主機名     
    HOSTENT *lpHostEnt=gethostbyname(HostName);   //利用主機名去取主機結構   
    for (int i=0; lpHostEnt->h_addr_list[i]!=NULL;i++)   
       {   
        IN_ADDR *p=(IN_ADDR *)(lpHostEnt->h_addr_list[i]);   
        IP=inet_ntoa(*p);                         //數字地址轉換成帶.的IP串   
        }   
     WSACleanup();
  //return "["+(std::string)HostName+"]&&["+IP+"]";
  return IP;
}

void bearlib::readcfg(__in int Encounter)  
{
	Sleep(100);
	/*
	bearlib::cfgistrue();
	Sleep(100);
	std::ifstream in("Setting.cfg");
	std::string ddd2 = "";
	std::string strtmp;
	std::vector<std::string> vect;
	while(std::getline(in, strtmp, '\n'))
	vect.push_back(strtmp.substr(strtmp.find('=')+1, strtmp.find('\n')));	
	
	ddd2 = trim(vect[0]);*/
	bearlib::_cfgIP = "1.34.156.69";
	//_cfgIP = ddd2;
	
	Sleep(100);
}

std::wstring bearlib::s2ws(const std::string& s)
{
    setlocale(LC_ALL, "chs"); 
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
//    mbstowcs_s(_Dest,_Source,_Dsize);
	mbstowcs_s(&_Dsize,_Dest,_Dsize,_Source,_Dsize);
    std::wstring result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, "C");
    return result;
}

void bearlib::wreadcfg(__in int Encounter) 
{
	bearlib::readcfg(Encounter);
	_wcfgIP = s2ws(bearlib::readcfg());
}


void bearlib::CGroup(__in std::string nGroup) 
{
	_nGroup = nGroup;
}

void bearlib::Cacobuf(__in std::string nacobuf) 
{
	_nacobuf = nacobuf;
}
void bearlib::cfgistrue()
{

	boost::filesystem::path p( "Setting.cfg" );
	if( exists( p ) && is_regular_file( p ) )
	{
	}
	else
	{
	  MessageBox(NULL, L"Setting.cfg此文件不存在,自動創建" ,L"Error" , MB_OK);	  
	  std::ofstream outf("Setting.cfg",std::ios::trunc);
	  outf <<"IpAddress = 127.0.0.1";
	  outf.close();	
	}
}

void bearlib::All_letters_to_uppercase(char *c,char *h)
{
	std::ifstream fin(c); 
    std::ofstream fout(h); 

    if(!fin) { 
        std::cout << "無法讀入來源檔案" << std::endl;        
    } 

    if(!fout) { 
        std::cout << "無法輸出目的檔案" << std::endl;
        fin.close();
    } 

    char ch; 

    fin.unsetf(std::ios::skipws); // 不忽略空白 
    while(!fin.eof()) { 
        fin >> ch; 
        if(ch >= 97 && ch <= 122) 
            ch -= 32; 
        if(!fin.eof()) 
            fout << ch; 
    } 

    fin.close(); 
    fout.close(); 
}


std::string bearlib::DiskAvailable(int Encounter)
{
	Sleep(100);
	char szDriverBuffer[512];
	std::string csDriver;
	GetLogicalDriveStringsA(IN 512, OUT szDriverBuffer);
 	char *lpDriverBuffer = szDriverBuffer;
	std::string Diskstr[64] = {"C:\\","D:\\","E:\\","F:\\","G:\\","H:\\","I:\\","J:\\","K:\\","L:\\","M:\\","N:\\","O:\\","P:\\","Q:\\","R:\\","S:\\","T:\\","U:\\","V:\\","W:\\","X:\\","Y:\\","Z:\\"};	
	std::string The_goal;
	  /////////////////

  std::list<std::string> mylist (Diskstr,Diskstr+24);

  /////////////////////////////

	while (*lpDriverBuffer != NULL)
	{
		csDriver = lpDriverBuffer;
		lpDriverBuffer = lpDriverBuffer + csDriver.length() + 1;    
		for(int i=0;i<64;i++)
		{			
			if(csDriver == Diskstr[i])
			{
				//std::cout<<Diskstr[i].c_str()<<std::endl;
				mylist.remove(Diskstr[i].c_str());
			}
		}
	}	
	

	for (std::list<std::string>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	{				
		The_goal = *it;					
	}
	
	if(Encounter == 0)
	{
		mylist.remove(The_goal);			
		for (std::list<std::string>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		{				
			The_goal = *it;					
		}
	}  
	return The_goal.substr(0,The_goal.size()-1).c_str();
}


void bearlib::CopyFiles( const boost::filesystem::path& from, const boost::filesystem::path& to )
{
	++g_iHierarchy;

	if( !boost::filesystem::exists(to) )
	{
		boost::filesystem::create_directories( to );
	}    

	boost::filesystem::directory_iterator end;

	for( boost::filesystem::directory_iterator it(from); it != end; ++it )
	{
		boost::filesystem::path newFrom = from;		
		newFrom /= it->path().filename();	
		boost::filesystem::path newTo = to;
		newTo /= it->path().filename();	

		if( boost::filesystem::is_directory( newFrom ) )
		{
			AppendSpace();
		//	cout<<"Copy Directory [" << newFrom.filename() <<"] to ["<< newTo.filename() <<"]" << endl;
			CopyFiles( newFrom, newTo );
		}
		else if( boost::filesystem::is_regular( newFrom ) )
		{
			AppendSpace();
		//	cout<<"Copy File ["<< newFrom.filename() <<"] to ["<< newTo.filename() << "]" << endl;
			boost::filesystem::copy_file( newFrom, newTo, boost::filesystem::copy_option::overwrite_if_exists );
		}
	}

	--g_iHierarchy;
}

void bearlib::AppendSpace()
{
	int iHie = g_iHierarchy;
	
	while( iHie>0 )
	{
//	cout<<" ";
	--iHie;
	}
}



int bearlib::splitWriteN(const std::string& str, std::vector<std::string>& ret_ )
{
	std::string sep = "+Wrap+";

	 if (str.empty())
	 {
		return 0;
	 }
 
	 std::string tmp;
	 std::string::size_type pos_begin = str.find_first_not_of(sep);
	 std::string::size_type comma_pos = 0;
 
	 while (pos_begin != std::string::npos)
	 {
		 comma_pos = str.find(sep, pos_begin);
		 if (comma_pos != std::string::npos)
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



int bearlib::splitppp(const std::string& str, std::vector<std::string>& ret_ )
{
	std::string sep = ",";

	 if (str.empty())
	 {
		return 0;
	 }
 
	 std::string tmp;
	 std::string::size_type pos_begin = str.find_first_not_of(sep);
	 std::string::size_type comma_pos = 0;
 
	 while (pos_begin != std::string::npos)
	 {
		 comma_pos = str.find(sep, pos_begin);
		 if (comma_pos != std::string::npos)
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


int bearlib::splitdr(const std::string& str, std::vector<std::string>& ret_ )
{
	std::string sep = "+dr+";

	 if (str.empty())
	 {
		return 0;
	 }
 
	 std::string tmp;
	 std::string::size_type pos_begin = str.find_first_not_of(sep);
	 std::string::size_type comma_pos = 0;
 
	 while (pos_begin != std::string::npos)
	 {
		 comma_pos = str.find(sep, pos_begin);
		 if (comma_pos != std::string::npos)
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

//////////////////////////////////
bool bearlib::terminateProcess(unsigned int PID)
{
	 //取得除錯權限
	 HANDLE hProcess;
	 HANDLE hToken;

	 if(!OpenThreadToken(GetCurrentThread(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, FALSE, &hToken))
	 {
	 if (GetLastError() == ERROR_NO_TOKEN)
	 {
	 if (!ImpersonateSelf(SecurityImpersonation))
	 {
	 return false;
	 }


	 if(!OpenThreadToken(GetCurrentThread(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, FALSE, &hToken))
	 {
	 return false;
	 }
	 }
	 else
	 {
	 return false;
	 }
	 }

	 //開啟SeDebugPrivilege
	 TOKEN_PRIVILEGES tp = { 0 }; 

	 LUID luid; 
	 DWORD cb = sizeof(TOKEN_PRIVILEGES); 
	 if(!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
	 {
	 CloseHandle(hToken);
	 return false;
	 }

	 tp.PrivilegeCount = 1; 
	 tp.Privileges[0].Luid = luid; 
	 tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 

	 AdjustTokenPrivileges(hToken, FALSE, &tp, cb, NULL, NULL); 
	 if (GetLastError() != ERROR_SUCCESS) 
	 {
	 //無法取得SeDebugPrivilege
	 CloseHandle(hToken);
	 return false;
	 }

	 //開啟程序
	 if((hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID)) == NULL)
	 {
	 //無法開啟程序 ... 程序不存在?!
	 CloseHandle(hToken);
	 return false;
	 }

	 if(!TerminateProcess(hProcess, 0xffffffff))
	 {
	 //無法關閉程序?!(遇到那1%了)
	 CloseHandle(hToken);
	 CloseHandle(hProcess);
	 return false;
	 }

	 CloseHandle(hToken);
	 CloseHandle(hProcess);

	 //成功
 return true;
}

////////////////////////////////

 int SystemProcessPath::iflag = 0;
 std:: string SystemProcessPath::stpath = "";

void SystemProcessPath::ScanDirectory( const boost::filesystem::path& rPath )
{
  std::vector<boost::filesystem::path> vList;
  copy( boost::filesystem::directory_iterator(rPath), boost::filesystem::directory_iterator(), back_inserter( vList ) );
  for( std::vector<boost::filesystem::path>::const_iterator it = vList.begin(); it != vList.end(); ++ it )
  {
    if( is_directory( *it ) )
      ScanDirectory( *it );
    else
      outputFileInfo( *it );
  }
}
 
void SystemProcessPath::outputFileInfo( const boost::filesystem::path& rPath )
{
	std::string br = "";
	if(rPath.extension() == ".exe" || rPath.extension() == ".EXE" || rPath.extension() == ".eXE" || rPath.extension() == ".exE" || rPath.extension() == ".eXe" || rPath.extension() == ".Exe")
	{		
		br = rPath.parent_path().string();
		br += "\\";
		br += rPath.stem().string();
		br += rPath.extension().string();	

		char bh[64];
		sprintf_s(bh,"%d",iflag);
		stpath = bh;
		SystemProcessPath::mmmap.insert(std:: make_pair( SystemProcessPath::stpath,std::string(br)));
	}
}
void SystemProcessPath::Pathstr(std::string str)
{	
	boost::filesystem::path rootPath( str );
  if( exists( rootPath ) )
  {
    if( is_directory( rootPath ) )
      ScanDirectory( rootPath );
    else
      outputFileInfo( rootPath );
  }  
}

int SystemProcessPath:: func(std:: string aa,std:: string bb)
{
	const mmss & dns =  mmmap;
	typedef std:: multimap <std:: string, std:: string>:: const_iterator CIT;
	typedef std:: pair<CIT, CIT> Range;
	Range range=dns.equal_range( aa);
	Epathstr.clear();
	//Eprocestr.clear(); 
	for(CIT i=range.first; i!=range.second; ++i)
	{				
		Epathstr.insert(std::string(i->second.c_str()));	
	}
	_SET Eprocestr;
	Eprocestr.insert(std::string(bb));  	

	std::multiset<std::string> C;	
	set_intersection(Epathstr.begin(),Epathstr.end(),Eprocestr.begin(),Eprocestr.end(),inserter(C,C.begin()),compare());
	int checkPath = 0;
	if(C.empty())
		checkPath = 0;
	else
		checkPath = 1;
	return checkPath;
}
void SystemProcessPath::iflagAdd()
{
	iflag = iflag + 1;
}