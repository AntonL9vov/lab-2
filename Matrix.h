//
// Created by AntonLvov on 07.05.2021.
//

#ifndef LAB_2_MATRIX_H
#define LAB_2_MATRIX_H

#endif //LAB_2_MATRIX_H
#include "ArraySequence.h"

template <class T>
class Matrix{
private:
    int length;
    int height;
    size_t elementSize = sizeof(T);
    ArraySequence<T> arraySequence;
public:
    Matrix(){}

    Matrix(T* array, int len, int hei){
        arraySequence = ArraySequence<T>(array, len*hei);
        length = len;
        height = hei;
    }

    Matrix(const ArraySequence<T> arraySequence1, int len, int hei){
        length = len;
        height = hei;
        arraySequence = arraySequence1;
    }

    Matrix<T> *sumMatrices(Matrix<T> matrix){
        if(elementSize!=matrix.elementSize) return nullptr;
        if(length!=matrix.length||height!=matrix.height) return nullptr;
        T *a = new T[length*height];
        for (int i = 0; i < length*height; ++i) {
            a[i] = arraySequence.Get(i) + matrix.arraySequence.Get(i);
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, length, height);
        return matrix1;
    }

    Matrix<T> *subMatrices(Matrix<T> matrix){
        if(elementSize!=matrix.elementSize) return nullptr;
        if(length!=matrix.length||height!=matrix.height) return nullptr;
        T *a = new T[length*height];
        for (int i = 0; i < length*height; ++i) {
            a[i] = arraySequence.Get(i) - matrix.arraySequence.Get(i);
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, length, height);
        return matrix1;
    }

    Matrix<T> *scalarMultMatrix(float b){
        T *a = new T[length*height];
        for (int i = 0; i < length*height; ++i) {
            a[i] = arraySequence.Get(i)*b;
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, length, height);
        return matrix1;
    }

    Matrix<T> *multMatrices(Matrix<T> matrix){
        if(elementSize!=matrix.elementSize) return nullptr;
        if(height!=matrix.length) return nullptr;
        T *a = new T[matrix.length*height];
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < matrix.height; ++j) {
                a[i*matrix.length + j] = 0;
                for (int k = 0; k < height; ++k) {
                    a[i*matrix.length + j] = a[i*matrix.length + j] + arraySequence.Get(i*length + k) * matrix.arraySequence.Get(k*matrix.length + j);
                }
            }
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, matrix.length, height);
        return matrix1;
    }

    void changeLines(int first, int second){
        if(first<1||first>height||second<1||second>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.changeElements((first-1)*length + i, (second-1)*length + i);
        }
    }

    void multLine(int line, float a){
        if(line<1||line>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.InsertAt(arraySequence.Get((line-1)*length+i)*a, (line-1)*length+i);
        }
    }

    void addToLine(int line, float a){
        if(line<1||line>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.InsertAt(arraySequence.Get((line-1)*length+i)+a, (line-1)*length+i);
        }
    }

    void print(){
        std::cout<<""<<std::endl;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < length; ++j) {
                std::cout<<arraySequence.Get(i*length + j)<<" ";
            }
            std::cout<<""<<std::endl;
        }
    }
};