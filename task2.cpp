#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr){}
};

template <typename T>
void insertatend(Node<T>* &head, T value){
    Node<T>* newnode = new Node<T> (value);

    if (head == nullptr){
        head = newnode;
        return;
    }

    Node<T>* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

template <typename T>
void move_elements(Node<T>* &head, int x){
    Node<T>* temp = head;

    if(head == nullptr || x<=0) return;

    int len = 1;
    while(temp->next != nullptr){
        len++;
        temp = temp->next;
    }
    if(x>len) return;

    temp = head;
    for(int i=1; i<x; i++) temp = temp->next;

    // head = temp->next;
    Node<T>* newHead = temp->next;
    temp->next = nullptr;
    
    Node<T>* tail = newHead;
    while(tail->next != nullptr) tail = tail->next;

    tail->next = head;
    head = newHead;
}

template <typename T>
void printlist(Node<T>* head){
    cout << "list : " << endl;
    Node<T>* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    }

template<typename T>
void freelist(Node<T>* head){
    while(head != nullptr){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl << "FREEEED" << endl ;
}

int main() {
    
    Node<int>* head = nullptr;

    //5, 3 1 8 6 4 2
    insertatend(head, 5);
    insertatend(head, 3);
    insertatend(head, 1);
    insertatend(head, 8);
    insertatend(head, 6);
    insertatend(head, 4);
    insertatend(head, 2);

    printlist(head);

    cout << endl << "===========moving============" << endl;

    move_elements(head, 5);

    cout << "after moving....." << endl;

    printlist(head);

    freelist(head);

    return 0;
}