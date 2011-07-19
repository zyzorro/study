#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main( int argc, char* argv[])
{

	DIR  * dp;
	struct dirent * dirp;

	if( argc != 2)
	{
		printf(" please enter a directery name \n");
		exit(1);
	}

	dp = opendir( argv[1]);
	if(!dp)
	{
		printf("can not open dir:%s",argv[1]);
		exit(2);
	}
	while( dirp = readdir(dp))
	{
		char *name = dirp->d_name;
		printf("%s\n", name);
	
	}

	return 0;	
}


