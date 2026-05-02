#define LONG_LONG_INT_IN_MB 131072

template <class T, class Derived>
void ArraySequence<T,Derived>::Resize(size_t newSize){

    size_t capacity = items->GetCount();

    if(newSize > size){
        if(newSize > capacity){

            size_t newCapacity;
            if(capacity <= LONG_LONG_INT_IN_MB){
                newCapacity = 2*capacity;
            }else{
                newCapacity = capacity + LONG_LONG_INT_IN_MB;
            }

            if(newSize <= newCapacity){
                items->Resize(newCapacity);
            }else{
                items->Resize(newSize);
            }

        }
    }else{
        if(newSize <= capacity/3){
            items->Resize(capacity/2);
        }
    }

    size = newSize;

}

template <class T, class Derived>
ArraySequence<T,Derived>::Enumerator::Enumerator(const ArraySequence<T,Derived> &arraySequence){
    if(!arraySequence.size) throw EnumeratorCtorError();
    innerEnumerator = new typename DynamicArray<T>::Enumerator(*(arraySequence.items), arraySequence.size - 1);
}

template <class T, class Derived>
const T& ArraySequence<T,Derived>::Enumerator::Current() const{
    return innerEnumerator->Current();
}

template <class T, class Derived>
bool ArraySequence<T,Derived>::Enumerator::HasNext() const{
    return innerEnumerator->HasNext();
}

template <class T, class Derived>
bool ArraySequence<T,Derived>::Enumerator::MoveNext(){
    return innerEnumerator->MoveNext();
}

template <class T, class Derived>
bool ArraySequence<T,Derived>::Enumerator::HasPrev() const{
    return innerEnumerator->HasPrev();
}

template <class T, class Derived>
bool ArraySequence<T,Derived>::Enumerator::MovePrev(){
    return innerEnumerator->MovePrev();
}

template <class T, class Derived>
ArraySequence<T,Derived>::ArraySequence(const T *items, size_t count){
    this->items = new DynamicArray<T>(items, count);
    size = count;
}

template <class T, class Derived>
ArraySequence<T,Derived>::ArraySequence(){
    items = new DynamicArray<T>(0);
    size = 0;
}

template <class T, class Derived>
ArraySequence<T,Derived>::ArraySequence(const DynamicArray<T> &dynamicArray){
    items = new DynamicArray<T>(dynamicArray);
    size = dynamicArray.GetCount();
}

template <class T, class Derived>
ArraySequence<T,Derived>::ArraySequence(const ArraySequence<T,Derived> &arraySequence){

    size = arraySequence.GetCount();

    items = new DynamicArray<T>(size);
    for(size_t number = 0; number < size; number++){
        items->Set(number, arraySequence.Get(number));
    }
    
}

template <class T, class Derived>
ArraySequence<T,Derived>::~ArraySequence(){
    delete items;
}

template <class T, class Derived>
const T& ArraySequence<T,Derived>::GetFirst() const{
    if(!size) throw EmptySequence();
    return items->GetFirst();
}

template <class T, class Derived>
const T& ArraySequence<T,Derived>::GetLast() const{
    if(!size) throw EmptySequence();
    return items->Get(size-1);
}

