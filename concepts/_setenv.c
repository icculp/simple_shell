#include "concepts.h"

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	char *var;
	char *cpy;

	if (name == NULL)
		return (-1);
	if (strlen(name) == 0)
		return (-1);
	if (value == NULL)
		value = "";
	cpy = strdup(name);
	strcat(cpy, "=");
	strcat(cpy, value);
	while (name[j])
	{
		if (name[j] == '=')
			return (-1);
		j++;
	}
	while (environ[i] != NULL)
	{
		var = strdup(environ[i]);
		var = strtok(var, "=");
		if ((_strcmp(var, name) == 0) && (overwrite > 0))
		{
			environ[i] = strdup(cpy);
			i = 0;
			while (environ[i])
			{
				printf("env[%d]: %s\n", i, environ[i]);
				i++;
			}
			return (0);
		}
		else if ((_strcmp(var, name) == 0) && (overwrite == 0))
			return (0);
		i++;
	}
	environ[i] = strdup(cpy);
	i++;
	environ[i] = NULL;
	return (0);
}

/**
int main(void)
{
	char *name = "PATf", *val = "whatasdf";
	int ret;
	ret = _setenv(name, val, 1);
	printf("returned value: %d\n", ret);
	return (0);
}*/
