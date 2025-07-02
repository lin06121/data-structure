#include<iostream>
using namespace std;

template<class T>
class list {
public:
    struct node {
        T data;
        node* next;
        node(const T& x, node* n = nullptr) : data(x), next(n) {}
        node() : next(nullptr) {}
    };

    node* head;

    list() {
        head = new node;
    }

    void traverse() const {
        node* p = head->next;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void reverse() {
        if (head->next == nullptr || head->next->next == nullptr) return;

        node* prev = nullptr;
        node* curr = head->next;
        node* nextNode;

        while (curr != nullptr) {
            nextNode = curr->next;  // Save next node
            curr->next = prev;      // Reverse current node's pointer
            prev = curr;            // Move prev and curr one step forward
            curr = nextNode;
        }
        head->next = prev;  // Set the new head
    }
};

int main() {
    list<int> lst;

    // Add some test data to the list (for example purposes)
    lst.head->next = new list<int>::node(1);
    lst.head->next->next = new list<int>::node(2);
    lst.head->next->next->next = new list<int>::node(3);
    lst.head->next->next->next->next = new list<int>::node(4);

    cout << "Original list: ";
    lst.traverse();

    lst.reverse();

    cout << "Reversed list: ";
    lst.traverse();

    return 0;
}

