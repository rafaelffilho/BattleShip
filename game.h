#ifndef GAME
#define GAME

#define VERTICAL 0x0
#define HORIZONTAL 0x1

#include <ctime>

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
            matrix[i][x] = code;
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
            matrix[y][i] = code;
        }
    }
    std::cout << "X: " << x << "Y: " << y << std::endl;
}

void create_table(int** matrix){
    for (int i = 0; i < 15; i++)
        for (int q = 0; q < 15; q++)
            matrix[i][q] = 0;

    insNormaShip(1, 3, HORIZONTAL, matrix);
}

#endif