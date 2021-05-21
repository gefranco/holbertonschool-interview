#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *args[])
{
	(void) args;
        if (argc != 3)
        {
                fprintf(stderr, "Error\n");
                return (98);
        }
	return (EXIT_SUCCESS);
}
