//
// Created by 玉林 on 25-5-30.
//
#include <iostream>
#include <vector>
using namespace std;

// 完整的Graph类实现
template<class TypeofVer, class TypeofNode>
class Graph {
public:
    struct edgeNode {
        int end;                    // 边的终点
        TypeofNode weight;          // 边的权重
        edgeNode* next;            // 下一条边

        edgeNode(int e, TypeofNode w) : end(e), weight(w), next(nullptr) {}
    };

    struct verNode {
        TypeofVer data;            // 顶点数据
        edgeNode* head;            // 邻接表头指针

        verNode() : head(nullptr) {}
        verNode(TypeofVer d) : data(d), head(nullptr) {}
    };

    verNode* verlist;              // 顶点数组
    int vers;                      // 顶点数量

public:
    // 构造函数
    Graph(int n, TypeofVer d[]) : vers(n) {
        verlist = new verNode[vers];
        for(int i = 0; i < vers; i++) {
            verlist[i].data = d[i];
            verlist[i].head = nullptr;
        }
    }

    // 析构函数
    ~Graph() {
        for(int i = 0; i < vers; i++) {
            edgeNode* p = verlist[i].head;
            while(p != nullptr) {
                edgeNode* temp = p;
                p = p->next;
                delete temp;
            }
        }
        delete[] verlist;
    }

    // 查找顶点索引
    int find(TypeofVer vertex) {
        for(int i = 0; i < vers; i++) {
            if(verlist[i].data == vertex) {
                return i;
            }
        }
        return -1;
    }

    // 插入边
    void insert(TypeofVer v1, TypeofVer v2, TypeofNode weight) {
        int i = find(v1);
        int j = find(v2);

        if(i == -1 || j == -1) {
            cout << "错误：顶点不存在！" << endl;
            return;
        }

        // 在顶点i的邻接表中添加边到顶点j
        edgeNode* newEdge = new edgeNode(j, weight);
        newEdge->next = verlist[i].head;
        verlist[i].head = newEdge;
    }

    // 重载版本：直接用索引插入
    void insert(int i, int j, TypeofNode weight) {
        if(i < 0 || i >= vers || j < 0 || j >= vers) {
            cout << "错误：索引超出范围！" << endl;
            return;
        }

        edgeNode* newEdge = new edgeNode(j, weight);
        newEdge->next = verlist[i].head;
        verlist[i].head = newEdge;
    }

