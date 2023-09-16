#include "main.h"

/**
 * _print - Custom printf function.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	int j = 0, i;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
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
