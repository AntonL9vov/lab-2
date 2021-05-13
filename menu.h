//
// Created by AntonLvov on 09.05.2021.
//

#ifndef LAB_2_MENU_H
#define LAB_2_MENU_H

#include "Matrix.h"
#include "iostream"
#include <complex>

#endif //LAB_2_MENU_H


using namespace std;

int GetInt(){
    int a;
    cin>>a;
    if (a<1){
        cout<<"Number is out of range. Try again:";
        GetInt();
    }
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number: ";
    cin>>a;
    if(a>upper||a<lower){
        cout<<"Number is out of range, try again"<<endl;
        GetInt(lower, upper);
    }
    return a;
}

int getNumber(int a){
    int b;
    cin>>b;
    return b;
}

float getNumber(float a){
    int b;
    cin>>b;
    return b;
}

complex<float> getNumber(complex<float> a){
    float b, c;
    cout<<endl;
    cout<<"Input real part: ";
    cin>>b;
    cout<<"Input imaginary part: ";
    cin>>c;
    complex<float> num = complex<float>(b,c);
    return num;
}

int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
}

complex<float> randomComplex() {
    return complex<float>(randomFloat(), randomFloat());
}

ostream& operator << (ostream& cout, complex<float> com){
    if (com.imag() == 0) return cout << com.real();

    if (com.real() != 0) {
        cout << com.real();
    }

    if (com.imag() > 0) {
        if (com.real() != 0)
            cout << '+';
        if (com.imag() != 1)
            cout << com.imag();
        return cout << 'i';
    }
    else {
        if (com.imag() == -1)
            return cout << "-i";
        return cout << com.imag() << 'i';
    }
}

void printMenu(){
    cout<<"Menu: "<<endl;
    cout<<"What do you want to do?"<<endl;
    cout<<"1.  Put vector in memory."<<endl;
    cout<<"2.  Put matrix in memory."<<endl;
    cout<<"3.  Show available vectors in memory."<<endl;
    cout<<"4.  Show available matrices in memory."<<endl;
    cout<<"5.  Sum two vectors."<<endl;
    cout<<"6.  Sum two matrices."<<endl;
    cout<<"7.  Sub two vectors."<<endl;
    cout<<"8.  Sub two matrices"<<endl;
    cout<<"9.  Multiply two vectors."<<endl;
    cout<<"10. Multiply two matrices."<<endl;
    cout<<"11. Multiply vector on scalar."<<endl;
    cout<<"12. Multiply matrix on scalar."<<endl;
    cout<<"13. Change lines in matrix."<<endl;
    cout<<"14. Multiply line in matrix."<<endl;
    cout<<"15. Add line to line in matrix."<<endl;
    cout<<"16. Remove vector from memory."<<endl;
    cout<<"17. Remove matrix from memory."<<endl;
}

template<class T>
void createVector(ArraySequence<Vector<T>*> *array, int dimension){
    cout<<endl;
    cout<<"Input 1 coordinate:";
    T a = getNumber(a);
    T *r = new T[1];
    r[0] = a;
    ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
    for (int i = 0; i < dimension-1; ++i) {
        cout<<"Input "<<i + 2 <<" coordinate:";
        arraySequence->Append(getNumber(a));
    }
    auto *vector = new Vector<T>(*arraySequence);
    cout<<"it is your new vector: "<<*vector<<endl;
    array->Append(vector);
};

void createRandomIntVector(ArraySequence<Vector<int>*> *vectorInt, int dimension){
    int *a = new int[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomInt();
    }
    auto *vector = new Vector<int>(a, dimension);
    cout<<vector->GetDimension();
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorInt->Append(vector);
}

