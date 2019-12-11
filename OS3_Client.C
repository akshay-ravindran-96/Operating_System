#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
void upper_string(char []);
int main(int argc, char *argv[]) {	
	 int fd;
    char * myfifo = "/tmp/myfifo";
mkfifo(myfifo, 0666);
	FILE *pToFile = fopen(argv[1],"r");
	
	int line = 0;
	char *s= "STOP";
	char input[512];
	 fd = open(myfifo, O_WRONLY);
	while( fgets( input, 512, pToFile )) {
		line++;
		printf("Line:%d -> %s",line,input);
	 upper_string(input);
write(fd, input, sizeof(input));
	//printf("Line:%d -> %s",line,input);
	sleep(1);
	}
write(fd, s, sizeof(s));
	close(fd);
	printf("\n\nEnd Of Program\n");
	
	fclose(pToFile);
	unlink(myfifo);
	return 0;

}

void upper_string(char s[]) {
   int c = 0;
 
   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
