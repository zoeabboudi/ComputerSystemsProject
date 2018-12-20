/*
 * adder.c - a minimal CGI program that subtracts two numbers
 */
/* $begin adder */
#include "csapp.h"
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
        echo(connfd);
        Close(connfd);
    }


    
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&');
	*p = '\0';
	strcpy(arg1, buf);
	strcpy(arg2, p+1);
	n1 = atoi(arg1);
	//n2 = atoi(arg2);
    }
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
    sprintf(content, "Welcome to Zoe & Mori's News API: ");
    sprintf(content, "%sZoe & Mori's News portal.\r\n<p>", content);
    //replace next line with how to parse through JSON given and return it nicely
    sprintf(content, "%sThe answer is: %d \r\n<p>", 
	    content, n1, n1);
    sprintf(content, "%sThanks for visiting!\r\n", content);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
/* $end adder */
