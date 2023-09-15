#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int j = 0, i;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			j++;
		}
		else if (format[i + 1])
		{
			i++;
			j += _format_specifier(format[i], args);
		}
	}

	va_end(args);
	return (j);
}
