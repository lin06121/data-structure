þÿ        node* next;
        node(const T& x, node* n = nullptr) : data(x), next(n) {}
        node() : next(nullptr) {}
    };

    node* head;

    list() {
        head = new node;
    }
    
    list(const list &a) { 
        head = new node;
        node *p = a.head->next;
        node* q = head;
        while (p != nullptr) {
            q->next = new node(p->data);
            p = p->next;
            q = q->next; 
        }
    }

    void traverse() const {
        node* p = head->next;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    
    friend list operator+(const list &a, const list &b) {
        list c;
        node *tail = c.head;
        
        // ´¦ÀíµÿýöÁ´±í
        node *p = a.head->next;
        while (p != nullptr) {
            tail->next = new node(p->data);
            tail = tail->next;
            p = p->next;
        }
        
        // ´¦ÀíµÿýöÁ´±í
        p = b.head->next;
        while (p != nullptr) {
            tail->next = new node(p->data);
            tail = tail->next;
            p = p->next;
        }
        
        return c;
    }
};

int main() {
    list<int> list1;
    list1.head->next = new list<int>::node(1);
    list1.head->next->next = new list<int>::node(2);
    
    list<int> list2;
    list2.head->next = new list<int>::node(3);
    list2.head->next->next = new list<int>::node(4);
    
    list<int> list3 = list1 + list2;
    list3.traverse(); // Êä³ö£º1 2 3 4
    
    return 0;
}

