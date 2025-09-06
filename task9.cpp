#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class linklist {
public:
    Node* head;

    linklist() : head(NULL) {}
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverse(Node* node) {
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }

    void rearrange() {
        if (!head || !head->next) return;

        Node* curr = head;
        Node* altHead = NULL;   
        Node* altTail = NULL;

        while (curr && curr->next) {
            Node* temp = curr->next; 
            curr->next = temp->next; 
            curr = curr->next;       

            temp->next = NULL;
            if (!altHead) {
                altHead = altTail = temp;
            } else {
                altTail->next = temp;
                altTail = temp;
            }
        }

        altHead = reverse(altHead);

        Node* tail = head;
        while (tail->next) tail = tail->next;
        tail->next = altHead;
    }
};

int main() {
    linklist list;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int x : arr) list.append(x);

    cout << "Original List:" << endl;
    list.display();

    list.rearrange();

    cout << "Modified List:" << endl;
    list.display();

    return 0;
}
