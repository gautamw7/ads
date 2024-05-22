#include<iostream>
using namespace std;

class CirQueue{
    int max;
    int front = -1;
    int rear = -1;
    int* arr;
    int count;
public:

    CirQueue(int size){
        arr = new int[size];
        front = 0;
        rear = -1;
        max = size;
        count = 0;
    }

    void enCirQueue(int x){
        if(isFull()){
            cout << "CirQueue is full";
        }
        arr[rear] = x;
        rear = (rear + 1) % max;
        count++;
    }

    int deCirQueue(){
        if(isempty()){
            cout << "CirQueue is Empty";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % max;
        count--;
        return x;
    }

    bool isempty() {
        return count == 0 || rear == -1;
    }

    bool isFull(){
        return count == max;
    }

    int frontElement(){
        if(isempty()){
            cout << "Empty";
            return -1;
        }
        int x = arr[front];
        return x;
    }

    int size(){
        return max;
    }

};

int main(){
    CirQueue CirQueue(5);  // Create a CirQueue of capacity 5

    CirQueue.enCirQueue(1);
    CirQueue.enCirQueue(2);
    CirQueue.enCirQueue(3);
    CirQueue.enCirQueue(4);
    CirQueue.enCirQueue(5);

    cout << "Front element is: " << CirQueue.frontElement() << endl;
    cout << "CirQueue size is: " << CirQueue.size() << endl;

    CirQueue.deCirQueue();
    CirQueue.deCirQueue();

    cout << "Front element after dequeuing two elements is: " << CirQueue.frontElement() << endl;
    cout << "CirQueue size after dequeuing two elements is: " << CirQueue.size() << endl;

    return 0;
}