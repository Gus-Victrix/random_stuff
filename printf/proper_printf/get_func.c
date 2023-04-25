#include "main.h"

/**
   * get_func - Gets the address of the helper function to handle a case.
   *
   * @format: Format string being printed by _printf.
   * @ptr: Position of the string currently being considered.
   *
   * Return: Address of the required function.
   */

  int (*get_func(const char *format, int *ptr))(const char *, int *, char *,
          unsigned short *, va_list)
  {
      functions function[] = {
          {'%', _percentile},
          {'c', _character},
          {'s', _string},
          {'d', _integer},
          {'i', _integer},
          {'x', _hexadecimal},
          {'X', _upper_hexadecimal},
          {0,0}
      };
      unsigned short i = 0;

      (*ptr)++;
      while (function[i].f)
      {
          if (function[i].c == *(format + *ptr))
              break;
          i++;
      }
      return (function[i].f);
  }
