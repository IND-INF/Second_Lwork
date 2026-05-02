#ifndef _IMMUTABLE_ARRAY_SEQUENCE_H_
#define _IMMUTABLE_ARRAY_SEQUENCE_H_

#include "array_sequence.h"

template <class T>
class ImmutableArraySequence : public ArraySequence<T,ImmutableArraySequence<T>>{
    protected:
        ImmutableArraySequence<T>* Instance() override;
    public:
        ImmutableArraySequence(const T *items, size_t count);
        ImmutableArraySequence();
        ImmutableArraySequence(const DynamicArray<T> &dynamicArray);
        ImmutableArraySequence(const ImmutableArraySequence<T> &arraySequence);
};

#include "immutable_array_sequence.tpp"

#endif //_IMMUTABLE_ARRAY_SEQUENCE_H_