#include "shell.h"

/**
 * _strcpy - Copy str
 * @dest: Init var
 * @src: Init var
 * Return: Points to destination
 */

char *_strcpy(char *dest, char *src)
{
int i = 0;  

if (dest == src || src == 0)  

return (dest);
while (src[i])
{
dest[i] = src[i];
i++;  
}
dest[i] = '\0';  
return (dest);  
}

/**
 * _strdup - Str duplicated
 * @str: Init var
 * Return: Points to duplicated string otherwise NULL 
 */

char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL) 
return (NULL); 
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)  
return (NULL);  
for (length++; length--;)
ret[length] = *(--str);
return (ret); 
}

/**
 * _puts - Display input
 * @str: Init var
 * Return: Nothing
 */

void _puts(char *str)
{
int i = 0;

if (!str)

return;  
while (str[i] != '\0')
{
_putchar(str[i]);
i++;       
} 
}

/**
 * _putchar - prints  char
 * @c: Init var
 * Return: On success 1 or -1 if error
 */

int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)

{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)  
buf[i++] = c;  
return (1); 
}
