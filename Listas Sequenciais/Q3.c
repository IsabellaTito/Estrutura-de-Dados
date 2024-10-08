#include <stdio.h>
#include <string.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir_semrep(int elemento);
void inserir_SRBusc(int elemento);
void remover_all(int elemento);
int buscar(int elemento);
void imprimir();


int main(){

    return 0;
}

//SEM USAR O BUSCAR

void inserir_semrep(int elemento){
  if (pos>=MAX)
    printf("Lista Cheia!!\n");
  else{
    int check=0;
    for(int i = 0; i<pos;i++)
      if(l[i] == elemento){
        check = 1;
        printf("Este elemento já está na lista!\n");
        break;
      }
    if(check == 0){
      l[pos] = elemento;
      pos++;
    }
  }  
}

//USANDO A FUNÇÃO BUSCAR

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
	if (l[i] == elemento)
  	return i;
  }
  return -1;
}

void inserir_SRBusc(int elemento){
  if (pos>=MAX)
    printf("Lista Cheia!!\n");
  else{
    if(buscar(elemento) == -1 ){
      l[pos] = elemento;
      pos++;
    }
    else
      printf("Este elemento já está na lista!\n");
  } 
}

void remover_all(int elemento){
  int index = buscar(elemento);
  while (index != -1){
    for(int i=index; i < pos-1; i++)
      l[i] = l[i+1];
    pos--;
    index = buscar(elemento);
  }
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}