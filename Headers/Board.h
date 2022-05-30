

#ifndef RUMMIKUB_PROJECT_BOARD_H
#define RUMMIKUB_PROJECT_BOARD_H
#include "Sets.h"

typedef tList tBoardArray[NumTiles*2];

struct tBoard{
    tBoardArray sets;
    int counter=0;
};

void addSet(tBoard &board, tList set);
bool play(tBoard &board, tRack &rack);
void display(tBoard board);
void deleteBoard(tBoard &board);

#endif //RUMMIKUB_PROJECT_BOARD_H
