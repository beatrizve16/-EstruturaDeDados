//programa que implementa uma pilha//

#include <stdio.h>
#include <stdlib.h>

//declaracao da estrutura do no //
struct no
{
int numero;
struct no *proximo;
};

//funcao que insere um no na pilha //

struct no *push(struct no *cabeca, int numero){
//alocacao da memori para o no 

struct no *novoNo = (struct no *) malloc(sizeof(struct no));
novoNo -> numero = numero;
novoNo -> proximo = cabeca;
return novoNo;
}

// funcao que remove umno na pilha//
struct no *pop(struct no *cabeca){
    // caso facil : lista vazia
    if (cabeca==NULL){
        return cabeca;
    }

    //caso medio: lista nao vazia
    struct no *excluir = cabeca;
    cabeca = cabeca-> proximo;
    printf("%d\n", excluir -> numero);
    free(excluir);

    return cabeca;

}


//funcao principal

int main(){

    struct no *pilha = NULL;
    int i;

    for (i = 0; i< 10; i ++){
        pilha = push(pilha,i);
    }

    for (i=0; i<10; i++){
        pilha=pop(pilha);
    }
}
