#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class stack {
    friend istream& operator>>(istream& in, stack& obj) {
        cout << "please deliver stack[" << obj.top + 1 << "]:\n";
        for (int i = 0; i <= obj.top; i++) in >> obj.s[i];
        return in;
    }
    
    friend ostream& operator<<(ostream& os, const stack& obj) {
        os << "stack is:\n";
        for (int i = 0; i <= obj.top; i++) os << obj.s[i] << '\t';
        os << endl;
        return os;
    }

    friend bool operator==(const stack& s1, const stack& s2) {
        if (s1.top != s2.top) return false;
        for (int i = 0; i <= s1.top; i++) {
            if (s1.s[i] != s2.s[i]) return false;
        }
        return true;
    }

private:
    int top;
    T* s;
    int maxSize;

public:
    stack(int size) : top(-1), s(new T[size]), maxSize(size) {}
    
    stack(const stack& arr);

    bool isempty() const { return top == -1; }
    bool isfull() const { return top == maxSize - 1; }

    void push(const T& x);
    T pop();
    stack& operator=(const stack& s1);

    T& operator[](int index) {
        assert(index >= 0 && index <= top);
        return s[index];
    }

    const T& operator[](int index) const {
        assert(index >= 0 && index <= top);
        return s[index];
    }

    ~stack() {
        delete[] s;
    }
};

template <class T>
stack<T>::stack(const stack<T>& arr) : top(arr.top), s(new T[arr.maxSize]), maxSize(arr.maxSize) {
    for (int i = 0; i <= arr.top; i++) {
        s[i] = arr.s[i];
    }
}

template <class T>
void stack<T>::push(const T& x) {
    if (!isfull()) {
        s[++top] = x;
    } else {
        cout << "Stack overflow" << endl;
    }
}

template <class T>
T stack<T>::pop() {
    if (!isempty()) {
        return s[top--];
    } else {
        cout << "Stack underflow" << endl;
        return T(); 
    }
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& s1) {
    if (this != &s1) {
        delete[] s;
        top = s1.top;
        maxSize = s1.maxSize;
        s = new T[s1.maxSize];
        for (int i = 0; i <= s1.top; i++) {
            s[i] = s1.s[i];
        }
    }
    return *this;
}

#endif // STACK_H
