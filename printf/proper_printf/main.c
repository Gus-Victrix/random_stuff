#include "main.h"

/**
 * main - Comparing printf() and _printf()
 *
 * @argc: Number of commandline arguments.
 * @argv: Array of commandline arguments.
 *
 * Return: 0.
 */

int main(const int argc, const char **argv)
{
	short i = 0;

	while (i < argc)
	{
		printf("Handling simple string");
		_printf("Handling simple string");
		if (**argv == 'c')
		{
			printf("Handling a character: %c", 'c');
			_printf("Handling a character: %c", 'c');
		}
		if (**argv == 's')
		{
			printf("Handling a string: %s", "This is a string");
			_printf("Handling a string: %s", "This is a string");
		}
		if (**argv == '%')
		{
			printf("Handling a percent: %%");
			_printf("Handling a percent: %%");
		}
		if (**argv == 'd')
		{
			printf("Handling d as an integer: %d", 14);
			_printf("Handling d as an integer: %d", 14);
		}
		if (**argv == 'i')
		{
			printf("Handling i as an integer: %i", 14);
			_printf("Handling i as an integer: %i", 14);
		}
		if (**argv == 'x')
		{
			printf("Handling x as a hexadecimal: %x", 14);
			_printf("Handling x as a hexadecimal: %x", 14);
		}
		if (**argv == 'X')
		{
			printf("Handling X as a capitalized hexadecimal: %X", 14);
			_printf("Handling X as a capitalized hexadecimal: %X", 14);
		}
		if (**argv == 'f')
		{
			printf("Handling f as a floating point number: %f", 1.234567);
			_printf("Handling f as a floating point number: %f", 1.234567);
		}
		if (**argv == 'p')
		{
			printf("Handling p as an address: %p", &i);
			_printf("Handling p as an address: %p", &i);
		}
		(*argv)++, i++;
	}
	return (0);
}
