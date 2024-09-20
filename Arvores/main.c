#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

//LISTA 10 - ÁRVORES BINÁRIAS

//Para rodar pelo terminar colocar: g++ *.c (pq como está separado em arquivos as informações,
//  dessa forma o * indica para rodar todos os arquivos de uma vez) -o nome.exe
//Para chamar o arquivo exe, precisa colocar ./'nome.exe'

void mostrarFolhas(struct sNODE *no);
int getMAX(struct sNODE *no);
int getMIN(struct sNODE *no);
int distanciaDaRaiz(struct sNODE *no, int dado);

int main(){

    int l[]={14,7,25,4,9,16,28,2,10,8,15,26,30};

    for(int i=0; i<13; i++)
        raiz = inserir(raiz,l[i]);

    printf("Em Ordem:\n");
    emOrdem(raiz);
    
    printf("\nPre Ordem:\n");
    preOrdem(raiz);

    printf("\nPos Ordem:\n");
    posOrdem(raiz);

    printf("\nMostrar Folhas: \n");
    mostrarFolhas(raiz);

    printf("\nMaior elemento: \n");
    printf("%d", getMAX(raiz));

    printf("\nMenor elemento: \n");
    printf("%d", getMIN(raiz));

    printf("\nDistancia da rais (10): \n");
    printf("%d", distanciaDaRaiz(raiz,10));

    printf("\nDistancia da rais (16): \n");
    printf("%d", distanciaDaRaiz(raiz,16));

    printf("\nDistancia da rais (14): \n");
    printf("%d", distanciaDaRaiz(raiz,14));

    return 0;
}

// QUESTÃO 1


void mostrarFolhas(struct sNODE *no){
    if(no){
        mostrarFolhas(no->esq); //Indica para andar por toda a esquerda primeiro (para ficar na ordem)
        if(no->esq == no->dir) //Printa se for folha
            printf("%d ",no->dado);
        mostrarFolhas(no->dir); //Depois anda todos na direita 
    }
}

// QUESTÃO 2

int getMAX(struct sNODE *no){
    if(no){
        if(!no->dir)
            return no->dado;
        else
            return getMAX(no->dir);
    }
    return 0;
    //OU
    //printf("Árvore Vaiza\n");
    //exit(0);
}

// QUESTÃO 3

int getMIN(struct sNODE *no){
    if(no){
        if(!no->esq)
            return no->dado;
        else
            return getMIN(no->esq);
    }
    printf("Árvore Vaiza\n");
    exit(0);
}

// QUESTÃO 4

int distanciaDaRaiz(struct sNODE *no, int dado){
    if(no){
        if(no->dado == dado)
            return 0;
        else{
            if(dado < no->dado)
                return distanciaDaRaiz(no->esq,dado)+1;
            else
               return distanciaDaRaiz(no->dir,dado)+1;
        }
    }
    printf("Dado não encontrado!\n");
    exit(0);
}