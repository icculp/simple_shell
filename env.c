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
		ptr = _strtok(var, "=");/** separate var name from var value */
		if (_strcmp(ptr, name) == 0)
		{ /** var name found, return only var value */
			ptr = _strtok(NULL, "=");
			val = _strdup(ptr);
			free(var);
			return (val);
		}
		free(var); /** name not found */
		i++;
	}
	return (NULL);
}

/**
 * _setenv - sets environment variable
 * @name: name of variable
 * @value: value of variable
 * @overwrite: overwrite value to make changes
 * Return: 0 for success or -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	char *var, *var2, *cpy;

	if (name == NULL || _strlen(name) == 0)
		return (-1);
	if (value == NULL)
		value = "";
	cpy = _strdup(name);
	_strcat(cpy, "="), _strcat(cpy, value);
	while (name[j])
	{
		if (name[j] == '=')
		{
			free(cpy);
			return (-1);
		}
		j++;
	}
	while (environ[i] != NULL)
	{
		var = _strdup(environ[i]);
		var2 = _strtok(var, "=");
		if ((_strcmp(var2, name) == 0) && (overwrite > 0))
		{
			environ[i] = _strdup(cpy);
			free(var), free(cpy);
			return (0);
		}
		else if ((_strcmp(var2, name) == 0) && (overwrite == 0))
		{
			free(var), free(cpy);
			return (0);
		}
		i++;
	}
	environ[i++] = _strdup(cpy);
	environ[i] = NULL;
	free(var), free(cpy);
	return (0);
}

/**
 * _unsetenv - unsets environment variable
 * @name: name of variable
 * Return: 0 for success or -1 on failure
 */

int _unsetenv(const char *name)
{
	int i = 0, j = 0;
	char *var, *var2, *cpy;

	if (name == NULL)
		return (-1);
	if (_strlen(name) == 0)
		return (-1);
	while (name[j])
	{
		if (name[j] == '=')
			return (-1);
		j++;
	}
	while (environ[i] != NULL)
	{
		var = _strdup(environ[i]);
		var2 = _strtok(var, "=");
		if ((_strcmp(var2, name) == 0))
		{
			cpy = environ[i];
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			free(var), free(cpy);
			return (0);
		}
		i++;
	}
	free(var);
	return (0);
}
