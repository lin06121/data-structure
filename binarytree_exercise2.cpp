//
// Created by 玉林 on 25-3-31.
//
#include <iostream>
#include "binarytree1.h"

using namespace std;

int main() {
    binarytree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7); // 现在是一个完全二叉树

    cout << "该树是否是完全二叉树？ " << (tree.isCompleteBinaryTree() ? "是" : "否") << endl;

    // 手动删除一个节点，制造非完全二叉树情况
    tree.delRight(2); // 删除值为 2 的右子树，使其变成不完全二叉树

    cout << "修改后，该树是否是完全二叉树？ " << (tree.isCompleteBinaryTree() ? "是" : "否") << endl;

    return 0;
}
