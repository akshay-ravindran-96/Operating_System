#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<unistd.h>
int isNumber(char number[])
{
 int i=0;
 int x=0;
 if(number[0]== '-')
 i=1;
 for(; number[i]!=0;i++)
 {
  if(!isdigit(number[i]))
  return 0;
 }
 x=atoi(number);
return x;
}
int main(int argc, char* argv[])
{
int N;
int i=0;
 pid_t pid;
int child=0;
printf("Hi");
if(argc==1)
{
 printf(" tThere is No Parameter for N:");
}
else if(argc>2)
{
 printf(" There are too many parameters");
}
else
{
     N= isNumber(argv[1]);
       if(N!=0)
	  {
	      printf(" N is anumber");
	      printf("%d", N);
	      for(child=0; child<3;++child)
	      {
	          printf("\n");
	          pid= fork();
	          if(pid==-1)
	          perror("\n fork error");
	          else if (pid>0)
	          {
	              for(i=0;i<N;i++)
	              {
	              printf(" This is parent process %d  \n", getpid());
	              sleep(2);
	              }
	              continue;
	          }
	          else if(child==0)
	          {
	                for(i=0;i<N;i++)
	              {
	              printf(" THis is the Child process %d C_Parent : %d \n", getpid(), getppid());
	               sleep(2);
	              }
	              break;
	              
	          }
	          else if(child==1)
	          {
	                for(i=0;i<N;i++)
	              {
	              printf(" THis is the Child process %d C_Parent : %d  \n", getpid(), getppid());
	               sleep(2);
	              }
	              break;
	              
	          }
	          else if(child==2)
	         
	          {
	                for(i=0;i<N;i++)
	              {
	              printf(" THis is the Child process %d C_Parent : %d \n", getpid(), getppid());
	               sleep(2);
	              }
	              break;
	              
	          }
	          
	      }

	      }


	      else
		  {
		   printf("N is not a number");
			}

}
      return 0;

}
