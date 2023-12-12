#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>


/*Buffer*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*Num Flags Conv*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/*Hist Config*/
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3


extern char **environ;

#define USE_GETLINE 0
#define USE_STRTOK 0


/* Structure emulating a list*/

typedef struct liststr

{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/*Struct holding info that relates to shell*/

typedef struct passinfo

{
	char *arg;          /*Cmd args from getline*/
	char *fname;			       /*Program filename*/
	char *path;		       /*Path to actual cmd */
	int err_num;			    /*Err code for exit*/
	char **argv;	                 	     /*Array of str from arg*/
	list_t *history;          /*Hist node*/
	char **cmd_buf;		   /*Pointer to cmd buff chain*/
	int argc;				/*Arg count*/
	unsigned int line_count;     /*Line count of err*/
	char **environ;		/*copy of environ*/
	int status;			   /*Return status last exec cmd */
	int readfd;	/*Fd for input read*/
	int env_changed;		    /*Flag for env change*/
	int histcount;		      /*Hist count of lines*/
	list_t *env;			     /*List copy of env*/
	int cmd_buf_type;     /*Cmd chain (&&, ;, ||) */
	list_t *alias;		   	    /*Alias node*/
	int linecount_flag; /*Flag counting ipnut line*/
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, 0, NULL, \
	0, 0, 0}

/*Structure to specify built-in shell cmds*/

typedef struct builtin

{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int find_builtin(info_t *);
void find_cmd(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);

char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);
int loophsh(char **);

char *_strncat(char *, char *, int);
void _puts(char *);
int _putchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
char *_strncpy(char *, char *, int);
int _eputchar(char);
char *_strcpy(char *, char *);
void _eputs(char *);
char *_strdup(const char *);
char **strtow(char *, char *);
char *_strchr(char *, char);
char **strtow2(char *, char);

int bfree(void **);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);
char *_memset(char *, char, unsigned int);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

int _strlen(char *);
char *starts_with(const char *, const char *);
int _strcmp(char *, char *);

char *_strcat(char *, char *);

int _erratoi(char *);
char **get_environ(info_t *);
int _myexit(info_t *);
int _myalias(info_t *);
int interactive(info_t *);
int _myhistory(info_t *);
void remove_comments(char *);
int _isalpha(int);
char *convert_number(long int, int, int);
int is_delim(char, char *);
int _unsetenv(info_t *, char *);
void print_error(info_t *, char *);
int print_d(int, int);
int _setenv(info_t *, char *, char *);
int _mycd(info_t *);
int _atoi(char *);
int _myhelp(info_t *);

int build_history_list(info_t *info, char *buf, int linecount);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);  
int read_history(info_t *info);
int renumber_history(info_t *info);
int write_history(info_t *info);
void set_info(info_t *, char **);
int _getline(info_t *, char **, size_t *);
char *get_history_file(info_t *info);
void sigintHandler(int);
int _myenv(info_t *);
list_t *add_node(list_t **, const char *, int);
char *_getenv(info_t *, const char *);
int _mysetenv(info_t *);
void free_info(info_t *, int);
void clear_info(info_t *);
list_t *add_node_end(list_t **, const char *, int);
ssize_t get_input(info_t *);

size_t print_list(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);  
ssize_t get_node_index(list_t *, list_t *);
void free_list(list_t **);
list_t *node_starts_with(list_t *, char *, char);
size_t print_list_str(const list_t *);

#endif
