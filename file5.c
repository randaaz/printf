#include "main.h"

/**
 * _width - Parses and sets the width parameter from a format specifier string.
 *
 * @ptr: A pointer to a format specifier string.
 * @pp: A pointer to a structure containing print parameters.
 * @args: A va_list of arguments (not used).
 *
 * Return: A pointer to the next character in the format specifier string.
 */
char *_width(char *ptr, pp_p *pp, va_list args)
{
	int width = 0;

	if (*ptr == '*')
	{
		width = va_arg(args, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
			width = width * 10 + (*ptr++ - '0');
	}

	pp->g = width;
	return (ptr);
}

/**
 * print_r - Prints a string in reverse order.
 *
 * @args: A va_list of arguments containing the string to print.
 * @pp: A pointer to a structure containing print parameters (unused).
 *
 * Return: The number of characters printed.
 */
int print_r(va_list args, pp_p *pp)
{
	int l = 0, add = 0;
	char *ptr = va_arg(args, char *);

	(void)pp;

	if (ptr)
	{
		while (*ptr)
		{
			l++;
			ptr++;
		}
		ptr--;

		while (l > 0)
		{
			add += _putchar(*ptr);
			l--;
			ptr--;
		}
	}
	return (add);
}

/**
 * print_R - Encode a string using ROT13 and print it.
 * @args: The va_list containing the string to encode.
 * @pp: Unused.
 *
 * Return: The number of characters printed.
 */

int print_R(va_list args, pp_p *pp)
{
	int i;
	int charac_n = 0;
	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *ptr = va_arg(args, char *);

	(void)pp;

	i = 0;
	while (ptr[i])
	{
		char c = ptr[i];

		if (c >= 'A' && c <= 'Z')
		{
			c = array[c - 'A'];
		}
		else if (c >= 'a' && c <= 'z')
		{
			c = array[c - 'a' + 26];
		}

		charac_n += _putchar(c);
		i++;
	}
	return (charac_n);
}

/**
 * _unsigned - Convert an unsigned integer to a string representation.
 * @pp: Pointer to a pp_p structure (not used in this function).
 * @args: A va_list containing the unsigned integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
int _unsigned(va_list args, pp_p *pp)
{
	unsigned long ll;

	if (pp->jj)
		ll = (unsigned long) va_arg(args, unsigned long);
	else if (pp->ii)
		ll = (unsigned short int) va_arg(args, unsigned int);
	else
		ll = (unsigned int) va_arg(args, unsigned int);
	pp->a = 1;
	return (print_n(Convert_integers_to_a_string(ll, 10,
					CONVERTED_TO_BINARY_U, pp), pp));
}

/**
 * _rubric - Convert an unsigned long integer to a hexadecimal string.
 * @args: A va_list containing the unsigned long integer to convert.
 * @pp: Pointer to a pp_p structure (not used in this function).
 *
 * Return: A pointer to the resulting string.
 */
int _rubric(va_list args, pp_p *pp)
{
	unsigned long int number = va_arg(args, unsigned long int);
	char *ptr;

	if (!number)
		return (print_many_characters("(nil)"));

	ptr = Convert_integers_to_a_string(number, 16,
			CONVERTED_TO_BINARY_U | CONVERTED_TO_BINARY_L, pp);
	*--ptr = 'x';
	*--ptr = '0';
	return (print_n(ptr, pp));
}
