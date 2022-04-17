#include "main.h"

/**
 * print_int - prints an integer
 * @i: integer to print
 *
 * Return: number of chars and digits printed
 */
int print_int(va_list i)
{
	int f = va_arg(i, int);
	unsigned int length = 0, modulo = 1;
	/*putchars a '-' for negative numbers*/

	if (f < 0)
	{
		_putchar('-');
		f = f * -1;
		length++;
	}
	/*printing 1 int at a time with putchar?*/

	while ((f / modulo) >= 10)
	{
		modulo = modulo * 10;
	}
	while (modulo >= 1)
	{
		_putchar((f / modulo) + '0');
		f = f % modulo;
		modulo = modulo / 10;
		length++;
	}
	return (length);
}

/**
 * print_char - prints a character with _putchar to stdout.
 * @c: character to print
 *
 * Return: always 1
 */

int print_char(va_list c)
{
	/* protect against null character */
	if (!c)
		exit(1);
	_putchar((char)va_arg(c, int));
	return (1);
}

/**
 * print_string - prints a string of characters
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list s)
{
	int length;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (length = 0; str[length]; length++)
	{
		_putchar(str[length]);
	}
	return (length);
}
