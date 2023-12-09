#include "shell.h"

/**
 * _eputs - func that prints str to stderr.
 * @str: str.
 * Return: void.
 */

void _eputs(char *str) {
	int i = 0;

        if (!str)
	{
		return;
	}

	while (str[i] != '\0')  
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - func that writes char to stderr.
 * @c: char.
 * Return: On error, -1 is returned, and errno is set appropriately.otherwise 1 (Success).
 */

int _eputchar(char c)

{
	static int i;
        static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH) {
		buf[i++] = c; 
	}

	return (1);
}

/**
 * _putfd - Func that writes char to fd.
 * @c: char.
 * @fd: file descriptor.
 * Return: On error, -1 is returned, and errno is set appropriately. Otherwise 1 (success).
 */

int _putfd(char c, int fd)

{
	static int i;
	static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
		write(fd, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return 1;
}

/**
 * _putsfd - Func that prints str to fd.
 * @str: str.
 * @fd: File Descriptor.
 * Return: num of chars.
 */

int _putsfd(char *str, int fd)

{
	int i = 0;

	if (!str) {
		return (0);
	}

	while (*str)
	{
		i += _putfd(*str++, fd); 
	}

	return i;
}
