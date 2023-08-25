#include <stdio.h>
#include <stdarg.h>
/**
 *_printf - prints output format
 *format: pointer to the file
 *Return: the number of characters priint _printf(const char *format, ...)
 */

int _printf(const char *format, ...)
{
	int count = 0;

	char specifier;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;

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

				case 'i':
					{
						int number = va_arg(args, int );
						printf("%i", number);
						count++;
						break;

					}
				case 'd':
					{
						double number2 = va_arg(args, double);
						printf("%d",number2);
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
