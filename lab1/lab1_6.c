#include <stdio.h>

int main(){
	FILE *fin, *fout;
	char operator;
	float num1, num2, result;

	fin=fopen("operations.txt", "r");
	fout=fopen("risultati.txt", "w");

	while(!feof(fin)){
		operator = fgetc(fin);
		fscanf(fin, "%f %f ", &num1, &num2);
		switch(operator){
			case '+':
				result=num1+num2;
				break;
			case '-':
				result=num1-num2;
				break;
			case '*':
				result=num1*num2;
				break;
			case '/':
				result=num1/num2;
				break;
			default:
				printf("Operazione invalida. \n");
				return 0;
		}

		fprintf(fout, "%c %.2f\n", operator, result);
	}
	

	fclose(fin); fclose(fout);

	return 1;

}
