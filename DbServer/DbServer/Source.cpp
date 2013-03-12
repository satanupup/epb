
/////////////
#include <stdio.h>
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <map>
#include <algorithm>
#include <sqlite3.h>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/random.hpp>

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>


//
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>


#include <ctime>

#pragma comment(lib,"sqlite3.lib")

using boost::asio::ip::tcp;


using namespace std;


class dicedate
{
public:
	dicedate(){		
        memset(Role_Name,0,256);
		memset(Dice_reasons,0,1024);
		memset(Quantity,0,256);
		memset(Dice_face,0,256);
		memset(Adjusted_value,0,256);
	}
	 char Role_Name[256];
	 char Dice_reasons[1024];
	 char Quantity[256];
	 char Dice_face[256];
	 char Adjusted_value[256];
};

class clientSessionMeng
	:public boost::enable_shared_from_this<clientSessionMeng>
{
public:
	clientSessionMeng(boost::asio::io_service& ioservice):m_socket(ioservice)
	{
		memset(data_, 0, sizeof(data_));
	}
	~clientSessionMeng()
	{
	}
	tcp::socket& socket()
	{
		return m_socket;
	}
	void start()
	{
		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));               
	}
private:

	double SampleNormal (double mean, double sigma);
	int bhja1(const string& str, vector<string>& ret_, string sep);
	int C_spart(const std::string& str, std::vector<std::string>& ret_);
	void EncodeDecode(char *str);
	void fn_GroupList(char *str);
	void fn_update(char *str);
	void fn_UserList(char *str);
	void fn_GetSoftwareName(char *str);
	void fn_GetSoftwarePathName(char *str);
	void fn_SoftwareTick(char *str);
	void fn_APPDel(char *str);
	void fn_APPAdd(char *str);
	void fn_groupadd(char *str);
	void fn_groupdel(char *str);
	void fn_UserAdd(char *str);
	void fn_UserDel(char *str);
	void fn_gg(char *str);
	void fn_UserMod(char *str);
	void fn_ManagementAccount(char *str);
	void fn_ClientVerification(char *str);

	void fn_Founding(char *str);
	void fn_Detail(char *str);
	void fn_MissionList(char *str);
	void fn_Deposit(char *str);
	void fn_NewAccount(char *str);

	void fn_Entrust(char *str);
	void fn_Receivingtask(char *str);
	void fn_Connection(char *str);

	void fn_OffsetCoordinates(char *str);
	void fn_GetAppMax(char *str);
	void fn_GetAppUse(char *str);
	void fn_Approve(char *str);
	void fn_AppLogout(char *str);
	void fn_DiceUpdate(char *str);


	void VerificationNumber(std::string VerificationNumberW){VerificationNumberW_ = VerificationNumberW;}
	std::string VerificationNumber(){return VerificationNumberW_;}


	void handle_write(const boost::system::error_code& error)
	{
		if(error)
		{
			m_socket.close();
		}
	}
	void handle_read(const boost::system::error_code& error)
	{
		if(!error)
		{
			EncodeDecode(data_); //dai
			//0608
			//	std::cout<<"2"<< data_ <<std::endl;

			//指令名稱不能夠重複 
			//例如UserList
			//UserListabc
			//這樣這兩個指令都會執行
			//需要更好的方案

			Sleep(1);
			//clientSessionMeng::VerificationIsTrue = true;

			instruction = "ClientVerification";
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "ClientVerification") == 0)	
				fn_ClientVerification(data_);

			instruction = "NTR";
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "NTR") == 0)	
			{
				//	std::cout<<"VerificationNumber="<<clientSessionMeng::VerificationNumber().c_str()<<std::endl;

				//std::cout<<"judgment="<<judgment.substr(instruction.length(),judgment.length()).c_str()<<std::endl;
				if(strcmp(clientSessionMeng::VerificationNumber().c_str(), judgment.substr(instruction.length(),judgment.length()).c_str()) == 0)
					clientSessionMeng::VerificationIsTrue = true;

			}

			if(VerificationIsTrue == true)
			{
				instruction = "update";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "update") == 0)	
					fn_update(data_);

				instruction = "GroupList";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GroupList") == 0)
					fn_GroupList(data_);

				instruction = "UserList";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserList") == 0)
					fn_UserList(data_);	

				instruction = "GetSoftwareName";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetSoftwareName") == 0)
					fn_GetSoftwareName(data_);

				instruction = "GetSoftwarePathName";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetSoftwarePathName") == 0)
					fn_GetSoftwarePathName(data_);

				instruction = "SoftwareTick";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "SoftwareTick") == 0)
					fn_SoftwareTick(data_);

				instruction = "APPDel";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "APPDel") == 0)
					fn_APPDel(data_);

				instruction = "APPAdd";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "APPAdd") == 0)
					fn_APPAdd(data_);

				instruction = "groupadd";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "groupadd") == 0)
					fn_groupadd(data_);

				instruction = "groupdel";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "groupdel") == 0)
					fn_groupdel(data_);

				instruction = "UserAdd";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserAdd") == 0)
					fn_UserAdd(data_);

				instruction = "UserDel";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserDel") == 0)
					fn_UserDel(data_);

				instruction = "gg";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "gg") == 0)
					fn_gg(data_);

				instruction = "UserMod";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserMod") == 0)
					fn_UserMod(data_);

				instruction = "ManagementAccount";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "ManagementAccount") == 0)
					fn_ManagementAccount(data_);

				instruction = "Founding";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Founding") == 0)
					fn_Founding(data_);

				instruction = "Detail";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Detail") == 0)
					fn_Detail(data_);

				instruction = "MissionList";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "MissionList") == 0)
					fn_MissionList(data_);

				instruction = "Deposit";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Deposit") == 0)
					fn_Deposit(data_);

				instruction = "NewAccount";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "NewAccount") == 0)
					fn_NewAccount(data_);


				instruction = "Entrust";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Entrust") == 0)
					fn_Entrust(data_);

				instruction = "Receivingtask";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Receivingtask") == 0)
					fn_Receivingtask(data_);


				instruction = "Connection";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Connection") == 0)
					fn_Connection(data_);

				instruction = "OffsetCoordinates";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "OffsetCoordinates") == 0)
					fn_OffsetCoordinates(data_);

				instruction = "GetAppMax";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetAppMax") == 0)
					fn_GetAppMax(data_);

				instruction = "GetAppUse";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetAppUse") == 0)
					fn_GetAppUse(data_);

				instruction = "Approve";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Approve") == 0)
					fn_Approve(data_);

				instruction = "AppLogout";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "AppLogout") == 0)
					fn_AppLogout(data_);
								
				instruction = "DiceUpdate";
				judgment = data_;
				if(strcmp(judgment.substr(0,instruction.length()).c_str(), "DiceUpdate") == 0)
					fn_DiceUpdate(data_);

				

			}
			else
			{
				m_socket.close();
			}


		}
		else
		{
			m_socket.close();
		}
	}
private:
	tcp::socket m_socket;
	const static int max_len = 16000;
	//	const int max_len
	char data_[max_len];

	static bool VerificationIsTrue;
	static std::string VerificationNumberW_;
	std::string judgment;
	std::string instruction;


};
std::string clientSessionMeng::VerificationNumberW_ = "";
bool clientSessionMeng::VerificationIsTrue = false;

class serverAppMeng
{
	typedef boost::shared_ptr<clientSessionMeng> session_ptr;
public:
	serverAppMeng(boost::asio::io_service& ioservice,tcp::endpoint& endpoint)
		:m_ioservice(ioservice),
		acceptor_(ioservice,endpoint)
	{
		session_ptr new_session(new clientSessionMeng(ioservice));
		acceptor_.async_accept(new_session->socket(),
			boost::bind(&serverAppMeng::handle_accept,this,boost::asio::placeholders::error,
			new_session));
	}
	~serverAppMeng()
	{
	}
private:
	void handle_accept(const boost::system::error_code& error,session_ptr& session)
	{
		if(!error)
		{
			//        std::cout << "aaget a new client!" << std::endl;
			session->start();
			session_ptr new_session(new clientSessionMeng(m_ioservice));
			acceptor_.async_accept(new_session->socket(),

				boost::bind(&serverAppMeng::handle_accept,this,boost::asio::placeholders::error,
				new_session));
		}
	}
private:
	boost::asio::io_service& m_ioservice;
	tcp::acceptor acceptor_;
};


void hello_world1() 
{	
	boost::asio::io_service myIoService;
	short port = 8100;
	tcp::endpoint endPoint(tcp::v4(),port);
	serverAppMeng sa(myIoService,endPoint);
	myIoService.run();

}


//////////////////////進入點///////////////////////////
int main(int argc , char* argv[])
{

	boost::thread my_thread(&hello_world1);	
	my_thread.join();



	return 0;
}


