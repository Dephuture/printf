#include "main.h"
/**
 * _putstr - main entry
 * @str: string
 * Return: 0
 */

int _putstr(const char *str)
{
	int len = 0;

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}
