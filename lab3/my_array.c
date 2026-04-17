#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"
#include "check.h"

Err print_array(const int *array, int len) {
    if (len == 0 || array == NULL) {
        return ERR_MEM;
    }
    for (int i = 0; i < len; ++i) {
        printf("array[%d] = %d\n",i, array[i]);
    }
    printf("\n"); 
    return ERR_OK;
}
Err mem_allocation(int** array, int* len, int* cap){
    if (*len == *cap){
        *cap *= 2;
        int* status = realloc(*array, *cap * sizeof(int));
        if (status == NULL){
            return ERR_MEM;
        }
        *array = status;
        return ERR_OK;
    }
    if (*len < (*cap/2)){
        *cap /= 2;
        int* status = realloc(*array, *cap * sizeof(int));
        if (status == NULL){
            return ERR_MEM;
        }
        *array = status;
        return ERR_OK;
    }
}
Err initializing_array(int** array, int len, int cap){  
    *array = malloc(cap * sizeof(int));
    int value;   
    printf("Enter the values: "); 
    for (int i = 0; i < len; i++){
        int status = -1;	    
        status = check_int("", &value); 
        if (status == 1){	
            (*array)[i] = value;
        }
        else{   
	        free(*array);
            *array = NULL;	    
	        printf("Incorrect data...\n");
            return ERR_MEM;
            break;	    
    	}	
    }
    return ERR_OK;
}

Err insert_element(int** array, int* len, int* cap, int value, int index) {
    if (index < 0) return ERR_MEM;
   
    if (index > *len){
        index = *len;	    
    }

    int finish_i = *len - 1;
    while (finish_i >= index){
        (*array)[finish_i+1] = (*array)[finish_i];
        finish_i -= 1;
    }
    (*array)[index] = value;
    *len += 1;
    Err status = mem_allocation(array, len, cap);
    return status;

}

Err delete_element(int** array, int* len, int* cap, int index){
    if (index >= *len || index < 0){
        return ERR_MEM;
    }
    while (index < *len -1){
        (*array)[index] = (*array)[index + 1];
        index += 1;
    }   
    *len -= 1;
    Err status = mem_allocation(array, len, cap);
    return status;
}

Err convert_array(int m, int** subarray, int** array, int *len, int* cap){
	Err error;
    int len_subarray = 0;
    for (int i = 0; i < *len; i++){
	    int sum = 0;
	    int element = (*array)[i];
	    while (element != 0){
	        sum += element % 10;
	        element /= 10; 
   	    }
	    if (sum == m){
	        len_subarray += 1;
		    int *new_subarray = realloc(*subarray, len_subarray * sizeof(int));
            if (new_subarray == NULL){
		    	return ERR_MEM;
		    }
		    *subarray = new_subarray; 
		    (*subarray)[len_subarray - 1] = (*array)[i];
            error = delete_element(array, len, cap, i);
            i -= 1; 
	        error = mem_allocation(array, len, cap);
	    }
   
    }
    return ERR_OK;	

}