void clientSessionMeng::fn_update(char *str)
{

	if(strcmp(str, "update") == 0)
	{
		std::string strInstruction;
		strInstruction = "make -C /var/yp";		

		FILE *pp;
		if( (pp = _popen(strInstruction.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		_pclose(pp);

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));

	}
}

void clientSessionMeng::fn_GroupList(char *str)
{
	if(strcmp(str, "GroupList") == 0)
	{
		std::string strInstruction;
		strInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";

		char buf[max_len];
		FILE *pp;
		if( (pp = _popen(strInstruction.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		std::string strbh;
		strbh = "";
		while(fgets(buf, sizeof(buf), pp))
		{
			strbh += buf;
		}
		_pclose(pp);
		//

		if(strcmp(strbh.c_str(), "") == 0)
		{
			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{

			char br[1024];
			sprintf_s(br,"%s",strbh.c_str());
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;

			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt), 
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
	}
}


void clientSessionMeng::fn_UserList(char *str)
{

	std::string GroupName;
	GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	bool GroupIsTrue = false;
	std::string bhy= "";
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		//判斷傳來的群組是否存在  不存在的話才繼續新增使用者 OK

		bhy.erase(remove(bhy.begin(),bhy.end(),'\r'),bhy.end());
		bhy.erase(remove(bhy.begin(),bhy.end(),'\n'),bhy.end());
		bhy.erase(remove(bhy.begin(),bhy.end(),'\t'),bhy.end());

		if(bhy == judgment.substr(instruction.length(),judgment.length()))
		{
			//std::cout<<"aaaaaaaaa"<<std::endl;
			GroupIsTrue = true;
		}

	}
	_pclose(ff);


	//

	if(GroupIsTrue == true)
	{

		std::string bstrCode;	
		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4==";	              
		bstrCode += judgment.substr(instruction.length(),judgment.length()).c_str();
		bstrCode += " {print $1\",\"$4}'";


		char buf[max_len];
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		std::string strbh;
		strbh = "";
		while(fgets(buf, sizeof(buf), pp))
		{
			strbh += buf;
		}
		_pclose(pp);

		if(strcmp(strbh.c_str(), "") == 0)
		{
			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{

			char br[1024];
			sprintf_s(br,"%s",strbh.c_str());
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;
			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}


	}
	else
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}



}



void clientSessionMeng::fn_GetSoftwareName(char *str)
{

	std::string Software_APPNAME_APPON_str;

	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}


	//選到的Group
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();	
	//std::cout<<">"<<GroupNamestr.c_str()<<"<"<<std::endl;



	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[256];	
	sprintf_s(aa,"select APPNAME,APPON,APPPATHNAME from sensordata where GROUPNAME = \"%s\";",GroupNamestr.c_str());
	sql = aa;	

	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int bh=0;
	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{
		if(strcmp(azResult[i], "APPNAME") == 0 || strcmp(azResult[i], "APPON") == 0 || strcmp(azResult[i], "APPPATHNAME") == 0)
		{		
		}
		else
		{
			bh++;
			Software_APPNAME_APPON_str += azResult[i];

			if(bh==1)
			{
				Software_APPNAME_APPON_str += "!@";
			}
			if(bh==2)
			{
				Software_APPNAME_APPON_str += "#$";
			}
			if(bh == 3)
			{
				Software_APPNAME_APPON_str += "%^";
				Software_APPNAME_APPON_str += "\n";
				bh=0;
			}

			else
			{


			}

		}
	}
	//std::cout<<Software_APPNAME_APPON_str.c_str()<<std::endl;


	sqlite3_free_table( azResult );
	sqlite3_close(db);    

	if(strcmp(Software_APPNAME_APPON_str.c_str(), "") == 0)
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}
	else
	{

		char br[1024];
		sprintf_s(br,"%s",Software_APPNAME_APPON_str.c_str());
		EncodeDecode(br);
		std::string bgtt;
		bgtt = br;

		boost::asio::async_write(m_socket,
			boost::asio::buffer(bgtt),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}



}
void clientSessionMeng::fn_GetSoftwarePathName(char *str)
{
	std::string APPPATHNAME_str;

	/////////
	std::string APPNamestr;
	APPNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();	

	std::string ddt;
	ddt = ",";
	int ssde = APPNamestr.find_last_of(ddt);
	std::string APPName_01 = "";
	APPName_01 = APPNamestr.substr(0,ssde).c_str();
	std::string APPNameGroup_01 = "";
	APPNameGroup_01 = APPNamestr.substr(ssde+1).c_str();

	//std::cout<<APPName_01.c_str()<<" , "<<APPNameGroup_01.c_str()<<std::endl;

	//APPName_01.c_str() 
	//APPNameGroup_01.c_str()
	/////////
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[256];	
	sprintf_s(aa,"select APPPATHNAME from sensordata where APPNAME = \"%s\" and GROUPNAME = \"%s\";",APPName_01.c_str(),APPNameGroup_01.c_str());
	sql = aa;	

	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	
		if(strcmp(azResult[i], "APPPATHNAME") == 0)
		{		
		}
		else
		{
			APPPATHNAME_str += azResult[i];	
		}
	}

	sqlite3_free_table( azResult );
	sqlite3_close(db);    

	if(strcmp(APPPATHNAME_str.c_str(), "") == 0)
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}
	else
	{

		char br[1024];
		sprintf_s(br,"%s",APPPATHNAME_str.c_str());
		EncodeDecode(br);
		std::string bgtt;
		bgtt = br;
		boost::asio::async_write(m_socket,
			boost::asio::buffer(bgtt),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}




}


void clientSessionMeng::fn_SoftwareTick(char *str)
{
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();	
	//std::cout<<">"<<GroupNamestr.c_str()<<"<"<<std::endl;

	std::string GROUPNAME;
	std::string APPNAME;
	std::string APPON;

	vector<string> vt;
	bhja1(GroupNamestr.c_str(), vt, " ");
	for (size_t i = 0; i < vt.size(); ++ i)
	{
		GROUPNAME = vt[0].c_str();
		APPNAME = vt[1].c_str();
		APPON = vt[2].c_str();		
	}
	//std::cout<<">"<<GROUPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPON.c_str()<<"<"<<std::endl;


	//group02 office 1
	//update sensordata set APPON = "1" where GROUPNAME = "group02" and APPNAME = "office";
	//sprint(a,"update sensordata set APPON = %s where GROUPNAME = "%s" and APPNAME = "%s";",1,group02,office);

	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}

	char aa[256];
	sprintf_s(aa,"update sensordata set APPON = \"%s\" where GROUPNAME = \"%s\" and APPNAME = \"%s\";",APPON.c_str(),GROUPNAME.c_str(),APPNAME.c_str());
	sql = aa;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	sqlite3_close(db);    



	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}


void clientSessionMeng::fn_APPDel(char *str)
{
	std::string APPNamestr;
	APPNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();	

	{

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open("test.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		char aa[256];	
		sprintf_s(aa,"delete from SensorData where APPNAME='%s';",APPNamestr.c_str());
		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

		sqlite3_close(db);    
	}

	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok

	{
		FILE *pp;	
		std::string DelNameHome;
		DelNameHome = "/home/project/";
		DelNameHome += APPNamestr.c_str();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
			//刪除資料夾
			std::string DelApp;
			DelApp = "rm -r /home/project/";
			DelApp += APPNamestr.c_str();

			if( (pp = _popen(DelApp.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);
		}
		else
		{

		}

	}
	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok

	{
		FILE *pp;	
		std::string DelNameHome;
		DelNameHome = "/home/project/Phancloud/Reg/";
		DelNameHome += APPNamestr.c_str();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
			//刪除資料夾
			std::string DelApp;
			DelApp = "rm -r /home/project/Phancloud/Reg/";
			DelApp += APPNamestr.c_str();

			if( (pp = _popen(DelApp.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);
		}
		else
		{

		}

	}

	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));


}

void clientSessionMeng::fn_APPAdd(char *str)
{

	std::string APPNamestr;
	APPNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();	
	//std::cout<<APPNamestr.c_str()<<std::endl;

	std::string APPNAME;
	std::string APPPATHNAME;
	std::string APPMAX;

	vector<string> vt;
	bhja1(APPNamestr.c_str(), vt, ",");
	for (size_t i = 0; i < vt.size(); ++ i)
	{
		APPNAME = vt[0].c_str();
		APPPATHNAME = vt[1].c_str();
		APPMAX = vt[2].c_str();		
	}
	//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPMAX.c_str()<<"<"<<std::endl;


	//std::string ddt;
	//ddt = ",";
	//int ssde = APPNamestr.find_last_of(ddt);
	//std::string APPName_01 = "";
	//APPName_01 = APPNamestr.substr(0,ssde).c_str();
	//std::string APPNamePath_01 = "";
	//APPNamePath_01 = APPNamestr.substr(ssde+1).c_str();

	FILE *pp;

	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok
	std::string DelNameHome;
	DelNameHome = "/PhancloudData";


	boost::filesystem::path p(DelNameHome.c_str());
	if(exists(p) &&is_directory(p))
	{
	}
	else
	{

		std::string mkdirApp;
		mkdirApp = "mkdir /PhancloudData";

		if( (pp = _popen(mkdirApp.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}

		_pclose(pp);

	}

	DelNameHome = "/PhancloudData/App";

	boost::filesystem::path p2(DelNameHome.c_str());
	if(exists(p2) &&is_directory(p2))
	{
	}
	else
	{
		std::string mkdirApp;
		mkdirApp = "mkdir /PhancloudData/App";
		if( (pp = _popen(mkdirApp.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		_pclose(pp);


	}




	//改權限777
	std::string ChmodstrGroupName;

	ChmodstrGroupName = "chmod 777 /PhancloudData/App/";


	if( (pp = _popen(ChmodstrGroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);

	}

	_pclose(pp);

	//從路徑 /PhancloudData/App 查詢軟體名稱,取得新增的群組名稱,對DB插入所有的軟體
	//插入路徑


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;

	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}


	int nrow = 0, ncolumn = 0;
	//		char **azResult; //二維數組存放結果
	char aa[256];	


	//		sprintf_s(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12));");
	sprintf_s(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");


	sql = aa;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );



	std::string strInstruction;
	strInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1}'";

	char buf[max_len];


	if( (pp = _popen(strInstruction.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;

		exit(1);
	}

	while(fgets(buf, sizeof(buf), pp))
	{

		std::string strbh;
		strbh = buf;

		strbh.erase(remove(strbh.begin(),strbh.end(),'\r'),strbh.end());
		strbh.erase(remove(strbh.begin(),strbh.end(),'\n'),strbh.end());
		strbh.erase(remove(strbh.begin(),strbh.end(),'\t'),strbh.end());
		//std::cout<<buf<<"=="<<APPName_01.c_str()<<std::endl;
		//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
		//std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
		//std::cout<<">"<<APPMAX.c_str()<<"<"<<std::endl;

		sprintf_s(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s', '%s' , 0 , '%s' ,'%s' , 0);",strbh.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());

		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	

	}
	_pclose(pp);
	sqlite3_close(db);    


	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));



}

void clientSessionMeng::fn_groupadd(char *str)
{
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	
	//std::cout<<GroupNamestr.c_str()<<std::endl;

	std::string GroupName;
	GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string bhy;
	bhy = "";
	std::string ddt;
	ddt = ",";
	int bbaw;
	bool GroupIsTrue = false;
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		bbaw = bhy.find_last_of(ddt);
		//判斷傳來的群組是否存在  不存在的話才繼續新增使用者 OK
		if(bhy.substr(0,bbaw) == GroupNamestr.c_str())
		{
			GroupIsTrue = true;
		}
	}
	_pclose(ff);
	//

	if(GroupIsTrue == true)
	{
		std::cout<<GroupNamestr.c_str()<<"Presence of the group"<<std::endl;
	}
	else if(GroupIsTrue == false)
	{
		//std::cout<<"該群組不存在,可以新增"<<std::endl;


		///////////////////////////////////////
		std::string bstrCode;	
		bstrCode = "groupadd ";
		//groupadd //

		bstrCode += GroupNamestr.c_str();
		std::cout<<"Add a Group "<<GroupNamestr.c_str()<<std::endl;
		//groupadd names
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		_pclose(pp);



		///////

		//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok
		std::string DelNameHome;
		DelNameHome = "/PhancloudData";

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		}
		else
		{
			std::string mkdirGroup;
			mkdirGroup = "mkdir /PhancloudData";
			if( (pp = _popen(mkdirGroup.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);

		}

		DelNameHome = "/PhancloudData/Group";

		boost::filesystem::path p2(DelNameHome.c_str());
		if(exists(p2) &&is_directory(p2))
		{
		}
		else
		{
			std::string mkdirGroup;
			mkdirGroup = "mkdir /PhancloudData/Group";
			if( (pp = _popen(mkdirGroup.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);


		}


		//新增群組資料夾
		std::string MkdirstrGroupName;
		MkdirstrGroupName = "mkdir /PhancloudData/Group/";
		MkdirstrGroupName += GroupNamestr.c_str();

		if( (pp = _popen(MkdirstrGroupName.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;

			exit(1);
		}

		_pclose(pp);

		//改資料夾擁有者
		std::string ChownstrGroupName;

		ChownstrGroupName = "chown root:";
		ChownstrGroupName += GroupNamestr.c_str();
		ChownstrGroupName += " /PhancloudData/Group/";
		ChownstrGroupName += GroupNamestr.c_str();

		if( (pp = _popen(ChownstrGroupName.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;

			exit(1);
		}

		_pclose(pp);

		//改權限777
		std::string ChmodstrGroupName;

		ChmodstrGroupName = "chmod 777 /PhancloudData/Group/";
		ChmodstrGroupName += GroupNamestr.c_str();

		if( (pp = _popen(ChmodstrGroupName.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);

		}

		_pclose(pp);


		//在文件中附加字串 開通samba的功能 /etc/samba/smb.conf

		std::ofstream outf("/etc/samba/smb.conf",std::ios::app);
		outf <<std::endl; 
		outf << ";"<<GroupNamestr.c_str()<<"start" << std::endl; 

		outf << "["<<GroupNamestr.c_str()<<"]" << std::endl; 
		outf << "comment    = Temporary file space" << std::endl; 
		outf << "path       = /PhancloudData/Group/" <<GroupNamestr.c_str()<< std::endl; 
		outf << "writable   = yes" << std::endl; 
		outf << "guest ok   = yes" << std::endl; 

		outf << ";"<<GroupNamestr.c_str()<<"end" << std::endl;
		outf.close();	

		//從路徑 /PhancloudData/App 查詢軟體名稱,取得新增的群組名稱,對DB插入所有的軟體

		std::string Software_APPNAME_APPPATHNAME_str;

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open("test.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[256];	

		//bear

		//		sprintf_s(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12));");

		sprintf_s(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");

		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

		//從路徑 /PhancloudData/App 查詢軟體名稱
		//select distinct APPNAME,APPPATHNAME from sensordata ;
		//查詢不重複的APPNAME,APPPATHNAME

		sprintf_s(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		//////////
		std::string APP_Path_max;

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			//std::cout<<azResult[i]<<std::endl;

			if(strcmp(azResult[i], "APPNAME") == 0)
			{		
			}
			else if(strcmp(azResult[i], "APPPATHNAME") == 0)
			{		
			}
			else if(strcmp(azResult[i], "APPMAX") == 0)
			{		
			}
			else
			{
				Software_APPNAME_APPPATHNAME_str += azResult[i];
				//std::cout<<i<<std::endl;



				if((i+1)%3 == 0)
				{
					Software_APPNAME_APPPATHNAME_str += "\n";
				}
				else
				{

					Software_APPNAME_APPPATHNAME_str += ",";
				}

			}

		}
		//std::cout<<Software_APPNAME_APPPATHNAME_str.c_str()<<std::endl;
		///////

		/*

		std::string APPNAME;
		std::string APPPATHNAME;
		std::string APPMAX;

		vector<string> vt;
		bhja1(APPNamestr.c_str(), vt, "\n");
		for (size_t i = 0; i < vt.size(); ++ i)
		{
		APPNAME = vt[0].c_str();
		APPPATHNAME = vt[1].c_str();
		APPMAX = vt[2].c_str();		
		}
		//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
		//std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
		//std::cout<<">"<<APPMAX.c_str()<<"<"<<std::endl;
		*/
		std::vector<std::string> vt;

		C_spart(Software_APPNAME_APPPATHNAME_str, vt);
		//std::string software_Name_01="";
		//std::string software_PathName_01="";
		std::string APPNAME;
		std::string APPPATHNAME;
		std::string APPMAX;
		for (size_t i = 0; i < vt.size(); ++ i)
		{ 		
			//std::string trrq = ",";
			//	int abc = vt[i].find_last_of(trrq);
			//	software_Name_01 = vt[i].substr(0,abc);
			//	software_PathName_01 = vt[i].substr(abc+1);
			//std::cout<<vt[i].c_str()<<std::endl;

			vector<string> vt2;
			bhja1(vt[i].c_str(), vt2, ",");
			for (size_t j = 0; j < vt2.size(); ++ j)
			{

				APPNAME = vt2[0].c_str();
				APPPATHNAME = vt2[1].c_str();
				APPMAX = vt2[2].c_str();		
			}

			//			std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
			//			std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
			//			std::cout<<">"<<APPMAX.c_str()<<"<"<<std::endl;



			sprintf_s(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s', '%s' , 0 , '%s' , '%s' , 0);",GroupNamestr.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());

			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	

		}			


		sqlite3_free_table( azResult );
		sqlite3_close(db);  


	}
	else
	{
		std::cout<<"x exception error"<<std::endl;
	}


	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));


}


void clientSessionMeng::fn_groupdel(char *str)
{
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	
	std::string GroupName;
	GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string bhy;
	bhy = "";
	std::string ddt;
	ddt = ",";
	int bbaw;
	bool GroupIsTrue = false;
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		bbaw = bhy.find_last_of(ddt);
		//判斷傳來的群組是否存在  不存在的話才繼續新增使用者 OK
		if(bhy.substr(0,bbaw) == GroupNamestr.c_str())
		{
			GroupIsTrue = true;
		}
	}
	_pclose(ff);
	//

	if(GroupIsTrue == true)
	{
		//std::cout<<GroupNamestr.c_str()<<"該群組存在,可以刪除"<<std::endl;

		//////////////////////////
		//刪除群組
		std::string bstrCode;	
		bstrCode = "groupdel ";	               
		bstrCode += GroupNamestr.c_str();
		std::cout<<"Delete Group "<<GroupNamestr.c_str()<<std::endl;

		//			char buf[max_len];
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		_pclose(pp);
		//還沒作 判斷該資料夾是否存在 存在才能刪除

		//刪除群組資料夾
		{		
			///////

			std::string DelNameHome;
			DelNameHome = "/PhancloudData/Group/";
			DelNameHome += GroupNamestr.c_str();

			boost::filesystem::path p(DelNameHome.c_str());
			if(exists(p) &&is_directory(p))
			{
				//刪除資料夾
				std::string DelNameHome;
				DelNameHome = "rm -r /PhancloudData/Group/";
				DelNameHome += GroupNamestr.c_str();
				if( (pp = _popen(DelNameHome.c_str(), "r")) == NULL )
				{
					std::cout<<"_popen() error!"<<std::endl;
					exit(1);
				}
				_pclose(pp);
			}
			else
			{
				//std::cout<<"使用者"<<UserNamestr.c_str()<<"資料夾已經刪除"<<std::endl;
			}

			/////	

		}	

		//在smb.conf去掉刪除的群組名稱
		{
			int   line   =   0; 
			std::ifstream   ifs; 
			std::string   str; 
			std::string   smbstr; 
			ifs.open( "/etc/samba/smb.conf"); 
			while(getline(ifs,   str)) 
			{ 
				smbstr += str;
				smbstr += "\n";
				line++; 
			} 				

			std::string LLQ;
			LLQ = ";";
			LLQ += GroupNamestr.c_str();
			LLQ += "start";
			std::string QQW;
			QQW = ";";
			QQW += GroupNamestr.c_str();
			QQW += "end";
			int abc = smbstr.find (LLQ);	
			int kfc = smbstr.rfind (QQW);	

			std::string hh;
			hh = smbstr.substr(0,abc).c_str();
			hh += smbstr.substr(kfc + QQW.length() ).c_str();

			ifs.close();			
			std::ofstream outf("/etc/samba/smb.conf",std::ios::trunc);
			outf <<hh.c_str()<<std::endl; 
			outf.close();	
		}
		{

			sqlite3 *db=NULL;
			char *zErrMsg = 0;
			int rc;
			char *sql;
			rc = sqlite3_open("test.db", &db);   
			if( rc )
			{
				fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
				exit(1);
			}
			else {
				//printf("open code.db successfully!\n");
			}

			char aa[256];	
			sprintf_s(aa,"delete from SensorData where GROUPNAME='%s';",GroupNamestr.c_str());
			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

			sqlite3_close(db);    
		}
		//

		/////////////////////////
	}
	else if(GroupIsTrue == false)
	{
		std::cout<<"The group does not exist, can not be deleted"<<std::endl;

	}
	else
	{
		std::cout<<"x exception error"<<std::endl;
	}


	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));



}


void clientSessionMeng::fn_UserAdd(char *str)
{

	//判斷是否重複名稱 OK	
	std::string GroupName;
	GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string bhy;
	bhy = "";
	std::string ddt;
	ddt = ",";
	int bbaw;
	//
	std::string zhj = "  ";
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();
	int ssde = GroupNamestr.find_last_of(zhj);		
	//
	bool GroupIsTrue = false;
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		bbaw = bhy.find_last_of(ddt);
		//判斷選擇的群組是否存在  是的話才繼續新增使用者 OK
		if(bhy.substr(0,bbaw) == GroupNamestr.substr(0,ssde))
		{
			GroupIsTrue = true;
		}
	}
	_pclose(ff);
	//
	if(GroupIsTrue == true)
	{			
		// 判斷使用者是否存在 ok
		//////////////////////////////
		std::string bstrCode;	
		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
		char buf[max_len];
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		std::string bgq = " ";
		std::string aa;
		std::string UserNamestr;
		aa = judgment.substr(instruction.length(),judgment.length()).c_str();
		int abc = aa.find_last_of(bgq);
		UserNamestr = aa.substr(abc+1).c_str();

		std::string InstructionUserIsTrue;
		InstructionUserIsTrue = "";
		bool UserIsTrue = false;
		while(fgets(buf, sizeof(buf), pp))
		{
			InstructionUserIsTrue = buf;
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\r'),InstructionUserIsTrue.end());
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\n'),InstructionUserIsTrue.end());
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\t'),InstructionUserIsTrue.end());
			if(InstructionUserIsTrue == UserNamestr)
			{
				UserIsTrue = true;
			}
		}
		_pclose(pp);


		///

		if(UserIsTrue == true)
		{
			std::cout<<"This user"<<std::endl;
		}
		else if(UserIsTrue == false)
		{
			//	std::cout<<"沒有此使用者,可以新增"<<std::endl;

			//useradd -m -g 
			std::string useraddInstruction;	
			useraddInstruction = "useradd -m -g ";			  
			//useradd -m -g "group user"
			useraddInstruction += judgment.substr(instruction.length(),judgment.length()).c_str();
			FILE *pp;

			if( (pp = _popen(useraddInstruction.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);
			//
			//初始化密碼rootroot
			std::string bgq = " ";
			std::string UserNamestr;
			UserNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();
			int abc = UserNamestr.find_last_of(bgq);
			std::string password;
			password = "echo \"";
			password += UserNamestr.substr(abc+1).c_str();
			std::cout<<"In the group "<<GroupNamestr.substr(0,ssde).c_str()<<" Add User "<<UserNamestr.substr(abc+1).c_str() <<std::endl;
			password += ":rootroot\"| chpasswd";

			if( (pp = _popen(password.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;

				exit(1);
			}
			_pclose(pp);
			//更改777權限
			std::string chmodstr;

			chmodstr = "chmod 777 /home/";
			chmodstr += UserNamestr.substr(abc+1).c_str();

			if( (pp = _popen(chmodstr.c_str(), "r")) == NULL )
			{

				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);
			//add smbuser
			chmodstr = "";
			chmodstr = "(echo rootroot;echo rootroot)|smbpasswd -s -a  ";
			chmodstr += UserNamestr.substr(abc+1).c_str();

			if( (pp = _popen(chmodstr.c_str(), "r")) == NULL )

			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);


		}
		else
		{
			std::cout<<"x例外錯誤"<<std::endl;
		}

		/////////////////////////////

	}
	else if(GroupIsTrue == false)
	{		
		std::cout<<"The group does not exist"<<std::endl;	
	}
	else
	{
		std::cout<<"x exception error"<<std::endl;
	}		

	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));


	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

void clientSessionMeng::fn_UserDel(char *str)
{
	//判斷是否重複名稱 OK	
	std::string GroupName;
	GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string bhy;
	bhy = "";
	std::string ddt;
	ddt = ",";
	int bbaw;
	//
	std::string zhj = "  ";
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();
	int ssde = GroupNamestr.find_last_of(zhj);		
	//
	bool GroupIsTrue = false;
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		bbaw = bhy.find_last_of(ddt);
		//判斷選擇的群組是否存在  是的話才繼續新增使用者 OK
		if(bhy.substr(0,bbaw) == GroupNamestr.substr(0,ssde))
		{
			GroupIsTrue = true;
		}
	}
	_pclose(ff);
	//
	if(GroupIsTrue == true)
	{			
		// 判斷使用者是否存在 ok
		//////////////////////////////
		std::string bstrCode;	
		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
		char buf[max_len];
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		std::string bgq = " ";
		std::string aa;
		std::string UserNamestr;
		aa = judgment.substr(instruction.length(),judgment.length()).c_str();
		int abc = aa.find_last_of(bgq);
		UserNamestr = aa.substr(abc+1).c_str();

		std::string InstructionUserIsTrue;
		InstructionUserIsTrue = "";
		bool UserIsTrue = false;
		while(fgets(buf, sizeof(buf), pp))
		{
			InstructionUserIsTrue = buf;
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\r'),InstructionUserIsTrue.end());
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\n'),InstructionUserIsTrue.end());
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\t'),InstructionUserIsTrue.end());

			if(InstructionUserIsTrue == UserNamestr)
			{
				UserIsTrue = true;
			}
		}
		_pclose(pp);


		///

		if(UserIsTrue == true)
		{
			//	std::cout<<"有此使用者,可以刪除"<<std::endl;
			//std::cout<<UserNamestr.c_str()<<std::endl;

			/////////////////////////////////////////////////////////////	
			//刪除smb使用者帳戶				
			std::string chmodstr;
			chmodstr = "pdbedit -x -u ";
			chmodstr += UserNamestr.c_str();
			if( (pp = _popen(chmodstr.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);	
			//刪除使用者		
			std::string userdelInstruction;		
			userdelInstruction = "userdel -r ";
			userdelInstruction += UserNamestr.c_str();
			std::cout<<"Delete a user "<<UserNamestr.c_str()<<std::endl;
			if( (pp = _popen(userdelInstruction.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);

			//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok
			std::string DelNameHome;
			DelNameHome = "/home/";
			DelNameHome += UserNamestr.c_str();

			boost::filesystem::path p(DelNameHome.c_str());
			if(exists(p) &&is_directory(p))
			{
				//	std::cout<<"1"<<std::endl;

				//刪除資料夾
				std::string DelNameHome;
				DelNameHome = "rm -r /home/";
				DelNameHome += UserNamestr.c_str();
				if( (pp = _popen(DelNameHome.c_str(), "r")) == NULL )
				{
					std::cout<<"_popen() error!"<<std::endl;
					exit(1);
				}
				_pclose(pp);
			}
			else
			{
				//std::cout<<"使用者"<<UserNamestr.c_str()<<"資料夾已經刪除"<<std::endl;
			}



		}
		else if(UserIsTrue == false)
		{
			std::cout<<"This user"<<std::endl;
		}
		else
		{
			std::cout<<"x exception error"<<std::endl;
		}

		/////////////////////////////

	}
	else if(GroupIsTrue == false)
	{		
		std::cout<<"The group does not exist"<<std::endl;	
	}
	else
	{
		std::cout<<"x exception error"<<std::endl;
	}		

	//
	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));


	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

void clientSessionMeng::fn_gg(char *str)
{
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();

	std::string GroupName;
	GroupName = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $1 == \"";
	GroupName += GroupNamestr.c_str();
	GroupName += "\" {print $4}'";

	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string GetGroupName;
	while(fgets(hh, sizeof(hh), ff))
	{
		GetGroupName = hh;
	}
	_pclose(ff);

	GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\r'),GetGroupName.end());
	GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\n'),GetGroupName.end());
	GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\t'),GetGroupName.end());
	std::string GetGroupNameInstruction;
	if(strcmp(GetGroupName.c_str(), "") == 0)
	{
	}
	else{
		std::string GidtogroupInstruction;
		GidtogroupInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3 == ";
		GidtogroupInstruction += GetGroupName.c_str();
		GidtogroupInstruction += " {print $1}'";
		if( (ff = _popen(GidtogroupInstruction.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}

		//std::string GetGroupNameInstruction;
		while(fgets(hh, sizeof(hh), ff))
		{
			GetGroupNameInstruction = hh;
		}
		_pclose(ff);

	}
	if(strcmp(GetGroupNameInstruction.c_str(), "") == 0)
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}
	else
	{

		char br[1024];
		sprintf_s(br,"%s",GetGroupNameInstruction.c_str());
		EncodeDecode(br);
		std::string bgtt;
		bgtt = br;
		boost::asio::async_write(m_socket,
			boost::asio::buffer(bgtt),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}



}


void clientSessionMeng::fn_UserMod(char *str)
{
	std::string GroupName;
	GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
	char hh[max_len];
	FILE *ff;
	if( (ff = _popen(GroupName.c_str(), "r")) == NULL )
	{
		std::cout<<"_popen() error!"<<std::endl;
		exit(1);
	}
	std::string bhy;
	bhy = "";
	std::string ddt;
	ddt = ",";
	int bbaw;
	//
	std::string zhj = "  ";
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();
	int ssde = GroupNamestr.find_last_of(zhj);		
	//
	bool GroupIsTrue = false;
	while(fgets(hh, sizeof(hh), ff))
	{
		bhy = hh;
		bbaw = bhy.find_last_of(ddt);
		//判斷選擇的群組是否存在  是的話才繼續新增使用者 OK
		if(bhy.substr(0,bbaw) == GroupNamestr.substr(0,ssde))
		{
			GroupIsTrue = true;
		}
	}
	_pclose(ff);
	//
	if(GroupIsTrue == true)
	{			
		// 判斷使用者是否存在 ok
		//////////////////////////////
		std::string bstrCode;	
		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
		char buf[max_len];
		FILE *pp;
		if( (pp = _popen(bstrCode.c_str(), "r")) == NULL )
		{
			std::cout<<"_popen() error!"<<std::endl;
			exit(1);
		}
		std::string bgq = " ";
		std::string aa;
		std::string UserNamestr;
		aa = judgment.substr(instruction.length(),judgment.length()).c_str();
		int abc = aa.find_last_of(bgq);
		UserNamestr = aa.substr(abc+1).c_str();

		std::string InstructionUserIsTrue;
		InstructionUserIsTrue = "";
		bool UserIsTrue = false;
		while(fgets(buf, sizeof(buf), pp))
		{
			InstructionUserIsTrue = buf;

			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\r'),InstructionUserIsTrue.end());
			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\n'),InstructionUserIsTrue.end());

			InstructionUserIsTrue.erase(remove(InstructionUserIsTrue.begin(),InstructionUserIsTrue.end(),'\t'),InstructionUserIsTrue.end());
			if(InstructionUserIsTrue == UserNamestr)
			{
				UserIsTrue = true;
			}
		}
		_pclose(pp);

		if(UserIsTrue == true)
		{
			std::string useraddInstruction;	
			useraddInstruction = "usermod -g ";	
			useraddInstruction += judgment.substr(instruction.length(),judgment.length()).c_str();
			FILE *pp;

			if( (pp = _popen(useraddInstruction.c_str(), "r")) == NULL )
			{
				std::cout<<"_popen() error!"<<std::endl;
				exit(1);
			}
			_pclose(pp);

		}
		else if(UserIsTrue == false)
		{
		}
		else
		{
			std::cout<<"x exception error"<<std::endl;
		}


	}
	else if(GroupIsTrue == false)
	{		
		std::cout<<"The group does not exist"<<std::endl;	
	}
	else
	{
		std::cout<<"x exception error"<<std::endl;
	}		

	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

void clientSessionMeng::fn_ManagementAccount(char *str)
{	
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length()+1,judgment.length()).c_str();


	if(strcmp(GroupNamestr.c_str(), "") == 0)
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}
	else
	{
		std::string acobuf="";
		std::string passbuf="";
		std::string zhj = ",";
		int ssde = GroupNamestr.find_last_of(zhj);	
		acobuf = GroupNamestr.substr(0,ssde).c_str();
		passbuf = GroupNamestr.substr(ssde+1).c_str();
		//std::cout<<acobuf.c_str()<<std::endl;
		//std::cout<<passbuf.c_str()<<std::endl;


		if((strcmp(acobuf.c_str(), "admin") == 0) && (strcmp(passbuf.c_str(), "rootroot") == 0))
		{			

			char br[1024];
			sprintf_s(br,"%s","1");
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;
			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{
			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));	

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
	}


}
//0608
void clientSessionMeng::fn_ClientVerification(char *str)
{
	//std::cout<<"0"<<judgment.c_str()<<std::endl;

	double VerificationNumber = double();
	VerificationNumber = SampleNormal(1,99999999);
	char ch[64];
	for(int i=0;i<64;i++)
	{
		sprintf_s(ch,"%f",VerificationNumber);
	}

	clientSessionMeng::VerificationNumber(ch);

	EncodeDecode(ch);
	std::string bgtt;
	bgtt = ch;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));


}


void clientSessionMeng::fn_Founding(char *str)
{
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	rc = sqlite3_open("Mission.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}

	int nrow = 0, ncolumn = 0;
	//		char **azResult; //二維數組存放結果
	char aa[3000];	

	//bear5

	sprintf_s(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,TITLE VARCHAR(12),CONTENT VARCHAR(12) ,DATE VARCHAR(12),PERSONNEL INTEGER,WHETHER INTEGER ,TASKCODE VARCHAR(12),ACOBUF VARCHAR(12));");

	sql = aa;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	char str1[1000] ,str2[21000],str3[1000],str4[1000],str5[1000],str6[1000];
	char strr[16000];

	sprintf_s(strr,"%s",GroupNamestr.c_str());
	//std::cout<<strr<<std::endl;

	sscanf_s(strr,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",str1,str2,str3,str4,str5,str6);

	//std::cout<<str4<<std::endl;

	int yrr = atoi(str4);
	//int bbae = atoi(str5);
	//INSERT INTO "sensordata" VALUES( NULL ,'bb','bb','aa',0,0 );
	std::cout<<str1<<"\t"<<str2<<"\t"<<str3<<"\t"<<yrr<<"\t"<<str5<<std::endl;

	sprintf_s(aa,"INSERT INTO \"sensorsata\" VALUES( NULL ,'%s', '%s' , '%s' , %d , 0 , '%s', '%s');",str1,str2,str3,yrr,str5,str6);
	sql = aa;	
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );			


	sqlite3_close(db);  



	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));



}
void clientSessionMeng::fn_Detail(char *str)
{
	std::string APPPATHNAME_str;
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	//std::cout<<GroupNamestr.c_str()<<std::endl;

	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("Mission.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n","");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[16000];	

	sprintf_s(aa,"SELECT * FROM sensorsata;","");

	sql = aa;	

	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int dr=0;
	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	

		if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
		{		
		}
		else
		{

			APPPATHNAME_str += azResult[i];	

			if(dr == 7)
			{
				dr = 0;
				APPPATHNAME_str += "+Wrap+";			}
			else
			{
				APPPATHNAME_str += ",";	
				dr++;


			}
		}

	}
	//std::cout<<APPPATHNAME_str.c_str()<<","<<ncolumn<<","<<nrow<<std::endl;

	sqlite3_free_table( azResult );
	sqlite3_close(db);    



	if(strcmp(APPPATHNAME_str.c_str(), "") == 0)
	{			

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));



	}
	else
	{


		char br[16000];
		sprintf_s(br,"%s",APPPATHNAME_str.c_str());
		EncodeDecode(br);
		std::string bgtt;
		bgtt = br;

		boost::asio::async_write(m_socket,
			boost::asio::buffer(bgtt),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}







}
void clientSessionMeng::fn_MissionList(char *str)
{
	boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));


	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));
}




void clientSessionMeng::fn_Deposit(char *str)
{
	std::string APPPATHNAME_str;
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	
	//std::cout<<GroupNamestr.c_str()<<std::endl;


	if(strcmp(GroupNamestr.c_str(), "") == 0)
	{			

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));



	}
	else
	{


		std::string acobuf="";
		std::string passbuf="";
		std::string zhj = ",";
		int ssde = GroupNamestr.find_last_of(zhj);	
		acobuf = GroupNamestr.substr(0,ssde).c_str();
		passbuf = GroupNamestr.substr(ssde+1).c_str();
		//std::cout<<acobuf.c_str()<<std::endl;
		//std::cout<<passbuf.c_str()<<std::endl;
		////////////////////////////////////////////////

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql ;
		rc = sqlite3_open("Account.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[16000];	

		//sprintf_s(aa,"SELECT * FROM sensorsata;","");

		//std::cout<<acobuf.c_str()<<std::endl;
		//std::cout<<passbuf.c_str()<<std::endl;

		sprintf_s(aa,"select ACOBUF from sensorsata where ACOBUF = \"%s\" and PASSBUF = \"%s\";",acobuf.c_str(),passbuf.c_str());

		sql = aa;	

		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		int dr=0;
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
			{		
			}
			else
			{

				APPPATHNAME_str += azResult[i];	


			}

		}

		//std::cout<<APPPATHNAME_str.c_str()<<","<<nrow<<","<<ncolumn<<std::endl;

		sqlite3_free_table( azResult );
		sqlite3_close(db);   



		if(strcmp(APPPATHNAME_str.c_str(), "") == 0)
		{		

			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));	

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{


			char br[16000];
			sprintf_s(br,"%s","1");
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;
			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));

		}
	}
}



void clientSessionMeng::fn_NewAccount(char *str)

{
	std::string APPPATHNAME_str;
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	if(strcmp(GroupNamestr.c_str(), "") == 0)
	{			

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));



	}
	else
	{


		std::string acobuf="";
		std::string passbuf="";
		std::string zhj = ",";
		int ssde = GroupNamestr.find_last_of(zhj);	
		acobuf = GroupNamestr.substr(0,ssde).c_str();
		passbuf = GroupNamestr.substr(ssde+1).c_str();
		//std::cout<<acobuf.c_str()<<std::endl;
		//std::cout<<passbuf.c_str()<<std::endl;

		////////////////////////////////////

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open("Account.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		//		char **azResult; //二維數組存放結果
		char aa[16000];	

		//bear5

		sprintf_s(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,ACOBUF VARCHAR(12),PASSBUF VARCHAR(12) ,RECEIVINGTASK VARCHAR(12),TASKCODE VARCHAR(12));");

		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );


		//delete from sensordata where CODE='bb';

		sprintf_s(aa,"delete from sensorsata where ACOBUF='%s' and PASSBUF='%s';",acobuf.c_str(),passbuf.c_str());
		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	


		sprintf_s(aa,"INSERT INTO \"sensorsata\" VALUES( NULL ,'%s', '%s' , '' , '');",acobuf.c_str(),passbuf.c_str());
		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );			


		sqlite3_close(db);  

		//////////////////////////////////

		if((strcmp(acobuf.c_str(), "") == 0) || (strcmp(passbuf.c_str(), "") == 0))
		{			
			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));	

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{

			char br[16000];
			sprintf_s(br,"%s","1");
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;
			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
	}
}


