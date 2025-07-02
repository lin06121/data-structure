#include <iostream>
#include "STACK_H.h"

int main() {
    stack<int> s1(10);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1;

    stack<int> s2 = s1;
    s2.push(4);

    cout << (s1 == s2 ? "Stacks are equal" : "Stacks are not equal") << endl;

    return 0;
}
