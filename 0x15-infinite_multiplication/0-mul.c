#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void print_n(int *n, int);
void sum(int *n_1, int *n_2, int);
void reset(int *n, int s);
int main(int argc, char *args[])
{

	int r, b_10;
	int i, j;
	int n_1, n_2;
	int  carry = 0;
	int flag_sum = 1;
	int *result_1 = malloc(strlen(args[1]) + strlen(args[2]) * sizeof(int));
	int *result_2 = malloc(strlen(args[1]) + strlen(args[2]) * sizeof(int));

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (98);
	}

		b_10 = strlen(args[1]) + strlen(args[2]);

	reset(result_1, strlen(args[1]) + strlen(args[2]));
	reset(result_2, strlen(args[1]) + strlen(args[2]));

	for (i = strlen(args[1]) - 1; i >= 0; i--)
	{
		b_10 = strlen(args[1]) + strlen(args[2]) - (strlen(args[1]) - i - 1);
		n_1 = args[1][i] - '0';
		carry = 0;
		for (j = strlen(args[2]) - 1; j >= 0; j--)
		{

			n_2 = args[2][j] - '0';
			r = n_1 * n_2;

			if (!flag_sum)
				result_1[b_10] = (r % 10) + carry;
			else
				result_2[b_10] = (r % 10) + carry;
			carry = r / 10;
			/*printf("----%d\n",result[b_10]);*/
			b_10 -= 1;
		}
			if (!flag_sum)
			{
				/*printf("n_1\n");*/
				result_1[b_10] = carry;
				print_n(result_1, strlen(args[1]) + strlen(args[2]));
			}
			else
			{
				/*printf("n_2\n");*/
				result_2[b_10] = carry;
				sum(result_1, result_2, strlen(args[1]) + strlen(args[2]));
				reset(result_2, strlen(args[1]) + strlen(args[2]));
			}
	}
	print_n(result_1, strlen(args[1]) + strlen(args[2]));
	free(result_1);
	free(result_2);
	return (EXIT_SUCCESS);
}

void reset(int *n, int s)
{
	int i;

	for (i = 0; i < s; i++)
		n[i] = 0;
}

void sum(int *n_1, int *n_2, int s)
{
	int i, res, r;
	(void)n_1;
	(void)n_2;
	res = 0;
	for (i = s - 1; i >= 0; i--)
	{

		r = n_1[i] + n_2[i];
		n_1[i] = (r % 10) + res;
		res = r / 10;
	}
}

void print_n(int *n, int s)
{
	int i;
	int flag_0 = 1;
	char nl = '\n';
	char c;

	for (i = 0; i <= s; i++)
	{
		if (n[i] != 0)
		{

			flag_0 = 0;
			c = n[i] + '0';
			write(1, &c, 1);
			/*printf("%d",n[i]);*/
		}
		else if (!flag_0)
		{
			c = n[i] + '0';
			write(1, &c, 1);
		}

	}
	write(1, &nl, 1);
}
