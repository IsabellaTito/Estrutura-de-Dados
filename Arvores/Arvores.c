#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

struct sNODE *raiz = NULL;

struct sNODE *inserir(struct sNODE *no, int dado){
    if(!no){
        no = (struct sNODE*) malloc(sizeof(struct sNODE));
        no->dado = dado;
        no->dir = no->esq = NULL;
    }
    else if(dado < no->dado)
        no->esq = inserir(no->esq,dado);
    else
        no->dir = inserir(no->dir,dado);
    return no;
}

struct sNODE *remover(struct sNODE *no, int dado){
    struct sNODE *aux = NULL, *aux2=NULL;
    if(no){
        if(no->dado == dado){
            if(no->esq == no->dir){//folha
                free(no);
                return NULL;
            }
            else if(no->dir == NULL){//filho da esq
                aux = no->esq;
                free(no);
                return aux;
            }
            else if(no->esq == NULL){//filho da dir
                aux = no->dir;
                free(no);
                return aux;
            }
            else{//ambos os filhos
                aux = aux2 = no->dir;
                while(aux2->esq)
                    aux2 = aux2->esq;
                aux2->esq = no->esq;
                free(no);
                return aux;
            }    
        }
        else if(dado < no->dado)
            no->esq = remover(no->esq,dado);
        else
            no->dir = remover(no->dir,dado);
    }
    return no;
}

void emOrdem(struct sNODE *no){
   if(no){
    emOrdem(no->esq);
    printf("%d ", no->dado);
    emOrdem(no->dir);
   }
}

void preOrdem(struct sNODE *no){
    if(no){
        printf("%d ", no->dado);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(struct sNODE *no){
    if(no){
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d ", no->dado);
    }
}

struct sNODE *buscar(struct sNODE *no, int dado){
    if(no){
        if(no->dado == dado)
            return no;
        else if(dado < no->dado)
            return buscar(no->esq,dado);
        else
           return buscar(no->dir,dado);
    }
    return NULL;
}

int obter(struct sNODE *no){
    if(no)
        return no->dado;
    printf("Nenhum dado para retornar\n");
    exit(0);
}

struct sNODE *apagar(struct sNODE *no){
    if(no){
        apagar(no->esq);
        apagar(no->dir);
        free(no);
    }
    return NULL;
}