void clientSessionMeng::fn_Receivingtask(char *str)
{
	std::string APPPATHNAME_str;
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	if(strcmp(GroupNamestr.c_str(), "") == 0)
	{			

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));



	}
	else
	{


		std::string acobuf="";
		std::string passbuf="";
		std::string zhj = ",";
		int ssde = GroupNamestr.find_last_of(zhj);	
		acobuf = GroupNamestr.substr(0,ssde).c_str();
		passbuf = GroupNamestr.substr(ssde+1).c_str();
		//std::cout<<acobuf.c_str()<<std::endl;
		//std::cout<<passbuf.c_str()<<std::endl;
		//std::string taskcodestr;
		//taskcodestr = acobuf.c_str();
		//taskcodestr += "+dr+";
		//taskcodestr += passbuf.c_str();
		////////////////////////////////////

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open("Account.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[16000];	
		//////////////////////////////



		sprintf_s(aa,"select RECEIVINGTASK from sensorsata where ACOBUF = \"%s\";",passbuf.c_str());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
			{		
			}
			else
			{
				APPPATHNAME_str += azResult[i];										
			}

		}
		std::cout<<APPPATHNAME_str.c_str()<<std::endl;

		sqlite3_free_table( azResult );

		std::string addtaskcodestr = "";
		addtaskcodestr += APPPATHNAME_str.c_str();
		addtaskcodestr += ",";
		addtaskcodestr += acobuf.c_str();
		//pupu+dr+19:24:39@p@pupu+dr+19:24:39@p@pupu+dr+19:24:39
		//////////////////////////////
		sprintf_s(aa,"update sensorsata set RECEIVINGTASK = \"%s\" where ACOBUF = \"%s\" ;",addtaskcodestr.c_str(),passbuf.c_str());
		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );


		sqlite3_close(db);  


		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));

	}
}




