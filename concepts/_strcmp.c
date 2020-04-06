#include "concepts.h"

/**
* _strcmp - Compares two strings
* @s1: String 1
* @s2: String 2
* Return: Dest buffer
*/

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, ret = 0;

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
