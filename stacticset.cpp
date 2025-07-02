//
// Created by 玉林 on 25-4-21.
//
#include <iostream>
#include<string>
using namespace std;

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;


    bool operator==(const SET& s) const {
        return key == s.key && other == s.other;
    }
};

template <class KEY, class OTHER>
class stacticset {
public:
    SET<KEY, OTHER>* data;
    int size;

    // 构造函数
    stacticset(int size = 10) {
        this->size = size;
        data = new SET<KEY, OTHER>[size];
    }

    // 析构函数
    ~stacticset() {
        delete[] data;
    }

    // 并集操作
    stacticset operator+(const stacticset& a) {
        stacticset<KEY, OTHER> tmp(size + a.size);
        for (int i = 0; i < size; i++) {
            tmp.data[i] = data[i];
        }
        int k = 0;
        for (int j = 0; j < a.size; j++) {
            bool cross = false;
            for (int i = 0; i < size; i++) {
                if (data[i] == a.data[j]) {
                    cross = true;
                    break;
                }
            }
            if (!cross) {
                tmp.data[size + k] = a.data[j];
                k++;
            }
        }
        tmp.size = size + k; // 更新新集合大小
        return tmp;
    }

    // 差集操作
    stacticset operator-(const stacticset& a) {
        stacticset<KEY, OTHER> tmp(size);
        int k = 0;
        for (int i = 0; i < size; i++) {
            bool cross = false;
            for (int j = 0; j < a.size; j++) {
                if (data[i] == a.data[j]) {
                    cross = true;
                    break;
                }
            }
            if (!cross) {
                tmp.data[k] = data[i];
                k++;
            }
        }
        tmp.size = k;
        return tmp;
    }

    // 交集操作
    stacticset operator*(const stacticset& a) {
        stacticset<KEY, OTHER> tmp(size > a.size ? a.size : size);
        int k = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < a.size; j++) {
                if (data[i] == a.data[j]) {
                    tmp.data[k] = data[i];
                    k++;
                    break;
                }
            }
        }
        tmp.size = k;
        return tmp;
    }
};


int main() {
    // 创建两个集合 A 和 B，大小分别为 3 和 2
    stacticset<string, string> A(3);
    stacticset<string, string> B(2);

    // 初始化集合 A 的元素
    A.data[0] = {"apple", "fruit"};
    A.data[1] = {"carrot", "vegetable"};
    A.data[2] = {"banana", "fruit"};

    // 初始化集合 B 的元素
    B.data[0] = {"carrot", "vegetable"};
    B.data[1] = {"pear", "fruit"};

    // 打印集合 A
    cout << "Set A:" << endl;
    for (int i = 0; i < A.size; i++) {
        cout << A.data[i].key << " - " << A.data[i].other << endl;
    }

    // 打印集合 B
    cout << "\nSet B:" << endl;
    for (int i = 0; i < B.size; i++) {
        cout << B.data[i].key << " - " << B.data[i].other << endl;
    }

    // 并集
    auto Union = A + B;
    cout << "\nA + B (Union):" << endl;
    for (int i = 0; i < Union.size; i++) {
        cout << Union.data[i].key << " - " << Union.data[i].other << endl;
    }

    // 差集
    auto Difference = A - B;
    cout << "\nA - B (Difference):" << endl;
    for (int i = 0; i < Difference.size; i++) {
        cout << Difference.data[i].key << " - " << Difference.data[i].other << endl;
    }

    // 交集
    auto Intersection = A * B;
    cout << "\nA * B (Intersection):" << endl;
    for (int i = 0; i < Intersection.size; i++) {
        cout << Intersection.data[i].key << " - " << Intersection.data[i].other << endl;
    }

    return 0;
}


