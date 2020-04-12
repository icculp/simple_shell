#ifndef SHELLHEAD_H
#define SHELLHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
* struct pathlist - struct
* @str: string data
* @next: next node
*/

typedef struct pathlist
{
	char *str;
	struct pathlist *next;
} pathlist;

extern char **environ;
void free_list(pathlist *head);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
pathlist *add_node_end(pathlist **head, const char *str);
void print_pathlist(const pathlist *h);
pathlist *pathparser(char *val, pathlist *h);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
void penv(void);

#endif
