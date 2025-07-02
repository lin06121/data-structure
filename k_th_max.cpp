//
// Created by 玉林 on 25-5-12.
//
#include<iostream>
using namespace std;
enum HeapType { MAX_HEAP, MIN_HEAP };

class priorityQueue {
public:
  int *array;
  int size;
  int capacity;
  HeapType type;

  priorityQueue(int *a, int n, HeapType t = MAX_HEAP, int c = 100) {
    type = t;
    capacity = std::max(c, n + 10);
    size = n;
    array = new int[capacity + 1];
    for (int i = 0; i < n; ++i)
      array[i + 1] = a[i]; // index 从 1 开始
    buildheap();
  }

  ~priorityQueue() {
    delete[] array;
  }

  bool isEmpty() const { return size == 0; }

  int dequeue() {
    int temp = array[1];
    array[1] = array[size--];
    percolateDown(1);
    return temp;
  }

  void enqueue(int element) {
    if (size == capacity - 1) doublespace();
    int hole = ++size;
    for (; hole > 1 && compare(element, array[hole / 2]); hole /= 2)
      array[hole] = array[hole / 2];
    array[hole] = element;
  }

private:
  bool compare(int a, int b) {
    return (type == MAX_HEAP) ? a > b : a < b;
  }

  void buildheap() {
    for (int i = size / 2; i > 0; --i)
      percolateDown(i);
  }

  void percolateDown(int hole) {
    int child;
    int tmp = array[hole];
    for (; hole * 2 <= size; hole = child) {
      child = hole * 2;
      if (child < size && compare(array[child + 1], array[child]))
        child++;
      if (compare(array[child], tmp))
        array[hole] = array[child];
      else
        break;
    }
    array[hole] = tmp;
  }

  void doublespace() {
    int *tmp = array;
    capacity *= 2;
    array = new int[capacity + 1];
    for (int i = 1; i <= size; ++i)
      array[i] = tmp[i];
    delete[] tmp;
  }
};

void func1(int *a, int k, int n) {
  priorityQueue pq(a, n);
  int tmp = -1;
  for (int i = 0; i < k; i++) tmp = pq.dequeue();
  cout << "func1 k-th largest: " << tmp << endl;
}


void func2(int *a, int k, int n) {
  int *tmp = new int[k];
  for (int i = 0; i < k; ++i)
    tmp[i] = a[i];
  priorityQueue pq(tmp, k, MIN_HEAP);

  for (int i = k; i < n; ++i) {
    if (a[i] > pq.array[1]) { // array[1] 是最小堆顶
      pq.dequeue();
      pq.enqueue(a[i]);
    }
  }

  cout << "func2 k-th largest: " << pq.array[1] << endl;
  delete[] tmp;
}

int main() {
  int a[] = {6, 8, 4, 9, 2, 6, 7, 8, 11, 3, 5, 16};
  int n = sizeof(a) / sizeof(a[0]);
  int k;
  cout << "Enter the k-th index: ";
  cin >> k;

  // 找到第 k 大的元素
  priorityQueue maxPQ(a, n);
  int tmp;
  for (int i = 0; i < k; ++i)
    tmp = maxPQ.dequeue();
  cout << "func1 k-th largest: " << tmp << endl;

  func2(a, k, n);

  return 0;
}


