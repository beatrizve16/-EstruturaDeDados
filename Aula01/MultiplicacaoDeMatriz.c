#include <stdio.h>
# define LIN1 2 
#define COL1_LIN2 3
#define COL2 2 

int main(){
	//declaracao de variaveis 
	int operando1[LIN1][COL1_LIN2];
	int operando2 [COL1_LIN2][COL2];
	int resultado[LIN1][COL2];
	
	int i;
	int j;
	int k;
	
	//entrada de dados 
	for (i=0; i<LIN1; i++){
		for (j=0; j<COL1_LIN2; j++){
			printf("Operando1[%d][%d]=", i, j);
			scanf("%d", &operando1[i][j]);
		}
	}
	
	for (i=0; i<COL1_LIN2; i++){
		for (j=0; j<COL2; j++){
			printf("Operando2[%d][%d]=", i, j);
			scanf("%d", &operando2[i][j]);
		}
	}
	
	//processamento 
	for ( i =0; i<LIN1; i++){
		for (j=0; j<COL2; j++){
			resultado[i][j]=0;
			for (k=0; k<COL1_LIN2; k++){
				resultado[i][j]+= (operando1[i][k] * operando2[k][j]);
			}
		}
	}
	
	// saida de dados 
	for (i=0; i<LIN1; i++){
		for (j=0; j<COL2; j++){
			printf("%d\t", resultado[i][j]);
		}
		
		printf("\n");
	}
}
