#include "shell.h"

/**
 * _memset - Fills memo with byte
 * @s: Init variable
 * @b: Init var
 * @n: Init var
 * Return: Points memory s.
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i; 

for (i = 0; i < n; i++)
s[i] = b;

return (s); 
}

/**
 * ffree - Release a string of strings.
 * @pp: Array of strings.
 */

void ffree(char **pp)
{
char **a = pp;

if (!pp) 
return;
while (*pp)

free(*pp++);  
free(a);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Init pointer
 * @old_size: Init var
 * @new_size: Init var
 * Return: Pointer to a new block.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return malloc(new_size);
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)

return ptr;

p = malloc(new_size);
if (!p)
return NULL;  

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);  
return (p); 
}
