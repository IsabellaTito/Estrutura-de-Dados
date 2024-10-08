#include <stdio.h>
#include <string.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(char str[]);
int buscar(char str[]);
void remover(char str[]);
char* obter(int indice);
int tamanho();
void imprimir();
void apagar();


int main(){

    return 0;
}


void inserir(char str[]){
  if (pos>=MAX)
    printf("Lista Cheia!!\n");
  else{
    strcpy(l[pos], str);
    pos++;    
  }
}

int buscar(char str[]){
  for(int i=0; i<pos; i++)
    if(strcmp(l[i],str) == 0){
      return i;
      break;
    }
  return -1;
} 

void remover(char str[]){
  int strin = buscar(str);
  if(strin == -1)
    printf("Elemento não encontrado na lista!\n");
  else{
    for(int i=strin; i<pos-1; i++)
      strcpy(l[i], l[i+1]);
    pos--;
  }
}

char* obter(int indice){
  return l[indice];
}

int tamanho(){
  return pos;
  
}

void imprimir(){
  printf("[ ");
  for(int i=0; i<pos;i++){
    if(i==pos-1)
    printf("%s ",l[i]);
    else
      printf("%s, ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  pos = 0;
}
