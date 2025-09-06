#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};

void insertatfront(Node* &head, int value){
    Node* newnode = new Node (value);

    if (!head) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void insertatend(Node* &head, int value){
    Node* newnode = new Node (value);

    if (head == nullptr){
        newnode->next = newnode;
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void insertatpos(Node* &head, int pos, int value) {
    if (pos <= 0) return;

    Node* newnode = new Node(value);
    if (!head) {
        if (pos == 1) {
            newnode->next = newnode;
            head = newnode;
        } else {
            delete newnode;
        }
        return;
    }

    Node* tail = head;
    while (tail->next != head) tail = tail->next;

    if (pos == 1) {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletethis(Node* &head, int x) {
    if (!head) return;

    Node* temp = head, *prev = nullptr;
    Node* tail = head;

    while (tail->next != head) tail = tail->next;

    // single node case
    if (head == head->next && head->data == x) {
        delete head;
        head = nullptr;
        return;
    }

    // delete head
    if (head->data == x) {
        tail->next = head->next;
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // delete elsewhere
    while (temp->next != head && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == x) {
        prev->next = temp->next;
        delete temp;
    }
}

void printlist(Node* head){
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void freelist(Node* &head){
    if (!head) return;

    Node* temp = head->next;
    while (temp != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete head;
    head = nullptr;

    cout << endl << "FREEEED" << endl ;
}

int main() {
    Node* head = nullptr;

    insertatend(head, 10);
    insertatend(head, 20);
    insertatfront(head, 5);
    insertatpos(head, 2, 15);

    printlist(head);  // 5 15 10 20

    deletethis(head, 15);
    printlist(head);  // 5 10 20

    freelist(head);

    return 0;
}
