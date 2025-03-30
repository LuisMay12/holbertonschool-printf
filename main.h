#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_format(char specifier, va_list args);
void print_number(int n);

#endif /* MAIN_H */
