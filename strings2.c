#include "shellhead.h"

/**
* _strspn - Gets the length of a prefix substring
* @s: Initial segment to get length
* @accept: the bytes to check for
* Return: Number of bytes in s containing bytes from accept
*/

unsigned int _strspn(char *s, const char *accept)
{
	unsigned int i, j = 0, k = 0, l;

	while (s[j] != '\0')
	{
		j++;
	}
	while (accept[k] != '\0')
	{
		k++;
	}
	for (i = 0; i < j; i++)
	{
		for (l = 0; l < k; l++)
		{
			if (s[i] == accept[l])
				break;
		}
		if (l == k)
			break;
	}
	return (i);
}

/**
* _strcspn - Copy of strcspn
* @s1: First string
* @s2: Second string
* Return: Num
*/

size_t _strcspn(const char *s1, const char *s2)
{
	const char *s = s1;
	const char *c;

	while (*s1)
	{
		for (c = s2; *c; c++)
		{
			if (*s1 == *c)
				break;
		}
		if (*c)
			break;
		s1++;
	}
	return (s1 - s);
}

/**
* _strtok - Copy of strtok
* @str: Str to tokenize
* @delim: Delimter
* Return: Pointer to token
*/

char *_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + _strspn(p, delim);
	p = str + _strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}
