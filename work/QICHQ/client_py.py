from calendar import c
import socket


# 创建一个socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 主动去连接局域网内IP为192.168.27.238，端口为6688的进程
client.connect(('10.186.84.25', 6688))

while True:
    # 接受控制台的输入
    data = input()
    # 对数据进行编码格式转换，不然报错
    data = data.encode('gbk')
    # 如果输入quit则退出连接
    if data == b'quit':
        print('connect quit.')
        break
    else:
        # 发送数据
        client.sendall(data)
        # 接收服务端的反馈数据
        rec_data = client.recv(1024)
        print(b'form server receive:' + rec_data)

# 发送数据告诉服务器退出连接
client.sendall(b'quit')
client.close()











'''''''''''''''''''''''''''''
import socket

def client(ip, port, message):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((ip, port))
        sock.sendall(bytes(message, 'utf-8'))
        response = str(sock.recv(1024), 'utf-8')
        print("Received: {}".format(response))


HOST, PORT = "10.186.84.25", 8081
while 1==1:
    message = input(">")
    if message=='':
        print("未输入")
    else:    
        client(HOST, PORT, message)
'''''''''''''''''''''''''''