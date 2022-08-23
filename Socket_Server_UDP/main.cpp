#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(SOCKADDR_IN));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = INADDR_ANY;
	ServerSockAddr.sin_port = htons(11111);

	bind(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR_IN));

	while (1)
	{
		char Buffer[1024] = { 0, };
		SOCKADDR_IN ClientSockAddr;
		memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
		int ClientSockAddrLength = sizeof(SOCKADDR_IN);
		int RecvSize = recvfrom(ServerSocket, Buffer, sizeof(Buffer), 0, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
		int SentSize = sendto(ServerSocket, Buffer, RecvSize, 0, (SOCKADDR*)&ClientSockAddr, sizeof(SOCKADDR_IN));
	}

	WSACleanup();
}