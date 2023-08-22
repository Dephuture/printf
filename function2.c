#include "main.h"
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
