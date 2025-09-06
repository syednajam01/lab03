#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class doublylinkedlist {
public:
    Node* head;
    Node* tail;

    doublylinkedlist() : head(NULL), tail(NULL) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " <-> ";
            curr = curr->next;
        }
        cout << endl;
    }
};

doublylinkedlist* concatenate(doublylinkedlist* L, doublylinkedlist* M) {
    if (!L->head) return M;   
    if (!M->head) return L;   

    L->tail->next = M->head;
    M->head->prev = L->tail;
    L->tail = M->tail;

    return L;
}

int main() {
    doublylinkedlist* L = new doublylinkedlist();
    doublylinkedlist* M = new doublylinkedlist();

    L->append(1);
    L->append(2);
    L->append(3);

    M->append(4);
    M->append(5);
    M->append(6);

    cout << "list L:" << endl;
    L->display();
    cout << "list M:" << endl;
    M->display();

    L = concatenate(L, M);

    cout << "After concatenation:" << endl;
    L->display();

    return 0;
}
