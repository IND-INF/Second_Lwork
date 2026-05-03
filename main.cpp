#include "List_sequence/immutable_list_sequence.h"
#include "List_sequence/mutable_list_sequence.h"
#include "Array_sequence/immutable_array_sequence.h"
#include "Array_sequence/mutable_array_sequence.h"
#include "sequence_math.h"
#include "sequence_test.h"
#include <iostream>
#include <sstream>

#define SEQUENCE_MAP_MACRO \
do{ \
    if(isArray){ \
        if(isMutable){ \
            seqSubserv1 = (static_cast<MutableArraySequence<double>*>(seq))-> \
                        template Map<double,MutableArraySequence<double>>(func); \
        }else{ \
            seqSubserv1 = (static_cast<ImmutableArraySequence<double>*>(seq))-> \
                        template Map<double,ImmutableArraySequence<double>>(func); \
        } \
    }else{ \
        if(isMutable){ \
            seqSubserv1 = (static_cast<MutableListSequence<double>*>(seq))-> \
                        template Map<double,MutableListSequence<double>>(func); \
        }else{ \
            seqSubserv1 = (static_cast<ImmutableListSequence<double>*>(seq))-> \
                        template Map<double,ImmutableListSequence<double>>(func); \
        } \
    } \
}while(0);

#define SEQUENCE_WHERE_MACRO \
do{ \
    if(isArray){ \
        if(isMutable){ \
            seqSubserv1 = (static_cast<MutableArraySequence<double>*>(seq))->template Where(func); \
        }else{ \
            seqSubserv1 = (static_cast<ImmutableArraySequence<double>*>(seq))->template Where(func); \
        } \
    }else{ \
        if(isMutable){ \
            seqSubserv1 = (static_cast<MutableListSequence<double>*>(seq))->template Where(func); \
        }else{ \
            seqSubserv1 = (static_cast<ImmutableListSequence<double>*>(seq))->template Where(func); \
        } \
    } \
}while(0);

