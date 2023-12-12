#include "shell.h"

/**
 * bfree - Releases a pointer and NULLs the address
 * @ptr: Initialize pointer
 * Return: 1 if released, otherwise 0.
 */

int bfree(void **ptr) 
{
if (ptr && *ptr)
{
free(*ptr);   /* Release memory */
*ptr = NULL;  /* Set pointer to NULL */
return 1;     /* Return 1 to indicate success */
}
return 0; 
}
