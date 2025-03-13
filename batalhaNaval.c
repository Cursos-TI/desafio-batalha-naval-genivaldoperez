#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10
int x_1 = 1; // Define em qual linha o navio horizontal sera posicionado (valores de 0 a 9)
int y_1 = 7; // Define em qual coluna o navio horizontal começará a ser impresso (valores de 0 a 7)
int x_2 = 7; // Define em qual linha o navio vertical começará a ser impresso (valores de 0 a 7)
int y_2 = 7; // Define em qual coluna o navio vertical sera posicionado (valores de 0 a 9)

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[LINHA][COLUNA];


    // Loop que atribui 0 a todas os elementos da matriz tabuleiro
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Loop que atribui o valor 3 nas coordenadas dos navios vertical e horizontal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[x_1][y_1 + i] = 3;
        tabuleiro[x_2 + i][y_2] = 3;
    }
    
    //Loop que imprime o tabuleiro do jogo
    for (int i = 0; i < 10; i++)
    {
        if (i == 0){
            printf("   ");
            int contador = 0;
            char coluna = 'A';
            while (contador < 10)
            {
                printf("%c ", coluna + contador);
                contador++;
            }
            printf("\n");
        }
        
        if (i == 9){
            printf("%d ", i + 1);
        } else {
            printf("%d  ", i + 1);
        }
        
        int j = 0;
        while (j < 10)
        {
            printf("%d ", tabuleiro[i][j]);
            j++;
        }
        printf("\n");    
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
