#include "losowanie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wybieranie.h"
#include "rozgrywka.h"

int main() {
    struct wstep {
        char pytanie[50];
        int wybor;
    };
    struct wstep rozpoczecie;
    strcpy(rozpoczecie.pytanie,"Czy chcesz rozpoczac gre?\n1 - TAK\n0 - NIE\n");

    printf(rozpoczecie.pytanie);
    scanf("%d",&rozpoczecie.wybor);

    switch (rozpoczecie.wybor) {
        case 0: {
            printf("Koniec gry");
            return 0;
        } case 1: {
            int s_bot[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
            int s_gracz[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
            losowanie_statkow(s_bot);
            /*
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("%d ", s_bot[i][j]);
                }
                printf("\n");
            }*/
            printf("Pora na wybranie polozenia statkow!\nPola na ktorych mozesz postawic statek sa oznaczone '~',\n"
                   "pola zajete przez statek 'o', a pola na ktorych nie mozesz postawic statku '.'\n");
            wybor_statkow(s_gracz);
            /*
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("%d ", s_gracz[i][j]);
                }
                printf("\n");
            }*/
            int t_bot[9] = {5, 4, 3, 3, 2, 2, 1, 1, 1};
            int t_gracz[9] = {5, 4, 3, 3, 2, 2, 1, 1, 1};
            int trafione[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
            int p_bot = 0, p_gracz = 0;
            zamiana(s_bot);
            zamiana(s_gracz);
            while (p_bot < 22 && p_gracz < 22) {
                ostrzal_gracz(s_bot, t_gracz, p_gracz, trafione);
                ostrzal_bot(s_gracz, t_bot, p_bot);
            }
        }
    }
}