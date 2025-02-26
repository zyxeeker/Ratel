#pragma once
#include<WinSock2.h>
#include<ws2tcpip.h>
/*
*  by CallMeEngineer  2021/10/24
*/

#include <iostream>
#include <string>
#include <vector>
#include "TcpClient.h"
#include "ThreadMangerPool.h"
#include "Log.h"
#pragma comment(lib, "Ws2_32.lib")
class CMySocket
{
public:
	CMySocket(void);
	bool initSocket();
	~CMySocket(void);
	bool bindSocket(int listenport = 80);
	void Run();
	int HandleRecv(int fd, char* buf, unsigned int buflen, int i);

private:
	WSADATA wsaData;
	SOCKET serverSocket;
	SOCKADDR_IN servAdr;
	static CTcpClient tcpClient;	
	std::vector<int> clientfds;
	bool ifClose;
	static CThreadMangerPool threadPool;

};

