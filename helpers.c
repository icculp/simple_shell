#include "shellhead.h"

/**
* pathval - Appends executable to directories in path
* @execcpy: Copy of executable command
* @currentpath: The current node in the path linked list
* Return: Character pointer of executable appended to pathname
*/

char *pathval(char *execcpy, pathlist *currentpath)
{
	char *pathval;

	pathval = _strdup(currentpath->str);
	pathval = _strcat(pathval, "/");
	pathval = _strcat(pathval, execcpy);
	return (pathval);
}

/**
* freecmd - Frees the commands in sh->cmd and sh->execcpy
* @sh: Pointer to shell struct data holder
*/

void freecmd(shellstruct *sh)
{
	int i = 0;

	while (sh->cmd[i])
	{
		if (_strcmp(sh->cmd[i], ""))
			free(sh->cmd[i]);
		sh->cmd[i] = NULL;
		i++;
	}
	free(sh->execcpy);
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
	sh->commandnumber++;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "s_hell$ ", 8);
	sh->get = getline(&sh->buf, &sh->size, stdin);
	return (sh);
}

/**
* _execve - Executes and checks env path directories
* @sh: Struct containing all data types needed for better memory management
*/

void _execve(shellstruct *sh)
{
	int execval = -1, i = 0;
	pathlist *currentpath;
	char *execwpath = NULL;
	char *cn = malloc(sizeof(char) * 2);

	currentpath = sh->pathhead;
	while (execval == -1)
	{
		if ((execval == -1) && (currentpath == NULL))
		{
			execval = execve(sh->cmd[0], sh->cmd, environ);
			/** Lines 88-100 for printing command not found error message  */
			while (sh->av[0][i])
			{
				sh->av[0][i] = sh->av[0][i + 2];
				i++;
			}
			write(STDOUT_FILENO, sh->av[0], _strlen(sh->av[0]));
			write(STDOUT_FILENO, ": ", 2);
			cn[0] = (char)(sh->commandnumber + 48);
			write(STDOUT_FILENO, cn, 1);
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, sh->execcpy, _strlen(sh->execcpy));
			write(STDOUT_FILENO, ": not found\n", 12);
			free(cn);
			freehelper(sh);
			_exit(127);
		}
		else
		{
			execwpath = pathval(sh->execcpy, currentpath);
			currentpath = currentpath->next;
			execval = execve(execwpath, sh->cmd, environ);
			free(execwpath);
		}
	}
}
