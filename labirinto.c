/* Desenvolvido por: Thiago Negri ( hunz ) */
/* Email: tn_negri@hotmail.com */

#include <stdio.h>
#include <stdlib.h>

/* Definicoes, para facilitar o uso da funcao para desenhar o mapa */
#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define GRAMA 3
#define OUTRA_COISA 4

/* Definicoes que eu uso em quase todos os meus codigos :) */
#define OK 1
#define ERRO 2

/* Usuarios de Windows, troquem "clear" por "cls" */
#define LIMPARTELA "cls"

int    coluna_atual = 2,
   linha_atual = 2;

/* O Mapa */
int mapa[10][10] = { 
1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,1,0,1,
1,0,0,0,0,1,1,1,0,1,
1,0,0,0,0,3,0,0,0,1,
1,0,0,1,3,3,3,0,0,1,
1,0,0,0,0,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,
1,1,1,4,4,4,4,1,0,1,
1,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1 
};

/* Funcao para desenhar o Mapa */
int desenhar_mapa()
{
   int linha,coluna;
   for (linha=0;linha<10;linha++) {
      for (coluna=0;coluna<10;coluna++) {
         if ((linha == linha_atual) && (coluna == coluna_atual)) {
            printf("@");
            continue;
         }
         if (mapa[linha][coluna] == CHAO)
            printf(" ");
         if (mapa[linha][coluna] == PAREDE)
            printf("*");
         if (mapa[linha][coluna] == GRAMA)
            printf(".");
         if (mapa[linha][coluna] == OUTRA_COISA)
            printf("+");
      }
      printf("\n");
   }
   return OK;
}

int main()
{
   char movimento;
   while ((movimento != 'x') && (movimento != 'X')) {
      system(LIMPARTELA);
      desenhar_mapa();
      printf("\n\n  (N)\n(W)+(E)\n  (S)\n\n"); /* Imprime as direcoes */
      if ((scanf("%c",&movimento))==0) {
         printf("mensagem de erro..\n");
         getchar(); getchar();
         return ERRO;
      }
      if ((movimento == 'n') || (movimento == 'N')) {
         linha_atual = linha_atual - 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != GRAMA)) {
            linha_atual = linha_atual + 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 's') || (movimento == 'S')) {
         linha_atual = linha_atual + 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != GRAMA)) {
            linha_atual = linha_atual - 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'e') || (movimento == 'E')) {
         coluna_atual = coluna_atual + 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != GRAMA)) {
            coluna_atual = coluna_atual - 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'w') || (movimento == 'W')) {
         coluna_atual = coluna_atual - 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != GRAMA)) {
            coluna_atual = coluna_atual + 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
   }
}