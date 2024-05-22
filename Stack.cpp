#include<iostream>
using namespace std;

class Stack{
    int top;
    int max;
    int* arr;
public:

    Stack(int size){
        arr = new int[size];
        max = size;
        top = -1;
    }

    void push(int x){
        if(top == max) {
            cout << "The stack is full";
        }
        top++;
        arr[top] = x;
    }

    int pop(){
        if(top == -1){
            cout << "Stack is empty";
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    int topElement(){
        if(top == -1){
            cout << "Stack is empty";
            return -1;
        }
        int x = arr[top];
        return x;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == max -1;
    }

    int size(){
        return max;
    }

};

int main(){
    Stack stack(5);  // Create a stack of capacity 5

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Top element is: " << stack.topElement() << endl;
    cout << "Stack size is: " << stack.size() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element after popping two elements is: " << stack.topElement() << endl;
    cout << "Stack size after popping two elements is: " << stack.size() << endl;

    return 0;
}