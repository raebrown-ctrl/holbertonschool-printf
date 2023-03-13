#include "main.h"
/**
* get_category_functions - function that returns a specifier.
* @cc: compare a character for function.
*Return: if 'cc' is NULL return NULL. If 'cc' is == return specifier.
*/

void (*get_category_functions(char cc))(char *, va_list, int *)
{
	int i = 0;
	specifier type[] = {
		{"c", pr_char},
		{"s", pr_string},
		{"d", pr_decimal},
		{"i", pr_int},
		{NULL, NULL}
	};
	for (; type[i].type != NULL && *(type[i].type) != cc; i++)
		if (type[i].type == NULL)
		{
			return (NULL);
		}
	return (type[i].box);
}

