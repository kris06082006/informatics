#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"

size_t mystrlen(const char *s) {
    int size = 0;
    while (*s) {
        s++;
        size++;
    }
    return size;
}

char *get_str(char *prt) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    printf("%s", prt);
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0){
            int chunk_len = mystrlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            mymemcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
             scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {    
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *mystrdup(const char *s){
    int len = mystrlen(s);
    char *new_s = malloc(len + 1);
    for (int i = 0; i <= len; i++) {
        new_s[i] = s[i];
    }  
    return new_s;
}

char *mystrtok(char *s, const char *delim) {
    static char* b = NULL;
    char *word = NULL;
    if (s != NULL){ 
        b = s;
    }
    else if ((s == NULL) && (b == NULL)){
        return NULL;
    }
    int len = mystrlen(b);  
    for (int j = 0; ((j <= len) && ((mydelim(b, delim) == 1) || (b[0] == '\0'))); j++) { //проходится по строке пока не наткнется на символ, отличный от табуляции
        if (b[0] == '\0') {
            return NULL;
        }
        else {
            b++;
        }
    }
    word = b;
    len = mystrlen(b);
    for (int i = 0; i <= len; i++) {
        if (mydelim(b, delim) == 1){
            (b)[0] = '\0';
            b++; 
            return word;
        }
        else if (b[0] == '\0'){
            b = NULL;
            return word;
        }
        else {
            b++;            
        }

    }
}

int mydelim(char *s, const char *del){
    int len = mystrlen(del);
    for (int i = 0; i < len; i++){
        if (del[i] == s[0]){
            return 1;
        } 
    }
    return 0;
}

void *mymemcpy(void *dest, const void *src, size_t n){ 
    unsigned char *new_dest = (unsigned char *)dest;
    const unsigned char *new_src = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++){
        new_dest[i] = new_src[i];
    }
    return dest;
}
