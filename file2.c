#include "main.h"

/**
 * _len - Calculate the length of a string.
 * @ptr: The string to calculate the length of.
 *
 * Return: The length of the string.
 */

int _len(char *ptr)
{
	int i = 0;

	for (; *ptr != '\0'; ptr++)
		i++;

	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(int c)
{
	static int i;
	static char buffer[BUFFER_S];

	if (c == BUFFER_D || i >= BUFFER_S)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUFFER_D)
	{
		buffer[i++] = c;
	}
	return (1);
}

/**
 * print_many_characters - print many characters follow by new line
 * @ptr: pointer to characters
 *
 * Return: (ptr - ptr1)
 */

int print_many_characters(char *ptr)
{
	char *ptr1 = ptr;

	while (*ptr)
	{
		_putchar(*ptr++);
	}

	return (ptr - ptr1);
}


/**
 * print_to_ - Print characters from begin to end, excluding unless.
 *
 * @begin: Pointer to the beginning of the character array.
 * @end: Pointer to the end of the character array.
 * @unless: Pointer to a character that should be excluded from printing.
 *
 * Return: The number of characters printed (excluding unless).
 */

int print_to_(char *begin, char *end, char *unless)
{
	int add = 0;

	for (; begin <= end; begin++)
	{
		if (begin != unless)
		{
			add += _putchar(*begin);
		}
	}

	return (add);
}


/**
 * print_bi - Print a formatted binary number to the standard output.
 * @args: A va_list containing the arguments to be formatted and printed.
 * @pp: A pointer to a pp_p structure containing formatting options.
 *
 * Return: The number of characters printed.
 */

int print_bi(va_list args, pp_p *pp)
{
	unsigned int number = va_arg(args, unsigned int);
	char *ptr = Convert_integers_to_a_string(number, 2,
			CONVERTED_TO_BINARY_U, pp);
	int i = 0;

	if (pp->d && number)
	{
		*--ptr = '0';
	}
	pp->a = 1;
	return (i += print_n(ptr, pp));
}
