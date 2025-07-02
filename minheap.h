//
// Created by 玉林 on 25-4-12.
//

#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

template<class T>
class minheap {
public:
    explicit minheap(int capacity = 100);
    minheap(const T data[], int size);
    ~minheap();

    bool isempty() const;
    void enQueue(const T &x);
    T deQueue();
    T gethead() const;
    int findMin(const T& x) const;
    void decreasekey(int i, const T& value);

    int currentsize;
    T *array;
    int maxsize;

    void doublespace();
    void buildheap();
    void percolate(int hole);
    void findMin(int index, const T& x, int& bestIndex, T& bestValue) const;

};

// 构造函数
template<class T>
minheap<T>::minheap(int capacity) {
    maxsize = capacity;
    array = new T[maxsize + 1]; // 0号不存储元素
    currentsize = 0;
}

// 用数组建堆
template<class T>
minheap<T>::minheap(const T data[], int size) {
    maxsize = size + 10;
    array = new T[maxsize + 1];
    currentsize = size;
    for (int i = 0; i < size; ++i)
        array[i + 1] = data[i];
    buildheap();
}

// 析构函数
template<class T>
minheap<T>::~minheap() {
    delete[] array;
}

// 是否为空
template<class T>
bool minheap<T>::isempty() const {
    return currentsize == 0;
}

// 入队
template<class T>
void minheap<T>::enQueue(const T &x) {
    if (currentsize == maxsize - 1)
        doublespace();

    // 上滤插入
    int hole = ++currentsize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}

// 出队
template<class T>
T minheap<T>::deQueue() {
    if (isempty())
        throw underflow_error("Heap is empty.");

    T minItem = array[1];
    array[1] = array[currentsize--];
    percolate(1);
    return minItem;
}

// 取堆顶元素
template<class T>
T minheap<T>::gethead() const {
    if (isempty())
        throw underflow_error("Heap is empty.");
    return array[1];
}

// 扩容
template<class T>
void minheap<T>::doublespace() {
    T *oldArray = array;
    maxsize *= 2;
    array = new T[maxsize + 1];
    for (int i = 1; i <= currentsize; ++i)
        array[i] = oldArray[i];
    delete[] oldArray;
}

// 建堆（下滤）
template<class T>
void minheap<T>::buildheap() {
    for (int i = currentsize / 2; i > 0; --i)
        percolate(i);
}

// 下滤
template<class T>
void minheap<T>::percolate(int hole) {
    T temp = array[hole];
    int child;
    for (; hole * 2 <= currentsize; hole = child) {
        child = hole * 2;
        if (child != currentsize && array[child + 1] < array[child])
            ++child;
        if (array[child] < temp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = temp;
}
// 私有递归函数：在 index 为根的子堆中查找满足 >= x 的最小值
template<class T>
void minheap<T>::findMin(int index, const T& x, int& bestIndex, T& bestValue) const {
    if (index > currentsize) return;

    if (array[index] >= x) {
        // 更新最小值
        if (bestIndex == -1 || array[index] < bestValue) {
            bestIndex = index;
            bestValue = array[index];
        }
    }

    // 继续查找左右子树
    findMin(index * 2, x, bestIndex, bestValue);     // 左子树
    findMin(index * 2 + 1, x, bestIndex, bestValue); // 右子树
}
template<class T>
int minheap<T>::findMin(const T& x) const {
    int bestIndex = -1;
    T bestValue = std::numeric_limits<T>::max();
    findMin(1, x, bestIndex, bestValue); // 从根开始
    return bestIndex;
}
template<class T>
void minheap<T>::decreasekey( int i, const T& value) {


    // 减少第 i 个元素的优先级
    array[i] -= value;

    // 上滤调整堆结构
    percolate(i);
}



#endif // MINHEAP_H

