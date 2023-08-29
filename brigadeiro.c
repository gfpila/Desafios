#include <stdio.h>

//INGREDIENTES POR DOCE
float leite = 1.0/30;
float manteiga = 1.0/30;
float achocolatado = 4.0/30;

void calcularIngredientes(int brigadeiros) {
    float qtdLeite = leite * brigadeiros;
    float qtdManteiga = manteiga * brigadeiros;
    float qtdAchocolatado = achocolatado * brigadeiros;
    printf("Latas de leite: %.2f\nColheres de manteiga: %.2f\nColheres de achocolatado: %.2f\n", qtdLeite, qtdManteiga, qtdAchocolatado);
}

int main (void) {
    printf("Quantos brigadeiros deseja? ");
    int brigadeiros;
    scanf("%d", &brigadeiros);
    calcularIngredientes(brigadeiros);
    printf("Digite 1 para sair\n");
    int sair;
    scanf("%d", &sair);
    return 0;
}
    
