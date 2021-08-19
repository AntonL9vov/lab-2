//
// Created by AntonLvov on 08.06.2021.
//

#ifndef LAB_2_QUEUE_H
#define LAB_2_QUEUE_H

#endif //LAB_2_QUEUE_H
#include "Deque.h"

template <class T>
class Queue{
private:
    Deque<T> list;
public:
    Queue(T *items, int count){
        list = Deque<T>(items, count);
    }

    ~Queue(){
        delete &list;
    }

    T GetFirst(){
        return list.GetFirst();
    }

    void Push(T item){
        list.PushRight(item);
    }

    bool IsEmpty(){
        return list.IsEmpty();
    }

    T Pop(){
        return list.PopLeft();
    }
};