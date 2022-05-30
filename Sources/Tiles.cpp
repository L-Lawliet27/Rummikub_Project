//
// Created by Andrés Salazar Colina on 1/5/22.
//

#include "../Headers/Tiles.h"
using namespace std;

bool operator==(tTile left, tTile right){
    return (left.num==right.num) && (left.color==right.color);
}

void display(tTile tile){
    if(tile.num!=-1){
        textColor(tile.color);
        cout<<tile.num<<"  ";
        textColor(WHITE);
    }//if
}