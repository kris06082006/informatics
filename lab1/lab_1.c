#include <stdio.h>

int min_num(int);
int reverse_min_negative_num(int);
int min_negative_num(int);

int main(){
    int number = 0;
    scanf("%d", &number);
    int new_number = min_num(number);
    printf("%d\n", new_number);

    return 0;
}

int min_num(int num){
    if (num < 0){
        int minimal_num = min_negative_num(num);
	return minimal_num;
    }
    else{
        num = min_negative_num(num);
	int minimal_num = reverse_min_negative_num(num);
	return minimal_num;
    }
}

int reverse_min_negative_num(int n) {
    n *= -1;
    int n_reverse = 0;
    while (n > 0) {
        n_reverse = n_reverse * 10 + n % 10;
	n /= 10;
    }
    return n_reverse;
}

int min_negative_num(int num) {
    if (num < 0) {
    
        num = num * -1;
    }
    int new_num = 0;
    int a = 0;
    int discharge = 1;
    for (; a < 10; a += 1) {
        int num_copy = num;
	while (num_copy != 0) {
	    if ((num_copy % 10) == a) {
	        new_num += a * discharge;
		num_copy /= 10;
		discharge *= 10;
	    }
	    else{
	        num_copy /= 10;
	    }
	}
    }
    return new_num * -1;
}
