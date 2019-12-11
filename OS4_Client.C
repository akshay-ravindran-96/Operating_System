#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include <sys/shm.h>
void upper_string(char []);
const int SHM_SIZE = 1024;  
 char FILE_NAME[] = "";


int main(int argc, char *argv[]) {	

key_t key;
    int shmid;
    char *data;
    int n;
strncpy(FILE_NAME, argv[1], SHM_SIZE);
    if ((key = ftok(argv[1], 1)) == -1) {
        perror("ftok");
        exit(1);
    }


if ((shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT )) == -1) {
        perror("shmget");
        exit(1);
    }

 data = (char *) shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }


FILE *pToFile = fopen(FILE_NAME,"r");
int line = 0;
char input[512];
int i=1;
	while(fgets( input, 512, pToFile )) {
 
		line++;
		printf("Line:%d -> %s",line,input);
		 upper_string(input);
		// printf("Line:%d -> %s",line,input);
		strncpy(data, input, SHM_SIZE);
		//printf("Line:%d -> %s",line,data);	
		sleep(5);	
	}
strncpy(data, "STOP", SHM_SIZE);

		

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

fclose(pToFile);


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