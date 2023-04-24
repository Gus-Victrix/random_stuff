#include "main.h"

/**
 * _strlen - Checks the size of a string.
 *
 * @str: String to be measured in length.
 *
 * Return: Length of the string.
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str)
		str++, i++;

	return (i);
}
