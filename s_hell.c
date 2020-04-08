#include "shellhead.h"

/**
* main - Program that functions as command line interpreter
* @ac: arguments count
* @av: argument value
* Return: 0 on success or -1 on failure
*/

int main(int ac, char **av)
{
	char **cmd = malloc(sizeof(char *) * 10);
	char *buf, *buf2, *pathval, *val, *execcpy;
	size_t size = 0;
	pid_t parent, child;
	int i = 0, stat, get, ci = 0, execval;
	pathlist *pathhead = NULL, *currentpath;

	if (cmd == NULL)
		return (1);

	val = _getenv("PATH");
	printf("val: %s\n", val);
	pathhead = pathparser(val, pathhead);
	currentpath = pathhead;
	printf("currentpath: %s\n", currentpath->str);
	write(STDOUT_FILENO, "s_hell$ ", 8);
	get = getline(&buf, &size, stdin);
	while (get >= 0)
	{
		ci = 0;
		buf[_strlen(buf) - 1] = '\0';
		buf2 = strtok(buf, " ");
		while (buf2)
		{
			cmd[ci] = _strdup(buf2);
			buf2 = strtok(NULL, " ");
			ci++;
		}
		if (!_strcmp(cmd[0], "exit"))
		{
			exit(1);
		}
		if (!_strcmp(cmd[0], "env"))
		{
			penv();
		}

		cmd[ci] = NULL;
		execcpy = _strdup(cmd[0]);
		child = fork();
		if (child == -1)
		{
			perror("child error, you suck at parenting. Go get a cat.");
			return (-1);
		}
		if (child == 0)
		{
			execval = (execve(cmd[0], cmd, NULL));

			while (execval == -1)
			{
				if ((execval == -1) && (currentpath == NULL))
				{
					perror(av[0]);
					exit(1);
				}
				else
				{
					cmd[0] = _strdup(execcpy);
					pathval = _strdup(currentpath->str);
					pathval = _strcat(pathval, "/");
					pathval = _strcat(pathval, cmd[0]);
					currentpath = currentpath->next;
					cmd[0] = _strdup(pathval);
					execve(cmd[0], cmd, NULL);
				}
			}
		}
		else
		{
			wait(&stat);
			write(STDOUT_FILENO, "s_hell$ ", 8);
			get = getline(&buf, &size, stdin);
		}
	}
		free_list(pathhead);
		free_list(currentpath);
		free(buf);
		free(execcpy);
		free(pathval);
		free(cmd);
	return (0);
}
