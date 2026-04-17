#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "prog.h"

int main() {
    list *lst = malloc(sizeof(list)); 
    while(init(lst) == 0) {
        print_list(lst); 
        process(lst); 
        print_list(lst); 
        clear_list(lst); 
    }
    free(lst); 
    return 0;      
}
