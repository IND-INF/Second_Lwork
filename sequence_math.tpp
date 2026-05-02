template <class sequenceType, class T>
SequenceMath::MinMaxAvgType<T> SequenceMath::MinMaxAvg(const sequenceType &sequence){

    SequenceMath::MinMaxAvgType<T> initial;
    initial.min = initial.max = initial.avg = sequence.GetFirst();

    initial = sequence.template Reduce<SequenceMath::MinMaxAvgType<T>>
                ([](const SequenceMath::MinMaxAvgType<T>& initial, const T &element){
        
        SequenceMath::MinMaxAvgType<T> ans = initial;

        if(ans.min > element) ans.min = element;
        else if(ans.max < element) ans.max = element;
        
        ans.avg += element;

        return ans;

    }, initial);
    initial.avg -= sequence.GetFirst();

    SequenceMath::MinMaxAvgType<T> ans;
    ans.min = initial.min;
    ans.max = initial.max;
    ans.avg = initial.avg/sequence.GetCount();
    
    return ans;

}

template <class sequenceType, class T>
T SequenceMath::QuickSelect(const sequenceType &sequence, const size_t &number){

    if(sequence.GetCount() == 1) return sequence.GetFirst();

    T pivot = (sequence.GetFirst() + sequence.GetLast()) / 2;

    sequenceType *lessPart = sequence.Where([&pivot](T x){ return pivot > x; });
    if(lessPart->GetCount() > number){
        pivot = SequenceMath::QuickSelect<sequenceType, T>(*lessPart, number);
        delete lessPart;
        return pivot;
    }
    delete lessPart;

    sequenceType *greaterPart = sequence.Where([&pivot](T x){ return pivot < x; });
    size_t lessOrEqualCount = sequence.GetCount() - greaterPart->GetCount();
    if(lessOrEqualCount <= number){
        pivot = SequenceMath::QuickSelect<sequenceType, T>(*greaterPart, number - lessOrEqualCount);
        delete greaterPart;
        return pivot;
    }
    delete greaterPart;
    
    return pivot;

}

template <class sequenceType, class T>
T SequenceMath::Median(const sequenceType &sequence){
    size_t number = sequence.GetCount() / 2;
    return SequenceMath::QuickSelect<sequenceType,T>(sequence, number);
}

template <class sequenceType, class T>
void SequenceMath::QuickSort(sequenceType *&sequence){
    
    if(sequence->GetCount() <= 1) return;

    T pivot = (sequence->GetFirst() + sequence->GetLast()) / 2;

    sequenceType *lessPart = sequence->Where([&pivot](T x){ return pivot > x; });
    if(!lessPart->GetCount()){

        sequenceType *greaterPart = sequence->Where([&pivot](T x){ return pivot < x; });
        if(!greaterPart->GetCount()) return;

        sequenceType *notGreaterPart = sequence->Where([&pivot](T x){ return !(pivot < x); });

        SequenceMath::QuickSort<sequenceType,T>(greaterPart);
        SequenceMath::QuickSort<sequenceType,T>(notGreaterPart);

        delete sequence;
        sequence = notGreaterPart->DirectConcat(greaterPart);

        delete greaterPart;
        delete notGreaterPart;

    }else{

        sequenceType *notLessPart = sequence->Where([&pivot](T x){ return !(pivot > x); });
        
        SequenceMath::QuickSort<sequenceType,T>(lessPart);
        SequenceMath::QuickSort<sequenceType,T>(notLessPart);

        delete sequence;
        sequence = lessPart->DirectConcat(notLessPart);

        delete lessPart;
        delete notLessPart;

    }

}

