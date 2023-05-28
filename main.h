#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - Struct op
* @fmt: format.
* @fn: The function associated.
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int percent_sign(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int unsgnd_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexadecimal_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexa_upper_notation(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hexa_number(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int _non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],	int flags, int width,
int precision, int size);

int _flags(const char *format, int *i);
int calc_width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int string_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int write_handle(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_address(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_num_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int _printable(char);
int _hexa_code(char, char[], int);
int _digit(char);
long int convert_size_number(long int num, int size);
long int _size_unsgnd(unsigned long int num, int size);
#endif
