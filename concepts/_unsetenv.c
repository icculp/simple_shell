#include "concepts.h"

extern char **environ;

int _unsetenv(const char *name)
{
	int i = 0, j = 0;
	char *var;

	if (name == NULL)
		return (-1);
	if (strlen(name) == 0)
		return (-1);
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
		if ((_strcmp(var, name) == 0))
		{
			while (environ[i] != NULL)
			{
				if (environ[i + 1] != NULL)
					environ[i] = strdup(environ[i + 1]);
				else
					environ[i] = NULL;
				i++;
			}
			j = 0;
			return (0);
		}
		i++;
	}
	return (0);
}

/**
int main(void)
{
	char *name = "PATH";
	int ret;
	ret = _unsetenv(name);
	printf("returned value: %d\n", ret);
	return (0);
}*/
