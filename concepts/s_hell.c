#include "concepts.h"

/**
* _exec - Exectues a program within our program
*/

int main(void)
{
	char *cmd[] = {"0", NULL};
	char *buf;
	size_t size = 0;
	pid_t parent;
	pid_t child;
	int i = 0, stat, get;

	printf("s_hell$ ");
	get = getline(&buf, &size, stdin);
	while (get >= 0)
	{
	printf("whatever dude\n");
	cmd[0] = strtok(buf, "\n");
/**	printf("buf: %s\n", cmd[0]);
	while (1)
		printf("cmd: %s\n", cmd[i]), i++;
*/
	child = fork();
	if (child == -1)
	{
		perror("child error, you suck at parenting. Go get a cat.");
		return (1);
	}
	if (child == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Errrrrrrrror:");
		}
	}
	else
	{
		wait(&stat);
	}
	printf("s_hell$ ");
	get = getline(&buf, &size, stdin);
	}
	return (0);
}
