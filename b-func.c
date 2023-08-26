#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    
    while (*format) 
    {
	    if (*format == '%') 
	    {
		    format++;
	
		    if (*format == 'b')
		    {
			    unsigned int num = va_arg(args, unsigned int);
			    unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
			    int printed = 0;
			    
			    for (int i = 0; i < sizeof(unsigned int) * 8; i++) 
			    {
				    putchar((num & mask) ? '1' : '0');
				    printed++;
				    mask >>= 1;
			    }
			    
			    count += printed;
		    }
	    }
	    format++;
    }

    return (count);
}
