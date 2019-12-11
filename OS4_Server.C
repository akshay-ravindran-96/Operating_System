#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include <sys/shm.h>

const int SHM_SIZE = 1024;  /* make it a 1K shared memory segment */
char FILE_NAME[] = "";


int main(int argc, char *argv[])
{
    key_t key;
    int shmid;
    char *data;
    int n;
strncpy(FILE_NAME, argv[1], SHM_SIZE);
    /* make the key: */
    if ((key = ftok( FILE_NAME, 1)) == -1) {
        perror("ftok");
        exit(1);
    }


    /* connect to (and possibly create) the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }
    data = (char *) shmat(shmid, NULL, 0);

    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    /* read the segment */


    while ((strcmp(data,"STOP") != 0) )
    {
        printf("segment contains: \"%s\"\n", data);
	sleep(5);
	
       
    }

    /* detach from the segment: */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* delete the IPC structure */
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
