#ifndef _IMMUTABLE_LIST_SEQUENCE_H_
#define _IMMUTABLE_LIST_SEQUENCE_H_

#include "list_sequence.h"

template <class T>
class ImmutableListSequence : public ListSequence<T,ImmutableListSequence<T>>{
    protected:
        ImmutableListSequence<T>* Instance() override;
    public:
        ImmutableListSequence(const T *items, const size_t &count);
        ImmutableListSequence();
        ImmutableListSequence(const LinkedList<T> &list);
        ImmutableListSequence(const ImmutableListSequence<T> &listSequence);
};

#include "immutable_list_sequence.tpp"

#endif //_IMMUTABLE_LIST_SEQUENCE_H_