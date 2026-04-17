#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#include "process_4a.h"

#define PROMPT "> "

int main(){
    char *input = readline(PROMPT);
    while (input != NULL){
        printf("\"%s\"\n", input);
        char *output = process(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
        input = readline(PROMPT);
    }
    return 0;
}
