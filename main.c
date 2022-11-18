#include<stdio.h>
//Faça um programa em C que leia um número N de elementos de um vetor de inteiros V, e em seguida leia os N elementos de V.
//Após isso, leia um número inteiro K, seguido da leitura de K inteiros. 
//O seu programa deverá busca todos os K números no vetor V, e escrever 1 se o elemento foi encontrado em V e 0 caso contrário.
void busca(int *v, int num, int n);

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d\n", &k);
    //int vb[k];
    int num;
    for(j = 0; j < k; j++){
        scanf("%d", &num);
        busca(v, num, n);
    }
    
}
void busca(int *v, int num, int n){
    int i, verifica = 0;
    for(i = 0; i < n; i++){
        if(num==v[i]){
           verifica = 1; 
        }
        /*else{
            printf("0\n");
        }*/
    }
    if(verifica==1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}
