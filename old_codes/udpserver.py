from socket import *

serverPort=12000

serverSocket=socket(AF_INET,SOCK_DGRAM)

serverSocket.bind(('127.0.0.1',serverPort))
while 1:
	msg,clientAddress=serverSocket.recvfrom(2048)
	msg=msg.split(' ')
	msg.sort()
	msg=' '.join(msg)
	print msg

	serverSocket.sendto(msg,clientAddress)