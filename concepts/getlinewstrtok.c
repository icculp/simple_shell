#include <stdio.h>
#include <stdlib.h>
#include "concepts.h"

int main(void)
{
	char *buf, buf1[100], *buf2;
	size_t size = 0;
	int num;

	printf("$ ");
	num = getline(&buf, &size, stdin);
	strcpy(buf1, buf);
	while (num >= 0)
	{
		buf2 = strtok(buf1, " ");
		while (buf2 != NULL)
		{
			printf("%s\n", buf2);
			buf2 = strtok(NULL, " ");
		}
		printf("command: %s\n", buf);
		printf("length: %zu\n", size);
		printf("num: %d\n", num);
		num = -1;
	}

	free(buf);
	return(0);
}
