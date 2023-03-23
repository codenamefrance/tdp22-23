#include <stdio.h>

int main(){

	FILE *fpin, *fpout;
	char current_char, next_char;
	int counter;

	fpin = fopen("sorgente.txt", "r");

	if(fpin==NULL){
		printf("Errore nella lettura del file. \n");
		return 1;
	}

	fpout = fopen("codifica.txt", "w");
	
	if(fpout==NULL){
		printf("Errore nella lettura del file. \n");
		return 1;
	}
	
	fscanf(fpin, "%c", &current_char);
	fscanf(fpin, "%c", &next_char);

	while(!feof(fpin)){
		counter=0;

		while(current_char==next_char && counter<9){
			counter+=1;
			fscanf(fpin, "%c", &next_char);
		}
		if(counter>=2){
			fprintf(fpout, "%c$%d", current_char, counter);
		}
		else{
			if(counter==1){
				fprintf(fpout, "%c%c", current_char, current_char);
			}
			else{
				fprintf(fpout, "%c", current_char);
			}
		}
		current_char=next_char;
		fscanf(fpin, "%c", &next_char);
	}

	fclose(fpout);
	fclose(fpin);

}
