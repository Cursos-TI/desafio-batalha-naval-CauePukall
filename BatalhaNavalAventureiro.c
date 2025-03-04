#include <stdio.h>

int main() {
  
    int tabuleiro[10][10] = {0};
    
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++);
    }

     // Primeiro Navio na horizontal!
     tabuleiro[3][2] = 3;
     tabuleiro[3][3] = 3;
     tabuleiro[3][4] = 3;
     // Segundo navio na vertical!
     tabuleiro[5][7] = 3;
     tabuleiro[6][7] = 3;
     tabuleiro[7][7] = 3;
     // Terceiro navio na diagonal!
     tabuleiro[1][6] = 3;
     tabuleiro[2][7] = 3;
     tabuleiro[3][8] = 3;
     // Quarto navio na diagonal!
     tabuleiro[7][2] = 3;
     tabuleiro[8][3] = 3;
     tabuleiro[9][4] = 3;

     printf("Tabuleiro de Batalha Naval:\n");
     for (int linha = 0; linha < 10; linha++) {
         for (int coluna = 0; coluna < 10; coluna++) {
             printf("%d ", tabuleiro[linha][coluna]);
         }
         printf("\n");
     }

      return 0;
    }
     
  