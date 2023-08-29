#include <stdio.h>
#include <stdlib.h>

/* No jogo, o usuário deve enfrentar o computador. Então, vocês precisam desenvolver alguma forma que o computador gere um valor randômico. Vocês tiveram uma ideia: representar cada jogada com números inteiros, usando uma biblioteca do C, que gera números aleatórios: a stdlib. */

int main (void) {
    printf("Pedra, Papel, Tesoura!\n---------------\n");
    while(1) {
        printf("Digite um valor:\n1: Pedra\n2: Papel\n3: Tesoura\n4: Sair do jogo\n\n");
        int opcao;
        scanf("%d", &opcao);
        int computador = rand() % 3 + 1;    
        // 1 ganha de 3, 2 ganha de 1, 3 ganha de 2
        printf("\n");
        switch (opcao) {
            case 1:
                printf("Voce: Pedra\n");
                if (computador == 2) {
                    printf("Computador: Papel\nVoce perdeu :(\n");
                    break;
                } else if (computador == 1) {
                    printf("Computador: Pedra\nEmpate :|\n");
                    break;
                } else if (computador == 3) {
                    printf("Computador: Tesoura\nVoce ganhou :D\n");
                    break;
                }    
            case 2:
                printf("Voce: Papel\n");
                if (computador == 3) {
                    printf("Computador: Tesoura\nVoce perdeu :(\n");
                    break;
                } else if (computador == 2) {
                    printf("Computador: Papel\nEmpate :|\n");
                    break;
                } else if (computador == 1) {
                    printf("Computador: Pedra\nVoce ganhou :D\n");
                    break;
                }
            case 3:
                printf("Voce: Tesoura\n");
                if (computador == 1) {
                    printf("Computador: Pedra\nVoce perdeu :(\n");
                    break;
                } else if (computador == 3) {
                    printf("Computador: Tesoura\nEmpate :|\n");
                    break;
                } else if (computador == 2) {
                    printf("Computador: Papel\nVoce ganhou :D\n");
                    break;
                }   
            case 4:
                return 0;   
            }
            int jogarDnv;
            printf("\nDeseja jogar novamente?\n1:Sim\n2:Nao\n");
            scanf("%d", &jogarDnv);
            if(jogarDnv == 1) {
                continue;
            } else {
                return 0;
            } 
        }
    }