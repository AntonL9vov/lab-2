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
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number:";
    cin>>a;
    if(a>upper||a<lower){
        cout<<"Number is out of range, try again";
        GetInt(lower, upper);
    }
    return a;
}

int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return (float)randomInt() + (float)randomInt()/(float)randomInt();
}

complex<int> randomComplex() {
    return complex<int>(randomInt(), randomInt());
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

void createIntVector(ArraySequence<Vector<int>*> vectorInt, int dimension){
    int *a = new int[dimension];
    cout<<"Input coordinates:"<<endl;
    for (int i = 0; i < dimension; ++i) {
        cout<<"Input "<<i<<" coordinate";
        a[i] = GetInt();
        cout<<endl;
    }
    Vector<int> *vector = new Vector<int>(a, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorInt.Append(vector);
}

void createRandomIntVector(ArraySequence<Vector<int>*> vectorInt, int dimension){
    int *a = new int[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomInt();
    }
    Vector<int> *vector = new Vector<int>(a, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorInt.Append(vector);
}

void createFloatVector(ArraySequence<Vector<float>*> vectorFloat, int dimension){
    float *a = new float[dimension];
    cout<<"Input coordinates:"<<endl;
    for (int i = 0; i < dimension; ++i) {
        cout<<"Input "<<i<<" coordinate";
        cin>>a[i];
        cout<<endl;
    }
    Vector<float> *vector = new Vector<float>(a, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorFloat.Append(vector);
}

void createRandomFloatVector(ArraySequence<Vector<float>*> vectorFloat, int dimension){
    float *a = new float[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomFloat();
    }
    Vector<float> *vector = new Vector<float>(a, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorFloat.Append(vector);
}

void createComplexVector(ArraySequence<Vector<complex<float>>*> vectorComplex, int dimension){
    float *a = new float[dimension];
    float *b = new float[dimension];
    cout<<"Input coordinates:"<<endl;
    for (int i = 0; i < dimension; ++i) {
        cout<<"Input real part for "<<i<<" coordinate";
        cin>>a[i];
        cout<<endl<<"Input imaginary part for"<<i<<" coordinate";
        cin>>b[i];
        cout<<endl;
    }
    complex<float> *c = new complex<float>[dimension];
    for (int i = 0; i < dimension; ++i) {
        c[i] = complex<float>(a[i],b[i]);
    }
    Vector<complex<float>> *vector = new Vector<complex<float>>(c, dimension);
    cout<<"it is your new vector: "<<*vector<<endl;
    vectorComplex.Append(vector);
}

void createRandomComplexVector(ArraySequence<Vector<complex<float>>*> vectorComplex, int dimension){
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
    vectorComplex.Append(vector);
}

void getVector(ArraySequence<Vector<int>*> vectorInt, ArraySequence<Vector<float>*> vectorFloat, ArraySequence<Vector<complex<float>>*> vectorComplex){
    cout<<"Input vector dimension:"<<endl;
    int dimension = GetInt();
    int ch;
    cout<<"How do you want to input your vector?"<<endl;
    cout<<"1. Randomly."<<endl;
    cout<<"2. By myself."<<endl;
    ch = GetInt(1, 2);
    cout<<"What type of vector do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);
    switch (a) {
        case 1:
            if(ch==1) {
                createRandomIntVector(vectorInt, dimension);
            }else{
                createIntVector(vectorInt,dimension);
            }
            break;
        case 2:
            if (ch==1){
                createRandomFloatVector(vectorFloat, dimension);
            }else{
                createFloatVector(vectorFloat, dimension);
            }
            break;
        case 3:
            if (ch==1){
                createRandomComplexVector(vectorComplex, dimension);
            }else{
                createComplexVector(vectorComplex, dimension);
            }
            break;
        default: break;
    }
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
        cout << "9. Exit."<<endl;

        number = GetInt(1,8);

        if(number == 9) break;

        switch (number) {
            case 1: getVector(vectorInt, vectorFloat, vectorComplex);
                break;
            case 2: break;
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
