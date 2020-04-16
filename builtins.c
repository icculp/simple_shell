#include "shellhead.h"

/**
 * illegalexitnum - writes illegal num error on exit
 * @sh: pointer of shellstruct
 */

void illegalexitnum(shellstruct *sh)
{
	char *cn;

	cn = malloc(sizeof(char) * 2);
	write(STDOUT_FILENO, sh->av[0], _strlen(sh->av[0]));
	write(STDOUT_FILENO, ": ", 2);
	cn[0] = (char)(sh->commandnumber + 48);
	write(STDOUT_FILENO, cn, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, sh->execcpy, _strlen(sh->execcpy));
	write(STDOUT_FILENO, ": Illegal number: ", 18);
	write(STDOUT_FILENO, sh->cmd[1], _strlen(sh->cmd[1]));
	write(STDOUT_FILENO, "\n", 1);
	free(cn);
}

/**
* builtins - checks for builtin commands like env and exit
* @sh: Tokenized argument array in sh->cmd
* Return: Flag value of 1 if certain builtins run
*/

int builtins(shellstruct *sh)
{
	int exitstatus = 0;

	if(!_strcmp(sh->cmd[0], "exit"))
	{
		if (sh->cmd[1] != NULL)
		{
			exitstatus = _atoi(sh->cmd[1]);
			if (exitstatus < 0)
			{
				illegalexitnum(sh);
				return (1);
			}
		}
		freehelper(sh);
		exit(exitstatus);
	}
	if (!_strcmp(sh->cmd[0], "env"))
	{
		penv();
		return (1);
	}
	if (!_strcmp(sh->cmd[0], "setenv"))
	{
		if (sh->cmd[1] == NULL)
			perror("setenv");
		if (sh->cmd[2] == NULL)
			sh->cmd[2] = "";
		else
			_setenv(sh->cmd[1], sh->cmd[2], 1);
		return (1);
	}
	if (!_strcmp(sh->cmd[0], "unsetenv"))
	{
		if (sh->cmd[1] == NULL)
			perror("unsetenv");
		else
			_unsetenv(sh->cmd[1]);
		return (1);
	}
	return (0);
}
