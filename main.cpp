#include <iostream>
#include "LinkedList.h"


int main() {
    int *a = new int[5];
    for (int i = 0; i < 5; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 5);
    linkedList.Print();
    LinkedList<int> *list = linkedList.GetSubList(1, 3);
    list->Print();
    linkedList.Concat(list);
    linkedList.Print();
    std::cout << linkedList.GetLength();
    return 0;
}
