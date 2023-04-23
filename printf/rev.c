#include "main.h"

/**
 * _rev - Reverses string input.
 *
 * @string: String to be reversed.
 *
 * Return: Reversed string.
 */

char *_rev(char *string)
{
	unsigned short len = 0, i = 0;
	char temp = 0;

	len = _strlen(string) - 1;

	while (i < len)
	{
		temp = string[i];
		string[i] = string[len];
		string[len] = temp;
		i++, len--;
	}
	return (string);
}
