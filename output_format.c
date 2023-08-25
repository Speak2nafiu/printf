#include <stdio.h>
#include <stdarg.h>
/**
 *_printf - prints output format
 *format: pointer to the file
 *Return: the number of characters priint _printf(const char *format, ...)
 */

int _printf(const char *format, ...)
{
	va_list args;
	
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			char specifier = *format;

			switch (specifier)
			{
				case 'c':
					{
						int c = va_arg(args, int);
						
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						const char *s = va_arg(args, const char *);
						
						while (*s != '\0')
						{
							putchar(*s);
							s++;
							count++;
						}

						break;
					}
				case '%':
					{
						putchar('%');
						count++;

						break;
					}
			}
		}

		else
		{
			putchar(*format);
			count++;
		}

		format++;

	}

	va_end(args);

	return (count);
}
