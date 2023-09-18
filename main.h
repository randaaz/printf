#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define NULL_S "(null)"

#define BUFFER_S 1024
#define BUFFER_D -1

#define CONVERTED_TO_BINARY_L 1
#define CONVERTED_TO_BINARY_U 2

#define I_PP_P {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct pp_p - holding format specifiers as bitfields
 * @a: First specifier (unsigned int)
 * @b: Second specifier (unsigned int)
 * @c: Third specifier (unsigned int)
 * @d: Fourth specifier (unsigned int)
 * @e: Fifth specifier (unsigned int)
 * @f: Sixth specifier (unsigned int)
 * @g: Seventh specifier (unsigned int)
 * @h: Eighth specifier (unsigned int)
 * @ii: Ninth specifier (unsigned int)
 * @jj: Tenth specifier (unsigned int)
 */
typedef struct pp
{
	unsigned int a    : 1;
	unsigned int b    : 1;
	unsigned int c    : 1;
	unsigned int d    : 1;
	unsigned int e    : 1;
	unsigned int f    : 1;
	unsigned int g;
	unsigned int h;
	unsigned int ii   : 1;
	unsigned int jj   : 1;
	int precision;
} pp_p;

/**
 * struct rr_s - holding format specifiers and functions
 * @rr: format specifier (char)
 * @ss: pointer to a function taking va_list as argument
 */
typedef struct rr
{
	char *rr;
	int  (*ss)(va_list, pp_p *);
} rr_s;

char *Convert_integers_to_a_string(long int numb, int foundation, int fls, pp_p *pp);
int _isdigit(int n);
int _len (char *ptr);
int print_n(char *ptr, pp_p *pp);
int print_n_r(char *ptr, pp_p *pp);
int print_n_l(char *ptr, pp_p *pp);
int _putchar(int c);
int print_many_characters(char *ptr);
int print_to_(char *begin, char *end, char *unless);
int print_bi(va_list args, pp_p *pp);
int (*_format_specifier(char *ptr))(va_list args, pp_p *pp);
int _printf_func(char *ptr, va_list args, pp_p *p);
int _flag(char *ptr, pp_p *p);
char *_precision(char *p, pp_p *pp, va_list args);
void ppp(pp_p *pp, va_list args);
int print_character(va_list args, pp_p *pp);
int print_integer(va_list args, pp_p *pp);
int print_string(va_list args, pp_p *pp);
int print_per(va_list args, pp_p *pp);
int _printf(const char *format, ...);
int _modifier(char *s, pp_p *pp);
char *_width(char *ptr, pp_p *pp, va_list args);
int print_r(va_list args, pp_p *pp);
int print_R(va_list args, pp_p *pp);
int _unsigned(va_list args, pp_p *pp);
int _rubric(va_list args, pp_p *pp);
int print_h(va_list args, pp_p *pp);
int print_H(va_list args, pp_p *pp);
int print_o(va_list args, pp_p *pp);
int print_S(va_list args, pp_p *pp);

#endif
