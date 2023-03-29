#include <stdio.h>

int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);

int is_alpha(char character);

int char_counter=0;


int main(){
	FILE *fin, *fout;
	char sel;
    char file_in[50], file_out[50];

    printf("Inserire C per la codifica. \nInserire D per la decodifica \n");
    scanf("%c", &sel);
    switch(sel){
	    case 'C':
	    	printf("Prego, inserire i nomi dei file di entrata e di uscita, separati da uno spazio. \n");
	    	scanf("%s %s", file_in, file_out);
	    	fin=fopen(file_in, "r"); 
	    	if(fin==NULL){printf("Errore nella lettura del file %s", file_in); return 0;}
	    	fout=fopen(file_out, "w"); 
	    	if(fout==NULL){printf("Errore nella creazione del file %s", file_out); return 0;}

	    	printf("Operazione eseguita con successo! Sono stati scritti %d caratteri. \n", codifica(fin, fout));

	    	fclose(fin); fclose(fout);

	    	break;
	    case 'D':
	    	printf("Prego, inserire i nomi dei file di entrata e di uscita, separati da uno spazio. \n");
	    	scanf("%s %s", file_in, file_out);
	    	fin=fopen(file_in, "r"); 
	    	if(fin==NULL){printf("Errore nella lettura del file %s \n", file_in); return 0;}
	    	fout=fopen(file_out, "w"); 
	    	if(fout==NULL){printf("Errore nella creazione del file %s \n", file_out); return 0;}
	    	
	    	printf("Operazione eseguita con successo! Sono stati scritti %d caratteri. \n", decodifica(fin, fout));

	    	fclose(fin); fclose(fout);
	    	break;
	    default:
	    	printf("Scelta non valida. \n"); 
	    	return 0;
    }

}


int codifica(FILE *fin, FILE *fout){
    char current_char, last_char;
    int num_counter=0, alpha_counter=0, char_counter=0;
    int i;

    fscanf(fin, "%c", &current_char);
    last_char=' ';

    while(!feof(fin)){
        if(current_char <= '9' && current_char >= '0'){ // prende i caratteri numerici
            if(current_char-num_counter>='0'){
                current_char = current_char + num_counter;
                fprintf(fout, "%c", current_char);
                num_counter+=1;
                char_counter+=1;

            }
            else{
                i = num_counter;
                while(current_char+i>'9'){
                    i = i - ('9'-current_char+1);
                    current_char = '0';
                }
                current_char = current_char + i;
                num_counter+=1;
                fprintf(fout, "%c", current_char);
                char_counter+=1;

            }
        }

        else if(is_alpha(current_char)){

            if(!is_alpha(last_char)){
                fprintf(fout, "%c", current_char);
                char_counter+=1;
            }
            else{
                if(is_alpha(last_char)==1){ // last_char maiuscolo
                    alpha_counter = last_char-'A';
                }
                if(is_alpha(last_char)==2){ // last_char minuscolo
                    alpha_counter = last_char-'a';
                }

                if(is_alpha(current_char)==1){ // current_char maiuscolo

                    if(current_char+alpha_counter<='Z'){
                        current_char= current_char+alpha_counter;
                        fprintf(fout, "%c", current_char);
                        char_counter+=1;

                    }
                    else{
                        i = alpha_counter;
                        while(current_char+i>'Z'){
                            i = i - ('Z'-current_char+1);
                            current_char = 'A';
                        }
                        current_char = current_char + i;
                        fprintf(fout, "%c", current_char);
                        char_counter+=1;

                    }

                }

                if(is_alpha(current_char)==2){ // current_char minuscolo
                    if(current_char+alpha_counter<='z'){
                        current_char = current_char+alpha_counter;
                        fprintf(fout, "%c", current_char);
                        char_counter+=1;

                    }
                    else{
                        i = alpha_counter;
                        while((current_char+i)>'z'){
                            i = i - ('z'-current_char+1);
                            current_char = 'a';
                        }
                        current_char = current_char + i;
                        fprintf(fout, "%c", current_char);
                        char_counter+=1;

                    }

                }
            }

        }
        else{
            fprintf(fout,"%c",current_char);
            char_counter+=1;
        }
      

        last_char=current_char;
        fscanf(fin, "%c", &current_char);
    }

    return char_counter;

}        

int decodifica(FILE *fin, FILE *fout){
    char current_char, last_char, newchar;
    int num_counter=0, alpha_counter=0;
    int char_counter=0;
    int i;

    fscanf(fin, "%c", &current_char);
    last_char=' ';

    while(!feof(fin)){
        if(current_char <= '9' && current_char >= '0'){ // prende i caratteri numerici
            if(current_char-num_counter>='0'){
                newchar = current_char - num_counter;
                fprintf(fout, "%c", newchar);
                num_counter+=1;
                char_counter+=1;

            }
            else{
                i = num_counter;
                newchar = current_char;
                while(newchar-i<'0'){
                    i = i - (newchar-'0'+1);
                    newchar = '9';
                }
                newchar = newchar - i;
                num_counter+=1;
                fprintf(fout, "%c", newchar);
                char_counter+=1;

            }
        }

        else if(is_alpha(current_char)){

            if(!is_alpha(last_char)){
                fprintf(fout, "%c", current_char);
                char_counter+=1;

            }

            else{
                if(is_alpha(last_char)==1){ // last_char maiuscolo
                    alpha_counter = last_char-'A';
                }
                if(is_alpha(last_char)==2){ // last_char minuscolo
                    alpha_counter = last_char-'a';
                }

                if(is_alpha(current_char)==1){ // current_char maiuscolo

                    if(current_char-alpha_counter>='A'){
                        newchar = current_char-alpha_counter;
                        fprintf(fout, "%c", newchar);
                        char_counter+=1;

                    }
                    else{
                        i = alpha_counter;
                        newchar = current_char;
                        while(newchar-i<'A'){
                            i = i - (newchar-'A'+1);
                            newchar = 'Z';
                        }
                        newchar = newchar - i;
                        fprintf(fout, "%c", newchar);
                        char_counter+=1;

                    }

                }

                if(is_alpha(current_char)==2){ // current_char minuscolo
                    if(current_char-alpha_counter>='a'){
                        newchar = current_char - alpha_counter;
                        fprintf(fout, "%c", newchar);
                        char_counter+=1;

                    }
                    else{
                        i = alpha_counter;
                        newchar = current_char;
                        while(newchar-i<'a'){
                            i = i - (newchar-'a'+1);
                            newchar = 'z';
                        }
                        newchar = newchar - i;
                        fprintf(fout, "%c", newchar);
                        char_counter+=1;

                    }
                }
            }

        }
        else{
        	fprintf(fout,"%c",current_char);
        	char_counter+=1;
        }
      
        last_char=current_char;
        fscanf(fin, "%c", &current_char);
    }
    return char_counter;

}        

int is_alpha(char character){
    if(character <= 'Z' && character >= 'A'){
        return 1;
    }
    if(character <= 'z' && character >= 'a'){
        return 2;
    }
    else{
        return 0;
    }
}
