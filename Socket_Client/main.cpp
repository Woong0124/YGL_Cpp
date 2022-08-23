#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <WinSock2.h>
#include <string>

int main()
{
	WSAData WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSOCKADDR.sin_port = htons(3000);

	int Result = connect(ServerSocket, (SOCKADDR*)&ServerSOCKADDR, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		std::cout << "fail connect : " << GetLastError() << std::endl;
		exit(-1);
	}


	char Buffer[1024] = { 0, };
	int RecvBytes = recv(ServerSocket, Buffer, 1024, 0);

	std::cout << Buffer << std::endl;

	std::string StrSentBytes = Buffer;
	std::string LValue;
	std::string RValue;
	if (StrSentBytes.find('+') != std::string::npos)
	{
		LValue = StrSentBytes.substr(0, StrSentBytes.find('+'));
		RValue = StrSentBytes.substr(StrSentBytes.find('+') + 1, -1);
		std::cout << LValue << std::endl;
		std::cout << RValue << std::endl;
	}
	else if (StrSentBytes.find('-') != std::string::npos)
	{
		LValue = StrSentBytes.substr(0, StrSentBytes.find('-'));
		RValue = StrSentBytes.substr(StrSentBytes.find('-') + 1, -1);
		std::cout << LValue << std::endl;
		std::cout << RValue << std::endl;
	}
	else if (StrSentBytes.find('*') != std::string::npos)
	{
		LValue = StrSentBytes.substr(0, StrSentBytes.find('*'));
		RValue = StrSentBytes.substr(StrSentBytes.find('*') + 1, -1);
		std::cout << LValue << std::endl;
		std::cout << RValue << std::endl;
	}
	else if (StrSentBytes.find('/') != std::string::npos)
	{
		LValue = StrSentBytes.substr(0, StrSentBytes.find('/'));
		RValue = StrSentBytes.substr(StrSentBytes.find('/') + 1, -1);
		std::cout << LValue << std::endl;
		std::cout << RValue << std::endl;
	}
	int Anwser = stoi(LValue) * stoi(RValue);
	std::cout << Anwser << std::endl;

	std::string StrAnwser = std::to_string(Anwser);
	int SentBytes = send(ServerSocket, StrAnwser.c_str() , StrAnwser.length(), 0);

	recv(ServerSocket, Buffer, sizeof(Buffer), 0);
	std::cout << "Answer :" << Buffer << std::endl;

	closesocket(ServerSocket);
	WSACleanup();
}