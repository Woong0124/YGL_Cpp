#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSAData WsaData;
	if (WSAStartup(MAKEWORD(2, 2), &WsaData))
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
	ServerSockAddr.sin_port = htons(4000);

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

	std::ifstream file("C\\Work\\UE_Loge", std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "fail : file not found";
		exit(0);
	}
	int read_cnt = 0;
	char Buffer[1024];
	int sendLength = 0;
	int totalLength = 0;
	do
	{
		Sleep(50);
		file.read(Buffer, sizeof(Buffer));
		read_cnt = file.gcount();

		if (read_cnt < sizeof(Buffer))
			sendLength = send(ClientSocket, Buffer, read_cnt, 0);
		else
			sendLength = send(ClientSocket, Buffer, sizeof(Buffer), 0);


		totalLength += sendLength;
		std::cout << "sendLength " << sendLength << ", totalLength: " << totalLength << "\n";
	} while (read_cnt >= sizeof(Buffer));

	shutdown(ClientSocket, SD_SEND);
	file.close();

	recv(ClientSocket, Buffer, sizeof(Buffer), 0);
	std::cout << Buffer << "\n";

	closesocket(ServerSocket);
	closesocket(ClientSocket);

	WSACleanup();
}