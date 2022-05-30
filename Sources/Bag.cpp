
#include "../Headers/Bag.h"
using namespace std;

void createBag(tBag &bag){

    for (int i = 0; i < BagRows; ++i) {
        for (int j = 0; j < NumTiles; ++j) {
            bag.tiles[i][j] = new tTile;
            bag.tiles[i][j]->num=j+1;
            bag.tiles[i][j]->color= tColor(i%4);
        }//for
    }//for
    bag.counter=BagRows*NumTiles;
}


tTile getTile(tBag &bag){
    tTile tile;
    int row, col;
    if (bag.counter>0){
        row = rand()%BagRows;
        col = rand()%NumTiles;
        //bag.tiles[row][col];
        while(bag.tiles[row][col]->color==NONE){
            col++;
            if(col==NumTiles){
                row++;
                col=0;
                if(row==BagRows)
                    row=0;
            }//if
        }//while
        tile = *bag.tiles[row][col];
        //bag.tiles[row][col] = NULL;
        //bag.tiles[row][col]->color=NONE;
        //bag.tiles[row][col]->num=-1;
        //bag.tiles[row][col] = NULL;
        bag.counter--;
    }//if
    return tile;
}


void display(tBag bag){
    for (int i = 0; i < BagRows; ++i) {
        for (int j = 0; j < NumTiles; ++j) {
            display(*bag.tiles[i][j]);
            if(j==NumTiles-1)
                cout<<endl;
        }//for
    }//for
}

void deleteBag(tBag &bag){
    for (int i = 0; i < BagRows; ++i) {
        for (int j = 0; j < NumTiles; ++j) {
            delete bag.tiles[i][j];
        }
    }
    bag.counter=0;
}