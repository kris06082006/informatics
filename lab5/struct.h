#ifndef STRUCT_H
#define STRUCT_H

typedef struct chr {
    char data; 
    struct chr *next; 
} chr;  


typedef struct list {
    chr *head; 
} list; 

int init(list *); 
void print_list(list *); 
void clear_list(list *); 

#endif
