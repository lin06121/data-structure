//
// Created by 玉林 on 25-4-27.
//
#include<iostream>
#include "binarysearchtree.h"
using namespace std;
int main()
{binarysearchtree<int, string> bst;

    SET<int, string> s1 = {10, "Ten"};
    SET<int, string> s2 = {5, "Five"};
    SET<int, string> s3 = {15, "Fifteen"};
    SET<int, string> s4 = {7, "Seven"};
    SET<int, string> s5 = {3, "Three"};
    bst.insert(s1);
    bst.insert(s2);
    bst.insert(s3);
    bst.insert(s4);
    bst.insert(s5);

    // 获取第 3 大的元素
    SET<int, string> *s = bst.find_kth_max(3);

    if (s != nullptr) {
        cout << "The 3rd largest element is: " << s->other << endl;
    } else {
        cout << "Element not found!" << endl;
    }
   return 0;
}