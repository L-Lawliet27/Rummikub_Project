//
// Created by Andrés Salazar Colina on 1/5/22.
//

#ifndef RUMMIKUB_PROJECT_RACKS_H
#define RUMMIKUB_PROJECT_RACKS_H
#include "Rack.h"
const int NumPlayers = 4;
typedef tRack tRacks[NumPlayers];

void newTile(tTile tile, tRack &rack);
void deal(tBag &bag, tRacks &racks);
int lowest(const tRacks &racks);
void deleteRacks(tRacks &racks);

#endif //RUMMIKUB_PROJECT_RACKS_H
