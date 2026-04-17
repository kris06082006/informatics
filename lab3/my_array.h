#ifndef ARRAY_H
#define ARRAY_H

typedef enum Err {
    ERR_OK = 0,
    ERR_MEM = -1,
} Err;

Err print_array(const int*array, int len);
Err initializing_array(int** array, int len, int cap);
Err insert_element(int** array, int* len, int* cap, int value, int index);
Err delete_element(int** array, int* len, int* cap, int index);
Err convert_array(int m, int** subarray, int** array, int* len, int* cap);
Err mem_allocation(int** array, int* len, int* cap);

#endif
