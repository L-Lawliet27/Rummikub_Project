

#include "../Headers/Racks.h"


void newTile(tTile tile, tRack &rack){
    tilesPtr aux;

    if (rack.capacity==rack.counter){
        rack.capacity+=MAXCAP;
        aux = new tTile[rack.capacity];
        for (int i = 0; i < rack.counter; ++i) {
            aux[i] = rack.tiles[i];
        }
        delete [] rack.tiles;
        rack.tiles = aux;
    }
    rack.tiles[rack.counter] = tile;
    rack.counter++;
}


void deal(tBag &bag, tRacks &racks){
    tTile tile;
    for (int i = 0; i < NumPlayers; ++i) {
        for (int j = 0; j < InitialTiles; ++j) {
            tile = getTile(bag);
            newTile(tile, racks[i]);
        }//for
    }//for
}



int lowest(const tRacks &racks){
    int lowest = 0, playerPoints=0, prevPlayerPoints=0;

    for (int i = 0; i < NumPlayers; ++i) {
        for (int j = 0; j < racks[i].counter; ++j)
            playerPoints += racks[i].tiles[j].num;

        if(i==0 || playerPoints < prevPlayerPoints){
            prevPlayerPoints = playerPoints;
            lowest=i;
        }//if
        playerPoints=0;
    }//for
    return lowest;
}

void deleteRacks(tRacks &racks){
    for (int i = 0; i < NumPlayers; ++i) {
        deleteRack(racks[i]);
    }
}