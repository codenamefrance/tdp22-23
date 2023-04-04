#define filein "input.txt"
#define fileout "out.txt"

#include <stdio.h>
#include <ctype.h>

int is_punteggiatura(char carattere);

int main(){

	FILE *fin, *fout;

	int char_count;
	char cur_char, next_char;
	int i;
	int up_flag=1;

	fin=fopen(filein, "r");
	fout=fopen(fileout, "w");

	if(fin==NULL || fout==NULL) return 0;

	fscanf(fin, "%c", &cur_char); 
	fscanf(fin, "%c", &next_char); 

	while(!feof(fin)){
		i=0;
		while(i<25){
			if(isalpha(cur_char)){
				if(up_flag==1){
					cur_char = toupper(cur_char); up_flag=0;
				}
				fprintf(fout, "%c", cur_char);
				char_count+=1;
			}
			else{
				if(isdigit(cur_char)){
					fprintf(fout, "*");
					char_count+=1;
				}
				else if(cur_char=='\n'){
					while(i<25){
						fprintf(fout, " ");
						i++;
					}
				}
				else if(is_punteggiatura(cur_char)){ 
					fprintf(fout, "%c", cur_char);
					char_count+=1;

					if(cur_char != ' ' && next_char != ' ' && next_char != '\n'){
						fprintf(fout, " "); i++;
					}
					if(cur_char=='?' || cur_char=='!' || cur_char == '.'){
						up_flag=1;
					}
				}
				else{
					fprintf(fout, "%c" ,cur_char);
					char_count+=1;
				}
			}

			i++;
			cur_char = next_char;
			fscanf(fin, "%c", &next_char);
		}
	
		fprintf(fout, "| c:%d \n", char_count);
		char_count=0;
	}
}

int is_punteggiatura(char carattere){

	if(carattere=='!'||carattere=='.' ||carattere==' '||carattere==39 ||carattere==';' || carattere==':' ||carattere==','||carattere=='?')
		return 1;
	else
		return 0;
}
