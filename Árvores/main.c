#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);

int main(){

    return 0;
}

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
   

}