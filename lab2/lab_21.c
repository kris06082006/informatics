#include <stdio.h>
#include <math.h>

long double cos_2(long double, long double, int*);
int check_long_double(char, long double*);

int main(){
	int count_of_members = 1;
	long double x = 0;
	long double accurary = 0;
	int status_1 = 0;
	int status_2 = 0;
	char variable_x = 'x';
	char variable_accurary = 'a';
	while (status_1 != 1){
		status_1 = check_long_double(variable_x, &x);
		if (status_1 == 3) return 0;
	}
	while (status_2 != 1){
		status_2 = check_long_double(variable_accurary, &accurary);
		if (status_2 == 3) return 0;
	}
	long double s1 = cosl(x) * cosl(x);
	long double s2 = cos_2(x, accurary, &count_of_members);
	printf("s1: %.19Lf\ns2: %.19Lf\n", s1, s2);
	printf("%d\n", count_of_members); 

	return 0;
}


int check_long_double(char variable, long double* x){
	printf("Enter %c: ", variable);
	char c;
	int result = scanf("%Lf%c", x, &c);
	if (result == EOF){
		printf("\nEnd of the program!\n");
		return 3;
	}
	if (result == 0 || c != '\n'){
		printf("Error! Try agayn.\n");
		scanf("%*[^\n]");
		return 2;
	}
	if (c == '\n'){
		return 1;
	}

}


long double cos_2(long double x, long double accurary, int* count_of_members){
	long double sum = 1 -(x*x), d = -(x*x), y = 4*x*x;
	int i = 2;
	while (fabsl(d) > accurary){
		d *= -1 * y/((i*2)*(i*2-1));
		sum += d;
		*count_of_members += 1;
		i += 1;
	}
	return sum;
}
