#include <stdio.h>
#include <stdlib.h>

// Declaracao da estrutura do no 
struct no {
    int numero; // o * eh o ponteiro e o que esta antes eh para onde ele vai apontar 
    struct no *anterior; // declara o ponteiro e diz que ele aponta para o proprio ponteiro 
    struct no *proximo; // declara o ponteiro 
};

// Funcao que insere um no na lista
// Inserir eh o nome 
// O que vem antes eh o valor de retorno e o dentro sao os parametros de entrada 
// Recebe um ponteiro para um struct no (a cabeca) e recebe o numero que quer inserir 
// Ela devolve um ponteiro para o struct no 
struct no *inserir(struct no *cabeca, int numero) {
    // Alocacao de novo no 
    struct no *novoNo = (struct no *)malloc(sizeof(struct no)); // Mostra o tamanho do no??? 
    novoNo->numero = numero;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    // Caso facil lista vazia :)))
    // So apontar a cabeca para o novo no, feliz
    // Atualiza a cabeca e retorna ela vazia 
    if (cabeca == NULL) {
        cabeca = novoNo;
        return cabeca;
    }

    // Caso dificil lista nao vazia :((
    // Saber quem eh o ultimo -> eh o cara cujo proximo aponta para nulo 
    struct no *ultimo = cabeca;
    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }

    // O ULTIMO que
    ultimo->proximo = novoNo; // Apontou o ultimo para o novo no 
    novoNo->anterior = ultimo; // Apontou o anterior do novo no ao novo no 

    return cabeca;
}

// Funcao que remove um no da lista 
struct no *remover(struct no *cabeca, int numero) {
    // Caso muito facil: nao tem nada na lista :D eba
    // Esta vazia quando a cabeca esta nula 
    if (cabeca == NULL) {
        return NULL;
    }

    // Caso medio facil: excluir o primeiro :)
    // Se o anterior for nulo, mas nao precisa se o 
    // numero que tiver na cabeca for o numero que eu quero 
    if (cabeca->numero == numero) {
        // Se o numero que a cabeca aponta eh o numero
        // que quero excluir significa que ele e o primeiro
        struct no *excluir = cabeca;
        // Criei um novo ponteiro excluir e 
        // apontei para a cabeca
        cabeca = cabeca->proximo;
        // Apontei a cabeca para o proximo
        if (cabeca != NULL) {
            cabeca->anterior = NULL; // O anterior do 2 que estava no 1 
            // So pode fazer isso se a cabeca for diferente de nulo, se a
            // lista estiver vazia nao precisa fazer nada 
        }
        free(excluir);
        return cabeca;
    }

    // Cenário difícil: excluir no meio ou fim :(
    struct no *ponteiro = cabeca;
    while ((ponteiro != NULL) && (ponteiro->numero != numero)) {
        // Enquanto o ponteiro estiver apontando para alguma coisa &&
        // Procura ou o numero ou o final da lista 
        ponteiro = ponteiro->proximo;
    }

    if (ponteiro == NULL) {
        return cabeca;
    }

    // 1 2 3 4 
    // Ponteiro aponta para o 2, o anterior eh o 1, 
    // O proximo do ponteiro anterior eh o que aponta para o 2, 
    // Queremos que ele aponte para o proximo ou seja, o 3 
    if (ponteiro->anterior != NULL) {
        ponteiro->anterior->proximo = ponteiro->proximo;
    }

    if (ponteiro->proximo != NULL) { // Cenário de exclusão do último
        ponteiro->proximo->anterior = ponteiro->anterior;
    }

    free(ponteiro);
    return cabeca;
}

// Funcao que imprime os nos da lista 
void imprimir(struct no *cabeca) {
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL) {
        printf("%d, ", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
    printf("\n"); // Corrigido: adicionado o ponto e vírgula
}

// Funcao que modela um menu de opcoes 
int menu() {
    int opcao;

    printf("+==============+\n");
    printf("| Menu de Opcoes|\n");
    printf("+==============+\n");
    printf("| 1 - Inserir  |\n");
    printf("| 2 - Remover  |\n");
    printf("| 3 - Imprimir |\n");
    printf("| 4 - Sair     |\n");
    printf("+==============+\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

// funcao principal de executar o programa!!!

int main(){
    struct no *cabeca = NULL;
   int opcao = 0;
   int numero = 0;

   while (opcao!=4)
   {
opcao = menu();

switch (opcao)
{
case 1:
printf("Digite o numero: ");
scanf("%d" , &numero);
cabeca= inserir(cabeca, numero);
    break;

case 2:
printf("Digite o numero: ");
scanf("%d" , &numero);
cabeca= remover(cabeca, numero);
    break;

case 3:

imprimir(cabeca);
    break;
}

}
   
}
