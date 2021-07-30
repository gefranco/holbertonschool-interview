#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 && wildcmp(s1 + 1, s2))
			return (1);
		return (wildcmp(s1, s2 + 1));
	}

	if (*s1 != *s2)
		return (0);
	if (!*s1)
		return (1);
	return (wildcmp(s1 + 1, s2 + 1));
}
