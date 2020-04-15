#include "shellhead.h"

/**
* main - Program that functions as command line interpreter
* @ac: Args count
* @av: Args variable array
* Return: 0 on success or -1 on failure
*/

int main(int ac, char **av)
{
	pid_t child;
	int builtin = 0;
	shellstruct sh = {NULL, 0, 0, 0, NULL, NULL, NULL, 0, 0, NULL};

	initialize(&sh, ac, av);
	while (sh.get >= 0)
	{
		sh.buf[_strlen(sh.buf) - 1] = '\0';
		commandparser(&sh);
		if (!(_strcmp(sh.cmd[0], "")))
		{
			freecmd(&sh), prompt(&sh);
			continue;
		}
		builtin = builtins(&sh);
		if (builtin == 1)
		{
			freecmd(&sh);
			builtin = 0, prompt(&sh);
			continue;
		}
		child = fork();
		if (child == -1)
			perror("Fork failed, you are infertile. "), exit(1);
		if (child == 0)
			_execve(&sh);
		else
		{
			wait(&sh.stat);
			freecmd(&sh), prompt(&sh);
		}
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	freehelper(&sh);
	return (0);
}
