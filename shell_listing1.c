#include "shell.h"

/**
 * list_len - Sets length for linked lists
 * @h: Init var
 * Return: Size of the list.
 */

size_t list_len(const list_t *h)
{
size_t i = 0;

while (h)
{
h = h->next; 
i++;  
}
return (i);
}

/**
 * list_to_strings - Return array 
 * @head: Init var
 * Return: Array of strings.
 */

char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head);
char **strs; 
char *str;  

size_t j;

if (!head || !i)
return NULL;

strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return NULL;
for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++) /* Initialize j */
free(strs[j]);
free(strs);
return NULL;
		}
str = _strcpy(str, node->str);
strs[i] = str; 
}
strs[i] = NULL;
return strs;
}

/**
 * print_list - Prints every element
 * @h: Init variable
 * Return: Size of the list.
 */

size_t print_list(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_puts(": "); 
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/**
 * node_starts_with - Returns node
 * @node: Initialize variable
 * @prefix: Init var
 * @c: Init var
 * Return: Match or NULL.
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;

while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))  
return node; 
node = node->next; 
}
return NULL;
}

/**
 * get_node_index - Gets index of a node
 * @head: Init pointer
 * @node: Init var
 * Return: Index of the node or -1 if not found.
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
if (head == node)
return i;
head = head->next;  
i++; 
}
return (-1); 
}
