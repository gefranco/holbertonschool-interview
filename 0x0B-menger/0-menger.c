#include <stdio.h>
#include <math.h>
void menger(int level)
{
	int i, j;
	int center[4][2] = {{1, 1}, {3, 6}, {9, 18}, {27, 54}};
	double cfi_1, cfi_2, cfi_3, cfj_1, cfj_2, cfj_3;
	double fractions = pow(3, level);/*total fractions of cubes*/

	cfi_1 = cfi_2 = cfi_3 = cfj_1 = cfj_2 = cfj_3 = 0;
	i = j = 0;

	for (i = 0; i < fractions; i++)
	{
		if (cfi_1 == 3)
			cfi_1 = 0;
		if (cfi_2 == 9)
			cfi_2 = 0;
		if (cfi_3 == 27)
			cfi_3 = 0;
		for (j = 0; j < fractions; j++)
		{
			if (cfj_1 == 3)
				cfj_1 = 0;
			if (cfj_2 == 9)
				cfj_2 = 0;
			if (cfj_3 == 27)
				cfj_3 = 0;
			if ((cfi_1 == center[0][0] &&  cfj_1 == center[0][1])
			|| ((cfi_2 >= center[1][0] &&  cfi_2 < center[1][1]) &&
			cfj_2 >= center[1][0] && cfj_2 < center[1][1])
			|| ((cfi_3 >= center[2][0] &&  cfi_3 < center[2][1]) &&
			cfj_3 >= center[2][0] && cfj_3 < center[2][1])
			|| ((i >= center[3][0] &&  i < center[3][1]) &&
			j >= center[3][0] && j < center[3][1])
			)
				printf(" ");
			else
				printf("#");
			cfj_1++;
			cfj_2++;
			cfj_3++;
		}
		cfi_1++;
		cfi_2++;
		cfi_3++;
		printf("\n");
	}
}
