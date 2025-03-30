#include "main.h"

/**
 * print_number - Prints an integer using only write
 * @n: Integer to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n / 10)
			print_number(-(n / 10));
		write(1, &"0123456789"[-(n % 10)], 1);
	}
	else
	{
		if (n / 10)
			print_number(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}
