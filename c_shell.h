#ifndef C_SHELL
#define C_SHELL

/*
 * input and output operations
 */
#include <stdio.h>

/*
 * macros for general-purpose utility
 */
#include <stdlib.h>

/*
 * macros for POSIX (Portable Operating System Interface)
 */
#include <unistd.h>

/*
 * macros for manipulating strings - character arrays
 */
#include <string.h>

/*
 * macros for dealing with child processes
 */
#include <sys/wait.h>

/*
 * defines types used in system calls and other system-related functions
 */
#include <sys/types.h>

/*
 * declarations for the error codes
 */
#include <errno.h>

/*
 * definitions for commonly used C data types and macros
 */
#include <stddef.h>

/*
 * prototypes, macros, and data types for working with file
 * system metadata
 */
#include <sys/stat.h>

/*
 * declarations for signal handling in C programs
 * For communicating with processes
 */
#include <signal.h>

/**
 * struct pathToList - linked list with PATH to directories
 * @dir: directory within path
 * @ptr: pointer to next node
 */
typedef struct pathToList
{
	char *dir;
	struct pathToList *ptr;
} pathToList;

/**
 * struct buildsetup - store information about a build step
 * @name: accepted command
 * @function: execute command
 */
typedef struct buildsetup
{
	char *name;
	void (*function)(char **);
} buildsetup;

/*
 * represents the environment of the current process
 * key-value pairs containing information about the current
 * environment the program is executing.
 */
extern char **environ;

char *concat_all(char *name, char *sep, char *value);
char *_strdup(char *str);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);

char **stringsplit(char *str, const char *delimeter);
void execute(char **av);
void *reallocation(void *ptr, unsigned int old_space, unsigned int new_space);

char *_getenv(const char *name);
pathToList *add_node_end(pathToList **head, char *str);
pathToList *linkpath(char *path);
char *_which(char *filename, pathToList *head);

/*check if command is a built_in*/
void(*checkbuild(char **arv))(char **arv);

/*convert string to int*/
int _atoi(char *s);

/*exit the shell*/
void exitshell(char **arv);

/*print current environment*/
void env(char **arv);

/*set new env or modify known one*/
void _setenv(char **arv);

/*remove env variable*/
void _unsetenv(char **arv);

/*deallocate memory & avoid memory leaks*/
void dealloc(char **arv);

/*free memory to each node in linked list*/
void free_list(pathToList *head);

#endif

