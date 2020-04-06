#ifndef concepts_h
#define concepts_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct pathlist
{
	char *str;
	struct pathlist *next;
} pathlist;


int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
pathlist *add_node_end(pathlist **head, const char *str);
void print_pathlist(const pathlist *h);
pathlist *pathparser(char *val, pathlist *h);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
