#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char name [20];
void child()
{
	printf("ENTER YOUR NAME : ");
	scanf("%20s", name);
	printf("NAME : %s\n", name);
}

void parent()
{
	wait(NULL);
	printf("JOB IS DONE\n");
}

int main(void)
{
	for(int i=1; i<5; i++)
	{
		pid_t pid = fork();

		if(pid == 0)
		{
			child();
			exit(EXIT_SUCCESS);
		}
		else
		{
			parent();
		}
	}
	return EXIT_SUCCESS;
}
