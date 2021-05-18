//
// Created by AntonLvov on 17.05.2021.
//

#ifndef LAB_2_TEST_H
#define LAB_2_TEST_H

#endif //LAB_2_TEST_H

#include "LinkedList.h"
#include "menu.h"

using namespace std;

void isAllRight(bool a){
    if(a){
        cout<<"Test passed successfully."<<endl;
    } else{
        cout<<"Something went wrong"<<endl;
    }
}

void dynamicArrTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> dynamicArray = DynamicArray<int>(a, 10);
    for (int i = 0; i < 10; ++i) {
        if (dynamicArray.Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void dynamicArrayTestGetLength(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> dynamicArray = DynamicArray<int>(a, 10);
    if (dynamicArray.GetLength() != 10) m = false;
    isAllRight(m);
}

void dynamicArrTestSet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> dynamicArray = DynamicArray<int>(a, 10);
    for (int i = 10; i > 0; --i) {
        dynamicArray.Set(i, i);
    }
    for (int i = 10; i > 0; --i) {
        if (dynamicArray.Get(i) != i) m = false;
    }
    isAllRight(m);
}

void dynamicArrTestResize(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> dynamicArray = DynamicArray<int>(a, 10);
    dynamicArray.Resize(5);
    if (dynamicArray.GetLength() != 5) m = false;
    for (int i = 0; i < 5; ++i) {
        if (dynamicArray.Get(i) != i+1) m = false;
    }
    dynamicArray.Resize(10);
    if (dynamicArray.GetLength() != 10) m = false;
    for (int i; i < 5; ++i) {
        if (dynamicArray.Get(i) != i+1) m = false;
    }
    for (int i = 0; i < 5; ++i) {
        if (dynamicArray.Get(i+5) != i+1) m = false;
    }
    isAllRight(m);
}

void dynamicArrTests(){
    dynamicArrTestGet();
    dynamicArrTestResize();
    dynamicArrayTestGetLength();
    dynamicArrTestSet();
}

void linkedListTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    for (int i = 0; i < 10; ++i) {
        if(linkedList.Get(i)!=i+1) m = false;
    }
    isAllRight(m);
}

void linkedListTestGetFirst(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if (linkedList.GetFirst() != 1) m = false;
    isAllRight(m);
}

void linkedListTestGetLast(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if (linkedList.GetLast() != 10) m = false;
    isAllRight(m);
}

void linkedListTestGetLength(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if(linkedList.GetLength()!=10) m = false;
    isAllRight(m);
}

void linkedListTestGetSubList(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    LinkedList<int> *linkedList1 = linkedList.GetSubList(2,8);
    if (linkedList1->GetLength()!= 6) m = false;
    for (int i = 0; i < 6; ++i) {
        if(linkedList1->Get(i)!=i+3) m = false;
    }
    isAllRight(m);
}

void linkedListTestInsertAt(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    linkedList.InsertAt(8, 5);
    if(linkedList.Get(6) != 8) m = false;
    isAllRight(m);
}

void linkedListTests(){
    linkedListTestGetLength();
    linkedListTestGet();
    linkedListTestGetFirst();
    linkedListTestGetSubList();
    linkedListTestGetLast();
    linkedListTestInsertAt();
}

void arraySequenceTestGetFirst(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    if(arraySequence.GetFirst()!=1) m = false;
    isAllRight(m);
}

void arraySequenceTestGetLast(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    if(arraySequence.GetFirst()!=10) m = false;
    isAllRight(m);
}

void arraySequenceTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    for (int i = 0; i < 10; ++i) {
        if(arraySequence.Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestGetSubSequence(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    ArraySequence<int> *arraySequence1 = arraySequence.GetSubsequence(2, 8);
    if(arraySequence1->GetLength() != 6) m = false;
    for (int i = 0; i < 6; ++i) {
        if(arraySequence1->Get(i) != i+3) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestAppend(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.Append(11);
    if(arraySequence.GetLength() != 11) m = false;
    for (int i = 0; i < 11; ++i) {
        if(arraySequence.Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestPrepend(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.Prepend(0);
    if(arraySequence.GetLength() != 11) m = false;
    for (int i = 0; i < 11; ++i) {
        if(arraySequence.Get(i) != i) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestInsertAt(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.InsertAt(5, 2);
    if(arraySequence.Get(2)!=5) m = false;
    isAllRight(m);
}

void arraySequenceTestChangeElements(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.changeElements(2,3);
    if(arraySequence.Get(2)!=3) m = false;
    if(arraySequence.Get(3)!=2) m = false;
    isAllRight(m);
}

void arraySequenceTestDeleteElements(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.deleteElement(2);
    if(arraySequence.GetLength()!=9) m = false;
    for (int i = 0; i < 2; ++i) {
        if(arraySequence.Get(i)!=i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestAll(){
    arraySequenceTestGetFirst();
    arraySequenceTestGetLast();
    arraySequenceTestGet();
    arraySequenceTestGetSubSequence();
    arraySequenceTestInsertAt();
    arraySequenceTestPrepend();
    arraySequenceTestChangeElements();
    arraySequenceTestDeleteElements();
    arraySequenceTestAppend();
}

void testMatrixGetElement(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    Matrix<int> matrix = Matrix<int>(a, 3,3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
           if(matrix.GetElement(i,j) != i*matrix.GetLength() + j) m = false;
        }
    }
    isAllRight(m);
}

void testMatrixSum(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(matrix->GetElement(i,j) != i*matrix1.GetLength() + j + i*matrix2->GetLength() + j) m = false;
        }
    }
    isAllRight(m);
}

void testMatrixSub(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(matrix->GetElement(i,j) != 0) m = false;
        }
    }
    isAllRight(m);
}

void testMatrixMult(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    isAllRight(m);
}

void matrixTests(){
    testMatrixSum();
    testMatrixSub();
    testMatrixMult();
    testMatrixGetElement();
}