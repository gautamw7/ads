#include<iostream>
#include<vector>
using namespace std;

struct node{
    int value;
    node *next;

    node(int value){
        this->value = value;
        next = nullptr;
    }
};

class HashTable{
private:
    int size;
    vector<node*> hashTable;
public:

    HashTable(int size){
        this->size = size;
        hashTable.resize(size, nullptr);
    }

    int hashFunction(int value){
        return (value % size);
    }

    void push(int value){
        int hashValue = hashFunction(value);
        node *newNode = new node(value);
        if(hashTable[hashValue] == nullptr){
            hashTable[hashValue] = newNode;
        }else{
            node *current = hashTable[hashValue];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayNode(node *head){
        node *current = head;
        while(current != nullptr){
            cout << "| " << current->value << " | ";
            current = current->next;
        }
    }

    void display(){
        for(int i = 0; i < size ; i++){
            cout << i << " -> ";
            displayNode(hashTable[i]);
            cout << endl;
        }
    }

        void deleteEdge(int value){
            int positon = hashFunction(value);

            if(hashTable[positon]->value == value){
                hashTable[positon] = hashTable[positon]->next;
            }else{
                node *current = hashTable[positon];
                while(current->next->next != nullptr || current->next->value != value){
                    if(current->next->value == value){
                        break;
                    }
                    current = current->next;
                }
                if (current->next != nullptr && current->next->value == value) {
                    current->next = current->next->next;
                    return;
                }
                cout << "Node is not found"<< endl;
            }
        }
};

int main(){
    HashTable table(10); // Create a hash table with size 10
    table.push(5);
    table.push(15);
    table.push(25);
    table.push(35);
    table.push(44);
    table.push(55);
    table.push(65);
    table.push(75);
    table.push(86);
    table.push(66);
    table.push(22);
    table.push(11);
    table.push(80);
    table.push(95);
    table.push(105); // Table is full

    table.deleteEdge(5);
    table.deleteEdge(80);
    table.deleteEdge(105);
    table.deleteEdge(55);

    table.display();
    return 0;
}