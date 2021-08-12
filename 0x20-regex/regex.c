#include <stdio.h>
int regex_match(char const *str, char const *pattern)
{
	int match = 0;
	if (*str == '\0' &&  *pattern =='\0')
		return (1);

	
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1)  != '*')
	{
		return (regex_match(str +=1, pattern +=1));	
	}
	if (*(pattern + 1) == '*')
	{
		if(*str != '\0' && (*str == *pattern || *pattern == '.'))
			match = regex_match(str +=1, pattern);
		return (regex_match(str, pattern +=2) || match);
	}
	return (0);
}
