#include <stdio.h>

#define maxN 30

int abs(int d);
void ruota(int v[maxN], int N, int P, int dir);

int main(){
    int v[maxN];
    int N=6;
    int P;
    int dir;

    for(int y=0; y<N; y++){
        scanf("%d", &v[y]);
    }
    printf("\nOra inserisci un P<N e un valore per la direzione (>0 sx, <0 dx). Digita 0 per uscire\n");
    scanf("%d %d", &P, &dir);
    if(dir==0 || P==0) return 0;
    ruota(v, N, P, dir);
}

void ruota(int v[maxN], int N, int P, int dir){
    int x;
    int new[N];


    if(dir>0) {
        // turning right

        for (int i = 0; i < N; i++) {
            x = (i + P) % N;
            new[x] = v[i];
        }
        for (int i = 0; i < N; i++) {
            printf("%d ", new[i]);
        }
    }
    else{
        // turning left


        for (int i = 0; i < N; i++) {
            // equivaeìle ad uno spostamento a deestra du N-P
            x = (i + abs(N - P)) % N;
            new[x] = v[i];
        }
        for (int i = 0; i < N; i++) {
            printf("%d ", new[i]);
        }

    }
}

int abs(int d){
    if(d>0) return d;
    if(d<0) return -d;
}
