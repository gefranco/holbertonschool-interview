#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
					cnt ++;
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
