#include "main.h"

/**
 * int_to_string - Converts signed integer to string.
 *
 * @integer: Integer to be converted to string.
 *
 * Return: Pointer to integer string.
 */

char *int_to_string(int integer)
{
	char n = 0;

	if (integer < 0)
	{
		integer *= -1;
		n = 1;
	}
	return (num_to_string(integer, n));
}
