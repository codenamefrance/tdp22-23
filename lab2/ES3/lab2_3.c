#include <stdio.h>

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

int main(){
    FILE *fin, *fout;
    char sel;

    printf("Select what to do: (C/D)  \n");
    scanf("%c", &sel);
    switch(sel){
        case 'C':
            fin=fopen("sorgente.txt", "r");
            fout=fopen("compresso.txt", "w");
            printf("Operazione completata. Sono stampati %d caratteri. \n", comprimi(fin, fout));
            break;
        case 'D':
            fin=fopen("compresso.txt", "r");
            fout=fopen("decompresso.txt", "w");
            printf("Operazione completata. Sono stampati %d caratteri. \n", decomprimi(fin, fout));
            break;
        default:
            printf("Scelta invalida."); return 1;
    }
}


int comprimi(FILE *fin, FILE *fout){

    char current_char, next_char;
    int counter, caratteri=0;

    if(fin==NULL || fout==NULL) return 0;

    fscanf(fin, "%c", &current_char);
    fscanf(fin, "%c", &next_char);

    while(!feof(fin)){
        counter=0;

        while(current_char==next_char && counter<9){
            counter+=1;
            fscanf(fin, "%c", &next_char);
        }
        if(counter>=2){
            fprintf(fout, "%c$%d", current_char, counter);
            caratteri+=3;
        }
        else{
            if(counter==1){
                fprintf(fout, "%c%c", current_char, current_char);
                caratteri+=2;
            }
            else{
                fprintf(fout, "%c", current_char);
                caratteri+=1;
            }
        }
        current_char=next_char;
        fscanf(fin, "%c", &next_char);
    }

    fclose(fout);
    fclose(fin);

    return caratteri;
}
int decomprimi(FILE *fin, FILE *fout){
    int counter, caratteri=0;
    char current_char, next_char;

    if(fin==NULL || fout==NULL) return 0;

    fscanf(fin, "%c", &current_char);
    fscanf(fin, "%c", &next_char);
    while(!feof(fin)){
        if(next_char=='$'){
            fprintf(fout, "%c", current_char);
            caratteri+=1;
            fscanf(fin, "%c", &next_char);
            counter = (int)(next_char)-48;
		
            while(counter>0){
                fprintf(fout, "%c", current_char);
                caratteri+=1;
                counter = counter-1;
            }

            fscanf(fin, "%c", &current_char);
            fscanf(fin, "%c", &next_char);
        }
        else{
            fprintf(fout, "%c", current_char);
            caratteri+=1;
            current_char=next_char;
            fscanf(fin, "%c", &next_char);
        }

    }
    fclose(fin);
    fclose(fout);

    return caratteri;
}
