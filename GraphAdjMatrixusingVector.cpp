#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adjacencyList;
public:
    Graph(int nNodes){
        this->size = nNodes + 1;
        adjacencyList.resize(size, vector<int>(size, 0));

    }

    void addEdge(int start, int end){
        if(start < 0 || end < 0 || start >= size || end >= size){
            cout << "Error: Invalid node index\n";
            return;
        }

        adjacencyList[start][end] = 1;
        adjacencyList[end][start] = 1;
    }

    void displayGraph(){
        cout << "  ";
        for (int i = 0; i < size; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " ";
            for(int num : adjacencyList[i]) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    void deleteEdge(int start, int end){
        adjacencyList[start][end] = 0;
        adjacencyList[end][start] = 0;
    }
};

int main() {
    Graph graph(5);


    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.displayGraph();

    return 0;
}

/*
 * Time Complexity
Graph Construction:

The constructor initializes the adjacency list with size (nNodes + 1) x (nNodes + 1), where nNodes is the number of nodes in the graph. Initializing the vector and filling it with zeros takes O(V^2), where V is the number of vertices.
Adding an Edge (addEdge):

The addEdge function sets the corresponding entry in the adjacency matrix to 1 for both vertices. Since it involves only constant time operations, the time complexity is O(1).
Displaying the Graph (displayGraph):

The displayGraph function iterates through each vertex and its adjacent vertices. It prints the entire adjacency list, which takes O(V^2) time for a complete traversal of the list.
Space Complexity
Graph Storage:
The space complexity for storing the adjacency list is O(V^2), where V is the number of vertices. This is because each vertex can be connected to any other vertex in the graph.
Summary
Time Complexity:

Graph Construction: O(V^2)
Adding an Edge: O(1)
Displaying the Graph: O(V^2)
Space Complexity:

Overall: O(V^2)
 */