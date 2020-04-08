#include "shellhead.h"

/**
 * _getenv - gets environment value
 * @name: name of enviornment variable
 * Return: pointer to value of variable
 */

char *_getenv(const char *name)
{
	int i = 0;
	char **var = environ;

	while (environ[i] != NULL)
	{
		*var = environ[i];
		*var = strtok(*var, "=");
		if (_strcmp(*var, name) == 0)
		{
			*var = strtok(NULL, "=");
			return (*var);
		}
		i++;
	}
	return (NULL);
}
