#include "shellhead.h"

/**
 * illegalexitnum - writes illegal num error on exit
 * @sh: pointer of shellstruct
 */

void illegalexitnum(shellstruct *sh)
{ /** shold cpy/cat to one var and call write once */
	char *cn;

	cn = malloc(sizeof(char) * 2);
	write(STDERR_FILENO, sh->av[0], _strlen(sh->av[0]));
	write(STDERR_FILENO, ": ", 2);
	cn[0] = (char)(sh->commandnumber + 48);
	write(STDERR_FILENO, cn, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, sh->execcpy, _strlen(sh->execcpy));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, sh->cmd[1], _strlen(sh->cmd[1]));
	write(STDERR_FILENO, "\n", 1);
	free(cn);
}

/**
* builtins - checks for builtin commands like env and exit
* @sh: Tokenized argument array in sh->cmd
* Return: If builtin run, set flag to 1, so main will free and reprompt, else 0
*/

int builtins(shellstruct *sh)
{
	int exitstatus = 0;

	if (!_strcmp(sh->cmd[0], "exit"))
	{
		if (sh->cmd[1] != NULL)
		{ /** exit flags */
			exitstatus = _atoi(sh->cmd[1]);
			if (exitstatus < 0)
			{ /** negative return on neg ints and chars */
				illegalexitnum(sh);
				return (1);
			}}
		else /** no flags, return with child execve  exit status */
			exitstatus = WEXITSTATUS(sh->stat);
		freehelper(sh), exit(exitstatus);
	}
	if (!_strcmp(sh->cmd[0], "env"))
	{
		penv();
		return (1);
	}
	if (!_strcmp(sh->cmd[0], "setenv"))
	{
		if (sh->cmd[1] == NULL) /** no name to set */
			perror("setenv");
		if (sh->cmd[2] == NULL) /** no value to set to name */
			sh->cmd[2] = "";
		else /** name and value good, set them */
			_setenv(sh->cmd[1], sh->cmd[2], 1);
		return (1);
	}
	if (!_strcmp(sh->cmd[0], "unsetenv"))
	{
		if (sh->cmd[1] == NULL) /** no name to unset */
			perror("unsetenv");
		else
			_unsetenv(sh->cmd[1]);
		return (1); }
	return (0);
}
