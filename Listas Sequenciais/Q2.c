#include <stdio.h>
#include <string.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir_ini (int elemento);
void imprimir();

int main(){

    return 0;
}

void inserir_ini (int elemento){
  if (pos>=MAX)
    printf("Lista Cheia!!\n");
  else{
    for(int i=pos; i>0;i--){
      l[i] = l[i-1];
    }
    l[0] = elemento;
    pos++;
  }  
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}
