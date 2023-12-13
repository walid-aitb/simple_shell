#include "shell.h"

/**
 * _strlen - Brings back length
 * @s: Intialize variable
 * Return: int lentgh
 */


int _strlen(char *s)
{
int i = 0;

if (!s)

return (0);

while (*s++)
i++;  
return (i); 
}

/**
 * _strcmp - Compare string
 * @s1: Init var
 * @s2: Init var
 * Return: Negative , positive or 0 under conditions.
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2) 

{
if (*s1 != *s2) 
return (*s1 - *s2); 
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks starting string
 * @haystack: Init var
 * @needle: Init var
 * Return: Address of the next char otherwise NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
while (*needle) 
{
if (*needle++ != *haystack++)  
return (NULL); 
}
return (char *)haystack;
}

/**
 * _strcat - Concat str
 * @dest: Init var
 * @src: Init var
 * Return: Points to destination
 */

char *_strcat(char *dest, char *src)
{

char *ret = dest;

while (*dest) 
dest++;
while (*src)

*dest++ = *src++;   
*dest = *src; 
return ret; 
}
