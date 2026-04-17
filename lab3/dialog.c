#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"
#include "check.h"
#include "dialog.h"

int dialog(int **data, int* len, int* cap) {  
    int index = 0;
    Err error; 
    int value = 0;
    int status = -1;
    char option = -1;
    printf("\n");
    printf("***** MENU *****\n");
    printf("1. Set a sequence of integers\n");
    printf("2. Inserting a new element\n");
    printf("3. Deleting an element\n");
    printf("4. Convert an array\n");
    printf("5. Print an array\n");
    printf("0. Exit\n");
    printf("\n");

    int r = scanf(" %c", &option);
    if (r == EOF){ 
        printf("The end rogram\n");
        return 1;
    }

    switch (option) {
    case '0':
        printf("Exiting...\n");
        return 1; 
        break;

    case '1': 
        free(*data);
        *data = NULL;
        *len = 0;
        *cap = 0;
        printf("Enter the len: ");
        status = check_int("", len);
        if (*len <= 0 || status != 1){
            printf("Incorrect data...\n");
            *len = 0;
            return 0;
        }        
        *cap = *len * 2;
        error = initializing_array(data, *len, *cap);
        if (error == ERR_OK ) error = print_array(*data, *len);
        if (error == ERR_MEM) printf("Oops... Array is empty\n");
        break;

    case '2':
        if (*len == 0){
            *len += 1;
            *cap += 2;
            error = initializing_array(data, *len, *cap);
            error = print_array(*data, *len);
            return 0;
        }
        printf("Enter the index: ");
        status = check_int("", &index);
        if (status != 1){
            printf("Incorrect data...\n");
            error = print_array(*data, *len);
            return 0;  
        }
        printf("Enter the value: ");
        status = check_int("", &value);
        if (status != 1){
            printf("Incorrect data...\n");
            error = print_array(*data, *len);
            return 0;  
        }
        error = insert_element(data, len, cap, value, index); 
        if (error == ERR_MEM){
            printf("Incorrect data...\n");
            error = print_array(*data, *len);
            return 0;
        }
        error = print_array(*data, *len);
        break; 
    case '3':
        if (*len == 0){
            printf("Oops... Array is empty\n");
            return 0;
        }

        printf("Enter the index: ");
        status = check_int("", &index);
        if (status != 1){
            printf("Incorrection data...\n");
            error = print_array(*data, *len);
            return 0;
        }
        error = delete_element(data, len, cap, index);
        if (error == ERR_MEM){
            printf("Incorrect data...\n");
            error = print_array(*data, *len);
            return 0;
        }
        if (*len == 0){
            printf("Array is empty\n");
            return 0;
        }
        error = print_array(*data, *len);
        break; 
    case '4':
        if (*len == 0){
            printf("Oops... Array is empty\n");
            return 0;
        }
        int m = 0; 
        int* subarray = NULL;
        printf("Enter M: ");
        status = check_int("", &m);
        if (status != 1){
            printf("Incorrect data...\n");
            return 0;
        }
        int old_len = *len;
        error = convert_array(m, &subarray, data, len, cap);
        printf("Array:\n");
        error = print_array(*data, *len);
        if (error == ERR_MEM){
            printf("Array is empty\n");
            printf("\n"); 
        }
        printf("Subarray:\n");
        error = print_array(subarray, (old_len - *len));
        if (error == ERR_MEM){
            printf("Subarray is empty\n");
        }
        free(subarray);
        break;
    case '5':
        print_array(*data, *len);
        break; 

    default:
        printf("Wrong input!\n");
        break;
    }
    return 0; 
}   
