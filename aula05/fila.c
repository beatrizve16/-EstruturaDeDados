//programa que implementa uma fila//

#include <stdio.h>
#include <stdlib.h>

//declaracao da estrutura do no //
struct no
{
int numero;
struct no *proximo;
};


// funcao que insere o no na fila //

struct no *entrar(struct no *cabeca, int numero){
//alocacao da memori para o no 

struct no *novoNo = (struct no *) malloc(sizeof(struct no));
novoNo -> numero = numero;
novoNo -> proximo = cabeca;
return novoNo;
}

// funcao que remove um no da fila//
struct no *remover(struct no *cabeca){
//caso facil ; fila vazia 
if ( cabeca== NULL){
    return NULL;
}

//caso medio facil: fila so tem um unico no 
if(cabeca -> proximo == NULL){
    printf("%d\n", cabeca -> numero);
    free(cabeca);
    return NULL;
}

//caso dificil : fila tem varios nos 
struct no *ponteiro = cabeca;
while (ponteiro-> proximo->proximo!=NULL)
{
ponteiro= ponteiro->proximo;
}

printf("%d\n", ponteiro-> proximo->  numero);
free(ponteiro->proximo);
ponteiro->proximo=NULL;
return cabeca;
}

int main(){

    struct no *fila = NULL;
    int i;

    for (i = 0; i< 10; i ++){
        fila = entrar(fila,i);
    }

    for (i=0; i<10; i++){
        fila=sair(fila);
    }
}
