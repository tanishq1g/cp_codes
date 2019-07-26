from socket import *

serverName='localhost' 

serverPort=2000

clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

sentence=raw_input("enter alphabets: ")

clientSocket.send(sentence)

modifiedSentence=clientSocket.recv(1024)

print 'from server:', modifiedSentence

clientSocket.close()