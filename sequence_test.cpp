#include "sequence_test.h"

char TestDA1(){

    int items[4] = {-2, 14, 9, 1};

    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 2);
    int **ptr = reinterpret_cast<int**>(dynArr);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 2 || (*ptr)[0] != -2 || (*ptr)[1] != 14){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    dynArr = new DynamicArray<int>(items, 0);
    ptr = reinterpret_cast<int**>(dynArr);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr || *ptr){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    dynArr = new DynamicArray<int>(nullptr, 3);
    ptr = reinterpret_cast<int**>(dynArr);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 3){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA2(){

    DynamicArray<int> *dynArr = new DynamicArray<int>(4);
    int **ptr = reinterpret_cast<int**>(dynArr);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 4){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA3(){

    int items[2] = {10, -3};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 2);

    DynamicArray<int> *dynArr = new DynamicArray<int>(*dynArr0);
    int **ptr = reinterpret_cast<int**>(dynArr);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);
    delete dynArr0;

    if(*sizePtr != 2 || (*ptr)[0] != 10 || (*ptr)[1] != -3){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA4(){

    int items[4] = {17, 0, -13, -10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);
    
    if(dynArr->GetFirst() != 17){
        delete dynArr;
        return 'i';
    }
    if(dynArr->GetFirst() != 17){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA5(){

    int items[3] = {20, -5, 10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    if(dynArr->GetLast() != 10){
        delete dynArr;
        return 'i';
    }
    if(dynArr->GetLast() != 10){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA6(){
    
    int items[5] = {16, -7, 5, 14, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    if(dynArr->Get(0) != 16 || dynArr->Get(1) != -7 || dynArr->Get(2) != 5 || dynArr->Get(3) != 14 ||
                dynArr->Get(4) != 2){
        delete dynArr;
        return 'i';
    }
    if(dynArr->Get(0) != 16 || dynArr->Get(1) != -7 || dynArr->Get(2) != 5 || dynArr->Get(3) != 14 ||
                dynArr->Get(4) != 2){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA7(){

    int items[6] = {-5, -15, -18, 9, -3, 17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 6);

    if(dynArr->GetCount() != 6){
        delete dynArr;
        return 'i';
    }
    if(dynArr->GetCount() != 6){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA8(){

    int items[2] = {-1, -8};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 2);

    DynamicArray<int> *dynArr = dynArr0->Copy();
    delete dynArr0;

    if(dynArr->GetCount() != 2 || dynArr->GetFirst() != -1 || dynArr->GetLast() != -8){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA9(){

    int items[4] = {2, 3, 0, 20};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    dynArr->Set(3, -20);
    if(dynArr->Get(3) != -20){
        delete dynArr;
        return 'i';
    }
    dynArr->Set(2, 0);
    if(dynArr->Get(2) != 0){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA10(){

    int items[5] = {17, -3, -5, -6, -17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    dynArr->Resize(2);
    if(dynArr->GetCount() != 2 || dynArr->Get(0) != 17 || dynArr->Get(1) != -3){
        delete dynArr;
        return 'i';
    }
    dynArr->Resize(6);
    if(dynArr->GetCount() != 6 || dynArr->Get(0) != 17 || dynArr->Get(1) != -3){
        delete dynArr;
        return 'i';
    }
    delete dynArr;

    return 'c';

}
char TestDA11(){

    int items[5] = {-5, 12, 2, 19, -17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(dynArr);

    IEnumerable<int>::IEnumerator *enumer = dynArr->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+4){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}
char TestDAE1(){

    int items[4] = {-2, 14, 9, 1};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);
    int **ptr0 = reinterpret_cast<int**>(dynArr);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+3){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}
char TestDAE2(){

    int items[5] = {16, -7, 5, 14, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(dynArr);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr, 2);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}
char TestDAE3(){

    int items[3] = {9, 8, 1};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);
    int **ptr0 = reinterpret_cast<int**>(dynArr);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+1 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+2 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';
    
}
char TestDAE4(){

    int items[4] = {-13, 7, -15, -10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);
    int **ptr0 = reinterpret_cast<int**>(dynArr);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);
    int **ptr = reinterpret_cast<int**>(enumer);

    enumer->MoveNext();
    enumer->MoveNext();
    if(!(enumer->MovePrev()) || ptr[0] != (*ptr0)+1 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(!(enumer->MovePrev()) || ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';
    
}
char TestDAE5(){

    int items[3] = {14, -6, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    if(!(enumer->HasNext())){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}
char TestDAE6(){

    int items[4] = {15, -6, -14, 11};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    if(enumer->HasPrev()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}
char TestDAE7(){

    int items[3] = {-16, 6, 12};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    if(enumer->Current() != -16){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete dynArr;
        return 'i';
    }
    delete enumer;
    delete dynArr;

    return 'c';

}

char TestLL1(){

    int items[4] = {-2, 14, 9, 1};

    LinkedList<int> *list = new LinkedList<int>(items, 2);
    int **ptr = reinterpret_cast<int**>(list);
    int **nextPtr = (reinterpret_cast<int**>((*ptr)+1))+1;
    int **lastPtr = ptr+1;
    int **prevPtr = reinterpret_cast<int**>((*lastPtr)+1);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+2);

    if(*sizePtr != 2 || (*ptr)[0] != -2 || (*nextPtr)[0] != 14 || (*lastPtr)[0] != 14 || (*prevPtr)[0] != -2){
        delete list;
        return 'i';
    }
    delete list;

    list = new LinkedList<int>(items, 0);
    ptr = reinterpret_cast<int**>(list);
    lastPtr = ptr+1;
    sizePtr = reinterpret_cast<size_t*>(ptr+2);

    if(*sizePtr || *ptr || *lastPtr){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL2(){

    LinkedList<int> *list = new LinkedList<int>();
    int **ptr = reinterpret_cast<int**>(list);
    int **lastPtr = ptr+1;
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+2);

    if(*sizePtr || *ptr || *lastPtr){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL3(){

    int items[2] = {10, -3};
    LinkedList<int> *list0 = new LinkedList<int>(items, 2);

    LinkedList<int> *list = new LinkedList<int>(*list0);
    int **ptr = reinterpret_cast<int**>(list);
    int **nextPtr = (reinterpret_cast<int**>((*ptr)+1))+1;
    int **lastPtr = ptr+1;
    int **prevPtr = reinterpret_cast<int**>((*lastPtr)+1);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+2);
    delete list0;

    if(*sizePtr != 2 || (*ptr)[0] != 10 || (*nextPtr)[0] != -3 || (*lastPtr)[0] != -3 || (*prevPtr)[0] != 10){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL4(){

    int items[4] = {17, 0, -13, -10};
    LinkedList<int> *list = new LinkedList<int>(items, 4);
    
    if(list->GetFirst() != 17){
        delete list;
        return 'i';
    }
    if(list->GetFirst() != 17){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL5(){

    int items[3] = {20, -5, 10};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    if(list->GetLast() != 10){
        delete list;
        return 'i';
    }
    if(list->GetLast() != 10){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL6(){
    
    int items[5] = {16, -7, 5, 14, 2};
    LinkedList<int> *list = new LinkedList<int>(items, 5);

    if(list->Get(0) != 16 || list->Get(1) != -7 || list->Get(2) != 5 || list->Get(3) != 14 ||
                list->Get(4) != 2){
        delete list;
        return 'i';
    }
    if(list->Get(0) != 16 || list->Get(1) != -7 || list->Get(2) != 5 || list->Get(3) != 14 ||
                list->Get(4) != 2){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL7(){

    int items[6] = {-5, -15, -18, 9, -3, 17};
    LinkedList<int> *list = new LinkedList<int>(items, 6);

    if(list->GetCount() != 6){
        delete list;
        return 'i';
    }
    if(list->GetCount() != 6){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL8(){
    
    int items[6] = {-13, -16, 0, 9, 7, 11};
    LinkedList<int> *list0 = new LinkedList<int>(items, 6);

    LinkedList<int> *list = list0->GetSubList(2, 5);
    delete list0;


    if(list->GetCount() != 3 || list->Get(0) != 0 || list->Get(1) != 9 || list->Get(2) != 7){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL9(){

    int items[2] = {-1, -8};
    LinkedList<int> *list0 = new LinkedList<int>(items, 2);

    LinkedList<int> *list = list0->Copy();
    delete list0;

    if(list->GetCount() != 2 || list->GetFirst() != -1 || list->GetLast() != -8){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL10(){

    int items[2] = {5, -11};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    list->Append(10);
    if(list->GetCount() != 3 || list->GetLast() != 10){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL11(){

    int items[2] = {-11, 20};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    list->Prepend(-1);
    if(list->GetCount() != 3 || list->GetFirst() != -1){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL12(){

    int items[3] = {-7, -18, 0};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    list->InsertAt(-13, 1);
    if(list->GetCount() != 4 || list->Get(1) != -13){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL13(){

    int items1[2] = {11, 19};
    int items2[2] = {10, -9};
    LinkedList<int> *list01 = new LinkedList<int>(items1, 2);
    LinkedList<int> *list02 = new LinkedList<int>(items2, 2);

    LinkedList<int> *list = list01->Concat(list02);
    delete list01;
    delete list02;

    if(list->GetCount() != 4 || list->Get(0) != 11 || list->Get(1) != 19 || list->Get(2) != 10 ||
                list->Get(3) != -9){
        delete list;
        return 'i';
    }
    delete list;

    return 'c';

}
char TestLL14(){

    int items[5] = {-5, 12, 2, 19, -17};
    LinkedList<int> *list = new LinkedList<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(list);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';

}
char TestLLE1(){

    int items[4] = {-2, 14, 9, 1};
    LinkedList<int> *list = new LinkedList<int>(items, 4);
    int **ptr0 = reinterpret_cast<int**>(list);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';

}
char TestLLE2(){

    int items[3] = {9, 8, 1};
    LinkedList<int> *list = new LinkedList<int>(items, 3);
    int **ptr0 = reinterpret_cast<int**>(list);
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(!(enumer->MoveNext()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    if(!(enumer->MoveNext()) || ptr[0] != ptr0[1] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';
    
}
char TestLLE3(){

    int items[4] = {-13, 7, -15, -10};
    LinkedList<int> *list = new LinkedList<int>(items, 4);
    int **ptr0 = reinterpret_cast<int**>(list);
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    enumer->MoveNext();
    enumer->MoveNext();
    if(!(enumer->MovePrev()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    if(!(enumer->MovePrev()) || ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return 'i';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';
    
}
char TestLLE4(){

    int items[3] = {14, -6, 2};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(!(enumer->HasNext())){
        delete enumer;
        delete list;
        return 'i';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete list;
        return 'i';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete list;
        return 'i';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';

}
char TestLLE5(){

    int items[4] = {15, -6, -14, 11};
    LinkedList<int> *list = new LinkedList<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(enumer->HasPrev()){
        delete enumer;
        delete list;
        return 'i';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete list;
        return 'i';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete list;
        return 'i';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';

}
char TestLLE6(){

    int items[3] = {-16, 6, 12};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(enumer->Current() != -16){
        delete enumer;
        delete list;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete list;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete list;
        return 'i';
    }
    delete enumer;
    delete list;

    return 'c';

}

#define TEST_MACRO(condition) \
do{ \
    if(!(condition)) fail = true; \
}while(0)

char TestAS1(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -2 || (*ptr)->Get(1) != 14){
        delete seq;
        return 'i';
    }
    delete seq;

    seq = new MutableArraySequence<int>(items, 0);
    ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr || (*ptr)->GetCount()){
        delete seq;
        return 'i';
    }
    delete seq;

    seq = new MutableArraySequence<int>(nullptr, 3);
    ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 3 || (*ptr)->GetCount() != 3){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS2(){

    MutableArraySequence<int> *seq = new MutableArraySequence<int>();
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr || (*ptr)->GetCount()){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS3(){

    int items[2] = {-5, 0};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 2);

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(*dynArr);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);
    delete dynArr;

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -5 || (*ptr)->Get(1) != 0){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS4(){

    int items[2] = {10, -3};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 2);

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(*seq0);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);
    delete seq0;

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != 10 || (*ptr)->Get(1) != -3){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS5(){

    int items[4] = {17, 0, -13, -10};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);
    
    if(seq->GetFirst() != 17){
        delete seq;
        return 'i';
    }
    if(seq->GetFirst() != 17){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS6(){

    int items[3] = {20, -5, 10};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    if(seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    if(seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS7(){
    
    int items[5] = {16, -7, 5, 14, 2};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return 'i';
    }
    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS8(){

    int items[6] = {-5, -15, -18, 9, -3, 17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 6);

    if(seq->GetCount() != 6){
        delete seq;
        return 'i';
    }
    if(seq->GetCount() != 6){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS9(){
    
    int items[6] = {-13, -16, 0, 9, 7, 11};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 6);

    MutableArraySequence<int> *seq = seq0->GetSubsequence(2, 5);
    delete seq0;


    if(seq->GetCount() != 3 || seq->Get(0) != 0 || seq->Get(1) != 9 || seq->Get(2) != 7){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS10(){

    int items[2] = {-1, -8};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 2);

    MutableArraySequence<int> *seq = seq0->Copy();
    delete seq0;

    if(seq->GetCount() != 2 || seq->GetFirst() != -1 || seq->GetLast() != -8){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS11(){

    int items1[2] = {11, 19};
    int items2[2] = {10, -9};
    MutableArraySequence<int> *seq01 = new MutableArraySequence<int>(items1, 2);
    MutableArraySequence<int> *seq02 = new MutableArraySequence<int>(items2, 2);

    MutableArraySequence<int> *seq = seq01->Concat(seq02);
    delete seq01;
    delete seq02;

    if(seq->GetCount() != 4 || seq->Get(0) != 11 || seq->Get(1) != 19 || seq->Get(2) != 10 || seq->Get(3) != -9){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS12(){

    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(seq);

    IEnumerable<int>::IEnumerator *enumer = seq->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+4){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestAS13(){

    int items[3] = {9, 8, 1};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 3);

    MutableArraySequence<int> *seq = seq0->template Map<int,MutableArraySequence<int>>([](const int &x){
        return (x - 5)*2 + 3;
    });
    delete seq0;

    if(seq->GetCount() != 3 || seq->Get(0) != 11 || seq->Get(1) != 9 || seq->Get(2) != -5){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS14(){

    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq = seq0->Where([](const int &x){ return x < 10; });
    delete seq0;
    if(seq->GetCount() != 3 || seq->Get(0) != -5 || seq->Get(1) != 2 || seq->Get(2) != -17){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestAS15(){
    
    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    int res = seq->template Reduce<int>([](const int &in, const int &x){ return in+x; }, 0);
    if(res != 11) return 'i';

    return 'c';
    
}
char TestASE1(){

    int items[4] = {-2, 14, 9, 1};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestASE2(){

    int items[3] = {9, 8, 1};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+1 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+2 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';
    
}
char TestASE3(){

    int items[4] = {-13, 7, -15, -10};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    enumer->MoveNext();
    enumer->MoveNext();
    if(!(enumer->MovePrev()) || ptr[0] != (*ptr0)+1 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->MovePrev()) || ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';
    
}
char TestASE4(){

    int items[3] = {14, -6, 2};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestASE5(){

    int items[4] = {15, -6, -14, 11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestASE6(){

    int items[3] = {-16, 6, 12};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(enumer->Current() != -16){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestMAS1(){

    int items[2] = {5, -11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);

    if(seq->Append(10) != seq || seq->GetCount() != 3 || seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestMAS2(){

    int items[2] = {-11, 20};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);

    if(seq->Prepend(-1) != seq || seq->GetCount() != 3 || seq->GetFirst() != -1){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestMAS3(){

    int items[3] = {-7, -18, 0};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    if(seq->InsertAt(-13, 1) != seq || seq->GetCount() != 4 || seq->Get(1) != -13){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestIAS1(){

    int items[2] = {5, -11};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 2);

    ImmutableArraySequence<int> *seq1 = seq->Append(10);
    if(seq1->GetCount() != 3 || seq1->GetLast() != 10 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}
char TestIAS2(){

    int items[2] = {-11, 20};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 2);

    ImmutableArraySequence<int> *seq1 = seq->Prepend(-1);
    if(seq1->GetCount() != 3 || seq1->GetFirst() != -1 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}
char TestIAS3(){

    int items[3] = {-7, -18, 0};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 3);

    ImmutableArraySequence<int> *seq1 = seq->InsertAt(-13, 1);
    if(seq1->GetCount() != 4 || seq1->Get(1) != -13 || seq->GetCount() != 3){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}

char TestLS1(){

    int items[4] = {-2, 14, 9, 1};

    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -2 || (*ptr)->Get(1) != 14){
        delete seq;
        return 'i';
    }
    delete seq;

    seq = new MutableListSequence<int>(items, 0);
    ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount()){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS2(){

    MutableListSequence<int> *seq = new MutableListSequence<int>();
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount()){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS3(){

    int items[2] = {-5, 0};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    MutableListSequence<int> *seq = new MutableListSequence<int>(*list);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);
    delete list;

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -5 || (*ptr)->Get(1) != 0){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS4(){

    int items[2] = {10, -3};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 2);

    MutableListSequence<int> *seq = new MutableListSequence<int>(*seq0);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);
    delete seq0;

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != 10 || (*ptr)->Get(1) != -3){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS5(){

    int items[4] = {17, 0, -13, -10};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);
    
    if(seq->GetFirst() != 17){
        delete seq;
        return 'i';
    }
    if(seq->GetFirst() != 17){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS6(){

    int items[3] = {20, -5, 10};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    if(seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    if(seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS7(){
    
    int items[5] = {16, -7, 5, 14, 2};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);

    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return 'i';
    }
    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS8(){

    int items[6] = {-5, -15, -18, 9, -3, 17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 6);

    if(seq->GetCount() != 6){
        delete seq;
        return 'i';
    }
    if(seq->GetCount() != 6){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS9(){
    
    int items[6] = {-13, -16, 0, 9, 7, 11};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 6);

    MutableListSequence<int> *seq = seq0->GetSubsequence(2, 5);
    delete seq0;


    if(seq->GetCount() != 3 || seq->Get(0) != 0 || seq->Get(1) != 9 || seq->Get(2) != 7){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS10(){

    int items[2] = {-1, -8};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 2);

    MutableListSequence<int> *seq = seq0->Copy();
    delete seq0;

    if(seq->GetCount() != 2 || seq->GetFirst() != -1 || seq->GetLast() != -8){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS11(){

    int items1[2] = {11, 19};
    int items2[2] = {10, -9};
    MutableListSequence<int> *seq01 = new MutableListSequence<int>(items1, 2);
    MutableListSequence<int> *seq02 = new MutableListSequence<int>(items2, 2);

    MutableListSequence<int> *seq = seq01->Concat(seq02);
    delete seq01;
    delete seq02;

    if(seq->GetCount() != 4 || seq->Get(0) != 11 || seq->Get(1) != 19 || seq->Get(2) != 10 || seq->Get(3) != -9){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS12(){

    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(seq);

    IEnumerable<int>::IEnumerator *enumer = seq->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestLS13(){

    int items[3] = {9, 8, 1};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 3);

    MutableListSequence<int> *seq = seq0->template Map<int,MutableListSequence<int>>([](const int &x){
        return (x - 5)*2 + 3;
    });
    delete seq0;

    if(seq->GetCount() != 3 || seq->Get(0) != 11 || seq->Get(1) != 9 || seq->Get(2) != -5){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS14(){

    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 5);

    MutableListSequence<int> *seq = seq0->Where([](const int &x){ return x < 10; });
    delete seq0;
    if(seq->GetCount() != 3 || seq->Get(0) != -5 || seq->Get(1) != 2 || seq->Get(2) != -17){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestLS15(){
    
    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);

    int res = seq->template Reduce<int>([](const int &in, const int &x){ return in+x; }, 0);
    if(res != 11) return 'i';

    return 'c';
    
}
char TestLSE1(){

    int items[4] = {-2, 14, 9, 1};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestLSE2(){

    int items[3] = {9, 8, 1};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);
    int **ptr0 = *(reinterpret_cast<int***>(seq));
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(!(enumer->MoveNext()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->MoveNext()) || ptr[0] != ptr0[1] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';
    
}
char TestLSE3(){

    int items[4] = {-13, 7, -15, -10};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    enumer->MoveNext();
    enumer->MoveNext();
    if(!(enumer->MovePrev()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->MovePrev()) || ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';
    
}
char TestLSE4(){

    int items[3] = {14, -6, 2};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestLSE5(){

    int items[4] = {15, -6, -14, 11};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return 'i';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestLSE6(){

    int items[3] = {-16, 6, 12};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(enumer->Current() != -16){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete seq;
        return 'i';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete seq;
        return 'i';
    }
    delete enumer;
    delete seq;

    return 'c';

}
char TestMLS1(){

    int items[2] = {5, -11};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);

    if(seq->Append(10) != seq || seq->GetCount() != 3 || seq->GetLast() != 10){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestMLS2(){

    int items[2] = {-11, 20};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);

    if(seq->Prepend(-1) != seq || seq->GetCount() != 3 || seq->GetFirst() != -1){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestMLS3(){

    int items[3] = {-7, -18, 0};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    if(seq->InsertAt(-13, 1) != seq || seq->GetCount() != 4 || seq->Get(1) != -13){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestILS1(){

    int items[2] = {5, -11};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 2);

    ImmutableListSequence<int> *seq1 = seq->Append(10);
    if(seq1->GetCount() != 3 || seq1->GetLast() != 10 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}
char TestILS2(){

    int items[2] = {-11, 20};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 2);

    ImmutableListSequence<int> *seq1 = seq->Prepend(-1);
    if(seq1->GetCount() != 3 || seq1->GetFirst() != -1 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}
char TestILS3(){

    int items[3] = {-7, -18, 0};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 3);

    ImmutableListSequence<int> *seq1 = seq->InsertAt(-13, 1);
    if(seq1->GetCount() != 4 || seq1->Get(1) != -13 || seq->GetCount() != 3){
        delete seq;
        delete seq1;
        return 'i';
    }
    delete seq;
    delete seq1;

    return 'c';

}

char TestSM1(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    SequenceMath::MinMaxAvgType<int> mma = SequenceMath::MinMaxAvg<MutableArraySequence<int>,int>(*seq);

    if(mma.min != -9 || mma.max != 27 || mma.avg != 9){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestSM2(){

    int items[4] = {-7, 16, 4, -11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);

    if(SequenceMath::Median<MutableArraySequence<int>,int>(*seq) != 4){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestSM3(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    if(SequenceMath::PermutationQuantity<MutableArraySequence<int>,int>(*seq) != 60){
        delete seq;
        return 'i';
    }
    delete seq;

    return 'c';

}
char TestSM4(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<MutableArraySequence<int>*> *seqSeq =
                SequenceMath::LessPrevious<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    delete seq;


    if(seqSeq->Get(0)->GetCount() != 0){
        delete seqSeq;
        return 'i';
    }
    if(seqSeq->Get(1)->GetCount() != 1 || seqSeq->Get(1)->Get(0) != -4){
        delete seqSeq;
        return 'i';
    }
    if(seqSeq->Get(2)->GetCount() != 1 || seqSeq->Get(2)->Get(0) != -4){
        delete seqSeq;
        return 'i';
    }
    if(seqSeq->Get(3)->GetCount() != 3 || seqSeq->Get(2)->Get(0) != -4 || seqSeq->Get(2)->Get(1) != 16 ||
                seqSeq->Get(2)->Get(2) != 16){
        delete seqSeq;
        return 'i';
    }
    if(seqSeq->Get(4)->GetCount() != 0){
        delete seqSeq;
        return 'i';
    }
    delete seqSeq;

    return 'c';

}
char TestSM5(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<MutableArraySequence<int>*> *seqSeq1 =
                SequenceMath::Prefixes<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    MutableArraySequence<MutableArraySequence<int>*> *seqSeq2 =
                SequenceMath::Postfixes<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    delete seq;

    for(size_t numb = 0, numb1; numb < 5; numb++){
        if(seqSeq1->Get(numb)->GetCount() != numb+1 || seqSeq2->Get(4-numb)->GetCount() != numb+1){
            delete seqSeq1;
            delete seqSeq2;
            return 'i';
        }
        for(numb1 = 0; numb1 <= numb; numb1++){
            if(seqSeq1->Get(numb)->Get(numb1) != items[numb1] ||
                        seqSeq2->Get(4-numb)->Get(numb-numb1) != items[4-numb1]){
                delete seqSeq1;
                delete seqSeq2;
                return 'i';
            }
        }
    }
    delete seqSeq1;
    delete seqSeq2;

    return 'c';

}
char TestSM6(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::NeighbourMeans<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(1) != 9 || seq1->Get(2) != 19 || seq1->Get(3) != 11){
        delete seq1;
        return 'i';
    }
    delete seq1;

    return 'c';

}
char TestSM7(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::QuadraticMeans<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(0) != 18 || seq1->Get(1) != 16 || seq1->Get(2) != 16 ||
                seq1->Get(3) != 12 || seq1->Get(4) != 17){
        delete seq1;
        return 'i';
    }
    delete seq1;

    return 'c';

}
char TestSM8(){

    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::NeighbourMeans<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(0) != -13 || seq1->Get(1) != 43 || seq1->Get(2) != 32 ||
                seq1->Get(3) != 43 || seq1->Get(4) != -13){
        delete seq1;
        return 'i';
    }
    delete seq1;

    return 'c';

}

void TestCounter(int &count, const char &output, const std::string &str){//сделать макросом
    if(output == 'c'){
        count++;
        return;
    }
    std::cout << str << " not passed" << std::endl;
}

void DoTest(){

    int count = 0;
    
    TestCounter(count, TestDA1(), "TestDA1");
    TestCounter(count, TestDA2(), "TestDA2");
    TestCounter(count, TestDA3(), "TestDA3");
    TestCounter(count, TestDA4(), "TestDA4");
    TestCounter(count, TestDA5(), "TestDA5");
    TestCounter(count, TestDA6(), "TestDA6");
    TestCounter(count, TestDA7(), "TestDA7");
    TestCounter(count, TestDA8(), "TestDA8");
    TestCounter(count, TestDA9(), "TestDA9");
    TestCounter(count, TestDA10(), "TestDA10");
    TestCounter(count, TestDA11(), "TestDA11");
    TestCounter(count, TestDAE1(), "TestDAE1");
    TestCounter(count, TestDAE2(), "TestDAE2");
    TestCounter(count, TestDAE3(), "TestDAE3");
    TestCounter(count, TestDAE4(), "TestDAE4");
    TestCounter(count, TestDAE5(), "TestDAE5");
    TestCounter(count, TestDAE6(), "TestDAE6");
    TestCounter(count, TestDAE7(), "TestDAE7");

    TestCounter(count, TestLL1(), "TestLL1");
    TestCounter(count, TestLL2(), "TestLL2");
    TestCounter(count, TestLL3(), "TestLL3");
    TestCounter(count, TestLL4(), "TestLL4");
    TestCounter(count, TestLL5(), "TestLL5");
    TestCounter(count, TestLL6(), "TestLL6");
    TestCounter(count, TestLL7(), "TestLL7");
    TestCounter(count, TestLL8(), "TestLL8");
    TestCounter(count, TestLL9(), "TestLL9");
    TestCounter(count, TestLL10(), "TestLL10");
    TestCounter(count, TestLL11(), "TestLL11");
    TestCounter(count, TestLL12(), "TestLL12");
    TestCounter(count, TestLL13(), "TestLL13");
    TestCounter(count, TestLL14(), "TestLL14");
    TestCounter(count, TestLLE1(), "TestLLE1");
    TestCounter(count, TestLLE2(), "TestLLE2");
    TestCounter(count, TestLLE3(), "TestLLE3");
    TestCounter(count, TestLLE4(), "TestLLE4");
    TestCounter(count, TestLLE5(), "TestLLE5");
    TestCounter(count, TestLLE6(), "TestLLE6");

    TestCounter(count, TestAS1(), "TestAS1");
    TestCounter(count, TestAS2(), "TestAS2");
    TestCounter(count, TestAS3(), "TestAS3");
    TestCounter(count, TestAS4(), "TestAS4");
    TestCounter(count, TestAS5(), "TestAS5");
    TestCounter(count, TestAS6(), "TestAS6");
    TestCounter(count, TestAS7(), "TestAS7");
    TestCounter(count, TestAS8(), "TestAS8");
    TestCounter(count, TestAS9(), "TestAS9");
    TestCounter(count, TestAS10(), "TestAS10");
    TestCounter(count, TestAS11(), "TestAS11");
    TestCounter(count, TestAS12(), "TestAS12");
    TestCounter(count, TestAS13(), "TestAS13");
    TestCounter(count, TestAS14(), "TestAS14");
    TestCounter(count, TestAS15(), "TestAS15");
    TestCounter(count, TestASE1(), "TestASE1");
    TestCounter(count, TestASE2(), "TestASE2");
    TestCounter(count, TestASE3(), "TestASE3");
    TestCounter(count, TestASE4(), "TestASE4");
    TestCounter(count, TestASE5(), "TestASE5");
    TestCounter(count, TestASE6(), "TestASE6");
    TestCounter(count, TestMAS1(), "TestMAS1");
    TestCounter(count, TestMAS2(), "TestMAS2");
    TestCounter(count, TestMAS3(), "TestMAS3");
    TestCounter(count, TestIAS1(), "TestIAS1");
    TestCounter(count, TestIAS2(), "TestIAS2");
    TestCounter(count, TestIAS3(), "TestIAS3");

    TestCounter(count, TestLS1(), "TestLS1");
    TestCounter(count, TestLS2(), "TestLS2");
    TestCounter(count, TestLS3(), "TestLS3");
    TestCounter(count, TestLS4(), "TestLS4");
    TestCounter(count, TestLS5(), "TestLS5");
    TestCounter(count, TestLS6(), "TestLS6");
    TestCounter(count, TestLS7(), "TestLS7");
    TestCounter(count, TestLS8(), "TestLS8");
    TestCounter(count, TestLS9(), "TestLS9");
    TestCounter(count, TestLS10(), "TestLS10");
    TestCounter(count, TestLS11(), "TestLS11");
    TestCounter(count, TestLS12(), "TestLS12");
    TestCounter(count, TestLS13(), "TestLS13");
    TestCounter(count, TestLS14(), "TestLS14");
    TestCounter(count, TestLS15(), "TestLS15");
    TestCounter(count, TestLSE1(), "TestLSE1");
    TestCounter(count, TestLSE2(), "TestLSE2");
    TestCounter(count, TestLSE3(), "TestLSE3");
    TestCounter(count, TestLSE4(), "TestLSE4");
    TestCounter(count, TestLSE5(), "TestLSE5");
    TestCounter(count, TestLSE6(), "TestLSE6");
    TestCounter(count, TestMLS1(), "TestMLS1");
    TestCounter(count, TestMLS2(), "TestMLS2");
    TestCounter(count, TestMLS3(), "TestMLS3");
    TestCounter(count, TestILS1(), "TestILS1");
    TestCounter(count, TestILS2(), "TestILS2");
    TestCounter(count, TestILS3(), "TestILS3");

    TestCounter(count, TestSM1(), "TestSM1");
    TestCounter(count, TestSM2(), "TestSM2");
    TestCounter(count, TestSM3(), "TestSM3");
    TestCounter(count, TestSM4(), "TestSM4");
    TestCounter(count, TestSM5(), "TestSM5");
    TestCounter(count, TestSM6(), "TestSM6");
    TestCounter(count, TestSM7(), "TestSM7");
    TestCounter(count, TestSM8(), "TestSM8");

    std::cout << count << " of 100 tests passed" << std::endl;

}