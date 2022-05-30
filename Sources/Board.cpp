
#include "../Headers/Board.h"
using namespace std;

void addSet(tBoard &board, tList set){
    //int setPos = 0;
    int count = board.counter;
    //int setNum = set[setPos].num;
    //int setNum = set.tile.num;

    board.sets[count] = copy(set);
    board.counter++;

//    while (list != NULL){
//        board.sets[count][setPos].num = setNum;
//        board.sets[count][setPos].color = set[setPos].color;
//        setPos++;
//        setNum = set[setPos].num;
//    }//while
}

bool play(tBoard &board, tRack &rack){
    tList set = new tSet, aux;
    int counter, jug;
    bool played=false;
//    board counter
//    numtiles
//    aux[i] = board sets
//            if placetile aux set[0]
//            counter++
//            if(counter > 1)
//                cout<<
//    display(rack);

    counter = newSet(rack, set);

    if(counter==1){
        cout<<"Sets on the Board where it can be placed: ";
        counter = 0;
        for (int i = 0; i < board.counter; ++i) {
            //for (int j = 0; j < NumTiles; ++j){
                //aux[j] = board.sets[i][j];
                aux = board.sets[i];
            //}//for
            if(placeTile(aux,set->tile)){
                counter++;
                if(counter>1)
                    cout<<", ";
                cout<< i+1;
                jug=i;
            }//if
        }//for

        if(counter ==0 ){
            cout<<"None! Try Again..."<<endl;
        }else if(counter==1){
            cout<<"  -> Placed!"<<endl;
            placeTile(board.sets[jug], set->tile);
            removeTiles(rack, set);
            played = true;
        }else{
            cout<<"Choose where to Place: ";
            cin>>jug;
            if(jug-1 != -1){
                placeTile(board.sets[jug-1], set->tile);
                removeTiles(rack, set);
                played = true;
            }else
                cout<<"Not Valid Set"<<endl;
        }//end

    }else if (counter>=3){
        display(set);
        if(checkRun(set, counter)){
            cout<<" - Valid Run!"<<endl;
            played = true;
        }else if(checkGroup(set, counter)){
            cout<<" - Valid Group!"<<endl;
            played = true;
        }else{
            cout<<" - Invalid Group!"<<endl;
        }
        if(played){
            addSet(board,set);
            removeTiles(rack, set);
        }//if
    }//else if
    deleteSet(set);
    return played;
}



void display(tBoard board){
    cout<<"Board: ";

    if(board.counter==0){
        cout<<"No Sets\n"<<endl;
    }else{
        cout<<"\n";
        for (int i = 0; i < board.counter; ++i) {
            textColor(WHITE);
            cout<<" "<<i<<":  ";
            display(board.sets[i]);
        }
        cout<<"\n";
    }
}


void deleteBoard(tBoard &board){
    for (int i = 0; i < board.counter; ++i) {
        deleteSet(board.sets[i]);
    }
}


