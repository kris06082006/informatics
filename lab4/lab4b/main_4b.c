#include <stdio.h>
#include <stdlib.h>

#include "process_4b.h"

#define PROMPT "> "

int main(){
    char *input = get_str(PROMPT);
    while (input != NULL){
        printf("\"%s\"\n", input);
        char *output = process(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
        input = get_str(PROMPT);
    }
    return 0;


}
