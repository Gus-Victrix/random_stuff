#include "main.h"
#include <stdio.h>

/**
 * main - testing various functions.
 * Return: 0.
 */

int main(void)
{
	int number = 1;
	char *str;

	for (number = 1; number < 100; number++)
	{
		str = upper(from_dec(number, 16));
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
