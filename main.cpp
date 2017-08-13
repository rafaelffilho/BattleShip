#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

#define TILESIZE 26

int main() {

    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;
    SDL_Event e;
    int mouseX;
    int mouseY;
    SDL_Rect rects[15][15];

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("BattleShip", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 390, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    for(int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            SDL_Rect temp;
            temp.h = TILESIZE;
            temp.w = TILESIZE;
            temp.y = TILESIZE * i;
            temp.x = TILESIZE * j;
            rects[i][j] = temp;
        }
    }

    int** matrix = new int*[15];
    for (int i = 0; i < 15; i++)
        matrix[i] = new int[15];

    create_table(matrix);

    for (int k = 0; k < 15; ++k) {
        for (int i = 0; i < 15; ++i) {
            std::cout << matrix[k][i] << "\t";
        }
        std::cout << "\n";
    }

    while(running){
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            running = false;
        if(e.type == SDL_KEYDOWN)
            if(e.key.keysym.sym == SDLK_q)
                running = false;

        SDL_RenderClear(renderer);

        for(int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
                if (matrix[i][j] != 0)
                    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0xff);
                if (matrix[i][j] == 66)
                    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
                SDL_RenderFillRect(renderer, &rects[i][j]);
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);
        if(mouseX < TILESIZE * 15 && mouseY < TILESIZE * 15) {
            SDL_SetRenderDrawColor(renderer, 0xff, 0x0, 0x0, 0xff);
            SDL_RenderFillRect(renderer, &rects[mouseY / TILESIZE][mouseX / TILESIZE]);
        }
        SDL_SetRenderDrawColor(renderer, 0x56, 0x87, 0xa4, 0xff);
        SDL_RenderPresent(renderer);
    }

    for (int i = 0; i < 15; ++i)
        delete [] matrix[i];
    delete [] matrix;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}