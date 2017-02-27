#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <errno.h>

int main (void)
{
  char recvBuff[1024];
  struct sockaddr_in serv_addr;

  int sockfd = 0,n = 0;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0 ){
      printf("\n Error: Could not create socket \n");
      return 1;
  } 
  printf("\n Socket descriptor: %d\n", sockfd);

  memset(recvBuff, '0', sizeof(recvBuff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){ 
    printf("\n Error : Connect Failed. Errno: %d\n", errno);
  }

   while(n = read(sockfd, recvBuff, sizeof(recvBuff)-1) > 0){
    recvBuff[23] = 0;
    printf("\n N: %d \n", n);
    if(fputs(recvBuff, stdout) == EOF)
    {
      printf("\n Error : Fputs error \n");
    }
    printf("\n");
  }

  if(n < 0){
    printf("\n Read error \n");
  }
  return 0;
}