template <class sequenceType, class T>
size_t SequenceMath::PermutationQuantity(const sequenceType &sequence){
    
    sequenceType *copy = sequence.DirectCopy();
    SequenceMath::QuickSort<sequenceType,T>(copy);

    typedef struct struct_Quadruplet{
        size_t perms;
        size_t number;
        T prev;
        size_t equalNumber;
    } Quadruplet;

    Quadruplet initial;
    initial.perms = 1;
    initial.number = 0;
    initial.prev = copy->GetFirst();
    initial.equalNumber = 0;

    initial = copy->template Reduce<Quadruplet>([](const Quadruplet &initial, const T &element){
        
        Quadruplet ans = initial;
        
        ans.number++;
        ans.perms *= ans.number;

        if(ans.prev == element){
            ans.equalNumber++;
            ans.perms /= ans.equalNumber;
        }else{
            ans.prev = element;
            ans.equalNumber = 1;
        }

        return ans;

    }, initial);

    delete copy;
    return initial.perms;

}

template <class seqOfSeqType, class sequenceType, class T>
seqOfSeqType* SequenceMath::LessPrevious(const sequenceType &sequence){

    size_t number = 0;

    seqOfSeqType *ans = sequence.template Map<sequenceType*,seqOfSeqType>([&sequence, &number](const T &element){

        T current = element;

        sequenceType *subseq = sequence.DirectGetSubsequence(0, number);
        number++;

        sequenceType *subans = subseq->Where([&current](const T &x){ return current > x; });

        delete subseq;
        return subans;

    });

    return ans;

}

template <class seqOfSeqType, class sequenceType, class T>
seqOfSeqType* SequenceMath::Prefixes(const sequenceType &sequence){

    size_t number = 0;

    seqOfSeqType *ans = sequence.template Map<sequenceType*,seqOfSeqType>([&sequence, &number](const T &element){
        number++;
        sequenceType *subans = sequence.DirectGetSubsequence(0, number);
        return subans;
    });

    return ans;

}

template <class seqOfSeqType, class sequenceType, class T>
seqOfSeqType* SequenceMath::Postfixes(const sequenceType &sequence){

    size_t number = 0;

    seqOfSeqType *ans = sequence.template Map<sequenceType*,seqOfSeqType>([&sequence, &number](const T &element){
        sequenceType *subans = sequence.DirectGetSubsequence(number, sequence.GetCount());
        number++;
        return subans;
    });

    return ans;

}

template <class sequenceType, class T>
sequenceType* SequenceMath::NeighbourMeans(const sequenceType &sequence){
    
    typename IEnumerable<T>::IEnumerator *nextEnumerator;
    typename IEnumerable<T>::IEnumerator *prevEnumerator;
    nextEnumerator = sequence.GetEnumerator();
    prevEnumerator = sequence.GetEnumerator();

    sequenceType *ans = sequence.template Map<T,sequenceType>([&nextEnumerator, &prevEnumerator](const T &element){
        
        if(!(nextEnumerator->HasPrev())){
            nextEnumerator->MoveNext();
            return element;
        }
        if(!(nextEnumerator->HasNext())) return element;

        nextEnumerator->MoveNext();

        T mean = (prevEnumerator->Current() + element + nextEnumerator->Current())/3;

        prevEnumerator->MoveNext();
        return mean;
        
    });

    return ans;

}

template <class sequenceType, class T>
sequenceType* SequenceMath::QuadraticMeans(const sequenceType &sequence){

    size_t subsumCount = sequence.GetCount() - 1;
    T squareSum = sequence.template Reduce<T>([](const T &initial, const T &element){
        return initial + element*element;
    }, 0);

    sequenceType *ans = sequence.template Map<T,sequenceType>([&squareSum, &subsumCount](const T &element){
        return sqrt((squareSum - element*element)/subsumCount);
    });

    return ans;

}

template <class sequenceType, class T>
sequenceType* SequenceMath::ReflectionSums(const sequenceType &sequence){

    typename IEnumerable<T>::IEnumerator *reflectingEnumerator = sequence.GetEnumerator();
    while(reflectingEnumerator->MoveNext());

    sequenceType *ans = sequence.template Map<T,sequenceType>([&reflectingEnumerator](T element){
        T subans = element + reflectingEnumerator->Current();
        reflectingEnumerator->MovePrev();
        return subans;
    });

    return ans;
    
}