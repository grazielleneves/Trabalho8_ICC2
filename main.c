#include<stdio.h>
#include <stdlib.h>
//Faça um programa em C que leia um número N de elementos de um vetor de inteiros V, e em seguida leia os N elementos de V.
//Após isso, leia um número inteiro K, seguido da leitura de K inteiros. 
//O seu programa deverá busca todos os K números no vetor V, e escrever 1 se o elemento foi encontrado em V e 0 caso contrário.
int busca(int *a, int n, int x);
void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);

int main(){
    int n, i, j, k;
    scanf("%d", &n);

    int *v = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    mergeSort(v, 0, n-1);
    scanf("%d\n", &k);
    int *vk = (int *) malloc(k * sizeof(int));
    for(i = 0; i < n; i++){
            scanf("%d", &vk[i]);
        }
        
    //int aux;
    for(j = 0; j < k; j++){
       	//aux = v[j];
       	int resultado = busca(v, n, vk[j]);
        printf("%d\n", resultado);
    }

    return 0;
    
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int busca(int* a, int n, int x) { // vetor ordenado
    int c = 0;
    int f = n - 1;
    int m;
    //int verifica = 0;
    while (c <= f)
    {
        m = (c + f) / 2;
        if (x == a[m])
            return 1;
        else if (x < a[m])
        {
            f = m - 1;
        }
        else
        { // x > a[m]
            c = m + 1;
        }
    }
    return 0;
}

