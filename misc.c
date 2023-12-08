#include "shell.h"

/**
 * interactive - true if interactive mode is used.
 * @info: Pointer to struct
 * Return: 1 if interactive, otherwise 0
 */

int interactive(info_t *info)

{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check delimiter.
 * @c: char
 * @delim: string delim
 * Return: 1 (true), otherwise 0
 */

int is_delim(char c, char *delim)

{
        while (*delim) {
	if (*delim++ == c)
	{
		return 1;
	}
	}
	return (0);
}

/**
 * _atoi - func that converts str to int.
 * @s: String.
 * Return: 0 if null, otherwise return converted num.
 */

int _atoi(char *s)

{
	int i, sign = 1, output, flag = 0;
        unsigned int result = 0;

        for (i = 0; s[i] != '\0' && flag != 2; i++)
        {
		if (s[i] == '-') {
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
                {
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		} else if (flag == 1) {
			flag = 2;
		}
	}

	if (sign == -1) {
		output = -result;  
	}
	else
        {
		output = result;
	}

	return output;
}

/**
 * _isalpha - func that checks alphab order.
 * @c: char
 * Return: 1 (c is in alphabetic order), otherwise 0.
 */

int _isalpha(int c) 
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return (1);
	} else {
		return 0;
	}
}
