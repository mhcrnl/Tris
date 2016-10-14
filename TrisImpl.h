#include "Tris.h"

enum mark_e {
   None,
   Cross,
   Nought
};

struct tris_t {
    int placedSymbols;
    int grid[9];
    mark_e next;
    int initialized;
};

int getIndex(int row, int column);
