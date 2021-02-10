#include <stdio.h>
int is_palindrome(unsigned long n)
{
	unsigned long m, number, svnumber;
	unsigned long b;

	svnumber = n;
	number = 0;
	b = 1;
	n = n / 10;
	while ((m = n % 10))
	{
		n = n / 10;
		b = b * 10;
	}

	n = svnumber;

	while ((m = n % 10))
	{
		n = n / 10;
		number = number + (b * m);
		b = b / 10;
	}
	n = svnumber;
	if (n == number)
		return (1);
	else
		return (0);
}
