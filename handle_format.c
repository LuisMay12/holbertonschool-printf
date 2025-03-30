#include "main.h"

/**
 * handle_format - Handles format specifier logic
 * @specifier: format character
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int handle_format(char specifier, va_list args)
{
	char *str;
	char c;
	int count = 0;

	switch (specifier)
	{
	case 'c':
		c = va_arg(args, int);
		count += write(1, &c, 1);
		break;
	case 's':
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
			count += write(1, str++, 1);
		break;
	case '%':
		count += write(1, "%", 1);
		break;
	default:
		count += write(1, "%", 1);
		count += write(1, &specifier, 1);
		break;
	}
	return (count);
}
