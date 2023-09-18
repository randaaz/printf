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
	int j = 0;
	char *p, *begin;
	pp_p  pp = I_PP_P;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *) format; *p; p++)
	{
		ppp(&pp, args);
		if (*p != '%')
		{
			j += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		while (_flag(p, &pp))
		{
			p++;
		}
		p = _width(p, &pp, args);
		p = _precision(p, &pp, args);
		if (_modifier(p, &pp))
			p++;
		if (!_format_specifier(p))
			j += print_to_(begin, p,
					pp.ii || pp.jj ? p - 1 : 0);
		else
			j +=  _printf_func(p, args, &pp);
	}
	_putchar(BUFFER_D);
	va_end(args);
	return (j);
}
