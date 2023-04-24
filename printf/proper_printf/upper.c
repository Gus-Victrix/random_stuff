#include "main.h"

/**
 * upper - Converts input string to uppercase.
 *
 * @string: String to be converted.
 *
 * Return: Pointer to modified string.
 */

char *upper(char *string)
{
	unsigned int i = 0;
	while (string[i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
		i++;
	}
	return (string);
}
