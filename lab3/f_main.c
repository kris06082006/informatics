#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"
#include "check.h"
#include "dialog.h"

int main() {  
    int *data = NULL;
    int len = 0; 
    int cap = 0;
    int out = 0; 
    while(!out) {
        out = dialog(&data, &len, &cap); 
    }
    free(data);
    return 0;
}
