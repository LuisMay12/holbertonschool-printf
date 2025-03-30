#include "main.h"

/**
 * handle_integer - Handles printing of integers
 * @num: integer to print
 *
 * Return: number of characters printed
 */
int handle_integer(int num)
{
	int count = 0, temp = num;

	print_number(num);
	if (temp == 0)
		count = 1;
	else
	{
		if (temp < 0)
		{
			temp = -temp;
			count++;
		}
		while (temp)
		{
			temp /= 10;
			count++;
		}
	}
	return (count);
}

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

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (specifier == 's')
	{
		int count = 0;

		str = va_arg(args, char *);

		if (!str)
			str = "(null)";
		while (*str)
			count += write(1, str++, 1);
		return (count);
	}
	else if (specifier == '%')
	{
		return (write(1, "%", 1));
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		return (handle_integer(va_arg(args, int)));
	}
	else
	{
		int count = 0;

		count += write(1, "%", 1);
		count += write(1, &specifier, 1);
		return (count);
	}
}
