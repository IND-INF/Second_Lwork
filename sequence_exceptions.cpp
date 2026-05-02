#include "sequence_exceptions.h"

ElementIndexOutOfRange::ElementIndexOutOfRange(size_t entered, size_t current) : enteredIndex(entered), currentSize(current),
            message("The entered index of the requested element is " + std::to_string(enteredIndex) +
                ", though the sequence size is" + std::to_string(currentSize) + "."){}

const char* ElementIndexOutOfRange::what() const noexcept{
    return message.c_str();
}

IndexOutOfRange::IndexOutOfRange(size_t entered, size_t current) : enteredSize(entered), currentSize(current),
            message("The entered end index is " + std::to_string(enteredSize) +
                ", though the sequence size is" + std::to_string(currentSize) + "."){}

const char* IndexOutOfRange::what() const noexcept{
    return message.c_str();
}

const char* EnumeratorCtorError::what() const noexcept{
    return "The sequence is empty, so the enumerator can't be constructed.";
}

const char* ListCtorError::what() const noexcept{
    return "The list items can't be created since the passed items pointer is a nullptr.";
}

const char* EmptySequence::what() const noexcept{
    return "The sequence is empty, so the element does not exist.";
}

