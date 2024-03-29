#include "shell.h"

/**
 * input_buf - Commanded buffers chaines
 * @info: Init variable
 * @buf: Init var
 * @len: Init var
 * Return: Bytes read.
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0; 

if (!*len) /* Fill if empty */
{
free(*buf); /* Release if exists */

*buf = NULL;  
signal(SIGINT, sigintHandler);

#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif

if (r > 0)
{
if ((*buf)[r - 1] == '\n') 
{
(*buf)[r - 1] = '\0'; 
r--;
}

info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
*len = r;
info->cmd_buf = buf; 
}
}

return (r);
}

/**
 * get_input - Gets a line minus the newline.
 * @info: Parameter struct.
 * Return: Bytes read.
 */

ssize_t get_input(info_t *info)
{
static char *buf; /* ';' commanded buffer chain */
static size_t i, j, len;
ssize_t r = 0;  
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);

if (r == -1) 

return (-1);

if (len) 
{
j = i; /* Sets new iterator */
p = buf + i;

check_chain(info, buf, &j, i, len);
while (j < len)
{
if (is_chain(info, buf, &j))
break;
j++;
}

i = j + 1;
if (i >= len)
{
i = len = 0; /* Resetting position */
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;

return _strlen(p); /* Return length */
} 

*buf_p = buf;
return r; /* Return length */
}

/**
 * read_buf - Function that reads a buffer
 * @info: Init param
 * @buf: Init var
 * @i: Init var
 * Return: r.
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)

return (0);

r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r; 

return r; 
}

/**
 * _getline - Get next line
 * @info: Init param
 * @ptr: Init var
 * @length: Init var
 * Return: s.
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k; 
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
s = *length;

if (i == len)
i = len = 0;

r = read_buf(info, buf, &len);

if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1); 

if (!new_p) /* Failed memory allocation */
return p ? free(p), -1 : -1;

if (s)

_strncat(new_p, buf + i, k - i);
else
_strncpy(new_p, buf + i, k - i + 1);

s += k - i; 
i = k;
p = new_p;

if (length)
*length = s;
*ptr = p; 

return (s);
}

/**
 * sigintHandler - Stops the command ctrl_c
 * @sig_num: Initialize variable
 * Return: void.
 */

void sigintHandler(__attribute__((unused)) int sig_num)
{
_puts("\n");
_puts("$ "); 

_putchar(BUF_FLUSH);
} 
