//
// Created by 玉林 on 25-3-31.
//
#include <iostream>
#include <queue>
using namespace std;

template<class T>
class NaryTree {
public:
    struct Node {
        T data;
        Node* firstChild;
        Node* nextSibling;

        Node(T val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
    };

    Node* root;

    NaryTree() : root(nullptr) {}
    NaryTree(T val) { root = new Node(val); }

    // 遍历操作
    void preOrder(Node* node) const;
    void inOrder(Node* node) const;
    void postOrder(Node* node) const;
    void levelOrder(Node* node) const;
};

// 前序遍历
template<class T>
void NaryTree<T>::preOrder(Node* node) const {
    if (node == nullptr) return;

    cout << node->data << " ";
    preOrder(node->firstChild);
    preOrder(node->nextSibling);
}

// 中序遍历
template<class T>
void NaryTree<T>::inOrder(Node* node) const {
    if (node == nullptr) return;

    inOrder(node->firstChild);
    cout << node->data << " ";
    inOrder(node->nextSibling);
}

// 后序遍历
template<class T>
void NaryTree<T>::postOrder(Node* node) const {
    if (node == nullptr) return;

    postOrder(node->firstChild);
    postOrder(node->nextSibling);
    cout << node->data << " ";
}

// 层次遍历
template<class T>
void NaryTree<T>::levelOrder(Node* node) const {
    if (node == nullptr) return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";

        Node* child = cur->firstChild;
        while (child) {
            q.push(child);
            child = child->nextSibling;
        }
    }
}

// 测试代码
int main() {
    NaryTree<int> tree(1);
    tree.root->firstChild = new NaryTree<int>::Node(2);
    tree.root->firstChild->nextSibling = new NaryTree<int>::Node(3);
    tree.root->firstChild->firstChild = new NaryTree<int>::Node(4);
    tree.root->firstChild->nextSibling->firstChild = new NaryTree<int>::Node(5);
    tree.root->firstChild->nextSibling->nextSibling = new NaryTree<int>::Node(6);

    cout << "前序遍历: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "中序遍历: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "后序遍历: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "层次遍历: ";
    tree.levelOrder(tree.root);
    cout << endl;

    return 0;
}
