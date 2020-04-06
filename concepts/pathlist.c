#include "concepts.h"

pathlist *add_node_end(pathlist **head, const char *str)
{
	pathlist *new, *temp;

/**	printf("stringinside pathlistaddnode: %s\n", str);*/
/** Add new node */
	new = (pathlist *) malloc(sizeof(pathlist));
	if (new == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = NULL;

/**	printf("added node string?: %s\n", new->str);*/
/** Traverse to last node to append new to end */
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

void print_pathlist(const pathlist *h)
{
/**	printf("list:\n");
	printf("h first str: %s\n", h->str);*/
	while (h != NULL)
	{
/**		printf("h not null, duh\n");*/
		printf("%s\n", h->str);
		h = h->next;
	}
}
