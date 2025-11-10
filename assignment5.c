//fork
//parent process writes to buffer, child reads it, known as Pipes.
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){


char msg[]="This is the value being passed";

int filedes[2];
  
pipe (filedes);  //creates two file des values(these are the pipes). filedes[0] open for read.. file des [1] open for write//
				//either read or write. processes shouldnt perform both. to do this use close(filedes)//
				
	long int get_pid();
	int temp;
	int num_pid= fork();  //returns the value of fork//
	if(num_pid<0)
		printf("error in fork execution");
		
	
		if(num_pid==0)    
		       //child process
			{
			close(filedes[1]);           //close write
			read(filedes[0],msg,sizeof(msg));    //3 parameters. (read,variable,size), child process, unistd header. read should be closed during this+//
			printf("child is reading the data");
			printf("Child read: %s\n", msg);
			close(filedes[0]);
			}
				
		else
		{
		close(filedes[0]);
		write(filedes[1],msg,sizeof(msg));    //3 parameters. (write,variable,size), parent process, unistd header. read should be closed during this+//
		close(filedes[1]);
						wait(NULL);
		}
		
	
	return 0;

}
