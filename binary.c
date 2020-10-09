#include <stdio.h>
#include <stdlib.h>

typedef struct No NoArvore;

struct No {
  int valorDoNo;
  struct No* esquerda;
  struct No* direita;
};

NoArvore* criarArvoreVazia(void) {
  return NULL;
}

NoArvore* criarArvore(int valor, NoArvore* esquerda, NoArvore* direita) {
  NoArvore* No=(NoArvore*)malloc(sizeof(NoArvore));
  if(No==NULL) exit(1);
  No->valorDoNo = valor;
  No->esquerda = esquerda;
  No->direita = direita;
  return No;
}

NoArvore* inserir(int valorInformadoParaNo, NoArvore* No) {
  if (No == NULL) {
    No = (NoArvore*)malloc(sizeof(NoArvore));
    No->valorDoNo = valorInformadoParaNo;
    No->esquerda = NULL;
    No->direita = NULL;
  }
  else if (valorInformadoParaNo < No->valorDoNo)
    No->esquerda = inserir(valorInformadoParaNo, No->esquerda);
  else /* valorInformadoParaNo >= a->valorDoNo */
    No->direita = inserir(valorInformadoParaNo, No->direita);
  return No;
}

void imprimir (NoArvore* No, int quantidadeDeNo, int first) {
  if (No != NULL) {
    
    if(No->valorDoNo != NULL && first == 1) {
      int i;
      for (i = 0; i < (quantidadeDeNo - first); i++)
        printf("   ");
      printf("%d\n", No->valorDoNo);
    }

    if(No->esquerda != NULL) {
      int contadorEsquerda;
      for (contadorEsquerda = 0; contadorEsquerda < (quantidadeDeNo - (first + 1)); contadorEsquerda++){
        printf("   ");
      }
      printf("%d", No->esquerda->valorDoNo);
      // imprimirSemQuebra (No->esquerda, quantidadeDeNo, first + 1);
    }

    if(No->direita != NULL) {
      int contadorDireita;
      for (contadorDireita = 0; contadorDireita < (quantidadeDeNo - (first + 5)); contadorDireita++) {
        printf("   ");
      }
      printf("%d", No->direita->valorDoNo);
      // imprimirSemQuebra (No->direita, quantidadeDeNo, first + 1);
    }

    if(No->esquerda != NULL) {
      imprimir (No->esquerda, quantidadeDeNo, first + 1);
    } else if(No->direita != NULL) {
      imprimir (No->direita, quantidadeDeNo, first + 1);
    }
  } else {
    printf("\n");
  }
}

void imprimirSemQuebra (NoArvore* No, int quantidadeDeNo, int first) {
  if (No != NULL) {
    
    if(No->valorDoNo != NULL && first == 1) {
      int i;
      for (i = 0; i < (quantidadeDeNo - first); i++)
        printf("   ");
      printf("%d\n", No->valorDoNo);
    }

    if(No->esquerda != NULL) {
      int contadorEsquerda;
      for (contadorEsquerda = 0; contadorEsquerda < (quantidadeDeNo - (first + 1)); contadorEsquerda++){
        printf("   ");
      }
      printf("%d", No->esquerda->valorDoNo);
      // imprimirSemQuebra (No->esquerda, quantidadeDeNo, first + 1);
    }

    if(No->direita != NULL) {
      int contadorDireita;
      for (contadorDireita = 0; contadorDireita < (quantidadeDeNo - (first + 5)); contadorDireita++) {
        printf("   ");
      }
      printf("%d", No->direita->valorDoNo);
      // imprimirSemQuebra (No->direita, quantidadeDeNo, first + 1);
    }


    // if(No->esquerda != NULL) {
    //   imprimirSemQuebra (No->esquerda, quantidadeDeNo, first + 1);
    // } else if(No->direita != NULL) {
    //   imprimir (No->direita, quantidadeDeNo, first + 1);
    // }

    // imprimir (No->esquerda,quantidadeDeNo, first + 1);
    // imprimirSemQuebra (No->direita,quantidadeDeNo, first + 6);
  } else {
    printf("\n");
  }
}

int main() {
  printf("******************************************************\n");
  printf("\tLhe apresento minha arvore binaria:\n");
  printf("******************************************************\n\n");
  
  NoArvore* raiz = criarArvoreVazia();
  int quantidadeDeNo = 10;
  raiz = criarArvore(6, NULL, NULL);
  // raiz = inserir(6, raiz);

  // printf("%d", raiz->valorDoNo);

  raiz = inserir(4, raiz);
  raiz = inserir(8, raiz);
  raiz = inserir(2, raiz);
  raiz = inserir(5, raiz);
  raiz = inserir(1, raiz);
  raiz = inserir(3, raiz);
  raiz = inserir(7, raiz);
  raiz = inserir(9, raiz);
  raiz = inserir(6, raiz);
  imprimir(raiz, quantidadeDeNo, 1);
  
  
}
