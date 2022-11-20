#include<stdio.h>
#include <stdlib.h>
//Amália Vitória de Melo - 13692417
//Gabriel Henrique dos Santos - 13783972
//Grazielle Tomaz Neves - 13861176
//Pedro Guilherme Tolvo - 10492012
int busca(int *a, int n, int x);
void quick(int *v, int f, int l);

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    quick(v, 0, n-1);
    scanf("%d\n", &k);
    int vk[k];
    for(i = 0; i < k; i++){
            scanf("%d", &vk[i]);
    }
    for(j = 0; j < k; j++){
       	int resultado = busca(v, n, vk[j]);
        printf("%d\n", resultado);
    }
    return 0; 
}
void quick(int *v, int f, int l){
    if (f >= l) {
        return;
    }
    int m = (l + f)/2;
    int pivot = v[m];
    int i = f;
    int j = l;
    while(1){
        while(v[i] < pivot){
            i++;
        }
        while(v[j] > pivot){
            j--;
        }
        if (i >= j) {
            break;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i++;
        j--;
    }
    quick(v, f, j);
    quick(v, j+1, l);
}
int busca(int* a, int n, int x) { // vetor ordenado
    int c = 0;
    int f = n - 1;
    int m;
    while (c <= f){
        m = (c + f) / 2;
        if (x == a[m])
            return 1;
        else if (x < a[m]){
            f = m - 1;
        }
        else{ 
            c = m + 1;
        }
    }
    return 0;
}

