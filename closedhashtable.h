//
// Created by 玉林 on 25-4-29.
//

#ifndef CLOSEDHASHTABLE_H
#define CLOSEDHASHTABLE_H

#include<iostream>
using namespace std;

// 定义 SET 结构体
template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

// 闭散列哈希表
template <class KEY, class OTHER>
class closedhashtable {
public:
    struct node {
        SET<KEY, OTHER> data;
        int state; // 0: empty, 1: active, 2: deleted
        node(SET<KEY, OTHER> d, int s = 0) : data(d), state(s) {}
        node() : state(0) {}
    };

    node* array; // 哈希表数组
    int size;    // 当前数组大小
    int deadline; // 删除元素阈值
    int count1;  // 活跃元素个数
    int count2;  // 删除元素个数
    int (*key)(const KEY&); // 取 key 的哈希函数

    // 默认哈希函数（直接返回KEY）
    static int default_key(const KEY& x) { return x; }

    // 构造函数
    closedhashtable(int i, int length = 101, int(*f)(const KEY& x) = default_key)
        : size(length), deadline(i), count1(0), count2(0), key(f) {
        array = new node[size];
    }

    // 析构函数
    ~closedhashtable() {
        delete[] array;
    }

    // 查找
    SET<KEY, OTHER>* find(const KEY& x) const {
        int initpos = key(x) % size;
        int pos = initpos;
        do {
            if (array[pos].state == 0) return nullptr;
            else if (array[pos].state == 1 && array[pos].data.key == x)
                return &array[pos].data;
            pos = (pos + 1) % size;
        } while (pos != initpos);
        return nullptr;
    }

    // 插入
    void insert(const SET<KEY, OTHER>& x) {
        if (find(x.key) != nullptr) return; // 如果已有，直接返回

        int initpos = key(x.key) % size;
        int pos = initpos;
        do {
            if (array[pos].state != 1) { // 找到空位或者被删除的位置
                array[pos].data = x;
                array[pos].state = 1;
                count1++;

                if (count1 * 2 > size) // 负载因子大于0.5时扩容
                    doublespace();
                return;
            }
            pos = (pos + 1) % size;
        } while (pos != initpos);
    }

    // 删除
    void remove(const KEY& x) {
        int initpos = key(x) % size;
        int pos = initpos;
        do {
            if (array[pos].state == 0) return;
            else if (array[pos].state == 1 && array[pos].data.key == x) {
                array[pos].state = 2; // 标记为删除
                count2++;
                if (count2 > deadline) // 如果删除元素过多，重新哈希
                    rehash();
                return;
            }
            pos = (pos + 1) % size;
        } while (pos != initpos);
    }

private:
    // 扩容
    void doublespace() {
        node* tmp = array;
        int old_size = size;

        size = size * 2 + 1;
        array = new node[size];
        count1 = 0;
        count2 = 0;
        deadline *= 2;

        for (int i = 0; i < old_size; i++) {
            if (tmp[i].state == 1)
                insert(tmp[i].data);
        }
        delete[] tmp;
    }

    // 重新哈希
    void rehash() {
        node* tmp = array;
        array = new node[size];
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < size; i++) {
            if (tmp[i].state == 1)
                insert(tmp[i].data);
        }
        delete[] tmp;
    }
};

#endif // CLOSEDHASHTABLE_H
