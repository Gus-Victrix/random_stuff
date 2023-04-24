#include "main.h"

/**
 * int_to_hex - Convert integer to hexadecimal string.
 *
 * @decimal: Integer input.
 *
 * Return: Hexadecimal string.
 */

char *int_to_hex(int integer)
{
	return(from_int(integer, 16));
}
