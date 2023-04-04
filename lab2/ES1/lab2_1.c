#include <stdio.h>

int main(){

	int num1, num2, resto, mcd;
	printf("Please, input two integer numbers:   \n");
	scanf("%d %d", &num1, &num2);

	resto = num1>num2? num1%num2 : num2%num1;

	if(resto!=0){
		while(resto!=0){
			num1 = num1<num2?num1:num2;
			num2 = resto;
			resto = num1%num2;
		}
		mcd = num2;
	}
	else{
		mcd=num1>num2?num2:num1;
	}
	printf("\nMDC is:  %d\n",mcd);

}
