#include <stdio.h>

#define maxN 30

int abs(int d);
void ruota(int v[maxN], int N, int P, int dir);


int main() {
    int v[]={1,2,3,4,5,6};
    int N=6;
    int x;
    int new[N];
    int P=3;

    // turning right

    for(int i=0; i<N; i++){
        x = (i + P)%N;
        new[x]=v[i];
    }
    for(int i=0; i<N; i++){
        printf("%d ", new[i]);
    }

    printf("\n");
    // turning left

    for(int i=0; i<N; i++){
        // equivaeìle ad uno spostamento a deestra du N-P
        x = (i+abs(N-P))%N;
        new[x]=v[i];
    }
    for(int i=0; i<N; i++){
        printf("%d ", new[i]);
    }
}


int abs(int d){
    if(d>0) return d;
    if(d<0) return -d;
}
