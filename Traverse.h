#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "Binarytree.h"
#include <vector>

template<class DATA>
bool preorder(const Bitreenode<DATA>* node, std::vector<DATA>& list) {
    if (node != nullptr) {
        list.push_back(node->data); // 使用 push_back 插入数据
        if (node->left != nullptr)
            preorder(node->left, list); // 遍历左子树
        if (node->right != nullptr)
            preorder(node->right, list); // 遍历右子树
        return true;
    }
    return false;
}

template<class DATA>
bool inorder(const Bitreenode<DATA>* node, std::vector<DATA>& list) {
    if (node != nullptr) {
        if (node->left != nullptr)
            inorder(node->left, list); // 遍历左子树
        list.push_back(node->data); // 插入当前节点数据
        if (node->right != nullptr)
            inorder(node->right, list); // 遍历右子树
        return true;
    }
    return false;
}

template<class DATA>
bool postorder(const Bitreenode<DATA>* node, std::vector<DATA>& list) {
    if (node != nullptr) {
        if (node->left != nullptr)
            postorder(node->left, list); // 遍历左子树
        if (node->right != nullptr)
            postorder(node->right, list); // 遍历右子树
        list.push_back(node->data); // 插入当前节点数据
        return true;
    }
    return false;
}

#endif

