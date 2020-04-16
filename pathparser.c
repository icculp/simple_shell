#include "shellhead.h"

/**
* pathval - Appends executable to directories in path
* @execcpy: Copy of executable command
* @currentpath: The current node in the path linked list
* Return: Character pointer of executable appended to pathname
*/

char *pathval(char *execcpy, pathlist *currentpath)
{ /** helper for _execve in helpers.c */
	char *pathval;

	pathval = _strdup(currentpath->str); /** /dir1 */
	pathval = _strcat(pathval, "/"); /** /dir1/ */
	pathval = _strcat(pathval, execcpy); /** /dir1/command */
	return (pathval);
}

/**
 * pathparser - parses environ path
 * @val: path string, untokenized
 * @h: linked list to store path tokens
 * Return: pointer to head of linked list
 */

pathlist *pathparser(char *val, pathlist *h)
{ /** separates path values by : delimiters in environ var $PATH */
	char *valptr = NULL;

	valptr = _strtok(val, ":");
	while (valptr)
	{
		add_node_end(&h, valptr);
		valptr = _strtok(NULL, ":");
	}
	free(val);
	return (h);
}

/**
 * add_node_end - adds new node in linked list
 * @head: head of linked list - node 1
 * @str: node data value
 * Return: pointer to struct
 */

pathlist *add_node_end(pathlist **head, const char *str)
{
	pathlist *new, *temp;

	new = (pathlist *) malloc(sizeof(pathlist));
	if (new == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (temp);
}

/**
 * print_pathlist - prints pathlist string from struct
 * @h: head of linked list
 */
void print_pathlist(const pathlist *h)
{
	while (h != NULL)
	{
		write(STDOUT_FILENO, h->str, _strlen(h->str));
		write(STDOUT_FILENO, "\n", 1);
		h = h->next;
	}
}

/**
 * free_list - frees memory of linked list
 * @head: head node of linked list
 */

void free_list(pathlist *head)
{
	pathlist *tmp = head;

	while (head != NULL)
	{
		tmp = head;
		free(tmp->str);
		head = head->next;
		free(tmp);
	}
}
