#include<iostream>
using namespace std;
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    double num;
    cout << "请输入一个浮点数: ";
    cin >> num;

    // 将数字转换为字符串，方便逐位处理
    string numStr = to_string(num);

    double result = 0.0;

    // 处理整数部分和小数部分
    int integerPart = static_cast<int>(num);
    double fractionalPart = num - integerPart;

    // 处理整数部分的各位数字
    int temp = integerPart;
    int position = 0;
    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;

        // 根据位数计算对应的权重
        if (position == 0) { // 个位
            result += digit * 0.005; // 1x0.5%
        } else if (position == 1) { // 十位
            result += digit * 0.01; // 10x0.1%
        } else if (position == 2) { // 百位
            result += digit * 0.1; // 100x0.1%
        } else if (position == 3) { // 千位
            result += digit * 1; // 1000x0.1%
        } else if (position == 4) { // 万位
            result += digit * 10; // 10000x0.1%
        }
        position++;
    }

    // 处理小数部分的各位数字
    string fractionalStr = numStr.substr(numStr.find('.') + 1);
    for (int i = 0; i < fractionalStr.length(); i++) {
        int digit = fractionalStr[i] - '0';

        // 根据小数点后的位数计算对应的权重
        if (i == 0) { // 十分位
            result += digit * 0.002+0.02; // 0.1x2%
        } 
    }

    cout << "计算结果: " << result << endl;

    return 0;
}
