#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

int main (void)
{
  struct sockaddr_in serv_addr;

  char sendBuff[1025];

  int listenfd = 0, connfd = 0;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("socket retrieve success\n");
  printf("socket descriptor: %d\n", listenfd);

  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(sendBuff, '0', sizeof(sendBuff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(5000);

  bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

  if( listen(listenfd, 10) == -1){
    printf("Failed to listen. Errno: %d\n", errno);
    return -1;
  }
  
  while(1)
    {
      connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

      strcpy(sendBuff, "Fuck you, from server");
      printf("\n sendBuff len: %ld \n", strlen(sendBuff));
      write(connfd, sendBuff, strlen(sendBuff));

      close(connfd);
      sleep(1);
    }
  return 0;
}