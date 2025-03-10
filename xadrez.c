#include <stdio.h>

#define TAMANHO_TABULEIRO 8

int main() {
    int torre_x = 0, torre_y = 0;
    char direcao;
    int passos;
    char continuar_movendo;

    printf("Posição inicial da Torre: a1\n");

    do {
        printf("Digite a direção (u para cima, d para baixo, l para esquerda, r para direita): ");
        scanf(" %c", &direcao);
        printf("Digite o número de passos: ");
        scanf("%d", &passos);

        switch (direcao) {
            case 'u':
                if (torre_y + passos < TAMANHO_TABULEIRO) {
                    printf("Torre movida de %c%d para %c%d\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x, torre_y + 1 + passos);
                    torre_y += passos;
                } else {
                    printf("Torre movida de %c%d para %c%d\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x, TAMANHO_TABULEIRO);
                    torre_y = TAMANHO_TABULEIRO - 1;
                }
                break;
            case 'd':
                if (torre_y - passos >= 0) {
                    printf("Torre movida de %c%d para %c%d\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x, torre_y + 1 - passos);
                    torre_y -= passos;
                } else {
                    printf("Torre movida de %c%d para %c1\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x);
                    torre_y = 0;
                }
                break;
            case 'l':
                if (torre_x - passos >= 0) {
                    printf("Torre movida de %c%d para %c%d\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x - passos, torre_y + 1);
                    torre_x -= passos;
                } else {
                    printf("Torre movida de %c%d para a%d\n", 'a' + torre_x, torre_y + 1, torre_y + 1);
                    torre_x = 0;
                }
                break;
            case 'r':
                if (torre_x + passos < TAMANHO_TABULEIRO) {
                    printf("Torre movida de %c%d para %c%d\n", 'a' + torre_x, torre_y + 1, 'a' + torre_x + passos, torre_y + 1);
                    torre_x += passos;
                } else {
                    printf("Torre movida de %c%d para h%d\n", 'a' + torre_x, torre_y + 1, torre_y + 1);
                    torre_x = TAMANHO_TABULEIRO - 1;
                }
                break;
            default:
                printf("Direção inválida.\n");
        }

        printf("Você quer mover a Torre novamente? (s/n): ");
        scanf(" %c", &continuar_movendo);
    } while (continuar_movendo == 's' || continuar_movendo == 'S');

    return 0;
}
