#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

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

/*Helper functions*/
int _percentile(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _character(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _upper_hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _address(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _float(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);
int _integer(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params);



#endif /*MAIN_H*/
