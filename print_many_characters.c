#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_many_characters - print many characters follow by new line
 * @ptr: pointer to characters
 */

void print_many_characters(const char *ptr)
{
	int i;

	for (i = 0; ptr[i] != '\0'; i++)
	{
		_putchar(ptr[i]);
	}
	_putchar('\n');
}
