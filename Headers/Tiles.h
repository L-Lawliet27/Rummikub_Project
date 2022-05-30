//
// Created by Andrés Salazar Colina on 1/5/22.
//

#ifndef RUMMIKUB_PROJECT_TILES_H
#define RUMMIKUB_PROJECT_TILES_H
#include "Colors.h"

const int NumTiles = 13; //column
const int InitialTiles = 14;
const int MaxTiles = 50;

struct tTile{
    int num = -1;
    tColor color = NONE;
};

bool operator==(tTile left, tTile right);
void display(tTile tile);

#endif //RUMMIKUB_PROJECT_TILES_H
