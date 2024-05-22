#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<limits>
using namespace std;

typedef pair<int, int> distVertx; // Pair to store (distance, vertex)

class Graph{
private:
    int size;
    vector<vector<pair<int,int>>> adjList;
public:

    Graph(int nNodes){
        this->size = nNodes;
        adjList.resize(size);
    }

    void addEdge(int start, int end, int weight){
        if(start < 0 || end < 0 || end >= size || start >= size){
            cout << "Error: Node invalid" << endl;
            return;
        }
        adjList[start].push_back({end, weight});
        adjList[end].push_back({start, weight});
    }

    void display(){
        for(int i = 0; i < size ; i++){
            cout << "Vector " << i << ": ";
            for(auto Edge : adjList[i]){
                cout << "->" << Edge.first << " (Weight: " << Edge.second << ") ";
            }
            cout << endl;
        }
    }

    void DijkastraAlgo(int startIndex){
        priority_queue<distVertx, vector<distVertx>, greater<distVertx>> pq;
        //         the data type, the data storage type, type of max/min
        vector<int> distances(size, numeric_limits<int>::max());

        vector<bool> visited(size, false);

        distances[startIndex] = 0;
        pq.push({0,startIndex});

        while(!pq.empty()){
            int currentDistance = pq.top().first;
            int currentVert = pq.top().second;

            pq.pop();
            if(visited[currentVert]) continue;
            visited[currentVert] = true;

            for(auto neighbour : adjList[currentVert]){
                int nextNode = neighbour.first;
                int weight = neighbour.second;
                int nextDistance = currentDistance + weight;

                if(nextDistance < distances[nextNode]){
                    distances[nextNode] = nextDistance;
                    pq.push({nextDistance, nextNode });
                }
            }
        }
        // end of loop

        cout << "Shortest distances from node " << startIndex << ":\n";
        for (int i = 0; i < size; ++i) {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

};

int main() {
    Graph graph(6); // Create a graph with vertices numbered 0 through 5

    // Adding weighted edges (undirected)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 6);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 7);

    // Display the weighted graph
    graph.display();

    // Find and display the MST using Kruskal's algorithm
    graph.DijkastraAlgo(0);

    return 0;
}