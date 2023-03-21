/*  Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore
utilizzando la formula di Eulero.
Formula di Eulero o metodo dei resti: si procede per divisioni successive del numero maggiore per
quello minore, sostituendo ad ogni passo il valore maggiore con il minore ed il minore
col resto della divisione. Il processo termina quando il resto è 0   */

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
