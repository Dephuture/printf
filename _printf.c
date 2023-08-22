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
	char buffer[BUFFER_SIZE];


	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printchar++;
		}
		else if (*format == '%')
		{
			format++;
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
				case 'd':
				case 'i':
						int num = va_arg(arg_list, int);
						int len = 0;
						if (num == 0) {
							buffer[len++] = '0';
						} else {
							if (num < 0) {
								putchar('-');
								printchar++;
								num = -num;
							}
							int temp = num;
							while (temp > 0) {
								temp /= 10;
								len++;
							}
							temp = num;
							for (int i = len - 1; i >= 0; i--) {
								buffer[i] = '0' + (temp % 10);
								temp /= 10;
							}
						}
						for (int i = 0; i < len; i++) {
							putchar(buffer[i]);
							printchar++;
						}
						break;
			}

		}
		else {
			putchar(*format);
			printchar++;
		}
		format++;
	}
	va_end(arg_list);
	return (printchar);
}

