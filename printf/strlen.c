#include "main.h"
#include <stddef.h>

/**
 * _strlen - Checks the size of a string.
 *
 * @str: String to be measured in length.
 *
 * Return: Length of the string.
 */

size_t _strlen(char *str)
{
	size_t i = 0;

	while (*str)
		str++, i++;

	return (i);
}
