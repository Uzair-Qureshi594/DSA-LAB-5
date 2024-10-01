#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == value) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int value;
int n;
cout<<"Enter the Number for Linklist :";
cin>>n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value   " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    list.display();

    cout << "Enter value To insert at the Head 5 : ";
    cin >> value;
    list.insert(value);
    list.display();

    cout << "Enter value for deletion delete: ";
    cin >> value;
    list.deleteNode(value);
    list.display();

}