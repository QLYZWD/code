#include <stdio.h>
#include <winsock2.h>


//1������������
#pragma comment(lib,"ws2_32.lib") //���� ws2_32.libddl

int main()
{
	//2����ʼ�� DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2) ,&wsaData); //�汾��2.2

	//3������Socket ���׽��֣�
							//ipv4     �������ӵ��׽���  TCPЭ��
	SOCKET servSock = socket(AF_INET , SOCK_STREAM, IPPROTO_TCP);
	
	//4�����÷������˻�����Ϣ
	SOCKADDR_IN saddr;
	//INADDR_ANY Ϊ�����ַ���ص�
	saddr.sin_addr.S_un.S_addr = htons(INADDR_ANY); //IP��ַ
	saddr.sin_family = AF_INET; //ipv4Э������
	saddr.sin_port = htons(8082); //�˿ں�
	

	//5�����ڱ��ض˿�
	bind(servSock, (SOCKADDR*)&saddr, sizeof(SOCKADDR));

	printf("�������������ɹ����ȴ������У�\n");

	//6�������˿�
	listen(servSock , 100);
	

	//7��ѭ������

	

	//8���ȴ��ͻ�������
	//��������״̬��ֱ���пͻ�������
	while (true)
	{
	int len = sizeof(SOCKADDR);
	SOCKADDR_IN caddr;
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&caddr, &len);

	printf("�ͻ���(%s)���ӳɹ���\n",caddr);


	char recvBuf[1000] = "";
	recv(clntSock, recvBuf, 1000, 0);
	printf("%s\n", recvBuf);

	//10������������ͻ��˷���Ϣ
	char sendBuf[1000] = "";
	sprintf_s(sendBuf, "�������ӳɹ�");
	send(clntSock, sendBuf, strlen(sendBuf) + 1, 0);	
	}
	



	//11���رշ�����
	//closesocket(clntSock);
	//closesocket(servSock);

	//12���˳�������
	WSACleanup();
	printf("�������ر�!\n");
	
	return 0;
}

