
#include "../Headers/Sets.h"
using namespace std;


tList copy(tList setToAdd){
    tList aux = NULL, copy=NULL;

    while(setToAdd!=NULL && setToAdd->tile.num !=- 1){
        if(copy!=NULL){
            aux->next = new tSet;
            aux = aux->next;
            aux->tile = setToAdd->tile;
        }else{
            copy = new tSet;
            copy->tile = setToAdd->tile;
            aux = copy;
        }
        setToAdd = setToAdd->next;
    }
    return copy;
}


void deleteSet(tList &set){
    if(set != NULL){
        tList aux = set;
        set = set->next;
        delete aux;
        deleteSet(set);
    }
}

bool checkRun(tList set, int counter){
    bool run = true;
    int i =0, j;
    tList nextSet, currentSet = set;
    while(run && i<counter-1 && currentSet->next!=NULL){
        j=i+1;
        if(j<counter){
            nextSet = currentSet->next;
            if(!(currentSet->tile.num < nextSet->tile.num && currentSet->tile.color==nextSet->tile.color)){
                run = false;
            }
        }//if
        if(run){
            i++;
            currentSet = nextSet;
        }//if
    }//while
    return run;
}

bool checkGroup(tList set, int counter){
    bool group = true;
    int i =0, j;
    tList nextSet, currentSet = set;
    while(group && i<counter-1 && currentSet->next!=NULL){
        j=i+1;
        if(j<counter){
            nextSet = currentSet->next;
            if(currentSet->tile.num != nextSet->tile.num || currentSet->tile.color == nextSet->tile.color){
                group = false;
            }//if
        }//if
        if(group){
            i++;
            currentSet = nextSet;
        }//if
    }//while
    return group;
}


void displayRuns(const tRack rack){
    int pos = 0;

    int tilesInSet=0, repeated = 0, i;
    //bool initAdd = true;
    tRack auxRack = rack;
    tColor prevColor = NONE;
    sortByColor(auxRack);

    cout<<"Possible Runs: "<<endl;

    while(pos < auxRack.counter) {
        //set[tilesInSet] = auxRack.tiles[pos];
        if(auxRack.tiles[pos].color != prevColor) {
            i = pos + 1;
            repeated = 0;

            tList set = new tSet;
            set->tile = auxRack.tiles[pos];
            tList list = set;
            tilesInSet++;

            while (i < auxRack.counter) {
                if (list->tile == auxRack.tiles[i]) {
                    repeated++;
                }
                if (list->tile.num < auxRack.tiles[i].num && list->tile.color == auxRack.tiles[i].color) {
                    if (checkRunSequence(set, auxRack.tiles[i])) {
                        //set[tilesInSet] = auxRack.tiles[i];
                        //set.next = auxRack.tiles[i];
                        list->next = new tSet;
                        list->next->tile = auxRack.tiles[i];
                        list = list->next;
                        tilesInSet++;
                    }//if
                } else if (list->tile.color != auxRack.tiles[i].color) {
                    if (tilesInSet >= 3 && tilesInSet <= 13) {
                        display(set);
                        prevColor = list->tile.color;
                    }//if
                    deleteSet(set);
                    tilesInSet = 0;
                }//else
                i++;
            }//while
        }//if
        if(repeated != 0 && tilesInSet==0) pos += repeated;
        else pos++;
    }//while
}


void displayGroups(const tRack rack){
    int pos = 0;
    int tilesInSet=0;
    tRack auxRack = rack;
    sortByNumber(auxRack);

    cout<<"Possible Groups: "<<endl;

    while(pos <= auxRack.counter-2) {
        tList set = new tSet;
        set->tile = auxRack.tiles[pos];
        tList list = set;
        tilesInSet++;
        int i = pos + 1;
        while(i< auxRack.counter){
            if (auxRack.tiles[pos].num == auxRack.tiles[i].num && auxRack.tiles[pos].color != auxRack.tiles[i].color) {
                if (checkGroupSequence(set, auxRack.tiles[i])) {
                    //set[tilesInSet] = auxRack.tiles[pos];
                    //tilesInSet++;
                    list->next = new tSet;
                    list->next->tile = auxRack.tiles[i];
                    list = list->next;
                    tilesInSet++;
                }//if
            }else if (auxRack.tiles[pos].num != auxRack.tiles[i].num){
                if (tilesInSet == 3 || tilesInSet == 4) {
                    display(set);
                }//if
                deleteSet(set);
                tilesInSet = 0;
            }//else
            i++;
        }//while
        pos++;
    }//while
}



