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
		puts(appname);
		appname[strlen(appname)-1]=0;
	
		if ( ( child=fork()) <0 )
		{		
			printf(" fork() error \n");
			exit(-1);
		}
		
		if( child == 0 ) //child process
		{
			printf("in child process");
			fflush(1);
			int result= execlp(appname,(char *)0);
			exit(result);
		}
		else
		{
			printf("in parent process");
			waitpid( child,status,0);
		}

	}

	return 0;	
}


