
#include "epb_BoostClass.h"
#include "epb_icmp_header.hpp"
#include "epb_ipv4_header.hpp"

bool pinger::network_check = false;
bool pinger::network_check_2 = false;

void pinger::handle_timeout()
  {
    if (num_replies_ == 0)
	{
		pinger::network_check = false;
		if(MessageBox(NULL, TEXT("連線失敗，請確認IP是否正確") ,TEXT("Error")  ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
		{
            exit(1);
		}
	}
	// MessageBox(NULL, L"Request timed out" ,L"Error" , MB_OK);
		//OutputDebugString(L"Request timed out");

    // Requests must be sent no less than one second apart.	
    timer_.expires_at(time_sent_ + posix_time::seconds(15));
    timer_.async_wait(boost::bind(&pinger::start_send, this));
  }

void pinger::handle_receive(std::size_t length)
  {
    // The actual number of bytes received is committed to the buffer so that we
    // can extract it using a std::istream object.
    reply_buffer_.commit(length);

    // Decode the reply packet.
    std::istream is(&reply_buffer_);
    ipv4_header ipv4_hdr;
    icmp_header icmp_hdr;
    is >> ipv4_hdr >> icmp_hdr;

    // We can receive all ICMP packets received by the host, so we need to
    // filter out only the echo replies that match the our identifier and
    // expected sequence number.
    if (is && icmp_hdr.type() == icmp_header::echo_reply
          && icmp_hdr.identifier() == get_identifier()
          && icmp_hdr.sequence_number() == sequence_number_)
    {
      // If this is the first reply, interrupt the five second timeout.
      if (num_replies_++ == 0)
        timer_.cancel();

      // Print out some information about the reply packet.
      posix_time::ptime now = posix_time::microsec_clock::universal_time();
	  char bg1[128];
	  TCHAR ff1[128];
	  pinger::network_check = true;
	  
	//TCHAR strText[512] = {0};  
	//		_stprintf_s(strText,TEXT("%s"),sendCGlobal::Setstr.c_str());	

	  sprintf_s(bg1,"%d bytes from %s: icmp_seq=%d, ttl=%d, time=%I64d ms\n",length - ipv4_hdr.header_length(),
		  ipv4_hdr.source_address().to_string().c_str(),icmp_hdr.sequence_number(),ipv4_hdr.time_to_live(),
		  (now - time_sent_).total_milliseconds() );
	  for(int i=0;i<128;i++)
		  ff1[i] = bg1[i];
	  
	  OutputDebugString(ff1);
	  /*
      std::cout << length - ipv4_hdr.header_length()
        << " bytes from " << ipv4_hdr.source_address()
        << ": icmp_seq=" << icmp_hdr.sequence_number()
        << ", ttl=" << ipv4_hdr.time_to_live()
        << ", time=" << (now - time_sent_).total_milliseconds() << " ms"
        << std::endl;*/
    }

    start_receive();
  }

