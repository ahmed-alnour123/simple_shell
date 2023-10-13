#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;
extern char *name;
extern int hist;

/**
 * struct list_s - struct
 * @dir: variable
 * @next: variable
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - struct
 * @name: variable
 * @f: variable
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **, char **);
} builtin_t;

/**
 * struct alias_s - struct
 * @name: variable
 * @value: variable
 * @next: variable
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

extern alias_t *aliases;

alias_t *add_alias_end(alias_t **, char *, char *);
char **_copyenv(void);
char **_getenv(const char *);
char **_strtok(char *, char *);
char **replace_aliases(char **);
char *_itoa(int);
char *_strcat(char *, const char *);
char *_strchr(char *, char);
char *_strcpy(char *, const char *);
char *_strncat(char *, const char *, size_t);
char *error_1(char **);
char *error_126(char **);
char *error_127(char **);
char *error_2_cd(char **);
char *error_2_exit(char **);
char *error_2_syntax(char **);
char *error_env(char **);
char *get_args(char *, int *);
char *get_location(char *);
int (*get_builtin(char *))(char **, char **);
int _strcmp(char *, char *);
int _strlen(const char *);
int _strncmp(const char *, const char *, size_t);
int _strspn(char *, char *);
int call_args(char **, char **, int *);
int check_args(char **);
int create_error(char **, int);
int execute(char **, char **);
int handle_args(int *);
int my_alias(char **, char __attribute__((__unused__)) **);
int my_cd(char **, char __attribute__((__unused__)) **);
int my_env(char **, char __attribute__((__unused__)) **);
int my_exit(char **, char **);
int my_help(char **, char __attribute__((__unused__)) **);
int my_setenv(char **, char __attribute__((__unused__)) **);
int my_unsetenv(char **, char __attribute__((__unused__)) **);
int proc_file_commands(char *, int *);
int run_args(char **, char **, int *);
list_t *add_node_end(list_t **, char *);
list_t *get_path_dir(char *);
ssize_t _getline(char **, size_t *, FILE *);
void *_realloc(void *, unsigned int, unsigned int);
void free_alias_list(alias_t *);
void free_args(char **, char **);
void free_env(void);
void free_list(list_t *);
void free_list(list_t *);
void handle_line(char **, ssize_t);
void help_alias(void);
void help_all(void);
void help_cd(void);
void help_env(void);
void help_exit(void);
void help_help(void);
void help_history(void);
void help_setenv(void);
void help_unsetenv(void);
void variable_replacement(char **, int *);
#endif /* _SIMPLE_SHELL_H_ */
