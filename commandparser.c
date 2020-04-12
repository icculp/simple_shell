#include "shellhead.h"

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
		buf2 = strtok(sh->buf, " ");
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
			buf2 = strtok(NULL, " ");
			ci++;
		}
		sh->cmd[ci] = NULL;
		free(buf2);
		return (sh);
}
