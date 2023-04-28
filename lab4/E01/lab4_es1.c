#include <stdio.h>
#define maxN 31

//idea! Trasformare il sottovettore in una struct con relativo contatore.

void sottoSequenze(int V[], int N);

int main(){
    int V[maxN]; int N=0;
    FILE *fin;

    fin=fopen("vectors.txt", "r");
    if(fin==NULL) return 0;

    while(!feof(fin)){
        fscanf(fin, "%d", &V[N]);
        N+=1;
    }
    if(N!=0){
        sottoSequenze(V, N);
    }

}

void sottoSequenze(int V[], int N){

    int subN=0;
    int maxlen=0; int curlen=0;
    int eov=0;
    int subV[31];

    /* Leggo i vettori dal vettore principale. Man mano mi salvo le lunghezze e i rispettivi indici nel
    sotto vettore */

    for(int i=0; i<N; i++){
        if(V[i]==0) eov=1;
        if(i==N-1){
            curlen+=1;
            eov=1;
        }
        if(!eov) {
            curlen += 1;

            for (int j = i + 1; j < N && !eov; j++) {
                if (V[j] == 0) eov = 1;
                else {
                    curlen += 1;
                }

            }
            if (curlen > maxlen) maxlen = curlen;

            /* Per risparmiare tempo, decido fin da subito di salvare mano a mano i massimi relativi, invece
            di salvarli tutti */
            if (curlen == maxlen) {
                subV[subN] = curlen;
                subV[subN + 1] = i;
                subN += 2;
            }
        }
        eov=0;
        curlen=0;
    }

    // Ora leggo i dati salvati in subV, scritti nella coppia (lunghezza del vettore-indice di inizio)
    if(maxlen!=0){
        int start_index;
        int x = 0;
        while (x < subN) {
            curlen = subV[x];
            if (curlen == maxlen) {
                start_index = subV[x + 1];
                for (int j = 0; j < curlen; j++) {
                    printf("%d ", V[start_index + j]);
                }
                printf("\n");
            }
            x += 2;
        }
    }
}
