#include "concepts.h"

/**
* _exec - Exectues a program within our program
*/



int main(void)
{
	char *cmd[] = {"0", "1", NULL};
	char **args = malloc(sizeof(char *) * 10);
	char *buf, *buf2;
	size_t size = 0;
	pid_t parent;
	pid_t child;
	int i = 0, stat, get, ci = 0;

	printf("startprog\n");
	printf("s_hell$ ");
	get = getline(&buf, &size, stdin);
	while (get >= 0)
	{
		ci = 0;
		buf[strlen(buf) - 1] = '\0';
		buf2 = strtok(buf, " ");
		while (buf2)
		{
			args[ci] = strdup(buf2);
			buf2 = strtok(NULL, " ");
			ci++;
		}
		args[ci] = NULL;
		ci = 0;
/**		while (args[ci])
		{
			printf("cmd[%d]: %s\n", ci, args[ci]);
			ci++;
		}
*/	

		child = fork();
		if (child == -1)
		{
			perror("child error, you suck at parenting. Go get a cat.");
			return (1);
		}
		if (child == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror(cmd[0]);
				exit(98);
			}
		}
		else
		{
			wait(&stat);
			printf("s_hell$ ");
			get = getline(&buf, &size, stdin);
			printf("get: %d\n", get);
		}
	}
	printf("end\n");
	return (0);
}
