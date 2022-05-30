

#ifndef RUMMIKUB_PROJECT_BAG_H
#define RUMMIKUB_PROJECT_BAG_H
#include "Tiles.h"

const int BagRows = NumColors*2;

typedef tTile* tilesPtr;
typedef tilesPtr tBagArray[BagRows][NumTiles];

struct tBag{
    tBagArray tiles;
    int counter=0;
};

void createBag(tBag &bag);
tTile getTile(tBag &bag);
void display(tBag bag);
void deleteBag(tBag &bag);


#endif //RUMMIKUB_PROJECT_BAG_H
