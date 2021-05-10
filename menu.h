//
// Created by AntonLvov on 09.05.2021.
//

#ifndef LAB_2_MENU_H
#define LAB_2_MENU_H

#endif //LAB_2_MENU_H
#include "Matrix.h"
#include "Vector.h"
#include "iostream"
#include <complex>

using namespace std;

int GetInt(){
    int a;
    cout<<"Input number:";
    cin<<a;
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number:";
    cin<<a;
    if(a<upper||a>lower){
        cout<<"Number is out of range, try again";
        GetInt(lower, upper);
    }
    return a;
}


