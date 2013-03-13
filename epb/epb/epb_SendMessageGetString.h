#include <winsock2.h>
#include <istream>
#include <iostream>
#include <ostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
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
#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <stdio.h>
#include <string.h>

#pragma   comment(lib,"mpr")

class sendCGlobal{
public:
	//Modify the string
	static int bb(const std::string& str, std::vector<std::string>& ret_);
	//Encryption
	static void EncodeDecode(char *str);
	//Receive_instructions
	static void CReceive_instructions(std::string Receive_instructions)
	{
		Receive_instructions_ = Receive_instructions;
	}
	static std::string CReceive_instructions()
	{
		return Receive_instructions_;
	}
	static void Modify_Receive_instructions_str();	
	//Transfer_instruction
	static void CTransfer_instruction(std::string Transfer_instruction)
	{
		Transfer_instruction_ = Transfer_instruction;					
	}
	static std::string CTransfer_instruction()
	{		
		return Transfer_instruction_;
	}
	//VerificationNumberR
	static void CVerificationNumberR(std::string VerificationNumberR)
	{
		VerificationNumberR_ = VerificationNumberR;					
	}
	static std::string CVerificationNumberR()
	{		
		return VerificationNumberR_;
	}
	
	static void ClientVerification();
private:
	static std::string Receive_instructions_;
	static std::string Transfer_instruction_;
	static std::string VerificationNumberR_;
	static std::string VerificationNumberW_;
};


using boost::asio::ip::tcp;

class sendclient
{
public:
    sendclient(boost::asio::io_service& io_service,tcp::endpoint& endpoint)
        : socket(io_service)
    {
        socket.async_connect(endpoint,
            boost::bind(&sendclient::handle_connect,this,boost::asio::placeholders::error)
            );
		
        memset(getBuffer,0,16000);//將getBuffer全部設成 0
    }
    ~sendclient()
    {
    }
//private:
    void handle_connect(const boost::system::error_code& error);    
	void handle_read(const boost::system::error_code& error);

void handle_write(const boost::system::error_code& error)
{//無窮迴圈
}
//private:
    tcp::socket socket;	
    char getBuffer[16000];
};
