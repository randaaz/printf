#include "main.h"

/**
 * print_intger - print intger numbers
 * @args: The va_list containing the character to print
 */

void print_intger(va_list args)
{
	int number = va_arg(args, int);
	char size[20];
	int i = 0;

	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}

	while (number > 0)
	{
		size[i++] = number % 10 + '0';
		number /= 10;
	}

	while (i > 0)
	{
		_putchar(size[--i]);
	}
}
