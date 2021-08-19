//
// Created by AntonLvov on 08.06.2021.
//

#ifndef LAB_2_DEQUE_H
#define LAB_2_DEQUE_H

#endif //LAB_2_DEQUE_H

#include "ListSequence.h"

template <class T>
class Deque{
private:
    LinkedListSequence<T> linkedListSequence;

    void DeleteElement(int i){
        Element<T> *element = linkedListSequence.GetElement(i);
        element->next->prev = element->prev;
        element->prev->next = element->next;
        delete element;
    }
public:
    Deque(T* items, int count){
        linkedListSequence = LinkedListSequence<T>(items, count);
    }

    ~Deque(){
        delete &linkedListSequence;
    }

    void PushLeft(T item){
        linkedListSequence.Prepend(item);
    }

    void PushRight(T item){
        linkedListSequence.Append(item);
    }

    T GetLast(){
        return linkedListSequence.GetLast();
    }

    T GetFirst(){
        return linkedListSequence.GetFirst();
    }

    T PopLeft(){
        T data = GetFirst();
        DeleteElement(0);
        return data;
    }

    T PopRight(){
        T data = GetLast();
        DeleteElement(linkedListSequence.GetLength());
        return data;
    }

    int GetLength(){
        return linkedListSequence.GetLength();
    }

    bool IsEmpty(){
        if (!GetLength())
            return false;
        return true;
    }
};