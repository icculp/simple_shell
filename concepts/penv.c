#include "concepts.h"

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i;

	while (env[i] != NULL)
	{
		printf("env: %s\n", environ[i]);
		i++;
	}
	printf("environ: %p\n", environ);
    return (0);
}
