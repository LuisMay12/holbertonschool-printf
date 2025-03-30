#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: Character string with format specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
