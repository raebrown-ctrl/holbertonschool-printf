#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.>
#include <stdlib.h>
/* prototypes */

int _printf(const char *format, ...);
int _putchar(char c);
int pr_string(va_list args);
int pr_char(va_list args);
int pr_int(va_list args);
int pr_decimal(va_list args);
int pr_percent(va_list args);
int (*_select_func(char c))(va_list);

#endif

