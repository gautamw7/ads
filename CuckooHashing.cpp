#include <iostream>
#include <vector>
using namespace std;

class CuckooHashTable {
private:
    int size;
    vector<int> hashTable1;
    vector<int> hashTable2;

    int hashFunction1(int value) {
        return value % size;
    }

    int hashFunction2(int value) {
        return (value / size) % size;
    }

public:
    CuckooHashTable(int size) {
        this->size = size;
        hashTable1.resize(size, -1);
        hashTable2.resize(size, -1);
    }

    void deleteValue(int value){
        int positon = hashFunction1(value);

        if(hashTable1[positon] == value){
                hashTable1[positon] = -1;
                return;
        }else{
            positon = hashFunction2(value);
            if(hashTable2[positon] == value){
                hashTable2[positon] = -1;
                return;
            }
        }

        cout << "Value " << value << " not found in the hash tables." << endl;

    }

    void push(int value) {
        int count = 0;
        while (count < size) {
            int pos1 = hashFunction1(value);
            if (hashTable1[pos1] == -1) {
                hashTable1[pos1] = value;
                return;
            } else {
                int displacedValue = hashTable1[pos1];
                hashTable1[pos1] = value;
                value = displacedValue;
            }

            int pos2 = hashFunction2(value);
            if (hashTable2[pos2] == -1) {
                hashTable2[pos2] = value;
                return;
            } else {
                int displacedValue = hashTable2[pos2];
                hashTable2[pos2] = value;
                value = displacedValue;
            }
            count++;
        }

        cout << "Infinite Loop encountered for value: " << value << endl;
    }

    void display() {
        cout << "Hash Table 1          Hash Table 2" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " -> " << hashTable1[i];
            cout << "               " << i << " -> " << hashTable2[i] << endl;
        }
    }

    bool full(){
        for(int i = 0; i < size ; i++){
            if(hashTable2[i] == -1 || hashTable1[i] == -1) return false;
        }

        return true;
    }

    void hashReset(){
        hashTable1.resize(size, -1);
        hashTable2.resize(size, -1);
    }

    void hashResize(int table1, int table2){
        hashTable1.resize(table1);
        hashTable2.resize(table2);
    }

};

int main() {
    CuckooHashTable table(10);

    vector<int> values = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
    for (int value : values) {
        table.push(value);
    }

    table.deleteValue(20);
    table.deleteValue(55);
    table.display();
    return 0;
}
