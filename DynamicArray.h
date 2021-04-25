//
// Created by AntonLvov on 22.04.2021.
//

#ifndef LAB_2_DYNAMICARRAY_H
#define LAB_2_DYNAMICARRAY_H

#include <string>
#include <iostream>
#include "cstring"


template <class T>
class DynamicArray {
private:
    T *array;
    int length;
    size_t sizeOfElement = sizeof(T);
public:
    DynamicArray(T* items, int count) {
        length = 0;
        if(count>0){
            array = (T *) malloc(count*sizeOfElement);
            for(; length<count; length++){
                array[length] = items[length];
            }
        }
    }

    DynamicArray(int size) {
        length = size;
        array = (T *) malloc(size*sizeOfElement);
        for(int i = 0; i<size; i++) array[i] = 0;
    }

    DynamicArray(const DynamicArray<T> &dynamicArray ) {
        length = 0;
        array = (T *) malloc(dynamicArray.length*sizeOfElement);
        for(; length<dynamicArray.length; length++){
            array[length] = dynamicArray.array[length];
        }
    }

    ~DynamicArray(){
    }

    T Get(int index) {

    }

    int GetSize() {

    }

    void Set(int index, T value) {

    }

    void Resize(int newSize){

    }

    void Print() {
        for(int i = 0; i<length; i++){
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //LAB_2_DYNAMICARRAY_H
