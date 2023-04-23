#include "main.h"

/**
 * dec_to_bin - Converts decimal string to binary string.
 *
 * @decimal: Decimal to be converted to binary.
 *
 * Return: Binary string.
 */

char *dec_to_bin(int decimal)
{
	int temp = 0;
	short position = 0, i;
	char *binary, sign = 0;

	if (decimal < 0)
	{
		sign = 1;
		decimal *= -1;
	}

	temp = decimal;

	while (temp)
	{
		temp /= 2;
		position++;
	}
	binary = malloc(position * sizeof(char) + sign + 1);

	for (i = 0; i < position; i++)
	{
		binary[i] = (decimal % 2) + '0';
		decimal /= 2;
	}
	if (sign)
	{
		binary[i] = '-';
		i++;
	}
	binary[i] = 0;

	return (_rev(binary));
}
