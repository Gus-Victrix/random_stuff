#include "main.h"

/**                                                                             
   * _flush - Flushes a buffer of specified size.                                 
   *                                                                              
   * @buffer: Character buffer to be flushed.                                     
   * @index: Index to which the buffer is filled.                                 
   *                                                                              
   * Return: Number of printed characters.                                        
   */                                                                             
                                                                                  
  unsigned short _flush(char *buffer, unsigned short *index)                      
  {                                                                               
      unsigned short i = 0;                                                       
                                                                                  
      i = *index;                                                                 
      write(1, buffer, *index);                                                   
      *index = 0;                                                                 
                                                                                  
      return (i);                                                                 
  }  
