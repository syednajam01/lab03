#include <iostream>
using namespace std;

struct Node{
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

void deleteatmiddle(Node* &head){
    Node* temp = head;

    if(head==nullptr) return;

    if (head->next == nullptr) {          // only one node
        delete head;
        head = nullptr;
        return;
    }

    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    temp = head;

    Node* pre = nullptr;
    for(int i=1; i<(count/2); i++){
        pre = temp;
        temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
}

void deletethis(Node* &head, int x){
    if(head==nullptr)return;

    Node* temp = head;

    if(head->data == x){
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* pre = nullptr;

    while(temp != nullptr && temp->data != x){
        pre = temp;
        temp = temp->next;
    }
    if(temp==nullptr) return;

    pre->next = temp->next;
    delete temp;
}

void printlist(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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

    append(head, 11);
    append(head, 45);
    append(head, 62);
    append(head, 87);
    append(head, 43);
    append(head, 95);

    cout << "list : " << endl;
    printlist(head);

    deleteatmiddle(head);
    cout << "list : " << endl;
    printlist(head);

    deletethis(head, 43);
    cout << "list : " << endl;
    printlist(head);
    
    return 0;
}