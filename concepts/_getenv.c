#include "concepts.h"

extern char **environ;

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

/**
int main(void)
{
	char *string = "SHELL", *val;
	val = _getenv(string);
	printf("val: %s\n", val);
	return (0);
}
*/