template <class T, class Derived>
const T& ArraySequence<T,Derived>::Get(size_t index) const{
    if(index >= size) throw ElementIndexOutOfRange(index, size);
    return items->Get(index);
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::GetSubsequence(size_t startIndex, size_t endIndex) const{
    return static_cast<Sequence<T>*>(DirectGetSubsequence(startIndex, endIndex));
}

template <class T, class Derived>
size_t ArraySequence<T,Derived>::GetCount() const{
    return size;
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::Copy() const{
    return static_cast<Sequence<T>*>(DirectCopy());
}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectGetSubsequence(size_t startIndex, size_t endIndex) const{

    if(startIndex >= size) throw ElementIndexOutOfRange(startIndex, size);
    if(endIndex > size) throw IndexOutOfRange(endIndex, size);

    size_t subSize;
    DynamicArray<T> *subItems;
    if(endIndex > startIndex){

        subSize = endIndex-startIndex;
        subItems = new DynamicArray<T>(subSize);

        for(size_t number = 0; number < subSize; number++){
            subItems->Set(number, items->Get(number+startIndex));
        }

    }else{
        subSize = 0;
        subItems = new DynamicArray<T>(0);
    }

    Derived *subSeq = new Derived;
    subSeq->items = subItems;
    subSeq->size = subSize;

    return subSeq;

}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectCopy() const{
    return new Derived(*(static_cast<const Derived*>(this)));
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::Append(const T &item){
    return static_cast<Sequence<T>*>(DirectAppend(item));
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::Prepend(const T &item){
    return static_cast<Sequence<T>*>(DirectPrepend(item));
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::InsertAt(const T &item, size_t index){
    return static_cast<Sequence<T>*>(DirectInsertAt(item, index));
}

template <class T, class Derived>
Sequence<T>* ArraySequence<T,Derived>::Concat(const Sequence<T> *list) const{
    return static_cast<Sequence<T>*>(DirectConcat(list));
}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectAppend(const T &item){
    return DirectInsertAt(item, size);
}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectPrepend(const T &item){
    return DirectInsertAt(item, 0);
}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectInsertAt(const T &item, size_t index){

    if(index > size) throw IndexOutOfRange(index, size);

    Derived *instance = Instance();

    instance->Resize(size+1);

    for(size_t number = size-1; number > index; number--){
        instance->items->Set(number, items->Get(number-1));
    }

    instance->items->Set(index, item);
    return instance;

}

template <class T, class Derived>
Derived* ArraySequence<T,Derived>::DirectConcat(const Sequence<T> *list) const{

    const Derived *arrSeq = dynamic_cast<const Derived*>(list);
    size_t listSize = arrSeq->GetCount();

    DynamicArray<T> *newItems = new DynamicArray<T>(size+listSize);

    for(size_t number = 0; number < size; number++){
        newItems->Set(number, items->Get(number));
    }
    for(size_t number = 0; number < listSize; number++){
        newItems->Set(number+size, arrSeq->Get(number));
    }

    Derived *newSeq = new Derived;
    newSeq->items = newItems;
    newSeq->size = size+listSize;

    return newSeq;

}

template <class T, class Derived>
template <class T2, class Derived2, class Func>
Derived2* ArraySequence<T,Derived>::Map(Func func) const{

    DynamicArray<T2> *mapItems = new DynamicArray<T2>(size);

    for(size_t number = 0; number < size; number++){
        mapItems->Set(number, func(items->Get(number)));
    }

    Derived2 *mapSeq = new Derived2(*mapItems);
    delete mapItems;

    return mapSeq;

}

template <class T, class Derived>
template <class Func>
Derived* ArraySequence<T,Derived>::Where(Func func) const{

    DynamicArray<T> *whereItems = new DynamicArray<T>(size);

    size_t count = 0;
    for(size_t number = 0; number < size; number++){
        if(func(items->Get(number))){
            whereItems->Set(count, items->Get(number));
            count++;
        }
    }
    whereItems->Resize(count);

    Derived *whereSeq = new Derived;
    whereSeq->items = whereItems;
    whereSeq->size = count;

    return whereSeq;

}

template <class T, class Derived>
template <class T2, class Func>
T2 ArraySequence<T,Derived>::Reduce(Func func, const T2 &initial) const{

    T2 res = initial;

    for(size_t number = 0; number < size; number++){
        res = func(res, items->Get(number));
    }

    return res;

}

template <class T, class Derived>
typename IEnumerable<T>::IEnumerator* ArraySequence<T,Derived>::GetEnumerator() const{
    return new typename ArraySequence<T,Derived>::Enumerator(*this);
}