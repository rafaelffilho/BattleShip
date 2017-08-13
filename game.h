#ifndef GAME
#define GAME

#define VERTICAL 0x0
#define HORIZONTAL 0x1

#include <ctime>

void outline(int x, int y, int size, int rotation, int** matrix){
    if(rotation == VERTICAL){
        matrix[x-1][y] = 66;
        for (int i = y; i < y + size; i++) {

        }
    } else {

    }
}

void insNormaShip(int code, int size, int rotation, int** matrix){
    srand(time(NULL));
    int x;
    int y;
    bool quit = true;
    if(rotation == VERTICAL){
        do {
            quit = true;
            x = rand() % 14;
            y = rand() % 14 - size;
            y = (y < 0) ? 0 : y;
            for (int i = y; i < y + size; i++)
                    if(matrix[i][y] != 0)
                        quit = false;
        } while (!quit);
        for(int i = y; i < y + size; i++){
            matrix[i][y] = code;
        }
    } else {
        do {
            quit = true;
            x = rand() % 14;
            y = rand() % 14 - size;
            y = (y < 0) ? 0 : y;
            for (int i = x; i < x + size; i++)
                if(matrix[x][i] != 0)
                    quit = false;
        } while (!quit);
        for(int i = x; i < x + size; i++){
            matrix[x][i] = code;
        }
    }
}

void create_table(int** matrix){
    for (int i = 0; i < 15; i++)
        for (int q = 0; q < 15; q++)
            matrix[i][q] = 0;



    insNormaShip(1, 3, VERTICAL, matrix);
    insNormaShip(2, 5, HORIZONTAL, matrix);
    insNormaShip(3, 2, VERTICAL, matrix);
    insNormaShip(4, 4, VERTICAL, matrix);
}

#endif