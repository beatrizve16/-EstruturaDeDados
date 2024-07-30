#include <stdio.h>
#include <stdlib.h>
const int COLUNAS = 3; 
const int LINHAS = 2; 

int main(){
	
//Declarando as variaveis 
	
	int matrizOriginal[LINHAS][COLUNAS];
	int matrizTransposta[COLUNAS][LINHAS];
	int i=0;
	int j=0; 
	
// Entrada de dados 
	
	for (i=0; i<LINHAS; i++){
		for (i=0; i<COLUNAS; i++){
		printf("matrizOriginal[%d][%d]= ", i, j);
		scanf("%d\t", &matrizOriginal[i][j]);
	}	 
}

//processamento de dados 
	for (i=0; i<LINHAS; i++){
		for (i=0; i<COLUNAS; i++){
	matrizTransposta[j][i]= matrizOriginal[i][j];
	}	 
}

//saida de dados 
printf("\n====== Matriz Original ======\n");
for ( i = 0; i< LINHAS; i ++){
	for (j=0; j< COLUNAS ; j++){
		printf("%d\t", matrizOriginal[i][j]);
	}
	printf("\n");
}

printf("\n====== Matriz Transposta ======\n");
for ( i = 0; i< LINHAS; i ++){
	for (j=0; j< COLUNAS ; j++){
		printf("%d\t", matrizTransposta[i][j]);
	}
	printf("\n");
}

}
