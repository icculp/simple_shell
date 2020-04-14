#ifndef SHELLHEAD_H
#define SHELLHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define SSIZE_MAX 2147479552

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

/**
* struct shellstruct - Struct holding common data types for shell
* @buf: Buffer to hold strings given as input to getline
* @size: Size of buf for getline
* @get: Return value of getline
* @stat: Wait space
* @pathhead: Head of path linked list
* @cmd: Arugment array
* @execcpy: Copy of executable name without arguments or path
* Description: Allows multiple arguments TO and RETURN from helper func
*/

typedef struct shellstruct
{
	char *buf;
	size_t size;
	int get;
	int stat;
	pathlist *pathhead;
	char **cmd;
	char *execcpy;
} shellstruct;

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
int builtins(shellstruct *sh);
shellstruct *commandparser(shellstruct *sh);
char *pathval(char *execcpy, pathlist *currentpath);
void _execve(shellstruct *sh);
shellstruct *prompt(shellstruct *sh);
void freehelper(shellstruct *sh);
void freecmd(shellstruct *sh);
int _atoi(char *s);
void siginthandler(int sig_num);
void initialize(shellstruct *sh);

unsigned int _strspn(char *s, const char *accept);
size_t _strcspn(const char *s1, const char *s2);

char *_strtok(char *str, const char *delim);
#endif
