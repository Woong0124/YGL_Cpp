#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSAData WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr("192.168.10.141");
	ServerSOCKADDR.sin_port = htons(4000);


	char Buffer[1024];
	int Result = connect(ServerSocket, (SOCKADDR*)&ServerSOCKADDR, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		std::cout << "fail connect : " << GetLastError() << std::endl;
		exit(-1);
	}

	std::ofstream WriteFile("test.png", std::ifstream::binary);
	if (WriteFile.is_open())
	{
		char* Buffer = new char[60000];
		int RecvSize = recv(ServerSocket, Buffer, 60000, 0);
		WriteFile.write(Buffer, RecvSize);

		Buffer = nullptr;
		delete[] Buffer;
	}
	WriteFile.close();

	closesocket(ServerSocket);
	WSACleanup();
}