void insertionSort(int * v, int n){

    int i,j,x;

    for(i=1; i<n; i++){
        x=v[i];
        j=i-1;
        while(j>=0 && x<v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
    printf("Ecco il tuo vettore ordinato!\n");

}
