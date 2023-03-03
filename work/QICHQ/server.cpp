#include <stdio.h>
#include <winsock2.h>


//1、加载驱动库
#pragma comment(lib,"ws2_32.lib") //加载 ws2_32.libddl

int main()
{
	//2、初始化 DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2) ,&wsaData); //版本号2.2

	//3、创建Socket （套接字）
							//ipv4     面向连接的套接字  TCP协议
	SOCKET servSock = socket(AF_INET , SOCK_STREAM, IPPROTO_TCP);
	
	//4、设置服务器端基本信息
	SOCKADDR_IN saddr;
	//INADDR_ANY 为任意地址本地的
	saddr.sin_addr.S_un.S_addr = htons(INADDR_ANY); //IP地址
	saddr.sin_family = AF_INET; //ipv4协议类型
	saddr.sin_port = htons(8082); //端口号
	

	//5、绑定在本地端口
	bind(servSock, (SOCKADDR*)&saddr, sizeof(SOCKADDR));

	printf("服务器端启动成功！等待连接中！\n");

	//6、监听端口
	listen(servSock , 100);
	

	//7、循环监听

	

	//8、等待客户端连接
	//处于阻塞状态，直到有客户端连接
	while (true)
	{
	int len = sizeof(SOCKADDR);
	SOCKADDR_IN caddr;
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&caddr, &len);

	printf("客户端(%s)连接成功！\n",caddr);


	char recvBuf[1000] = "";
	recv(clntSock, recvBuf, 1000, 0);
	printf("%s\n", recvBuf);

	//10、服务器端向客户端发消息
	char sendBuf[1000] = "";
	sprintf_s(sendBuf, "你已连接成功");
	send(clntSock, sendBuf, strlen(sendBuf) + 1, 0);	
	}
	



	//11、关闭服务器
	//closesocket(clntSock);
	//closesocket(servSock);

	//12、退出服务器
	WSACleanup();
	printf("服务器关闭!\n");
	
	return 0;
}

