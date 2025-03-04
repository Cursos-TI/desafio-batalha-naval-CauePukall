#include <stdio.h>

int main() {
  
    int tabuleiro[10][10];
    
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // Colocar um navio horizontal
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[3][4] = 3;
    
    // Colocar um navio vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    
    printf("Tabuleiro de Batalha Naval:\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    return 0;
}