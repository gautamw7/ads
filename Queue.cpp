#include<iostream>
using namespace std;

class Queue{
    int max;
    int front = -1;
    int rear = -1;
    int* arr;
    int count = 0;
public:

    Queue(int size){
        arr = new int[size];
        front = 0;
        rear = 0;
        max = size;
    }

    void enqueue(int x){
        if(isFull()){
            cout << "Queue is full";
        }
        arr[rear] = x;
        rear = (rear + 1);
        count++;
    }

    int dequeue(){
        if(isempty()){
            cout << "Queue is Empty";
            return -1;
        }
        int x = arr[front];
        front = (front + 1);
        count--;
        return x;
    }

    bool isempty() {
        return count == 0;
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
    Queue queue(5);  // Create a queue of capacity 5

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Front element is: " << queue.frontElement() << endl;
    cout << "Queue size is: " << queue.size() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element after dequeuing two elements is: " << queue.frontElement() << endl;
    cout << "Queue size after dequeuing two elements is: " << queue.size() << endl;

    return 0;
}