void clientSessionMeng::fn_Entrust(char *str)
{
	std::string APPPATHNAME_str;
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	//std::cout<<GroupNamestr.c_str()<<std::endl;


	if(strcmp(GroupNamestr.c_str(), "") == 0)
	{			

		boost::asio::async_write(m_socket,
			boost::asio::buffer(""),
			boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
			boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
			boost::asio::placeholders::error));



	}
	else
	{



		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open("Account.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[16000];	
		//////////////////////////////



		sprintf_s(aa,"select RECEIVINGTASK from sensorsata where ACOBUF = \"%s\";",GroupNamestr.c_str());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
			{		
			}
			else
			{
				APPPATHNAME_str += azResult[i];										
			}

		}
		//std::cout<<APPPATHNAME_str.c_str()<<std::endl;

		sqlite3_free_table( azResult );

		sqlite3_close(db);  

		/////////////////////////////////////////
		/*

		rc = sqlite3_open("Mission.db", &db);   
		if( rc )
		{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		//sprintf_s(aa,"select * from sensorsata where ACOBUF = \"%s\" and TASKCODE = \"%s\";","gg2","09:08:42");
		sprintf_s(aa,"SELECT * FROM sensorsata;","");
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		int dr = 0;
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
		if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
		{		
		}
		else
		{

		APPPATHNAME_str += azResult[i];	

		if(dr == 7)
		{
		dr = 0;
		APPPATHNAME_str += "+Wrap+";			
		}
		else
		{
		APPPATHNAME_str += ",";	
		dr++;


		}
		}

		}
		//std::cout<<APPPATHNAME_str.c_str()<<","<<ncolumn<<","<<nrow<<std::endl;

		sqlite3_free_table( azResult );
		sqlite3_close(db);    

		*/

		//////////////////////////////////////////

		if(strcmp(APPPATHNAME_str.c_str(), "") == 0)
		{			

			boost::asio::async_write(m_socket,
				boost::asio::buffer(""),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));	

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));



		}
		else
		{


			char br[16000];
			sprintf_s(br,"%s",APPPATHNAME_str.c_str());
			EncodeDecode(br);
			std::string bgtt;
			bgtt = br;

			boost::asio::async_write(m_socket,
				boost::asio::buffer(bgtt),
				boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
				boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}

		/*
		boost::asio::async_write(m_socket,
		boost::asio::buffer(""),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));	

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

		}
		*/
	}
}
//0817



