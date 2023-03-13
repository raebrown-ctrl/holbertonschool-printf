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
}
