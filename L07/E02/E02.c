#include <stdio.h>
#define MAX 31

void insertionSort(int vec[MAX], int N);
void selectionSort(int vec[MAX], int N);
void shellSort(int vec[MAX], int N);

int main(){
    int riga[MAX];
    int rows;
    int N, it;
    FILE *fin;


    fin=fopen("sort1.txt", "r");
    fscanf(fin, "%d\n", &rows);

    for(int l=0; l<rows; l++){
        fscanf(fin, "%d", &N);
        for(int m=0; m<N; m++){
            fscanf(fin,"%d",&riga[m]);
        }

        printf("\n\n============START OF ROW %d ANALYSIS======\n\n", l+1);

        shellSort(riga, N);
        printf("\n");
        insertionSort(riga, N);
        printf("\n");
        selectionSort(riga, N);
        printf("\n");

        printf("\n\n=============END OF ROW %D ANALYSIS========\n\n", l+1);
    }


}

void insertionSort(int vec[MAX], int N){

    printf("Insertion sort results: \n");

    int i, j, l=0, x;
    int tot_it=0, ext=0, intern=0, swaps=0;
    for(i=l+1; i<N; i++){
        intern=0;;

        x=vec[i];
        j=i-1;
        /*Prima mi creo lo spazio spostando gli altri, dopo mi metto io*/
        while(x<vec[j] && j>=l){
            vec[j+1]=vec[j];
            j--;
            intern+=1;
            swaps++;
        }
        vec[j+1]=x;
        tot_it+=intern;
        ext++;
        swaps++;

        printf("Passo %d: %d iterazioni interne\n", i+1, intern);
    }
    tot_it+=ext;


    printf("Tot. iterations: %d\n", tot_it);
    printf("Swaps: %d\n", swaps),
    printf("Ext cycle iterations: %d\n", ext);
    printf("Intern. cycle iterations: %d\n", intern);
}


void selectionSort(int vec[MAX], int N){
    int i, j, l=0, r=N-1, min;
    int temp;
    int tot_it=0, ext=0, intern=0, swaps=0;
    for(int i=l;i<r;i++){
        intern=0;

        min=i; //guardo solo indice di riferimento
        for(j=i+1;j<=r;j++){
            if(vec[j]<vec[min])
                min=j;
                intern++;
        }
        if(min!=i){
            swaps++;

            temp=vec[i];
            vec[i]=vec[min];
            vec[min]=temp;
        }
        printf("Passo %d: %d iterazioni interne\n", i+1, intern);
        ext++;
        tot_it+=intern;
    }
    tot_it+=ext;
    
    printf("Selection Sort results: \n");
    printf("Tot. iterations: %d\n", tot_it);
    printf("Swaps: %d\n", swaps),
    printf("Ext cycle iterations: %d\n", ext);
    printf("Intern. cycle iterations: %d\n", intern);
}

void shellSort(int vec[MAX], int N){
    int x, l=0, r=N-1, i, j, h=1;
    int tot_it=0, ext=0, intern=0, swaps=0;

    /* Setting h to his max value*/
    while (h <= N/3){ // Knuth sequence
    h = 3*h+1;
    }
    while(h>=1){
        ext=0;
        for(i = l+h; i<=r ;i++){
            j=i;
            x=vec[i];
            intern=0;
            while(j>=l+h && x<vec[j-h]){
                vec[j] = vec[j-h];
                j-=h;
                intern++;
                swaps++;

            }
            vec[j]=x;
            swaps++;
            ext++;
            printf("Passo %d: %d iterazioni interne\n", i+1, intern);
            tot_it+=intern;
        }
        tot_it+=ext;
        h=h/3;
    }

    printf("Shell Sort results: \n");
    printf("Tot. iterations: %d\n", tot_it);
    printf("Swaps: %d\n", swaps),
    printf("Ext cycle iterations: %d\n", ext);
    printf("Intern. cycle iterations: %d\n", intern);
}
