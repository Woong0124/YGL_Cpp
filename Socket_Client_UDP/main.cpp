#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);
	SOCKET ClientSocket = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
	ClientSockAddr.sin_family = PF_INET;
	ClientSockAddr.sin_addr.s_addr = inet_addr("192.168.10.141");
	ClientSockAddr.sin_port = htons(11111);

	char Buffer[1024] = { 0, };

	int Resuld = connect(ClientSocket, (SOCKADDR*)&ClientSockAddr, sizeof(SOCKADDR_IN));
	int ClientSockAddrLength = sizeof(SOCKADDR_IN);
	int RecvSize = recvfrom(ClientSocket, Buffer, sizeof(Buffer), 0, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
	int SentSize = sendto(ClientSocket, Buffer, RecvSize, 0, (SOCKADDR*)&ClientSockAddr, sizeof(SOCKADDR_IN));

	WSACleanup();
}