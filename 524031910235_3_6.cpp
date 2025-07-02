#include<iostream>
#include "524031910235_3_6_1_H_INCLUDED"
using namespace std;
template <class T>
class stack
{
public:
    struct node{
    T data;
    node *next;
    node(const T &x,node *N=NULL)
    {
        data=x; next=N;
    }
    node():next(NULL){}
    ~node(){}
    };
    node *top;
    stack()
    {
        top=NULL;
    }
    ~stack()
    {
        node *temp;
        while(temp!=NULL)
        {
            temp=top;
            top=top->next;
            delete temp;
        }
    }
    bool isempty() const
    {
        return top==NULL;
    }
    void push(const T &x)
    {
        top=new node(x,top);
    }
    T pop()
    {
        node* tmp=top;
        top=top->next;
        T x=tmp->data;
        delete tmp;
        return x;
    }
    T topx() const
    {
        return top->data;
    }

};
