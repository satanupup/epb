#include "applay_entry.h"

#pragma comment(lib, "ws2_32.lib")
bool connent_to_network()
{
	u_short port = 8081; 
	return false;
}

int N_TTlist_ll_ppp() //請聽者
{
	u_short protnum = 8080;
	// Initialize Winsock.
pp:WSADATA wsaData;

	int iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
	if ( iResult != NO_ERROR )
		printf("Error at WSAStartup()\n");

	// Create a socket.
	SOCKET m_socket;
	m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

	if ( m_socket == INVALID_SOCKET ) {
		printf( "Error at socket(): %ld\n", WSAGetLastError() );
		WSACleanup();
		return 0;
	}

	// Bind the socket.
	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr( "127.0.0.1" );
	service.sin_port = htons( protnum );

	if ( bind( m_socket, (SOCKADDR*) &service, sizeof(service) ) == SOCKET_ERROR ) {
		printf( "bind() failed.\n" );
		closesocket(m_socket);

		return 0;
	}

	// Listen on the socket.
	if ( listen( m_socket, 1 ) == SOCKET_ERROR )
		printf( "Error listening on socket.\n");

	// Accept connections.
	SOCKET AcceptSocket;

	//printf( "Waiting for a client to connect...\n" );

	//process(rt());
	while (1) 
	{
		AcceptSocket = SOCKET_ERROR;
		while ( AcceptSocket == SOCKET_ERROR ) {
			AcceptSocket = accept( m_socket, NULL, NULL );
		}
		//printf( "Client Connected.\n");
		m_socket = AcceptSocket; 
		break;
		//system("pause");
	}

	// Send and receive data.
	int bytesSent;
	int bytesRecv = SOCKET_ERROR;
	char sendbuf[32] = "Content-Type: text/html";
	char recvbuf[1024] = "";

	bytesRecv = recv( m_socket, recvbuf, 32, 0 );
	//printf( "Bytes Recv: %ld\n", bytesRecv );
	printf("\n");
	printf(recvbuf);
	//system("pause");
	bytesSent = send( m_socket, sendbuf, 23, 0 );
	//printf( "Bytes Sent: %ld\n", bytesSent );
	bytesRecv = recv( m_socket, recvbuf, 255, 0 );

	printf(recvbuf);
	//bytesRecv = recv( m_socket, recvbuf, 255, 0 );
	//printf(recvbuf);
	printf("\n***************我是分隔線************************************8\n"); 
	WSACleanup();
	//free(AcceptSocket);

	goto pp;
	system("pause");
	return 0;
}