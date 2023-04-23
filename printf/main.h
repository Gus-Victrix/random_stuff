#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char);

size_t _printf(const char *, ...);

unsigned short _flush(char *, unsigned short *);

size_t _strlen(char *);

size_t _push(char *, size_t, unsigned short *, char *);

size_t percent_handler(const char *, size_t *, char *, unsigned short *, va_list);

unsigned short backslash_handler(const char *, size_t *, char *, unsigned short *, va_list);

char *_rev(char *);

char *num_to_string(size_t, char);

char *int_to_string(int);

char *ints_to_bin(char *);

unsigned int _pow(int,int);

char *from_dec(int, unsigned short);

char *upper(char *);

#endif /*MAIN_H*/
