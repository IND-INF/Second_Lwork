#ifndef _SEQUENCE_MATH_H_
#define _SEQUENCE_MATH_H_

#include <cstddef>
#include <cmath>

namespace SequenceMath{

    template <class T>
    class MinMaxAvgType{
        public:
            T min;
            T max;
            T avg;
    };

    template <class sequenceType, class T>
    MinMaxAvgType<T> MinMaxAvg(const sequenceType &sequence);

    template <class sequenceType, class T>
    T QuickSelect(const sequenceType &sequence, const std::size_t &number);
    template <class sequenceType, class T>
    T Median(const sequenceType &sequence);

    template <class sequenceType, class T>
    void QuickSort(sequenceType &sequence);
    template <class sequenceType, class T>
    std::size_t PermutationQuantity(const sequenceType &sequence);

    template <class seqOfSeqsType, class sequenceType, class T>
    seqOfSeqsType* LessPrevious(const sequenceType &sequence);

    template <class seqOfSeqsType, class sequenceType, class T>
    seqOfSeqsType* Prefixes(const sequenceType &sequence);
    template <class seqOfSeqsType, class sequenceType, class T>
    seqOfSeqsType* Postfixes(const sequenceType &sequence);

    template <class sequenceType, class T>
    sequenceType* NeighbourMeans(const sequenceType &sequence);

    template <class sequenceType, class T>
    sequenceType* QuadraticMeans(const sequenceType &sequence);

    template <class sequenceType, class T>
    sequenceType* ReflectionSums(const sequenceType &sequence);

}

#include "sequence_math.tpp"

#endif //_SEQUENCE_MATH_H_