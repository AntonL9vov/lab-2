//
// Created by AntonLvov on 08.06.2021.
//

#ifndef LAB_2_STACK_H
#define LAB_2_STACK_H

#endif //LAB_2_STACK_H

#include "Deque.h"

template <class T>
class Stack{
private:
    Deque<T> list;
public:
    Stack(T *items, int count){
        list = Deque<T>(items, count);
    }

    ~Stack(){
        delete &list;
    }

    void Push(T item){
        list.PushLeft(item);
    }

    T Pop(){
        return list.PopLeft();
    }
};