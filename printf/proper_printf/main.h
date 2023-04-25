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

/*Modifiers*/

/*Helper functions*/
int _float(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _address(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _percentile(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _character(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _upper_hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _integer(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _rot13(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _special_string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _octal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _binary(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _reverse(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);

/*Toolkit*/
char *from_int(long long decimal, unsigned short base);
int _strlen(char *str);
char *_rev(char *string);
char *upper(char *string);
char *show_non_print(char *string);
char *r13(char *string);

#endif /*MAIN_H*/
