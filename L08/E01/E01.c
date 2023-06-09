#include <stdio.h>
#define MAXR 50

enum colours {white, black};

void leggiMatrice(int mat[MAXR][MAXR], int max ,int *nr,int *nc);
int riconosciRegione(int matrix[MAXR][MAXR], int rows, int cols, int x, int y,int *base, int *altezza);


int main(){

    int matrice[MAXR][MAXR];
    int nrow, ncol;

    leggiMatrice(matrice,MAXR,&nrow,&ncol);

    printf("\n NR:%d NC:%d \n", nrow, ncol);

    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    int lbase, lalt;
    int xi=1 ,yk=2;

    if(riconosciRegione(matrice, nrow, ncol, xi, yk, &lbase, &lalt)){
        printf("Ho trovato una matrice con estremo (%d,%d). Ecco le tue informazioni: \n", xi, yk);
        printf("Base: %d\n", lbase);
        printf("Altezza: %d\n", lalt);
    }
    else{
        printf("Purtroppo all'estremo (%d,%d) non inizia alcuna matrice.\n", xi, yk);
    }

    return 0;
}

int riconosciRegione(int matrix[MAXR][MAXR], int rows, int cols, int x, int y,int *base, int *altezza){

    int len=0, hei=0;
    int j,k;
    int row_flag=0, col_flag=0;

    if(matrix[x][y]!=black) return 0;

    // Ora devo capire se l'indice che mi è stato dato è un inizio


    if(y>0){
        if(matrix[x][y-1] == black ) return 0;
    }
    if(x>0){
        if(matrix[x-1][y] == black) return 0;
    }

    // Se supera il controllo precedente, è un indice di partenza.

    for(j=x; j<rows && !row_flag; j++){
        for(k=y; k<cols && !col_flag; k++){
            if(matrix[j][k]==black){
                len=1;
                while(matrix[j][k+len]==black && k+len<cols+1){
                    len+=1;
                }
                row_flag=1;

                hei=1;
                while(matrix[j+hei][k]==black && j+hei<rows+1){
                    matrix[j+hei][k]=white;
                    hei+=1;  
                }
                col_flag=1;
            }
        }
    }

    *base = len;
    *altezza = hei;

    return 1;
}

void leggiMatrice(int mat[MAXR][MAXR], int max ,int *nr,int *nc){

    FILE *fin;

    fin=fopen("mappa.txt", "r");

    fscanf(fin, "%d %d", nr, nc);

    for(int r=0; r<*nr; r++){
        for(int c=0; c<*nc; c++){
            fscanf(fin, "%d", &mat[r][c]);
        }
    }
    printf("Matrice caricata correttamente!\n");

}
