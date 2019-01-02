/*
 * adder.c - a minimal CGI program that subtracts two numbers
 */
/* $begin adder */
#include "../csapp.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/* int open_listenfd(char *port) {
  strcut addrinfo hints, *listp, *p;
  int listenfd, optval=1;

  
  } */
/*
int Open_clientfd(char *hostname, char *port){
  int clientfd;                                                                    
  struct addrinfo hints, *listp, *p;

  /* Get a list of potential server addresses 
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM; /* Open a connenction 
  hints.ai_flags = AI_NUMERICSERV; /* using numeric port arg 
  hints.ai_flags != AI_ADDRCONFIG; /* Recommended for connection 
  Getaddrinfo(hostname, port, &hints, &listp);
}
*/

#if 0
//echo server:
void echo(int connfd) 
{
    size_t n; 
    char buf[MAXLINE]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) { //line:netp:echo:eof
      printf("server received %d bytes, and the string is %s\n", (int)n, buf);
        Rio_writen(connfd, buf, n);
        //printf("server received %s string\n", buf);
    }
}
void echo(int connfd);

//echoserver:
int main(int argc, char **argv)
{
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;  /* Enough space for any address */  //line:netp:echos\
erveri:sockaddrstorage                                                                         
    char client_hostname[MAXLINE], client_port[MAXLINE];
    


    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    listenfd = Open_listenfd(argv[1]);
    while (1) {        //infinite loop, classic c construct                                    
        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE,
                    client_port, MAXLINE, 0);    //try to find out where it's coming from      
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
//echo(connfd);
        Close(connfd);
    }

#endif


    
int main(int argc, char **argv){
    
    char *zipcode, *urlBegin, *urlEnd, *s;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];

    int n1=0, n2=0;

    /* Extract the zipCode */
    zipcode = strncat(getenv("QUERY_STRING"), "\0", 5);
    

    //urlBegin ="/data/2.5/weather?zip=";
    //urlEnd = ",us&units=imperial&APPID=364ebbea13d49a5e8e505870368c78be";
    //s = strcat(urlBegin, zipcode);
    // s = strcat(s, urlEnd);
    //sprintf(content, "%s \n<p>", s);

    
    // THIS IS WHERE ECHOclient  COMES IN
    int clientfd;

    char *host, *port, buf[MAXLINE];
    rio_t rio;
    host  = "http://www.openweathermap.org";
//data/2.5/weather?zip=19004,us&APPID=364ebbea13d49a5e8e505870368c78be";
    port = "80";

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio,clientfd);

    while (Fgets(buf,MAXLINE, stdin) != NULL){
      Rio_writen(clientfd, buf, strlen(buf));  //Send line to server
      Rio_readlineb(&rio, buf, MAXLINE);       // recieve line from server
      printf("echo:");
      Fputs(buf, stdout);
      printf("type:"); fflush(stdout);
    }
#if 0
    // THIS IS ECHO SERVER
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;  /* Enough space for any address */  //line:netp:echos\
erveri:sockaddrstorage                                                                         
    char client_hostname[MAXLINE], client_port[MAXLINE];
    


    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    listenfd = Open_listenfd(argv[1]);
    while (1) {        //infinite loop, classic c construct                                    
        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE,
                    client_port, MAXLINE, 0);    //try to find out where it's coming from      
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
        //echo(connfd);
        Close(connfd);
    }

#endif
   
    //const char* command  = "wget -O results.txt urlBegin";
    //int result = 0;
    
    //result = system(command);
    //fprintf(stderr, "this is what happened: %d", result);
	
    
      /* Argument list starts with "?"
	 Arguments separated  by "&"
	 Spaces represented by "+" or "%20"
	 Example:
	 argument list starts with "https://newsapi.org/v2/everything?" +
          "q=Apple&" +
          "from=2018-12-17&" +
          "sortBy=popularity&" +
          "apiKey=f8f3dee3f2524f47a1309bc2381b8cb2"; */

    


    /* Make the response body */
    //sprintf(content, "%s this is result");
    sprintf(content, "%sWelcome to Zoe & Mori's News API: ");
    sprintf(content, "%sZoe & Mori's News portal.\r\n<p>", content);
    //replace next line with how to parse through JSON given and return it nicely
    //sprintf(content, "%sThe answer is: %d \r\n<p>", 
    //content, n1, n1);
    sprintf(content, "%sThanks for visiting!\r\n", content);

    
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
