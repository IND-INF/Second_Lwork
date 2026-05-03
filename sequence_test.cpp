#include "sequence_test.h"

#define TEST_CONDITION_MACRO(condition) \
do{                                     \
    if(!(condition)) fail = true;       \
}while(0);

#define TEST_EXCEPTION_MACRO(functionUnderTest, exeptionType)   \
do{                                                             \
    try{                                                        \
        (functionUnderTest);                                    \
    }                                                           \
    catch((exeptionType) exc){}                                 \
    catch(...){                                                 \
        fail = true;                                            \
    }                                                           \
}while(0);

#define TEST_OUT_OF_RANGE_MACRO(functionUnderTest, entered, minimal, maximal)   \
do{                                                                             \
    try{                                                                        \
        (functionUnderTest);                                                    \
    }                                                                           \
    catch(IndexOutOfRange exc){                                                 \
        if(exc.GetEnteredIndex() != (entered)) fail = true;                     \
        if(exc.GetMinimalLimit() != (minimal)) fail = true;                     \
        if(exc.GetMaximalLimit() != (maximal)) fail = true;                     \
    }                                                                           \
    catch(...){                                                                 \
        fail = true;                                                            \
    }                                                                           \
}while(0);

#define TEST_COUNTER_MACRO(testName)                            \
do{                                                             \
    if(testName() == '1') count++;                              \
    else std::cout << #testName << " not passed" << std::endl;  \
}while(0);

char TestDynArrFullCtor(){

    bool fail = false;
    int items[6] = {-2, 14, 9, 1, 10, -13};

    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 4)
    TEST_CONDITION_MACRO(dynArr->Get(0) == -2)
    TEST_CONDITION_MACRO(dynArr->Get(1) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 9)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 1)
    delete dynArr;

    dynArr = new DynamicArray<int>(items, 0);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 0)
    delete dynArr;

    dynArr = new DynamicArray<int>(nullptr, 3);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 3)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrSizeCtor(){

    bool fail = false;
    DynamicArray<int> *dynArr = new DynamicArray<int>(4);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 4)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrCopyCtor(){

    bool fail = false;
    int items[5] = {10, -3, 6, -15, 16};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 5);

    DynamicArray<int> *dynArr = new DynamicArray<int>(*dynArr0);
    delete dynArr0;

    TEST_CONDITION_MACRO(dynArr->GetCount() == 5)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 10)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -3)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 6)
    TEST_CONDITION_MACRO(dynArr->Get(3) == -15)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 16)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrGetFirst(){

    bool fail = false;
    int items[4] = {17, 0, -13, -10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);
    
    TEST_CONDITION_MACRO(dynArr->GetFirst() == 17)
    TEST_CONDITION_MACRO(dynArr->GetFirst() == 17)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrGetLast(){

    bool fail = false;
    int items[3] = {20, -5, 10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    TEST_CONDITION_MACRO(dynArr->GetLast() == 10)
    TEST_CONDITION_MACRO(dynArr->GetLast() == 10)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrGet(){

    bool fail = false;
    int items[5] = {16, -7, 5, 14, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    TEST_CONDITION_MACRO(dynArr->Get(0) == 16)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -7)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 5)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 2)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 16)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -7)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 5)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 2)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrGetCount(){

    bool fail = false;
    int items[6] = {-5, -15, -18, 9, -3, 17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 6);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 6)
    TEST_CONDITION_MACRO(dynArr->GetCount() == 6)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrCopy(){

    bool fail = false;
    int items[4] = {-1, -8, 7, 6};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 4);

    DynamicArray<int> *dynArr = dynArr0->Copy();
    delete dynArr0;

    TEST_CONDITION_MACRO(dynArr->GetCount() == 4)
    TEST_CONDITION_MACRO(dynArr->Get(0) == -1)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -8)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 7)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 6)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrSet(){

    bool fail = false;
    int items[4] = {2, 3, 0, 20};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    dynArr->Set(3, -20);
    TEST_CONDITION_MACRO(dynArr->Get(3) == -20)
    dynArr->Set(2, 0);
    TEST_CONDITION_MACRO(dynArr->Get(2) == 0)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrResize(){

    bool fail = false;
    int items[5] = {17, -3, -5, -6, -17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    dynArr->Resize(2);
    TEST_CONDITION_MACRO(dynArr->GetCount() == 2)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 17)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -3)
    dynArr->Resize(6);
    TEST_CONDITION_MACRO(dynArr->GetCount() == 6)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 17)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -3)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrGetEnumerator(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    IEnumerable<int>::IEnumerator *enumer = dynArr->GetEnumerator();

    TEST_CONDITION_MACRO(!(enumer->HasPrev()))
    TEST_CONDITION_MACRO(enumer->Current() == -5)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 12)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 2)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 19)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == -17)
    TEST_CONDITION_MACRO(!(enumer->HasNext()))
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrEnumCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    TEST_CONDITION_MACRO(!(enumer->HasPrev()))
    TEST_CONDITION_MACRO(enumer->Current() == -2)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 14)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 9)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 1)
    TEST_CONDITION_MACRO(!(enumer->HasNext()))
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrEnumCtorWithIndex(){

    bool fail = false;
    int items[5] = {16, -7, 5, 14, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr, 2);

    TEST_CONDITION_MACRO(!(enumer->HasPrev()))
    TEST_CONDITION_MACRO(enumer->Current() == 16)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == -7)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 5)
    TEST_CONDITION_MACRO(!(enumer->HasNext()))
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrEnumMoveNext(){

    bool fail = false;
    int items[4] = {9, 8, 1, -4};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    TEST_CONDITION_MACRO(enumer->MoveNext())
    TEST_CONDITION_MACRO(enumer->Current() == 8)
    TEST_CONDITION_MACRO(enumer->MoveNext())
    TEST_CONDITION_MACRO(enumer->Current() == 1)
    TEST_CONDITION_MACRO(enumer->MoveNext())
    TEST_CONDITION_MACRO(enumer->Current() == -4)
    TEST_CONDITION_MACRO(!(enumer->MoveNext()))
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';
    
}
char TestDynArrEnumMovePrev(){

    bool fail = false;
    int items[4] = {-13, 7, -15, -10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    enumer->MoveNext();
    enumer->MoveNext();
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->MovePrev())
    TEST_CONDITION_MACRO(enumer->Current() == -15)
    TEST_CONDITION_MACRO(enumer->MovePrev())
    TEST_CONDITION_MACRO(enumer->Current() == 7)
    TEST_CONDITION_MACRO(enumer->MovePrev())
    TEST_CONDITION_MACRO(enumer->Current() == -13)
    TEST_CONDITION_MACRO(!(enumer->MovePrev()))
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';
    
}
char TestDynArrEnumHasNext(){

    bool fail = false;
    int items[3] = {14, -6, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    TEST_CONDITION_MACRO(enumer->HasNext());
    TEST_CONDITION_MACRO(enumer->HasNext());
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->HasNext());
    TEST_CONDITION_MACRO(enumer->HasNext());
    enumer->MoveNext();
    TEST_CONDITION_MACRO(!(enumer->HasNext()));
    TEST_CONDITION_MACRO(!(enumer->HasNext()));
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrEnumHasPrev(){

    bool fail = false;
    int items[3] = {15, -6, -14};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    TEST_CONDITION_MACRO(!(enumer->HasPrev()))
    TEST_CONDITION_MACRO(!(enumer->HasPrev()))
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->HasPrev())
    TEST_CONDITION_MACRO(enumer->HasPrev())
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->HasPrev())
    TEST_CONDITION_MACRO(enumer->HasPrev())
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestDynArrEnumCurrent(){

    bool fail = false;
    int items[4] = {-16, 6, 12, 7};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new DynamicArray<int>::Enumerator(*dynArr);

    TEST_CONDITION_MACRO(enumer->Current() == -16)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 6)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 12)
    enumer->MoveNext();
    TEST_CONDITION_MACRO(enumer->Current() == 7)
    delete enumer;
    delete dynArr;

    if(fail) return '0';
    return '1';

}

