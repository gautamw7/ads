#include<iostream>
using namespace std;

class Graph{
private:
    int size;
    int matrix[10][10];
    const int max_size = 10;
public:
    Graph(int nNodes){
        if (nNodes > max_size) {
            cout << "Error: Maximum size exceeded." << endl;
            exit(1);
        }

        this->size = nNodes + 1;
        for(int i = 0; i < max_size; i++){
            for(int j = 0; j < max_size; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int start, int end){
        if( start < 0 || start >= size || end >= size ){
            cout << "Error : max size reached";
            return;
        }

        matrix[start][end] = 1;
        // to make this undirected addd
        // matrix[end][start] = 1;
    }

    void display(){

        cout << "  ";
        for(int i =0 ; i < size; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < size; i++){
            cout << i << " ";
            for(int j = 0; j < size; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void deleteEdge(int start, int end){
        matrix[start][end] = 0;
        // for undirected graph
        // matrix[end][start] = 1;

    }
};

// Graph starting from 0
int main(){
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(3, 0);
    graph.addEdge(3, 2);
    graph.addEdge(3, 1);
    graph.addEdge(5, 1);
    graph.addEdge(5, 2);


    graph.display();
    return 0;
}