void clientSessionMeng::fn_GetAppUse(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	//std::cout<<GroupNamestr.c_str()<<std::endl;


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n","");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[16000];	

	//		sprintf_s(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
	sprintf_s(aa,"select APPUSE from sensordata where  APPNAME = \"%s\";",GroupNamestr.c_str());
	sql = aa;
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	
		//std::cout<<azResult[i]<<std::endl;
		if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
		{		
		}
		else
		{

			APPPATHNAME_str = azResult[i];		

		}

	}

	sqlite3_free_table( azResult );
	sqlite3_close(db);   



	char br[16000];
	sprintf_s(br,"%s",APPPATHNAME_str.c_str());
	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}
void clientSessionMeng::fn_GetAppMax(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	//std::cout<<GroupNamestr.c_str()<<std::endl;


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("test.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n","");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[16000];	

	//		sprintf_s(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
	sprintf_s(aa,"select APPMAX from sensordata where  APPNAME = \"%s\";",GroupNamestr.c_str());
	sql = aa;
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	
		//std::cout<<azResult[i]<<std::endl;
		if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
		{		
		}
		else
		{

			APPPATHNAME_str = azResult[i];		

		}

	}

	sqlite3_free_table( azResult );
	sqlite3_close(db);   



	char br[16000];
	sprintf_s(br,"%s",APPPATHNAME_str.c_str());
	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

