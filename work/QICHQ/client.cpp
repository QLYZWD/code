#include<stdio.h>
#include<winsock2.h>
#include <string.h>
//1������������
#pragma comment(lib , "ws2_32.lib") //���� ws2_32 dll

int main()
{
	//2����ʼ��DLL

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2) , &wsaData); //�汾��

	//3�������׽���
						//ipv4    ģʽ          Э��
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//4���������ӷ������Ϣ
	printf("���������ip��\n");
	char ip[15];
	scanf("%s",&ip);
	SOCKADDR_IN saddr;
	saddr.sin_addr.S_un.S_addr = inet_addr(ip);
	printf("%c",inet_addr(ip));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8082);

	//5��������������
	bool flag = connect(sock, (SOCKADDR*)&saddr, sizeof(SOCKADDR));
	//printf("%d\n", flag);
	if (flag == 0)
	{
		printf("�ͻ������ӳɹ���");
	}
	else {
		printf("�ͻ�������ʧ�ܣ�");
		
	}

	//6�������˷�����Ϣ
	char  sendBuf[1000] = "";
	sprintf(sendBuf, "�ͻ�����������\n,");
	send(sock, sendBuf, strlen(sendBuf) + 1, 0);

	//7�����շ����������͵���Ϣ
	char recvBuf[1000] = "";
	recv(sock, recvBuf, 1000, 0);
	printf("��Ϣ����:%s\n", recvBuf);
	scanf("%s",&ip);
	
	//8���ر��װ���
	closesocket(sock);

	//9����ֹ DLLʹ��
	WSACleanup();

	printf("�ͻ��˹ر�!\n");
	return 0;
}
