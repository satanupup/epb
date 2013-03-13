
#include "epb_SendMessageGetString.h"
#include "epb_bearlib.h"
std::string sendCGlobal::Receive_instructions_		= "";
std::string sendCGlobal::Transfer_instruction_		= "";
std::string sendCGlobal::VerificationNumberR_		= "";
std::string sendCGlobal::VerificationNumberW_		= "";


void sendCGlobal::ClientVerification()
{	
	std::string Temporary_str;
	Temporary_str = "ClientVerification";
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
		
	Temporary_str = "NTR";
	Temporary_str += sendCGlobal::CVerificationNumberR();
	sendCGlobal::CTransfer_instruction(Temporary_str);	
	
	try
	{
		boost::asio::io_service rr;
		tcp::endpoint dd(boost::asio::ip::address_v4::from_string(bearlib::readcfg().c_str()),8100);
		boost::shared_ptr<sendclient> br(new sendclient(rr,dd));
		rr.run();
	}
	catch (std::exception& e)
	{
		WCHAR strText[512];
		MultiByteToWideChar( CP_ACP, 0, e.what(), -1, strText, 510 );
		OutputDebugString(strText);     
	}

}

void sendclient::handle_connect(const boost::system::error_code& error)
    {
        if(!error)
        {
			std::vector<char*> Tempstr;
			char strText[16000] = {0};  
			sprintf_s(strText,"%s",sendCGlobal::CTransfer_instruction().c_str());	

			Tempstr.push_back(strText);

			sendCGlobal::EncodeDecode(strText);	

            boost::asio::async_write(socket,boost::asio::buffer(strText),
                boost::bind(&sendclient::handle_write,this,boost::asio::placeholders::error));
					
			socket.async_read_some(boost::asio::buffer(getBuffer,16000),
                boost::bind(&sendclient::handle_read,this,boost::asio::placeholders::error));
			
        }
        else
        {
            socket.close();
        }
	}
void sendclient::handle_read(const boost::system::error_code& error)
{	
    if(!error)
    {	
		sendCGlobal::EncodeDecode(getBuffer);		
		sendCGlobal::CReceive_instructions(getBuffer);			
    }
    else
    {
        socket.close();
    }
}


void sendCGlobal::EncodeDecode(char *str)
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
void sendCGlobal::Modify_Receive_instructions_str()
{			
	std::string Receive_instructions = "";
	Receive_instructions = Receive_instructions_.c_str();

	Receive_instructions.erase(remove(Receive_instructions.begin(), Receive_instructions.end(), '\r'), Receive_instructions.end());	
	Receive_instructions.erase(remove(Receive_instructions.begin(), Receive_instructions.end(), '\n'), Receive_instructions.end());
	Receive_instructions.erase(remove(Receive_instructions.begin(), Receive_instructions.end(), '\t'), Receive_instructions.end());
	
	Receive_instructions_ = Receive_instructions;

}


int sendCGlobal::bb(const std::string& str, std::vector<std::string>& ret_)
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
