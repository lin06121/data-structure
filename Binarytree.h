#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// ???
template <class DATA>
class Bitreenode {
private:
    DATA data;
    Bitreenode* left;
    Bitreenode* right;

public:
    Bitreenode(DATA value) : data(value), left(nullptr), right(nullptr) {}
    DATA getData() const { return data; }
    Bitreenode* getLeft() const { return left; }
    Bitreenode* getRight() const { return right; }
    void setLeft(Bitreenode* node) { left = node; }
    void setRight(Bitreenode* node) { right = node; }
};

// ????
template <class DATA>
class Bitree {
private:
    Bitreenode<DATA>* root;
    int size;

    void clearTree(Bitreenode<DATA>* node) {
        if (node) {
            clearTree(node->getLeft());
            clearTree(node->getRight());
            delete node;
        }
    }

public:
    Bitree() : root(nullptr), size(0) {}
    ~Bitree() { clearTree(root); size = 0; }

    // ?????
    void insertRoot(const DATA& data) {
        if (!root) {
            root = new Bitreenode<DATA>(data);
            size = 1;
        }
    }

    // ??????
    bool insertLeft(Bitreenode<DATA>* node, const DATA& data) {
        if (!node || node->getLeft()) return false;
        node->setLeft(new Bitreenode<DATA>(data));
        ++size;
        return true;
    }

    // ??????
    bool insertRight(Bitreenode<DATA>* node, const DATA& data) {
        if (!node || node->getRight()) return false;
        node->setRight(new Bitreenode<DATA>(data));
        ++size;
        return true;
    }

    // ????
    Bitreenode<DATA>* search(Bitreenode<DATA>* node, const DATA& data) {
        if (!node) return nullptr;
        if (node->getData() == data) return node;
        Bitreenode<DATA>* leftSearch = search(node->getLeft(), data);
        return leftSearch ? leftSearch : search(node->getRight(), data);
    }

    // ????
    bool remove(Bitreenode<DATA>*& node, const DATA& data) {
        if (!node) return false;
        if (node->getData() == data) {
            clearTree(node);
            node = nullptr;
            --size;
            return true;
        }
        return remove(node->getLeft(), data) || remove(node->getRight(), data);
    }

    // ?????
    Bitreenode<DATA>* getRoot() { return root; }

    // ??????
    void printInOrder(Bitreenode<DATA>* node) {
        if (!node) return;
        printInOrder(node->getLeft());
        cout << node->getData() << " ";
        printInOrder(node->getRight());
    }
};

#endif
    // ??????????
    void removeLeft(Bitreenode<DATA>* node) {
        if (node && node->left) {
            clearTree(node->left);
            node->left = nullptr;
        }
    }

    // ??????????
    void removeRight(Bitreenode<DATA>* node) {
        if (node && node->right) {
            clearTree(node->right);
            node->right = nullptr;
        }
    }

    // ??????????
    static Bitree* merge(Bitree* leftTree, Bitree* rightTree, const DATA& rootdata) {
        Bitree* newTree = new Bitree();
        newTree->root = new Bitreenode<DATA>(rootdata);
        newTree->root->left = leftTree->root;
        newTree->root->right = rightTree->root;

        newTree->size = leftTree->size + rightTree->size + 1;
        leftTree->root = nullptr;
        rightTree->root = nullptr;

        return newTree;
    }

    // ????????????
    DATA getData(const Bitreenode<DATA>* node) const { return node->data; }

    // ??????????
    int getSize() const { return size; }
    // ????root
	Bitreenode<DATA>*& getBitreeroot()
	{return root;
	 } 
	 
};

#endif

