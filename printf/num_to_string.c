#include "main.h"

/**
 * num_to_string - Converts number into string.
 *
 * @num: Unsigned number.
 * @sign: Sign of the number.
 *
 * Return: Pointer to new string.
 */

char *num_to_string(size_t num, char sign)
{
	char *str;
	unsigned short len = 1, i;
	size_t test = num;

	while (test /= 10)
		len++;
	str = malloc(len * sizeof(char) + sign + 1);

	for(i = 0; i < len; i++)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
	{
		str[i] = '-';
	}

	str[++i] = 0;

	return (_rev(str));
}
