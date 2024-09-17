///////////////////////////////////////////////////
////programa que implementa uma matriz esparsa/////
//////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////
///// declaração de constantes ///////////////////
/////////////////////////////////////////////////

#define MODULO 16

//////////////////////////////////////////////////
///////////declaração das estruturas /////////////
//////////////////////////////////////////////////

struct no
{
    int numero;
    struct no *proximoNo;
};

struct diretor
{
    int resto;
    struct no *proximoNo;      // ponteiro para a horizontal
    struct no *proximoDiretor; // ponteiro para a vertical
};

/////////////////////////////////////////////////////
//////função cria um diretor novo //////////////////
///////////////////////////////////////////////////

struct diretor *criarDiretor(struct diretor *cabeca, int resto)
{
    struct diretor *novoDiretor = (struct diretor *)malloc(sizeof(struct diretor));
    novoDiretor->resto = resto;
    novoDiretor->proximoNo = NULL;
    novoDiretor->proximoDiretor = cabeca;
    return novoDiretor;
}
/////////////////////////////////////////////////////
//////função que procura o diretor correto /////////
///////////////////////////////////////////////////

struct diretir *procurarDiretor(struct diretor *cabeca, int resto)
{
    struct diretor *ponteiroDiretor = cabeca;
    while ((ponteiroDiretor != NULL) && (ponteiroDiretor->resto != resto))
    {
        ponteiroDiretor = ponteiroDiretor->proximoDiretor;
    }

    return ponteiroDiretor;
}

///////////////////////////////////////////////////////////
///////função que insere um no na matriz esparsa////////////
//////////////////////////////////////////////////////////

struct diretor *inserir(struct diretor *cabeca, int numero)
{
    // procurar o diretor correto
    struct diretor *ponteiroDiretor = procurarDiretor(cabeca, (numero % MODULO));

    if (ponteiroDiretor == NULL)
    {
        cabeca = criarDiretor(cabeca, (numero % MODULO));
        ponteiroDiretor = cabeca;
    }
    // inserção propriamente dita

    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->numero = numero;
    novoNo->proximoNo = ponteiroDiretor->proximoNo;
    ponteiroDiretor->proximoNo = novoNo;

    return cabeca;
}

//////////////////////////////////////////////////////////
//////função que imprime a matriz esparsa na tela/////////
/////////////////////////////////////////////////////////

void imprimir(struct diretor *cabeca)
{
    struct diretor *ponteiroDiretor = cabeca;
    while (ponteiroDiretor != NULL)
    {

        printf("%d\t", ponteiroDiretor->resto);
        struct no *ponteiroNo = ponteiroDiretor->proximoNo;
        while (ponteiroNo != NULL)
        {
            printf("%d, ", ponteiroNo->numero);
            ponteiroNo = ponteiroNo->proximoNo;
        }

        printf("\n");
        ponteiroDiretor = ponteiroDiretor->proximoDiretor;
    }
}

///////////////////////////////////////////////////////////
////////funçao que remove um no da matriz esparsa//////////
//////////////////////////////////////////////////////////

void remover(struct diretor *cabeca, int numero){
//cenario muito facil :D matriz vazia
if(cabeca==NULL){
    return;
}

// cenario medio facil :)) nao encontrou o diretor
struct diretor *ponteiroDiretor = procurarDiretor(cabeca,(numero % MODULO));
if(ponteiroDiretor==NULL){
    return;
}

//cenario facil :) lista do diretor correto vazia
if(ponteiroDiretor -> proximoNo==NULL){
    return;
}

//cenario medio :/ excluir o primeiro 
if(ponteiroDiretor->proximoNo->numero == numero){
    struct no *excluir = ponteiroDiretor -> proximoNo;
    ponteiroDiretor->proximoNo = ponteiroDiretor ->proximoNo->proximoNo;

    free(excluir);
    return;
}

//procurar um no a ser removido
struct no *anterior = ponteiroDiretor->proximoNo;

while((anterior->proximoNo != NULL) && (anterior -> proximoNo->numero!=numero)){
    anterior = anterior -> proximoNo;
}

//cenario medio dificil :( nao encontrei um numero na lista
if(anterior->proximoNo==NULL){
    return;
}

//cenario dificil :(( excluir no meio ou no final
struct no *excluir = anterior -> proximoNo;
anterior -> proximoNo = anterior -> proximoNo-> proximoNo;
free(excluir);

}







///////////////////////////////////////////////////////////
//////////função principal de execução do programa/////////
////////////////////////////////////////////////////////

int main()
{
    struct diretor *matrizEsparsa = NULL;
    int i = 0;
    for (i = 0; i < 50; i++)
    {
        matrizEsparsa = inserir(matrizEsparsa, i);
    }
imprimir(matrizEsparsa);


printf("====================================\n");
   for (i = 0; i < 10; i++)
    {
       remover(matrizEsparsa, i);
    }
 for (i = 40; i < 50; i++)
    {
       remover(matrizEsparsa, i);
    }
imprimir(matrizEsparsa);
}
