#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
};

void insertatfront(Node* &head, int value){
    Node* newnode = new Node (value);

    newnode->next = head;
    head = newnode;
}

void insertatpos(Node* &head, int pos, int value){
    if (pos <= 0) return; 
    if(head==nullptr)return;

    Node* newnode = new Node (value);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    int count = 1;
    while(temp != nullptr && count<pos-1){
        count++;
        temp = temp->next;
    }

    if(temp==nullptr){
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertatend(Node* &head, int value){
    Node* newnode = new Node (value);

    if (head == nullptr){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}


void arraytolist(Node* &head, int arr[], int n){
    for(int i=0; i<n; i++){
        insertatend(head, arr[i]);
    }
}

void printlist(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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

void freelist(Node* head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl << "FREEEED" << endl ;
}

int main() {
    int size = 5;
    int arr[size] = {3, 1, 2, 5, 8};
    cout << "array : ";
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;

    Node* head = nullptr;

    arraytolist(head, arr, size);
    cout << "list : ";
    printlist(head);
    cout << endl ;

    cout << "adding 9 at the end : " << endl;
    insertatend(head, 9);
    cout << "list : ";
    printlist(head);
    cout << endl;

    cout << "addong 11 at pos 3 : " << endl;
    insertatpos(head, 3, 11);
    cout << "list : ";
    printlist(head);
    cout << endl;

    cout << "inserting 4 at front : " << endl;
    insertatfront(head, 4);
    cout << "list : ";
    printlist(head);
    cout << endl;

    cout << "deleting 1, 2 ,5 from the list : " << endl;
    deletethis(head, 1);
    deletethis(head, 2);
    deletethis(head, 5);
    cout << "list : ";
    printlist(head);
    cout << endl;

    freelist(head);

    return 0;
}