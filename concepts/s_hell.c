#include "concepts.h"

/**
* _exec - Exectues a program within our program
*/



int main(void)
{
	char **args = malloc(sizeof(char *) * 10);
	char *buf, *buf2, *pathval, *val, *execcpy;
	size_t size = 0;
	pid_t parent;
	pid_t child;
	int i = 0, stat, get, ci = 0, execval;
	pathlist *pathhead = NULL, *currentpath;


	printf("startprog\n");

	val = _getenv("PATH");
	printf("val: %s\n", val);
	pathhead = pathparser(val, pathhead);
	currentpath = pathhead;
	printf("cp->str: %s\n", currentpath->str);
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
		execcpy = strdup(args[0]);
		child = fork();
		if (child == -1)
		{
			perror("child error, you suck at parenting. Go get a cat.");
			return (1);
		}
		if (child == 0)
		{
			printf("we're now a child\n");
			execval = execve(args[0], args, NULL);
			printf("execval: %d\n", execval);
			while (execval == -1)
			{
				if ((execval == -1) && (currentpath == NULL))
				{
					perror(args[0]);
					exit(98);
				}
				else
				{
					args[0] = strdup(execcpy);
					printf("currentpath->str: %s\n", currentpath->str);
					pathval = strdup(currentpath->str);
					printf("pathval: %s\n", pathval);
					pathval = strcat(pathval, "/");
					pathval = strcat(pathval, args[0]);
					args[0] = strdup(pathval);
					printf("wholepath: %s\n", args[0]);
					execval = execve(args[0], args, NULL);
					currentpath = currentpath->next;
				}
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
