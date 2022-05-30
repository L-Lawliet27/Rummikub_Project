
#ifndef RUMMIKUB_PROJECT_SETS_H
#define RUMMIKUB_PROJECT_SETS_H
#include "Racks.h"

struct tSet;
typedef tSet* tList;
struct tSet{
    tTile tile;
    tList next = NULL;
};

//typedef tTile tSet[NumTiles+1];
tList copy(tList setToAdd);
void deleteSet(tList &set);
//int find(const tSet set, tTile tile);
//void cleanSet(tSet set);
void removeTiles(tRack &rack, tList set);
int newSet(tRack rack, tList &set);
bool placeTile(tList set, tTile tile);
void display(tList set);
bool checkRun(tList set, int counter);
bool checkGroup(tList set, int counter);
void displayGroups(const tRack rack);
void displayRuns(const tRack rack);
bool checkGroupSequence(tList set, tTile tile);
bool checkRunSequence(tList set, tTile tile);
void displayPositions(int num);
#endif //RUMMIKUB_PROJECT_SETS_H
