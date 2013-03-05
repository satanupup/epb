//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff 
// (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying
// file LICENSE_1_0.txt or 
// copy at <a href="http://www.boost.org/LICENSE_1_0.txt" title="http://www.boost.org/LICENSE_1_0.txt">http://www.boost.org/LICENSE_1_0.txt</a>)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

std::string make_daytime_string()
{
        using namespace std; // For time_t, time and ctime;
        time_t now = time(0);
        return ctime(&now);
}

int main()
{
        try
        {
                boost::asio::io_service io_service;
                // 在本機13端口建立一個socket
                udp::socket socket(io_service, udp::endpoint(udp::v4(), 13));

                for (;;)
                {
                        boost::array<char, 1> recv_buf;
                        udp::endpoint remote_endpoint;
                        boost::system::error_code error;
                        // 接收一個字符，這樣就得到了遠程端點(remote_endpoint)
                        socket.receive_from(boost::asio::buffer(recv_buf),
                        remote_endpoint, 0, error);

                        if (error && error != boost::asio::error::message_size)
                                throw boost::system::system_error(error);

                        std::string message ="hello world";// make_daytime_string();
                        // 向遠程端點發送字符串message(當前時間)    
                        boost::system::error_code ignored_error;
                        socket.send_to(boost::asio::buffer(message),
                        remote_endpoint, 0, ignored_error);
                }
        }
        catch (std::exception& e)
        {
                std::cerr << e.what() << std::endl;
        }

        return 0;
}