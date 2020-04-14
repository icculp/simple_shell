#include "shellhead.h"

/**
 * penv - prints environ
 */

void penv(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _getenv - gets environment value
 * @name: name of enviornment variable
 * Return: pointer to value of variable
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *var = NULL, *val = NULL, *ptr;

	while (environ[i] != NULL)
	{
		var = _strdup(environ[i]);
		ptr = _strtok(var, "=");
		if (_strcmp(ptr, name) == 0)
		{
			ptr = _strtok(NULL, "=");
			val = _strdup(ptr);
			free(var);
			return (val);
		}
		free(var);
		i++;
	}
	return (NULL);
}
