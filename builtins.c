#include "shellhead.h"

/**
* builtins - checks for builtin commands like env and exit
* @sh: Tokenized argument array in sh->cmd
* Return: Flag value of 1 if certain builtins run
*/

int builtins(shellstruct *sh)
{
	int exitstatus = 0;

	if (!_strcmp(sh->cmd[0], "exit"))
	{
		if (sh->cmd[1] != NULL)
			exitstatus = _atoi(sh->cmd[1]);
		freehelper(sh);
		exit(exitstatus);
	}
	if (!_strcmp(sh->cmd[0], "env"))
	{
		penv();
		return (1);
	}
	return (0);
}
