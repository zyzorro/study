#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAXSIZE 128 

int main( int argc, char* argv[])
{

	char appname[MAXSIZE];
	pid_t child;	
	int status;
	
	while( gets(appname) != NULL)
	{
	//	appname[strlen(appname)-1]=0;
	//	puts(appname);
		if ( ( child=fork()) <0 )
		{		
			printf(" fork() error \n");
			exit(-1);
		}
		if ( child == 0 ) //child process
		{
			printf("in child process\n");
	//		fprintf(stdout,"in child process \n");   // notice: stdout != 1 ,as stdout's type is FILE * 
			int result= execlp(appname,appname,(char *)0);
			exit(result);
		}

		{
			fprintf(stdout,"in parent process\n");
			waitpid( child,status,0);
			if ( WIFEXITED(status))
			{
				printf("return value is :%d", WEXITSTATUS(status));
			}
			
			printf("in parent process2\n");
		}

	}

	return 0;	
}


