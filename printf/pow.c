#include "main.h"

/**
 * _pow - Raises base to the power of index.
 *
 * @base: Input to be raised to a certain power.
 * @index: Input to be used as power.
 *
 * Return: base ^ index.
 */

unsigned int _pow(int base, int index)
{
	unsigned int ans = 1;

	while (index)
	{
		ans *= base;
		index--;
	}
	return (ans);
}
