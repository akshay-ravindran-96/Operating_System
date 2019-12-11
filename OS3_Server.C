#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#define MAX_BUF 1024

int main()
{
    int fd;
char *S="STOP";
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
int i=1;

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
while(i==1)
{
    		read(fd, buf, MAX_BUF);
    		printf("Received: %s\n", buf);

			if(strcmp(buf,S)==0)
				i=0;
}

    close(fd);

    return 0;
}