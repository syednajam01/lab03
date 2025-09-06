#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T x) : data(x), next(nullptr){}
};

template<typename T>
class Flight{
    public:
        string flightnumber;
        Node<T>* passengerhead;
        Flight* next;

        Flight(string f) : flightnumber(f), passengerhead(nullptr), next(nullptr) {}
};

// function prototypes
template<typename T> void sortedlist(Node<T>* &head, T name);
template<typename T> void cancel(Node<T>* &head, T name);
template<typename T> void displayList(Node<T>* head);
template<typename T> void freelist(Node<T>* &head);

template<typename T>
void bookflight(Flight<T>* &flighthead, string passenger, string flightno){
    Flight<string>* ftemp = flighthead;

    while(ftemp != nullptr && ftemp->flightnumber != flightno) ftemp = ftemp->next;

    if(ftemp == nullptr){
        sortedflight(flighthead, flightno);

        ftemp = flighthead;
        while(ftemp != nullptr && ftemp->flightnumber != flightno) ftemp = ftemp->next;
    }

    //flight complete now passengers
    sortedlist(ftemp->passengerhead, passenger);
    return;
}

void cancelflight(Flight<string>* &flighthead, string passenger, string flightno){
    Flight<string>* ftemp = flighthead;
    
    if(flighthead == nullptr) return;

    while(ftemp != nullptr && ftemp->flightnumber != flightno) ftemp = ftemp->next;

    if(ftemp == nullptr){
        cout << "no flights found" << endl;
        return;
    }

    cancel(ftemp->passengerhead, passenger);
    return;
}

void displayflight(Flight<string>* &flighthead, string flightno){
    Flight<string>* ftemp = flighthead;

    if(ftemp == nullptr) return;

    while(ftemp != nullptr && ftemp->flightnumber != flightno) ftemp = ftemp->next;
    if(ftemp == nullptr){
        cout << "flight not found!" << endl;
        return;
    }

    displayList(ftemp->passengerhead);
}

template<typename T>
bool checkreservation(Flight<T>* &flighthead, string flightno, string passenger){
    Flight<T>* ftemp = flighthead;
    while(ftemp != nullptr && ftemp->flightnumber != flightno)ftemp = ftemp->next;
    if(ftemp == nullptr){
        cout << "flight not found" << endl;
        return false;
    }
    Node<string>* ptemp  = ftemp->passengerhead;
    while(ptemp != nullptr){
        if(ptemp->data == passenger){
            cout << passenger << " has a reservation in flight " << flightno;
            return true;
        }
        ptemp = ptemp->next;
    }
    cout << passenger << " does NOT have a reservation in " << flightno << endl;
    return false;
}

template<typename T>
void sortedlist(Node<T>* &head, T name){
    Node<T>* newnode = new Node<T> (name);
    if(head==nullptr){
        head = newnode;
        return;
    }
    if(head->data > name){
        newnode->next = head;
        head = newnode;
        return;
    }
    Node<T>* temp = head;
    while(temp->next!=nullptr && temp->next->data < name) temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}

void sortedflight(Flight<string>* &flighthead, string name){
    Flight<string>* newnode = new Flight<string> (name);
    if(flighthead==nullptr){
        flighthead = newnode;
        return;
    }
    if(flighthead->flightnumber > name){
        newnode->next = flighthead;
        flighthead = newnode;
        return;
    }
    Flight<string>* ftemp = flighthead;
    while(ftemp->next!=nullptr && ftemp->next->flightnumber < name) ftemp = ftemp->next;
    newnode->next = ftemp->next;
    ftemp->next = newnode;
}

template<typename T>
void cancel(Node<T>* &head, T name){
    Node<T>* temp = head;
    if(head==nullptr) return;
    if (head->data == name){
        head = head->next;
        delete temp;
        return;
    }
    Node<T>* pre = nullptr;
    while(temp != nullptr && temp->data != name){
        pre = temp;
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "no data found" << endl;
        return;
    }
    else{
        pre->next = temp->next;
        delete temp;
        return;
    }
}

template<typename T>
void check(Node<T>* head, T name){
    if(head==nullptr) return;
    Node<T>* temp = head;
    while(temp != nullptr && temp->data != name) temp = temp->next;
    if(temp == nullptr){
        cout << "no reservation" << endl;
        return;
    }
    else{
        cout << "reserved" << endl;
        return;
    }
}

template<typename T>
void nametolist(Node<T>* &head, T name){
    Node<T>* newnode = new Node<T> (name);

    if(head==nullptr){
        head = newnode;
        return;
    }

    Node<T>* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

int options() {
    int n;
    do {
        cout << "\n====== Airline Reservation System ======\n";
        cout << "1. Book a flight for a passenger\n";
        cout << "2. Cancel passenger from a flight\n";
        cout << "3. Check passenger in a flight\n";
        cout << "4. Display passengers of a flight\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";
        cin >> n;
    } while (n < 1 || n > 5);
    return n;
}

template<typename T>
void displayList(Node<T>* head) {
    Node<T>* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deletelist(Flight<string>* &flighthead){
    while(flighthead!=nullptr){
        Flight<string>* ftemp = flighthead;
        freelist(flighthead->passengerhead);
        flighthead = flighthead->next;
        delete ftemp;
    }
    flighthead = nullptr;
    cout << endl << "FREEEED" << endl ;
}

template<typename T>
void freelist(Node<T>* &head){
    while(head != nullptr){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Flight<string>* flightHead = nullptr;  // list of flights

    int choice;
    do {
        choice = options();
        string flightNo, passenger;

        switch (choice) {
            case 1: // book
                cout << "Enter flight number: ";
                cin >> flightNo;
                cout << "Enter passenger name: ";
                cin >> passenger;
                bookflight(flightHead, passenger, flightNo);
                break;

            case 2: // cancel
                cout << "Enter flight number: ";
                cin >> flightNo;
                cout << "Enter passenger name: ";
                cin >> passenger;
                cancelflight(flightHead, passenger, flightNo);
                break;

            case 3: // check
                cout << "Enter flight number: ";
                cin >> flightNo;
                cout << "Enter passenger name: ";
                cin >> passenger;
                checkreservation(flightHead, flightNo, passenger);
                break;

            case 4: // display
                cout << "Enter flight number: ";
                cin >> flightNo;
                displayflight(flightHead, flightNo);
                break;

            case 5:
                cout << "Exiting system...\n";
                break;
        }
    } while (choice != 5);

    deletelist(flightHead);

    return 0;
}
