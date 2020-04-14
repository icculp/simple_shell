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
		i++;
	}
	free(sh->execcpy);
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
	int execval = -1;
	pathlist *currentpath;
	char *execwpath = NULL;

	currentpath = sh->pathhead;
	while (execval == -1)
	{
		if ((execval == -1) && (currentpath == NULL))
		{
			execval = execve(sh->cmd[0], sh->cmd, NULL);
			perror(sh->execcpy);
			freehelper(sh);
			exit(1);
		}
		else
		{
			execwpath = pathval(sh->execcpy, currentpath);
			currentpath = currentpath->next;
			execval = execve(execwpath, sh->cmd, NULL);
			free(execwpath);
		}
	}
}
