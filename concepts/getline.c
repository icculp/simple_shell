#include <stdio.h>
#include <stdlib.h>
#include "concepts.h"

int main(void)
{
	char *buf;
	size_t size = 0;
	int num;

	printf("$ ");
	num = getline(&buf, &size, stdin);
	while (num >= 0)
	{
		printf("command: %s\n", buf);
		printf("length: %zu\n", size);
		printf("num: %d\n", num);
		num = getline(&buf, &size, stdin);
	}
	free(buf);
	return(0);
}
