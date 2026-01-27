#include "losowanie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int spr(int lista[10][10], int x, int y, int s, int poz) {
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

void otoczenie(int lista[10][10], int x, int y) {
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

void losowanie_statkow(int (lista)[10][10]) {
    int w[9] = {5,4,3,3,2,2,1,1,1};
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        int poz, x, y;
        int s = w[i];
        poz = rand() % 2;
        if (poz == 0) {
            x = rand() % (10-s);
            y = rand() % 10;
        } else {
            x = rand() % 10;
            y = rand() % (10-s);
        }
        while (spr(lista, x, y, s, poz) != 1) {
            poz = rand() % 2;
            if (poz == 0) {
                x = rand() % (10-s);
                y = rand() % 10;
            } else {
                x = rand() % 10;
                y = rand() % (10-s);
            }
        }
        if (poz == 0) {
            for (int j = 0; j < s; j++) {
                otoczenie(lista, x, y+j);
            }
            for (int j = 0; j < s; j++) {
                lista[x][y+j] = i+1;
            }
        } else {
            for (int j = 0; j < s; j++) {
                otoczenie(lista, x+j, y);
            }
            for (int j = 0; j < s; j++) {
                lista[x+j][y] = i+1;
            }
        }
    }
}