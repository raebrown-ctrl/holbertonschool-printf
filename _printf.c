<<<<<<< HEAD
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - recreation of printf to find certain specifiers
 * Description: Funtion that prints string format.
 *
 * @format: arguments function
 * Return: an int len of string to '\0'
 */

int _printf(const char *format, ...)
{
	int i = 0, bf_count = 0;
	char *buffer = NULL;
	void (*category_functions)(char *, va_list, int *);
	va_list args;

	va_start(args, format), buffer = malloc(sizeof(char) * 2048);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;

			category_functions = get_category_functions(format[i + 1]);
			if (category_functions == NULL)
			{
				buffer[bf_count] = format[i];

				if (format[i + 1] != '%')
				{
					buffer[bf_count + 1] = format[i + 1];
					bf_count += 2;
				}
				else
					bf_count++;
			}
			else
				category_functions(buffer, args, &bf_count);
			i++;
			continue;
		}
		buffer[bf_count] = format[i];
		bf_count++;
	}
	va_end(args), write(1, buffer, bf_count), free(buffer);
	return (bf_count);
=======
#include "main.h"
/**
* _printf - prints the formatted string to std output
@format: input to be printed
* Return - The number of the characters that were printed.
*/
int _printf(const char *format, ...)
{
	int i = 0, k = 0;
	int n_displayed = 0;
	char *str = NULL;
	va_list args;
	int (*func)(va_list);

	va_start(args, format);

	while (format[i] != '\0')
	{	
		if (format[i] != '%')
		{
		_putchar(format[i]);
		n_displayed++;
		}
		else if (format[i + 1] == '%')
		{
			i++;
			_putchar('%');
			n_displayed++;
		}
		else
		{
			func = _selec_func(format[i + 1]);
			if (func != NULL)
			{
				n_displayed += func(args);
				i++;
			}
		}

		i++;
	}

	va_end(args);
	return (n_displayed);
>>>>>>> b16ea61e9d3284d06eb508562e9039e558525590
}
