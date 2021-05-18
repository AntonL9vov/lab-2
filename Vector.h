//
// Created by AntonLvov on 04.05.2021.
//

#ifndef LAB_2_VECTOR_H
#define LAB_2_VECTOR_H

#endif //LAB_2_VECTOR_H
#include "ArraySequence.h"

template <class T>
class Vector{
private:
    int dimension;
    ArraySequence<T> arraySequence;
    size_t elementSize = sizeof(T);
public:
    Vector(){
    }

    Vector(Vector<T> &vector){
        arraySequence = ArraySequence<T>(vector.arraySequence);
        this->dimension = vector.arraySequence.GetLength();
    }

    Vector(const ArraySequence<T> &arraySequence1){
        arraySequence = ArraySequence<T>(arraySequence1);
        dimension = arraySequence.GetLength();
    }

    Vector(T *array, int dim){
        dimension = dim;
        arraySequence = ArraySequence<T>(array, dim);
    }

    Vector<T> *addVectors(Vector<T> vector){
        if(elementSize != vector.elementSize) return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if (dimension == vector.dimension || dimension>vector.dimension){
            a = new T[dimension];
            for (int i = 0; i < dimension; ++i) {
                a[i] = arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        }else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(vector.arraySequence.Get(i) + arraySequence.Get(i), i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *subVectors(Vector<T> vector){
        if(elementSize != vector.elementSize) return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if (dimension == vector.dimension || dimension>vector.dimension){
            a = new T[dimension];
            for (int i = 0; i < dimension; ++i) {
                a[i] = arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        }else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(arraySequence.Get(i) - vector.arraySequence.Get(i) , i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *multVectors(Vector<T> vector){
        if(elementSize != vector.elementSize) return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if (dimension == vector.dimension || dimension>vector.dimension){
            a = new T[dimension];
            for (int i = 0; i < dimension; ++i) {
                a[i] = arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        }else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(arraySequence.Get(i) * vector.arraySequence.Get(i) , i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *scalarMultVector(float  a){
        T *b = new T[dimension];
        ArraySequence<T> arraySequence1 = ArraySequence<T>(b, dimension);
        for (int i = 0; i < dimension; ++i) {
            arraySequence1.InsertAt(arraySequence.Get(i)*a, i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    friend std::ostream& operator<<(std::ostream &out, Vector &vector){
        out<<"{";
        for (int i = 0; i < vector.dimension - 1; ++i) {
            out<<vector.arraySequence.Get(i)<<", ";
        }
        out<<vector.arraySequence.Get(vector.dimension-1)<<"}"<<std::endl;
        return out;
    }

    int GetDimension(){
        return dimension;
    }

    T GetCoordinate(int i){
        if (i<1||i>dimension) throw IndexOutOfRange();
        return arraySequence.Get(i-1);
    }
};
