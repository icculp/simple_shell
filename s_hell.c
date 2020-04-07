#include "shellhead.h"

/**
* main - Program that functions as command line interpreter
* @ac: arguments count
* @av: argument value
* Return: 0 on success or -1 on failure
*/

int main(int ac, char **av)
{
	char *cmd[] = {"0", NULL};
	char *buf;
	size_t size = 0;
	pid_t parent;
	pid_t child;
	int i = 0, stat, get;

	write(STDOUT_FILENO, "s_hell$ ", 8);
	get = getline(&buf, &size, stdin);

	while (get >= 0)
	{
		cmd[0] = strtok(buf, "\n");
       		child = fork();
		if (child == -1)
		{
			perror("child error, you suck at parenting. Go get a cat.");
			return (-1);
		}
		if (child == 0)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
			{
				perror(av[0]);
				exit(1);
			}
		}
		else
		{
			wait(&stat);
			write(STDOUT_FILENO, "s_hell$ ", 8);
			get = getline(&buf, &size, stdin);
		}
	}
	return (0);
}
