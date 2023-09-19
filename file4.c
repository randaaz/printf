#include "main.h"

/**
 * _modifier - Modifies print parameters based on a format modifier
 *
 * @s: A pointer to a format modifier string.
 * @pp: A pointer to a structure containing print parameters to modify.
 *
 * Return: 1 if a modification is made, 0 otherwise.
 */

int _modifier(char *s, pp_p *pp)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = pp->ii = 1;
			break;
		case 'l':
			i = pp->jj = 1;
			break;
	}
	return (i);
}

/**
 * print_character - Prints a character with padding if required.
 *
 * @args: A va_list of arguments containing the character to print.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed.
 */

int print_character(va_list args, pp_p *pp)
{
	char c = ' ';
	unsigned int xx = 1, i = 0, cc = va_arg(args, int);

	if (pp->f)
		i += _putchar(cc);
	while (xx++ < pp->g)
		i += _putchar(c);
	if (!pp->f)
		i += _putchar(cc);
	return (i);
}

/**
 * print_integer - Print an integer with optional padding.
 * @args: A va_list containing the arguments to be formatted and printed.
 * @pp: A pointer to a pp_p structure containing formatting options.
 *
 * Return: The number of characters printed.
 */

int print_integer(va_list args, pp_p *pp)
{
	long ll;

	if (pp->jj)
		ll = va_arg(args, long);
	else if (pp->ii)
		ll = (short int)va_arg(args, int);
	else
		ll = (int)va_arg(args, int);

	return (print_n(Convert_integers_to_a_string(ll, 10, 0, pp), pp));
}

/**
 * print_string - Prints a string with padding if required.
 *
 * @args: A va_list of arguments containing the string to print.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list args, pp_p *pp)
{
	char *ptr = va_arg(args, char *), c = ' ';
	unsigned int cc = 0, add = 0, i = 0, j;

	(void)pp;
	switch ((int)(!ptr))
	case 1:
		ptr = NULL_S;

		j = cc = _len(ptr);
		if (pp->h < cc)
			j = cc = pp->h;

		if (pp->f)
		{
			if (pp->h != UINT_MAX)
				for (i = 0; i < cc; i++)
					add += _putchar(*ptr++);
			else
				add += print_many_characters(ptr);
		}
		while (j++ < pp->g)
			add += _putchar(c);
		if (!pp->f)
		{
			if (pp->h != UINT_MAX)
				for (i = 0; i < cc; i++)
					add += _putchar(*ptr++);
			else
				add += print_many_characters(ptr);
		}
		return (add);
}

/**
 * print_per - Prints a percent sign.
 *
 * @args: A va_list of arguments (not used).
 * @pp: A pointer to a structure containing print parameters (not used).
 *
 * Return: The number of characters printed (1 for '%').
 */

int print_per(va_list args, pp_p *pp)
{
	(void)args;
	(void)pp;
	return (_putchar('%'));
}
