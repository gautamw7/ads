#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adjacencyList;

public:
    Graph(int size) {
        this->size = size + 1;
        adjacencyList.resize(this->size);
    }

    void addEdge(int start, int end) {
        if (start < 0 || start >= size || end < 0 || end >= size) {
            cout << "Error: Invalid node index\n";
            return;
        }

        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }

    void displayGraph() {
        for (int i = 0; i < size; i++) {
            cout << "Vertex " << i << ":";
            for (int vertex : adjacencyList[i]) {
                cout << " -> " << vertex;
            }
            cout << endl;
        }
    }

    void deleteEdge(int start, int end) {
        // Remove edge from start to end
        auto it = find(adjacencyList[start].begin(), adjacencyList[start].end(), end);
        if (it != adjacencyList[start].end()) {
            adjacencyList[start].erase(it);
        } else {
            cout << "Edge from " << start << " to " << end << " not found." << endl;
        }

        // Remove edge from end to start
        it = find(adjacencyList[end].begin(), adjacencyList[end].end(), start);
        if (it != adjacencyList[end].end()) {
            adjacencyList[end].erase(it);
        } else {
            cout << "Edge from " << end << " to " << start << " not found." << endl;
        }
    }

    void BreathFirstSearch(int start){
        queue<int> queue;
        queue.push(start);

        vector<bool> visited(size, false);

        cout << endl << "Breath First Search of graph : " ;
        while(!queue.empty()){
            int current = queue.front();
            queue.pop();

            if(visited[current]) continue;

            visited[current] = true;

            cout << current << " ";

            for(int neighbour : adjacencyList[current]){
                if(!visited[neighbour])  queue.push(neighbour);
            }
        }

    }

    void DepthFirstSearch(int start){
        stack<int> stack;
        stack.push(start);

        vector<bool> visited(size, false);

        cout << endl << "Depth First Search of graph : " ;
        while(!stack.empty()){
            int current = stack.top();
            stack.pop();

            if(visited[current]) continue;

            visited[current] = true;

            cout << current << " ";

            for(int neighbour : adjacencyList[current]){
                if(!visited[neighbour])  stack.push(neighbour);
            }
        }
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
    graph.addEdge(5,4);
    graph.addEdge(4,2);
    graph.displayGraph();

    graph.DepthFirstSearch(0);
    graph.BreathFirstSearch(0);
    return 0;
}















/*
 * Time Complexity
Graph Construction:

The constructor initializes an adjacency list of size n + 1, where n is the number of vertices. This operation is O(n).
Adding an Edge:

Adding an edge involves inserting an element at the end of a list, which is O(1) for each insertion. Since the graph is undirected, each edge insertion involves two O(1) operations. Therefore, the time complexity for adding an edge is O(1).
Displaying the Graph:

Displaying the graph involves iterating over all vertices and their adjacency lists. The total time complexity depends on the number of vertices (V) and edges (E). For each vertex, we print all its adjacent vertices. Hence, the time complexity is O(V + E).
Space Complexity
Graph Construction:

The space complexity for the adjacency list itself is O(V + E).
O(V) space is required for the vector to store the lists for each vertex.
O(E) space is required for storing the edges, where E is the total number of edges. Each edge is stored twice (once for each vertex in an undirected graph).
Graph Storage:

The adjacency list contains a vector of list<int>, which requires additional overhead for storing the lists themselves. However, this overhead is linear with respect to the number of vertices and edges.
Summary
Time Complexity:

Graph Construction: O(n)
Adding an Edge: O(1)
Displaying the Graph: O(V + E)
Space Complexity:

Overall: O(V + E)*/