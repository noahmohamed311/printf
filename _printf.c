#include "main.h"
#include <stdlib.h>

/**
 * specifiercheck - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
int (*specifiercheck(const char *format))(va_list)
{
	unsigned int i;
	specifier p[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	/* protect against null format specifier */
	if (!format)
		exit(99);
	for (i = 0; p[i].spec != NULL; i++)
	{
		if (*(p[i].spec) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}

/**
 * _printf - prints anything in string format
 * @format: list of argument types formatted in a string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, length = 0;
	va_list ap;
	int (*f)(va_list);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]), length++;
		}
		if (!format[i])
			return (length);
	if (format[i + 1] == '%')
	{
		_putchar('%');
		i += 2,	length = length + 1;
	}
	else if (format[i + 1] == '\0')
	{
		i++;
		continue;
	}
	else
	{
		f = specifiercheck(&format[i + 1]);
	if (f == NULL)
	{
	_putchar(format[i]), _putchar(format[i + 1]);
	i += 2,	length = length + 2;
	}
	else
	{
	length = length + f(ap), i += 2;
	}}}
va_end(ap);
return (length);
}
