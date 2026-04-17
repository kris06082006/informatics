#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t"

char *process(const char *str){
    char *s = strdup(str); //копия исходной строки
    int s_len = strlen(s); //длина исходной строки
    char *new_s = calloc(s_len + 1, sizeof(char)); // выходная строка (новая и пустая)
//    int new_len = 0;
    int new_i = 0;
    char *word = strtok(s, DELIM); // берет слово и ставит в конец '\0'
    while (word != NULL){
//        printf("Word: \"%s\"\n", word);
        int w_len = strlen(word);
        int symbol = word[w_len - 1];
        int c = 0;
        for (int i = 0; i < w_len; i++){
            if (word[i] != symbol){
                new_s[new_i] = word[i];
                new_i += 1;
                c += 1;
            }
        }
        if (c != 0){
            new_s[new_i] = ' ';
            new_i += 1;
        }  
//        printf("Result: \"%s\"\n", new_s);
        word = strtok(NULL, DELIM); 
    }
    free(s);
    if (new_i > 0){
        --new_i;
    }
    new_s[new_i] = '\0';
    new_s = realloc(new_s, (new_i + 1) * sizeof(char));   
    return new_s;
 }
    
    
