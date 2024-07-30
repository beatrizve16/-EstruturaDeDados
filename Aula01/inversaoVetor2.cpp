#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//Declarando as variaveis 
	
	int vetorOriginal[5];
	int vetorInvertido[5];
	int i;

	// entrada de dados 
	
	for (i=0; i<5; i++){
		printf("Digite o valor da posicao %d do vetor:  ", i);
		scanf("%d", &vetorOriginal[i]);
	}
	
	//processamento de dados
	for (i = 0; i < 5; i++){
		vetorInvertido[5-1-i]= vetorOriginal[i];
		
	}
	
		//saida de dados 

	for( i = 0; i < 5; i++){
		printf("vetorInvertido[%d]=%d\n" , i, vetorInvertido[i]);
	}
	
}
	

