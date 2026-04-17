#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

size_t mystrlen(const char *s);
char *get_str(char *prt);
char *mystrdup(const char *s);
char *mystrtok(char *s, const char *delim);
void *mymemcpy(void *dest, const void *src, size_t n); 
int mydelim(char *s,const char *del);

#endif
