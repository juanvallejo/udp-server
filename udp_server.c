/**
 * Sample UDP server
 *
 * @author juanvallejo
 * @date 6/25/15
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {

   int sockfd;
   int n;

   struct sockaddr_in servaddr;
   struct sockaddr_in cliaddr;

   socklen_t len;

   // make room for message received
   char mesg[1000];

   sockfd = socket(AF_INET, SOCK_DGRAM, 0);

   // set first n bytes of the area starting at first
   // address location of our servaddr to zero. ('\0')
   memset(&servaddr, sizeof(servaddr), 0);
   servaddr.sin_family = AF_INET;

   // convert '0.0.0.0' to socket byte
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

   // convert integer 32000 (representing the port to bind the socket to)
   // to socket form
   servaddr.sin_port = htons(14552);

   // bind the socket. Cast mem area of servaddr to type
   // of struct sockaddr memory (socket friendly stuff)
   bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

   // loop forever listening for messages
   while(1) {

      len = sizeof(cliaddr);

      // receive message from 0.0.0.0 on port 32000, cast the client address to
      // socket friendly memory space
      n = recvfrom(sockfd, mesg, 1000, 0, (struct sockaddr *)&cliaddr, &len);
      sendto(sockfd, mesg, n, 0, (struct sockaddr *)&cliaddr, len);

      mesg[n] = 0;
      printf("Message received: %s \n", mesg);

   }

}