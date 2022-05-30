

#include "../Headers/Rack.h"
using namespace std;



void initRack(tRack &rack){
    rack.tiles = new tTile[MAXCAP];
    rack.capacity = MAXCAP;
}

void deleteRack(tRack &rack){
    delete [] rack.tiles;
    rack.counter=0;
    rack.capacity=0;
}


void sortByNumber(tRack &rack){
    for (int i = 0; i < rack.counter-1; ++i) {
        int lowest = i;
        for (int j = i+1; j < rack.counter; ++j) {
            if(rack.tiles[j].num < rack.tiles[lowest].num)
                lowest=j;
        }//for
        if(lowest > i){
            tTile tmp;
            tmp = rack.tiles[i];
            rack.tiles[i] = rack.tiles[lowest];
            rack.tiles[lowest] = tmp;
        }//if
    }//for
}

void sortByColor(tRack &rack){
    for (int i = 0; i < rack.counter-1; ++i) {
        int lowest = i;
        for (int j = i+1; j < rack.counter; ++j) {
            if(rack.tiles[j].color < rack.tiles[lowest].color)
                lowest=j;
        }//for
        if(lowest > i){
            tTile tmp;
            tmp = rack.tiles[i];
            rack.tiles[i] = rack.tiles[lowest];
            rack.tiles[lowest] = tmp;
        }//if
    }//for

    for (int i = 0; i < rack.counter-1; ++i) {
        int lowest = i;
        for (int j = i+1; j < rack.counter; ++j) {
            if(rack.tiles[j].num < rack.tiles[lowest].num && rack.tiles[j].color == rack.tiles[lowest].color)
                lowest=j;
        }
        if(lowest > i){
            tTile tmp;
            tmp = rack.tiles[i];
            rack.tiles[i] = rack.tiles[lowest];
            rack.tiles[lowest] = tmp;
        }//if
    }//for
}


void display(tRack rack){
    cout<<"Rack: ";
    for (int i = 0; i < rack.counter; ++i) {
        textColor(rack.tiles[i].color);
        cout<<rack.tiles[i].num<<"  ";
        textColor(WHITE);
    }
    cout<<"\n";
}


