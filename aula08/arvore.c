// ordem-> qtd de filhos da arvore
// nivel-> distancia entre um no e a raiz
// altura-> maior nivel entre todas as folhas da arvore +1

// programa que implementa uma arvore de ordem 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// declaracao da estrutura do no

struct no
{
  int numero;
  struct no *filho1;
  struct no *filho2;
  struct no *filho3;
  struct no *filho4;
  struct no *filho5;
};

// funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero)
{
  // caso facil: arvore vazia
  if (raiz == NULL)
  {
    raiz = (struct no *)malloc(sizeof(struct no));
    raiz->numero = numero;
    raiz->filho1 = NULL;
    raiz->filho2 = NULL;
    raiz->filho3 = NULL;
    raiz->filho4 = NULL;
    raiz->filho5 = NULL;
    return raiz;
  }

  // caso dificil: arvore nao vazia
  int sorteio = (1 + (rand() % 5));
  if (sorteio == 1)
  {
    raiz->filho1 = inserir(raiz->filho1, numero);
  }
  else if (sorteio = 2)
  {
    raiz->filho2 = inserir(raiz->filho2, numero);
  }
  else if (sorteio == 3)
  {
    raiz->filho3 = inserir(raiz->filho3, numero);
  }
  else if (sorteio == 4)
  {
    raiz->filho4 = inserir(raiz->filho4, numero);
  }
  else
  {
    raiz->filho5 = inserir(raiz->filho5, numero);
    return raiz;
  }
}

// funcao que navega a arvore

void navegar(struct no *raiz, int identacao, char *filho)
{
  if (raiz == NULL)
  {
    return;
  }

  int i = 0;
  for (i = 0; i < identacao; i++)
  {
    printf("-");
  }
  printf("%d%s\n", raiz->numero, filho);

  identacao += 3;

  navegar(raiz->filho1, identacao, "(F1)");
  navegar(raiz->filho2, identacao, "(F2)");
  navegar(raiz->filho3, identacao, "(F3)");
  navegar(raiz->filho4, identacao, "(F4)");
  navegar(raiz->filho5, identacao, "(F5)");
}

// funcao principal para rodar o programa

int main()
{
  struct no *arvore = NULL;
  int i = 0;
  for (i = 0; i < 10; i++)
  {
    arvore = inserir(arvore, i);
  }

  navegar(arvore, 0, "");
}
