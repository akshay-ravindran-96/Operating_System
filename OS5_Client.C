#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
#include <sys/mman.h>

void upper_string(char []);
const int SHM_SIZE = 1024; 
 char FILE_NAME[] = "x.txt";

#define FILEPATH "y.txt"
#define NUMINTS  (1000)
#define FILESIZE (NUMINTS * sizeof(int))

int main(int argc, char *argv[])
{
    int i;
    int fd;
    int result;
char *s="*";
    char *map;  /* mmapped array of int's */

  
    fd = open(FILEPATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fd == -1) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }

   
    result = lseek(fd, FILESIZE-1, SEEK_SET);
    if (result == -1) {
	close(fd);
	perror("Error calling lseek() to 'stretch' the file");
	exit(EXIT_FAILURE);
    }
    
    
    result = write(fd, "", 1);
    if (result != 1) {
	close(fd);
	perror("Error writing last byte of the file");
	exit(EXIT_FAILURE);
    }

 
    map = (char *)mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
	close(fd);
	perror("Error mmapping the file");
	exit(EXIT_FAILURE);
    }
    
    
FILE *pToFile = fopen(FILE_NAME,"r");
int line = 0;
char input[512];
	while(fgets( input, 512, pToFile )) {
 
		line++;
		printf("Line:%d -> %s",line,input);
		 upper_string(input);
		// printf("Line:%d -> %s",line,input);
		strncpy(map, input, SHM_SIZE);
		//printf("Line:%d -> %s",line,data);	
		sleep(3);	
	}
strncpy(map, "STOP", SHM_SIZE);
 
   
    if (munmap(map, FILESIZE) == -1) {
	perror("Error un-mmapping the file");
	
    }

 
    close(fd);
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