    // 打印图
    void printGraph() {
        cout << "图的邻接表表示:" << endl;
        for(int i = 0; i < vers; i++) {
            cout << "顶点 " << i << "(" << verlist[i].data << "): ";
            edgeNode* p = verlist[i].head;
            while(p != nullptr) {
                cout << "-> " << p->end << "(权重:" << p->weight << ") ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

// 自顶而下动态规划 + 反转链表
int *maxTimes;        // 备忘录：从起点到每个节点的最长时间
int *predecessor;     // 备忘录：记录前驱节点
bool *computed;       // 标记是否已计算

template<class TypeofVer, class TypeofNode>
struct ReversedGraph {
    vector<vector<pair<int, int>>> adjList;  // 反转后的邻接表
    int vertices;

    ReversedGraph(Graph<TypeofVer, TypeofNode> &original) {
        vertices = original.vers;
        adjList.resize(vertices);

        // 反转原图的所有边
        for(int i = 0; i < vertices; i++) {
            typename Graph<TypeofVer, TypeofNode>::edgeNode* p = original.verlist[i].head;
            while(p != nullptr) {
                adjList[p->end].push_back({i, p->weight});
                p = p->next;
            }
        }
    }

    void printReversedGraph() {
        cout << "\n反转图的邻接表:" << endl;
        for(int i = 0; i < vertices; i++) {
            cout << "顶点 " << i << ": ";
            for(auto& edge : adjList[i]) {
                cout << "<- " << edge.first << "(权重:" << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

template<class TypeofVer, class TypeofNode>
int dpMaxTime(ReversedGraph<TypeofVer, TypeofNode> &reversedGraph, int node, int startNode)
{
    if(computed[node]) return maxTimes[node];

    if(node == startNode) {
        maxTimes[node] = 0;
        predecessor[node] = -1;
        computed[node] = true;
        return 0;
    }

    int maxVal = -1;
    int bestPred = -1;

    for(auto& edge : reversedGraph.adjList[node]) {
        int predNode = edge.first;
        int weight = edge.second;

        int predTime = dpMaxTime(reversedGraph, predNode, startNode);
        if(predTime >= 0) {
            int currentTime = predTime + weight;
            if(currentTime > maxVal) {
                maxVal = currentTime;
                bestPred = predNode;
            }
        }
    }

    maxTimes[node] = maxVal;
    predecessor[node] = bestPred;
    computed[node] = true;

    return maxVal;
}

template<class TypeofVer, class TypeofNode>
void findCriticalPath(Graph<TypeofVer, TypeofNode> &graph)
{
    cout << "=== AOE网络关键路径分析 ===" << endl;
    graph.printGraph();

    // 找入度为0的节点
    vector<bool> hasIncoming(graph.vers, false);

    for(int i = 0; i < graph.vers; i++) {
        typename Graph<TypeofVer, TypeofNode>::edgeNode* p = graph.verlist[i].head;
        while(p != nullptr) {
            hasIncoming[p->end] = true;
            p = p->next;
        }
    }

    int startNode = -1;
    cout << "\n入度分析: ";
    for(int i = 0; i < graph.vers; i++) {
        if(!hasIncoming[i]) {
            cout << "节点" << i << "(无入度) ";
            if(startNode == -1) startNode = i;
        } else {
            cout << "节点" << i << "(有入度) ";
        }
    }
    cout << endl;

    if(startNode == -1) {
        cout << "错误：图中存在环或没有起始节点！" << endl;
        return;
    }

    cout << "选择起始节点: " << startNode << endl;

    // 创建反转图
    ReversedGraph<TypeofVer, TypeofNode> reversedGraph(graph);
    reversedGraph.printReversedGraph();

    // 初始化备忘录
    maxTimes = new int[graph.vers];
    predecessor = new int[graph.vers];
    computed = new bool[graph.vers];

    for(int i = 0; i < graph.vers; i++) {
        computed[i] = false;
        maxTimes[i] = -1;
        predecessor[i] = -1;
    }

    // 计算所有节点的最长路径
    int maxProjectTime = 0;
    int criticalEndNode = startNode;

    cout << "\n=== 动态规划计算结果 ===" << endl;
    for(int i = 0; i < graph.vers; i++) {
        int time = dpMaxTime(reversedGraph, i, startNode);
        cout << "从起点到节点 " << i << " 的最长路径时间: ";
        if(time >= 0) {
            cout << time << endl;
            if(time > maxProjectTime) {
                maxProjectTime = time;
                criticalEndNode = i;
            }
        } else {
            cout << "不可达" << endl;
        }
    }

    cout << "\n=== 关键路径分析结果 ===" << endl;
    cout << "项目完成时间: " << maxProjectTime << endl;
    cout << "关键路径终点: 节点" << criticalEndNode << endl;
    cout << "关键路径: ";

    // 重构关键路径
    vector<int> path;
    int current = criticalEndNode;

    while(current != -1) {
        path.push_back(current);
        current = predecessor[current];
    }

    // 输出路径
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if(i > 0) cout << " -> ";
    }
    cout << " (总时间: " << maxProjectTime << ")" << endl;

    // 清理内存
    delete[] maxTimes;
    delete[] predecessor;
    delete[] computed;
}

int main()
{
    cout << "构建AOE网络图..." << endl;

    // 使用字符作为顶点标识
    char vertices[] = {'a', 'b', 'c', 'd', 'e'};
    Graph<char, int> graph(5, vertices);

    // 添加边 (使用字符)
    graph.insert('a', 'b', 2);  // a -> b (2)
    graph.insert('a', 'c', 4);  // a -> c (4)
    graph.insert('b', 'd', 5);  // b -> d (5)
    graph.insert('b', 'e', 1);  // b -> e (1)
    graph.insert('c', 'd', 3);  // c -> d (3)

    cout << "图构建完成！开始关键路径分析...\n" << endl;

    findCriticalPath(graph);

    cout << "\n程序执行完成！" << endl;
    return 0;
}