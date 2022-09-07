
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

