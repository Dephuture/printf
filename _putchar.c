#include "main.h"
/**
 * _putchar - main entry
 * @c: char
 * Return: 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
