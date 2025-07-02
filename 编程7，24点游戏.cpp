//要实现24点游戏的算法，我们需要生成所有数字组合和运算符组合，然后评估所有可能的表达式。以下是详细的表达式构造和实现思路：

//### 1. 数字和运算符的组合

//我们使用四个数字 `a, b, c, d` 和基本运算符 `+`, `-`, `*`, `/`。

//### 2. 生成表达式的方式

/*我们可以考虑各种可能的括号组合和运算顺序。以下是可能的表达式结构（使用 `a`, `b`, `c`, `d` 表示数字）：

1. `((a op1 b) op2 c) op3 d`
2. `(a op1 (b op2 c)) op3 d`
3. `(a op1 b) op2 (c op3 d)`
4. `a op1 (b op2 (c op3 d))`
5. `a op1 b op2 c op3 d`（不使用括号）

### 3. C++ 示例代码

下面是实现这些逻辑的 C++ 代码示例：

```cpp*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 计算表达式
double evaluate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : INFINITY; // 避免除以零
        default: return 0;
    }
}

// 检查是否能得到24
bool check24(vector<double>& nums) {
    char ops[] = {'+', '-', '*', '/'};
    int n = nums.size();

    // 遍历所有数字排列
    sort(nums.begin(), nums.end());
    do {
        // 遍历所有运算符组合
        for (size_t i=0;i<=4;++i) { char op1=ops[i];
            for (size_t j=0;j<=4;++j) { char op2=ops[j];
                for (size_t k=0;k<=4;++k) { char op3=ops[k];
                    // 计算所有可能的表达式
                    // 1. ((a op1 b) op2 c) op3 d
                    double res1 = evaluate(evaluate(nums[0], nums[1], op1), nums[2], op2);
                    if (fabs(evaluate(res1, nums[3], op3) - 24) < 1e-6) return true;

                    // 2. (a op1 (b op2 c)) op3 d
                    double res2 = evaluate(nums[1], nums[2], op2);
                    if (fabs(evaluate(nums[0], evaluate(res2, nums[3], op3), op1) - 24) < 1e-6) return true;

                    // 3. (a op1 b) op2 (c op3 d)
                    double res3 = evaluate(nums[2], nums[3], op3);
                    if (fabs(evaluate(nums[0], evaluate(nums[1], res3, op2), op1) - 24) < 1e-6) return true;

                    // 4. a op1 (b op2 (c op3 d))
                    double res4 = evaluate(nums[2], nums[3], op3);
                    if (fabs(evaluate(nums[0], evaluate(nums[1], res4, op2), op1) - 24) < 1e-6) return true;

                    // 5. a op1 b op2 c op3 d (不使用括号)
                    double temp = evaluate(evaluate(nums[0], nums[1], op1), nums[2], op2);
                    if (fabs(evaluate(temp, nums[3], op3) - 24) < 1e-6) return true;
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    return false;
}

int main() { double value;
    vector<double> nums;
    cin>>value;
	while(value>0)
	cin>>value;
	nums.push_back(value);
	 // 示例输入
    if (check24(nums)) {
        cout << "可以得到24点！" << endl;
    } else {
        cout << "无法得到24点。" << endl;
    }
    return 0;
}
//```

/*### 代码解释

1. **evaluate函数**：计算两个数字之间的运算结果。
2. **check24函数**：遍历数字的排列和运算符的组合，计算所有可能的表达式，检查结果是否为24。
3. **主函数**：提供四个数字并调用 `check24` 函数。

### 注意事项

- 本代码仅涵盖基本情况，可以根据需求扩展更多的组合和处理逻辑。
- 可能需要调整精度检查的阈值（`1e-6`）以确保准确性。*/
