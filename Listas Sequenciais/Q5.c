#include <stdio.h>
#include <stdlib.h>

//-------------------------
//  QUESTÃO 5 - VALDEMORT
//-------------------------

//Criando um registro (struct) para criarmos várias listas com tamanhos distintos (Generalização do código das questões anteriores)

typedef struct {
  unsigned MAX;
  int *arr,pos;
}LISTA; // Nome da struct é LISTA, ou seja, criamos um novo tipo de variável chamado LISTA
/*
#### um adendo -> Na verdade, na verdade, a struct é sem nome! LISTA é um apelido para a struct sem nome. O typedef é usado seguindo a seguinte estrutura:

typedef TIPO_EXISTENTE NOVO_NOME_PARA_TIPO;

Olhando para esse modelo e comparando com o typedef acima, o TIPO_EXISTENTE compreende 'struct {...}', e NOVO_NOME_PARA_TIPO seria LISTA. O programador C costuma fazer isso porque, caso não faça, terá que ficar fazendo 'strct LISTA' toda vez que for criar um registro.

Sem typedef:
struct LISTA l1;

com typedef:
LISTA l1;

*/

void criar(LISTA *lst, int tam_MAX); //Recebe um tipo lista e um tipo inteiro (Essa função cria as listas)
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);

int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


int main() {
  LISTA l1;
  criar(&l1,5);
  inserir_ord(&l1,20);
  inserir_ord(&l1,5);
  inserir_ord(&l1,18);
  inserir_ord(&l1,35);
  inserir_ord(&l1,1);
  inserir_ord(&l1,5000);
  imprimir(&l1);
  printf("%d\n",buscar(&l1,20));
  printf("%d\n",buscar(&l1,500));
  remover(&l1,5);
  remover(&l1,35);
  imprimir(&l1);
  obter(&l1,0);
  obter(&l1,1);
  printf("%d\n",tamanho(&l1));
  apagar(&l1);
  imprimir(&l1);
    
  return 0;
}

void criar(LISTA *lst, int tam_MAX){
  //lst é o elemento do tipo lista. Como estamos passando o ponteiro para o registro, usamos -> para acessar os campos. Caso não fosse um ponteiro, acessamos os campos usando o ponto (.)
  lst-> MAX = tam_MAX; 
  lst -> pos = 0;
  lst -> arr = (int*) malloc(sizeof(int)*lst->MAX);
  
  //Usamos malloc (memory alloc) para alocar memória. Ele recebe a quantidade de bytes a ser alocado. 
  //(int*) - converte ponteiro para o tipo desejado
  //sizeof(tipo)- pega o tamanho de bytes do tipo desejado
  //lst->MAX - Indica a quantidade para alocar
  
  //Caso a memória não puder ser alocada, precisamos abortar o programa.
  //Se a memória não foi alocada. (malloc retorna NULL quando não consegue alocar)
  
  if(lst-> arr == NULL){
    printf("ERRO FATAL! Memoria não pode ser alocada. \n");
    exit(1); //Finaliza o programa com saída de erro
  }   
}

void apagar(LISTA *lst){
  free(lst->arr); //O que alocamos com o malloc devemos desalocar com o free
  //A função free apenas desaloca a memória, não apaga o endereço do ponteiro. Assim, mesmo após o free, o ponteiro continua apontando para o mesmo endereço. Para isso, atribuiremos NULL ao ponteiro.
  lst -> arr = NULL; 
}

void inserir_ord(LISTA *lst, int elemento){

  if(lst->pos >= lst->MAX)
    printf("Lista Cheia!\n");
  else{
  //Encontra a posição que deve entrar
  int p = 0;
  while (p < lst->pos && lst->arr[p] < elemento)
    p++;

  //faz o arrastão para vagar o espaço
  for(int i= lst->pos; i> p; i--)
    lst->arr[i] = lst->arr[i-1];

  //Insere o elemento
  lst-> arr[p] = elemento;
  lst->pos++;
  }
}

void remover(LISTA *lst, int elemento){

  int index = buscar (lst,elemento);
  if(index!=-1){
    for(int i=index; i < lst-> pos-1;i++)
      lst->arr[i] = lst->arr[i+1];
    lst->pos--;
  }
}

int buscar(LISTA *lst, int elemento){
  for(int i=0; i<lst->pos;i++)
    if(lst->arr[i] == elemento)
      return i;
  return -1;
}

int obter(LISTA *lst, int indice){
  if(indice>=0 && indice<lst->pos)
    return lst->arr[indice];
  else{
    printf("Indice Inexistente!\n");
    return 0;
  }
}

int tamanho(LISTA *lst){
  return lst->pos;
}

void imprimir(LISTA *lst){
  printf("[ ");
  for (int i=0; i< lst->pos; i++){
    if(i == lst->pos-1)
      printf("%d ",lst-> arr[i]);
    else
      printf("%d, ",lst-> arr[i]);
  }
  printf("]\n"); 
}