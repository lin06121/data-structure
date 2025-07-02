#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "请输入一个整数: ";
    std::cin >> n;

    n = n < 0 ? -n : n; // 处理负数
    std::vector<int> digits;

    while (n > 0) {
        digits.push_back(n % 10); // 获取最后一位
        n /= 10; // 去掉最后一位
    }

    // 反转并输出各位数
    for (size_t i = digits.size(); i > 0; --i) {
        std::cout << digits[i - 1] << " "; // 输出各位数
    }

    std::cout << std::endl;
    return 0;
}

