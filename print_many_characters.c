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
	static int i;
	static char buffer[BUFFER_s];

	if (c == BUFFER_D || i >= BUFFER_s)
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
 * print_many_characters - Prints many characters followed by a new line.
 * @ptr: Pointer to characters.
 *
 * Return: The number of characters printed.
 */

int print_many_characters(const char *ptr)
{
	int count = 0, i;

	for (i = 0; ptr[i] != '\0'; i++)
	{
		_putchar(ptr[i]);
		count++;
	}

	return (count);
}
