#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class CirLinkedList {
private:
    Node* head;
public:
    CirLinkedList() {
        head = nullptr;
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Points to itself to make it circular
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
            head = newNode;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Points to itself to make it circular
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void insertAt(int value, int position) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Points to itself to make it circular
            return;
        }
        Node* current = head;
        do {
            if (current->value == position) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "There is no such value" << endl;
    }

    int deleteAtStart() {
        if (isEmpty()) {
            cout << "Linked list not started" << endl;
            return -1;
        }
        int x = head->value;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        }
        return x;
    }

    int deleteAtEnd() {
        if (isEmpty()) {
            cout << "Linked list not started" << endl;
            return -1;
        }
        int x;
        if (head->next == head) {
            x = head->value;
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != head) {
                current = current->next;
            }
            x = current->next->value;
            delete current->next;
            current->next = head;
        }
        return x;
    }

    int deleteNode(int value) {
        if (isEmpty()) {
            cout << "Linked list not started" << endl;
            return -1;
        }
        int x;
        if (head->value == value) {
            return deleteAtStart();
        }
        Node* current = head;
        do {
            if (current->next->value == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                if (temp == head) {
                    head = current->next;
                }
                x = temp->value;
                delete temp;
                return x;
            }
            current = current->next;
        } while (current != head);
        cout << "Value not found" << endl;
        return -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    CirLinkedList myList;

    // Insertion
    myList.insert(10);
    myList.insert(20);
    myList.insertAtStart(5);
    myList.insert(30);
    myList.insert(15);
    myList.insertAt(25, 20); // Insert 25 after 20

    // Display the list
    cout << "Circular Linked List: ";
    myList.display(); // Expected output: 5 10 20 25 30 15

    // Deletion
    myList.deleteAtStart(); // Removes 5
    myList.deleteAtEnd();   // Removes 15
    myList.deleteNode(20);  // Removes 20

    // Display the list after deletion
    cout << "Circular Linked List after deletion: ";
    myList.display(); // Expected output: 10 25 30

    return 0;
}