void clientSessionMeng::fn_OffsetCoordinates(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	std::cout<<GroupNamestr.c_str()<<std::endl;


	std::string APPNAME;
	APPNAME = "S";

	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql ;
	rc = sqlite3_open("cc.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n","");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[16000];	

	sprintf_s(aa,"select APPUSE from sensordata where  APPNAME = \"%s\";",APPNAME.c_str());
	sql = aa;
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	

		if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 )
		{		
		}
		else
		{

			APPPATHNAME_str += azResult[i];										
		}

	}

	sqlite3_free_table( azResult );
	sqlite3_close(db);   


	char br[16000];
	sprintf_s(br,"%s",APPPATHNAME_str.c_str());
	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

	
void clientSessionMeng::fn_DiceUpdate(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	char **azResult; //二維數組存放結果

	rc = sqlite3_open("dice.db", &db);   
	if( rc )
	{
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
	}
	else {
	//printf("open code.db successfully!\n");
	}

	int nrow = 0, ncolumn = 0;
	char ch1[16000];	

	sprintf_s(ch1,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,ROLENAME VARCHAR(12),DICEREASONS VARCHAR(12) ,QUANTITY VARCHAR(12),DICEFACE VARCHAR(12),ADJUSTEDVALUE VARCHAR(12));");
	sql = ch1;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );


	sprintf_s(ch1,"select * from SensorData;");
	sql = ch1;	

	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int bh=0;	
	dicedate ch;
	std::vector<dicedate> chnumbers; 
	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{
		if(i>6)
		{
			if(i!=atoi(azResult[i])*6)
			{
				bh++;
			//	std::cout<<bh<<":\t"<<azResult[i]<<"\t";		
				sprintf_s(ch.Role_Name,"%s",azResult[i-4]);
				sprintf_s(ch.Dice_reasons,"%s",azResult[i-3]);	
				sprintf_s(ch.Quantity,"%s",azResult[i-2]);	
				sprintf_s(ch.Dice_face,"%s",azResult[i-1]);	
				sprintf_s(ch.Adjusted_value,"%s",azResult[i]);	
			}
			if(bh==5)
			{
				bh=0;
				chnumbers.push_back(ch);
			}
		}
	}
	//cout<<ch.Role_Name<<" "<<ch.Dice_reasons<<" "<<ch.Quantity<<" "<<ch.Dice_face<<" "<<ch.Adjusted_value<<endl;
	sqlite3_free_table( azResult );
	sqlite3_close(db);    
	
	char br[16000];
	int ck = 0;
	ck = chnumbers.size();
	dicedate ch2;
	std::string str1;
	for(int i=0;i<ck;i++)
	{		
		ch2 = chnumbers[i];
		str1 += ch2.Role_Name;
		str1 += ",";
		str1 += ch2.Dice_reasons;
		str1 += ",";
		str1 += ch2.Quantity;
		str1 += ",";
		str1 += ch2.Dice_face;
		str1 += ",";
		str1 += ch2.Adjusted_value;
		str1 += "\n";
		//sprintf_s(br,"%s,%s,%s,%s,%s",ch2.Role_Name,ch2.Dice_reasons,ch2.Quantity,ch2.Dice_face,ch2.Adjusted_value);	
		sprintf_s(br,"%s",str1.c_str());
	}

	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,

		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}
