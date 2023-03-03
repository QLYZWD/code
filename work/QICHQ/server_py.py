import socket


# 创建一个socket套接字，该套接字还没有建立连接
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 绑定监听端口，这里必须填本机的IP192.168.27.238，localhost和127.0.0.1是本机之间的进程通信使用的
server.bind(('10.186.84.25', 6688))
# 开始监听，并设置最大连接数
server.listen(5)

print(u'waiting for connect...')
# 等待连接，一旦有客户端连接后，返回一个建立了连接后的套接字和连接的客户端的IP和端口元组
connect, (host, port) = server.accept()
print(u'the client %s:%s has connected.' % (host, port))

while True:
    # 接受客户端的数据
    data = connect.recv(1024)
    # 如果接受到客户端要quit就结束循环
    if data == b'quit' or data == b'':
        print(b'the client has quit.')
        break
    else:
        # 发送数据给客户端
        connect.sendall(b'your words has received.')
        print(b'the client say:' + data)

# 结束socket
server.close()


''''''''''''''''
#继承StreamRequestHandler类，并重写其中的handle方法，该方法是在每个请求到来之后都会调用
class ThreadedTCPRequestHandler(socketserver.StreamRequestHandler):
    def handle(self):
        #这里是将传进的数据加上Hello 之后再返回，继承自StreamRequestHandler可以使用wfile这个类文件（file-like）对象
        data = str(self.request.recv(1024), 'utf-8')
        print(data)
        data = bytes(data, "utf-8")
        self.wfile.write(data) #write()方法只能写入bytes类型
        connect()

#该类是实现多请求并发处理，只需要继承socketserver.ThreadingMixIn即可，内部无需多加处理，采用默认方法。
class ThreadedTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass


if __name__ == "__main__":
    #如果是在局域网内实现通信，则必须将地址绑定在该PC在局域网中的地址
    #如果只是本机通信则为"localhost"或者"127.0.0.1"即可
    HOST, PORT = "10.186.84.25", 8081

    server = ThreadedTCPServer((HOST, PORT), ThreadedTCPRequestHandler)
    with server:
        server.serve_forever()
'''''