//
// Created by AntonLvov on 26.04.2021.
//

#ifndef LAB_2_LINKEDLIST_H
#define LAB_2_LINKEDLIST_H

#endif //LAB_2_LINKEDLIST_H
#include "IndexOutOfRangeException.h"
#include <iostream>

template <class T>
class LinkedList{
private:
    typedef struct Element {
        T data;
        struct Element *next;
    } element;

    int len = 0;

    element *head = nullptr;
    element *end = nullptr;
public:
    void Prepend(T item){
        element *element1 = new element;
        element1->data = item;
        element1->next = nullptr;
        len++;
        if (head == nullptr){
            head = element1;
            end = element1;
            return;
        }
        element1->next = head;
        head = element1;
    }

    void Append(T item){
       element *element1 = new element;
       element1->data = item;
       element1->next = nullptr;

       len++;

        if (head == nullptr){
            head = element1;
            end = element1;
            return;
        }

        end->next = element1;
        end = element1;
    }

    LinkedList (T* items, int count){
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }

    LinkedList (){
    }

    LinkedList (const LinkedList <T> & list){
        element *element1 = list.head;
        for (int i = 0; i < list.len; ++i) {
            Append(element1->data);
            element1 = element1->next;
        }
    }

    T GetFirst(){
        if(head == nullptr) throw IndexOutOfRange();
        return head->data;
    }

    T GetLast(){
        if(head == nullptr) throw IndexOutOfRange();
        return end->data;
    }

    T Get(int index){
        if(head == nullptr) throw IndexOutOfRange();
        if (index>len-1||index<0) throw IndexOutOfRange();
        element *element1 = new element;
        element1 = head;
        for (int i = 0; i < index; ++i) {
            element1 = element1->next;
        }
        return element1->data;
    }

    LinkedList<T> *GetSubList(int startIndex, int endIndex){
        if(head == nullptr) throw IndexOutOfRange();
        if (endIndex>len-1||startIndex>len-1||startIndex<0||endIndex<0||startIndex==endIndex) throw IndexOutOfRange();
        if(startIndex>endIndex){
            int a = startIndex;
            startIndex = endIndex;
            endIndex = a;
        }
        element *element1 = new element;
        element1 = head;
        for (int i = 0; i < startIndex; ++i) {
            element1 = element1->next;
        }
        LinkedList<T> *list = new LinkedList<T>;
        for (int i = 0; i < endIndex-startIndex; ++i) {
            list->Append(element1->data);
            element1 = element1->next;
        }
        list->end = element1;
        return list;
    }

    int GetLength(){
        return len;
    }

    void InsertAt(T item, int index){
        if(head == nullptr) throw IndexOutOfRange();
        if (index>len-1||index<0) throw IndexOutOfRange();
        element *element1 = new element;
        element1 = head;
        for (int i = 0; i < index; ++i) {
            element1 = element1->next;
        }
        element *element2 = new element;
        element2->data = item;
        element2->next = element1->next->next;
        element1->next = element2;
    }

    LinkedList<T>* Concat(LinkedList<T> *list){
        LinkedList<T> *linkedList = new LinkedList<T>;
        linkedList->head = head;
        linkedList->end = end;
        linkedList->end->next = list->head;
        linkedList->end = list->end;
        len = len + list->len;
        return linkedList;
    }

    std::ostream &operator <<()
};