void clientSessionMeng::fn_AppLogout(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	

	std::cout<<GroupNamestr.c_str()<<std::endl;

	std::string GROUPNAME;
	std::string APPNAME;
	std::string APPPATHNAME;
	std::string USERIP;
	std::string USERNAME;
	std::string LOGINTIME;

	vector<string> vt;
	bhja1(GroupNamestr.c_str(), vt, ",");
	for (size_t i = 0; i < vt.size(); ++ i)
	{
		GROUPNAME = vt[0].c_str();
		APPNAME = vt[1].c_str();
		APPPATHNAME = vt[2].c_str();	
		USERIP = vt[3].c_str();
		USERNAME = vt[4].c_str();
		LOGINTIME = vt[5].c_str();		
	}
	//std::cout<<">"<<GROUPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<USERIP.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<USERNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<LOGINTIME.c_str()<<"<"<<std::endl;


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	rc = sqlite3_open("login.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		//printf("open code.db successfully!\n");
	}

	char aa[16000];	
	sprintf_s(aa,"delete from SensorData where APPPATHNAME='%s' AND USERIP ='%s' AND USERNAME ='%s' ;",APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str());
	sql = aa;	
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	//sqlite3_close(db);    

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果

	std::string Appstr;
	sprintf_s(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
	sql = aa;	
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	
		if(strcmp(azResult[i], "APPPATHNAME") == 0)
		{		
		}
		else if(strcmp(azResult[i], "USERIP") == 0)
		{		
		}
		else if(strcmp(azResult[i], "USERNAME") == 0)
		{		
		}
		else
		{
			Appstr += azResult[i];

			if((i+1)%3 == 0)
			{
				Appstr += "\n";

			}
			else
			{
				Appstr += ",";
			}

		}

	}
	//std::cout<<Appstr.c_str()<<std::endl;

	sqlite3_free_table( azResult );



	std::vector<std::string> vt5;
	C_spart(Appstr, vt5);
	std::vector<std::string> arrnumber;

	std::string arrnumber_str;
	int CheckDistinct = 0;
	for (size_t i = 0; i < vt5.size(); ++ i)
	{ 				

		std::vector<string> vt2;
		bhja1(vt5[i].c_str(), vt2, ",");
		for (size_t j = 0; j < vt2.size(); ++ j)
		{
			arrnumber_str = vt2[0].c_str();


			if(strcmp(vt2[0].c_str(), APPPATHNAME.c_str()) == 0 && strcmp(vt2[1].c_str(), USERIP.c_str()) == 0 && strcmp(vt2[2].c_str(), USERNAME.c_str()) == 0 )
				CheckDistinct = 1;
		}	
		arrnumber.push_back(arrnumber_str.c_str());	

	}	


	if(CheckDistinct == 0)
	{			

	}
	sqlite3_close(db);  
	//////////





	char br[16000];







	std::string allpath;
	{		
		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;

		rc = sqlite3_open("test.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[16000];	

		sprintf_s(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");

		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], "APPPATHNAME") == 0)
			{		
			}
			else if(strcmp(azResult[i], "APPMAX") == 0)

			{		
			}
			else
			{
				allpath += azResult[i];


				if((i+1)%2 == 0)
				{
					allpath += "\n";

				}
				else
				{
					allpath += ",";
				}

			}
		}
		//std::cout<<allpath.c_str()<<std::endl;
		sqlite3_free_table( azResult );


		vector<string> vt4;
		bhja1(allpath.c_str(), vt4, "\n");
		for (size_t i = 0; i < vt4.size(); ++ i)
		{

			vector<string> vt6;
			bhja1(vt4[i].c_str(), vt6, ",");
			int bb=0;
			int cc=0;

			for (size_t j = 0; j < vt6.size(); ++ j)
			{
				//std::cout<<vt6[j].c_str()<<std::endl;
				cc = atoi(vt6[1].c_str());

				int ccnumber = arrnumber.size();
				for(int k=0;k<	ccnumber ;k++)
				{
					if(strcmp(arrnumber[k].c_str(), vt6[0].c_str()) == 0)			
						bb = bb + 1;		
				}

				//std::cout<<bb<<","<<cc<<","<<arrnumber.size()<<std::endl;

				if(j == 0)
				{

					char dde[64];
					sprintf_s(dde,"%d",bb);
					//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;
					std::string checkOK;


					//std::cout<<"aaaaa=\t"<<APPPATHNAME.c_str()<<"\t"<<vt6[j].c_str()<<std::endl;
					if(strcmp(APPPATHNAME.c_str(), vt6[j].c_str()) == 0)	
					{
						//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;


						if(bb <= cc) //99 <= 99 可執行
						{							
							//std::cout<<"gg========"<<APPPATHNAME.c_str()<<std::endl;
							sprintf_s(aa,"update sensordata set APPUSE = \"%s\" where APPPATHNAME = \"%s\";",dde,vt6[j].c_str());

							sql = aa;
							sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
							checkOK = "OK";
							sprintf_s(br,"%s",checkOK.c_str());

						}
						else
						{
							checkOK = "NO";	
							sprintf_s(br,"%s",checkOK.c_str());			

						}

					}



				}
				bb=0;
			}					
		}

		sqlite3_close(db);  	

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	sprintf_s(br,"%s","OK");	


	//std::cout<<br<<std::endl;


	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,

		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}
