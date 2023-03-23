#include <stdio.h>

int main(){

	FILE *fpin, *fpout, *fpdec;
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
	

// FUNZIONE DI CODIFICA

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
	fprintf(fpout,"\n");

	fclose(fpout);
	fclose(fpin);


// FUNZIONE DI DECODIFICA

	fpout = fopen("codifica.txt", "r");
	
	if(fpout==NULL){
		printf("Errore nella lettura del file. \n");
		return 1;
	}

	fpdec = fopen("decoded.txt", "w");
	
	if(fpdec==NULL){
		printf("Errore nella lettura del file. \n");
		return 1;
	}

	fscanf(fpout, "%c", &current_char);
	fscanf(fpout, "%c", &next_char);

	while(!feof(fpout)){
		if(next_char=='$'){
			fprintf(fpout,"%c",current_char);

			fscanf(fpout, "%d", &counter);
			for(counter;counter>=0;counter-=1){
				fprintf(fpdec,"%c",current_char);
			}
		}
		else{
			fprintf(fpdec, "%c%c", current_char, next_char);
		}
		
		fscanf(fpin, "%c", &current_char);
		fscanf(fpin, "%c", &next_char);

	fclose(fpdec);
	fclose(fpout);
	
	}
}
