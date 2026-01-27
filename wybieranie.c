#include "wybieranie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mapa(int lista[10][10]) {
    for (int j = 0; j < 10; j++) {
        if (j == 0) {printf("   A B C D E F G H I J\n");}
        for (int k = 0; k < 10; k++) {
            if (k == 0) {printf("%d ", j+1);}
            if (j != 9 && k == 0) {
                if (lista[j][k] == 0) {printf(" ~ ");}
                else if (lista[j][k] == 10) {printf(" . ");}
                else {printf(" o ");}
            } else {
                if (lista[j][k] == 0) {printf("~ ");}
                else if (lista[j][k] == 10) {printf(". ");}
                else {printf("o ");}
            }
        }
        printf("\n");
    }
}

int spraw(int lista[10][10], int x, int y, int s, int poz) {
    if (poz != 0 && poz != 1) {
        return 0;
    }
    if (poz == 0) {
        for (int j = 0; j < s; j++) {
            if (lista[x][y+j] != 0) {return 0;}
            if (y+j > 9) {return 0;}
        }
    } else {
        for (int j = 0; j < s; j++) {
            if (lista[x+j][y] != 0) {return 0;}
            if (x+j > 9) {return 0;}
        }
    }
    return 1;
}

void otoczenie_s(int lista[10][10], int x, int y) {
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            if (i>=0 && i<=9 && j>=0 && j <=9) {
                if (lista[i][j] == 0) {
                    lista[i][j] = 10;
                }
            }
        }
    }
}

void wybor_statkow(int lista[10][10]) {
    int w[9] = {5,4,3,3,2,2,1,1,1};
    int i = 0;
    while (i < 9) {
        int poz, x;
        char y;
        int s = w[i];
        mapa(lista);
        printf("Podaj wspolrzedne poczatku statku o dlugosci %d [rzad kolumna]: ", s);
        if (scanf("%d %c", &x, &y) != 2) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        }

        printf("Podaj czy statek ma byc ustawiony poziomo [0], czy pionowo [1]: ");
        if (scanf("%d", &poz) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        }

        x -= 1;
        y = (int)y - 65;
        while (spraw(lista, x, y, s, poz) != 1) {
            printf("Blad we wspolrzednych. Sprobuj ponownie.\n");
            printf("Podaj wspolrzedne poczatku statku o dlugosci %d [rzad kolumna]: ", s);
            if (scanf("%d %c", &x, &y) != 2) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    continue;
                }
            }
            printf("Podaj czy statek ma byc ustawiony poziomo [0], czy pionowo [1]: ");
            if (scanf("%d", &poz) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    continue;
                }
            }
            x -= 1;
            y = (int)y - 65;
        }
        if (poz == 0) {
            for (int j = 0; j < s; j++) {
                otoczenie_s(lista, x, y+j);
            }
            for (int j = 0; j < s; j++) {
                lista[x][y+j] = i+1;
            }
        } else {
            for (int j = 0; j < s; j++) {
                otoczenie_s(lista, x+j, y);
            }
            for (int j = 0; j < s; j++) {
                lista[x+j][y] = i+1;
            }
        }
        i += 1;
    }
}