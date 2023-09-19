#include "main.h"

/**
 * _format_specifier - Selects the appropriate printing
 * function based on a format specifier.
 *
 * @ptr: A pointer to a format specifier character.
 * Return: A pointer to the corresponding
 * printing function, or NULL if not found.
 */


int (*_format_specifier(char *ptr))(va_list args, pp_p * pp)
{
	rr_s specifiers[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_per},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_bi},
		{"u", _unsigned},
		{"o", print_o},
		{"x", print_h},
		{"X", print_H},
		{"p", _rubric},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	int i;

	for (i = 0; specifiers[i].rr; i++)
	{
		if (*ptr == specifiers[i].rr[0])
		{
			return (specifiers[i].ss);
		}
	}

	return (NULL);
}

/**
 * _printf_func - Selects and executes the appropriate printing
 * function based on a format specifier.
 *
 * @ptr: A pointer to a format specifier character.
 * @args: A va_list of arguments to be printed.
 * @pp: A pointer to a structure containing print parameters.
 *
 * Return: The number of characters printed,
 * or 0 if no valid format specifier is found.
 */
int _printf_func(char *ptr, va_list args, pp_p *pp)
{
	int (*ss)(va_list, pp_p *) = _format_specifier(ptr);

	if (ss)
		return (ss(args, pp));
	return (0);
}

/**
 *  _flag - Parses and sets format flags from a format specifier string.
 *
 * @ptr: A pointer to a format specifier string.
 * @pp: A pointer to a structure containing print parameters to set flags in.
 *
 * Return: 1 if a flag is set, 0 otherwise.
 */

int _flag(char *ptr, pp_p *pp)
{
	int j = 0;

	if (*ptr == '+')
	{
		j = pp->b = 1;
	}
	else if (*ptr == ' ')
	{
		j = pp->c = 1;
	}
	else if (*ptr == '#')
	{
		j = pp->d = 1;
	}
	else if (*ptr == '-')
	{
		j = pp->f = 1;
	}
	else if (*ptr == '0')
	{
		j = pp->e = 1;
	}

	return (j);
}

/**
 * _precision - Parses the precision field from a
 * format specifier string.
 *
 * @p: A pointer to a format specifier string.
 * @pp: A pointer to a structure containing print parameters.
 * @args: A va_list of arguments used for parsing dynamic precision.
 *
 * Return: A pointer to the next character in the format specifier string.
 */

char *_precision(char *p, pp_p *pp, va_list args)
{
	int width = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		width = va_arg(args, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			width = width * 10 + (*p++ - '0');
	}
	pp->ii = width;
	return (p);
}

/**
 * ppp - Initialize a pp_p struct
 * @pp: A pointer to the pp_p struct to initialize
 * @args: Unused (va_list)
 */
void ppp(pp_p *pp, va_list args)
{
	(void)args;

	pp->a = 0;
	pp->b = 0;
	pp->c = 0;
	pp->d = 0;
	pp->e = 0;
	pp->f = 0;
	pp->g = 0;
	pp->h = UINT_MAX;
	pp->ii = 0;
	pp->jj = 0;
}
