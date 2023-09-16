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
	int characters_printed = 0;
	int specifier_chars_printed;
	va_list args;

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			characters_printed++;
		}
		else
		{
			format++;
			if (*format)
			{
				specifier_chars_printed = _format_specifier(*format, args);
				if (specifier_chars_printed < 0)
					return (-1);
				characters_printed += specifier_chars_printed;
			}
			else
			{
				va_end(args);
				return (-1);
			}
		}
		format++;
	}

	va_end(args);
	return (characters_printed);
}
