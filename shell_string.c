#include "shell.h"

/**
 * _strncpy - Copies 'n' strings
 * @dest: Init var
 * @src: Init var
 * @n: Initialize variable
 * Return: Pointer to string
 */

char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)

{
dest[i] = src[i];
i++;
} 
if (i < n)

{  
j = i;           
while (j < n)
{
dest[j] = '\0';
j++;  
}
}

return s;
}

/**
 * _strncat - Concat two strings 'n' times
 * @dest: Initialize var
 * @src: Init variable
 * @n: The maximum number of bytes to be used.
 * Return: Pointer concat string.
 */

char *_strncat(char *dest, char *src, int n)
{

int i, j;
char *s = dest; 

i = 0;
j = 0;
while (dest[i] != '\0')

i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
} 
if (j < n)
dest[i] = '\0';
return (s); 

}

/**
 * _strchr - Locates a character in a string.
 * @s: Init var
 * @c: Init var
 * Return: Pointer to 'c' in 's' otherwise NULL
 */

char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s); 
} 
while (*s++ != '\0'); 

return (NULL); 
}
