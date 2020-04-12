#include "shellhead.h"

/**
* builtins - checks for builtin commands like env and exit
* @sh: Tokenized argument array in sh->cmd
* Return: Flag value of 1 if certain builtins run
*/

int builtins(shellstruct *sh)
{
		if (!_strcmp(sh->cmd[0], "exit"))
		{
			freehelper(sh);
			exit(0);
		}
		if (!_strcmp(sh->cmd[0], "env"))
		{
			penv();
			return (1);
		}
	return (0);
}
