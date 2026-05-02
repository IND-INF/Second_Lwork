#ifndef _SEQUENCE_EXEPTIONS_H_
#define _SEQUENCE_EXEPTIONS_H_

#include <exception>
#include <string>

class ElementIndexOutOfRange : public std::exception{
    private:
        size_t enteredIndex;
        size_t currentSize;
        std::string message;
    public:
        ElementIndexOutOfRange(size_t entered, size_t current);
        const char* what() const noexcept override;
};

class IndexOutOfRange : public std::exception{
    private:
        size_t enteredSize;
        size_t currentSize;
        std::string message;
    public:
        IndexOutOfRange(size_t entered, size_t current);
        const char* what() const noexcept override;
};

class EnumeratorCtorError : public std::exception{
    public:
        const char* what() const noexcept override;
};

class ListCtorError : public std::exception{
    public:
        const char* what() const noexcept override;
};

class EmptySequence : public std::exception{
    public:
        const char* what() const noexcept override;
};

#endif //_SEQUENCE_EXEPTIONS_H_