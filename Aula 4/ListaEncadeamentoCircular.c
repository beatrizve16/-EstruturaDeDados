//lista de encadeamento circular

#include <stdio.h>
#include <stdlib.h>

//declarar estrutura do no 

struct no {
    int numero; // o * eh o ponteiro e o que esta antes eh para onde ele vai apontar  
    struct no *proximo; // declara o ponteiro 
}; 

//funcao que insere um no na lista 
struct no *inserir(struct no *cabeca, int numero) {
//alocacao do novo no 
struct no *novoNo = (struct no *) malloc(sizeof(struct no));
novoNo -> numero = numero;
novoNo -> proximo = NULL;

//caso facil!Lista vazia!
if ( cabeca== NULL){
    novoNo -> proximo = novoNo; //aponta o proximo no pra ele mesmo
    //ponteiro pro proprio struct no 
    return novoNo;
}
//caso dificil: Lista nao vazia  insercao no fim!
//como achar o final? o proximo aponta para o qual a cabeca esta apontando 
struct no *ultimo = cabeca;
while (ultimo-> proximo != cabeca)
{
ultimo = ultimo -> proximo;

}
ultimo -> proximo = novoNo;
novoNo-> proximo= cabeca;
return cabeca;

}

//funcao que remove um no da lista

struct no *remover(struct no *cabeca, int numero){

// 1 caso muito facil = lista vazia
if (cabeca==NULL)
{
   return cabeca;
}

// 2 caso medio facil = remover o primeiro 

if (cabeca -> numero ==  numero)
{
    if (cabeca == cabeca-> proximo) // 3 remover o unico
    {
free(cabeca);
return NULL;
   }else{ //caso 2 remover o primeiro que nao e unico
    struct no *ultimo = cabeca;
    while (ultimo-> proximo != cabeca)
    {
        ultimo = ultimo -> proximo;
            }
    struct no *excluir = cabeca; // aponta um excluir para a cabeca
    cabeca = cabeca -> proximo; // aponta a cabeca para o proximo do que ele apontava antes
    ultimo -> proximo = cabeca;// o ultimo aponta para a nova cabeca
    free(excluir);

    return cabeca;
   }
    
}

//caso 4 5 6 muito dificil = remover no meio e no final
struct no *ponteiro = cabeca;
while ((ponteiro-> proximo != cabeca) && (ponteiro-> proximo-> numero!= numero)) // 1 olhei tudo e nao achei 2 parei exatamente na posicao anterior da que quero excluir 
{
ponteiro = ponteiro-> proximo;
}

if (ponteiro-> proximo== cabeca) // caso 6 -> nao encontrei
{
return cabeca;
} 
 // caso 4 e 5 = no meio ou no final 
struct no *excluir = ponteiro-> proximo;
ponteiro-> proximo = ponteiro-> proximo-> proximo;
free(excluir);
return cabeca;




}

// funcao que imprimi lista na tela 

void imprimir( struct no *cabeca){

    // caso facil lista vazia
    if (cabeca==NULL){
        return;
    }
   

   
   //caso dificil tem pelo menos um 
   struct no *ponteiro = cabeca;
  do{
printf("%d\n", ponteiro-> numero);
ponteiro= ponteiro -> proximo;
 } while (ponteiro!=cabeca);
     
}


// funcao que constroi um menu na tela 

int menu() {
    int opcao= 0;

    printf("+==============+\n");
    printf("| Menu de Opcoes|\n");
    printf("+==============+\n");
    printf("|1 - Inserir   |\n");
    printf("|2 - Remover   |\n");
    printf("|3 - Imprimir  |\n");
    printf("|4 - Sair      |\n");
    printf("+==============+\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

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
