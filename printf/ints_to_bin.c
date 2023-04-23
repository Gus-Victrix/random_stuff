#include "main.h"

/**
 * dec_to_bin - Converts decimal to binary.
 *
 * @decimal: Decimal to be converted to binary.
 *
 * Return: Binary string.
 */

int dec_to_bin(int decimal)
{
	int temp = 0;
	int ret = 0;
	short position = 0;

	while (decimal)
	{
		temp = decimal % 2;
		decimal /= 2;
		ret += temp * _pow(10, position);
		position++;
	}
	return (ret);
}
