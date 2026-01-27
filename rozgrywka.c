#include "rozgrywka.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mapa_2(int lista[10][10]) {
    for (int j = 0; j < 10; j++) {
        if (j == 0) {printf("   A B C D E F G H I J\n");}
        for (int k = 0; k < 10; k++) {
            if (k == 0) {printf("%d ", j+1);}
            if (j != 9 && k == 0) {
                if (lista[j][k] == 0) {printf(" ~ ");}
                else if (lista[j][k] == 10) {printf(" X ");}
                else {printf(" o ");}
            } else {
                if (lista[j][k] == 0) {printf("~ ");}
                else if (lista[j][k] == 10) {printf("X ");}
                else {printf("o ");}
            }
        }
        printf("\n");
    }
}

void zamiana(int lista[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (lista[i][j] == 0 || lista[i][j] == 10) {
                lista[i][j] = 0;
            }
        }
    }
}
void ostrzal_bot(int lista[10][10], int trafienia[9], int punkty) {
    zamiana(lista);
    int x, y;
    srand(time(NULL));
    x = rand() % 10;
    y = rand() % 10;
    while (lista[x][y] == 10) {
        x = rand() % 10;
        y = rand() % 10;
    }
    if (lista[x][y] != 0) {
        punkty += 1;
        int a = lista[x][y];
        trafienia[a - 1] -= 1;
        lista[x][y] = 10;
        if (trafienia[a - 1] == 0) {
            mapa_2(lista);
            printf("O nie! Zostales zatopiony!\n");
        } else {
            mapa_2(lista);
            printf("O nie! Zostales trafiony\n");
        }
        ostrzal_bot(lista, trafienia, punkty);
    } else {
        lista[y][x] = 10;
        mapa_2(lista);
        printf("Jestes caly.\n");
    }
}

void ostrzal_gracz(int lista[10][10], int trafienia[9], int punkty, int lista_2[10][10]) {
    zamiana(lista);
    int x;
    char y;
    mapa_2(lista_2);
    printf("Podaj wspolrzedne strzalu [rzad kolumna]: ");
    if (scanf("%d %c", &x, &y) != 2) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            continue;
        }
    }
    x -= 1;
    y = (int)y - 65;
    while (x < 0 || x > 10 || y < 0 || y > 10) {
        printf("Blad we wspolrzednych. Sprobuj ponownie.\n");
        printf("Podaj wspolrzedne strzalu [rzad kolumna]: ");
        if (scanf("%d %c", &x, &y) != 2) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        }
        x -= 1;
        y = (int)y - 65;
    }

    if (lista[x][y] == 10) {
        printf("W ten punkt juz strzelales. Wybierz punkt jeszcze raz.\n");
        ostrzal_gracz(lista, trafienia, punkty, lista_2);
    } else {
        if (lista[x][y] != 0) {
            punkty += 1;
            int a = lista[x][y];
            trafienia[a - 1] -= 1;
            lista[x][y] = 10;
            lista_2[x][y] = 1;
            if (trafienia[a - 1] == 0) {
                mapa_2(lista_2);
                printf("Zatopiony!\n");
            } else {
                mapa_2(lista_2);
                printf("Trafiony\n");
            }
            ostrzal_gracz(lista, trafienia, punkty, lista_2);
        } else {
            lista[x][y] = 10;
            lista_2[x][y] = 10;
            mapa_2(lista_2);
            printf("Pudlo!\n");
        }
    }
}
