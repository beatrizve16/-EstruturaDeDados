///////////////////////////////////////
/// programa que implementa percurso em grafos//
////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


///////////////////////////////////////
/// declaracao de constantes ////////////
/////////////////////////////////////////


#define QTD_VERTICES 4

////////////////////////////////////////////
//// funcao que constroi um grafo //////////
///////////////////////////////////////////

void construir(int grafo[QTD_VERTICES][QTD_VERTICES], int aleatorio){
   // declaracao de variaveis 
    int i, j, adjacencia;

    //inicializacao da estrutura 
    for (i=0; i< QTD_VERTICES; i++){
        for (j=0; j<QTD_VERTICES; j++){
            grafo[i][j]=0;
        }
    }

    //construcao propriamente dita 
    for (i=0; i<(QTD_VERTICES-1); i++){
        for(j=(i+1); j< QTD_VERTICES; i++){
            if(aleatorio){
                adjacencia=((( rand() %5 ) ==1 ) ? 1 : 0 );
            } else {
                printf("Digite <1> se %d for adjacente a %d: ", i, j);
                scanf("%d", &adjacencia);
            }

            grafo[i][j] = adjacencia;
            grafo[i][j]= adjacencia;
        }
    }
}

////////////////////////////////////////////////////////
// funcao recursiva que procura um percurso em um grafo //
/////////////////////////////////////////////////////////////

int procurarPercursoRecursivo (int grafo[QTD_VERTICES][QTD_VERTICES],
                                int visitado[QTD_VERTICES],
                                int inicio, int fim){
    int vizinho = 0;
    int retorno = 0;

    if(inicio == fim){
        return 1;
    }

    visitado[inicio] = 1;
    for(vizinho = 0; vizinho < QTD_VERTICES; vizinho ++){
        if((grafo[inicio][vizinho]) && (! visitado [vizinho])){
            if(procurarPercursoRecursivo(
                grafo, visitado, vizinho, fim)) {
                    retorno = 1;
                    printf("%d <-" , vizinho);
                    break;
                }
        }
    }

    return retorno;
}

void procurarPercurso(int grafo[QTD_VERTICES][QTD_VERTICES],
                        int inicio, int fim){
    int i = 0;
    int visitado[QTD_VERTICES];

    for (i = 0; i < QTD_VERTICES; i ++){
        visitado[i] = 0;
            }

        if (procurarPercursoRecursivo(grafo, visitado, inicio, fim)){
            printf("%d\n", inicio);

        } else{
            printf("No ha caminho \n");
        }
                        }


///////////////////////////////////////////////////////////////////
/// funcao principal de execucao do prigrama /////////////////////
//////////////////////////////////////////////////////////////////

int main(){
    // declaracao de variaveis 

    int grafo[QTD_VERTICES][QTD_VERTICES];
    int inicio, fim;

    // inicializacao da aleatoriedade 
    time_t t;
    srand(time(&t));

    // construcao do grafo 
    construir(grafo, 0);

    // desocberta de caminhos 
    while(1) {
        printf("Digite o vertice inicial : ");
        scanf("%d", &inicio);

        printf("Digite o vertice final ");
        scanf("%d", &fim);
    }
}
