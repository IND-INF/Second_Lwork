#include "List_sequence/immutable_list_sequence.h"
#include "List_sequence/mutable_list_sequence.h"
#include "Array_sequence/immutable_array_sequence.h"
#include "Array_sequence/mutable_array_sequence.h"
#include "sequence_math.h"
#include "sequence_test.h"
#include <iostream>
#include <sstream>

#define SEQUENCE_MAP_MACRO                                                      \
do{                                                                             \
    if(isArray){                                                                \
        if(isMutable){                                                          \
            seqSubserv1 = (static_cast<MutableArraySequence<double>*>(seq))->   \
                        Map<double,MutableArraySequence<double>>(func);         \
        }else{                                                                  \
            seqSubserv1 = (static_cast<ImmutableArraySequence<double>*>(seq))-> \
                        Map<double,ImmutableArraySequence<double>>(func);       \
        }                                                                       \
    }else{                                                                      \
        if(isMutable){                                                          \
            seqSubserv1 = (static_cast<MutableListSequence<double>*>(seq))->    \
                        Map<double,MutableListSequence<double>>(func);          \
        }else{                                                                  \
            seqSubserv1 = (static_cast<ImmutableListSequence<double>*>(seq))->  \
                        Map<double,ImmutableListSequence<double>>(func);        \
        }                                                                       \
    }                                                                           \
}while(0);

#define SEQUENCE_WHERE_MACRO                                                                \
do{                                                                                         \
    if(isArray){                                                                            \
        if(isMutable){                                                                      \
            seqSubserv1 = (static_cast<MutableArraySequence<double>*>(seq))->Where(func);   \
        }else{                                                                              \
            seqSubserv1 = (static_cast<ImmutableArraySequence<double>*>(seq))->Where(func); \
        }                                                                                   \
    }else{                                                                                  \
        if(isMutable){                                                                      \
            seqSubserv1 = (static_cast<MutableListSequence<double>*>(seq))->Where(func);    \
        }else{                                                                              \
            seqSubserv1 = (static_cast<ImmutableListSequence<double>*>(seq))->Where(func);  \
        }                                                                                   \
    }                                                                                       \
}while(0);

#define SEQUENCE_REDUCE_MACRO                                                                               \
do{                                                                                                         \
    if(isArray){                                                                                            \
        if(isMutable){                                                                                      \
            lfSubserv = (static_cast<MutableArraySequence<double>*>(seq))->Reduce<double>(func, initial);   \
        }else{                                                                                              \
            lfSubserv = (static_cast<ImmutableArraySequence<double>*>(seq))->Reduce<double>(func, initial); \
        }                                                                                                   \
    }else{                                                                                                  \
        if(isMutable){                                                                                      \
            lfSubserv = (static_cast<MutableListSequence<double>*>(seq))->Reduce<double>(func, initial);    \
        }else{                                                                                              \
            lfSubserv = (static_cast<ImmutableListSequence<double>*>(seq))->Reduce<double>(func, initial);  \
        }                                                                                                   \
    }                                                                                                       \
}while(0);

