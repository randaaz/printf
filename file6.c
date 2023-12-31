#include "main.h"

/**
 * print_h - Prints an integer in hexadecimal format with padding if required.
 *
 * @args: A va_list containing the integer to print.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed.
 */

int print_h(va_list args, pp_p *pp)
{
	unsigned long ll;
	int i = 0;
	char *ptr;

	if (pp->jj)
		ll = (unsigned long) va_arg(args, unsigned long);
	else if (pp->ii)
		ll = (unsigned short int) va_arg(args, unsigned int);
	else
		ll = (unsigned int) va_arg(args, unsigned int);

	ptr = Convert_integers_to_a_string(ll, 16, CONVERTED_TO_BINARY_U |
			CONVERTED_TO_BINARY_L, pp);
	if (pp->d && ll)
	{
		*--ptr = 'x';
		*--ptr = '0';
	}
	pp->a = 1;
	return (i += print_n(ptr, pp));
}

/**
 * print_H - Prints an integer in hexadecimal
 * format with padding if required (uppercase).
 *
 * @args: A va_list containing the integer to print.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed.
 */

int print_H(va_list args, pp_p *pp)
{
	unsigned long ll;
	int i = 0;
	char *ptr;

	if (pp->jj)
		ll = (unsigned long) va_arg(args, unsigned long);
	else if (pp->ii)
		ll = (unsigned short int) va_arg(args, unsigned int);
	else
		ll = (unsigned int) va_arg(args, unsigned int);

	ptr = Convert_integers_to_a_string(ll, 16, CONVERTED_TO_BINARY_U, pp);
	if (pp->d && ll)
	{
		*--ptr = 'X';
		*--ptr = '0';
	}
	pp->a = 1;
	return (i += print_n(ptr, pp));
}

/**
 * print_o - Prints an integer in octal format with padding if required.
 *
 * @args: A va_list containing the integer to print.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed.
 */
int print_o(va_list args, pp_p *pp)
{
	unsigned long ll;
	int i = 0;
	char *ptr;

	if (pp->jj)
		ll = (unsigned long) va_arg(args, unsigned long);
	else if (pp->ii)
		ll = (unsigned short int) va_arg(args, unsigned int);
	else
		ll = (unsigned int) va_arg(args, unsigned int);

	ptr = Convert_integers_to_a_string(ll, 8, CONVERTED_TO_BINARY_U, pp);
	if (pp->d && ll)
	{
		*--ptr = '0';
	}
	pp->a = 1;
	return (i += print_n(ptr, pp));
}

/**
 * print_S - Prints a string with non-printable characters escaped as '\xHH'.
 *
 * @args: A va_list containing the string to print.
 * @pp: A pointer to a structure containing print parameters (unused).
 *
 * Return: The number of characters printed.
 */

int print_S(va_list args, pp_p *pp)
{
	char *ptr = va_arg(args, char *);
	char *h;
	int add = 0;

	if ((int)(!ptr))
		return (print_many_characters(NULL_S));
	for (; *ptr; ptr++)
	{
		if ((*ptr > 0 && *ptr < 32) || *ptr >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			h = Convert_integers_to_a_string(*ptr, 16, 0, pp);
			if (!h[1])
				add += _putchar('0');
			add += print_many_characters(h);
		}
		else
		{
			add += _putchar(*ptr);
		}
	}
	return (add);
}
