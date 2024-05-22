#include<iostream>
#include<vector>
using namespace std;

class HashTable{
private:
    int size;
    vector<int> hashTable;
public:
    HashTable(int size){
        this->size = size;
        hashTable.resize(size, -1);
    }

    int hashFunction(int value){
        int pos = (value % size);
        if(hashTable[pos] == -1) return pos;

        int count = 0;
        while(hashTable[pos] != -1 && count < size){
            pos = (pos + 1) % size;
            count++;
        }
        return (count == size) ? -1 : pos;
    }

    void push(int value){
        int hashValue = hashFunction(value);
        if(hashValue == -1 ) {
            cout << "HashTable is full, " << value << " can't be fit."<< endl;
            return;
        }
        hashTable[hashValue] = value;
    }

    void display(){
        for(int i = 0; i < size ; i++){
            cout << i << " -> " << hashTable[i] << endl;
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
    table.push(95);
    table.push(105); // Table is full

    table.display();
    return 0;
}