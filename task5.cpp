#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node* next;

    Node(T x) : data(x), next(nullptr){}
};

template<typename T>
void append(Node<T>* &head, int value){
    Node<T>* newnode = new Node<T> (value);

    if (head == nullptr){
        head = newnode;
        return;
    }

    Node<T>* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

template<typename T>
int length(Node<T>* head){
    int len = 0;
    while(head != nullptr){
        len++;
        head = head->next;
    }
    return len;
}

template<typename T>
bool check(Node<T>* head, Node<T>* &head2){
    if(head==nullptr) return true;
    bool see = check(head->next, head2);
    if(!see) return false;
    bool equal = (head->data==head2->data);
    head2 = head2->next;
    return equal;
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
    
    Node<int>* headint = nullptr;
    Node<string>* headstr = nullptr;

    append(headint, 1);
    append(headint, 2);
    append(headint, 2);

    bool see = check(headint, headint);

    cout << (see)? "palindrome" : "not palindrome";

    freelist(headint);

    return 0;
}