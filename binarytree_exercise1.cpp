//
// Created by 玉林 on 25-3-31.
//
#include <iostream>
#include "binarytree1.h"

using namespace std;

int main() {
    binarytree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "中序遍历: ";
    tree.midOrder();

    cout << "度为2的节点数: " << tree.countDegreeTwoNodes() << endl;

    return 0;
}

