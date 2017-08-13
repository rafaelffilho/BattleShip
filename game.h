#ifndef GAME
#define GAME

#define VERTICAL 0x0
#define HORIZONTAL 0x1

#include <ctime>

void outline(int x, int y, int size, int rotation, int** matrix){
    if(rotation == VERTICAL){
        matrix[y-1][x] = 66;
        matrix[y+size][x] = 66;
        for (int i = y; i < y + size; i++) {
            matrix[i][x+1] = 66;
            matrix[i][x-1] = 66;
        }
    } else {
        matrix[y][x-1] = 66;
        matrix[y][x+size] = 66;
        for (int i = x; i < x + size; i++) {
            matrix[y+1][i] = 66;
            matrix[y-1][i] = 66;
        }
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
                    if(matrix[i][x] != 0)
                        quit = false;
        } while (!quit);
        for(int i = y; i < y + size; i++){
            matrix[i][x] = code;
        }
    } else {
        do {
            quit = true;
            x = rand() % 14 - size;
            y = rand() % 14;
            x = (x < 0) ? 0 : x;
            for (int i = x; i < x + size; i++)
                if(matrix[y][i] != 0)
                    quit = false;
        } while (!quit);
        for(int i = x; i < x + size; i++){
            matrix[y][i] = code;
        }
    }
    outline(x, y, size, rotation, matrix);
    std::cout << "X: " << x << "Y: " << y << std::endl;
}

void create_table(int** matrix){
    for (int i = 0; i < 15; i++)
        for (int q = 0; q < 15; q++)
            matrix[i][q] = 0;

    insNormaShip(1, 3, HORIZONTAL, matrix);
    insNormaShip(1, 3, VERTICAL, matrix);
}

#endif