#include "shell.h"

/**
 * is_cmd - Establish if a file is an executable cmd
 * @info: Init var
 * @path: Init path
 * Return: 1 for true otherwise 0
 */

int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st) != 0)
return 0;

if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
return 1;

return (0);
}

/**
 * dup_chars - Duplicates chars
 * @pathstr: Init var
 * @start: Init var
 * @stop: Init var
 * Return: New buffer pointed
 */

char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];  
int i, k = 0;

for (k = 0, i = start; i < stop; i++)
{
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
}
buf[k] = 0;  
return buf;
} 

/**
 * find_path - Find cmd in path
 * @info: Init var
 * @pathstr: Init var
 * @cmd: Init variable
 * Return: Full path of cmd if found, or NULL.
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
return NULL;

if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd)) 
return cmd; 
}

while (1) 
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);

if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}

if (is_cmd(info, path))
return path; 

if (!pathstr[i])
break;  

curr_pos = i;
} 
i++;
}  
return NULL;
}