void createRandomFloatVector(ArraySequence<Vector<float>*> *vectorFloat, int dimension){
    float *a = new float[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomFloat();
    }
    Vector<float> *vector = new Vector<float>(a, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorFloat->Append(vector);
}

void createRandomComplexVector(ArraySequence<Vector<complex<float>>*> *vectorComplex, int dimension){
    float *a = new float[dimension];
    float *b = new float[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomFloat();
        b[i] = randomFloat();
    }
    complex<float> *c = new complex<float>[dimension];
    for (int i = 0; i < dimension; ++i) {
        c[i] = complex<float>(a[i],b[i]);
    }
    Vector<complex<float>> *vector = new Vector<complex<float>>(c, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorComplex->Append(vector);
}

void getVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
    cout<<"---------"<<endl;
    int ch;
    cout<<endl;
    cout<<"What type of vector do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);

    cout<<"Input vector dimension: ";
    int dimension = GetInt();

    cout<<endl;
    cout<<"How do you want to input your vector?"<<endl;
    cout<<"1. Randomly."<<endl;
    cout<<"2. By myself."<<endl;
    ch = GetInt(1, 2);

    switch (a) {
        case 1:
            if(ch==1) {
                createRandomIntVector(vectorInt, dimension);
            }else{
                createVector(vectorInt,dimension);
            }
            break;
        case 2:
            if (ch==1){
                createRandomFloatVector(vectorFloat, dimension);
            }else{
                createVector(vectorFloat, dimension);
            }
            break;
        case 3:
            if (ch==1){
                createRandomComplexVector(vectorComplex, dimension);
            }else{
                createVector(vectorComplex, dimension);
            }
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}

template<class T>
void createMatrix(ArraySequence<Matrix<T>*> *array, int height, int length){
    cout<<endl;
    cout<<"Input 1,1 number:";
    T a = getNumber(a);
    T *r = new T[1];
    r[0] = a;
    ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            cout<<"Input "<<i+1<<", "<<j+1<<" number:";
            arraySequence->Append(getNumber(a));
        }
        j = 0;
    }
    auto *matrix = new Matrix<T>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomIntMatrix(ArraySequence<Matrix<int>*> *array, int height, int length){
    cout<<endl;
    int a = randomInt();
    int *r = new int[1];
    r[0] = a;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomInt());
        }
        j = 0;
    }
    auto *matrix = new Matrix<int>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomFloatMatrix(ArraySequence<Matrix<float>*> *array, int height, int length){
    cout<<endl;
    float a = randomFloat();
    float *r = new float[1];
    r[0] = a;
    ArraySequence<float> *arraySequence = new ArraySequence<float>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomFloat());
        }
        j = 0;
    }
    auto *matrix = new Matrix<float>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomComplexMatrix(ArraySequence<Matrix<complex<float>>*> *array, int height, int length){
    cout<<endl;
    complex<float> a = randomComplex();
    complex<float> *r = new complex<float>[1];
    r[0] = a;
    ArraySequence<complex<float>> *arraySequence = new ArraySequence<complex<float>>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomComplex());
        }
        j = 0;
    }
    auto *matrix = new Matrix<complex<float>>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void getMatrix(ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
    cout<<"---------"<<endl;
    cout<<"What type of matrix do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);

    cout<<"Input matrix length:";
    int length = GetInt();
    cout<<"Input matrix height: ";
    int height = GetInt();

    int ch;
    cout<<endl;
    cout<<"How do you want to input your matrix?"<<endl;
    cout<<"1. Randomly."<<endl;
    cout<<"2. By myself."<<endl;
    ch = GetInt(1, 2);
    switch (a) {
        case 1:
            if(ch==1) {
                createRandomIntMatrix(matrixInt, height, length);
            }else{
                createMatrix(matrixInt, height, length);
            }
            break;
        case 2:
            if (ch==1){
                createRandomFloatMatrix(matrixFloat, height, length);
            }else{
                createMatrix(matrixFloat, height, length);
            }
            break;
        case 3:
            if (ch==1){
                createRandomComplexMatrix(matrixComplex, height, length);
            }else{
                createMatrix(matrixComplex, height, length);
            }
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}

void menu(){
    ArraySequence<Vector<int>*> vectorInt;
    ArraySequence<Vector<float>*> vectorFloat;
    ArraySequence<Vector<complex<float>>*> vectorComplex;

    ArraySequence<Matrix<int>*> matrixInt;
    ArraySequence<Matrix<float>*> matrixFloat;
    ArraySequence<Matrix<complex<float>>*> matrixComplex;

    int number;
    
    while (true) {
        cout << "Menu: " << endl;
        cout << "What do you want to do?" << endl;
        cout << "1.  Input vector in memory." << endl;
        cout << "2.  Input matrix in memory." << endl;
        cout << "3.  Show available vectors in memory." << endl;
        cout << "4.  Show available matrices in memory." << endl;
        cout << "5.  Operate with vectors."<<endl;
        cout << "6.  Operate with matrices."<<endl;
        cout << "7.  Remove vector from memory."<<endl;
        cout << "8.  Remove matrix from memory."<<endl;
        cout << "9.  Exit."<<endl;

        number = GetInt(1,9);

        if(number == 9) break;

        switch (number) {
            case 1: getVector(&vectorInt, &vectorFloat, &vectorComplex);
                break;
            case 2:
                getMatrix(&matrixInt, &matrixFloat, &matrixComplex);
                break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            default: break;
        }
    }
}
