
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    return false;
}


//this is code for linked lists additem
void SortedList<T>:: AddItem(T item) {
    /*
     * first
     * middle/general case ok
     * end
     * empty               ok
     */

    //empty handlinghh

//setting up because we add nodes a lot in our loops
//i will keep the node adding in the loops for now
//they should be deleted once these next few lines are added
    NodeT *insertedNode = new NodeT; //create new node
    insertedNode->info = someItem;
    insertedNode->next = nullptr; //initializing the node

    //if list is empty, establish first node
    if(head == nullptr){ //if list is empty
        head = new NodeT;
        head->info = item; //initialize node
        head->next = nullptr;
        length++;
        return;
    }

    NodeT *curr = head;
    NodeT *prevLoc = nullptr;

    while (curr != nullptr) {

        if (someItem < curr->info) {
            //NodeT *insertedNode = new NodeT; //create new node
            //insertedNode->info = someItem;
            insertedNode->next = curr; //initializing the node
            if(curr != head) {
                prevLoc->next = insertedNode;
            }
            else{
                //if curr IS the head...
                head = insertedNode; //handles if insert is first case
            }
            length++;
            break; //move us to outside the while loop
        }

        prevLoc = curr; //previous location = current
        curr = curr->next; //update current
    }

    if (curr == nullptr){ //end case, add to end of list
        //NodeT *insertedNode = new NodeT; //create new node
        //insertedNode->info = someItem;
        //insertedNode->next = nullptr; //initializing the node
        prevLoc->next = insertedNode; //connect last item in list to new last item
        length++;
    } else {
        //do the general case (the above if statement)
        //if (someItem < currInfo)
    }
    length++; //only update the length once at the end
}



// begin    ok
// middle   ok
// end      ok
// empty    ok

void SortedList<T>::DeleteItem(T item){ //for linked lists again
    NodeT* curr = head;
    NodeT* prevLoc = nullptr;

    while(curr != nullptr){

        if(item == curr->info){

            if(curr != head) {
                prevLoc->next = curr->next; //middle general case
            } else{ //it is the head (first case)
                head = curr->next;
            }
            delete curr;
            length--;
            break;
        }

        prevLoc = curr;
        curr = curr->next;
    }
}

// begin    ok
// middle   ok
// end
// empty

template<class T>
void SortedList<T>::AddItem(T item) {

    int i;
    for(i = 0;i<length;i++){
        if(item < info[i]){
            for(int j = length; j > i ; j--){
                info[j] = info[j-1];
            }
            break;
        }
    }

    info[i] = item;
    length++;

}
//d
// begin    ok
// middle   ok
// end      ok
// empty    ok

template<class T>
void SortedList<T>::DeleteItem(T item) {

    int i;
    for(i = 0;i<length;i++){
        if(item == info[i]){
            for(int j = i+1; j < length; j++){
                info[j-1] = info[j];
                length--;
                return;
            }
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

