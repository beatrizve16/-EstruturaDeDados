#include <stdio.h>
#include <stdlib.h>

//declaracao da estrutura do no 

struct no {
	int numero;
	struct no *proximo;
};

//funcao que insere o no na lista 

struct no *inserir(struct no *cabeca, int numero){
	//caso facil - lista vazia
	//como sei que esta vazia? nulo 
	if (cabeca == NULL){
		cabeca = (struct no*) malloc(sizeof(struct no)); //qual o tamanho que quero alocar -> um numero e um ponteiro Abre o espaco de memoria faz um cast e aponta a cabeca para o espaco de memoria 
		cabeca -> numero = numero; //-> numero do struct que e apontado pra cabeca, numero = parametro de entrada ( vai insrir o numero na lista)
		cabeca -> proximo = NULL; //aponta para NULL 

		return cabeca;
	}
	
	// caso dificil - lista nao esta vazia
	struct no *ponteiro  = (struct no*) malloc(sizeof(struct no)); // cria outro ponteiro 
	ponteiro -> numero = numero; // aponta para a cabeca 
	ponteiro -> proximo = cabeca; // atualiza o numero novo apontando o numero novo  para o numero 	que estava apontando para a cabeca antes  
	cabeca = ponteiro; // aponta a cabeca para o ponteiro novo 
	
	return cabeca;
}

// funcao que imprimi a lista

void imprimir(struct no *cabeca){
struct no *ponteiro = cabeca; // cria a variavel ponteiro e aponta para a cabeca 

while (ponteiro != NULL){
	printf("%d\n", ponteiro -> numero);
	ponteiro = ponteiro -> proximo; // mudando o lugar da variaveç ponteiro apontando para o proximo do ponteiro 
}
	
}


//funcao principal de execucao do programa 

int main(){
	struct no *cabeca= NULL;
	int i = 0;
	
	for (i=0; i<1000000; i++){
		cabeca = inserir(cabeca,i);
	}
	
	
	imprimir(cabeca);
}


