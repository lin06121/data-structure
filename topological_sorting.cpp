//
// Created by 玉林 on 25-5-29.
//
#include<iostream>
#include"Graph.h"
using namespace std;

template<class TypeofVer, class TypeofNode>
void topologicalSort(Graph<TypeofVer, TypeofNode> &graph) {
  queue<int> q;
  typename Graph<TypeofVer, TypeofNode>::edgeNode* p;
  int current;

  // 初始化入度数组和深度数组
  int *degrees = new int[graph.vers];
  int *depths = new int[graph.vers];
  for (int i = 0; i < graph.vers; i++) {
    degrees[i] = 0;
    depths[i] = 0;
  }

  // 计算每个节点的入度
  for (int i = 0; i < graph.vers; i++) {
    for (p = graph.verlist[i].head; p != nullptr; p = p->next) {
      ++degrees[p->end];
    }
  }

  // 将入度为 0 的节点入队
  for (int i = 0; i < graph.vers; i++) {
    if (degrees[i] == 0) {
      q.push(i);
      depths[i] = 0;  // 深度为 0
    }
  }

  // 拓扑排序并计算深度
  while (!q.empty()) {
    current = q.front();
    q.pop();

    for (p = graph.verlist[current].head; p != nullptr; p = p->next) {
      // 更新邻接节点的深度，确保深度是最大的
      depths[p->end] = max(depths[p->end], depths[current] + 1);

      // 如果该节点的入度减为 0，加入队列
      if (--degrees[p->end] == 0) {
        q.push(p->end);
      }
    }
  }

  // 计算图的最大深度
  int maxdepth = 0;
  for (int i = 0; i < graph.vers; i++) {
    if (depths[i] > maxdepth) {
      maxdepth = depths[i];
    }
  }

  // 输出最大学期长度（即最大深度）
  cout << "Maximum length of semester: " << maxdepth + 1 << endl;

  // 按学期（深度）输出课程
  for (int i = 0; i <= maxdepth; i++) {
    cout << "Semester " << i << ": ";
    for (int j = 0; j < graph.vers; j++) {
      if (depths[j] == i) {
        cout << graph.verlist[j].ver << " ";
      }
    }
    cout << endl;
  }


  delete[] degrees;
  delete[] depths;
}




int main() {
  char d[]={'a','b','c','d','e'};
  Graph<char, int> graph(5,d);



  // 添加边
  graph.insert('a', 'b',0);  // A -> B
  graph.insert('a', 'c',0);  // A -> C
  graph.insert('b', 'd',0);  // B -> D
  graph.insert('b', 'e',0);  // B -> E

  // 计算拓扑排序的深度并输出
  topologicalSort(graph);

  return 0;
}