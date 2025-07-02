#ifndef Huffmancode_h
#define Huffmancode_h

#include <iostream>
#include <queue>
#include <map>
#include <string>
#include "Binarytree.h"

// Huffman节点定义
struct HuffmanNode {
    int freq;                             // 频率
    char character;                       // 字符
    Bitreenode<int>* treeNode;            // 对应的二叉树节点

    // 构造函数
    HuffmanNode(int frequency, char ch, Bitreenode<int>* node)
        : freq(frequency), character(ch), treeNode(node) {}

    // 定义优先队列的比较器（频率小的优先）
    bool operator>(const HuffmanNode& other) const {
        return freq > other.freq;
    }
};

// HuffmanTree类
class HuffmanTree {
private:
    Bitree<int>* huffmanTree;                         // Huffman树
    std::map<char, std::string> huffmanTable;         // Huffman编码表

    // 构建Huffman编码表（递归）
    void buildTable(Bitreenode<int>* node, const std::string& code) {
        if (!node) return;

        // 如果是叶子节点，将字符和编码加入表
        if (!node->left && !node->right) {
            huffmanTable[static_cast<char>(node->data)] = code;
            return;
        }

        // 左子树对应"0"，右子树对应"1"
        buildTable(node->left, code + "0");
        buildTable(node->right, code + "1");
    }

public:
    // 构造函数
    HuffmanTree() : huffmanTree(nullptr) {}

    // 析构函数
    ~HuffmanTree() {
        if (huffmanTree) delete huffmanTree;
    }

    // 构建Huffman树
    void buildHuffmanTree(const std::map<char, int>& frequencies) {
        // 定义小根堆优先队列
        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, std::greater<HuffmanNode>> pq;

        // 初始化优先队列
        for (std::map<char, int>::const_iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
            char character = it->first;
            int freq = it->second;
            Bitreenode<int>* node = new Bitreenode<int>(character);
            pq.push(HuffmanNode(freq, character, node));
        }

        // 合并节点直到只剩下一个节点
        while (pq.size() > 1) {
            HuffmanNode left = pq.top(); pq.pop();
            HuffmanNode right = pq.top(); pq.pop();

            int combinedFreq = left.freq + right.freq;

            // 合并两棵树
            Bitree<int>* leftTree = new Bitree<int>();
            Bitree<int>* rightTree = new Bitree<int>();
            leftTree->getBitreeroot() = left.treeNode;
            rightTree->getBitreeroot() = right.treeNode;

            Bitree<int>* mergedTree = Bitree<int>::merge(leftTree, rightTree, combinedFreq);

            // 将合并后的树的根节点重新入队
            pq.push(HuffmanNode(combinedFreq, '\0', mergedTree->getBitreeroot()));

            // 删除临时树，避免内存泄漏
            delete leftTree;
            delete rightTree;
        }

        // 最终的Huffman树
        huffmanTree = new Bitree<int>();
        huffmanTree->getBitreeroot() = pq.top().treeNode;
    }

    // 获取Huffman编码表
    std::map<char, std::string> getHuffmanTable() {
        huffmanTable.clear();
        if (huffmanTree && huffmanTree->getBitreeroot()) {
            buildTable(huffmanTree->getBitreeroot(), "");
        }
        return huffmanTable;
    }

    // 打印Huffman编码表
    void printHuffmanTable() {
        for (std::map<char, std::string>::iterator it = huffmanTable.begin(); it != huffmanTable.end(); ++it) {
            char character = it->first;
            std::string code = it->second;
            std::cout << character << ": " << code << std::endl;
        }
    }
};

#endif

