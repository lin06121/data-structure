//
// Created by 玉林 on 25-3-8.
//
#include <iostream>
#include <cstring>  // for memset()
#include "stack.h"
using namespace std;
int a[1000][1000];

int A1(int n, int m, int a[][1000]) {


    if (a[m][n] != -1) return a[m][n];  // 记忆化搜索

    if (m == 0) {
        a[m][n] = n + 1;
    } else if (m != 0 && n == 0) {
        a[m][n] = A1(1, m - 1, a);
    } else {
        a[m][n] = A1(A1(n - 1, m, a), m - 1, a);
    }
    return a[m][n];
}

int A2(int m, int n) {
    stack<int> answer;
    answer.push(m);
    answer.push(n);

    while (!answer.isempty()) {  // 修复 while 条件
        n = answer.pop();
        if (answer.isempty()) return n;
        m = answer.pop();

        if (m == 0) {
            answer.push(n + 1);
        } else if (n == 0) {
            answer.push(m - 1);
            answer.push(1);
        } else {
            answer.push(m - 1);
            answer.push(m);
            answer.push(n - 1);
        }
    }
    return -1;
}

int main() {
    int m, n;
    cout << "Please input m, n: ";
    cin >> m >> n;

    memset(a, -1, sizeof(a));  // 初始化数组

    cout << "Recursive A1(" << m << ", " << n << ") = " << A1(n, m, a) << "\n";
    cout << "Non-recursive A2(" << m << ", " << n << ") = " << A2(m, n) << "\n";

    return 0;
}
