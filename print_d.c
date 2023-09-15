#include "main.h"

/**
 * print_intger - print intger numbers
 * @args: The va_list containing the intger to print
 */

void print_intger(va_list args)
{
	int number = va_arg(args, int);
	char size[20];
	int i = 0;

	if (number == 0)
	{
		_putchar('0');
		return;

	}
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


/**
 * converted_to_binary - Converts an unsigned int
 * number to binary and prints it.
 * @args: The va_list containing the intger to  converted
 */
void converted_to_binary(va_list args)
{
	int j, i = 0, a[32];
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (n > 0)
	{
		a[i] = n % 2;
		i++;
		n /= 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(a[j] + '0');
	}
}
