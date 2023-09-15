#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct rr - holding format specifiers and functions
 * @rr: format specifier
 * @ss: pointer
 */

typedef struct rr
{
	char *rr;
	void (*ss)(char *, va_list);
} rr_s;

int _putchar(char c);
void print_many_characters(const char *ptr);



#endif
