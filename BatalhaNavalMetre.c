#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_MATRIZ_HABILIDADE 5


void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    tabuleiro[2][3] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[7][8] = 3;
}

void criarMatrizHabilidadeCone(int matrizHabilidade[TAMANHO_MATRIZ_HABILIDADE][TAMANHO_MATRIZ_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
            matrizHabilidade[i][j] = 0;
        }
    }
    
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
    
            if (i >= TAMANHO_MATRIZ_HABILIDADE / 2 && 
                j >= TAMANHO_MATRIZ_HABILIDADE / 2 - (i - TAMANHO_MATRIZ_HABILIDADE / 2) && 
                j < TAMANHO_MATRIZ_HABILIDADE / 2 + (i - TAMANHO_MATRIZ_HABILIDADE / 2 + 1)) {
                matrizHabilidade[i][j] = 1;
            }
        }
    }
}

void criarMatrizHabilidadeCruz(int matrizHabilidade[TAMANHO_MATRIZ_HABILIDADE][TAMANHO_MATRIZ_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
            matrizHabilidade[i][j] = 0;
        }
    }

    int centro = TAMANHO_MATRIZ_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        matrizHabilidade[centro][i] = 1;
        matrizHabilidade[i][centro] = 1; 
    }
}

void criarMatrizHabilidadeOctaedro(int matrizHabilidade[TAMANHO_MATRIZ_HABILIDADE][TAMANHO_MATRIZ_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
            matrizHabilidade[i][j] = 0;
        }
    }
 
    int centro = TAMANHO_MATRIZ_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matrizHabilidade[i][j] = 1;
            }
        }
    }
}

void aplicarHabilidadeNoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                   int matrizHabilidade[TAMANHO_MATRIZ_HABILIDADE][TAMANHO_MATRIZ_HABILIDADE], 
                                   int origemX, int origemY) {
    int centroDaHabilidade = TAMANHO_MATRIZ_HABILIDADE / 2;
 
    for (int i = 0; i < TAMANHO_MATRIZ_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ_HABILIDADE; j++) {
           
            int tabuleiroCoordenadaX = origemX - centroDaHabilidade + i;
            int tabuleiroCoordenadaY = origemY - centroDaHabilidade + j;
          
            if (tabuleiroCoordenadaX >= 0 && tabuleiroCoordenadaX < TAMANHO_TABULEIRO && 
                tabuleiroCoordenadaY >= 0 && tabuleiroCoordenadaY < TAMANHO_TABULEIRO) {
              
                if (matrizHabilidade[i][j] == 1) {
                    tabuleiro[tabuleiroCoordenadaX][tabuleiroCoordenadaY] = 5;
                }
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch(tabuleiro[i][j]) {
                case 0:
                    printf(". ");
                    break;
                case 3:
                    printf("S ");
                    break;
                case 5:
                    printf("X ");
                    break;
                default:
                    printf("? ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int matrizHabilidade[TAMANHO_MATRIZ_HABILIDADE][TAMANHO_MATRIZ_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    printf("Efeito da Habilidade de Cone:\n");
    criarMatrizHabilidadeCone(matrizHabilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, matrizHabilidade, 5, 5);
    imprimirTabuleiro(tabuleiro);
    
    inicializarTabuleiro(tabuleiro);

    printf("\nEfeito da Habilidade de Cruz:\n");
    criarMatrizHabilidadeCruz(matrizHabilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, matrizHabilidade, 7, 7);
    imprimirTabuleiro(tabuleiro);
   
    inicializarTabuleiro(tabuleiro);
   
    printf("\nEfeito da Habilidade de Octaedro:\n");
    criarMatrizHabilidadeOctaedro(matrizHabilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, matrizHabilidade, 3, 3);
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
