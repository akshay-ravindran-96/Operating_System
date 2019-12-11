        #include <stdio.h>
        #include<stdlib.h>
        #include<sys/types.h>
        #include<fcntl.h>
        #include<sys/stat.h>
        #include<unistd.h>
        
        
        int main(int argc, char* argv[])
        {
        int i=0;
         pid_t pid;
        
        printf("Hi");
        if(argc==1 || argc==2)
        {
         printf(" There is No Parameter for N:");
        }
        else if(argc>3)
        {
         printf(" There are too many parameters");
        }
        else
        {
            
             pid= fork();
        	          if(pid==-1)
        	          perror("\n fork error");
        	          else if (pid>0)
        	          {
        	          /* int fd;
        	           int ret;
        	   
        	           fd= open("x.txt", O_CREAT| O_WRONLY);
        	            if(fd<0)
        	            {
        	                perror("open not working");
        	                exit(1);
        	            }
        	              
        	           ret=dup2(fd,1);
        	           
        	            if(ret<0)
        	            {
        	                 perror("Dup not working");
        	                exit(1);
        	                
        	            }*/
        	            
        	            system(argv[2]);
        	            
        	          //  close(fd);
        	            printf("The Child Terminates");
        	              
        	          }
        
        
        }
        
            printf("The main Process Terminates");
            return 0;
        }