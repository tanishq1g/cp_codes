#to create sockets 
from socket import *

serverName='hostname' #here hostname is given(dns lookup is called automatically in this case) or sever IP address is given
serverPort= 12000	

clientSocket=socket(socket.AF_INET,socket.SOCK_DGRAM)

msg=raw_input("enter lowercase message")

clientSocket.sendto(message,(serverName,serverPort))

newmsg,serverAddress=clientSocket.recvfrom(2048)

print newmsg