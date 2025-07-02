#include <iostream>
#include <vector>
#include <map>

int countPairsWithDifferenceOne(const std::vector<int>& nums) {
    std::map<int, int> numCount;
    for (int i = 0; i < nums.size(); i++) {
        numCount[nums[i]]++;
    }

    int count = 0;
    for (std::map<int, int>::iterator it = numCount.begin(); it != numCount.end(); ++it) {
        int num = it->first;
        // 只计算(num, num+1)的对
        if (numCount.count(num + 1)) {
            count++;
        }
    }

    return count; // 返回相差1的数对数量
}

int main() {
    int n;
    std::cout << "请输入整数的数量: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "请输入 " << n << " 个整数: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int result = countPairsWithDifferenceOne(nums);
    std::cout << "相差1的数对数量为: " << result << std::endl;

    return 0;
}

