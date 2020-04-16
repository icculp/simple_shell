#include "shellhead.h"

/**
* freecmd - Frees the commands in sh->cmd and sh->execcpy
* @sh: Pointer to shell struct data holder
*/

void freecmd(shellstruct *sh)
{
	int i = 0;

	while (sh->cmd[i])
	{
		if (_strcmp(sh->cmd[i], ""))/** free all non empty strings */
			free(sh->cmd[i]);
		sh->cmd[i] = NULL; /** prevents double free error */
		i++;
	}
	free(sh->execcpy); /** dup of cmd[0], ready for next command */
	sh->execcpy = NULL;
}

/**
* freehelper - Function helper that frees memory allocated throughout program
* @sh: Struct containing data using memory
*/

void freehelper(shellstruct *sh)
{
	free_list(sh->pathhead);
	free(sh->buf);
	freecmd(sh);
	free(sh->cmd);
}

/**
* prompt - Prints prompt and awaits input
* @sh: Struct holding getline data and more
* Return: Struct with modified data
*/

shellstruct *prompt(shellstruct *sh)
{
	sh->commandnumber++;/** tracks count of interactions with shell */
	if (isatty(STDIN_FILENO))/** check for interactive mode */
		write(STDOUT_FILENO, "s_hell$ ", 8);
	sh->get = getline(&sh->buf, &sh->size, stdin);/** receive input */
	return (sh);/**redundant no need to return, could've been void function*/
}

/**
 * cmdnfound - prints error message with bad command
 * @sh: pointer to shellstruct
 */

void cmdnfound(shellstruct *sh)
{ /** Should cpy/cat to one variable and call write once, but nah */
	char *cn = malloc(sizeof(char) * 2);

	write(STDOUT_FILENO, sh->av[0], _strlen(sh->av[0]));
	write(STDOUT_FILENO, ": ", 2);
	cn[0] = (char)(sh->commandnumber + 48);
	write(STDOUT_FILENO, cn, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, sh->execcpy, _strlen(sh->execcpy));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(cn);
	freehelper(sh);
	_exit(127);/**exits in child process, so _exit used*/
}

/**
* _execve - Executes and checks env path directories
* @sh: Struct containing all data types needed for better memory management
*/

void _execve(shellstruct *sh)
{
	int execval = -1, i = 0, c = 0;
	pathlist *currentpath;
	char *execwpath = NULL;

	currentpath = sh->pathhead;
	while (execval == -1)
	{
		if ((execval == -1) && (currentpath == NULL))
		{/** probably need to check if current dir in $PATH... */
			while (sh->cmd[0][i])
			{ /** checks if command name contains path in it */
				if (sh->cmd[0][i] == '/')
					c++;
				i++;
			if (c != 0) /** name contains path, try to execute */
				execval = execve(sh->cmd[0], sh->cmd, environ);
			cmdnfound(sh);/** name doesn't contain path, and not in $PATH */
		}
		else
		{ /** copies directory in $PATH to front of command name b4 execute */
			execwpath = pathval(sh->execcpy, currentpath);
			currentpath = currentpath->next;
			execval = execve(execwpath, sh->cmd, environ);
			free(execwpath);
		}
	}
}
