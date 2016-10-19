#include "TrisImpl.h"
#include <stdio.h>

#define SIZE 3

int getIndex(int row, int column)
{
    return (row * SIZE) + column;
}

void new_game(tris_t* grid)
{
    grid->next = Cross;
    grid->initialized = 1;
}

/**
  * returns 0 on success operation
  */
int add(tris_t* grid, mark_e mark, int row, int column)
{
    if (grid->initialized == 0) {
        fprintf(stderr, "please call new_game(tris_t*) first\n");
        return -1;
    }
    if (grid->next != mark) {
        return -1;
    }
    grid->placedSymbols+=1;
    int i = getIndex(row, column);
    grid->grid[i] = mark;
    if (grid->next == Cross) {
    	grid->next = Nought;
    } else {
    	grid->next = Cross;
    }
    return 0;
}

mark_e get(tris_t* grid, int row, int column)
{
    if (grid->initialized == 0) {
        fprintf(stderr, "please call new_game(tris_t*) first\n");
        return -1;
    }
    return grid->grid[getIndex(row, column)];
}
