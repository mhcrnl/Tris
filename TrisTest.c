#include "TrisImpl.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int tests = 0;

void testTrisBoardIsEmpty() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    assert(t->placedSymbols == 0);
    tests++;
}

int main() {
    testTrisBoardIsEmpty();
    fprintf(stdout, "%d tests completed\n", tests);
    return 0;
}
