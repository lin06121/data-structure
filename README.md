# data-structure（上交数据结构课程作业整理）

本仓库是 **上海交通大学数据结构课程** 的作业与学习记录，主要使用 **C++**。
当前以“保留原始作业文件”为主：大量 `.cpp/.h` 源码与输入/结果文件仍在仓库根目录，另包含部分与数据结构主线无关的资料。

> 说明：本次以“可浏览、可学习、尽量不改动原始代码”为目标进行整理说明；**未删除任何已有源码/输入/结果文件**。

## 1. 仓库结构概览（现状）

```text
.
├─ *.cpp / *.h                    # 大部分课程作业源码（当前主要在根目录）
├─ coderforces/                   # Codeforces 练习
│  ├─ ganster.cpp
│  ├─ Modular_Sorting.cpp
│  └─  Palindromic String.cpp
├─ ESP32单片机学习资料/            # 与数据结构主线无关的单片机资料
├─ .idea/                         # IDE 工程配置
├─ Dev-Cpp 5.11 TDM-GCC 4.9.2 Setup.exe
├─ Result.txt / pascalcode.txt / All_W.txt
└─ CMakeLists.txt                 # 当前为空文件
```

## 2. 按主题分类的文件索引（基于现有文件）

> 以下均为仓库中已存在文件；为避免破坏历史作业与相对路径依赖，本次不强制搬移源码。

| 主题 | 关键文件（现有路径） | 说明 |
|---|---|---|
| 栈与队列 | `stack.h`, `STACK_H.h`, `stack1.cpp`, `ackermanstack.cpp`, `Queue.h`, `simulatequeuemath.cpp`, `simulaterQueue.cpp`, `simulaterqueue2.cpp`, `check1.cpp`, `csh.cpp` | 栈/队列实现与模拟题（含 Ackermann 栈模拟、排队模拟等） |
| 二叉树 / 二叉搜索树 | `Binarytree.h`, `binarytree1.h`, `Traverse.h`, `binarytree_exercise1.cpp`, `binarytree_exercise2.cpp`, `binarytree_exercise3.cpp`, `binarysearchtree.h`, `binarysearchtree_exercise1.cpp`, `binarysearchtree_exercise2.cpp`, `binarysearchtree_exercise3.cpp`, `未命名2.cpp` | 二叉树与 BST 的实现和练习 |
| 堆 | `minheap.h`, `minheap_exercise2.cpp`, `minheap_exercise_kth_min1.cpp`, `k_th_max.cpp` | 最小堆与第 k 小/大相关练习 |
| 哈希表 | `closedhashtable.h`, `closedhashtable.cpp` | 闭散列哈希表实现与使用 |
| 图 | `Graph.h`, `M_length_simple_path.cpp` | 图结构与路径相关练习 |
| 拓扑排序 / 最短路径 | `topological_sorting.cpp`, `topological_sorting2.cpp`, `编程17最短路径.cpp` | 拓扑排序和最短路径题目 |
| Huffman 编码 | `Huffmancode.h` | Huffman 树/编码实现 |
| 排序与字符串算法 | `编程13 排序.cpp`, `编程20字符排序.cpp`, `编程22 排序.cpp`, `编程19 最大回文.cpp`, `编程21 字符匹配.cpp`, `checkpascalcode.cpp`, `deleteDuplicate.cpp` | 排序、回文、字符匹配等 |
| 综合编程题 | `编程.cpp`, `编程2.cpp`, `编程4.cpp`, `编程5.cpp`, `编程5 n!求和.cpp`, `编程6全排列.cpp`, `编程7，24点游戏.cpp`, `编程8 素数和.cpp`, `编程10 数对.cpp`, `编程11逆转数字.cpp`, `编程12位数.cpp`, `编程14滑动窗口.cpp`, `编程15统计字母.cpp`, `编程16顺时针.cpp`, `编程18 maxmin.cpp`, `524031910235_1_6.cpp`, `524031910235_1_7.cpp`, `524031910235_3_6.cpp`, `524031910235_3_6_1.h`, `test.cpp` | 课程编程练习与编号作业 |
| Codeforces 练习 | `coderforces/ganster.cpp`, `coderforces/Modular_Sorting.cpp`, `coderforces/ Palindromic String.cpp` | 竞赛/练习题 |
| 其他资料（非数据结构主线） | `ESP32单片机学习资料/`, `.idea/`, `Dev-Cpp 5.11 TDM-GCC 4.9.2 Setup.exe`, `SymmetricPeakModel.FDF`, `线代作业.cpp`, `神经网络1.cpp`, `矩阵det.cpp`, `取整.cpp`, `未命名1.cpp`, `stacticset.cpp`, `evolution.cpp` | 建议与数据结构作业分开管理；当前保留原状 |

## 3. 待整理/命名含糊文件

以下文件名语义不够明确，或可能是阶段性草稿；为避免误判，本次不重命名不迁移：

- `未命名1.cpp`
- `未命名2.cpp`
- `524031910235_1_6.cpp`
- `524031910235_1_7.cpp`
- `524031910235_3_6.cpp`
- `test.cpp`

## 4. 编译与运行（g++ 单文件）

多数练习可按单文件编译：

```bash
g++ -std=c++11 文件名.cpp -o 程序名
./程序名
```

示例：

```bash
g++ -std=c++11 binarytree_exercise1.cpp -o binarytree_exercise1
./binarytree_exercise1
```

注意事项：

1. 部分文件依赖同目录头文件（如 `binarysearchtree.h`, `Binarytree.h`, `Queue.h`）。
2. 部分程序依赖输入文件（如 `pascalcode.txt`）或默认标准输入格式。
3. 个别文件依赖特定平台/环境（如 `topological_sorting2.cpp` 引入 `windows.h`，`线代作业.cpp` 依赖 `Eigen/Dense`）。
4. `CMakeLists.txt` 当前为空，暂无可直接复用的完整 CMake 构建流程。

## 5. 编译产物说明

仓库当前包含较多历史编译产物，例如：

- `*.exe`
- `*.o`
- `*.gch`

这些通常不是源码本体，建议后续逐步清理历史产物并通过 `.gitignore` 持续忽略。

## 6. 维护建议（最小干预）

1. 先保持源码不改名：优先补文档、补忽略规则，再做分目录迁移。
2. 若后续迁移目录，建议按主题新建目录（如 `tree/`, `graph/`, `heap/`, `hash/`, `problems/`），每次少量迁移并验证 include/输入路径。
3. 为每类题补一份最小可复现输入输出说明（可放在对应目录 README）。
4. 对明显是编译缓存/IDE 缓存的文件做清理，保留源码与题目数据。

## 7. 建议学习路线

1. 栈与队列（`stack.h`, `Queue.h`, `simulate*.cpp`）
2. 二叉树与遍历（`Binarytree.h`, `binarytree_exercise*.cpp`, `Traverse.h`）
3. 二叉搜索树（`binarysearchtree.h`, `binarysearchtree_exercise*.cpp`）
4. 堆与优先队列（`minheap.h`, `minheap_exercise*.cpp`）
5. 哈希表（`closedhashtable.*`）
6. 图与拓扑排序/最短路径（`Graph.h`, `topological_sorting*.cpp`, `编程17最短路径.cpp`）
7. Huffman 编码（`Huffmancode.h`）
8. 排序与字符串专题（`编程13/19/20/21/22` 等）
9. 综合题与竞赛题（`编程*.cpp`, `coderforces/*.cpp`）

---
如需继续做“分目录迁移版”整理，建议先小步迁移一类文件并逐步编译验证，避免一次性重构带来路径/环境问题。
