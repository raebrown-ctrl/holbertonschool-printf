#include "main.h"

/**
* _printf - writes the character c to stdout
* @format: check for data type
* Return: Always 0
*/

int _printf(const char *format, ...)
{
	int printed_chars;
	convert_t f_list[] = {
	{"c", pr_char},
	{"s", pr_string},
	{"%", pr_percent},
	{"d", pr_decimal},
	{"i", pr_int},
													};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
