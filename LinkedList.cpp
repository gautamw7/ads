#include<iostream>
using namespace std;

struct Node{
    int value;
    Node *next;

    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtStart(int value){
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;

        }
        newNode->next = head;
        head = newNode;
    }

    void insert(int value){
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node *current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAt(int value, int position){
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        if(head->value == position){
            newNode->next = head->next;
            head->next = newNode;
            return;
        }
        Node *current = head;
        while(current != nullptr) {
            if (current->next->value == position) {
                newNode->next = current->next->next;
                current->next = newNode;
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
        Node *newNode = head->next;
        int x = head->value;
        head = newNode;
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
        Node *current = head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        int x = current->next->value;
        delete current->next;
        current->next = nullptr;
        return x;
    }

    int deleteNode(int value){
        if(isEmpty()){
            cout << "Linked list not started";
            return -1;
        }
        if(head->value == value){
            int x = head->value;
            head = head->next;
            delete head;
            return x;
        }
        Node *current = head;
        while(current != nullptr){
            if(current->next->value == value){
                int x = current->next->value;
                current->next = current->next->next;
                delete current->next;
                return x;
            }
            current = current->next;
        }
        cout << "Value not found" << endl;
        return -1;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void deleteEvenNode(){
        if (isEmpty()) {
            return;
        }

        while(head!= nullptr && head->value %2 == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        Node *current = head->next;
        while(current->next != nullptr){
            cout << current->value << " ";
            if(current->next->value %2 == 0){
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }else {
                current = current->next;
            }
        }
    }
};

int main() {
    LinkedList myList;

    // Insertion
    myList.insert(10);
    myList.insert(20);
    myList.insertAtStart(5);
    myList.insert(35);
    myList.insert(15);
    myList.insert(21);
    myList.insertAtStart(5);
    myList.insert(35);
    myList.insert(30);
    myList.insert(352);
    myList.insert(351);



    // Display the list
    std::cout << "Linked List: ";
    myList.display(); // Output: 5 10 20 30
    myList.deleteAtStart();
    myList.deleteAtEnd();
    myList.deleteEvenNode();

    // Display the list after deletion
    std::cout << "\nLinked List after deletion: ";
    myList.display(); // Output: 10 20

    return 0;
}