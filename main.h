#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 100

int _printf(const char *format, ...);
int _printf1(const char *format, ...);
int _putint(int num);
int _putstr(const char *str);
int _putchar(char c);

#endif
