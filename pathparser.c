#include "shellhead.h"

/**
 * pathparser - parses environ path
 * @val: path string, untokenized
 * @h: linked list to store path tokens
 * Return: pointer to head of linked list
 */

pathlist *pathparser(char *val, pathlist *h)
{
	char *valptr = NULL;

	valptr = strtok(val, ":");
	while (valptr)
	{
		add_node_end(&h, valptr);
		valptr = strtok(NULL, ":");
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
