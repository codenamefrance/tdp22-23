#include <stdio.h>
#include <strings.h>

#define MAX_NR 50
#define MAX_NC 50
#define MAX 20


struct data{
    int indici[2];
    int height;
    int lenght;
    int surface;
};

enum colours {white, black};


void readFile(); //Mi riempie la mappa
int findRegions(int matrix[MAX_NR][MAX_NC], struct data database[MAX]); /*Mi cerca le regioni e me le salva su array */
int getMax(struct data database[MAX], int occurrences); //In base al parametro che gli dò, cerca il max e mi ritorna l'indice da rectangles


struct data rectangles[MAX];
int mat[MAX_NR][MAX_NC];

int main(){

    readFile();

    int rec_num = findRegions(mat, rectangles);

    getMax(rectangles, rec_num);

    return 0;
}
 

void readFile(){

    FILE *fin;
    int nr, nc;

    fin=fopen("mappa.txt", "r");
    if(fin==NULL){
        printf("ERRORE nella lettura del file di ingresso. Sto uscendo... \n ");
    }

    fscanf(fin, "%d %d", &nr, &nc);

    for(int r=0; r<nr; r++){
        for(int c=0; c<nc; c++){
            fscanf(fin, "%d", &mat[r][c]);
        }
    }
    printf("Matrice caricata correttamente!\n");

 }
 int findRegions(int matrix[MAX_NR][MAX_NC], struct data database[MAX]){

    int nr=5;
    int nc=6;
    int len=0, hei=0;
    int index=0;

    for(int j=0; j<nr; j++){
        for(int k=0; k<nc; k++){
            if(matrix[j][k]==black){

                len=1;
                while(matrix[j][k+len]==black && k+len<nc+1){
                    matrix[j][k+len]=white;
                    len+=1;
                }

                hei=1;
                while(matrix[j+hei][k]==black && j+hei<nr+1){
                    matrix[j+hei][k]=white;
                    hei+=1;  
                }

            database[index].indici[0]=j;
            database[index].indici[1]=k;

            database[index].lenght=len;
            database[index].height=hei;
            database[index].surface=len*hei;
            

            hei=0;
            len=0;
            index+=1;
            }
        }
    }
    return index;
 }

int getMax(struct data database[MAX], int occurrences){
    int max_base=0, max_altezza=0, max_area=0; //mi salvo solo l'indice di riferimento

    for(int l=1; l<occurrences; l++){
        if(database[l].lenght>database[max_base].lenght) max_base=l;
        if(database[l].height>database[max_altezza].height) max_altezza=l;
        if(database[l].surface>database[max_area].surface) max_area=l;
    }

    printf("Max base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", database[max_base].indici[0], 
                                                                  database[max_base].indici[1],
                                                                  database[max_base].lenght,
                                                                  database[max_base].height,
                                                                  database[max_base].surface);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", database[max_area].indici[0], 
                                                                  database[max_area].indici[1],
                                                                  database[max_area].lenght,
                                                                  database[max_area].height,
                                                                  database[max_area].surface);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", 
                                                                database[max_altezza].indici[0], 
                                                                database[max_altezza].indici[1],
                                                                database[max_altezza].lenght,
                                                                database[max_altezza].height,
                                                                database[max_altezza].surface);
                                        



}
