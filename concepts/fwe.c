#include "concepts.h"

/**
* _exec - Exectues a program within our program
*/

int main(void)
{
	char *argv[] = {"/bin/ls", NULL};
	pid_t parent;
	pid_t child;
	int i = 0, stat;

	for (i = 0; i < 5; i++)
	{
	child = fork();
	if (child == -1)
	{
		perror("child error, you suck at parenting. Go get a cat.");
		return (1);
	}
	if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&stat);
	}
	}
	return (0);
}
