#include <climits>

int reverse(int x) {
    long long reversed = 0; // 使用long long来避免溢出

    while (x != 0) {
        reversed = reversed * 10 + x % 10; // 取末尾数字
        x /= 10; // 去掉末尾数字

        // 检查是否溢出
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
    }
    
    return static_cast<int>(reversed);
}

