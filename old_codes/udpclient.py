 
from socket import *

serverName='127.0.0.1'
serverPort= 12000	

clientSocket=socket(AF_INET,SOCK_DGRAM)

msg=raw_input("enter array : ")

clientSocket.sendto(msg,(serverName,serverPort))

newmsg,serverAddress=clientSocket.recvfrom(2048)

print newmsg

clientSocket.close()