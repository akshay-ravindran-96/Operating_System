#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


char* itoa(int i, char b[]);
int main(int argc, const char *argv[])
{
char line[100];
char str[80];
int fd;
int i=0;
char b[10];
fd= open("Test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
close(1);
dup(fd);

if(argc!=2)
{
perror("Enter mail adress");
exit(-1);

}

FILE *fp =popen("find . -name \\*.C -print", "r");

	while(fgets(line, sizeof(line), fp) !=NULL)
	{
	i++;
	printf( "%s", line);

	}

printf(" Total no of lines : %d\n", i);

char *c=itoa(i, b);
printf("%s", c);

 strcpy (str,"echo \"Test.txt file is attached over this mail\" |mailx -s \" ");
strcat (str,c);	
strcat (str, "\" -a Test.txt ");
strcat(str, argv[1]);

system(str);
pclose(fp);

close(fd);



return 0;

}




char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}