#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x) : data(x), next(nullptr){}
};

void append(Node* &head, int value){
    Node* newnode = new Node (value);

    if (head == nullptr){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

void sort(Node*& head) {
    if (!head || !head->next) return;

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) {
            if (!evenHead)evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (!oddHead) oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    if (evenHead) {
        head = evenHead;
        evenTail->next = oddHead;
    } else head = oddHead;

    if (oddTail) oddTail->next = nullptr;
}

void printlist(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

void freelist(Node* head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl << "FREEEED" << endl ;
}

int main() {

    Node* head = nullptr;
    append(head, 9);
    append(head, 2);
    append(head, 8);
    append(head, 1);
    append(head, 7);
    append(head, 3);
    append(head, 6);
    append(head, 4);
    append(head, 5);

    printlist(head);

    sort(head);

    printlist(head);

    freelist(head);
    
    return 0;
}