void removeTiles(tRack &rack, tList set){
    tTile empty;
    tList list = set;

    while(list != NULL && list->tile.num != -1){
        for (int i = 0; i < rack.counter; ++i) {
            if(list->tile == rack.tiles[i] && list->tile.num != -1){
                rack.tiles[i] = rack.tiles[rack.counter-1];
                rack.tiles[rack.counter-1] = empty;
                rack.counter--;
                list = list->next;
            }//if
        }//for
    }//while
//    for (int i = 0; i < rack.counter; ++i) {
//        if(find(set, rack.tiles[i]) != -1){
//        }//if
//    }//for
}


int newSet(tRack rack, tList &set){
    int pos=-1, added=0;

    tList newSet = set;

    display(rack);
    displayPositions(rack.counter);

    cout<<"Tiles (0 at the end): ";
    cin>>pos;

    while(pos!=0){
        if(pos>0 && pos<=rack.counter){
            newSet->tile = rack.tiles[pos-1];
            newSet->next = new tSet;
            newSet = newSet->next;
            added++;
        }
        cin>>pos;
    }//while
    return added;
}


bool placeTile(tList set, tTile tile){
    //int pos = 0;
    tList list = set;
    if(list->tile.color == list->next->tile.color && list->tile.color==tile.color){
    //if(set[pos].color == set[pos+1].color && set[pos].color==tile.color){
        while(list != NULL){
        //while(set[pos].num != -1){
            if((list->tile.num < tile.num) && list->next == NULL){
            //if((list->tile.num+1==tile.num) && list->next == NULL){
            //if((set[pos].num+1==tile.num) && set[pos+1].num==-1){
                list->next = new tSet;
                list->next->tile = tile;
                //set[pos+1] = tile;
                return true;
            }else{
                list = list->next;
                //pos++;
            }//else
        }//while
        return false;

    }else if(list->tile.color != list->next->tile.color){
        bool hasNext = true;
        while(hasNext) {
            if (list->tile.color == tile.color) {
                //if(set[pos].color==tile.color){
                return false;
            } else if (list->next != NULL) {
                list = list->next;
                //pos++;
            } else
                hasNext = false;
        }
        list->next = new tSet;
        list->next->tile = tile;
        ////set[pos] = tile;
        return true;
    }//elseif

    return false;
}

//int find(const tSet set, tTile tile){
//    int beg=0, end=NumTiles, mid=0, pos=-1;
//    bool found = false;
//
//    while((beg<=end) && !found){
//        mid = (beg+end)/2;
//
//        if(set[mid] == tile){
//            found=true;
//            cout<<"FOUND";
//        }
//        else if(tile.num < set[mid].num)
//            end = mid-1;
//        else
//            beg = mid+1;
//    }//while
//    if(found) pos = mid;
//    return pos;
//}



//void cleanSet(tSet set){
//    for (int i = 0; i < NumTiles+1; ++i){
//        set[i].num=-1;
//        set[i].color=NONE;
//    }
//}

bool checkGroupSequence(tList set, tTile tile){
    bool notRep = true;
    tList list = set;

    while(list != NULL && notRep){
        if(list->tile==tile)
            notRep=false;
        if(notRep)
            list = list->next;
    }
    return notRep;
}



bool checkRunSequence(tList set, tTile tile){
    bool notRep = true;
    tList list = set;

    while(list != NULL && notRep){
        if(list->tile==tile)
            notRep=false;
        if(notRep)
            list = list->next;
    }
    return notRep;
}

void display(tList set){
    if(set != NULL && set->tile.num != -1){
        textColor(set->tile.color);
        cout<<set->tile.num<<"  ";
        textColor(WHITE);
        display(set->next);
    }else
        cout<<"\n";
}

void displayPositions(int num){
    cout<<"      ";
    for (int i = 0; i < num; ++i) {
        textColor(WHITE);
        cout<<i+1<<"  ";
    }
    cout<<"\n";
}
