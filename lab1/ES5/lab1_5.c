#include <stdio.h>

int main(){
	char operator;
	float num1, num2, result;

	printf("Prego: (+,-,*,/)  \n");
	operator = getchar();
	scanf(" %f %f", &num1, &num2);

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

	printf("%c %.2f", operator, result);
	return 1;

}
