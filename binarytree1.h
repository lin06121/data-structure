//
// Created by 玉林 on 25-3-31.
//

#ifndef BINARYTREE1_H
#define BINARYTREE1_H

#include <iostream>
#include <queue>
using namespace std;

template<class T>
class binarytree {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        Node() : left(nullptr), right(nullptr) {}
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
public:
    Node* root;

    void clear(Node*& t);
    Node* find(T x, Node* t) const;
    void preOrder(Node* t) const;
    void midOrder(Node* t) const;
    void postOrder(Node* t) const;
    int countDegreeTwoNodes(Node* node) const;
    void insert(T x);


    binarytree() : root(nullptr) {}
    binarytree(T x) { root = new Node(x); }
    ~binarytree() { clear(); }

    void clear();
    bool isEmpty() const { return root == nullptr; }
    T Root(T flag) const { return root ? root->data : flag; }
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delRight(T x);
    void delLeft(T x);
    void preOrder() const { preOrder(root); cout << endl; }
    void midOrder() const { midOrder(root); cout << endl; }
    void postOrder() const { postOrder(root); cout << endl; }
    int countDegreeTwoNodes() const { return countDegreeTwoNodes(root); }
    bool isCompleteBinaryTree() const;
};

// 清空树
template<class T>
void binarytree<T>::clear(Node*& t) {
    if (!t) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}

template<class T>
void binarytree<T>::clear() {
    clear(root);
}

// 查找节点
template<class T>
typename binarytree<T>::Node* binarytree<T>::find(T x, Node* t) const {
    if (!t) return nullptr;
    if (t->data == x) return t;
    Node* leftResult = find(x, t->left);
    return leftResult ? leftResult : find(x, t->right);
}

// 获取左子节点
template<class T>
T binarytree<T>::lchild(T x, T flag) const {
    Node* node = find(x, root);
    return (node && node->left) ? node->left->data : flag;
}

// 获取右子节点
template<class T>
T binarytree<T>::rchild(T x, T flag) const {
    Node* node = find(x, root);
    return (node && node->right) ? node->right->data : flag;
}

// 删除右子树
template<class T>
void binarytree<T>::delRight(T x) {
    Node* node = find(x, root);
    if (node && node->right) {
        clear(node->right);
    }
}

// 删除左子树
template<class T>
void binarytree<T>::delLeft(T x) {
    Node* node = find(x, root);
    if (node && node->left) {
        clear(node->left);
    }
}

// 先序遍历
template<class T>
void binarytree<T>::preOrder(Node* t) const {
    if (!t) return;
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}

// 中序遍历
template<class T>
void binarytree<T>::midOrder(Node* t) const {
    if (!t) return;
    midOrder(t->left);
    cout << t->data << " ";
    midOrder(t->right);
}

// 后序遍历
template<class T>
void binarytree<T>::postOrder(Node* t) const {
    if (!t) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << " ";
}

// 计算度为2的节点数
template<class T>
int binarytree<T>::countDegreeTwoNodes(Node* node) const {
    if (node == nullptr) return 0;

    int count = 0;
    if (node->left != nullptr && node->right != nullptr) {
        count += 1;
    }

    count += countDegreeTwoNodes(node->left);
    count += countDegreeTwoNodes(node->right);

    return count;
}
template<class T>
bool binarytree<T>::isCompleteBinaryTree() const {
    if (!root) return true; // 空树也是完全二叉树

    queue<Node*> q;
    q.push(root);
    bool mustBeLeaf = false;

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        // 如果已经遇到过不满的节点，但当前节点仍然有子节点，说明不是完全二叉树
        if (mustBeLeaf && (cur->left || cur->right)) {
            return false;
        }

        if (cur->left) {
            q.push(cur->left);
        } else {
            mustBeLeaf = true; // 左子树为空，则后续节点必须是叶子
        }

        if (cur->right) {
            q.push(cur->right);
        } else {
            mustBeLeaf = true; // 右子树为空，则后续节点必须是叶子
        }
    }
    return true;

}

template<class T>
void binarytree<T>::insert(T x) {
    if (!root) {
        root = new Node(x);
        return;
    }

    Node* cur = root;
    while (true) {
        if (x < cur->data) {
            if (!cur->left) {
                cur->left = new Node(x);
                return;
            }
            cur = cur->left;
        } else {
            if (!cur->right) {
                cur->right = new Node(x);
                return;
            }
            cur = cur->right;
        }
    }
}

#endif
