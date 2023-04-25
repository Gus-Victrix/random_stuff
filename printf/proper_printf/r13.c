#include "main.h"

/**
 * r13 - Performs a rot13 encryption on a string.
 *
 * @str: Input string.
 *
 * Return: rot13'ed string.
 */

char *r13(char *string)
{
	short i = 0;
	char c;

	while (string[i])
	{
		c = string[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			c += 13;
			if ((c > 'Z' && c < 'a') || c > 'z')
					c -= 26;
		}
		string[i] = c;
		i++;
	}
	return (string);
}
