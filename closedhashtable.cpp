//
// Created by 玉林 on 25-4-29.
//

#include<iostream>
#include "closedhashtable.h"

using namespace std;

int main() {
    // 创建一个闭散列哈希表
    closedhashtable<int, string> ht(5); // 超过5次删除后rehash

    // 插入一些元素
    ht.insert({1, "one"});
    ht.insert({2, "two"});
    ht.insert({3, "three"});
    ht.insert({4, "four"});

    // 查找元素
    auto res = ht.find(3);
    if (res != nullptr) cout << "Find key 3: " << res->other << endl;
    else cout << "Key 3 not found" << endl;

    // 删除一个元素
    ht.remove(2);
    res = ht.find(2);
    if (res != nullptr) cout << "Find key 2: " << res->other << endl;
    else cout << "Key 2 not found" << endl;

    // 再插入一个新元素
    ht.insert({5, "five"});
    res = ht.find(5);
    if (res != nullptr) cout << "Find key 5: " << res->other << endl;
    else cout << "Key 5 not found" << endl;

    // 连续删除测试触发rehash
    ht.remove(1);
    ht.remove(3);
    ht.remove(4);
    ht.remove(5);

    cout << "Test completed!" << endl;

    return 0;
}
