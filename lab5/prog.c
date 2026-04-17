#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#define dlm " \t"

int delimiter(char chr) {
    for (int x = 0; x < strlen(dlm); x++) {
        if (chr == dlm[x]) return 1; 
    }
    return 0; 
}

void clear_delimiters(list *lst) {
    while (delimiter(lst->head->data)) {
        chr *tmp = lst->head; 
        lst->head = lst->head->next;
        free(tmp);  
    }
    chr *prev = NULL, *now = lst->head;
    while (now->data != '\0') {
        if (delimiter(now->data) && delimiter(now->next->data)) {
            prev->next = now->next;
            prev->next->data = ' '; 
            free(now); 
            now = prev->next;
        } else if (delimiter(now->data) && now->next->data == '\0') {
            prev->next = now->next; 
            free(now); 
            now = prev->next;
        } else {
            if (delimiter(now->data)) now->data = ' '; 
            prev = now; 
            now = now->next; 
        }
        
    }
}

chr *cut_word(chr* now) {
    while ((!delimiter(now->next->data)) && now->next->data != '\0') {
        now = now->next; 
    }
    return now; 
}

int find_length(list *lst) {
    int len = 0; 
    chr *now = lst->head; 
    while (now->data != '\0') {
        len += 1; 
        now = cut_word(now);
        if (now->data == '\0') break; 
        now = now->next;    
    }
    return len; 
} 

void swap(list *lst, int length) {
    if (length <= 1) return ; 
    chr *word1_start = lst->head;
    chr *word1_end = cut_word(word1_start); 
    chr *word2_start = word1_start; 
    chr *word2_end;
    chr *tmp_end, *tmp_start; 
    for (int x = 1; x < length; x++) {
        if (x == 1) {
            word2_start = cut_word(word2_start);   
        } else {
            word2_start = cut_word(word2_start->next); 
        }
    }
    word2_end = cut_word(word2_start->next); 
    tmp_end = word2_end->next; 
    lst->head = word2_start->next->next;
    word2_end->next = word1_end->next; 
    word2_start->next->next = word1_start; 
    word1_end->next = tmp_end;
    for (int i = 1; i < length / 2; i++) {
        word1_start = word2_end->next;
        word1_end = cut_word(word1_start); 
        word2_start = word1_start; 
        for (int x = 1 + i; x < length - i; x++) {
            word2_start = cut_word(word2_start->next); 
        }
        word2_end = cut_word(word2_start->next); 
        tmp_end = word2_end->next; 
        tmp_start = word1_start->next; 
        word1_start->next = word2_start->next->next;
        word2_end->next = word1_end->next; 
        word2_start->next->next = tmp_start; 
        word1_end->next = tmp_end;
    } 
}

void process(list *lst) {
    clear_delimiters(lst); 
    int len = find_length(lst);
    swap(lst, len); 
}
