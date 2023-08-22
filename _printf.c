#include "main.h"
/**
 * _printf - functiion to clone the standard printf_function
 * @format: takes a variadic input
 * Return: return (-1) for failure
 */
int _printf(const char *format, ...)
{
	int printchar = 0;
	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printchar++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(arg_list, int);

					write(1, &c, 1);
					printchar++;
					break;
				}
				case '%':
				{
					write(1, format, 1);
					printchar++;
					break;
				}
				case 's':
				{
					char *s = va_arg(arg_list, char*);

					int strlen = 0;

					while (s[strlen] != '\0')
					strlen++;
					write(1, s, strlen);
					printchar += strlen;
					break;
				}
			}
		}
		format++;
	}
	va_end(arg_list);
	return (printchar);
}
/**
 * _printf - functiion to clone the standard printf_function
 * @format: takes a variadic input
 * Return: return (-1) for failure
 */
int _printf1(const char *format, ...)
{
        va_list args;
        int wr;

        va_start(args, format);
        wr = 0;
        while (*format)
        {
                if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
                {
                        int num = va_arg(args, int);

                        wr += _putint(num);
                        format += 2;
                }
                else
                {
                        _putchar(*format);
                        wr++;
                        format++;
                }
        }
        va_end(args);
        return (wr);
}
