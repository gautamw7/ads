#include<iostream>
using namespace std;

struct node{
    int value;
    node *next;
    node *back;

    explicit node(int value){
        this->value = value;
        this->next = nullptr;
        this->back = nullptr;
    }
};

class DoubleLinkedList{
private:
    node *head;
public:
    DoubleLinkedList() {
        head = nullptr;
    }

    void insertAtStart(int value){
        node *newnode = new node(value);
        if(head == nullptr){
            head = newnode;
            return;
        }
        newnode->next = head;
        head->back = newnode;
        head = newnode;
    }

    void insert(int value){
        node *newnode = new node(value);
        if(head == nullptr){
            head = newnode;
            return;
        }
        node *current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        newnode->back = current;
        current->next = newnode;
    }

    void insertAt(int value, int position){
        node *newnode = new node(value);
        if(head == nullptr){
            head = newnode;
            return;
        }
        if(head->value == position){
            newnode->next = head->next;
            newnode->back = head;
            head->next->back = newnode;
            head->next = newnode;
            return;
        }
        node *current = head;
        while(current != nullptr) {
            if (current->next->value == position) {
                newnode->next = current->next;
                newnode->back = current;
                current->next->back = newnode;
                current->next = newnode;
                return;
            }
            current = current->next;
        }
        cout << "There is no such value" << endl;
    }

    int deleteAtStart(){
        if(isEmpty()){
            cout << "Linked list not started";
            return -1;
        }
        node *newnode = head->next;
        newnode->back = nullptr;
        int x = head->value;
        head = newnode;
        return x;
    }

    int deleteAtEnd(){
        if(isEmpty()){
            cout << "Linked list not started";
            return -1;
        }
        if(head->next == nullptr){
            int x = head->value;
            delete head;
            head = nullptr;
            return x;
        }
        node *current = head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        int x = current->next->value;
        delete current->next;
        current->next = nullptr;
        return x;
    }

    int deletenode(int value){
        if(isEmpty()){
            cout << "Linked list not started";
            return -1;
        }
        if(head->value == value){
            int x = head->value;
            head->next->back = nullptr;
            head = head->next;
            delete head;
            return x;
        }
        node *current = head;
        while(current != nullptr){
            if(current->value == value){
                int x = value;
                current->next->back = current->back;
                current->back->next = current->next;
                delete current;
                return x;
            }
            current = current->next;
        }
        cout << "Value not found" << endl;
        return -1;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void reverseLinkedList(){
        node *prev = nullptr;
        node *current = head;
        while(current != nullptr){
            node *nextNode = current->next;
            current->next = current->back;
            current->back = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
};

int main() {
    DoubleLinkedList myList;

    // Insertion
    myList.insert(10);
    myList.insert(20);
    myList.insertAtStart(5);
    myList.insert(30);
    myList.insert(15);
    myList.insertAt(25, 20); // Insert 25 after 20

    // Display the list
    cout << "Linked List: ";
    myList.display(); // Expected output: 5 10 20 25 30 15

/*
    // Deletion
    myList.deleteAtStart(); // Removes 5
    myList.deleteAtEnd();   // Removes 15
    myList.deletenode(20);  // Removes 20

    // Display the list after deletion
    cout << "Linked List after deletion: ";
    myList.display(); // Expected output: 10 25 30
*/
    myList.reverseLinkedList();
    cout << "Linked List: ";
    myList.display();

    return 0;
}