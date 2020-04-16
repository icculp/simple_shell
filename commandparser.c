#include "shellhead.h"

/**
* initialize - Initializes values for shell, prevents ctrl-c and prompts
* @sh: Pointer to structure contaiing important data types for shell
* @ac: Args count
* @av: Args variable array
*/

void initialize(shellstruct *sh, int ac, char **av)
{
	int i = 0, start = -1;

	sh->ac = ac;
	sh->av = av;
	i = _strlen(av[0]) - 1;
	while (av[0][i] != '/')
		i--;
	while (sh->av[0][i] != '\0')
	{
		i++, start++;
		sh->av[0][start] = sh->av[0][i];
	}
	sh->cmd = malloc(sizeof(char *) * 128);
	sh->pathhead = pathparser(_getenv("PATH"), sh->pathhead);
	signal(SIGINT, siginthandler);
	prompt(sh);
}

/**
* siginthandler - Helps signal ignore sigint (ctrl-c)
* @sig_num: And unused variable but required for signal second arg
*/

void siginthandler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, siginthandler);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "s_hell$ ", 8);
	fflush(stdin);
}

/**
* commandparser_malloc - Tokenizes commands in buffer
* @sh: Buffer to tokenize in sh->buf
* Return: Pointer to tokenized array in sh->buf
*/

shellstruct *commandparser(shellstruct *sh)
{
		char *buf2;
		int ci = 0;

		if (sh->cmd == NULL)
		{
			freehelper(sh);
			exit(1);
		}
		buf2 = _strtok(sh->buf, " ");
		if (buf2 == NULL)
		{
			sh->cmd[0] = "";
			sh->cmd[1] = NULL;
			free(buf2);
			return (sh);
		}
		while (buf2)
		{
			sh->cmd[ci] = _strdup(buf2);
			buf2 = _strtok(NULL, " ");
			ci++;
		}
		sh->cmd[ci] = NULL;
		free(buf2);
		sh->execcpy = _strdup(sh->cmd[0]);
		return (sh);
}
