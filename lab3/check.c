#include <stdio.h>
#include <stdlib.h>

#include "check.h"

int check_int(char* variable, int* n){
        char c;
        int result = scanf("%d%c", n, &c);
        if (result == EOF){
                printf("\nEnd of the program!\n");
                return 3;
        }
        if (result == 0 || c != '\n'){
                scanf("%*[^\n]");
                return 2;
        }
        if (c == '\n'){
                return 1;
        }
}
