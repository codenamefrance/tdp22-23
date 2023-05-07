#include <stdio.h>
#define MAX 20

/*Qui sono raccolte tutte le informazioni relative alle sottomatrici*/
int submat[50];
int submat_size=0;

void add_to_sub(int sum, int row, int col);
int min(int a, int b);

int main(){
    int nr; int nc;
    int maxsum;

    int sum;
    int dim;

    char filename[MAX+1];
    FILE *fin;

    printf("Please, input filename: \n");
    scanf("%s", &filename);
    fin=fopen(filename, "r");

    if(fin==NULL) return 0;

    fscanf(fin, "%d %d", &nr, &nc);
    int mat[nr][nc];

    // Prendo i dati dal file di ingresso e li trasferisco nella matrice.

    for(int i=0; i<nr; i++){
        for(int j=0; j<nc; j++){
            fscanf(fin, "%d", &mat[i][j]);
        }
    }
    printf("File %s caricato correttamente. Inserisci un valore di dim: \n", filename);
    scanf("%d", &dim);
    while(dim>1 && dim<min(nr, nc)){
        sum=0;
        maxsum=-1;
        /* Print di tutte le sotto-matrici */
        printf("Le sottomatrici quadrate di dimensione %d sono: \n", dim);
        for (int x = 0; x + dim - 1 < nr; x++) {
            for (int y = 0; y + dim - 1 < nc; y++) {
                for (int z = 0; z < dim; z++) { // itera per le righe (z,k semplici counter)
                    for (int k = 0; k < dim; k++) { // itera per le colonne
                        printf("%d ", mat[x + z][y + k]);
                        sum += mat[x + z][y + k];
                    }
                    printf("\n");
                }
                printf("\n");

                /* Updating max sum and adding items to submat array */
                if (sum > maxsum) maxsum = sum;

                if (sum >= maxsum) {
                    add_to_sub(sum, x, y);
                }
                sum = 0;
            }
        }

        /* Print maxsum matrix */
        int l = 0;
        while (l < submat_size) {
            sum = submat[l];
            if (maxsum > 0 && sum == maxsum) {
                printf("\nLa sottomatrice con somma degli elementi massima (%d) e’: \n", maxsum);
                for (int z = 0; z < dim; z++) {
                    for (int k = 0; k < dim; k++) {
                        printf("%d ", mat[submat[l + 1] + z][submat[l + 2] + k]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            l += 3;
        }
        printf("Inserisci un nuovo valore per dim. \n");
        scanf("%d", &dim);
    }


}

void add_to_sub(int sum, int row, int col){
    submat[submat_size]=sum;
    submat[submat_size+1]=row;
    submat[submat_size+2]=col;

    submat_size+=3;
}

int min(int a, int b){
    if(a<b) return a;
    else return b;
}
