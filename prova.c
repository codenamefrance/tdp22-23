/*Esercizio 5. 
Scrivere un programma “calcolatrice” che esegua le quattro operazioni aritmetiche di base
(addizione, sottrazione, divisione e moltiplicazione) tra due valori op1 e op2.
Realizzare un programma C che:
a) Acquisisca da tastiera utilizzando getchar l’operazione da eseguire (‘+’, ‘-‘, ‘*’ e ‘/’)
b) Acquisisca da tastiera utilizzando scanf i due operandi (float) (es. 21.0 2.0).
c) Stampi a schermo il carattere dell’operazione seguita dal risultato (es. / 10.50).
Approfondimento: Cosa succede quando op2 è uguale a 0? 
*/

#include <stdio.h>

int main(){
	FILE *fpin, *fpout;
	char operand, operand_flag;
	float op1, op2, result;

	fpin = fopen("input.txt", "r");
	fpout= fopen("output.txt", "w");

	if(fpin!=NULL){
		while(!feof(fpin)){
			fscanf("%c %d %d\n",&operand,&op1,&op2);
			//...

		}
	}
	else{
		prinft("Errore file.");
	}

	

	operand_flag = 0;
	printf("Please, enter the operand (+,-,*,/)\n");
	while(operand_flag==0){
			operand=getchar();
			switch(operand){
				case '+':
					printf("You selected sum.\n");
					operand_flag = 1;
					break;
				case '-':
					printf("You selected subtraction.\n");
					operand_flag = 1;
					break;
				case '*':
					printf("You selected multiplication.\n");
					operand_flag = 1;
					break;
				case '/':
					printf("You selected division.\n");
					operand_flag = 1;
					break;
				default:
					printf("Invalid input!\n");
			}
		}

	printf("Now input the two numbers separated by a space\n");
	scanf("%f %f", &op1,&op2);

	switch(operand){
		case '+':
			result = op1+op2;
			break;
		case '-':
			result = op1-op2;
			break;
		case '*':
			result = op1*op2;
			break;
		case '/':
			result = op1/op2;
			break;

	}

	printf("Operation done successfully!\n");
	printf("%c %f", operand, result);


}