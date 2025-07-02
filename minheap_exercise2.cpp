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

    cout << "Before decreasing priority:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << "array[" << i << "] = " << h.array[i] << endl;
    }

    // 假设我们要将第 3 个元素的优先级减少 5
    h.decreasekey(3, 5);

    cout << "After decreasing priority:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << "array[" << i << "] = " << h.array[i] << endl;
    }

    return 0;
}
