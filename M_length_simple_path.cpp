//
// Created by 玉林 on 25-5-30.
//
#include "graph.h"
#include <iostream>
using namespace std;

int main() {


    char vertices[] = {'A', 'B', 'C', 'D', 'E'};
    Graph<char, int> g1(5, vertices);

    // 1.创建图
    g1.insert('A', 'B', 1);
    g1.insert('B', 'C', 1);
    g1.insert('A', 'D', 1);
    g1.insert('D', 'E', 1);
    g1.insert('B', 'D', 1);


    cout << "Paths of length 2 from A:" << endl;
    g1.find_m_length_simple_path('A', 2);

    cout << "Paths of length 1 from B:" << endl;
    g1.find_m_length_simple_path('B', 1);


    int int_vertices[] = {0, 1, 2, 3, 4};
    Graph<int, int> g2(5, int_vertices);

    // 2.创建图: 0->1->2->0,  0->3->4
    g2.insert(0, 1, 10);
    g2.insert(1, 2, 20);
    g2.insert(2, 0, 30);
    g2.insert(0, 3, 40);
    g2.insert(3, 4, 50);

    cout << "0->1, 1->2, 2->0, 0->3, 3->4" << endl;
    cout << "Paths of length 2 from 0:" << endl;
    g2.find_m_length_simple_path(0, 2);

    cout << "Paths of length 3 from 0(should find no paths):" << endl;
    g2.find_m_length_simple_path(0, 3);

    // 3.边界情况
    cout << "Path of length 0 from A (should print just A):" << endl;
    g1.find_m_length_simple_path('A', 0);

    cout << "Path of length 5 from A (should find no paths):" << endl;
    g1.find_m_length_simple_path('A', 5);


    return 0;
}

