

#ifndef RUMMIKUB_PROJECT_RACK_H
#define RUMMIKUB_PROJECT_RACK_H
#include "Bag.h"

int const MAXCAP = 8;
typedef tilesPtr tRackArray;

struct tRack{
    tRackArray tiles;
    int capacity = 0;
    int counter=0;
};

void initRack(tRack &rack);
void deleteRack(tRack &rack);
void sortByNumber(tRack &rack);
void sortByColor(tRack &rack);
void display(tRack rack);


#endif //RUMMIKUB_PROJECT_RACK_H
