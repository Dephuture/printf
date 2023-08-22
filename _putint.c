#include "main.h"
/**
 * _putint - main entry
 * @num: int input
 * Return: 0
 */

int _putint(int num)
{
	int len = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}
	if (num == 0)
	{
		_putchar('0');
		len++;
	}
	else
	{
		int rev_num = 0;

		while (num > 0)
		{
			rev_num = rev_num * 10 + num % 10;
			num /= 10;
		}
		while (rev_num > 0)
		{
			_putchar('0' + rev_num % 10);
			rev_num /= 10;
			len++;
		}
	}
	return (len);
}
