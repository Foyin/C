#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MY_PORT 60002
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 60002

int main()
{
  int myListenSocket, clientSocket;
  struct sockaddr_in  myAddr, clientAddr;
  int i, addrSize, bytesRcv;

  char buffer[30];

/* create socket */

  myListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (myListenSocket < 0) {
    printf("eek! couldn't open socket\n");
    exit(-1);
  }


/* setup my server address */
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((unsigned short) MY_PORT);

/* bind my listen socket */

  i = bind(myListenSocket, 
           (struct sockaddr *) &myAddr,
           sizeof(myAddr));
  if (i < 0) {
    printf("eek! couldn't bind socket\n");
    exit(-1);
  }


/* listen */
  i = listen(myListenSocket, 5);
  if (i < 0) {
    printf("eek! couldn't listen\n");
    exit(-1);
  }


/* wait for connection request */

  addrSize = sizeof(clientAddr);

  clientSocket = accept(myListenSocket,
                        (struct sockaddr *) &clientAddr,
                        &addrSize);
  if (clientSocket < 0) {
    printf("eek! couldn't accept the connection\n");
    exit(-1);
  }

/* read message from client and do something with it */
  while (1) {
    bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
    buffer[bytesRcv] = 0;
    printf("this is what the client sent:  %s\n", buffer);
    if(strcmp(buffer,"quit") == 0)
      break;
  } 

/* close sockets */

  close(myListenSocket);
  close(clientSocket);

  return 0;
}

int client()
{
  int mySocket;
  struct sockaddr_in  addr;
  int i;

  char inStr[80];
  char buffer[80];

/* create socket */
  mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (mySocket < 0) {
    printf("eek! couldn't open socket\n");
    exit(-1);
  }


/* setup address */
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  addr.sin_port = htons((unsigned short) SERVER_PORT);

/* connect to server */

  i = connect(mySocket, 
              (struct sockaddr *) &addr,
              sizeof(addr));
  if (i<0) {
    printf("client could not connect!\n");
    exit(-1);
  }

/* get input from user and send to server */
  while (1) {
    printf("what is your message?  ");
//    scanf("%s", inStr);
    fgets(inStr, sizeof(inStr), stdin);
    inStr[strlen(inStr)-1] = 0;
    strcpy(buffer, inStr);
    send(mySocket, buffer, strlen(buffer), 0);

    if(strcmp(inStr, "quit") == 0)
      break;
  } 

/* close the socket */

  close(mySocket);

  return 0;
}
