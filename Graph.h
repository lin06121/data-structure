//
// Created by 玉林 on 25-5-29.
//

#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<queue>
using namespace std;
template <class TypeofVer, class TypeofEdge>
class Graph {
  public:
    int vers, edges;

    struct edgeNode
    {
      int end;
      TypeofEdge weight;
      edgeNode *next;
      edgeNode(int e, TypeofEdge w,edgeNode* n=nullptr) : end(e), weight(w), next(n) {}
    };

    struct verNode
    { TypeofVer ver;
      edgeNode *head;
      verNode( edgeNode *n=nullptr) : head(n) {}
      };

   verNode *verlist;
    int find(TypeofVer v) {
        for(int i=0; i<vers; ++i)
            if (verlist[i].ver == v) return i;
        return -1;
    }
   Graph(int vsize, const TypeofVer d[])
   {vers = vsize; verlist = new verNode[vers];
     edges=0;
     for(int i=0;i<vers;++i)
       verlist[i].ver = d[i];}

   ~Graph()
   { int i;
     edgeNode *p;
     for(i=0;i<vers;++i)
       while((p=verlist[i].head)!=nullptr)
         { verlist[i].head=p->next;
         delete p;}
     delete [] verlist;}

   void insert(TypeofVer x,TypeofVer y, TypeofEdge w)
   { int i = find(x);
     int j = find(y);
     verlist[i].head=new edgeNode(j,w,verlist[i].head);
     ++edges;}

   void remove(TypeofVer x,TypeofVer y, TypeofEdge w)
   { int i = find(x);

   int j = find(y);
   edgeNode *p=verlist[i].head,*q;
   if(p==nullptr) return;
   if(p->end==j) {
     verlist[i].head=p->next;
     delete p;
   --edges;
   return;}
   while(p->next!=nullptr&&p->next->end!=j) p=p->next;
   if(p->next!=nullptr)
     { q=p->next;
     p->next=q->next;
     delete q;
     --edges;}
   }

   bool exist(TypeofVer x,TypeofVer y)
   { int i = find(x);
   int j = find(y);
   edgeNode *p=verlist[i].head;
   while(p!=nullptr&&p->end!=j)
     { p=p->next;}
   if(p==nullptr) return false;
   else return true;

   }



    void find_m_length_simple_path(TypeofVer start, int m, queue<verNode*> tmp, bool visited[])
    {
        int i = find(start);
        if (i == -1) return;


        visited[i] = true;
        tmp.push(&verlist[i]);

        if (m == 0) {

            queue<verNode*> temp_queue = tmp;
            while (!temp_queue.empty()) {
                verNode* p = temp_queue.front();
                temp_queue.pop();
                cout << p->ver;
                if (!temp_queue.empty()) cout << " -> ";
            }
            cout << endl;


        } else {

            edgeNode* s = verlist[i].head;
            while (s != nullptr) {
                if (!visited[s->end]) {
                    find_m_length_simple_path(verlist[s->end].ver, m - 1, tmp, visited);
                }
                s = s->next;
            }
            //visited[i] = false;
            //tmp.pop();why is not here to backwards?
        }


        visited[i] = false;
        tmp.pop();
    }


    void find_m_length_simple_path(TypeofVer start, int m)
    {
        bool* visited = new bool[vers];
        for (int i = 0; i < vers; ++i) visited[i] = false;
        queue<verNode*> tmp;

        find_m_length_simple_path(start, m, tmp, visited);

        delete[] visited;
    }


   };





#endif //GRAPH_H
