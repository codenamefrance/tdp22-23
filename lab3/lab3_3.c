#include <stdio.h>

#define filename "numeri.txt"

void verifyFromFile(FILE *fin);
int verificaTerna(float a, float b, float c);



int main(){
	FILE *fin;
	fin=fopen(filename, "r");
	verifyFromFile(fin);
	fclose(fin);
}


void verifyFromFile(FILE *fin){

	float num1, num2, num3;
	int max, min;
	int discarded=0;

	fscanf(fin, "%f%f%f", &num1, &num2, &num3);

	if(num1>num2){
		max=num1;
		min=num2;
	}
	else{
		min=num1;
		max=num2;
	}

	while(!feof(fin)){
		if(verificaTerna(num1, num2, num3)){
			max = num3>max?num3:max;
			min = num3<min?num3:min;
			
			num1=num2;
			num2=num3;
			fscanf(fin, "%f", &num3);

		}
		else{
			fscanf(fin, "%f", &num3);
			discarded+=1;

		}

	}

	printf("Numero massimo: %d \nNumero minimo: %d \nNumeri scartati: %d\n", max, min, discarded);

}

int verificaTerna(float a, float b, float c){

	int valid=0;

	if(a+b==c)
		valid=1;

	if(a-b==c || b-a==c)
		valid=1;

	if(a*b==c)
		valid=1;

	if(b!=0 && a/b==c || a!=0 && b/a==c)
		valid=1;

	return valid;
}
