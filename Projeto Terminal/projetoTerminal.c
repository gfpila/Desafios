#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

    //lOOP PROGRAMA
    while (1) {

        //INICIAR FUNÇÕES
        initscr();
        start_color();

        //COR
        init_pair(1, COLOR_BLUE, COLOR_BLACK);

        //DELCARAR VARIAVEIS DA JANELA
        int altura, largura, starty, startx;
        altura = 20;
        largura = 40;
        startx = (COLS - largura) / 2;
        starty = (LINES - altura) / 2;

        //INSTANCIAR JANELA
        WINDOW *janela = newwin(altura, largura, starty, startx);
        refresh();

        //DESENHAR INTERFACE
        wattron(janela, COLOR_PAIR(1) | A_BOLD);
        wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
        
        //TEXTO JANELA
        mvwprintw(janela, 3, 13, "Digite um BILL");
        mvwprintw(janela, 6, 6, "BILL #1: Calcular Media");
        mvwprintw(janela, 7, 6, "BILL #2: Calcular Combustivel");
        mvwprintw(janela, 8, 6, "BILL #3: Converter ASCII");
        mvwprintw(janela, 9, 6, "BILL #4: Converter Temperatura");
        mvwprintw(janela, 10, 6, "BILL #5: Calcular Hipotenusa");
        mvwprintw(janela, 11, 6, "BILL #6: Sair do Programa");
        mvwprintw(janela, 14, 7, "Digite um numero de 1 a 6:");

        wrefresh(janela);

        //PROMPT
        char input[50];
        mvwscanw(janela, 16, 19, "%s", input);
        if(strlen(input) == 1 && input[0] >= '1' && input[0] <= '6') {
            wclear(janela);
        } 
        else {
            wclear(janela);
            wrefresh(janela);
            continue;
        }

        //TELAS
        int opcao = input[0] - '0';

        switch (opcao) {

            case 1: //1 - Dadas as duas notas de um aluno, informe a sua média final.
                int redesenhar = 0;
                float nota1;
                float nota2;
                while(1) {
                    //TELA
                    wrefresh(janela);
                    wattron(janela, COLOR_PAIR(1) | A_BOLD);
                    wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
                    mvwprintw(janela, 3, 12, "Calcular Media:");
                    mvwprintw(janela, 6, 7, "      ______ ______      ");
                    mvwprintw(janela, 7, 7, "    //      Y      \\  ");
                    mvwprintw(janela, 8, 7, "   // ~~ ~~ | ~~ ~  \\   ");
                    mvwprintw(janela, 9, 7, "  // ~ ~ ~~ | ~~~ ~~ \\  ");
                    mvwprintw(janela, 10, 7, " //________.|.________\\ ");
                    mvwprintw(janela, 11, 7, "`----------`-'----------'");

                    //INPUT
                    if (redesenhar == 0) {
                        mvwprintw(janela, 13, 10, "Nota 1: ");
                        mvwprintw(janela, 14, 10, "Nota 2: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 13, 17, "%f", &nota1) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }
                    }
                    else if (redesenhar == 1) {
                        mvwprintw(janela, 13, 10, "Nota 1: %f", nota1);
                        mvwprintw(janela, 14, 10, "Nota 2: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 14, 17, "%f", &nota2) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }  
                    }
                    else if(redesenhar == 2) {
                        mvwprintw(janela, 13, 11, "Nota 1: %f", nota1);
                        mvwprintw(janela, 14, 11, "Nota 2: %f", nota2);
                        float media = (nota1 + nota2)/2;
                        mvwprintw(janela, 16, 11, "Media: %f", media);
                    }
                    mvwprintw(janela, 18, 8, "Pressione enter para sair");
                    wrefresh(janela);
                    getch();
                    break;
                }
                break;

            case 2: //Dados uma distância e o total de litros de combustível gasto por um automóvel para percorrê-la, informe o consumo médio.
                redesenhar = 0;
                float distancia;
                float litros;
                while(1) {
                    //TELA
                    wrefresh(janela);
                    wattron(janela, COLOR_PAIR(1) | A_BOLD);
                    wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
                    mvwprintw(janela, 4, 6, "Calcular Combustivel (KM/L):");
                    mvwprintw(janela, 7, 4, "   _-_-  _/\\______\\__    ");
                    mvwprintw(janela, 8, 4,  " _-_-__  / ,-. -|-  ,-.`-.");
                    mvwprintw(janela, 9, 4,"    _-_- `( o )----( o )-'");
                    mvwprintw(janela, 10, 4, "           `-'      `-'   ");

                    //INPUT
                    if (redesenhar == 0) {
                        mvwprintw(janela, 13, 9, "Distancia: ");
                        mvwprintw(janela, 14, 9, "Litros Gastos: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 13, 19, "%f", &distancia) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }
                    }
                    else if (redesenhar == 1) {
                        mvwprintw(janela, 13, 9, "Distancia: %f", distancia);
                        mvwprintw(janela, 14, 9, "Litros Gastos: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 14, 23, "%f", &litros) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }  
                    }
                    else if(redesenhar == 2) {
                        mvwprintw(janela, 13, 9, "Distancia: %f", distancia);
                        mvwprintw(janela, 14, 9, "Litros Gastos: %f", litros);
                        float consumo = distancia/litros;
                        mvwprintw(janela, 16, 4, "Consumo: %f litros por KM", consumo);
                    }
                    mvwprintw(janela, 18, 8, "Pressione enter para sair");
                    wrefresh(janela);
                    getch();
                    break;
                }
                break;

            case 3:
                redesenhar = 0;
                char caractere[50];
                while(1) {
                    //TELA
                    wrefresh(janela);
                    wattron(janela, COLOR_PAIR(1) | A_BOLD);
                    wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
                    mvwprintw(janela, 3, 12, "Converter ASCII:");
                    mvwprintw(janela, 6, 5, "    _    ____   ____ ___ ___ ");
                    mvwprintw(janela, 7, 5,  "   / \\  / ___| / ___|_ _|_ _|");
                    mvwprintw(janela, 8, 5,"  / _ \\ \\___ \\| |    | | | | ");
                    mvwprintw(janela, 9, 5, " / ___ \\ ___) | |___ | | | | ");
                    mvwprintw(janela, 10, 5, "/_/   \\_\\____/ \\____|___|___|");

                    //INPUT
                    if (redesenhar == 0) {
                        mvwprintw(janela, 13, 5, "Caracter: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 13, 15, "%s", &caractere) == 1 && strlen(caractere) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }
                    }
                    else if(redesenhar == 1) {
                        mvwprintw(janela, 13, 5, "Caracter: %s", caractere);
                        int ascii = caractere[0];
                        mvwprintw(janela, 15, 5, "Valor ASCII: %d", ascii);
                        mvwprintw(janela, 16, 5, "Valor Hexadecimal: 0x%x", ascii);
                    }
                    mvwprintw(janela, 18, 8, "Pressione enter para sair");
                    wrefresh(janela);
                    getch();
                    break;
                }
                break;

            case 4: //4 - Dada um temperatura em graus Fahrenheit, informe o valor correspondente em graus Celsius.
                redesenhar = 0;
                float temperatura;
                while(1) {
                    //TELA
                    wrefresh(janela);
                    wattron(janela, COLOR_PAIR(1) | A_BOLD);
                    wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
                    mvwprintw(janela, 3, 9, "Converter Temperatura:");
                    mvwprintw(janela, 6, 16, "    _   ");
                    mvwprintw(janela, 7, 16, " - | |  ");
                    mvwprintw(janela, 8, 16, " - | |  ");
                    mvwprintw(janela, 9, 16, " - | |  ");
                    mvwprintw(janela, 10, 16, " - | |  ");
                    mvwprintw(janela, 11, 16, "  (___) ");

                    //INPUT
                    if (redesenhar == 0) {
                        mvwprintw(janela, 14, 3, "Temp. Fahrenheit: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 14, 21, "%f", &temperatura) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }
                    }
                    else if(redesenhar == 1) {
                        float celsius = (temperatura - 32) * 5/9;
                        mvwprintw(janela, 14, 3, "Temp. Fahrenheit: %f", temperatura);
                        mvwprintw(janela, 16, 3, "Temp. Celsius: %f", celsius);
                    }
                    mvwprintw(janela, 18, 8, "Pressione enter para sair");
                    wrefresh(janela);
                    getch();
                    break;
                }
                break;

            case 5: //Dadas as medidas dos catetos de um triângulo retângulo, informe a medida da hipotenusa
                redesenhar = 0;
                float cateto1;
                float cateto2;
                while(1) {
                    //TELA
                    wrefresh(janela);
                    wattron(janela, COLOR_PAIR(1) | A_BOLD);
                    wborder(janela, '|', '|', '-', '-', '+', '+', '+', '+');
                    mvwprintw(janela, 2, 9, "Calcular Hipotenusa (M): ");
                    mvwprintw(janela, 5, 17, "|\\     ");
                    mvwprintw(janela, 6, 17, "| \\    ");
                    mvwprintw(janela, 7, 17, "|  \\   ");
                    mvwprintw(janela, 8, 17, "|   \\  ");
                    mvwprintw(janela, 9, 17, "|    \\ ");
                    mvwprintw(janela, 10, 17, "|_____\\");

                    //INPUT
                    if (redesenhar == 0) {
                        mvwprintw(janela, 13, 4, "Primeiro Cateto: ");
                        mvwprintw(janela, 14, 4, "Segundo Cateto: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 13, 21, "%f", &cateto1) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }
                    }
                    else if (redesenhar == 1) {
                        mvwprintw(janela, 13, 4, "Primeiro Cateto: %f", cateto1);
                        mvwprintw(janela, 14, 4, "Segundo Cateto: ");
                        wrefresh(janela);
                        if (mvwscanw(janela, 14, 20, "%f", &cateto2) == 1) {
                            redesenhar++;
                            wclear(janela);
                            continue;
                        }
                        else {
                            wclear(janela);
                            continue;
                        }  
                    }
                    else if(redesenhar == 2) {
                        mvwprintw(janela, 13, 4, "Primeiro Cateto: %f", cateto1);
                        mvwprintw(janela, 14, 4, "Segundo Cateto: %f", cateto2);
                        float hipotenusa = sqrt( (cateto1 * cateto1) + (cateto2 * cateto2) );

                        mvwprintw(janela, 16, 4, "Hipotenusa: %f", hipotenusa);
                    }
                    mvwprintw(janela, 18, 8, "Pressione enter para sair");
                    wrefresh(janela);
                    getch();
                    break;
                }
                break;

            case 6:
                clear();
                refresh();
                return 0;                
            }
        wclear(janela);
        wrefresh(janela);
    }
}