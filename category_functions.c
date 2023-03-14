#include "main.h"
/**
<<<<<<< HEAD
* pr_char - handle specific char 'c' from
* list of args
*
* Description: Function that returns a character.
*
* @buffer: points to memory location where
* output is stored
*
* @args: Arguments
*
* @bf_count: Pointer to an integer that
* keeps track of current position of the buffer.
*/
void pr_char(char *buffer, va_list args, int *bf_count)
{
	char c;

	c = (char)va_arg(args, int);
	buffer[*bf_count] = c;
	(*bf_count)++;
}

/**
* pr_string- takes specific character 's' from
* list of args
*
* Description: Function that returns a character.
*
* @buffer: points to memory location where
* output is stored.
* @args: Arguments
*
*@bf_count: Pointer to an integer that keeps track of current position of the
* buffer.
*/
void pr_string(char *buffer, va_list args, int *bf_count)
{
	int i;
	char *cc = NULL;

	cc = va_arg(args, char *);

	if (cc == NULL)
		cc = "(null)";
	for (i = 0; ch[i] != '\0'; i++)
	{
		buffer[*bf_count] = cc[i];
		(*bf_count)++;
	}
}
/**
* pr_int - takes specific charcter 'i' and 'd' from list of args
*
* Description: Function that returns a character.
*
*@buffer: points to memory location where output is stored
*
*@args: Arguments
*
* @bf_count: Pointer to an integer that keeps track of current position of the
* buffer.
*/
void pr_int(char *buffer, va_list args, int *bf_count)
{
	int arg, temp_arg, temp_num, num = 0, digits[15];

	arg = temp_arg = (int)va_arg(args, int);
	if (arg == 0)
	{
		buffer[*bf_count] = 48;
		(*bf_count)++;
	}
	if (arg > 0)
	{
		while (arg != 0)
		{
			temp_arg = arg % 10;
			arg /= 10;
			digits[num] = temp_arg;
			num++;
		}
	}
	else if (arg < 0)
	{
		buffer[*bf_count] = '-';
		(*bf_count)++
		while (arg != 0)
		{
			temp_num = arg % 10 * -1;
			digits[num] = temp_num;
			arg /= 10;
			num++;
		}
	}
	num--;
	while (num >= 0)
	{
		buffer[*bf_count] = digits[num] + '0';
		(*bf_count)++;
		num--;
	}
}
=======
* get_category_functions - function that returns a specifier.
* @cc: compare a character for function.
*Return: if 'cc' is NULL return NULL. If 'cc' is == return specifier.
*/

void (*get_category_functions(char cc))(char *, va_list, int *)
{
	int i = 0;
	specifiers type[] = {
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

>>>>>>> master
