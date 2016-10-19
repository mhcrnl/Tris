#include "TrisImpl.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int availableTests = 0;
int tests = 0;

void testTrisHasBeenInitialized() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(t->initialized != 0);
    tests++;
}

void testTrisBoardIsEmpty() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(t->placedSymbols == 0);
    for (int i = 0; i < 9; i++) {
        assert(t->grid[i] == None);
    }
    tests++;
}

void testCanAddOneCross() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    add(t, Cross, 0, 0);
    assert(t->placedSymbols == 1);
    mark_e mark = get(t, 0, 0);
    assert(mark == Cross);
    tests++;
}

void testGetIndex() {
    assert(getIndex(0, 0) == 0);
    assert(getIndex(0, 1) == 1);
    assert(getIndex(0, 2) == 2);
    assert(getIndex(1, 0) == 3);
    assert(getIndex(1, 1) == 4);
    assert(getIndex(1, 2) == 5);
    assert(getIndex(2, 0) == 6);
    assert(getIndex(2, 1) == 7);
    assert(getIndex(2, 2) == 8);
    tests++;
}

void testCannotAddTwoCrossesConsecutively() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(0 == add(t, Cross, 0, 0));
    assert(0 != add(t, Cross, 0, 1));
}

void testFirstPlayerIsCross() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(t->next == Cross);
    tests++;
}

void testCannotAddNoughtFirst() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(0 != add(t, Nought, 0, 1));
    tests++;
}

void testCanCompleteGame() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(0 == add(t, Cross, 0, 0));
    assert(0 == add(t, Nought, 0, 1));
    assert(0 == add(t, Cross, 0, 2));
    assert(0 == add(t, Nought, 1, 0));
    assert(0 == add(t, Cross, 1, 1));
    assert(0 == add(t, Nought, 1, 2));
    assert(0 == add(t, Cross, 2, 0));
    assert(0 == add(t, Nought, 2, 1));
    assert(0 == add(t, Cross, 2, 2));
    tests++;
}

void testCannotAddMoreThanNineMarks() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(0 == add(t, Cross, 0, 0));
    assert(0 == add(t, Nought, 0, 1));
    assert(0 == add(t, Cross, 0, 2));
    assert(0 == add(t, Nought, 1, 0));
    assert(0 == add(t, Cross, 1, 1));
    assert(0 == add(t, Nought, 1, 2));
    assert(0 == add(t, Cross, 2, 0));
    assert(0 == add(t, Nought, 2, 1));
    assert(0 == add(t, Cross, 2, 2));
    assert(0 != add(t, Nought, 3, 0));
    tests++;
}

void testCannotAddIntoAnOccupiedBox() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    assert(0 == add(t, Cross, 0, 0));
    assert(0 != add(t, Nought, 0, 0));
    tests++;
}

int main() {
    availableTests = 9;
    testTrisHasBeenInitialized();
    testTrisBoardIsEmpty();
    testFirstPlayerIsCross();
    testCanAddOneCross();
    testGetIndex();
    testCannotAddNoughtFirst();
    testCanCompleteGame();
    testCannotAddMoreThanNineMarks();
    testCannotAddIntoAnOccupiedBox();
    fprintf(stdout, "%d of %d tests completed\n", tests, availableTests);
    return 0;
}