void clientSessionMeng::fn_Approve(char *str)
{

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	
	std::cout<<GroupNamestr.c_str()<<std::endl;

	std::string GROUPNAME;
	std::string APPNAME;
	std::string APPPATHNAME;
	std::string USERIP;
	std::string USERNAME;
	std::string LOGINTIME;

	vector<string> vt;
	bhja1(GroupNamestr.c_str(), vt, ",");
	for (size_t i = 0; i < vt.size(); ++ i)
	{
		GROUPNAME = vt[0].c_str();
		APPNAME = vt[1].c_str();
		APPPATHNAME = vt[2].c_str();	
		USERIP = vt[3].c_str();
		USERNAME = vt[4].c_str();
		LOGINTIME = vt[5].c_str();		
	}
	//std::cout<<">"<<GROUPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<USERIP.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<USERNAME.c_str()<<"<"<<std::endl;
	//std::cout<<">"<<LOGINTIME.c_str()<<"<"<<std::endl;


	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;


	rc = sqlite3_open("login.db", &db);   
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	else {
		//printf("open code.db successfully!\n");
	}

	int nrow = 0, ncolumn = 0;
	char **azResult; //二維數組存放結果
	char aa[16000];	


	sprintf_s(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPPATHNAME VARCHAR(12),USERIP VARCHAR(12),USERNAME VARCHAR(12),LOGINTIME VARCHAR(12));");
	sql = aa;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	sprintf_s(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s','%s','%s','%s','%s','%s');",GROUPNAME.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str(),LOGINTIME.c_str());

	sql = aa;	
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	




	std::string Appstr;
	sprintf_s(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
	sql = aa;	
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{	
		if(strcmp(azResult[i], "APPPATHNAME") == 0)
		{		
		}
		else if(strcmp(azResult[i], "USERIP") == 0)
		{		
		}
		else if(strcmp(azResult[i], "USERNAME") == 0)
		{		
		}
		else
		{
			Appstr += azResult[i];

			if((i+1)%3 == 0)
			{
				Appstr += "\n";
			}
			else
			{
				Appstr += ",";
			}
		}

	}

	sqlite3_free_table( azResult );

	std::vector<std::string> vt5;
	C_spart(Appstr, vt5);
	std::vector<std::string> arrnumber;
	std::string arrnumber_str;
	int CheckDistinct = 0;
	for (size_t i = 0; i < vt5.size(); ++ i)
	{ 				
		std::vector<string> vt2;
		bhja1(vt5[i].c_str(), vt2, ",");
		for (size_t j = 0; j < vt2.size(); ++ j)
		{
			arrnumber_str = vt2[0].c_str();

			if(strcmp(vt2[0].c_str(), APPPATHNAME.c_str()) == 0 && strcmp(vt2[1].c_str(), USERIP.c_str()) == 0 && strcmp(vt2[2].c_str(), USERNAME.c_str()) == 0 )
				CheckDistinct = 1;
		}	
		arrnumber.push_back(arrnumber_str.c_str());	

	}	

	//std::cout<<">>>>>>>>"<<Appstr.c_str()<<std::endl;
	//	std::cout<<CheckDistinct<<std::endl;

	if(CheckDistinct == 0)
	{			

	}
	sqlite3_close(db);  
	//////////





	char br[16000];







	std::string allpath;
	{		
		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;

		rc = sqlite3_open("test.db", &db);   
		if( rc )
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			exit(1);
		}
		else {
			//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二維數組存放結果
		char aa[16000];	

		sprintf_s(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			if(strcmp(azResult[i], "APPPATHNAME") == 0)
			{		
			}
			else if(strcmp(azResult[i], "APPMAX") == 0)
			{		
			}
			else
			{
				allpath += azResult[i];

				if((i+1)%2 == 0)
				{
					allpath += "\n";
				}
				else
				{
					allpath += ",";
				}
			}
		}
		//std::cout<<allpath.c_str()<<std::endl;
		sqlite3_free_table( azResult );

		vector<string> vt4;
		bhja1(allpath.c_str(), vt4, "\n");
		for (size_t i = 0; i < vt4.size(); ++ i)
		{
			vector<string> vt6;
			bhja1(vt4[i].c_str(), vt6, ",");
			int bb=0;
			int cc=0;
			for (size_t j = 0; j < vt6.size(); ++ j)
			{
				//std::cout<<vt6[j].c_str()<<std::endl;
				cc = atoi(vt6[1].c_str());

				int ccnumber = arrnumber.size();
				for(int k=0;k<	ccnumber ;k++)
				{
					if(strcmp(arrnumber[k].c_str(), vt6[0].c_str()) == 0)			
						bb = bb + 1;		
				}
				//std::cout<<bb<<","<<cc<<","<<arrnumber.size()<<std::endl;

				if(j == 0)
				{
					char dde[64];
					sprintf_s(dde,"%d",bb);
					//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;
					std::string checkOK;

					//std::cout<<"aaaaa=\t"<<APPPATHNAME.c_str()<<"\t"<<vt6[j].c_str()<<std::endl;
					if(strcmp(APPPATHNAME.c_str(), vt6[j].c_str()) == 0)	
					{
						//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;

						if(bb <= cc) //99 <= 99 可執行
						{							
							//std::cout<<"gg========"<<APPPATHNAME.c_str()<<std::endl;
							sprintf_s(aa,"update sensordata set APPUSE = \"%s\" where APPPATHNAME = \"%s\";",dde,vt6[j].c_str());
							sql = aa;
							sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
							checkOK = "OK";
							sprintf_s(br,"%s",checkOK.c_str());
						}
						else
						{
							checkOK = "NO";	
							sprintf_s(br,"%s",checkOK.c_str());			
						}

					}


				}
				bb=0;
			}					
		}
		sqlite3_close(db);  	

	}


	//std::cout<<br<<std::endl;


	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}

void clientSessionMeng::fn_Connection(char *str)
{
	Sleep(1000);
	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	



	///////////////////////////////////
	
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;


	rc = sqlite3_open("dice.db", &db);   
	if( rc )
	{
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
	}

	else {
	//printf("open code.db successfully!\n");
	}

	int nrow = 0, ncolumn = 0;
	char ch1[16000];	

	sprintf_s(ch1,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,ROLENAME VARCHAR(12),DICEREASONS VARCHAR(12) ,QUANTITY VARCHAR(12),DICEFACE VARCHAR(12),ADJUSTEDVALUE VARCHAR(12));");
	sql = ch1;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );


	//sqlite3_close(db);  
	//////////

	/////////////////////////////

	/*
	sprintf_s(aa,"select * from SensorData;");
	sql = aa;	

	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int bh=0;
	for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{
	std::cout<<azResult[i]<<std::endl;
	}
	sqlite3_free_table( azResult );
	sqlite3_close(db);    
	*/
	char br[16000];

	std::cout<<GroupNamestr<<std::endl;

	char   szText[30000]="3"; 
	char   szText2[30000]="6"; 
	char   szText3[30000]="8"; 
	char   szText4[30000]="8"; 
	char   szText5[30000]="8"; 

	std::vector<std::string> vt5;
	C_spart(GroupNamestr, vt5);
	for (size_t i = 0; i < vt5.size(); ++ i)
	{ 				
		std::vector<string> vt2;
		bhja1(vt5[i].c_str(), vt2, ",");
		for (size_t j = 0; j < vt2.size(); ++ j)
		{
		//	cout<<vt2[j].c_str()<<endl;
			sprintf_s(szText,"%s",vt2[0].c_str());
			sprintf_s(szText2,"%s",vt2[1].c_str());
			sprintf_s(szText3,"%s",vt2[2].c_str());
			sprintf_s(szText4,"%s",vt2[3].c_str());
			sprintf_s(szText5,"%s",vt2[4].c_str());
				
		}									
	}	
	
	sprintf_s(ch1,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s','%s','%s','%s','%s');",szText,szText2,szText3,szText4,szText5);

	sql = ch1;	
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
		
	sqlite3_close(db);  

	//cout<<szText<<" "<<szText2<<" "<<szText3<<" "<<szText4<<" "<<szText5<<endl;
	typedef boost::minstd_rand base_generator_type;

	int a,b,c;
	a = atoi(szText3);
	b = atoi(szText4);
	c = atoi(szText5);
	//	c = a + b;
	//	char ch1[256];
	//sprintf_s(ch1,"%d",c);
	std::string sbuf = "";
	//				MessageBoxA(NULL, ch1 ,"Error" , MB_OK);

	base_generator_type generator(42);
	generator.seed(static_cast<unsigned int>(std::time(0)));
	base_generator_type saved_generator = generator;
	typedef boost::uniform_int<> distribution_type;
	typedef boost::variate_generator<base_generator_type&, distribution_type> gen_type;
	int face=b;
	gen_type die_gen(generator, distribution_type(1, face));

	// If you want to use an STL iterator interface, use iterator_adaptors.hpp.
	boost::generator_iterator<gen_type> die(&die_gen);
	int cc=0;
	int sum=0;
	int teeth=a;
	int Adjusted=c;
	int Additional=0;
	char chbuf[10];
	std::vector<int> numbers; 

	for(int i = 0; i < teeth+1; i++)
	{
		numbers.push_back(*die++); 
	}
	numbers.erase(numbers.begin());
	sbuf += szText;
	sbuf += " 的「";
	sbuf += szText2;
	sbuf += "」 擲了「" ;	
	_itoa_s(teeth,chbuf,10); 
	sbuf += chbuf;
	sbuf +=  " d " ;				
	_itoa_s(face,chbuf,10); 
	sbuf +=  chbuf;
	sbuf += " + ";	
	_itoa_s(Adjusted,chbuf,10); 
	sbuf += chbuf;
	sbuf += "」 ，擲出「";
	printf("\n%s 的「%s」 擲了「%d d %d + %d」 ，擲出「",szText,szText2,teeth,face,Adjusted);

	int sizz = numbers.size();
	for(int i=0;i<sizz;i++)
	{
		if(i == sizz-1)
		{
			_itoa_s(numbers[i],chbuf,10); 
			sbuf += chbuf;
			std::cout <<numbers[i];
			sum = sum + numbers[i];
			if(numbers[i] == 6)
				Additional++;
		}
		else
		{
			_itoa_s(numbers[i],chbuf,10); 
			sbuf += chbuf;
			sbuf += "、";
			std::cout <<numbers[i]<<"、";
			sum = sum + numbers[i];

			if(numbers[i] == 6)
				Additional++;
		}

	}


	boost::generator_iterator<gen_type> die2(&die_gen);
	if(Additional>0)
	{
		sbuf += "追加1d6 ";
		_itoa_s(Additional,chbuf,10); 
		sbuf += chbuf;
		sbuf += "次:";
		printf("追加1d6 %d次:",Additional);
	}

	int sum2=0;
	int aa=0;

	int Additional2=0;//0304
	boost::generator_iterator<gen_type> die3(&die_gen);// 0304

	int n = 1;
	for(int i=0;i<Additional;i++)
	{	
		aa = *die2++;
		sum2 = sum2 + aa;
		_itoa_s(aa,chbuf,10); 
		sbuf += chbuf ;
		sbuf += " ";
		std::cout<<aa<<" ";

	}
	sbuf += "」，總合為「";
	int csum=0;
	csum =  sum + Adjusted + sum2;				
	_itoa_s(csum,chbuf,10); 
	sbuf += chbuf;
	sbuf += "」。";
	printf("」，總合為「%d」。\n",sum + Adjusted + sum2);

	sbuf += "";
	std::cout << '\n';


	//std::cout << sbuf.c_str()<<std::endl;
	sprintf_s(br,"%s",sbuf.c_str());
	///////////////////////////
	EncodeDecode(br);
	std::string bgtt;
	bgtt = br;












	///////////////////////////////////////
	boost::asio::async_write(m_socket,
		boost::asio::buffer(bgtt),
		boost::bind(&clientSessionMeng::handle_write,shared_from_this(),
		boost::asio::placeholders::error));

	m_socket.async_read_some(boost::asio::buffer(data_,max_len),
		boost::bind(&clientSessionMeng::handle_read,shared_from_this(),
		boost::asio::placeholders::error));

}



void clientSessionMeng::EncodeDecode(char *str)
{
	char ch;
	int len, i;
	if ((len=strlen(str))<=0) return;
	for (i=0; i<len; i++)
	{
		switch(i%4)
		{
		case 0: case 3:
			str[i]=str[i]^0xDB;
			break;
		default:
			str[i]=str[i]^0xBD;
			break;
		}
	}

	for (i=0; i+3<len; i+=4)
	{
		ch=str[i];
		str[i]=str[i+3];
		str[i+3]=ch;
		ch=str[i+1];
		str[i+1]=str[i+2];
		str[i+2]=ch;
	}
}

int clientSessionMeng::C_spart(const std::string& str, std::vector<std::string>& ret_)
{
	std::string sep;
	sep = "\n";
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

int clientSessionMeng::bhja1(const string& str, vector<string>& ret_, string sep)
{
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

double clientSessionMeng::SampleNormal (double mean, double sigma)
{
	using namespace boost;
	static mt19937 rng(static_cast<unsigned> (std::time(0)));	
	normal_distribution<double> norm_dist(mean,sigma);	
	variate_generator<mt19937&, normal_distribution<double> >  normal_sampler(rng,norm_dist);	
	return normal_sampler();
}
