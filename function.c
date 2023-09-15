#include "main.h"

/**
 * print_character - Print a character
 * @args: The va_list containing the character to print
 */
void print_character(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 */
void print_string(va_list args)
{
	char *ptr = va_arg(args, char *);

	if (ptr == NULL)
		ptr = "(null)";

	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
}

/**
 * print_percent - Print a percent character
 * @args: Unused
 */
void print_percent(va_list args)
{
	(void)args;
	_putchar('%');
}

/**
 * _format_specifier - Processes and prints format specifiers.
 * @specifier: The format specifier character.
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */

int _format_specifier(char specifier, va_list args)
{
	int j;

	rr_s specifiers[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_intger},
		{'i', print_intger},
		{'u', _unsigned},
		{'o', _octal},
		{'x', _hex_lower},
		{'X', _hex_upper},
		{0, 0}
	};

	for (j = 0; specifiers[j].rr; j++)
	{
		if (specifier == specifiers[j].rr)
		{
			specifiers[j].ss(args);
			return (1);
		}
	}
	return (0);
}
