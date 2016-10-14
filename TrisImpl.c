#include "TrisImpl.h"

#define SIZE 3

int getIndex(int row, int column)
{
    return (row * SIZE) + column;
}

void new_game(tris_t* grid)
{
    grid->next = Cross;
}

/**
  * returns 0 on success operation
  */
int add(tris_t* grid, mark_e mark, int row, int column)
{
    if (grid->next != mark) {
        return -1;
    }
    grid->placedSymbols+=1;
    int i = getIndex(row, column);
    grid->grid[i] = mark;
    return 0;
}

mark_e get(tris_t* grid, int row, int column)
{
    return grid->grid[getIndex(row, column)];
}
