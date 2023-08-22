#include "main.h"

int _printf(const char *format, ...){
    int printchar = 0;

    va_list arg_list;
    if (format == NULL){
        return (-1);
    }

    va_start(arg_list, format);

    while(*format)
    {
        if (*format != '%'){
            write(1, format, 1);
            printchar++;
        }
        else
        {   
            format++;
            if(*format =='\0'){
                break;
            }
            switch (*format)
            {
                case 'c': {
                    char c = va_arg(arg_list, int);
                    write(1, &c, 1);
                    printchar++;
                    break;
                }
                case '%': {
                    write(1, format, 1);
                    printchar++;
                    break;
                }
                case 's': {
                    char *s = va_arg(arg_list, char*);
                    int strlen = 0;

                    while(s[strlen] != '\0')
                        strlen++;

                    write(1, s, strlen);
                    printchar += strlen;

                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(arg_list, int);
                    int temp = num;
                    int num_digits = 0;

                    if (num == 0) {
                        write(1, "0", 1);
                        printchar++;
                    } else {
                        if (num < 0) {
                            write(1, "-", 1);
                            printchar++;
                            temp = -temp;
                        }

                        while (temp > 0) {
                            temp /= 10;
                            num_digits++;
                        }

                        temp = num;

                        char digits_buffer[12]; // Max number of digits in a 32-bit int + 1 for null terminator

                        for (int i = num_digits - 1; i >= 0; i--) {
                            int digit = temp % 10;
                            digits_buffer[i] = '0' + digit;
                            temp /= 10;
                        }

                        write(1, digits_buffer, num_digits);
                        printchar += num_digits;
                    }

                    break;
                }
            }
        }
        format++;
    }
    va_end(arg_list);
    return printchar;
}
