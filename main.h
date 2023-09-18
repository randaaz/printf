#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


/**
 * struct rr - holding format specifiers and functions
 * @rr: format specifier (char)
 * @ss: pointer to a function taking va_list as argument
 */

typedef struct rr
{
	char rr;
	void (*ss)(va_list);
} rr_s;

int _putchar(char c);
int _printf(const char *format, ...);
void print_character(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_intger(va_list args);
void _unsigned(va_list args);
void _octal(va_list args);
void _hex_lower(va_list args);
void _hex_upper(va_list args);
void converted_to_binary(va_list args);
int _format_specifier(char specifier, va_list args);

#endif
