#include <stdio.h>

// Desafio Batalha Naval - MateCheck

// Definicao das variaveis globais

#define LINHA 10            // define a quantidade de linhas do tabuleiro
#define COLUNA 10           // define a quantidade de colunas do tabuleiro
int x_1 = 0;                // Define em qual linha o navio horizontal sera posicionado (valores de 0 a 9)
int y_1 = 7;                // Define em qual coluna o navio horizontal começará a ser impresso (valores de 0 a 7)
int x_2 = 7;                // Define em qual linha o navio vertical começará a ser impresso (valores de 0 a 7)
int y_2 = 9;                // Define em qual coluna o navio vertical sera posicionado (valores de 0 a 9)
int x_3 = 0;                // Define as linhas de um navio na diagonal (valores de 0 a 7)
int y_3 = 0;                // Define as colunas de um navio na diagonal (valores de 0 a 7)
int x_4 = 9;                // Define as linhas de um navio na diagonal (valores de 3 a 9)
int y_4 = 0;                // Define as colunas de um navio na diagonal (valores 0 a 7)
int origem_ocataedro_x = 0; // Define em qual linha inicia a habilidade octaedro
int origem_ocataedro_y = 3; // Define a partir de qual coluna inicia a habilidade octaedro
int origem_cruz_x = 7;      // Define em qual linha inicia a habilidade cruz
int origem_cruz_y = 3;      // Define a partir de qual coluna inicia a habilidade cruz
int origem_cone_x = 2;      // Define a partir de qual linha inicia a habilidade cone
int origem_cone_y = 5;      // Define a partir de qual coluna inicia a habilidade cone

int main() {

    // define a matriz tabuleiro
    int tabuleiro[LINHA][COLUNA];


    // Loop que atribui 0 a todas os elementos da matriz tabuleiro
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Loop que atribui o valor 3 identificando as coordenadas dos navios vertical, horizontal e diagonal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[x_1][y_1 + i] = 3;        // Navio horizontal
        tabuleiro[x_2 + i][y_2] = 3;        // Navio Vertical
        tabuleiro[x_3 + i][y_3 + i] = 3;    // Navio Diagonal 1
        tabuleiro[x_4 - i][y_4 + i] = 3;    // Navio Diagonal 2
    }

    // Define habilidade cruz
    int cruz[3][5];
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 2)
            {
                cruz[i][j] = 1;
            } else if (i == 1)
            {
                cruz[i][j] = 1;
            } else if (i == 2 && j == 2)
            {
                cruz[i][j] = 1;
            } else if ((i == 0 && j != 2) || (i == 2 && j != 2)){
                cruz[i][j] = 0;
            }
        }
    }

   // Atribui cruz ao tabuleiro
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 5; j++)
       {
            if (cruz[i][j] == 1)
            {
                tabuleiro[i + origem_cruz_x][j + origem_cruz_y] = cruz[i][j];
            }
       }
    }

    // Define habilidade cone
    int cone[3][5];
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 2)
            {
                cone[i][j] = 1;
            } else if (i == 1 && j > 0 && j < 4)
            {
                cone[i][j] = 1;
            } else if (i == 2)
            {
                cone[i][j] = 1;
            } else if ((i == 0 && j != 2) || (i == 2 && (j == 0 || j == 4))){
                cone[i][j] = 0;
            }
        }
    }

   // Atribui cone ao tabuleiro
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 5; j++)
       {
            if (cone[i][j] == 1)
            {
                tabuleiro[i + origem_cone_x][j + origem_cone_y] = cone[i][j];
            }
       }
    }

     // Define octaedro
     int octaedro[3][3];
     for(int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             if (i == 0 && j == 1)
             {
                 octaedro[i][j] = 1;
             } else if (i == 1)
             {
                 octaedro[i][j] = 1;
             } else if (i == 2 && j == 1)
             {
                 octaedro[i][j] = 1;
             } else if ((i == 0 && j != 1) || (i == 2 && j != 1)){
                 octaedro[i][j] = 0;
             }
         }
     }

    // Atribui octaedro ao tabuleiro
     for (int i = 0; i < 3; i++)
     {
        for (int j = 0; j < 3; j++)
        {
            if (octaedro[i][j]  == 1)
            {
                tabuleiro[i + origem_ocataedro_x][j + origem_ocataedro_y] = octaedro[i][j];
            }   
        }
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
    
    return 0;
}
