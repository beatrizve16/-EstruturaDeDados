//////////////////////////////////////////////////////
////// programa que implementa uma arvore de busca//////
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////////////
//////////declaracao da estrutura do no //////
///////////////////////////////////////////////

struct no{
    int numero;
    struct no *esquerda;
    struct no *direita;
};

///////////////////////////////////////////////
/// funcao que insere um no na arvore /////////
///////////////////////////////////////////////

struct no *inserir(struct no *raiz, int numero){

    //caso facil :D arvore vazia!! 
    if(raiz ==NULL){
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz-> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    }

    //caso dificil :( arvore nao vazia!!
    if(raiz -> numero > numero){
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    } else{
        raiz -> direita = inserir(raiz -> direita, numero);
    }
    return;
}

///////////////////////////////////////////////
/// funcao que procura um no na arvore /////////
///////////////////////////////////////////////


void procurar(struct no *raiz, int numero){
    //caso muito facil :D
    if(raiz == NULL){
        printf("Numero nao encontrado :(\n");
        return;
    }

    //caso facil :) numero procurado esta na raiz 

    if(raiz -> numero == numero ){
        printf("Parabens!!! Numero encontrado :)\n");
        return;
    }


    // caso dificil:( numero Nao esta na raiz
    if(raiz -> numero > numero){
        procurar(raiz-> esquerda , numero);
    } else{
        procurar(raiz-> direita, numero);
    }
}



/////////////////////////////////////////////////
/// funcao que navega a arvore em ordem //////////
/////////////////////////////////////////////////

void navegarEmOrdem(struct no *raiz){
    if(raiz == NULL){
        return;
    }

    navegarEmOrdem(raiz -> esquerda);
    printf("%d, ", raiz -> numero);
    navegarEmOrdem(raiz -> direita);
}

///////////////////////////////////////////////////
/// funcao principal de execução do programa /////
/////////////////////////////////////////////////


int main()
{
//declaração de variaveis 
struct no *arvore = NULL;
int i = 0;
int numero= 0;

// iniciação da aleatoriedade 
time_t t;
srand(time(&t));

// construção da árvore 
for(i=0; i<100; i++){
    arvore= inserir(arvore, rand()%100);
}

// navegação da árvore 
navegarEmOrdem(arvore);
printf("\n");

// procurando nos
while(1){
    printf("Digite um numero:");
    scanf("%d", &numero);
    procurar(arvore,numero);
}

} 

