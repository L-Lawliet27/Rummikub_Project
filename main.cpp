#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#include "Headers/Bag.h"
#include "Headers/Rack.h"
#include "Headers/Racks.h"
#include "Headers/Board.h"
using namespace std;

int menu();
void initRacks(tRacks &racks);

int main() {
    srand(time(NULL));
    //bool endgame = false;
    int choice;
    tBag bag;
    tRacks racks;
    tRack aux;
    tBoard board;
    tTile drawnTile;
    int player, winner;
    bool placedTile = false;
    createBag(bag);
    initRacks(racks);
    //display(bag);
    deal(bag, racks);
    //display(bag);

    while(bag.counter > 0){
        player = 0;
        cout<<"\nTurn for Player 1..."<<endl;
        display(board);
        while(player<NumPlayers){
            display(racks[player]);
            choice = menu();
            switch (choice) {
                case 1:
                    sortByNumber(racks[player]);
                    break;
                case 2:
                    sortByColor(racks[player]);
                    break;
                case 3:
                    displayGroups(racks[player]);
                    displayRuns(racks[player]);
                    //deleteRack(aux);
                    break;
                case 4:
                    play(board,racks[player]);
                    display(board);
                    if(!placedTile) placedTile = true;
                    break;
                case 0:
                    if(!placedTile){
                        drawnTile = getTile(bag);
                        newTile(drawnTile, racks[player]);
                        cout<<"\n Player "<<player+1<<" draws a tile from the bag\n"<<endl;
                    }else
                        placedTile = false;

                    player++;
                    if(player<NumPlayers){
                        cout<<"\n Turn for Player "<<player+1<<"...\n"<<endl;
                        display(board);
                    }
                    break;
            }//switch
        }//while
    }//while

    winner = lowest(racks);
    cout<<"Winner is Player "<< winner+1<<endl;

    deleteBag(bag);
    deleteRacks(racks);
    deleteBoard(board);
 //   _CrtDumpMemoryLeaks(); //Doesn't Work on Mac
    return 0;
}

int menu(){
    int choice = -1;
    while(choice == -1){
        cout<<"1: Sort by Number, 2: Sort by Color, 3: Possible Sets, 4: Place, 0: Next Player >>> ";
        cin>>choice;
        if(choice<0 || choice>4){
            cout<<"Cannot Recognize Command"<<endl;
            choice = -1;
        }
    }//while
    return choice;
}


void initRacks(tRacks &racks){
    for (int i = 0; i < NumPlayers; ++i) {
        initRack(racks[i]);
    }
}
























