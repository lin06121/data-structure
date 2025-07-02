//
// Created by 玉林 on 25-4-12.
//
#include<iostream>
#include "minheap.h"
int main() {
    minheap<int> h;
    h.enQueue(8);
    h.enQueue(3);
    h.enQueue(10);
    h.enQueue(1);
    h.enQueue(6);

    // 打印堆中的所有元素
    cout << "Heap elements: " << endl;
    for (int i = 1; i <= h.currentsize; ++i) {
        cout << "array[" << i << "] = " << h.array[i] << endl;
    }

    int index = h.findMin(5);
    if (index != -1)
        cout << "Found value >= 5: array[" << index << "] = " << h.array[index] << endl;
    else
        cout << "No value >= 5 found." << endl;

    return 0;
}
