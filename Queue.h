//
// Created by 玉林 on 25-3-18.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
  struct Node {
    T data;
    Node* next;
    Node(const T& x, Node* N = nullptr) : data(x), next(N) {}
    Node() : next(nullptr) {}
    ~Node() {}
  };
  Node* front;
  Node* rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  ~Queue() {
    Node* temp;
    while (front != nullptr) {
      temp = front;
      front = front->next;
      delete temp;
    }
  }

  bool isEmpty() const {
    return front == nullptr;
  }

  T getHead() const {
    if (front == nullptr) {
      throw runtime_error("Queue is empty!");
    }
    return front->data;
  }

  void enQueue(const T& x) {
    if (rear == nullptr)
      front = rear = new Node(x);
    else
      rear = rear->next = new Node(x);
  }

  T deQueue() {
    if (front == nullptr) {
      throw runtime_error("Queue underflow!");
    }
    Node* temp = front;
    T value = temp->data;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
    return value;
  }
  T getTail() const {
    if (rear  == nullptr) {
      throw runtime_error("Queue is empty!");
    }
    return rear->data;
  }
};

#endif // QUEUE_H
