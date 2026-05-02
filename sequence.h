#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <stddef.h>
#include "collection.h"

template <class T>
class Sequence : public ICollection<T>{
    public:

        virtual ~Sequence();

        virtual const T& GetFirst() const = 0;
        virtual const T& GetLast() const = 0;
        virtual Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const = 0;

        virtual Sequence<T>* Append(const T &item) = 0;
        virtual Sequence<T>* Prepend(const T &item) = 0;
        virtual Sequence<T>* InsertAt(const T &item, size_t index) = 0;
        virtual Sequence<T>* Concat(const Sequence<T> *list) const = 0;
        
};

#include "sequence.tpp"

#endif //_SEQUENCE_H_