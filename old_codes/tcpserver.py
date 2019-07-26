from socket import *

serverPort = 2000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print "server ready to receive"

while 1:
    connectionSocket, addr = serverSocket.accept()
    num = connectionSocket.recv(1024)
    l=num.split(' ')
    i=0
    for i in range(len(l)):
    	l[i]=int(l[i])
    l.sort(reverse=True)
    for i in range(len(l)):
    	l[i]=str(l[i])
    newmsg=' '.join(l)
    connectionSocket.send(newmsg)
    connectionSocket.close()
