#include <stdio.h>
#include <stdlib.h>

#include "struct.h" 

int init(list *lst) {
    lst->head = malloc(sizeof(chr));
    chr *now = lst->head; 
    char input = getchar();
    if (input == EOF) {
        free(lst->head);
        return 1; 
    }
    while (input != '\n') {
        now->data = input; 
        now->next = malloc(sizeof(chr)); 
        now = now->next; 
        input = getchar();  
    }
    now->data = '\0'; 
    now->next = NULL; 
    return 0; 
}

void print_list(list *lst) {
    chr *now = lst->head; 
    printf("<");
    while(now->data != '\0') {
        printf("%c", now->data); 
        now = now->next; 
    }
    printf(">\n"); 
}

void clear_list(list *lst) {
    chr *now = lst->head; 
    while (now->data != '\0') {
        chr *tmp = now; 
        now = now->next; 
        free(tmp); 
    } 
    free(now); 
}
