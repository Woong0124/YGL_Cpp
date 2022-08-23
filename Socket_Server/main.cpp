#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	// load Winsock
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cout << "Winsock Error : " << GetLastError() << std::endl;
		exit(-1);
	}

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "fail create Socket : " << GetLastError() << std::endl;
		exit(-1);
	}

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(SOCKADDR_IN));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ServerSockAddr.sin_port = htons(8000);

	int Result = bind(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		std::cout << "fail bind : " << GetLastError() << std::endl;
		exit(-1);
	}

	Result = listen(ServerSocket, 0);
	if (Result == SOCKET_ERROR)
	{
		std::cout << "fail listen : " << GetLastError() << std::endl;
		exit(-1);
	}

	SOCKADDR_IN ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
	int ClientSockAddrLength = sizeof(ClientSockAddr);
	SOCKET ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
	if (ClientSocket == SOCKET_ERROR)
	{
		std::cout << "fail accept : " << GetLastError() << std::endl;
		exit(-1);
	}

	char Buffer[] = "Hello World";
	int SentBytes = send(ClientSocket, Buffer, sizeof(Buffer), 0);
	if (SentBytes <= 0)
	{
		std::cout << "fail send : " << GetLastError() << std::endl;
		exit(-1);
	}

	char Buffer2[1024] = { 0, };
	int RecvBytes = recv(ClientSocket, Buffer2, 1024, 0);
	if (RecvBytes <= 0)
	{
		std::cout << "fail recv : " << GetLastError() << std::endl;
		exit(-1);
	}

	std::cout << Buffer2 << std::endl;

	closesocket(ServerSocket);
	closesocket(ClientSocket);

	WSACleanup();
}