int main(){

    bool stopFlag = false;
    bool subStopFlag = false;
    bool noHelpNotice = false;

    std::string enteredLine;
    std::istringstream lineInput;
    char enteredValue = 0;
    double *items;

    double lfSubserv;
    size_t sizeSubserv1;
    size_t sizeSubserv2;
    char cSubserv;

    bool isDouble = false;
    bool isArray = false;
    bool isMutable = false;

    bool newIsDouble = false;
    bool newIsArray = false;
    bool newIsMutable = false;

    Sequence<double> *seq = nullptr;
    Sequence<double> *seqSubserv1;
    Sequence<double> *seqSubserv2;

    do{

        if(noHelpNotice) noHelpNotice = false;
        else std::cout << "For help, enter 0." << std::endl;

        while(1){
            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                lineInput.clear();
                lineInput.str(enteredLine);
                if(lineInput >> enteredValue) break;
            }
        }

        switch(enteredValue){
            case '0':
                std::cout << "For sequence creation, enter 1." << std::endl;
                std::cout << "For sequence modification, enter 2." << std::endl;
                std::cout << "For output, enter 3." << std::endl;
                std::cout << "For exit from the program, enter any other symbol." << std::endl;
                noHelpNotice = true;
                break;
            case '1':

                while(1){

                    std::cout << "For a list sequence, enter 0." << std::endl;
                    std::cout << "For an array sequence, enter 1." << std::endl;
                    std::cout << "For exit, enter any other symbol." << std::endl;

                    while(1){
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredValue) break;
                        }
                    }

                    if(enteredValue == '0'){
                        newIsArray = false;
                        break;
                    }else if(enteredValue == '1'){
                        newIsArray = true;
                        break;
                    }else{

                        std::cout << "Exit? [y/n]" << std::endl;

                        while(1){
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> enteredValue) break;
                            }
                        }

                        if(enteredValue == 'y') break;

                    }

                }
                if(enteredValue == 'y'){
                    std::cout << "Exiting." << std::endl;
                    break;
                }

                while(1){

                    std::cout << "For an immutable sequence, enter 0." << std::endl;
                    std::cout << "For a mutable sequence, enter 1." << std::endl;
                    std::cout << "For exit, enter any other symbol." << std::endl;

                    while(1){
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredValue) break;
                        }
                    }

                    if(enteredValue == '0'){
                        newIsMutable = false;
                        break;
                    }else if(enteredValue == '1'){
                        newIsMutable = true;
                        break;
                    }else{

                        std::cout << "Exit? [y/n]" << std::endl;

                        while(1){
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> enteredValue) break;
                            }
                        }

                        if(enteredValue == 'y') break;

                    }

                }
                if(enteredValue == 'y'){
                    std::cout << "Exiting." << std::endl;
                    break;
                }

                while(1){

                    std::cout << "Enter a size of the sequence, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredValue = 0;
                    while(1){
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> sizeSubserv1) break;
                            if(lineInput >> enteredValue) break;
                        }
                    }

                    if(!enteredValue){
                        break;
                    }else{

                        std::cout << "Exit? [y/n]" << std::endl;

                        while(1){
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> enteredValue) break;
                            }
                        }

                        if(enteredValue == 'y') break;

                    }

                }
                if(enteredValue == 'y'){
                    std::cout << "Exiting." << std::endl;
                    break;
                }

                if(sizeSubserv1 > 0){

                    std::cout << "Enter items of the sequence, or enter a nonnumeric symbol to exit." << std::endl;

                    items = new double[sizeSubserv1];
                    sizeSubserv2 = 0;
                    while(1){

                        while(1){
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                break;
                            }
                        }

                        while(sizeSubserv2 < sizeSubserv1 && lineInput >> items[sizeSubserv2]){
                            sizeSubserv2++;
                        }
                        if(sizeSubserv2 < sizeSubserv1){
                                
                            std::cout << "Exit? [y/n]" << std::endl;

                            while(1){
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> enteredValue) break;
                                }
                            }

                            if(enteredValue == 'y') break;
                            else std::cout << "Continue entering." << std::endl;

                        }

                    }
                    if(enteredValue == 'y'){
                        delete []items;
                        std::cout << "Exiting." << std::endl;
                        break;
                    }

                }

                if(newIsArray){
                    if(newIsMutable){
                        seq = new MutableArraySequence<double>(items, sizeSubserv1);
                    }else{
                        seq = new ImmutableArraySequence<double>(items, sizeSubserv1);
                    }
                }else{
                    if(newIsMutable){
                        seq = new MutableListSequence<double>(items, sizeSubserv1);
                    }else{
                        seq = new ImmutableListSequence<double>(items, sizeSubserv1);
                    }
                }
                delete []items;

                isArray = newIsArray;
                isMutable = newIsMutable;

                std::cout << "The sequence created." << std::endl;

                break;
            
            case '2':

                if(!seq){
                    std::cout << "The sequence doesn't exist." << std::endl;
                    break;
                }
                
                do{

                    if(noHelpNotice) noHelpNotice = false;
                    else std::cout << "For help, enter 0." << std::endl;

                    while(1){
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredValue) break;
                        }
                    }

                    switch(enteredValue){
                        case '0':
                            std::cout << "To get a subsequence of the sequence, enter 1." << std::endl;
                            std::cout << "To append a value to the sequence, enter 2." << std::endl;
                            std::cout << "To prepend a value to the sequence, enter 3." << std::endl;
                            std::cout << "To insert a value at some position of the sequence, enter 4." << std::endl;
                            std::cout << "To concatenate the sequence with another one, enter 5." << std::endl;
                            std::cout << "To subject the sequence to a map, enter 6." << std::endl;
                            std::cout << "To select the sequence values by a condition, enter 7." << std::endl;
                            std::cout << "To exit, enter any other symbol." << std::endl;
                            noHelpNotice = true;
                            break;
                        case '1':

                            while(1){

                                std::cout << "Enter a start index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }
                            if(sizeSubserv1 >= seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            while(1){

                                std::cout << "Enter a final index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv2) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }
                            if(sizeSubserv2 > seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            seqSubserv1 = seq->GetSubsequence(sizeSubserv1, sizeSubserv2);
                            delete seq;
                            seq = seqSubserv1;

                            std::cout << "Done." << std::endl;

                            break;

                        case '2':
                            
                            while(1){

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            seqSubserv1 = seq->Append(lfSubserv);
                            if(seq != seqSubserv1){
                                delete seq;
                                seq = seqSubserv1;
                            }

                            std::cout << "Done." << std::endl;

                            break;
                        
                        case '3':

                            while(1){

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            seqSubserv1 = seq->Prepend(lfSubserv);
                            if(seq != seqSubserv1){
                                delete seq;
                                seq = seqSubserv1;
                            }

                            std::cout << "Done." << std::endl;

                            break;

                        case '4':

                            while(1){

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            while(1){

                                std::cout << "Enter an index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }
                            if(sizeSubserv1 > seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            seqSubserv1 = seq->InsertAt(lfSubserv, sizeSubserv1);
                            if(seq != seqSubserv1){
                                delete seq;
                                seq = seqSubserv1;
                            }

                            std::cout << "Done." << std::endl;

                            break;

                        case '5':
                            
                            while(1){

                                std::cout << "Enter a size of the other sequence, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            if(sizeSubserv1 > 0){

                                std::cout << "Enter items of the other sequence, or enter a nonnumeric symbol to exit." << std::endl;

                                items = new double[sizeSubserv1];
                                sizeSubserv2 = 0;
                                while(1){

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            break;
                                        }
                                    }

                                    while(sizeSubserv2 < sizeSubserv1 && lineInput >> items[sizeSubserv2]){
                                        sizeSubserv2++;
                                    }
                                    if(sizeSubserv2 < sizeSubserv1){
                                            
                                        std::cout << "Exit? [y/n]" << std::endl;

                                        while(1){
                                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                                lineInput.clear();
                                                lineInput.str(enteredLine);
                                                if(lineInput >> enteredValue) break;
                                            }
                                        }

                                        if(enteredValue == 'y') break;
                                        else std::cout << "Continue entering." << std::endl;

                                    }

                                }
                                if(enteredValue == 'y'){
                                    delete []items;
                                    std::cout << "Exiting." << std::endl;
                                    break;
                                }

                            }

                            if(newIsArray){
                                if(newIsMutable){
                                    seqSubserv2 = new MutableArraySequence<double>(items, sizeSubserv1);
                                }else{
                                    seqSubserv2 = new ImmutableArraySequence<double>(items, sizeSubserv1);
                                }
                            }else{
                                if(newIsMutable){
                                    seqSubserv2 = new MutableListSequence<double>(items, sizeSubserv1);
                                }else{
                                    seqSubserv2 = new ImmutableListSequence<double>(items, sizeSubserv1);
                                }
                            }
                            delete []items;

                            seqSubserv1 = seq->Concat(seqSubserv2);
                            delete seqSubserv2;
                            delete seq;
                            seq = seqSubserv1;
                            
                            std::cout << "Done." << std::endl;

                            break;

                        case '6':
                            
                            while(1){

                                std::cout << "For addition, enter 1." << std::endl;
                                std::cout << "For subtraction, enter 2." << std::endl;
                                std::cout << "For multiplication, enter 3." << std::endl;
                                std::cout << "For division, enter 4." << std::endl;
                                std::cout << "For exit, enter any other symbol." << std::endl;

                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(enteredValue == '1' || enteredValue == '2' || enteredValue == '3' || enteredValue == '4'){
                                    cSubserv = enteredValue;
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            while(1){

                                if(cSubserv == '1'){
                                    std::cout << "Enter a summand, or enter a nonnumeric symbol to exit." << std::endl;
                                }else if(cSubserv == '2'){
                                    std::cout << "Enter a subtrahend, or enter a nonnumeric symbol to exit." << std::endl;
                                }else if(cSubserv == '3'){
                                    std::cout << "Enter a multiplier, or enter a nonnumeric symbol to exit." << std::endl;
                                }else{
                                    std::cout << "Enter a divisor, or enter a nonnumeric symbol to exit." << std::endl;
                                }

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            if(cSubserv == '1'){
                                auto func = [&lfSubserv](const double &x){ return x + lfSubserv; };
                                SEQUENCE_MAP_MACRO
                            }else if(cSubserv == '2'){
                                auto func = [&lfSubserv](const double &x){ return x - lfSubserv; };
                                SEQUENCE_MAP_MACRO
                            }else if(cSubserv == '3'){
                                auto func = [&lfSubserv](const double &x){ return x * lfSubserv; };
                                SEQUENCE_MAP_MACRO
                            }else{
                                auto func = [&lfSubserv](const double &x){ return x / lfSubserv; };
                                SEQUENCE_MAP_MACRO
                            }
                            delete seq;
                            seq = seqSubserv1;

                            std::cout << "Done." << std::endl;

                            break;

                        case '7':
                            
                            while(1){

                                std::cout << "For 'equal to' condition, enter 1." << std::endl;
                                std::cout << "For 'less than' condition, enter 2." << std::endl;
                                std::cout << "For 'greater than' condition, enter 3." << std::endl;
                                std::cout << "For 'at most' condition, enter 4." << std::endl;
                                std::cout << "For 'at least' condition, enter 5." << std::endl;
                                std::cout << "For 'not equal to' condition, enter 6." << std::endl;
                                std::cout << "For exit, enter any other symbol." << std::endl;

                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(enteredValue == '1' || enteredValue == '2' || enteredValue == '3' ||
                                    enteredValue == '4' || enteredValue == '5' || enteredValue == '6'){
                                    cSubserv = enteredValue;
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            while(1){

                                std::cout << "Enter a number the sequence values will be compared with, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }

                            if(cSubserv == '1'){
                                auto func = [&lfSubserv](const double &x){ return x == lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }else if(cSubserv == '2'){
                                auto func = [&lfSubserv](const double &x){ return x < lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }else if(cSubserv == '3'){
                                auto func = [&lfSubserv](const double &x){ return x > lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }else if(cSubserv == '2'){
                                auto func = [&lfSubserv](const double &x){ return x <= lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }else if(cSubserv == '3'){
                                auto func = [&lfSubserv](const double &x){ return x >= lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }else{
                                auto func = [&lfSubserv](const double &x){ return x != lfSubserv; };
                                SEQUENCE_WHERE_MACRO
                            }
                            delete seq;
                            seq = seqSubserv1;

                            std::cout << "Done." << std::endl;

                            break;

                        default:

                            std::cout << "Exit? [y/n]" << std::endl;

                            while(1){
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> enteredValue) break;
                                }
                            }

                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                subStopFlag = true;
                            }

                            break;

                    }

                }while(!subStopFlag);

                subStopFlag = false;

                break;

            case '3':

                if(!seq){
                    std::cout << "The sequence doesn't exist." << std::endl;
                    break;
                }

                do{

                    if(noHelpNotice) noHelpNotice = false;
                    else std::cout << "For help, enter 0." << std::endl;

                    while(1){
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredValue) break;
                        }
                    }

                    switch(enteredValue){
                        case '0':
                            std::cout << "To get the first value of the sequence, enter 1." << std::endl;
                            std::cout << "To get the last value of the sequence, enter 2." << std::endl;
                            std::cout << "To get the value at some position of the sequence, enter 3." << std::endl;
                            std::cout << "To get the size of the sequence, enter 4." << std::endl;
                            std::cout << "To get the sequence, enter 5." << std::endl;
                            std::cout << "To get the min, max, and avg of the sequence, enter 6." << std::endl;
                            std::cout << "To get the median of the sequence, enter 7." << std::endl;
                            std::cout << "To get the permutation quantity of the sequence, enter 8." << std::endl;
                            std::cout << "To get the lists of previous values of the sequence that are less than a current, enter 9." << std::endl;
                            std::cout << "To get the prefixes of the sequence, enter a." << std::endl;
                            std::cout << "To get the postfixes of the sequence, enter b." << std::endl;
                            std::cout << "To get the neighbour means of the sequence, enter c." << std::endl;
                            std::cout << "To get the quadratic means of the sequence without a current value, enter d." << std::endl;
                            std::cout << "To get the reflection sums of the sequence, enter e." << std::endl;
                            std::cout << "To exit, enter any other symbol." << std::endl;
                            noHelpNotice = true;
                            break;
                        case '1':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            std::cout << seq->GetFirst() << std::endl;
                            break;

                        case '2':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            std::cout << seq->GetLast() << std::endl;
                            break;

                        case '3':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            while(1){

                                std::cout << "Enter an index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredValue = 0;
                                while(1){
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        if(lineInput >> enteredValue) break;
                                    }
                                }

                                if(!enteredValue){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    while(1){
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> enteredValue) break;
                                        }
                                    }

                                    if(enteredValue == 'y') break;

                                }

                            }
                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                break;
                            }
                            if(sizeSubserv1 >= seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            std::cout << seq->Get(sizeSubserv1) << std::endl;
                            break;
                        
                        case '4':
                            std::cout << seq->GetCount() << std::endl;
                            break;
                        case '5':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < seq->GetCount() - 1; sizeSubserv1++){
                                std::cout << seq->Get(sizeSubserv1) << " ";
                            }
                            std::cout << seq->GetLast() << std::endl;

                            break;

                        case '6':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            SequenceMath::MinMaxAvgType<double> mma;
                            if(isArray){
                                if(isMutable){
                                    mma = SequenceMath::MinMaxAvg<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    mma = SequenceMath::MinMaxAvg<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    mma = SequenceMath::MinMaxAvg<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    mma = SequenceMath::MinMaxAvg<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << mma.min << " " << mma.max << " " << mma.avg << std::endl;
                            break;

                        case '7':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            double median;
                            if(isArray){
                                if(isMutable){
                                    median = SequenceMath::Median<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    median = SequenceMath::Median<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    median = SequenceMath::Median<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    median = SequenceMath::Median<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << median << std::endl;
                            break;

                        case '8':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            size_t permQuantity;
                            if(isArray){
                                if(isMutable){
                                    permQuantity = SequenceMath::PermutationQuantity
                                                <MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    permQuantity = SequenceMath::PermutationQuantity
                                                <ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    permQuantity = SequenceMath::PermutationQuantity
                                                <MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    permQuantity = SequenceMath::PermutationQuantity
                                                <ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << permQuantity << std::endl;
                            break;

                        case '9':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            Sequence<Sequence<double>*> *lessPrev;
                            if(isArray){
                                if(isMutable){
                                    lessPrev = SequenceMath::LessPrevious
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    lessPrev = SequenceMath::LessPrevious
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    lessPrev = SequenceMath::LessPrevious
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    lessPrev = SequenceMath::LessPrevious
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < lessPrev->GetCount(); sizeSubserv1++){

                                if(!(lessPrev->Get(sizeSubserv1)->GetCount())){
                                    std::cout << "The list is empty." << std::endl;
                                    continue;
                                }

                                for(sizeSubserv2 = 0; sizeSubserv2 < lessPrev->Get(sizeSubserv1)->GetCount() - 1;
                                            sizeSubserv2++){
                                    std::cout << lessPrev->Get(sizeSubserv1)->Get(sizeSubserv2) << " ";
                                }
                                std::cout << lessPrev->Get(sizeSubserv1)->GetLast() << std::endl;

                            }

                            break;

                        case 'a':
                        
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            Sequence<Sequence<double>*> *pref;
                            if(isArray){
                                if(isMutable){
                                    pref = SequenceMath::Prefixes
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    pref = SequenceMath::Prefixes
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    pref = SequenceMath::Prefixes
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    pref = SequenceMath::Prefixes
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < pref->GetCount(); sizeSubserv1++){
                                for(sizeSubserv2 = 0; sizeSubserv2 < pref->Get(sizeSubserv1)->GetCount() - 1;
                                            sizeSubserv2++){
                                    std::cout << pref->Get(sizeSubserv1)->Get(sizeSubserv2) << " ";
                                }
                                std::cout << pref->Get(sizeSubserv1)->GetLast() << std::endl;
                            }

                            break;

                        case 'b':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            Sequence<Sequence<double>*> *postf;
                            if(isArray){
                                if(isMutable){
                                    postf = SequenceMath::Postfixes
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    postf = SequenceMath::Postfixes
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    postf = SequenceMath::Postfixes
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    postf = SequenceMath::Postfixes
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < postf->GetCount(); sizeSubserv1++){
                                for(sizeSubserv2 = 0; sizeSubserv2 < postf->Get(sizeSubserv1)->GetCount() - 1;
                                            sizeSubserv2++){
                                    std::cout << postf->Get(sizeSubserv1)->Get(sizeSubserv2) << " ";
                                }
                                std::cout << postf->Get(sizeSubserv1)->GetLast() << std::endl;
                            }

                            break;

                        case 'c':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            Sequence<double> *neighb;
                            if(isArray){
                                if(isMutable){
                                    neighb = SequenceMath::NeighbourMeans<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    neighb = SequenceMath::NeighbourMeans<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    neighb = SequenceMath::NeighbourMeans<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    neighb = SequenceMath::NeighbourMeans<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < neighb->GetCount() - 1; sizeSubserv1++){
                                std::cout << neighb->Get(sizeSubserv1) << " ";
                            }
                            std::cout << neighb->GetLast() << std::endl;

                            break;

                        case 'd':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            Sequence<double> *quadr;
                            if(isArray){
                                if(isMutable){
                                    quadr = SequenceMath::QuadraticMeans<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    quadr = SequenceMath::QuadraticMeans<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    quadr = SequenceMath::QuadraticMeans<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    quadr = SequenceMath::QuadraticMeans<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < quadr->GetCount() - 1; sizeSubserv1++){
                                std::cout << quadr->Get(sizeSubserv1) << " ";
                            }
                            std::cout << quadr->GetLast() << std::endl;

                            break;

                        case 'e':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            Sequence<double> *refl;
                            if(isArray){
                                if(isMutable){
                                    refl = SequenceMath::ReflectionSums<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    refl = SequenceMath::ReflectionSums<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    refl = SequenceMath::ReflectionSums<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    refl = SequenceMath::ReflectionSums<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            for(sizeSubserv1 = 0; sizeSubserv1 < refl->GetCount() - 1; sizeSubserv1++){
                                std::cout << refl->Get(sizeSubserv1) << " ";
                            }
                            std::cout << refl->GetLast() << std::endl;

                            break;

                        default:
                            
                            std::cout << "Exit? [y/n]" << std::endl;

                            while(1){
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> enteredValue) break;
                                }
                            }

                            if(enteredValue == 'y'){
                                std::cout << "Exiting." << std::endl;
                                subStopFlag = true;
                            }

                            break;

                    }

                }while(!subStopFlag);

                subStopFlag = false;

                break;

            default:
                
                std::cout << "Exit? [y/n]" << std::endl;

                while(1){
                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                        lineInput.clear();
                        lineInput.str(enteredLine);
                        if(lineInput >> enteredValue) break;
                    }
                }

                if(enteredValue == 'y'){
                    std::cout << "Exiting." << std::endl;
                    stopFlag = true;
                }

                break;

        }
    }while(!stopFlag);

    delete seq;

    return 0;

}