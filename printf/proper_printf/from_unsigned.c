#include "main.h"

/**
 * from_unsigned - Creates a string out of an integer input.
 *
 * @decimal: integer to be converted.
 * @base: The base to which an int is to be converted.
 *
 * Return: String of specified type.
 */

char *from_unsigned(size_t decimal, unsigned short base)
{
	size_t temp = 0;
	short position = 0, i;
	char *ret, sign = 0, hex;

	if (!decimal)
	{
		ret = malloc(2 * sizeof(char));
		*ret = '0';
		*(ret + 1) = 0;
		return (_rev(ret));
	}
	temp = decimal;

	while (temp)
	{
		temp /= base;
		position++;
	}
	ret = malloc(sign + 1 + position * sizeof(char));

	for (i = 0; i < position; i++)
	{
		hex = (decimal % base);
		if (hex > 9)
			ret[i] = hex - 10 + 97;
		else
			ret[i] = hex + '0';
		decimal /= base;
	}
	ret[i] = 0;

	return (_rev(ret));
}
