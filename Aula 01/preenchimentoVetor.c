#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//Declarando as variaveis 
	
	int vetor[10];
	int i;
	
	// entrada de dados 
	for (i=0; i<10; i++){
		printf("Digite o valor da posicao %d do vetor:  ", i);
		scanf("%d", &vetor[i]);
	}
	
	//saida de dados 
	
	for (i=0; i<10; i++){
		printf("vetor[%d] = %d\n", i , vetor[i]);
	}
	
}
