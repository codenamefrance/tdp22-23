/* Un file (sorgente.txt) contiene un testo composto da un numero indefinito di righe.
Notare che il testo NON contiene il carattere ‘$’.

Lo scopo del programma è di ricodificare il testo sostituendo 
sequenze di caratteri ripetuti da 2 a 9
volte (ATTENZIONE: il numero non comprende il primo carattere, cioè AA contiene una ripetizione,
BBB due ripetizioni, ecc.) con la terna di caratteri 

<carattere ripetuto>$<numero di ripetizioni>

(ATTENZIONE: per il <numero di ripetizioni> è sufficiente un carattere). Se un carattere fosse
ripetuto più di 9 volte, le ripetizioni sarebbero spezzate in più intervalli.
Ad esempio, la sequenza di caratteri “il numero 1000000 e’ grande”, viene compressa in “il numero
10$5 è grande”. La sequenza, “ci sono 15 = ripetuti: =============== e 4 punti....” viene
ricodificata in: “ci sono 15 = ripetuti: =$9=$4 e 4 punti.$3” 
*/


#include <stdio.h>

int main(){

	FILE *fpin, *fpout;
	char current_char, next_char;
	int counter;

	fpin = fopen("sorgente.txt", "r");
	fpout = fopen("codifica.txt", "w");
	if(fpin==NULL){
		printf("Errore nella lettura del file. \n");
		return 1;
	}
	if(fpout==NULL){
		printf("Errore nella lettura del file. \n");
		return 2;
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