char TestLinkedListFullCtor(){

    bool fail = false;
    int items[6] = {-2, 14, 9, 1, 10, -13};

    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 4)
    TEST_CONDITION_MACRO(dynArr->Get(0) == -2)
    TEST_CONDITION_MACRO(dynArr->Get(1) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 9)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 1)
    delete dynArr;

    dynArr = new DynamicArray<int>(items, 0);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 0)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListDefaultCtor(){

    bool fail = false;
    DynamicArray<int> *dynArr = new DynamicArray<int>();

    TEST_CONDITION_MACRO(dynArr->GetCount() == 0)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListCopyCtor(){

    bool fail = false;
    int items[5] = {10, -3, 6, -15, 16};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 5);

    DynamicArray<int> *dynArr = new DynamicArray<int>(*dynArr0);
    delete dynArr0;

    TEST_CONDITION_MACRO(dynArr->GetCount() == 5)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 10)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -3)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 6)
    TEST_CONDITION_MACRO(dynArr->Get(3) == -15)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 16)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGetFirst(){

    bool fail = false;
    int items[4] = {17, 0, -13, -10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 4);
    
    TEST_CONDITION_MACRO(dynArr->GetFirst() == 17)
    TEST_CONDITION_MACRO(dynArr->GetFirst() == 17)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGetLast(){

    bool fail = false;
    int items[3] = {20, -5, 10};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 3);

    TEST_CONDITION_MACRO(dynArr->GetLast() == 10)
    TEST_CONDITION_MACRO(dynArr->GetLast() == 10)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGet(){
  
    bool fail = false;
    int items[5] = {16, -7, 5, 14, 2};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 5);

    TEST_CONDITION_MACRO(dynArr->Get(0) == 16)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -7)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 5)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 2)
    TEST_CONDITION_MACRO(dynArr->Get(0) == 16)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -7)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 5)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 14)
    TEST_CONDITION_MACRO(dynArr->Get(4) == 2)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGetCount(){

    bool fail = false;
    int items[6] = {-5, -15, -18, 9, -3, 17};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 6);

    TEST_CONDITION_MACRO(dynArr->GetCount() == 6)
    TEST_CONDITION_MACRO(dynArr->GetCount() == 6)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGetSubList(){
   
    bool fail = false; 
    int items[6] = {-13, -16, 0, 9, 7, 11};
    LinkedList<int> *list0 = new LinkedList<int>(items, 6);

    LinkedList<int> *list = list0->GetSubList(2, 5);
    delete list0;

    TEST_CONDITION_MACRO(list->GetCount() == 3)
    TEST_CONDITION_MACRO(list->Get(0) == 0)
    TEST_CONDITION_MACRO(list->Get(1) == 9)
    TEST_CONDITION_MACRO(list->Get(2) == 7)
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListCopy(){

    bool fail = false;
    int items[4] = {-1, -8, 7, 6};
    DynamicArray<int> *dynArr0 = new DynamicArray<int>(items, 4);

    DynamicArray<int> *dynArr = dynArr0->Copy();
    delete dynArr0;

    TEST_CONDITION_MACRO(dynArr->GetCount() == 4)
    TEST_CONDITION_MACRO(dynArr->Get(0) == -1)
    TEST_CONDITION_MACRO(dynArr->Get(1) == -8)
    TEST_CONDITION_MACRO(dynArr->Get(2) == 7)
    TEST_CONDITION_MACRO(dynArr->Get(3) == 6)
    delete dynArr;

    if(fail) return '0';
    return '1';

}
char TestLinkedListAppend(){

    bool fail = false;
    int items[2] = {5, -11};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    list->Append(10);
    TEST_CONDITION_MACRO(list->GetCount() == 3)
    TEST_CONDITION_MACRO(list->GetLast() == 10)
    list->Append(-4);
    TEST_CONDITION_MACRO(list->GetCount() == 4)
    TEST_CONDITION_MACRO(list->GetLast() == -4)
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListPrepend(){

    bool fail = false;
    int items[2] = {-11, 20};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    list->Prepend(-1);
    TEST_CONDITION_MACRO(list->GetCount() == 3)
    TEST_CONDITION_MACRO(list->GetFirst() == -1)
    list->Prepend(5);
    TEST_CONDITION_MACRO(list->GetCount() == 4)
    TEST_CONDITION_MACRO(list->GetFirst() == 5)
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListInsertAt(){

    bool fail = false;
    int items[3] = {-7, -18, 0};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    list->InsertAt(-13, 1);
    TEST_CONDITION_MACRO(list->GetCount() == 4)
    TEST_CONDITION_MACRO(list->Get(1) == -13)
    list->InsertAt(-18, 0);
    TEST_CONDITION_MACRO(list->GetCount() == 5)
    TEST_CONDITION_MACRO(list->Get(0) == -18)
    list->InsertAt(4, 5);
    TEST_CONDITION_MACRO(list->GetCount() == 6)
    TEST_CONDITION_MACRO(list->Get(5) == 4)
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListConcat(){

    bool fail = false;
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
        return '0';
    }
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListGetEnumerator(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    LinkedList<int> *list = new LinkedList<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(list);

    IEnumerable<int>::IEnumerator *enumer = list->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListEnumCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};
    LinkedList<int> *list = new LinkedList<int>(items, 4);
    int **ptr0 = reinterpret_cast<int**>(list);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListEnumMoveNext(){

    bool fail = false;
    int items[3] = {9, 8, 1};
    LinkedList<int> *list = new LinkedList<int>(items, 3);
    int **ptr0 = reinterpret_cast<int**>(list);
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);
    int **ptr = reinterpret_cast<int**>(enumer);

    if(!(enumer->MoveNext()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return '0';
    }
    if(!(enumer->MoveNext()) || ptr[0] != ptr0[1] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return '0';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';
    
}
char TestLinkedListEnumMovePrev(){

    bool fail = false;
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
        return '0';
    }
    if(!(enumer->MovePrev()) || ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete list;
        return '0';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';
    
}
char TestLinkedListEnumHasNext(){

    bool fail = false;
    int items[3] = {14, -6, 2};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(!(enumer->HasNext())){
        delete enumer;
        delete list;
        return '0';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete list;
        return '0';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete list;
        return '0';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListEnumHasPrev(){

    bool fail = false;
    int items[4] = {15, -6, -14, 11};
    LinkedList<int> *list = new LinkedList<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(enumer->HasPrev()){
        delete enumer;
        delete list;
        return '0';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete list;
        return '0';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete list;
        return '0';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';

}
char TestLinkedListEnumCurrent(){

    bool fail = false;
    int items[3] = {-16, 6, 12};
    LinkedList<int> *list = new LinkedList<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new LinkedList<int>::Enumerator(*list);

    if(enumer->Current() != -16){
        delete enumer;
        delete list;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete list;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete list;
        return '0';
    }
    delete enumer;
    delete list;

    if(fail) return '0';
    return '1';

}

char TestArrSeqFullCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -2 || (*ptr)->Get(1) != 14){
        delete seq;
        return '0';
    }
    delete seq;

    seq = new MutableArraySequence<int>(items, 0);
    ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr || (*ptr)->GetCount()){
        delete seq;
        return '0';
    }
    delete seq;

    seq = new MutableArraySequence<int>(nullptr, 3);
    ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr != 3 || (*ptr)->GetCount() != 3){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqDefaultCtor(){

    bool fail = false;
    MutableArraySequence<int> *seq = new MutableArraySequence<int>();
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);

    if(*sizePtr || (*ptr)->GetCount()){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqItemsCopyCtor(){

    bool fail = false;
    int items[2] = {-5, 0};
    DynamicArray<int> *dynArr = new DynamicArray<int>(items, 2);

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(*dynArr);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);
    delete dynArr;

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -5 || (*ptr)->Get(1) != 0){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqCopyCtor(){

    bool fail = false;
    int items[2] = {10, -3};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 2);

    MutableArraySequence<int> *seq = new MutableArraySequence<int>(*seq0);
    DynamicArray<int> **ptr = reinterpret_cast<DynamicArray<int>**>(seq);
    size_t *sizePtr = reinterpret_cast<size_t*>(ptr+1);
    delete seq0;

    if(*sizePtr != 2 || (*ptr)->GetCount() != 2 || (*ptr)->Get(0) != 10 || (*ptr)->Get(1) != -3){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGetFirst(){

    bool fail = false;
    int items[4] = {17, 0, -13, -10};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);
    
    if(seq->GetFirst() != 17){
        delete seq;
        return '0';
    }
    if(seq->GetFirst() != 17){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGetLast(){

    bool fail = false;
    int items[3] = {20, -5, 10};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    if(seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    if(seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGet(){
 
    bool fail = false;   
    int items[5] = {16, -7, 5, 14, 2};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return '0';
    }
    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGetCount(){

    bool fail = false;
    int items[6] = {-5, -15, -18, 9, -3, 17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 6);

    if(seq->GetCount() != 6){
        delete seq;
        return '0';
    }
    if(seq->GetCount() != 6){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGetSubsequence(){

    bool fail = false;   
    int items[6] = {-13, -16, 0, 9, 7, 11};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 6);

    MutableArraySequence<int> *seq = seq0->GetSubsequence(2, 5);
    delete seq0;


    if(seq->GetCount() != 3 || seq->Get(0) != 0 || seq->Get(1) != 9 || seq->Get(2) != 7){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqCopy(){

    bool fail = false;
    int items[2] = {-1, -8};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 2);

    MutableArraySequence<int> *seq = seq0->Copy();
    delete seq0;

    if(seq->GetCount() != 2 || seq->GetFirst() != -1 || seq->GetLast() != -8){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqConcat(){

    bool fail = false;
    int items1[2] = {11, 19};
    int items2[2] = {10, -9};
    MutableArraySequence<int> *seq01 = new MutableArraySequence<int>(items1, 2);
    MutableArraySequence<int> *seq02 = new MutableArraySequence<int>(items2, 2);

    MutableArraySequence<int> *seq = seq01->Concat(seq02);
    delete seq01;
    delete seq02;

    if(seq->GetCount() != 4 || seq->Get(0) != 11 || seq->Get(1) != 19 || seq->Get(2) != 10 || seq->Get(3) != -9){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqGetEnumerator(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(seq);

    IEnumerable<int>::IEnumerator *enumer = seq->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+4){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqMap(){

    bool fail = false;
    int items[3] = {9, 8, 1};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 3);

    MutableArraySequence<int> *seq = seq0->template Map<int,MutableArraySequence<int>>([](const int &x){
        return (x - 5)*2 + 3;
    });
    delete seq0;

    if(seq->GetCount() != 3 || seq->Get(0) != 11 || seq->Get(1) != 9 || seq->Get(2) != -5){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqWhere(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq0 = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq = seq0->Where([](const int &x){ return x < 10; });
    delete seq0;
    if(seq->GetCount() != 3 || seq->Get(0) != -5 || seq->Get(1) != 2 || seq->Get(2) != -17){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqReduce(){
  
    bool fail = false;  
    int items[5] = {-5, 12, 2, 19, -17};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    int res = seq->template Reduce<int>([](const int &in, const int &x){ return in+x; }, 0);
    if(res != 11) return '0';

    if(fail) return '0';
    return '1';
    
}
char TestArrSeqEnumCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqEnumMoveNext(){

    bool fail = false;
    int items[3] = {9, 8, 1};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+1 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->MoveNext()) || ptr[0] != (*ptr0)+2 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';
    
}
char TestArrSeqEnumMovePrev(){

    bool fail = false;
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
        return '0';
    }
    if(!(enumer->MovePrev()) || ptr[0] != *ptr0 || ptr[1] != *ptr0 || ptr[2] != (*ptr0)+2){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';
    
}
char TestArrSeqEnumHasNext(){

    bool fail = false;
    int items[3] = {14, -6, 2};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqEnumHasPrev(){

    bool fail = false;
    int items[4] = {15, -6, -14, 11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestArrSeqEnumCurrent(){

    bool fail = false;
    int items[3] = {-16, 6, 12};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableArraySequence<int>::Enumerator(*seq);

    if(enumer->Current() != -16){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutArrSeqAppend(){

    bool fail = false;
    int items[2] = {5, -11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);

    if(seq->Append(10) != seq || seq->GetCount() != 3 || seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutArrSeqPrepend(){

    bool fail = false;
    int items[2] = {-11, 20};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 2);

    if(seq->Prepend(-1) != seq || seq->GetCount() != 3 || seq->GetFirst() != -1){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutArrSeqInsertAt(){

    bool fail = false;
    int items[3] = {-7, -18, 0};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 3);

    if(seq->InsertAt(-13, 1) != seq || seq->GetCount() != 4 || seq->Get(1) != -13){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestImmutArrSeqAppend(){

    bool fail = false;
    int items[2] = {5, -11};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 2);

    ImmutableArraySequence<int> *seq1 = seq->Append(10);
    if(seq1->GetCount() != 3 || seq1->GetLast() != 10 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestImmutArrSeqPrepend(){

    bool fail = false;
    int items[2] = {-11, 20};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 2);

    ImmutableArraySequence<int> *seq1 = seq->Prepend(-1);
    if(seq1->GetCount() != 3 || seq1->GetFirst() != -1 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestImmutArrSeqInsertAt(){

    bool fail = false;
    int items[3] = {-7, -18, 0};
    ImmutableArraySequence<int> *seq = new ImmutableArraySequence<int>(items, 3);

    ImmutableArraySequence<int> *seq1 = seq->InsertAt(-13, 1);
    if(seq1->GetCount() != 4 || seq1->Get(1) != -13 || seq->GetCount() != 3){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}

char TestListSeqFullCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};

    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -2 || (*ptr)->Get(1) != 14){
        delete seq;
        return '0';
    }
    delete seq;

    seq = new MutableListSequence<int>(items, 0);
    ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount()){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqDefaultCtor(){

    bool fail = false;
    MutableListSequence<int> *seq = new MutableListSequence<int>();
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);

    if((*ptr)->GetCount()){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqItemsCopyCtor(){

    bool fail = false;
    int items[2] = {-5, 0};
    LinkedList<int> *list = new LinkedList<int>(items, 2);

    MutableListSequence<int> *seq = new MutableListSequence<int>(*list);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);
    delete list;

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != -5 || (*ptr)->Get(1) != 0){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqCopyCtor(){

    bool fail = false;
    int items[2] = {10, -3};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 2);

    MutableListSequence<int> *seq = new MutableListSequence<int>(*seq0);
    LinkedList<int> **ptr = reinterpret_cast<LinkedList<int>**>(seq);
    delete seq0;

    if((*ptr)->GetCount() != 2 || (*ptr)->Get(0) != 10 || (*ptr)->Get(1) != -3){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGetFirst(){

    bool fail = false;
    int items[4] = {17, 0, -13, -10};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);
    
    if(seq->GetFirst() != 17){
        delete seq;
        return '0';
    }
    if(seq->GetFirst() != 17){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGetLast(){

    bool fail = false;
    int items[3] = {20, -5, 10};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    if(seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    if(seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGet(){
 
    bool fail = false;   
    int items[5] = {16, -7, 5, 14, 2};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);

    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return '0';
    }
    if(seq->Get(0) != 16 || seq->Get(1) != -7 || seq->Get(2) != 5 || seq->Get(3) != 14 ||
                seq->Get(4) != 2){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGetCount(){

    bool fail = false;
    int items[6] = {-5, -15, -18, 9, -3, 17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 6);

    if(seq->GetCount() != 6){
        delete seq;
        return '0';
    }
    if(seq->GetCount() != 6){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGetSubsequence(){
  
    bool fail = false;  
    int items[6] = {-13, -16, 0, 9, 7, 11};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 6);

    MutableListSequence<int> *seq = seq0->GetSubsequence(2, 5);
    delete seq0;


    if(seq->GetCount() != 3 || seq->Get(0) != 0 || seq->Get(1) != 9 || seq->Get(2) != 7){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqCopy(){

    bool fail = false;
    int items[2] = {-1, -8};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 2);

    MutableListSequence<int> *seq = seq0->Copy();
    delete seq0;

    if(seq->GetCount() != 2 || seq->GetFirst() != -1 || seq->GetLast() != -8){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqConcat(){

    bool fail = false;
    int items1[2] = {11, 19};
    int items2[2] = {10, -9};
    MutableListSequence<int> *seq01 = new MutableListSequence<int>(items1, 2);
    MutableListSequence<int> *seq02 = new MutableListSequence<int>(items2, 2);

    MutableListSequence<int> *seq = seq01->Concat(seq02);
    delete seq01;
    delete seq02;

    if(seq->GetCount() != 4 || seq->Get(0) != 11 || seq->Get(1) != 19 || seq->Get(2) != 10 || seq->Get(3) != -9){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqGetEnumerator(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);
    int **ptr0 = reinterpret_cast<int**>(seq);

    IEnumerable<int>::IEnumerator *enumer = seq->GetEnumerator();
    int **ptr = reinterpret_cast<int**>(enumer);

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqMap(){

    bool fail = false;
    int items[3] = {9, 8, 1};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 3);

    MutableListSequence<int> *seq = seq0->template Map<int,MutableListSequence<int>>([](const int &x){
        return (x - 5)*2 + 3;
    });
    delete seq0;

    if(seq->GetCount() != 3 || seq->Get(0) != 11 || seq->Get(1) != 9 || seq->Get(2) != -5){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqWhere(){

    bool fail = false;
    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq0 = new MutableListSequence<int>(items, 5);

    MutableListSequence<int> *seq = seq0->Where([](const int &x){ return x < 10; });
    delete seq0;
    if(seq->GetCount() != 3 || seq->Get(0) != -5 || seq->Get(1) != 2 || seq->Get(2) != -17){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqReduce(){
  
    bool fail = false;  
    int items[5] = {-5, 12, 2, 19, -17};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 5);

    int res = seq->template Reduce<int>([](const int &in, const int &x){ return in+x; }, 0);
    if(res != 11) return '0';

    if(fail) return '0';
    return '1';
    
}
char TestListSeqEnumCtor(){

    bool fail = false;
    int items[4] = {-2, 14, 9, 1};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);
    int **ptr0 = *(reinterpret_cast<int***>(seq));

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqEnumMoveNext(){

    bool fail = false;
    int items[3] = {9, 8, 1};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);
    int **ptr0 = *(reinterpret_cast<int***>(seq));
    int **nextPtr0 = (reinterpret_cast<int**>((*ptr0)+1))+1;

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);
    int **ptr = *(reinterpret_cast<int***>(enumer));

    if(!(enumer->MoveNext()) || ptr[0] != nextPtr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->MoveNext()) || ptr[0] != ptr0[1] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->MoveNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';
    
}
char TestListSeqEnumMovePrev(){

    bool fail = false;
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
        return '0';
    }
    if(!(enumer->MovePrev()) || ptr[0] != ptr0[0] || ptr[1] != ptr0[0] || ptr[2] != ptr0[1]){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->MovePrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';
    
}
char TestListSeqEnumHasNext(){

    bool fail = false;
    int items[3] = {14, -6, 2};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->HasNext())){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    enumer->MoveNext();
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->HasNext()){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqEnumHasPrev(){

    bool fail = false;
    int items[4] = {15, -6, -14, 11};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 4);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    if(enumer->HasPrev()){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return '0';
    }
    if(!(enumer->HasPrev())){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestListSeqEnumCurrent(){

    bool fail = false;
    int items[3] = {-16, 6, 12};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    IEnumerable<int>::IEnumerator *enumer = new MutableListSequence<int>::Enumerator(*seq);

    if(enumer->Current() != -16){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 6){
        delete enumer;
        delete seq;
        return '0';
    }
    enumer->MoveNext();
    if(enumer->Current() != 12){
        delete enumer;
        delete seq;
        return '0';
    }
    delete enumer;
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutListSeqAppend(){

    bool fail = false;
    int items[2] = {5, -11};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);

    if(seq->Append(10) != seq || seq->GetCount() != 3 || seq->GetLast() != 10){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutListSeqPrepend(){

    bool fail = false;
    int items[2] = {-11, 20};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 2);

    if(seq->Prepend(-1) != seq || seq->GetCount() != 3 || seq->GetFirst() != -1){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestMutListSeqInsertAt(){

    bool fail = false;
    int items[3] = {-7, -18, 0};
    MutableListSequence<int> *seq = new MutableListSequence<int>(items, 3);

    if(seq->InsertAt(-13, 1) != seq || seq->GetCount() != 4 || seq->Get(1) != -13){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestImmutListSeqAppend(){

    bool fail = false;
    int items[2] = {5, -11};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 2);

    ImmutableListSequence<int> *seq1 = seq->Append(10);
    if(seq1->GetCount() != 3 || seq1->GetLast() != 10 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestImmutListSeqPrepend(){

    bool fail = false;
    int items[2] = {-11, 20};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 2);

    ImmutableListSequence<int> *seq1 = seq->Prepend(-1);
    if(seq1->GetCount() != 3 || seq1->GetFirst() != -1 || seq->GetCount() != 2){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestImmutListSeqInsertAt(){

    bool fail = false;
    int items[3] = {-7, -18, 0};
    ImmutableListSequence<int> *seq = new ImmutableListSequence<int>(items, 3);

    ImmutableListSequence<int> *seq1 = seq->InsertAt(-13, 1);
    if(seq1->GetCount() != 4 || seq1->Get(1) != -13 || seq->GetCount() != 3){
        delete seq;
        delete seq1;
        return '0';
    }
    delete seq;
    delete seq1;

    if(fail) return '0';
    return '1';

}

char TestSeqMathMinMaxAvg(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    SequenceMath::MinMaxAvgType<int> mma = SequenceMath::MinMaxAvg<MutableArraySequence<int>,int>(*seq);

    if(mma.min != -9 || mma.max != 27 || mma.avg != 9){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestSeqMathMedian(){

    bool fail = false;
    int items[4] = {-7, 16, 4, -11};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 4);

    if(SequenceMath::Median<MutableArraySequence<int>,int>(*seq) != 4){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestSeqMathPermutationQuantity(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    if(SequenceMath::PermutationQuantity<MutableArraySequence<int>,int>(*seq) != 60){
        delete seq;
        return '0';
    }
    delete seq;

    if(fail) return '0';
    return '1';

}
char TestSeqMathLessPrevious(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<MutableArraySequence<int>*> *seqSeq =
                SequenceMath::LessPrevious<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    delete seq;


    if(seqSeq->Get(0)->GetCount() != 0){
        delete seqSeq;
        return '0';
    }
    if(seqSeq->Get(1)->GetCount() != 1 || seqSeq->Get(1)->Get(0) != -4){
        delete seqSeq;
        return '0';
    }
    if(seqSeq->Get(2)->GetCount() != 1 || seqSeq->Get(2)->Get(0) != -4){
        delete seqSeq;
        return '0';
    }
    if(seqSeq->Get(3)->GetCount() != 3 || seqSeq->Get(2)->Get(0) != -4 || seqSeq->Get(2)->Get(1) != 16 ||
                seqSeq->Get(2)->Get(2) != 16){
        delete seqSeq;
        return '0';
    }
    if(seqSeq->Get(4)->GetCount() != 0){
        delete seqSeq;
        return '0';
    }
    delete seqSeq;

    if(fail) return '0';
    return '1';

}
char TestSeqMathPrefixesPostfixes(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<MutableArraySequence<int>*> *seqSeq1 =
                SequenceMath::Prefixes<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    MutableArraySequence<MutableArraySequence<int>*> *seqSeq2 =
                SequenceMath::Postfixes<MutableArraySequence<MutableArraySequence<int>*>,
                MutableArraySequence<int>,int>(*seq);
    delete seq;

    for(std::size_t numb = 0, numb1; numb < 5; numb++){
        if(seqSeq1->Get(numb)->GetCount() != numb+1 || seqSeq2->Get(4-numb)->GetCount() != numb+1){
            delete seqSeq1;
            delete seqSeq2;
            return '0';
        }
        for(numb1 = 0; numb1 <= numb; numb1++){
            if(seqSeq1->Get(numb)->Get(numb1) != items[numb1] ||
                        seqSeq2->Get(4-numb)->Get(numb-numb1) != items[4-numb1]){
                delete seqSeq1;
                delete seqSeq2;
                return '0';
            }
        }
    }
    delete seqSeq1;
    delete seqSeq2;

    if(fail) return '0';
    return '1';

}
char TestSeqMathNeighbourMeans(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::NeighbourMeans<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(1) != 9 || seq1->Get(2) != 19 || seq1->Get(3) != 11){
        delete seq1;
        return '0';
    }
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestSeqMathQuadraticMeans(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::QuadraticMeans<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(0) != 18 || seq1->Get(1) != 16 || seq1->Get(2) != 16 ||
                seq1->Get(3) != 12 || seq1->Get(4) != 17){
        delete seq1;
        return '0';
    }
    delete seq1;

    if(fail) return '0';
    return '1';

}
char TestSeqMathReflectionSums(){

    bool fail = false;
    int items[5] = {-4, 16, 16, 27, -9};
    MutableArraySequence<int> *seq = new MutableArraySequence<int>(items, 5);

    MutableArraySequence<int> *seq1 = SequenceMath::ReflectionSums<MutableArraySequence<int>,int>(*seq);
    delete seq;

    if(seq1->GetCount() != 5 || seq1->Get(0) != -13 || seq1->Get(1) != 43 || seq1->Get(2) != 32 ||
                seq1->Get(3) != 43 || seq1->Get(4) != -13){
        delete seq1;
        return '0';
    }
    delete seq1;

    if(fail) return '0';
    return '1';

}

void DoTest(){

    int count = 0;

    TEST_COUNTER_MACRO(TestDynArrFullCtor)
    TEST_COUNTER_MACRO(TestDynArrSizeCtor)
    TEST_COUNTER_MACRO(TestDynArrCopyCtor)
    TEST_COUNTER_MACRO(TestDynArrGetFirst)
    TEST_COUNTER_MACRO(TestDynArrGetLast)
    TEST_COUNTER_MACRO(TestDynArrGet)
    TEST_COUNTER_MACRO(TestDynArrGetCount)
    TEST_COUNTER_MACRO(TestDynArrCopy)
    TEST_COUNTER_MACRO(TestDynArrSet)
    TEST_COUNTER_MACRO(TestDynArrResize)
    TEST_COUNTER_MACRO(TestDynArrGetEnumerator)
    TEST_COUNTER_MACRO(TestDynArrEnumCtor)
    TEST_COUNTER_MACRO(TestDynArrEnumCtorWithIndex)
    TEST_COUNTER_MACRO(TestDynArrEnumMoveNext)
    TEST_COUNTER_MACRO(TestDynArrEnumMovePrev)
    TEST_COUNTER_MACRO(TestDynArrEnumHasNext)
    TEST_COUNTER_MACRO(TestDynArrEnumHasPrev)
    TEST_COUNTER_MACRO(TestDynArrEnumCurrent)

    TEST_COUNTER_MACRO(TestLinkedListFullCtor)
    TEST_COUNTER_MACRO(TestLinkedListDefaultCtor)
    TEST_COUNTER_MACRO(TestLinkedListCopyCtor)
    TEST_COUNTER_MACRO(TestLinkedListGetFirst)
    TEST_COUNTER_MACRO(TestLinkedListGetLast)
    TEST_COUNTER_MACRO(TestLinkedListGet)
    TEST_COUNTER_MACRO(TestLinkedListGetCount)
    TEST_COUNTER_MACRO(TestLinkedListGetSubList)
    TEST_COUNTER_MACRO(TestLinkedListCopy)
    TEST_COUNTER_MACRO(TestLinkedListAppend)
    TEST_COUNTER_MACRO(TestLinkedListPrepend)
    TEST_COUNTER_MACRO(TestLinkedListInsertAt)
    TEST_COUNTER_MACRO(TestLinkedListConcat)
    TEST_COUNTER_MACRO(TestLinkedListGetEnumerator)
    TEST_COUNTER_MACRO(TestLinkedListEnumCtor)
    TEST_COUNTER_MACRO(TestLinkedListEnumMoveNext)
    TEST_COUNTER_MACRO(TestLinkedListEnumMovePrev)
    TEST_COUNTER_MACRO(TestLinkedListEnumHasNext)
    TEST_COUNTER_MACRO(TestLinkedListEnumHasPrev)
    TEST_COUNTER_MACRO(TestLinkedListEnumCurrent)

    TEST_COUNTER_MACRO(TestArrSeqFullCtor)
    TEST_COUNTER_MACRO(TestArrSeqDefaultCtor)
    TEST_COUNTER_MACRO(TestArrSeqItemsCopyCtor)
    TEST_COUNTER_MACRO(TestArrSeqCopyCtor)
    TEST_COUNTER_MACRO(TestArrSeqGetFirst)
    TEST_COUNTER_MACRO(TestArrSeqGetLast)
    TEST_COUNTER_MACRO(TestArrSeqGet)
    TEST_COUNTER_MACRO(TestArrSeqGetCount)
    TEST_COUNTER_MACRO(TestArrSeqGetSubsequence)
    TEST_COUNTER_MACRO(TestArrSeqCopy)
    TEST_COUNTER_MACRO(TestArrSeqConcat)
    TEST_COUNTER_MACRO(TestArrSeqGetEnumerator)
    TEST_COUNTER_MACRO(TestArrSeqMap)
    TEST_COUNTER_MACRO(TestArrSeqWhere)
    TEST_COUNTER_MACRO(TestArrSeqReduce)
    TEST_COUNTER_MACRO(TestArrSeqEnumCtor)
    TEST_COUNTER_MACRO(TestArrSeqEnumMoveNext)
    TEST_COUNTER_MACRO(TestArrSeqEnumMovePrev)
    TEST_COUNTER_MACRO(TestArrSeqEnumHasNext)
    TEST_COUNTER_MACRO(TestArrSeqEnumHasPrev)
    TEST_COUNTER_MACRO(TestArrSeqEnumCurrent)
    TEST_COUNTER_MACRO(TestMutArrSeqAppend)
    TEST_COUNTER_MACRO(TestMutArrSeqPrepend)
    TEST_COUNTER_MACRO(TestMutArrSeqInsertAt)
    TEST_COUNTER_MACRO(TestImmutArrSeqAppend)
    TEST_COUNTER_MACRO(TestImmutArrSeqPrepend)
    TEST_COUNTER_MACRO(TestImmutArrSeqInsertAt)

    TEST_COUNTER_MACRO(TestListSeqFullCtor)
    TEST_COUNTER_MACRO(TestListSeqDefaultCtor)
    TEST_COUNTER_MACRO(TestListSeqItemsCopyCtor)
    TEST_COUNTER_MACRO(TestListSeqCopyCtor)
    TEST_COUNTER_MACRO(TestListSeqGetFirst)
    TEST_COUNTER_MACRO(TestListSeqGetLast)
    TEST_COUNTER_MACRO(TestListSeqGet)
    TEST_COUNTER_MACRO(TestListSeqGetCount)
    TEST_COUNTER_MACRO(TestListSeqGetSubsequence)
    TEST_COUNTER_MACRO(TestListSeqCopy)
    TEST_COUNTER_MACRO(TestListSeqConcat)
    TEST_COUNTER_MACRO(TestListSeqGetEnumerator)
    TEST_COUNTER_MACRO(TestListSeqMap)
    TEST_COUNTER_MACRO(TestListSeqWhere)
    TEST_COUNTER_MACRO(TestListSeqReduce)
    TEST_COUNTER_MACRO(TestListSeqEnumCtor)
    TEST_COUNTER_MACRO(TestListSeqEnumMoveNext)
    TEST_COUNTER_MACRO(TestListSeqEnumMovePrev)
    TEST_COUNTER_MACRO(TestListSeqEnumHasNext)
    TEST_COUNTER_MACRO(TestListSeqEnumHasPrev)
    TEST_COUNTER_MACRO(TestListSeqEnumCurrent)
    TEST_COUNTER_MACRO(TestMutListSeqAppend)
    TEST_COUNTER_MACRO(TestMutListSeqPrepend)
    TEST_COUNTER_MACRO(TestMutListSeqInsertAt)
    TEST_COUNTER_MACRO(TestImmutListSeqAppend)
    TEST_COUNTER_MACRO(TestImmutListSeqPrepend)
    TEST_COUNTER_MACRO(TestImmutListSeqInsertAt)

    TEST_COUNTER_MACRO(TestSeqMathMinMaxAvg)
    TEST_COUNTER_MACRO(TestSeqMathMedian)
    TEST_COUNTER_MACRO(TestSeqMathPermutationQuantity)
    TEST_COUNTER_MACRO(TestSeqMathLessPrevious)
    TEST_COUNTER_MACRO(TestSeqMathPrefixesPostfixes)
    TEST_COUNTER_MACRO(TestSeqMathNeighbourMeans)
    TEST_COUNTER_MACRO(TestSeqMathQuadraticMeans)
    TEST_COUNTER_MACRO(TestSeqMathReflectionSums)

    std::cout << count << " of 100 tests passed" << std::endl;

}