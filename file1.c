#include "main.h"

/**
 * Convert_integers_to_a_string - Convert a
 * long integer to a string representation in a specified base.
 * @numb: The long integer to convert
 * @foundation: The base to convert the integer to
 * @fls: Flags for formatting (e.g., lowercase hexadecimal).
 * @pp: Pointer to a struct (not used in this function).
 *
 * Return: A pointer to the resulting string.
 */

char *Convert_integers_to_a_string(long int numb,
		int foundation, int fls, pp_p *pp)
{
	static char buffer[50];
	char *r;
	char mark = 0;
	char *ptr;
	unsigned long number = numb;
	(void)pp;

	if (!(fls & CONVERTED_TO_BINARY_U) && numb < 0)
	{
		number = -numb;
		mark = '-';
	}

	r = fls & CONVERTED_TO_BINARY_L ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = r[number % foundation];
		number /= foundation;
	} while (number != 0);

	if (mark)
		*--ptr = mark;
	return (ptr);
}



/**
 * print_n - Format a string with specified width and flags
 * @ptr: The string to format.
 * @pp: Pointer to a pp_p structure
 *
 * Return: The number of characters printed
 */

int print_n(char *ptr, pp_p *pp)
{
	unsigned int j = _len(ptr);
	int negeteve = (!pp->a && *ptr == '-');

	if (!pp->h && *ptr == '0' && !ptr[1])
		ptr = "";
	if (negeteve)
	{
		ptr++;
		j--;
	}
	if (pp->h != UINT_MAX)
		while (j++ < pp->h)
			*--ptr = '0';
	if (negeteve)
		*--ptr = '-';

	if (!pp->f)
		return (print_n_r(ptr, pp));
	else
		return (print_n_l(ptr, pp));
}


/**
 * print_n_r - Print a formatted string to the standard output (right-aligned).
 * @ptr: A pointer to the string to be printed.
 * @pp: A pointer to a pp_p structure containing
 * formatting options (not used here).
 *
 * Return: The number of characters printed.
 */
int print_n_r(char *ptr, pp_p *pp)
{
	unsigned int jj = 0, negeteve, negeteve1, j = _len(ptr);
	char x = ' ';

	if (pp->e && !pp->f)
		x = '0';
	negeteve = negeteve1 = (!pp->a && *ptr == '-');
	if (negeteve && j < pp->g && x == '0' && !pp->f)
		ptr++;
	else
		negeteve = 0;
	if ((pp->b && !negeteve1) || (!pp->b && pp->c && !negeteve1))
		j++;
	if (negeteve && x == '0')
		jj += _putchar('-');
	if (pp->b && !negeteve1 && x == '0' && !pp->a)
		jj += _putchar('+');
	else if (!pp->b && pp->c && !negeteve1 &&
			!pp->a && pp->e)
		jj += _putchar(' ');
	while (j++ < pp->g)
		jj += _putchar(x);
	if (negeteve && x == ' ')
		jj += _putchar('-');
	if (pp->b && !negeteve1 && x == ' ' && !pp->a)
		jj += _putchar('+');
	else if (!pp->b && pp->c && !negeteve1 &&
			!pp->a && !pp->e)
		jj += _putchar(' ');
	jj += print_many_characters(ptr);
	return (jj);
}


/**
 * print_n_l - Print a formatted string to the standard output (left-aligned).
 * @ptr: A pointer to the string to be printed.
 * @pp: A pointer to a pp_p structure
 * containing formatting options (not used here).
 *
 * Return: The number of characters printed.
 */

int print_n_l(char *ptr, pp_p *pp)
{
	unsigned int jj = 0, negeteve, negeteve1, j = _len(ptr);
	char x = ' ';

	if (pp->e && !pp->f)
		x = '0';
	negeteve = negeteve1 = (!pp->a && *ptr == '-');
	if (negeteve && j < pp->g && x == '0' && !pp->f)
		ptr++;
	else
		negeteve = 0;
	if (pp->b && !negeteve1 && !pp->a)
		jj += _putchar('+'), j++;
	else if (pp->c && !negeteve1 && !pp->a)
		jj += _putchar(' '), j++;
	jj += print_many_characters(ptr);
	while (j++ < pp->g)
		jj += _putchar(x);
	return (jj);
}


/**
 * _isdigit - Check if a character is a digit.
 * @n: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */

int _isdigit(int n)
{
	return (n >= '0' && n <= '9');
}
