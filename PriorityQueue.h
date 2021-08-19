//
// Created by AntonLvov on 08.06.2021.
//

#ifndef LAB_2_PRIORITYQUEUE_H
#define LAB_2_PRIORITYQUEUE_H

#endif //LAB_2_PRIORITYQUEUE_H
#include "Deque.h"

int randomInt() {
    return rand()%1000;
}

template<class T>
class QueueElement{
private:
    T data;
    int priority;
public:
    QueueElement(T item, int p){
        data = item;
        priority = p;
    }

    QueueElement(T item){
        data = item;
        priority = randomInt();
    }
};

template<class T>
class PriorityQueue {
private:
    Deque<QueueElement<T>> list;
public:
    PriorityQueue(QueueElement<T> *items, int count){
        list = Deque<QueueElement<T>>(items, count);
    }

    void Push(){
        list.PopRight();
    }
};