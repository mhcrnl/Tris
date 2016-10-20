#include "TrisImpl.h"
#include <stdio.h>

#define SIZE 3

mark_e verifyLine(int* grid, int* line) {
    int completed = 1;
    mark_e first = grid[line[0]];
    for (int i = 1; i < SIZE; i++) {
        if (grid[line[i]] !=  first) {
            return None;
        } else {
            completed++;
        }
    }
    if (completed == SIZE) {
        return first;
    }
    return None;
}

mark_e getWinner(int* grid) {
    int winnerLines[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    mark_e retval = verifyLine(grid, winnerLines[7]);
    if (retval != None) {
        return retval;
    } 

    return None;
}

int getIndex(int row, int column)
{
    return (row * SIZE) + column;
}

void new_game(tris_t* grid)
{
    grid->next = Cross;
    grid->winner = None;
    grid->initialized = 1;
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        grid->grid[i] = None;
    }
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
    if (grid->winner != None) {
        return -1;
    }
    if (grid->placedSymbols >= MAX_SYMBOLS) {
        return -1;
    }
    if (grid->next != mark) {
        return -1;
    }
    int i = getIndex(row, column);
    if (grid->grid[i] != None) {
        return -1;
    }
    grid->grid[i] = mark;
    if (grid->next == Cross) {
    	grid->next = Nought;
    } else {
    	grid->next = Cross;
    }
    grid->placedSymbols+=1;
    grid->winner = getWinner(grid->grid);
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
