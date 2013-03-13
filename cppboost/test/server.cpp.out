#include "AddShell.h"

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
#include <ctime>

using boost::asio::ip::tcp;


using namespace std;

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

sleep(0.1);
clientSessionMeng::VerificationIsTrue = true;
/*
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
*/
		if(VerificationIsTrue == true)
		{
			instruction = z00000000();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000001()) == 0)	
				fn_update(data_);
	
			instruction = z00000002();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000003()) == 0)
				fn_GroupList(data_);

			instruction = z00000004();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000005()) == 0)
				fn_UserList(data_);	

			instruction = z00000006();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000007()) == 0)
				fn_GetSoftwareName(data_);

			instruction = z00000008();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000009()) == 0)
				fn_GetSoftwarePathName(data_);

			instruction = z00000010();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000011()) == 0)
				fn_SoftwareTick(data_);

			instruction = z00000012();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000013()) == 0)
				fn_APPDel(data_);

			instruction = z00000014();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000015()) == 0)
				fn_APPAdd(data_);

			instruction = z00000016();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000017()) == 0)
				fn_groupadd(data_);

			instruction = z00000018();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000019()) == 0)
				fn_groupdel(data_);

			instruction = z00000020();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000021()) == 0)
				fn_UserAdd(data_);

			instruction = z00000022();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000023()) == 0)
				fn_UserDel(data_);

			instruction = z00000024();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000025()) == 0)
				fn_gg(data_);

			instruction = z00000026();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000027()) == 0)
				fn_UserMod(data_);

			instruction = z00000028();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000029()) == 0)
				fn_ManagementAccount(data_);

			instruction = z00000030();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000031()) == 0)
				fn_Founding(data_);
			
			instruction = z00000032();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000033()) == 0)
				fn_Detail(data_);
			
			instruction = z00000034();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000035()) == 0)
				fn_MissionList(data_);

			instruction = z00000036();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000037()) == 0)
				fn_Deposit(data_);

			instruction = z00000038();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000039()) == 0)
				fn_NewAccount(data_);


			instruction = z00000040();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000041()) == 0)
				fn_Entrust(data_);

			instruction = z00000042();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000043()) == 0)
				fn_Receivingtask(data_);


			instruction = z00000044();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000045()) == 0)
				fn_Connection(data_);

			instruction = z00000046();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000047()) == 0)
				fn_OffsetCoordinates(data_);

			instruction = z00000048();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000049()) == 0)
				fn_GetAppMax(data_);

			instruction = z00000050();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000051()) == 0)
				fn_GetAppUse(data_);

			instruction = z00000052();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000053()) == 0)
				fn_Approve(data_);

			instruction = z00000054();
			judgment = data_;
			if(strcmp(judgment.substr(0,instruction.length()).c_str(), z00000055()) == 0)
				fn_AppLogout(data_);



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

	if(strcmp(str, z00000056()) == 0)
	{
		std::string strInstruction;
		strInstruction = z00000057();		
	
		FILE *pp;
		if( (pp = popen(strInstruction.c_str(), z00000058())) == NULL )
		{
		std::cout<<z00000059()<<std::endl;
		exit(1);
		}
		pclose(pp);

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
	if(strcmp(str, z00000060()) == 0)
	{
		std::string strInstruction;
		strInstruction = z00000061();
			
		char buf[max_len];
		FILE *pp;
		if( (pp = popen(strInstruction.c_str(), z00000062())) == NULL )
		{
		std::cout<<z00000063()<<std::endl;
		exit(1);
		}
		std::string strbh;
		strbh = "";
		while(fgets(buf, sizeof(buf), pp))
		{
		strbh += buf;
		}
		pclose(pp);
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
	sprintf(br,z00000064(),strbh.c_str());
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
		GroupName = z00000065();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000066())) == NULL )
		{
		std::cout<<z00000067()<<std::endl;
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
		pclose(ff);


		//

		if(GroupIsTrue == true)
		{
		
			std::string bstrCode;	
			bstrCode = z00000068();	              
			bstrCode += judgment.substr(instruction.length(),judgment.length()).c_str();
			bstrCode += z00000069();


			char buf[max_len];
			FILE *pp;
			if( (pp = popen(bstrCode.c_str(), z00000070())) == NULL )
			{
			std::cout<<z00000071()<<std::endl;
			exit(1);
			}
			std::string strbh;
			strbh = "";
			while(fgets(buf, sizeof(buf), pp))
			{
			strbh += buf;
			}
			pclose(pp);

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
	sprintf(br,z00000072(),strbh.c_str());
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
		rc = sqlite3_open(z00000073(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000074(), sqlite3_errmsg(db));
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
		char **azResult; //二维数组存放结果
		char aa[256];	
		sprintf(aa,z00000075(),GroupNamestr.c_str());
		sql = aa;	

		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		int bh=0;
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{
			if(strcmp(azResult[i], z00000076()) == 0 || strcmp(azResult[i], z00000077()) == 0 || strcmp(azResult[i], z00000078()) == 0)
			{		
			}
			else
			{
			bh++;
				Software_APPNAME_APPON_str += azResult[i];

				if(bh==1)
				{
					Software_APPNAME_APPON_str += z00000079();
				}
				if(bh==2)
				{
					Software_APPNAME_APPON_str += z00000080();
				}
				if(bh == 3)
				{
				Software_APPNAME_APPON_str += z00000081();
				Software_APPNAME_APPON_str += z00000082();
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
	sprintf(br,z00000083(),Software_APPNAME_APPON_str.c_str());
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
		ddt = z00000084();
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
		rc = sqlite3_open(z00000085(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000086(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[256];	
		sprintf(aa,z00000087(),APPName_01.c_str(),APPNameGroup_01.c_str());
		sql = aa;	

		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			if(strcmp(azResult[i], z00000088()) == 0)
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
	sprintf(br,z00000089(),APPPATHNAME_str.c_str());
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
		bhja1(GroupNamestr.c_str(), vt, z00000090());
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
		rc = sqlite3_open(z00000091(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000092(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		char aa[256];
		sprintf(aa,z00000093(),APPON.c_str(),GROUPNAME.c_str(),APPNAME.c_str());
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
			rc = sqlite3_open(z00000094(), &db);   
			if( rc )
			{
			fprintf(stderr, z00000095(), sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
			}
			else {
			//printf("open code.db successfully!\n");
			}

			char aa[256];	
			sprintf(aa,z00000096(),APPNamestr.c_str());
			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

		    	sqlite3_close(db);    
			}
	
	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok

{
		FILE *pp;	
		std::string DelNameHome;
		DelNameHome = z00000097();
		DelNameHome += APPNamestr.c_str();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		//刪除資料夾
			std::string DelApp;
			DelApp = z00000098();
			DelApp += APPNamestr.c_str();

			if( (pp = popen(DelApp.c_str(), z00000099())) == NULL )
			{
			std::cout<<z00000100()<<std::endl;
			exit(1);
			}
			pclose(pp);
		}
		else
		{
		
		}

}
//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok

{
		FILE *pp;	
		std::string DelNameHome;
		DelNameHome = z00000101();
		DelNameHome += APPNamestr.c_str();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		//刪除資料夾
			std::string DelApp;
			DelApp = z00000102();
			DelApp += APPNamestr.c_str();

			if( (pp = popen(DelApp.c_str(), z00000103())) == NULL )
			{
			std::cout<<z00000104()<<std::endl;
			exit(1);
			}
			pclose(pp);
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
		bhja1(APPNamestr.c_str(), vt, z00000105());
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
		DelNameHome = z00000106();


		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		}
		else
		{

			std::string mkdirApp;
			mkdirApp = z00000107();

			if( (pp = popen(mkdirApp.c_str(), z00000108())) == NULL )
			{
				std::cout<<z00000109()<<std::endl;
				exit(1);
			}

			pclose(pp);

		}

		DelNameHome = z00000110();
	
		boost::filesystem::path p2(DelNameHome.c_str());
		if(exists(p2) &&is_directory(p2))
		{
		}
		else
		{
			std::string mkdirApp;
			mkdirApp = z00000111();
			if( (pp = popen(mkdirApp.c_str(), z00000112())) == NULL )
			{
			std::cout<<z00000113()<<std::endl;
			exit(1);
			}
			pclose(pp);


		}

	


	//改權限777
		std::string ChmodstrGroupName;

		ChmodstrGroupName = z00000114();


		if( (pp = popen(ChmodstrGroupName.c_str(), z00000115())) == NULL )
		{
		std::cout<<z00000116()<<std::endl;
		exit(1);

		}

		pclose(pp);

	//從路徑 /PhancloudData/App 查詢軟體名稱,取得新增的群組名稱,對DB插入所有的軟體
	//插入路徑


		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;

		rc = sqlite3_open(z00000117(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000118(), sqlite3_errmsg(db));
		sqlite3_close(db);

		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}


		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[256];	


//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12));");
		sprintf(aa,z00000119(),z00000120());


		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );



		std::string strInstruction;
		strInstruction = z00000121();
			
		char buf[max_len];

	
		if( (pp = popen(strInstruction.c_str(), z00000122())) == NULL )
		{
		std::cout<<z00000123()<<std::endl;

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

			sprintf(aa,z00000124(),strbh.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());

			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	

		}
		pclose(pp);
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
		GroupName = z00000125();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000126())) == NULL )
		{
		std::cout<<z00000127()<<std::endl;
		exit(1);
		}
		std::string bhy;
		bhy = "";
		std::string ddt;
		ddt = z00000128();
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
		pclose(ff);
		//

		if(GroupIsTrue == true)
		{
			std::cout<<GroupNamestr.c_str()<<z00000129()<<std::endl;
		}
		else if(GroupIsTrue == false)
		{
			//std::cout<<"該群組不存在,可以新增"<<std::endl;


	///////////////////////////////////////
		std::string bstrCode;	
		bstrCode = z00000130();
	//groupadd //
			      
		bstrCode += GroupNamestr.c_str();
		std::cout<<z00000131()<<GroupNamestr.c_str()<<std::endl;
	//groupadd names
		FILE *pp;
		if( (pp = popen(bstrCode.c_str(), z00000132())) == NULL )
		{
		std::cout<<z00000133()<<std::endl;
		exit(1);
		}
		pclose(pp);

	

	///////

	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok
		std::string DelNameHome;
		DelNameHome = z00000134();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		}
		else
		{
		std::string mkdirGroup;
		mkdirGroup = z00000135();
		if( (pp = popen(mkdirGroup.c_str(), z00000136())) == NULL )
		{
		std::cout<<z00000137()<<std::endl;
		exit(1);
		}
		pclose(pp);

		}

		DelNameHome = z00000138();
	
		boost::filesystem::path p2(DelNameHome.c_str());
		if(exists(p2) &&is_directory(p2))
		{
		}
		else
		{
		std::string mkdirGroup;
		mkdirGroup = z00000139();
		if( (pp = popen(mkdirGroup.c_str(), z00000140())) == NULL )
		{
		std::cout<<z00000141()<<std::endl;
		exit(1);
		}
		pclose(pp);


		}

	
	//新增群組資料夾
		std::string MkdirstrGroupName;
		MkdirstrGroupName = z00000142();
		MkdirstrGroupName += GroupNamestr.c_str();

		if( (pp = popen(MkdirstrGroupName.c_str(), z00000143())) == NULL )
		{
		std::cout<<z00000144()<<std::endl;

		exit(1);
		}

		pclose(pp);

	//改資料夾擁有者
		std::string ChownstrGroupName;

		ChownstrGroupName = z00000145();
		ChownstrGroupName += GroupNamestr.c_str();
		ChownstrGroupName += z00000146();
		ChownstrGroupName += GroupNamestr.c_str();

		if( (pp = popen(ChownstrGroupName.c_str(), z00000147())) == NULL )
		{
		std::cout<<z00000148()<<std::endl;

		exit(1);
		}

		pclose(pp);

	//改權限777
		std::string ChmodstrGroupName;

		ChmodstrGroupName = z00000149();
		ChmodstrGroupName += GroupNamestr.c_str();

		if( (pp = popen(ChmodstrGroupName.c_str(), z00000150())) == NULL )
		{
		std::cout<<z00000151()<<std::endl;
		exit(1);

		}

		pclose(pp);


	//在文件中附加字串 開通samba的功能 /etc/samba/smb.conf

		std::ofstream outf(z00000152(),std::ios::app);
		outf <<std::endl; 
		outf << z00000153()<<GroupNamestr.c_str()<<z00000154() << std::endl; 

		outf << z00000155()<<GroupNamestr.c_str()<<z00000156() << std::endl; 
		outf << z00000157() << std::endl; 
		outf << z00000158() <<GroupNamestr.c_str()<< std::endl; 
		outf << z00000159() << std::endl; 
		outf << z00000160() << std::endl; 

		outf << z00000161()<<GroupNamestr.c_str()<<z00000162() << std::endl;
		outf.close();	

	//從路徑 /PhancloudData/App 查詢軟體名稱,取得新增的群組名稱,對DB插入所有的軟體

	std::string Software_APPNAME_APPPATHNAME_str;

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		rc = sqlite3_open(z00000163(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000164(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[256];	

	//bear

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12));");

		sprintf(aa,z00000165(),z00000166());

		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	//從路徑 /PhancloudData/App 查詢軟體名稱
	//select distinct APPNAME,APPPATHNAME from sensordata ;
	//查詢不重複的APPNAME,APPPATHNAME
	
		sprintf(aa,z00000167(),z00000168());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
//////////
	std::string APP_Path_max;

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
//std::cout<<azResult[i]<<std::endl;

			if(strcmp(azResult[i], z00000169()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000170()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000171()) == 0)
			{		
			}
			else
			{
Software_APPNAME_APPPATHNAME_str += azResult[i];
//std::cout<<i<<std::endl;


				
				if((i+1)%3 == 0)
				{
					Software_APPNAME_APPPATHNAME_str += z00000172();
				}
				else
				{

					Software_APPNAME_APPPATHNAME_str += z00000173();
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
			bhja1(vt[i].c_str(), vt2, z00000174());
			for (size_t j = 0; j < vt2.size(); ++ j)
			{

				APPNAME = vt2[0].c_str();
				APPPATHNAME = vt2[1].c_str();
				APPMAX = vt2[2].c_str();		
			}

//			std::cout<<">"<<APPNAME.c_str()<<"<"<<std::endl;
//			std::cout<<">"<<APPPATHNAME.c_str()<<"<"<<std::endl;
//			std::cout<<">"<<APPMAX.c_str()<<"<"<<std::endl;


		
			sprintf(aa,z00000175(),GroupNamestr.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());

			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
									
		}			


		sqlite3_free_table( azResult );
		sqlite3_close(db);  
	  

		}
		else
		{
			std::cout<<z00000176()<<std::endl;
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
		GroupName = z00000177();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000178())) == NULL )
		{
		std::cout<<z00000179()<<std::endl;
		exit(1);
		}
		std::string bhy;
		bhy = "";
		std::string ddt;
		ddt = z00000180();
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
		pclose(ff);
		//

		if(GroupIsTrue == true)
		{
			//std::cout<<GroupNamestr.c_str()<<"該群組存在,可以刪除"<<std::endl;
		
		//////////////////////////
		//刪除群組
			std::string bstrCode;	
			bstrCode = z00000181();	               
			bstrCode += GroupNamestr.c_str();
			std::cout<<z00000182()<<GroupNamestr.c_str()<<std::endl;

			char buf[max_len];
			FILE *pp;
			if( (pp = popen(bstrCode.c_str(), z00000183())) == NULL )
			{
			std::cout<<z00000184()<<std::endl;
			exit(1);
			}
			pclose(pp);
	//還沒作 判斷該資料夾是否存在 存在才能刪除

		//刪除群組資料夾
			{		
	///////

		std::string DelNameHome;
		DelNameHome = z00000185();
		DelNameHome += GroupNamestr.c_str();

		boost::filesystem::path p(DelNameHome.c_str());
		if(exists(p) &&is_directory(p))
		{
		//刪除資料夾
			std::string DelNameHome;
			DelNameHome = z00000186();
			DelNameHome += GroupNamestr.c_str();
			if( (pp = popen(DelNameHome.c_str(), z00000187())) == NULL )
			{
				std::cout<<z00000188()<<std::endl;
				exit(1);
			}
			pclose(pp);
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
				ifs.open( z00000189()); 
				while(getline(ifs,   str)) 
				{ 
					smbstr += str;
					smbstr += z00000190();
				line++; 
				} 				
			
				std::string LLQ;
				LLQ = z00000191();
				LLQ += GroupNamestr.c_str();
				LLQ += z00000192();
				std::string QQW;
				QQW = z00000193();
				QQW += GroupNamestr.c_str();
				QQW += z00000194();
				int abc = smbstr.find (LLQ);	
				int kfc = smbstr.rfind (QQW);	

				std::string hh;
				hh = smbstr.substr(0,abc).c_str();
				hh += smbstr.substr(kfc + QQW.length() ).c_str();
															
				ifs.close();			
				std::ofstream outf(z00000195(),std::ios::trunc);
				outf <<hh.c_str()<<std::endl; 
				outf.close();	
			}
			{
		
			sqlite3 *db=NULL;
			char *zErrMsg = 0;
			int rc;
			char *sql;
			rc = sqlite3_open(z00000196(), &db);   
			if( rc )
			{
			fprintf(stderr, z00000197(), sqlite3_errmsg(db));
			sqlite3_close(db);
			exit(1);
			}
			else {
			//printf("open code.db successfully!\n");
			}

			char aa[256];	
			sprintf(aa,z00000198(),GroupNamestr.c_str());
			sql = aa;	
			sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

		    	sqlite3_close(db);    
			}
			//

			/////////////////////////
		}
		else if(GroupIsTrue == false)
		{
			std::cout<<z00000199()<<std::endl;

		}
		else
		{
			std::cout<<z00000200()<<std::endl;
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
		GroupName =  z00000201();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000202())) == NULL )
		{
		std::cout<<z00000203()<<std::endl;
		exit(1);
		}
		std::string bhy;
		bhy = "";
		std::string ddt;
		ddt = z00000204();
		int bbaw;
		//
		std::string zhj = z00000205();
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
		pclose(ff);
	//
		if(GroupIsTrue == true)
		{			
	// 判斷使用者是否存在 ok
	//////////////////////////////
		std::string bstrCode;	
		bstrCode = z00000206();
		char buf[max_len];
		FILE *pp;
		if( (pp = popen(bstrCode.c_str(), z00000207())) == NULL )
		{
		std::cout<<z00000208()<<std::endl;
		exit(1);
		}
			std::string bgq = z00000209();
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
		pclose(pp);


	///

		if(UserIsTrue == true)
		{
		std::cout<<z00000210()<<std::endl;
		}
		else if(UserIsTrue == false)
		{
	//	std::cout<<"沒有此使用者,可以新增"<<std::endl;
		
			//useradd -m -g 
			std::string useraddInstruction;	
			useraddInstruction = z00000211();			  
			//useradd -m -g "group user"
			useraddInstruction += judgment.substr(instruction.length(),judgment.length()).c_str();
			FILE *pp;
		
			if( (pp = popen(useraddInstruction.c_str(), z00000212())) == NULL )
			{
			std::cout<<z00000213()<<std::endl;
			exit(1);
			}
			pclose(pp);
		//
			//初始化密碼rootroot
			std::string bgq = z00000214();
			std::string UserNamestr;
			UserNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();
			int abc = UserNamestr.find_last_of(bgq);
			std::string password;
			password = z00000215();
			password += UserNamestr.substr(abc+1).c_str();
			std::cout<<z00000216()<<GroupNamestr.substr(0,ssde).c_str()<<z00000217()<<UserNamestr.substr(abc+1).c_str() <<std::endl;
			password += z00000218();
		
			if( (pp = popen(password.c_str(), z00000219())) == NULL )
			{
			std::cout<<z00000220()<<std::endl;

			exit(1);
			}
			pclose(pp);
			//更改777權限
			std::string chmodstr;

			chmodstr = z00000221();
			chmodstr += UserNamestr.substr(abc+1).c_str();

			if( (pp = popen(chmodstr.c_str(), z00000222())) == NULL )
			{

			std::cout<<z00000223()<<std::endl;
			exit(1);
			}
			pclose(pp);
			//add smbuser
			chmodstr = "";
			chmodstr = z00000224();
			chmodstr += UserNamestr.substr(abc+1).c_str();

			if( (pp = popen(chmodstr.c_str(), z00000225())) == NULL )

			{
			std::cout<<z00000226()<<std::endl;
			exit(1);
			}
			pclose(pp);


		}
		else
		{
		std::cout<<z00000227()<<std::endl;
		}

	/////////////////////////////

		}
		else if(GroupIsTrue == false)
		{		
			std::cout<<z00000228()<<std::endl;	
		}
		else
		{
			std::cout<<z00000229()<<std::endl;
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
		GroupName =  z00000230();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000231())) == NULL )
		{
		std::cout<<z00000232()<<std::endl;
		exit(1);
		}
		std::string bhy;
		bhy = "";
		std::string ddt;
		ddt = z00000233();
		int bbaw;
		//
		std::string zhj = z00000234();
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
		pclose(ff);
	//
		if(GroupIsTrue == true)
		{			
	// 判斷使用者是否存在 ok
	//////////////////////////////
		std::string bstrCode;	
		bstrCode = z00000235();
		char buf[max_len];
		FILE *pp;
		if( (pp = popen(bstrCode.c_str(), z00000236())) == NULL )
		{
		std::cout<<z00000237()<<std::endl;
		exit(1);
		}
			std::string bgq = z00000238();
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
		pclose(pp);


	///

		if(UserIsTrue == true)
		{
	//	std::cout<<"有此使用者,可以刪除"<<std::endl;
	//std::cout<<UserNamestr.c_str()<<std::endl;

	/////////////////////////////////////////////////////////////	
	//刪除smb使用者帳戶				
			std::string chmodstr;
			chmodstr = z00000239();
			chmodstr += UserNamestr.c_str();
			if( (pp = popen(chmodstr.c_str(), z00000240())) == NULL )
			{
			std::cout<<z00000241()<<std::endl;
			exit(1);
			}
			pclose(pp);	
	//刪除使用者		
			std::string userdelInstruction;		
			userdelInstruction = z00000242();
			userdelInstruction += UserNamestr.c_str();
			std::cout<<z00000243()<<UserNamestr.c_str()<<std::endl;
			if( (pp = popen(userdelInstruction.c_str(), z00000244())) == NULL )
			{
			std::cout<<z00000245()<<std::endl;
			exit(1);
			}
			pclose(pp);

	//判斷該使用者資料夾是否刪除,如果沒刪除的話輸入指令刪除 ok
		std::string DelNameHome;
		DelNameHome = z00000246();
		DelNameHome += UserNamestr.c_str();

	boost::filesystem::path p(DelNameHome.c_str());
	if(exists(p) &&is_directory(p))
	{
	//	std::cout<<"1"<<std::endl;

	//刪除資料夾
		    	std::string DelNameHome;
			DelNameHome = z00000247();
			DelNameHome += UserNamestr.c_str();
			if( (pp = popen(DelNameHome.c_str(), z00000248())) == NULL )
			{
			std::cout<<z00000249()<<std::endl;
			exit(1);
			}
			pclose(pp);
	}
	else
	{
		//std::cout<<"使用者"<<UserNamestr.c_str()<<"資料夾已經刪除"<<std::endl;
	}



		}
		else if(UserIsTrue == false)
		{
		std::cout<<z00000250()<<std::endl;
		}
		else
		{
		std::cout<<z00000251()<<std::endl;
		}

	/////////////////////////////

		}
		else if(GroupIsTrue == false)
		{		
			std::cout<<z00000252()<<std::endl;	
		}
		else
		{
			std::cout<<z00000253()<<std::endl;
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
		GroupName = z00000254();
		GroupName += GroupNamestr.c_str();
		GroupName += z00000255();

		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000256())) == NULL )
		{
		std::cout<<z00000257()<<std::endl;
		exit(1);
		}
		std::string GetGroupName;
		while(fgets(hh, sizeof(hh), ff))
		{
			GetGroupName = hh;
		}
		pclose(ff);

		GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\r'),GetGroupName.end());
		GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\n'),GetGroupName.end());
		GetGroupName.erase(remove(GetGroupName.begin(),GetGroupName.end(),'\t'),GetGroupName.end());
std::string GetGroupNameInstruction;
if(strcmp(GetGroupName.c_str(), "") == 0)
{
}
else{
		std::string GidtogroupInstruction;
		GidtogroupInstruction = z00000258();
		GidtogroupInstruction += GetGroupName.c_str();
		GidtogroupInstruction += z00000259();
		if( (ff = popen(GidtogroupInstruction.c_str(), z00000260())) == NULL )
		{
		std::cout<<z00000261()<<std::endl;
		exit(1);
		}

		//std::string GetGroupNameInstruction;
		while(fgets(hh, sizeof(hh), ff))
		{
			GetGroupNameInstruction = hh;
		}
		pclose(ff);

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
	sprintf(br,z00000262(),GetGroupNameInstruction.c_str());
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
		GroupName =  z00000263();
		char hh[max_len];
		FILE *ff;
		if( (ff = popen(GroupName.c_str(), z00000264())) == NULL )
		{
		std::cout<<z00000265()<<std::endl;
		exit(1);
		}
		std::string bhy;
		bhy = "";
		std::string ddt;
		ddt = z00000266();
		int bbaw;
		//
		std::string zhj = z00000267();
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
		pclose(ff);
	//
		if(GroupIsTrue == true)
		{			
	// 判斷使用者是否存在 ok
	//////////////////////////////
		std::string bstrCode;	
		bstrCode = z00000268();
		char buf[max_len];
		FILE *pp;
		if( (pp = popen(bstrCode.c_str(), z00000269())) == NULL )
		{
		std::cout<<z00000270()<<std::endl;
		exit(1);
		}
			std::string bgq = z00000271();
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
		pclose(pp);

		if(UserIsTrue == true)
		{
			std::string useraddInstruction;	
			useraddInstruction = z00000272();	
			useraddInstruction += judgment.substr(instruction.length(),judgment.length()).c_str();
			FILE *pp;
		
			if( (pp = popen(useraddInstruction.c_str(), z00000273())) == NULL )
			{
			std::cout<<z00000274()<<std::endl;
			exit(1);
			}
			pclose(pp);

		}
		else if(UserIsTrue == false)
		{
		}
		else
		{
		std::cout<<z00000275()<<std::endl;
		}


		}
		else if(GroupIsTrue == false)
		{		
			std::cout<<z00000276()<<std::endl;	
		}
		else
		{
			std::cout<<z00000277()<<std::endl;
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
		std::string zhj = z00000278();
		int ssde = GroupNamestr.find_last_of(zhj);	
		acobuf = GroupNamestr.substr(0,ssde).c_str();
		passbuf = GroupNamestr.substr(ssde+1).c_str();
//std::cout<<acobuf.c_str()<<std::endl;
//std::cout<<passbuf.c_str()<<std::endl;


		if((strcmp(acobuf.c_str(), z00000279()) == 0) && (strcmp(passbuf.c_str(), z00000280()) == 0))
		{			

				char br[1024];
				sprintf(br,z00000281(),z00000282());
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
	sprintf(ch,z00000283(),VerificationNumber);
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
		rc = sqlite3_open(z00000284(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000285(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[3000];	

	//bear5

		sprintf(aa,z00000286(),z00000287());

		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

char str1[1000] ,str2[21000],str3[1000],str4[1000],str5[1000],str6[1000];
char strr[16000];

sprintf(strr,z00000288(),GroupNamestr.c_str());
//std::cout<<strr<<std::endl;

sscanf(strr,z00000289(),str1,str2,str3,str4,str5,str6);

//std::cout<<str4<<std::endl;

int yrr = atoi(str4);
//int bbae = atoi(str5);
//INSERT INTO "sensordata" VALUES( NULL ,'bb','bb','aa',0,0 );
std::cout<<str1<<z00000290()<<str2<<z00000291()<<str3<<z00000292()<<yrr<<z00000293()<<str5<<std::endl;

		sprintf(aa,z00000294(),str1,str2,str3,yrr,str5,str6);
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
		rc = sqlite3_open(z00000295(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000296(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

		sprintf(aa,z00000297(),"");

		sql = aa;	

		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
int dr=0;
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

if(strcmp(azResult[i], z00000298()) == 0 ||strcmp(azResult[i], z00000299()) == 0||strcmp(azResult[i], z00000300()) == 0||strcmp(azResult[i], z00000301()) == 0 ||strcmp(azResult[i], z00000302()) == 0 ||strcmp(azResult[i], z00000303()) == 0 || strcmp(azResult[i], z00000304()) == 0 || strcmp(azResult[i], z00000305()) == 0)
			{		
			}
			else
			{

				APPPATHNAME_str += azResult[i];	
						
				if(dr == 7)
				{
					dr = 0;
					APPPATHNAME_str += z00000306();			}
				else
				{
					APPPATHNAME_str += z00000307();	
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
	sprintf(br,z00000308(),APPPATHNAME_str.c_str());
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
		std::string zhj = z00000309();
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
		rc = sqlite3_open(z00000310(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000311(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

		//sprintf(aa,"SELECT * FROM sensorsata;","");

//std::cout<<acobuf.c_str()<<std::endl;
//std::cout<<passbuf.c_str()<<std::endl;

		sprintf(aa,z00000312(),acobuf.c_str(),passbuf.c_str());

		sql = aa;	

		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
int dr=0;
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

if(strcmp(azResult[i], z00000313()) == 0 ||strcmp(azResult[i], z00000314()) == 0||strcmp(azResult[i], z00000315()) == 0 ||strcmp(azResult[i], z00000316()) == 0 ||strcmp(azResult[i], z00000317()) == 0 )
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
				sprintf(br,z00000318(),z00000319());
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
		std::string zhj = z00000320();
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
		rc = sqlite3_open(z00000321(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000322(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

	//bear5

		sprintf(aa,z00000323(),z00000324());

		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );


//delete from sensordata where CODE='bb';

		sprintf(aa,z00000325(),acobuf.c_str(),passbuf.c_str());
		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	


		sprintf(aa,z00000326(),acobuf.c_str(),passbuf.c_str());
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
				sprintf(br,z00000327(),z00000328());
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
		std::string zhj = z00000329();
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
		rc = sqlite3_open(z00000330(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000331(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	
//////////////////////////////

		

		sprintf(aa,z00000332(),passbuf.c_str());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

if(strcmp(azResult[i], z00000333()) == 0 ||strcmp(azResult[i], z00000334()) == 0||strcmp(azResult[i], z00000335()) == 0 ||strcmp(azResult[i], z00000336()) == 0 ||strcmp(azResult[i], z00000337()) == 0 )
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
addtaskcodestr += z00000338();
addtaskcodestr += acobuf.c_str();
//pupu+dr+19:24:39@p@pupu+dr+19:24:39@p@pupu+dr+19:24:39
//////////////////////////////
		sprintf(aa,z00000339(),addtaskcodestr.c_str(),passbuf.c_str());
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
		rc = sqlite3_open(z00000340(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000341(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	
//////////////////////////////

		

		sprintf(aa,z00000342(),GroupNamestr.c_str());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

if(strcmp(azResult[i], z00000343()) == 0 ||strcmp(azResult[i], z00000344()) == 0||strcmp(azResult[i], z00000345()) == 0 ||strcmp(azResult[i], z00000346()) == 0 ||strcmp(azResult[i], z00000347()) == 0 )
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

		//sprintf(aa,"select * from sensorsata where ACOBUF = \"%s\" and TASKCODE = \"%s\";","gg2","09:08:42");
	sprintf(aa,"SELECT * FROM sensorsata;","");
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
	sprintf(br,z00000348(),APPPATHNAME_str.c_str());
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
		rc = sqlite3_open(z00000349(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000350(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

//		sprintf(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
		sprintf(aa,z00000351(),GroupNamestr.c_str());
		sql = aa;
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
//std::cout<<azResult[i]<<std::endl;
			if(strcmp(azResult[i], z00000352()) == 0 ||strcmp(azResult[i], z00000353()) == 0 ||strcmp(azResult[i], z00000354()) == 0 )
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
	sprintf(br,z00000355(),APPPATHNAME_str.c_str());
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
		rc = sqlite3_open(z00000356(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000357(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

//		sprintf(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
		sprintf(aa,z00000358(),GroupNamestr.c_str());
		sql = aa;
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
//std::cout<<azResult[i]<<std::endl;
			if(strcmp(azResult[i], z00000359()) == 0 ||strcmp(azResult[i], z00000360()) == 0 ||strcmp(azResult[i], z00000361()) == 0 )
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
	sprintf(br,z00000362(),APPPATHNAME_str.c_str());
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
	APPNAME = z00000363();

		sqlite3 *db=NULL;
		char *zErrMsg = 0;
		int rc;
		char *sql ;
		rc = sqlite3_open(z00000364(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000365(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}
		else {
		//printf("open code.db successfully!\n","");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

		sprintf(aa,z00000366(),APPNAME.c_str());
		sql = aa;
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );

	std::string APPPATHNAME_str;

		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], z00000367()) == 0 ||strcmp(azResult[i], z00000368()) == 0 )
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
	sprintf(br,z00000369(),APPPATHNAME_str.c_str());
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
	bhja1(GroupNamestr.c_str(), vt, z00000370());
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
	rc = sqlite3_open(z00000371(), &db);   
	if( rc )
	{
	fprintf(stderr, z00000372(), sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
	}
	else {
	//printf("open code.db successfully!\n");
	}

	char aa[16000];	
	sprintf(aa,z00000373(),APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str());
	sql = aa;	
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
    	//sqlite3_close(db);    
			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果

		std::string Appstr;
		sprintf(aa,z00000374(),z00000375());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			if(strcmp(azResult[i], z00000376()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000377()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000378()) == 0)
			{		
			}
			else
			{
				Appstr += azResult[i];
			
				if((i+1)%3 == 0)
				{
					Appstr += z00000379();

				}
				else
				{
					Appstr += z00000380();
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
			bhja1(vt5[i].c_str(), vt2, z00000381());
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

		rc = sqlite3_open(z00000382(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000383(), sqlite3_errmsg(db));
		sqlite3_close(db);

		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

		sprintf(aa,z00000384(),z00000385());

		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	

			if(strcmp(azResult[i], z00000386()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000387()) == 0)

			{		
			}
			else
			{
				allpath += azResult[i];

			
				if((i+1)%2 == 0)
				{
					allpath += z00000388();

				}
				else
				{
					allpath += z00000389();
				}

			}
		}
//std::cout<<allpath.c_str()<<std::endl;
		sqlite3_free_table( azResult );


		vector<string> vt4;
		bhja1(allpath.c_str(), vt4, z00000390());
		for (size_t i = 0; i < vt4.size(); ++ i)
		{

			vector<string> vt6;
			bhja1(vt4[i].c_str(), vt6, z00000391());
			int bb=0;
			int cc=0;

			for (size_t j = 0; j < vt6.size(); ++ j)
			{
//std::cout<<vt6[j].c_str()<<std::endl;
				cc = atoi(vt6[1].c_str());


				for(int k=0;k<	arrnumber.size() ;k++)
				{
					if(strcmp(arrnumber[k].c_str(), vt6[0].c_str()) == 0)			
						bb = bb + 1;		
				}

//std::cout<<bb<<","<<cc<<","<<arrnumber.size()<<std::endl;

				if(j == 0)
				{

					char dde[64];
					sprintf(dde,z00000392(),bb);
					//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;
					std::string checkOK;


					//std::cout<<"aaaaa=\t"<<APPPATHNAME.c_str()<<"\t"<<vt6[j].c_str()<<std::endl;
					if(strcmp(APPPATHNAME.c_str(), vt6[j].c_str()) == 0)	
					{
						//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;

											
						if(bb <= cc) //99 <= 99 可執行
						{							
							//std::cout<<"gg========"<<APPPATHNAME.c_str()<<std::endl;
							sprintf(aa,z00000393(),dde,vt6[j].c_str());

							sql = aa;
							sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
							checkOK = z00000394();
							sprintf(br,z00000395(),checkOK.c_str());

						}
						else
						{
							checkOK = z00000396();	
							sprintf(br,z00000397(),checkOK.c_str());			

						}

					}
					

					
				}
				bb=0;
			}					
		}

	sqlite3_close(db);  	
  
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


sprintf(br,z00000398(),z00000399());	


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
	bhja1(GroupNamestr.c_str(), vt, z00000400());
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


		rc = sqlite3_open(z00000401(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000402(), sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
		}

		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	


		sprintf(aa,z00000403(),z00000404());
		sql = aa;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

		sprintf(aa,z00000405(),GROUPNAME.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str(),LOGINTIME.c_str());

		sql = aa;	
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	



	
		std::string Appstr;
		sprintf(aa,z00000406(),z00000407());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			if(strcmp(azResult[i], z00000408()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000409()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000410()) == 0)
			{		
			}
			else
			{
				Appstr += azResult[i];
			
				if((i+1)%3 == 0)
				{
					Appstr += z00000411();
				}
				else
				{
					Appstr += z00000412();
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
			bhja1(vt5[i].c_str(), vt2, z00000413());
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

		rc = sqlite3_open(z00000414(), &db);   
		if( rc )
		{
		fprintf(stderr, z00000415(), sqlite3_errmsg(db));
		sqlite3_close(db);

		exit(1);
		}
		else {
		//printf("open code.db successfully!\n");
		}

		int nrow = 0, ncolumn = 0;
		char **azResult; //二维数组存放结果
		char aa[16000];	

		sprintf(aa,z00000416(),z00000417());
		sql = aa;	
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	
		for(int i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		{	
			if(strcmp(azResult[i], z00000418()) == 0)
			{		
			}
			else if(strcmp(azResult[i], z00000419()) == 0)
			{		
			}
			else
			{
				allpath += azResult[i];
			
				if((i+1)%2 == 0)
				{
					allpath += z00000420();
				}
				else
				{
					allpath += z00000421();
				}
			}
		}
//std::cout<<allpath.c_str()<<std::endl;
		sqlite3_free_table( azResult );

		vector<string> vt4;
		bhja1(allpath.c_str(), vt4, z00000422());
		for (size_t i = 0; i < vt4.size(); ++ i)
		{
			vector<string> vt6;
			bhja1(vt4[i].c_str(), vt6, z00000423());
			int bb=0;
			int cc=0;
			for (size_t j = 0; j < vt6.size(); ++ j)
			{
//std::cout<<vt6[j].c_str()<<std::endl;
				cc = atoi(vt6[1].c_str());

				for(int k=0;k<	arrnumber.size() ;k++)
				{
					if(strcmp(arrnumber[k].c_str(), vt6[0].c_str()) == 0)			
						bb = bb + 1;		
				}
//std::cout<<bb<<","<<cc<<","<<arrnumber.size()<<std::endl;

				if(j == 0)
				{
					char dde[64];
					sprintf(dde,z00000424(),bb);
					//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;
					std::string checkOK;

					//std::cout<<"aaaaa=\t"<<APPPATHNAME.c_str()<<"\t"<<vt6[j].c_str()<<std::endl;
					if(strcmp(APPPATHNAME.c_str(), vt6[j].c_str()) == 0)	
					{
						//std::cout<<vt6.size()<<"\t i = "<<i<<"\t"<<bb<<"\t"<<cc<<"\t,\t"<<vt6[j].c_str()<<std::endl;
											
						if(bb <= cc) //99 <= 99 可執行
						{							
							//std::cout<<"gg========"<<APPPATHNAME.c_str()<<std::endl;
							sprintf(aa,z00000425(),dde,vt6[j].c_str());
							sql = aa;
							sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );	
							checkOK = z00000426();
							sprintf(br,z00000427(),checkOK.c_str());
						}
						else
						{
							checkOK = z00000428();	
							sprintf(br,z00000429(),checkOK.c_str());			
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

	std::string GroupNamestr;
	GroupNamestr = judgment.substr(instruction.length(),judgment.length()).c_str();	


	char br[16000];
	sprintf(br,z00000430(),z00000431());
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
	sep = z00000432();
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