int main(){

    DoTest();

    bool stopFlag = false;
    bool subStopFlag = false;
    bool noHelpNotice = false;

    std::string enteredLine;
    std::istringstream lineInput;
    char enteredChar = 0;
    char yesNoChar = 0;
    double *items = nullptr;

    double lfSubserv;
    std::size_t sizeSubserv1;
    std::size_t sizeSubserv2;
    char cSubserv;
    SequenceMath::MinMaxAvgType<double> minMaxAvgSubserv;

    bool isArray = false;
    bool isMutable = false;

    bool newIsArray = false;
    bool newIsMutable = false;

    Sequence<double> *seq = nullptr;
    Sequence<double> *seqSubserv1;
    Sequence<double> *seqSubserv2;
    IEnumerable<double>::IEnumerator *enumSubserv;
    Sequence<Sequence<double>*> *seqOfSeqsSubserv;
    IEnumerable<Sequence<double>*>::IEnumerator *enumOfSeqsSubserv;

    do{

        if(noHelpNotice) noHelpNotice = false;
        else std::cout << "For help, enter 0." << std::endl;

        do{
            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                lineInput.clear();
                lineInput.str(enteredLine);
                if(lineInput >> enteredChar) break;
            }
        }while(1);

        switch(enteredChar){
            case '0':
                std::cout << "For sequence creation, enter 1.\n";
                std::cout << "For sequence modification, enter 2.\n";
                std::cout << "For output, enter 3.\n";
                std::cout << "For exit from the program, enter any other symbol." << std::endl;
                noHelpNotice = true;
                break;
            case '1':

                do{                                                                             
                                                                                
                    std::cout << "For a list sequence, enter 0.\n";
                    std::cout << "For an array sequence, enter 1.\n";
                    std::cout << "For exit, enter any other symbol." << std::endl;                                         
                                                                                                
                    do{                                                                         
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){        
                            lineInput.clear();                                                  
                            lineInput.str(enteredLine);                                         
                            if(lineInput >> enteredChar) break;                                 
                        }                                                                       
                    }while(1);                                                                  
                                                                                                
                    if(enteredChar == '0'){
                        newIsArray = false;                                                          
                        break;                                                                  
                    }else if(enteredChar == '1'){
                        newIsArray = true;
                        break;
                    }else{                                                                      
                                                                                                
                        std::cout << "Exit? [y/n]" << std::endl;                                
                                                                                               
                        do{                                                                     
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){    
                                lineInput.clear();                                              
                                lineInput.str(enteredLine);                                     
                                if(lineInput >> yesNoChar) break;                         
                            }                                                                   
                        }while(1);                                                              
                                                                                                
                        if(yesNoChar == 'y') break;                                       
                                                                                                
                    }                                                                           
                                                                                                
                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                do{                                                                             
                                                                                
                    std::cout << "For an immutable sequence, enter 0.\n";
                    std::cout << "For a mutable sequence, enter 1.\n";
                    std::cout << "For exit, enter any other symbol." << std::endl;                                         
                                                                                                
                    do{                                                                         
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){        
                            lineInput.clear();                                                  
                            lineInput.str(enteredLine);                                         
                            if(lineInput >> enteredChar) break;                                 
                        }                                                                       
                    }while(1);                                                                  
                                                                                                
                    if(enteredChar == '0'){
                        newIsMutable = false;                                                          
                        break;                                                                  
                    }else if(enteredChar == '1'){
                        newIsMutable = true;
                        break;
                    }else{                                                                      
                                                                                                
                        std::cout << "Exit? [y/n]" << std::endl;                                
                                                                                                
                        do{                                                                     
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){    
                                lineInput.clear();                                              
                                lineInput.str(enteredLine);                                     
                                if(lineInput >> yesNoChar) break;                         
                            }                                                                   
                        }while(1);                                                              
                                                                                                
                        if(yesNoChar == 'y') break;                                       
                                                                                                
                    }                                                                           
                                                                                                
                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                do{

                    std::cout << "Enter a size of the sequence, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> sizeSubserv1) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{

                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                if(sizeSubserv1 > 0){

                    std::cout << "Enter items of the sequence, or enter a nonnumeric symbol to exit." << std::endl;

                    items = new double[sizeSubserv1];
                    sizeSubserv2 = 0;
                    do{

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                break;
                            }
                        }while(1);

                        enteredChar = 0;
                        while(sizeSubserv2 < sizeSubserv1){
                            if(!(lineInput >> items[sizeSubserv2])){
                                lineInput.clear();
                                lineInput >> enteredChar;
                                break;
                            }
                            sizeSubserv2++;
                        }

                        if(!(sizeSubserv2 < sizeSubserv1)){
                            break;
                        }
                        if(enteredChar){
                                
                            std::cout << "Exit? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y') break;
                            else std::cout << "Continue entering." << std::endl;

                        }

                    }while(1);
                    if(yesNoChar == 'y'){

                        delete []items;
                        items = nullptr;

                        std::cout << "Exiting." << std::endl;
                        yesNoChar = 0;
                        break;

                    }

                }

                if(seq) delete seq;

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
                items = nullptr;

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

                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    switch(enteredChar){
                        case '0':
                            std::cout << "To get a subsequence of the sequence, enter 1.\n";
                            std::cout << "To append a value to the sequence, enter 2.\n";
                            std::cout << "To prepend a value to the sequence, enter 3.\n";
                            std::cout << "To insert a value at some position of the sequence, enter 4.\n";
                            std::cout << "To concatenate the sequence with another one, enter 5.\n";
                            std::cout << "To subject the sequence to a map, enter 6.\n";
                            std::cout << "To select the sequence values by a condition, enter 7.\n";
                            std::cout << "To exit, enter any other symbol." << std::endl;
                            noHelpNotice = true;
                            break;
                        case '1':

                            do{

                                std::cout << "Enter a start index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }
                            if(sizeSubserv1 >= seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            do{

                                std::cout << "Enter a final index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv2) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }
                            if(sizeSubserv2 > seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            seqSubserv1 = seq->GetSubsequence(sizeSubserv1, sizeSubserv2);

                            std::cout << "The new sequence is:\n";
                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete seq;
                                seq = seqSubserv1;

                                std::cout << "Done." << std::endl;

                            }

                            break;

                        case '2':
                            
                            do{

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            if(isMutable){
                                seq->Append(lfSubserv);
                                std::cout << "Done." << std::endl;
                            }else{
                                
                                seqSubserv1 = seq->Append(lfSubserv);

                                std::cout << "The new sequence is:\n";
                                enumSubserv = seqSubserv1->GetEnumerator();
                                while(enumSubserv->HasNext()){
                                    std::cout << enumSubserv->Current() << " ";
                                    enumSubserv->MoveNext();
                                }
                                std::cout << enumSubserv->Current() << std::endl;
                                delete enumSubserv;
                                
                                std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> yesNoChar) break;
                                    }
                                }while(1);

                                if(yesNoChar == 'y'){

                                    yesNoChar = 0;

                                    delete seq;
                                    seq = seqSubserv1;

                                    std::cout << "Done." << std::endl;
                                    
                                }

                            }

                            break;
                        
                        case '3':

                            do{

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            if(isMutable){
                                seq->Prepend(lfSubserv);
                                std::cout << "Done." << std::endl;
                            }else{
                                
                                seqSubserv1 = seq->Prepend(lfSubserv);

                                std::cout << "The new sequence is:\n";
                                enumSubserv = seqSubserv1->GetEnumerator();
                                while(enumSubserv->HasNext()){
                                    std::cout << enumSubserv->Current() << " ";
                                    enumSubserv->MoveNext();
                                }
                                std::cout << enumSubserv->Current() << std::endl;
                                delete enumSubserv;
                                
                                std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> yesNoChar) break;
                                    }
                                }while(1);

                                if(yesNoChar == 'y'){

                                    yesNoChar = 0;

                                    delete seq;
                                    seq = seqSubserv1;

                                    std::cout << "Done." << std::endl;
                                    
                                }

                            }

                            break;

                        case '4':

                            do{

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            do{

                                std::cout << "Enter an index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }
                            if(sizeSubserv1 > seq->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            if(isMutable){
                                seq->InsertAt(lfSubserv, sizeSubserv1);
                                std::cout << "Done." << std::endl;
                            }else{
                                
                                seqSubserv1 = seq->InsertAt(lfSubserv, sizeSubserv1);

                                std::cout << "The new sequence is:\n";
                                enumSubserv = seqSubserv1->GetEnumerator();
                                while(enumSubserv->HasNext()){
                                    std::cout << enumSubserv->Current() << " ";
                                    enumSubserv->MoveNext();
                                }
                                std::cout << enumSubserv->Current() << std::endl;
                                delete enumSubserv;
                                
                                std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> yesNoChar) break;
                                    }
                                }while(1);

                                if(yesNoChar == 'y'){

                                    yesNoChar = 0;

                                    delete seq;
                                    seq = seqSubserv1;

                                    std::cout << "Done." << std::endl;
                                    
                                }

                            }

                            break;

                        case '5':
                            
                            do{

                                std::cout << "Enter a size of the other sequence, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            if(sizeSubserv1 > 0){

                                std::cout << "Enter items of the other sequence, or enter a nonnumeric symbol to exit." << std::endl;

                                items = new double[sizeSubserv1];
                                sizeSubserv2 = 0;
                                do{

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            break;
                                        }
                                    }while(1);

                                    enteredChar = 0;
                                    while(sizeSubserv2 < sizeSubserv1){
                                        if(!(lineInput >> items[sizeSubserv2])){
                                            lineInput.clear();
                                            lineInput >> enteredChar;
                                            break;
                                        }
                                        sizeSubserv2++;
                                    }

                                    if(!(sizeSubserv2 < sizeSubserv1)){
                                        break;
                                    }
                                    if(enteredChar){
                                            
                                        std::cout << "Exit? [y/n]" << std::endl;

                                        do{
                                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                                lineInput.clear();
                                                lineInput.str(enteredLine);
                                                if(lineInput >> yesNoChar) break;
                                            }
                                        }while(1);

                                        if(yesNoChar == 'y') break;
                                        else std::cout << "Continue entering." << std::endl;

                                    }

                                }while(1);
                                if(yesNoChar == 'y'){

                                    delete []items;
                                    items = nullptr;

                                    std::cout << "Exiting." << std::endl;
                                    yesNoChar = 0;
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
                            items = nullptr;

                            seqSubserv1 = seq->Concat(seqSubserv2);
                            delete seqSubserv2;

                            std::cout << "The new sequence is:\n";
                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete seq;
                                seq = seqSubserv1;

                                std::cout << "Done." << std::endl;
                                
                            }

                            break;

                        case '6':
                            
                            do{

                                std::cout << "For addition, enter 1.\n";
                                std::cout << "For subtraction, enter 2.\n";
                                std::cout << "For multiplication, enter 3.\n";
                                std::cout << "For division, enter 4.\n";
                                std::cout << "For exit, enter any other symbol." << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(enteredChar == '1' || enteredChar == '2' || enteredChar == '3' || enteredChar == '4'){
                                    cSubserv = enteredChar;
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            do{

                                if(cSubserv == '1'){
                                    std::cout << "Enter a summand, or enter a nonnumeric symbol to exit." << std::endl;
                                }else if(cSubserv == '2'){
                                    std::cout << "Enter a subtrahend, or enter a nonnumeric symbol to exit." << std::endl;
                                }else if(cSubserv == '3'){
                                    std::cout << "Enter a multiplier, or enter a nonnumeric symbol to exit." << std::endl;
                                }else{
                                    std::cout << "Enter a divisor, or enter a nonnumeric symbol to exit." << std::endl;
                                }

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
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

                            std::cout << "The new sequence is:\n";
                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete seq;
                                seq = seqSubserv1;

                                std::cout << "Done." << std::endl;
                                
                            }

                            break;

                        case '7':
                            
                            do{

                                std::cout << "For 'equal to' condition, enter 1.\n";
                                std::cout << "For 'less than' condition, enter 2.\n";
                                std::cout << "For 'greater than' condition, enter 3.\n";
                                std::cout << "For 'at most' condition, enter 4.\n";
                                std::cout << "For 'at least' condition, enter 5.\n";
                                std::cout << "For 'not equal to' condition, enter 6.\n";
                                std::cout << "For exit, enter any other symbol." << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(enteredChar == '1' || enteredChar == '2' || enteredChar == '3' ||
                                    enteredChar == '4' || enteredChar == '5' || enteredChar == '6'){
                                    cSubserv = enteredChar;
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            do{

                                std::cout << "Enter a number the sequence values will be compared with, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
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

                            std::cout << "The new sequence is:\n";
                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current sequence to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete seq;
                                seq = seqSubserv1;

                                std::cout << "Done." << std::endl;
                                
                            }

                            break;

                        default:

                            std::cout << "Exit? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
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

                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    switch(enteredChar){
                        case '0':
                            std::cout << "To get the first value of the sequence, enter 1.\n";
                            std::cout << "To get the last value of the sequence, enter 2.\n";
                            std::cout << "To get the value at some position of the sequence, enter 3.\n";
                            std::cout << "To get the size of the sequence, enter 4.\n";
                            std::cout << "To get the sequence, enter 5.\n";
                            std::cout << "To get the min, max, and avg of the sequence, enter 6.\n";
                            std::cout << "To get the median of the sequence, enter 7.\n";
                            std::cout << "To get the permutation quantity of the sequence, enter 8.\n";
                            std::cout << "To get the lists of previous values of the sequence that are less than a current, enter 9.\n";
                            std::cout << "To get the prefixes of the sequence, enter a.\n";
                            std::cout << "To get the postfixes of the sequence, enter b.\n";
                            std::cout << "To get the neighbour means of the sequence, enter c.\n";
                            std::cout << "To get the quadratic means of the sequence without a current value, enter d.\n";
                            std::cout << "To get the reflection sums of the sequence, enter e.\n";
                            std::cout << "To reduce the sequence with some function, enter f.\n";
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

                            do{

                                std::cout << "Enter an index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
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

                            enumSubserv = seq->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;

                            break;

                        case '6':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    minMaxAvgSubserv = SequenceMath::MinMaxAvg<MutableArraySequence<double>,
                                                double>(*(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    minMaxAvgSubserv = SequenceMath::MinMaxAvg<ImmutableArraySequence<double>,
                                                double>(*(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    minMaxAvgSubserv = SequenceMath::MinMaxAvg<MutableListSequence<double>,
                                                double>(*(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    minMaxAvgSubserv = SequenceMath::MinMaxAvg<ImmutableListSequence<double>,
                                                double>(*(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << minMaxAvgSubserv.min << " ";
                            std::cout << minMaxAvgSubserv.max << " ";
                            std::cout << minMaxAvgSubserv.avg << std::endl;
                            break;

                        case '7':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    lfSubserv = SequenceMath::Median<MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    lfSubserv = SequenceMath::Median<ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    lfSubserv = SequenceMath::Median<MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    lfSubserv = SequenceMath::Median<ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << lfSubserv << std::endl;
                            break;

                        case '8':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    sizeSubserv1 = SequenceMath::PermutationQuantity
                                                <MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    sizeSubserv1 = SequenceMath::PermutationQuantity
                                                <ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    sizeSubserv1 = SequenceMath::PermutationQuantity
                                                <MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    sizeSubserv1 = SequenceMath::PermutationQuantity
                                                <ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            std::cout << sizeSubserv1 << std::endl;
                            break;

                        case '9':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            if(isArray){
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::LessPrevious
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::LessPrevious
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::LessPrevious
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::LessPrevious
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumOfSeqsSubserv = seqOfSeqsSubserv->GetEnumerator();
                            do{

                                if(!(enumOfSeqsSubserv->Current()->GetCount())){
                                    std::cout << "The list is empty." << std::endl;
                                }else{
                                    enumSubserv = enumOfSeqsSubserv->Current()->GetEnumerator();
                                    while(enumSubserv->HasNext()){
                                        std::cout << enumSubserv->Current() << " ";
                                        enumSubserv->MoveNext();
                                    }
                                    std::cout << enumSubserv->Current() << std::endl;
                                    delete enumSubserv;
                                }

                                delete enumOfSeqsSubserv->Current();

                            }while(enumOfSeqsSubserv->MoveNext());
                            delete enumOfSeqsSubserv;

                            delete seqOfSeqsSubserv;

                            break;

                        case 'a':
                        
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            if(isArray){
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::Prefixes
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::Prefixes
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::Prefixes
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::Prefixes
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumOfSeqsSubserv = seqOfSeqsSubserv->GetEnumerator();
                            do{

                                if(!(enumOfSeqsSubserv->Current()->GetCount())){
                                    std::cout << "The list is empty." << std::endl;
                                }else{
                                    enumSubserv = enumOfSeqsSubserv->Current()->GetEnumerator();
                                    while(enumSubserv->HasNext()){
                                        std::cout << enumSubserv->Current() << " ";
                                        enumSubserv->MoveNext();
                                    }
                                    std::cout << enumSubserv->Current() << std::endl;
                                    delete enumSubserv;
                                }

                                delete enumOfSeqsSubserv->Current();

                            }while(enumOfSeqsSubserv->MoveNext());
                            delete enumOfSeqsSubserv;

                            delete seqOfSeqsSubserv;

                            break;

                        case 'b':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }
                            
                            if(isArray){
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::Postfixes
                                                <MutableArraySequence<Sequence<double>*>,
                                                MutableArraySequence<double>,double>(
                                                *(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::Postfixes
                                                <ImmutableArraySequence<Sequence<double>*>,
                                                ImmutableArraySequence<double>,double>(
                                                *(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqOfSeqsSubserv = SequenceMath::Postfixes
                                                <MutableListSequence<Sequence<double>*>,
                                                MutableListSequence<double>,double>(
                                                *(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqOfSeqsSubserv = SequenceMath::Postfixes
                                                <ImmutableListSequence<Sequence<double>*>,
                                                ImmutableListSequence<double>,double>(
                                                *(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumOfSeqsSubserv = seqOfSeqsSubserv->GetEnumerator();
                            do{

                                if(!(enumOfSeqsSubserv->Current()->GetCount())){
                                    std::cout << "The list is empty." << std::endl;
                                }else{
                                    enumSubserv = enumOfSeqsSubserv->Current()->GetEnumerator();
                                    while(enumSubserv->HasNext()){
                                        std::cout << enumSubserv->Current() << " ";
                                        enumSubserv->MoveNext();
                                    }
                                    std::cout << enumSubserv->Current() << std::endl;
                                    delete enumSubserv;
                                }

                                delete enumOfSeqsSubserv->Current();

                            }while(enumOfSeqsSubserv->MoveNext());
                            delete enumOfSeqsSubserv;

                            delete seqOfSeqsSubserv;

                            break;

                        case 'c':

                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::NeighbourMeans<MutableArraySequence<double>,
                                                double>(*(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::NeighbourMeans<ImmutableArraySequence<double>,
                                                double>(*(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::NeighbourMeans<MutableListSequence<double>,
                                                double>(*(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::NeighbourMeans<ImmutableListSequence<double>,
                                                double>(*(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;

                            delete seqSubserv1;

                            break;

                        case 'd':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::QuadraticMeans<MutableArraySequence<double>,
                                                double>(*(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::QuadraticMeans<ImmutableArraySequence<double>,
                                                double>(*(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::QuadraticMeans<MutableListSequence<double>,
                                                double>(*(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::QuadraticMeans<ImmutableListSequence<double>,
                                                double>(*(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;

                            delete seqSubserv1;

                            break;

                        case 'e':
                            
                            if(!(seq->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            if(isArray){
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::ReflectionSums<MutableArraySequence<double>,
                                                double>(*(static_cast<MutableArraySequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::ReflectionSums<ImmutableArraySequence<double>,
                                                double>(*(static_cast<ImmutableArraySequence<double>*>(seq)));
                                }
                            }else{
                                if(isMutable){
                                    seqSubserv1 = SequenceMath::ReflectionSums<MutableListSequence<double>,
                                                double>(*(static_cast<MutableListSequence<double>*>(seq)));
                                }else{
                                    seqSubserv1 = SequenceMath::ReflectionSums<ImmutableListSequence<double>,
                                                double>(*(static_cast<ImmutableListSequence<double>*>(seq)));
                                }
                            }

                            enumSubserv = seqSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;

                            delete seqSubserv1;

                            break;

                        case 'f':
                            
                            do{

                                std::cout << "For addition, enter 1.\n";
                                std::cout << "For multiplication, enter 2.\n";
                                std::cout << "For exit, enter any other symbol." << std::endl;

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(enteredChar == '1' || enteredChar == '2'){
                                    cSubserv = enteredChar;
                                    break;
                                }else{

                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            if(cSubserv == '1'){
                                auto func = [](const double &init, const double &x){ return x + init; };
                                double initial = 0;
                                SEQUENCE_REDUCE_MACRO
                            }else{
                                auto func = [](const double &init, const double &x){ return x * init; };
                                double initial = 1;
                                SEQUENCE_REDUCE_MACRO
                            }
                            std::cout << lfSubserv << std::endl;

                            break;

                        default:
                            
                            std::cout << "Exit? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                subStopFlag = true;
                            }

                            break;

                    }

                }while(!subStopFlag);

                subStopFlag = false;

                break;

            default:
                
                std::cout << "Exit? [y/n]" << std::endl;

                do{
                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                        lineInput.clear();
                        lineInput.str(enteredLine);
                        if(lineInput >> yesNoChar) break;
                    }
                }while(1);

                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    stopFlag = true;
                }

                break;

        }
    }while(!stopFlag);

    delete seq;

    return 0;

}