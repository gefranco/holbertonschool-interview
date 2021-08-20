#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * find_substring - finds all the possible substrings
 * containing a list of words within a given string
 * @s: is the string to scan
 * @words:  is the array of words
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store
 *     the number of elements in the returned array
 * Return: an allocated array, storing each index in s
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, str_len, cnt;
	int *res = calloc(600, sizeof(int));
	int *count = malloc(nb_words * sizeof(int));
	int i, j, k;

	str_len = strlen(s);
	len = strlen(words[0]);
	*n = 0;

	for (i = 0; i <= str_len - nb_words * len; i++)
	{
		memset(count, 0, nb_words * sizeof(int));
		cnt = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (count[k] == 1)
					continue;
				if (strncmp(s + i + j * len, words[k], len) == 0)
				{
					count[k] = 1;
					cnt += 1;
					break;
				}
			}

		}

		if (cnt == nb_words)
		{
			res[*n] = i;
			*n += 1;
		}
	}
	free(count);
	return (res);

}
