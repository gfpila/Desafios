#include <stdio.h>
#include <windows.h>
/*
1- Vermelho
2 - Verde
3 - Amarelo

O algoritmo deverá inicializar essa variável com 1, indicando a cor vermelha. Na sequência, o algoritmo deve iniciar uma repetição que deve:

- Mostrar o nome da cor correspondente à variável COR (utilizar um procedimento que cumpra esse objetivo);
- Na sequência, chamar outra função que mude o valor da variável COR, conforme a sequência de funcionamento do semáforo.

Assim como um semáforo, o algoritmo não precisa ter condição de parada, ele pode ser repetido infinitamente!
*/

void mudarCor (int *pointerSemaforo, int semaforoAtual) {
    switch (*pointerSemaforo)
    {
    case 1:
        //Se vermelho mude para o verde.
        *pointerSemaforo = 2;
        break;
    
    case 2:
        //Se verde mude para o vermelho
        *pointerSemaforo = 3;
        break;
    case 3:
        //Se amarelo mude para o vermelho
        *pointerSemaforo = 1;
        break;
    }        

}

int main (void) {
    int numSemaforo = 1;
    int *pointerSemaforo = &numSemaforo;
    while(1) {
        switch (numSemaforo)
        {
        case 1:
            printf("VERMELHO\n");
            //Espere 15 e mude para verde
            Sleep(15000);
            mudarCor(pointerSemaforo, numSemaforo);
            break;
        case 2:
            printf("VERDE\n");
            //Espere 15 e mude para amarelo
            Sleep(15000);
            mudarCor(pointerSemaforo, numSemaforo);
            break;
        case 3:
            //Espere 3 e mude para vermelho 
            printf("AMARELO\n");
            Sleep(3000);
            mudarCor(pointerSemaforo, numSemaforo);
            break;
        }     
    }   
}
