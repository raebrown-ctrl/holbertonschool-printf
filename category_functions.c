#include "main.h"
/**
* get_category_functions - function that returns a specifier.
* @cc: compare a character for function.
*Return: if 'cc' is NULL return NULL. If 'cc' is == return specifier.
*/

void (*get_category_functions(char cc))(char *, va_list, int *)
{
	int i = 0;
	specifiers cat[] = {
		{"c", pr_char},
		{"s", pr_string},
		{"d", pr_int},
		{"i", pr_int},
		{NULL, NULL}
	};
	for (; cat[i].cat != NULL && *(cat[i].cat) != cc; i++)
		if (cat[i].cat == NULL)
		{
			return (NULL);
		}
	return (cat[i].box);
}

