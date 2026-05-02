#ifndef _MUTABLE_ARRAY_SEQUENCE_H_
#define _MUTABLE_ARRAY_SEQUENCE_H_

#include "array_sequence.h"

template <class T>
class MutableArraySequence : public ArraySequence<T,MutableArraySequence<T>>{
    protected:
        MutableArraySequence<T>* Instance() override;
    public:
        MutableArraySequence(const T *items, size_t count);
        MutableArraySequence();
        MutableArraySequence(const DynamicArray<T> &dynamicArray);
        MutableArraySequence(const MutableArraySequence<T> &arraySequence);
};

#include "mutable_array_sequence.tpp"

#endif //_MUTABLE_ARRAY_SEQUENCE_H_