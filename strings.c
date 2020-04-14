#include "shellhead.h"

/**
* _atoi - Converts a string to an integer
* @s: String input to be converted
* Return: Value of integer to be retruned
*/

int _atoi(char *s)
{
	unsigned int result;
	int sign;

	result = 0;
	sign = 1;
	while (*s != '\0')
	{
		if ((*s) == '-')
		{
			sign = sign * -1;
			s++;
		}
		else if ((*s >= '0') && (*s <= '9'))
		{
			result = (result * 10) + ((*s) - '0');
			s++;
		}
		else if (result == 0 && !((*s >= '0') && (*s <= '9')))
		{
			s++;
		}
		else if (result > 0 && !((*s >= '0') && (*s <= '9')))
		{
			break;
		}
	}
	return (result * sign);
}

/**
* _strcmp - Compares two strings
* @s1: String 1
* @s2: String 2
* Return: Dest buffer
*/

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, ret = 0;

	if (s1[0] == '\0' && s2[0] != '\0')
		return (-1);
	if (s2[0] == '\0' && s1[0] != '\0')
		return (1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret = s1[i] - s2[i];
			break;
		}
		else
			i++;
	}
	return (ret);
}

/**
* _strlen - returns the length of a string
* @s: string taken to check length
* Return: length of string
 */

int _strlen(const char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}

/**
 * _strcat - concatenates two strings
 * @dest: ending string
 * @src: string appended to dest
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int j, i;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);

}

/**
 * _strdup - returns a pointer with malloc with a copy of given string
 * @str: given string to be copied
 * Return: NULL if str NULL or pointer containing copy of string
 */

char *_strdup(const char *str)
{
	int i;
	int len = 0;
	char *c;

	if (str == 0)
	{
		return (NULL);
	}
	for (len = 0; str[len] != '\0'; len++)
	{
		;
	}
	len++;
	c = malloc(sizeof(char) * len);
	if (c == NULL)
	{
		free(c);
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		c[i] = str[i];
	}
	return (c);
}
