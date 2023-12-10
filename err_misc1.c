#include "shell.h"

/**
 * _erratoi - Func to convert a str to int.
 * @s: str
 * Return: int, otherwise -1.
 */

int _erratoi(char *s)

{
	int i = 0;
        unsigned long int result = 0;

	if (*s == '+') {
		s++;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');

			if (result > INT_MAX)
			{
				return (-1);
			}
		}
		else {
			return -1;
		}
	}

	return (result);
}

/**
 * print_error - Func that prints err msg.
 * @info: info struct param.
 * @estr: str housing err.
 */

void print_error(info_t *info, char *estr)

{
	_eputs(info->fname);
	_eputs(": ");

	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Func that prints dec int to the base 10.
 * @input: num.
 * @fd: file d.
 * Return: count of nums.
 */

int print_d(int input, int fd)

{
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
        int i, count = 0;
	unsigned int _abs_, current;

	if (input < 0) {
		_abs_ = -input;
		__putchar('-');
		count++;
	}

	else
		_abs_ = input;
	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)  
	{
		if (_abs_ / i) {
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return count;
}

/**
 * convert_number - Func that convets similar to itoa.
 * @num: uns long num.
 * @base: conv base.
 * @flags: Arg flags.
 * Return: str.
 */

char *convert_number(long int num, int base, int flags)

{
	static char *array;
	static char buffer[50];
	char sign = 0;
        char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0) {
		n = -num;
		sign = '-';
	}

	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
        }
	return (ptr);
}

/**
 * remove_comments - Func that replaces '#' with '\0'.
 * @buf: str address.
 * Return : nothing.
 */
d
void remove_comments(char *buf)

{
        int i;

	for (i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
