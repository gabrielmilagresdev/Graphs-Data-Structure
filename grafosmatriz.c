#include <stdio.h>
#include <stdlib.h>

typedef int Bool;

#define TRUE 1
#define FALSE 0

//Função para inicializar a matriz completamente zerada
void inicializar(int **m, int v){
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            m[i][j] = 0;
}

//Função para imprimir o grafo em matriz
void imprimirGrafo(int **m, int v){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

//Função para verificar se uma aresta existe
Bool arestaExiste(int **m, int v, int a, int b){
    if(a >= v || a < 0 || b>=v || b<0){
        printf("Posicao invalida\n");
        return FALSE;
    }
    if(m[a][b] == 1){
        printf("A aresta %d -> %d existe\n",a,b);
        return TRUE;
    }
    printf("A aresta %d -> %d nao existe\n",a,b);
    return FALSE;
}

//Função para inserir uma aresta
Bool inserirAresta(int **m, int v, int a, int b){
    if(a >= v || a < 0 || b>=v || b<0){
        printf("Posicao invalida\n");
        return FALSE;
    }
    m[a][b] = 1;
    return TRUE;
}

int main(){
    //Tamanho da matriz quadrada
    int v = 5;

    //Alocando a matriz
    int** m = (int**) malloc(v * sizeof(int*));
    for(int i = 0; i < v; i++){
        m[i] = (int*) malloc(v* sizeof(int));
    }

    inicializar(m,v);
    inserirAresta(m,v,1,3);
    inserirAresta(m,v,0,1);
    inserirAresta(m,v,2,2);
    inserirAresta(m,v,3,2);
    imprimirGrafo(m,v);
}