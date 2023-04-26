#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/*main functions*/
int _printf(const char *format, ...);
unsigned short _flush(char *buffer, unsigned short *index);
int _push(char *str, int num, unsigned short *index, char *buffer);
int (*get_func(const char *format, int *ptr))(const char *format, int *ptr, char
		*buffer, unsigned short *index, va_list params);

/*structure used*/
typedef struct func_stores {
	char c;
	int (*f)(const char *format, int *ptr, char *buffer, unsigned short *index,
			va_list params);
} functions;

/*Modifiers of buffer*/
char *buff_shift(char *buffer, unsigned short *index, short shiftwidth,
		short group_size);
void buff_replace(char *mod_pos, short mod_width, char padding);
void pad_mgr(char *buffer, unsigned short *index, unsigned short initial,
		char direction, char padding, unsigned short pad_size);


/*Helper functions*/
int _special_padding(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _short(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _precision(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _long(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _float(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _address(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _percentile(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _character(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _upper_hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _integer(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _unsinged(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _rot13(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _special_string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _octal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _binary(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _reverse(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _padding(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);


/*Toolkit*/
char *from_int(long long decimal, unsigned short base);
char *from_unsigned(size_t decimal, unsigned short base);
int _strlen(char *str);
char *_rev(char *string);
char *upper(char *string);
char *show_non_print(char *string);
char *r13(char *string);
void _truncate(unsigned short position, int precision, unsigned short *index,
		char *buffer);
unsigned short _buffseek(char *buffer, unsigned short position, unsigned short
		*index, char c);
int _atoi(char *);

#endif /*MAIN_H*/
