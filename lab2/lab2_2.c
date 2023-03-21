/* Scrivere un programma in linguaggio C che visualizzi i primi N numeri della serie di Fibonacci, con N
acquisito in input da tastiera.
Suggerimento: ecco i primi numeri appartenenti alla serie 0 1 1 2 3 5 8 ... In modo formale la serie si
costruisce considerando la seguente relazione: Xi = Xi-1 + Xi-2, con X0 = 0 e X1 = 1;  */

#include <stdio.h>

int main(){
	int N;
	int x=0,y=1,z,i;

	printf("Please, input an integer (N>0):  \n");
	scanf("%d",&N);

	if(N<=2){
		N==1?printf("%d", x):printf("%d\n%d",x,y);
	}
	else{
		printf("%d\n%d\n",x,y);
		for(i=0;i<N-2;i++){
			z = x + y;
			x=y;
			y=z;
			printf("%d\n", z);
		}
	}

}
