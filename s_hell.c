#include "shellhead.h"

/**
* main - Program that functions as command line interpreter
* Return: 0 on success or -1 on failure
*/

int main(void)
{
	pid_t child;
	int builtin = 0;
	shellstruct sh = {NULL, 0, 0, 0, NULL, NULL, NULL};

	sh.cmd = malloc(sizeof(char *) * 128);
	sh.pathhead = pathparser(_getenv("PATH"), sh.pathhead);
	prompt(&sh);
	while (sh.get >= 0)
	{
		sh.buf[_strlen(sh.buf) - 1] = '\0';
		commandparser(&sh);
		sh.execcpy = _strdup(sh.cmd[0]);
		if (!(_strcmp(sh.cmd[0], "")))
		{
			freecmd(&sh);
			prompt(&sh);
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
			freecmd(&sh);
			prompt(&sh);
		}
	}
	freehelper(&sh);
	return (0);
}
