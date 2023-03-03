#include<stdio.h>
#include<winsock2.h>
#include <string.h>
//1、加载驱动库
#pragma comment(lib , "ws2_32.lib") //加载 ws2_32 dll

int main()
{
	//2、初始化DLL

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2) , &wsaData); //版本号

	//3、创建套接字
						//ipv4    模式          协议
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//4、设置连接服务端信息
	printf("输入服务器ip：\n");
	char ip[15];
	scanf("%s",&ip);
	SOCKADDR_IN saddr;
	saddr.sin_addr.S_un.S_addr = inet_addr(ip);
	printf("%c",inet_addr(ip));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8082);

	//5、发起连接请求
	bool flag = connect(sock, (SOCKADDR*)&saddr, sizeof(SOCKADDR));
	//printf("%d\n", flag);
	if (flag == 0)
	{
		printf("客户端连接成功！");
	}
	else {
		printf("客户端连接失败！");
		
	}

	//6、向服务端发送消息
	char  sendBuf[1000] = "";
	sprintf(sendBuf, "客户端请求连接\n,");
	send(sock, sendBuf, strlen(sendBuf) + 1, 0);

	//7、接收服务器端推送的消息
	char recvBuf[1000] = "";
	recv(sock, recvBuf, 1000, 0);
	printf("消息内容:%s\n", recvBuf);
	scanf("%s",&ip);
	
	//8、关闭套按字
	closesocket(sock);

	//9、终止 DLL使用
	WSACleanup();

	printf("客户端关闭!\n");
	return 0;
}
