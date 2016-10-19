#include "Tris.h"

#define MAX_SYMBOLS 9

enum mark_e {
   None,
   Cross,
   Nought
};

struct tris_t {
    int placedSymbols;
    int grid[MAX_SYMBOLS];
    mark_e next;
    int initialized;
};

int getIndex(int row, int column);
