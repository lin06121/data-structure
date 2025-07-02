//
// Created by 玉林 on 25-4-22.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>

using namespace std;

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class binarysearchtree {
private:
    struct Node {
        SET<KEY, OTHER> data;
        Node *left;
        Node *right;
        int size;
        Node(const SET<KEY, OTHER> &thedata, Node *l = nullptr, Node *r = nullptr)
            : data(thedata), left(l), right(r) {}
    };
    Node *root;

    // 辅助函数：递归清空
    void makeempty(Node *t) {
        if (t == nullptr) return;
        makeempty(t->left);
        makeempty(t->right);
        delete t;
    }

public:
    binarysearchtree() { root = nullptr; }

    ~binarysearchtree() { makeempty(root); }

    // 查找 x，返回指向SET的指针，找不到返回nullptr
    SET<KEY, OTHER> *find(const KEY &x) {
        Node *cur = root;
        while (cur != nullptr) {
            if (x < cur->data.key) {
                cur = cur->left;
            } else if (x > cur->data.key) {
                cur = cur->right;
            } else {
                return &(cur->data); // 找到了
            }
        }
        return nullptr;
    }

    // 插入节点（非递归）
    void insert(const SET<KEY, OTHER> &x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }

        Node *cur = root;
        Node *parent = nullptr;

        while (cur != nullptr) {
            parent = cur;
            if (x.key < cur->data.key) {
                cur = cur->left;
            } else if (x.key > cur->data.key) {
                cur = cur->right;
            } else {
                // 如果已经存在相同的key，可以更新other字段，或者不处理
                cur->data.other = x.other;
                return;
            }
        }

        if (x.key < parent->data.key)
            parent->left = new Node(x);
        else
            parent->right = new Node(x);
    }

    // 删除节点（非递归）
    void remove(const KEY &x) {
        Node *cur = root;
        Node *parent = nullptr;

        while (cur != nullptr && cur->data.key != x) {
            parent = cur;
            if (x < cur->data.key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (cur == nullptr) return; // 没找到

        // 有两个儿子
        if (cur->left != nullptr && cur->right != nullptr) {
            Node *succParent = cur;
            Node *succ = cur->right;

            // 找右子树最小节点（即中序后继）
            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }

            cur->data = succ->data; // 用后继代替当前节点
            // 然后去删除succ
            cur = succ;
            parent = succParent;
        }

        // cur至多有一个孩子
        Node *child;
        if (cur->left != nullptr)
            child = cur->left;
        else
            child = cur->right;

        if (parent == nullptr) {
            root = child; // 删除的是根节点
        } else if (parent->left == cur) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete cur;
    }

    void remove(const KEY &x,Node *&t)
    {if(t==nullptr) return;
        if(x<t->data.key) remove(x,t->left);
        else if(x>t->data.key) remove(x,t->right);
        else if(t->left!=nullptr&& t->right!=nullptr)
        { Node *tmp=t->right;
            while(tmp->left!=nullptr) tmp=tmp->left;
            t->data=tmp->data;
            remove(t->data.key,t->right);}
        else{
            Node *oldnode=t;
            t=(t->left!=nullptr)? t->left:t->right;
            delete oldnode;
           }
        }

    void delete_higher_than_x(const KEY &x, Node *&t) {
        if (t == nullptr) return;

        if (t->data.key > x) {
            Node *old=t;
            t=t->left;
            makeempty(old->right);
            delete old;
            delete_higher_than_x(x,t);
        } else {
            delete_higher_than_x(x, t->right);
        }
    }


    void delete_higher_than_x(const KEY &x) {
        delete_higher_than_x(x, root);
    }


    void delete_lower_than_x(const KEY &x, Node *&t) {
        if (t == nullptr) return;

        if (t->data.key < x) {
            Node *old = t;
            t = t->right;
            makeempty(old->left);
           delete old;
           delete_lower_than_x(x, t);
        } else {
            delete_lower_than_x(x, t->left);
        }
    }


    void delete_lower_than_x(const KEY &x) {
        delete_lower_than_x(x, root);
    }

   void delete_in_range(const KEY &low, const KEY &high, Node *&t) {
        if (t == nullptr) return;

        if (t->data.key >=low && t->data.key <=high) {
            remove(t->data.key,t);
            delete_in_range(low, high, t);
        } else if (t->data.key < low) {
            delete_in_range(low, high, t->right);
        } else {
            delete_in_range(low, high, t->left);
        }
    }



    void delete_in_range(const KEY &low, const KEY &high) {
        delete_in_range(low, high, root);
    }

   int size(Node* t)
    { if(t==nullptr) return 0;
       return 1+size(t->right)+size(t->left);}
    SET<KEY, OTHER> *find_kth_max(int k,Node *t)
    {  if(size(t->right)==(k-1)) return &(t->data);
        if(size(t->right)+1>k) return  find_kth_max(k,t->right);
        else return find_kth_max(k-size(t->right)-1,t->left);
   }
    SET<KEY, OTHER> *find_kth_max(int k)
    {return find_kth_max(k,root);}

   void preOrder(Node* t) const {
        if (!t) return;
        cout << t->data.key << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
    void preOrder() const { preOrder(root); cout << endl; }


};

#endif BINARYSEARCHTREE_H
