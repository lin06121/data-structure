#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
template <class T>
class stack
{
public:
    struct node{
    T data;
    node *next;
    node(const T &x,node *N=nullptr )
    {
        data=x; next=N;
    }
    node():next(nullptr ){}
    ~node(){}
    };
    node *top;
    stack()
    {
        top=nullptr ;
    }
    ~stack()
    {
        node *temp=top ;
        while(temp!= nullptr)
        {
            temp=top;
            top=top->next;
            delete temp;
        }
    }
    bool isempty() const
    {
        return top== nullptr;
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



#endif // STACK_H_INCLUDED
