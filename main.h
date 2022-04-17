#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print - structure for printing various types
 * @spec: to print
 * @f: print function
 */

typedef struct print
{
	char *spec;
	int (*f)(va_list);
} specifier;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);

#endif /* _MAIN_H_ */
