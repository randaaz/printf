#include "main.h"

/**
 * _unsigned - Print unsigned
 * @args: The va_list
 */
void _unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char size[20];
	int i = 0;

	while (n > 0)
	{
		size[i++] = n % 10 + '0';
		n /= 10;
	}

	while (i > 0)
	{
		_putchar(size[--i]);
	}
}

/**
 * _octal - Print octal
 * @args: The va_list
 */
void _octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char size[20];
	int i = 0;


	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (n > 0)
	{
		size[i++] = (n % 8) + '0';
		n /= 8;
	}

	while (i > 0)
	{
		_putchar(size[--i]);
	}
}

/**
 * _hex_lower - Print lower hexadecimal
 * @args: The va_list
 */
void _hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char size[20];
	int i = 0, re;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (n > 0)
	{
		re = n % 16;
		if (re < 10)
			size[i++] = re + '0';
		else
			size[i++] = re - 10 + 'a';
		n /= 16;
	}

	while (i > 0)
	{
		_putchar(size[--i]);
	}
}

/**
 * _hex_upper - Print upper hex
 * @args: The va_list
 */
void _hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char size[20];
	int i = 0, re;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (n > 0)
	{
		re = n % 16;
		if (re < 10)
			size[i++] = re + '0';
		else
			size[i++] = re - 10 + 'A';
		n /= 16;
	}

	while (i > 0)
	{
		_putchar(size[--i]);
	}
}
